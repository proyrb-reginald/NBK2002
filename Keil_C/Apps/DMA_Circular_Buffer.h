/**************************************************
@简介：为DMA设计的环形异步发送缓冲区
**************************************************/

#ifndef DMA_CIRCULAR_BUFFER_H
#define DMA_CIRCULAR_BUFFER_H

/******************** 导入头文件 ********************/

#include "SC_Init.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

/******************** 宏定义 ********************/

#define DMA_Select USE_DMA0          // 可选值：USE_UART0_DMA0、USE_UART0_DMA1、USE_UART1_DMA0、USE_UART1_DMA1
#define DMA_CIRCULAR_BUFFER_SIZE 256 // 环形缓冲区大小

/******************** 类型声明 ********************/

/******************** 变量声明 ********************/

/******************** 函数声明 ********************/

extern void DMA_Circular_Buffer_Init(void);                         // 初始化（必须先调用）
extern int  DMA_Circular_Buffer_Write(uint8_t *data, uint16_t len); // 写入多字节
extern void DMA_Circular_Buffer_IRQHandler(void);                   // 中断处理（必须在选择的DMA的中断中调用）
extern void vTask_DMA_Circular_Buffer(void *pvParameters);          // RTOS任务（必须创建）

#endif // DMA_CIRCULAR_BUFFER_H
