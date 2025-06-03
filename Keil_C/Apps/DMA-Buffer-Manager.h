/**
 * @file DMA-Buffer-Manager.h
 * @brief DMA缓冲区管理模块头文件
 * @note 实现基于环形缓冲区的DMA数据流管理，支持线程安全操作
 */

#ifndef DMA_Buffer_Manager_H
#define DMA_Buffer_Manager_H

#include "SC_Init.h"
#include "FreeRTOS.h"
#include "semphr.h"

typedef enum {
	DMA_UART = 0,
	DMA_SPI,
	DMA_TWI,
} DMA_Peripheral_Enum;

/**
 * @struct DMA_Buffer_Manager
 * @brief DMA缓冲区管理器核心结构体
 */
typedef struct
{
    volatile uint8_t *   _Buffer;			   // 指向缓冲区存储空间的指针
    volatile uint16_t    _Head;				   // 数据写入指针（生产者端）
    volatile uint16_t    _Tail;				   // 数据读取指针（消费者端）
    volatile uint16_t    _Transmitting_Length; // 当前正在传输的数据长度
    uint16_t             _Buffer_Length;	   // 缓冲区总长度（必须为2的幂次方）
    DMA_TypeDef *      	 _Select_DMA;		   // 选定的DMA控制器
    void *               _Select_Peripheral;   // 目标外设地址
	DMA_Peripheral_Enum  _Peripheral_Type;	   // 外设类型标识
    SemaphoreHandle_t    _Resource_Occupy;	   // 资源访问互斥锁
} DMA_Buffer_Manager;

/**
 * @brief 初始化DMA缓冲区管理器
 * @param Manager 指向管理器实例的指针
 * @param Buffer_Length 缓冲区长度（必须为2的幂次方）
 * @param Select_DMA 选定的DMA控制器（DMA0/DMA1）
 * @param Select_Peripheral 目标外设地址
 * @param Peripheral_Type 外设类型枚举
 * @note 如果缓冲区指针为空则自动分配内存
 *       如果已存在缓冲区但长度不匹配则重新分配
 */
void DMA_Buffer_Manager_Initialize(
    DMA_Buffer_Manager * const Manager,
    const uint16_t Buffer_Length,
    DMA_TypeDef * const Select_DMA,
	void * const Select_Peripheral,
	DMA_Peripheral_Enum Peripheral_Enum
);

/**
 * @brief 向缓冲区写入数据
 * @param Manager 管理器实例
 * @param Data_Pointer 指向数据源的指针
 * @param Data_Input_Length 要写入的数据长度
 * @return 实际写入的字节数（可能小于请求长度）
 * @note 该函数线程安全，内部使用互斥锁和临界区保护
 */
uint16_t DMA_Buffer_Manager_Input(
    DMA_Buffer_Manager * const Manager,
    uint8_t * const Data_Pointer,
    uint16_t Data_Input_Length
);
	
/**
 * @brief DMA传输完成中断处理程序
 * @param Manager 管理器实例
 * @note 需在DMA传输完成中断中调用此函数
 */
void DMA_Buffer_Manager_IRQHandler(DMA_Buffer_Manager * const Manager);

#endif // DMA_Buffer_Manager_H
