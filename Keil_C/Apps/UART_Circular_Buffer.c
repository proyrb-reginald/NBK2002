#include "UART_Circular_Buffer.h"
#include "sc32f1xxx_dma.h"
#include "print.h"

UART_CircularBuffer uart1;

// 初始化环形缓冲区结构体
void UART_CircularBuffer_Init(UART_CircularBuffer *uart) {
    uart->tx_buffer.head = uart->tx_buffer.tail = 0; // 初始化缓冲区head/tail指针

    uart->transmitting = 0; // 初始化DMA正在传输的标志位

    uart->using_s = xSemaphoreCreateMutex(); // 初始化互斥信号量
    if (uart->using_s == NULL) {
        while (1); // 错误处理
    }
    
    uart->transmit_s = xSemaphoreCreateBinary(); // 初始化同步信号量
    if (uart->transmit_s == NULL) {
        while (1); // 错误处理
    }
}

// 写入多字节数据
int UART_Buffer_Write(UART_CircularBuffer *uart, const uint8_t *data, uint16_t len) {
    int bytes_written = 0;

    // 获取互斥信号量（任务上下文）
    if (xSemaphoreTake(uart->using_s, portMAX_DELAY) == pdTRUE) {
        RingBuffer *rb = &uart->tx_buffer;
        uint16_t space = (rb->tail + TX_BUFFER_SIZE - rb->head - 1) & TX_BUFFER_SIZE_MASK;

        // 如果没有空间，直接返回0
        if (space == 0) {
            xSemaphoreGive(uart->using_s);
            return 0;
        }

        // 限制写入长度为可用空间
        if (len > space) {
            len = space;
        }

        // 分段写入（考虑环形缓冲区的环绕结构）
        uint16_t first_part_len = TX_BUFFER_SIZE - rb->head;
        if (first_part_len > len) {
            first_part_len = len;  // 不需要分段
        }

        // 第一段：从 head 到 buffer 末尾
        memcpy(&rb->buffer[rb->head], data, first_part_len);
        rb->head = (rb->head + first_part_len) & TX_BUFFER_SIZE_MASK;
        bytes_written += first_part_len;

        // 第二段：从 buffer 开头开始
        if (len > first_part_len) {
            uint16_t second_part_len = len - first_part_len;
            memcpy(&rb->buffer[rb->head + 1], data + first_part_len, second_part_len); // 需要+1进行修正
            rb->head = (rb->head + second_part_len + 1) & TX_BUFFER_SIZE_MASK; // 需要+1进行修正
            bytes_written += second_part_len;
        }

        // 如果当前未在传输中，尝试启动DMA
        if (!uart->transmitting) {
            xSemaphoreGive(uart1.transmit_s); // 通知启动传输任务
        }

        xSemaphoreGive(uart->using_s);
    }

    return bytes_written;
}

// 启动DMA发送
void UART_Buffer_StartDMATransfer(UART_CircularBuffer *uart) {
    if (xSemaphoreTake(uart->using_s, portMAX_DELAY) == pdTRUE) {
        // 如果缓冲区为空，则无需发送
        if (uart->tx_buffer.tail == uart->tx_buffer.head) {
            xSemaphoreGive(uart->using_s);
            return; 
        }
        
        // 保存当前head/tail指针
        uint16_t tail = uart->tx_buffer.tail;
        uint16_t head = uart->tx_buffer.head;
        
        // 计算当前可用传输长度
        if (head >= tail) {
            uart->transmit_size = head - tail;
        } else {
            uart->transmit_size = TX_BUFFER_SIZE - tail;
        }

        // 启动DMA传输（根据具体平台实现）
        DMA_SetSrcAddress(DMA0, (uint32_t)&uart->tx_buffer.buffer[uart->tx_buffer.tail]);
        DMA_SetCurrDataCounter(DMA0, uart->transmit_size);
        DMA_SoftwareTrigger(DMA0);
        
        uart->transmitting = 1; // 置DMA正在传输的标志位
        xSemaphoreGive(uart->using_s);
    }
}

// 启动DMA传输任务
void vTask_StartTransmit(void *pvParameters) {
	for(;;) {
        if (xSemaphoreTake(uart1.transmit_s, portMAX_DELAY) == pdTRUE) {
            UART_Buffer_StartDMATransfer(&uart1);
        }
	}
}

// DMA中断处理函数
void DMA0_IRQHandler(void) {
	DMA_ClearFlag(DMA0, DMA_FLAG_GIF|DMA_FLAG_TCIF|DMA_FLAG_HTIF|DMA_FLAG_TEIF);
    
    uart1.tx_buffer.tail = (uart1.tx_buffer.tail + uart1.transmit_size) & TX_BUFFER_SIZE_MASK; // 更新tail指针

    if (uart1.tx_buffer.tail != uart1.tx_buffer.head) {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        xSemaphoreGiveFromISR(uart1.transmit_s, &xHigherPriorityTaskWoken); // 如何还有数据就继续启动传输
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    } else {
        uart1.transmitting = 0; // 否则清除DMA正在传输的标志位
    }
}
