#ifndef UART_CIRCULAR_BUFFER_H
#define UART_CIRCULAR_BUFFER_H

#include <stdint.h>
#include <string.h>
#include "FreeRTOS.h"
#include "semphr.h"

#define TX_BUFFER_SIZE 256  // 建议增大缓冲区以适应DMA传输
#define TX_BUFFER_SIZE_MASK (TX_BUFFER_SIZE - 1) 

// 环形缓冲区结构
typedef struct {
    uint8_t buffer[TX_BUFFER_SIZE];
    volatile uint16_t head;
    volatile uint16_t tail;
} RingBuffer;

// 串口缓冲模块结构
typedef struct {
    RingBuffer tx_buffer;
    volatile uint8_t transmitting;   // 是否正在发送
    volatile uint16_t transmit_size;
    SemaphoreHandle_t using_s;       // 互斥信号量
    SemaphoreHandle_t transmit_s;    // 同步信号量
} UART_CircularBuffer;

extern UART_CircularBuffer uart1;

// 初始化环形缓冲区结构体
void UART_CircularBuffer_Init(UART_CircularBuffer *uart);

// 写入多字节数据
int UART_Buffer_Write(UART_CircularBuffer *uart, const uint8_t *data, uint16_t len);

// 启动DMA传输
void UART_Buffer_StartDMATransfer(UART_CircularBuffer *uart);

// 启动DMA传输任务
void vTask_StartTransmit(void *pvParameters);

// DMA中断处理函数
void UART_Buffer_DMA_IRQHandler(UART_CircularBuffer *uart);

#endif // UART_CIRCULAR_BUFFER_H
