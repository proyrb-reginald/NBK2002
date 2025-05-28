/******************** 宏定义 ********************/

#define USE_DMA0 0
#define USE_DMA1 1

/******************** 导入头文件 ********************/

#include "DMA_Circular_Buffer.h"
#include "sc32f1xxx_dma.h"
#include "print.h"

/******************** 宏定义 ********************/

#ifndef DMA_Select // 防止空定义
    #define DMA_Select USE_DMA0
#else
    #if (DMA_Select < 0 || DMA_Select > 1) //防止无效定义
        #undef DMA_Select
        #define DMA_Select USE_DMA0
    #endif
#endif

#ifndef DMA_CIRCULAR_BUFFER_SIZE // 防止空定义
    #define DMA_CIRCULAR_BUFFER_SIZE 256
#else
    #if (DMA_CIRCULAR_BUFFER_SIZE < 1) //防止无效定义
        #undef DMA_CIRCULAR_BUFFER_SIZE
        #define DMA_CIRCULAR_BUFFER_SIZE 16
    #endif
#endif

#define DMA_CIRCULAR_BUFFER_SIZE_MASK (DMA_CIRCULAR_BUFFER_SIZE - 1) // 环形缓冲区掩膜，用于快速取模

/******************** 类型声明 ********************/

typedef struct {
    uint8_t buffer[DMA_CIRCULAR_BUFFER_SIZE]; // 环形缓冲区
    volatile uint16_t head;                    // 头指针，写缓冲区会移动头指针
    volatile uint16_t tail;                    // 尾指针，发缓冲区会移动尾指针
} DMA_Circular_Buffer;

typedef struct {
    DMA_Circular_Buffer circular_buffer;
    volatile bool transmitting;      // DMA是否正在发送
    volatile uint16_t transmit_size; // 当前DMA正在传输内容的长度
    SemaphoreHandle_t using_s;       // RTOS互斥信号量
    SemaphoreHandle_t transmit_s;    // RTOS同步信号量
} DMA_Circular_Buffer_DMA_RTOS;

/******************** 变量定义 ********************/

static DMA_Circular_Buffer_DMA_RTOS corporation; // 法人

/******************** 函数定义 ********************/

static void DMA_Circular_Buffer_Transfer(void) {
    if (xSemaphoreTake(corporation.using_s, portMAX_DELAY) == pdTRUE) {
        // 如果缓冲区为空，则无需发送
        if (corporation.circular_buffer.tail == corporation.circular_buffer.head) {
            xSemaphoreGive(corporation.using_s);
            return; 
        }
        
        // 保存当前head/tail指针
        uint16_t tail = corporation.circular_buffer.tail;
        uint16_t head = corporation.circular_buffer.head;
        
        // 计算当前可用传输长度
        if (head >= tail) {
            corporation.transmit_size = head - tail;
        } else {
            corporation.transmit_size = DMA_CIRCULAR_BUFFER_SIZE_MASK - tail;
        }

        // 启动DMA传输（根据具体平台实现）
        DMA_SetSrcAddress(DMA0, (uint32_t)&corporation.circular_buffer.buffer[corporation.circular_buffer.tail]);
        DMA_SetCurrDataCounter(DMA0, corporation.transmit_size);
        DMA_SoftwareTrigger(DMA0);
        
        corporation.transmitting = 1; // 置DMA正在传输的标志位
        xSemaphoreGive(corporation.using_s);
    }
}

void DMA_Circular_Buffer_Init(void) {
    corporation.circular_buffer.head = 0;
    corporation.circular_buffer.tail = 0;
    corporation.transmitting = 0;
    corporation.transmit_size = 0;
    
    corporation.using_s = xSemaphoreCreateMutex(); // 初始化互斥信号量
    if (corporation.using_s == NULL) {
        while (1); // 错误处理
    }
    
    corporation.transmit_s = xSemaphoreCreateBinary(); // 初始化同步信号量
    if (corporation.transmit_s == NULL) {
        while (1); // 错误处理
    }
}

int  DMA_Circular_Buffer_Write(uint8_t * data, uint16_t len) {
    int bytes_written = 0;

    // 获取互斥信号量（任务上下文）
    if (xSemaphoreTake(corporation.using_s, portMAX_DELAY) == pdTRUE) {
        DMA_Circular_Buffer *rb = &corporation.circular_buffer;
        uint16_t space = (rb->tail + DMA_CIRCULAR_BUFFER_SIZE_MASK - rb->head - 1) & DMA_CIRCULAR_BUFFER_SIZE_MASK;

        // 如果没有空间，直接返回0
        if (space == 0) {
            xSemaphoreGive(corporation.using_s);
            return 0;
        }

        // 限制写入长度为可用空间
        if (len > space) {
            len = space;
        }

        // 分段写入（考虑环形缓冲区的环绕结构）
        uint16_t first_part_len = DMA_CIRCULAR_BUFFER_SIZE_MASK - rb->head;
        if (first_part_len > len) {
            first_part_len = len;  // 不需要分段
        }

        // 第一段：从 head 到 buffer 末尾
        memcpy(&rb->buffer[rb->head], data, first_part_len);
        rb->head = (rb->head + first_part_len) & DMA_CIRCULAR_BUFFER_SIZE_MASK;
        bytes_written += first_part_len;

        // 第二段：从 buffer 开头开始
        if (len > first_part_len) {
            uint16_t second_part_len = len - first_part_len;
            memcpy(&rb->buffer[rb->head + 1], data + first_part_len, second_part_len); // 需要+1进行修正
            rb->head = (rb->head + second_part_len + 1) & DMA_CIRCULAR_BUFFER_SIZE_MASK; // 需要+1进行修正
            bytes_written += second_part_len;
        }

        // 如果当前未在传输中，尝试启动DMA
        if (!corporation.transmitting) {
            xSemaphoreGive(corporation.transmit_s); // 通知启动传输任务
        }

        xSemaphoreGive(corporation.using_s);
    }

    return bytes_written;
}

void DMA_Circular_Buffer_IRQHandler(void) {    
    corporation.circular_buffer.tail = (corporation.circular_buffer.tail + corporation.transmit_size) & DMA_CIRCULAR_BUFFER_SIZE_MASK; // 更新tail指针

    if (corporation.circular_buffer.tail != corporation.circular_buffer.head) {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        xSemaphoreGiveFromISR(corporation.transmit_s, &xHigherPriorityTaskWoken); // 如何还有数据就继续启动传输
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    } else {
        corporation.transmitting = 0; // 否则清除DMA正在传输的标志位
    }
}

void vTask_DMA_Circular_Buffer(void *pvParameters) {
	for(;;) {
        if (xSemaphoreTake(corporation.transmit_s, portMAX_DELAY) == pdTRUE) {
            DMA_Circular_Buffer_Transfer();
        }
	}
}
