#include "UART_Circular_Buffer.h"
#include "sc32f1xxx_dma.h"

#include "SC_Init.h"

UART_CircularBuffer uart;

// 初始化环形缓冲区和DMA
void UART_CircularBuffer_Init(UART_CircularBuffer *uart) {
    // 初始化缓冲区
    uart->tx_buffer.head = 0;
    uart->tx_buffer.tail = 0;
    uart->tx_buffer.size_mask = TX_BUFFER_SIZE - 1;

    // 初始化状态标�?
    uart->transmitting = 0;
    uart->dma_active = 0;

    // 初始化互斥信号量
    uart->txSemaphore = xSemaphoreCreateMutex();
    if (uart->txSemaphore == NULL) {
        while (1);  // 错误处理
    }
}

// 写入单个字节（任务上下文�?
int UART_Buffer_Write(UART_CircularBuffer *uart, uint8_t data) {
    if (xSemaphoreTake(uart->txSemaphore, portMAX_DELAY) == pdTRUE) {
        uint16_t next_head = (uart->tx_buffer.head + 1) & uart->tx_buffer.size_mask;

        if (next_head == uart->tx_buffer.tail) {
            xSemaphoreGive(uart->txSemaphore);
            return -1;  // 缓冲区已�?
        }

        uart->tx_buffer.buffer[uart->tx_buffer.head] = data;
        uart->tx_buffer.head = next_head;

        if (!uart->dma_active && !uart->transmitting) {
            UART_Buffer_StartDMATransfer(uart);  // 尝试启动DMA发�?
        }

        xSemaphoreGive(uart->txSemaphore);
        return 0;
    }

    return -1;
}

// 写入多字节数据（任务上下文）
int UART_Buffer_WriteMulti(UART_CircularBuffer *uart, const uint8_t *data, uint16_t len) {
    if (uart->dma_active) {
        return 0;  // DMA 正在传输，暂时不能写入
    }
    
    int bytes_written = 0;

    // 获取互斥信号量（任务上下文）
    if (xSemaphoreTake(uart->txSemaphore, portMAX_DELAY) == pdTRUE) {
        RingBuffer *rb = &uart->tx_buffer;
        uint16_t space = (rb->tail - rb->head - 1) & rb->size_mask;

        // 如果没有空间，直接返回0
        if (space == 0) {
            xSemaphoreGive(uart->txSemaphore);
            return 0;
        }

        // 限制写入长度为可用空间
        if (len > space) {
            len = space;
        }

        // 分段写入（考虑环形缓冲区的环绕结构）
        uint16_t first_part_len = rb->size_mask + 1 - rb->head;
        if (first_part_len > len) {
            first_part_len = len;  // 不需要分段
        }

        // 第一段：从 head 到 buffer 末尾
        memcpy(&rb->buffer[rb->head], data, first_part_len);
        rb->head = (rb->head + first_part_len) & rb->size_mask;
        bytes_written += first_part_len;

        // 第二段：从 buffer 开头开始
        if (len > first_part_len) {
            uint16_t second_part_len = len - first_part_len;
            memcpy(&rb->buffer[rb->head], data + first_part_len, second_part_len);
            rb->head = (rb->head + second_part_len) & rb->size_mask;
            bytes_written += second_part_len;
        }

        // 如果当前未在传输中，尝试启动DMA
        if (!uart->dma_active && !uart->transmitting) {
            UART_Buffer_StartDMATransfer(uart);
        }

        xSemaphoreGive(uart->txSemaphore);
    }

    return bytes_written;
}

// 启动DMA发�?
void UART_Buffer_StartDMATransfer(UART_CircularBuffer *uart) {
    if (uart->tx_buffer.tail == uart->tx_buffer.head) {
        return;  // 缓冲区为空，无需发�?
    }
    
    // 保存当前 head/tail 指针
    uint16_t tail = uart->tx_buffer.tail;
    uint16_t head = uart->tx_buffer.head;
    
    // 计算当前可用传输长度
    uint16_t available;
    if (head >= tail) {
        available = head - tail;
    } else {
        available = TX_BUFFER_SIZE - tail;
    }

    // 启动DMA传输（根据具体平台实现）
    // 示例：HAL_UART_Transmit_DMA(uartHandle, &uart->tx_buffer.buffer[uart->tx_buffer.tail], available);
    // 或者使用DMA库函数：DMA_StartTransfer(uart->dma_handle, ...)
    DMA_SetSrcAddress(DMA0, (uint32_t)&uart->tx_buffer.buffer[uart->tx_buffer.tail]);
    DMA_SetCurrDataCounter(DMA0, available);
    DMA_SoftwareTrigger(DMA0);

    uart->dma_active = 1;
    uart->transmitting = 1;
}

// DMA中断处理函数（中断上下文�?
void DMA0_IRQHandler(void) {
	DMA_ClearFlag(DMA0, DMA_FLAG_GIF|DMA_FLAG_TCIF|DMA_FLAG_HTIF|DMA_FLAG_TEIF);
    
    taskENTER_CRITICAL();
    // 更新tail指针
    uint16_t available = 0;
    if (uart.tx_buffer.head >= uart.tx_buffer.tail) {
        available = uart.tx_buffer.head - uart.tx_buffer.tail;
    } else {
        available = TX_BUFFER_SIZE - uart.tx_buffer.tail;
    }
    
    uart.tx_buffer.tail = (uart.tx_buffer.tail + available) & uart.tx_buffer.size_mask;

    // 如果还有数据，再次启动DMA
    if (uart.tx_buffer.tail != uart.tx_buffer.head) {
        UART_Buffer_StartDMATransfer(&uart);
    } else {
        uart.transmitting = 0;
        uart.dma_active = 0;
    }
    
    taskEXIT_CRITICAL();
}
