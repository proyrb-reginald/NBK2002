#include "DMA-Buffer-Manager.h"
#include <string.h>

/**
 * @brief 启动DMA传输（内部函数）
 * @param Manager 管理器实例
 * @note 根据当前缓冲区状态配置DMA寄存器
 */
static void DMA_Buffer_Manager_Start(DMA_Buffer_Manager * const Manager)
{
	// 计算本次传输长度
	if (Manager->_Head > Manager->_Tail)
	{
		Manager->_Transmitting_Length = Manager->_Head - Manager->_Tail;
	}
	else
	{
		Manager->_Transmitting_Length = Manager->_Buffer_Length - Manager->_Tail; // 处理缓冲区环绕情况
	}
	// 配置DMA寄存器（假设使用DMA0通道）
	DMA_SetSrcAddress(DMA0, (uint32_t)&(Manager->_Buffer[Manager->_Tail])); // 设置源地址
	DMA_SetCurrDataCounter(DMA0, Manager->_Transmitting_Length); // 设置数据量
	DMA_SoftwareTrigger(DMA0); // 触发传输
}

/**
 * @brief 初始化DMA缓冲区管理器实现
 * @param Manager 管理器实例
 * @param Buffer_Length 缓冲区长度
 * @param Select_DMA 选定的DMA控制器
 * @param Select_Peripheral 外设地址
 * @param Peripheral_Type 外设类型
 */
void DMA_Buffer_Manager_Initialize
(
    DMA_Buffer_Manager * const Manager,
    const uint16_t Buffer_Length,
    DMA_TypeDef * const Select_DMA,
	void * const Select_Peripheral,
	DMA_Peripheral_Enum Peripheral_Type
) {
	// 参数有效性检查
    if (
        Manager == NULL || 								// 管理器指针有效性
        Buffer_Length == 0 || 							// 缓冲区长度非零
		((Buffer_Length & (Buffer_Length - 1)) != 0) || // 必须为2的幂次方
        ((Select_DMA != DMA0) && (Select_DMA != DMA1)) 	// DMA控制器有效性
    )
	{
        while(1); // 参数错误进入死循环（需根据实际项目替换为错误处理）
    }
	// 缓冲区初始化/重配置
    if (Manager->_Buffer == NULL)
	{
        Manager->_Buffer = (volatile uint8_t *)pvPortMalloc(Buffer_Length); // 首次分配内存
		configASSERT(Manager->_Buffer); // 内存分配检查
        Manager->_Buffer_Length = Buffer_Length;
    }
	else
	{
		// 已存在缓冲区时检查长度匹配
        if (Buffer_Length != Manager->_Buffer_Length)
		{
            vPortFree((void *)(Manager->_Buffer)); // 释放旧内存
            Manager->_Buffer = (volatile uint8_t *)pvPortMalloc(Buffer_Length); // 重新分配指定大小的内存
			configASSERT(Manager->_Buffer); // 内存分配检查
            Manager->_Buffer_Length = Buffer_Length;
        }
    }
	// 初始化管理器内部状态
    Manager->_Head = 0;
    Manager->_Tail = 0;
    Manager->_Transmitting_Length = 0;
    Manager->_Select_DMA = Select_DMA;
	Manager->_Select_Peripheral = Select_Peripheral;
	Manager->_Peripheral_Type = Peripheral_Type;
    Manager->_Resource_Occupy = xSemaphoreCreateMutex(); // 创建资源访问互斥锁
	configASSERT(Manager->_Resource_Occupy); // 资源创建检查
}

/**
 * @brief 数据写入缓冲区实现
 * @param Manager 管理器实例
 * @param Data_Pointer 数据源指针
 * @param Data_Input_Length 请求写入长度
 * @return 实际写入长度
 */
uint16_t DMA_Buffer_Manager_Input
(
    DMA_Buffer_Manager * const Manager,
    uint8_t * const Data_Pointer,
    uint16_t Data_Input_Length
) {
	// 获取互斥锁进入临界区
    if (xSemaphoreTake(Manager->_Resource_Occupy, portMAX_DELAY) == pdTRUE)
    {
		taskENTER_CRITICAL(); // 进入临界区
        uint16_t Free_Buffer_Length = (Manager->_Buffer_Length -
			(Manager->_Head - Manager->_Tail + 1)) &
			(Manager->_Buffer_Length - 1); // 计算可用空间（考虑环形缓冲区特性）
		// 缓冲区满
        if (Free_Buffer_Length == 0)
        {
            xSemaphoreGive(Manager->_Resource_Occupy); // 释放资源访问权限
			taskEXIT_CRITICAL(); // 退出临界区
            return 0;
        }
		// 限制写入长度不超过可用空间
        if (Data_Input_Length > Free_Buffer_Length)
        {
            Data_Input_Length = Free_Buffer_Length;
        }
		// 分段拷贝数据（处理缓冲区环绕）
        uint16_t First_Input_Length = Manager->_Buffer_Length - Manager->_Head;
        if (First_Input_Length > Data_Input_Length)
        {
            First_Input_Length = Data_Input_Length;
        }
		// 第一段拷贝
        memcpy((void *)&(Manager->_Buffer[Manager->_Head]), Data_Pointer, First_Input_Length);
        Manager->_Head = (Manager->_Head + First_Input_Length) & (Manager->_Buffer_Length - 1);
        uint16_t Inputted = First_Input_Length;
		// 第二段拷贝（如果存在环绕）
        if (Data_Input_Length > First_Input_Length)
        {
            uint16_t Second_Input_Length = Data_Input_Length - First_Input_Length;
			memcpy((void *)&Manager->_Buffer[Manager->_Head + 1], &Data_Pointer[First_Input_Length], Second_Input_Length);
			Manager->_Head = (Manager->_Head + Second_Input_Length + 1) & (Manager->_Buffer_Length - 1);
            Inputted += Second_Input_Length;
        }
		// 如果DMA当前未传输，启动新传输
		if (DMA_GetCurrDataCounter(DMA0) == 0)
		{
			DMA_Buffer_Manager_Start(Manager);
		}
        xSemaphoreGive(Manager->_Resource_Occupy); // 释放资源访问权限
		taskEXIT_CRITICAL(); // 退出临界区
        return Inputted; // 返回输入字节数
    }
    return 0;
}

/**
 * @brief DMA传输完成中断处理
 * @param Manager 管理器实例
 */
void DMA_Buffer_Manager_IRQHandler(DMA_Buffer_Manager * const Manager)
{
	Manager->_Tail = (Manager->_Tail +
		Manager->_Transmitting_Length) & (Manager->_Buffer_Length - 1); // 更新尾指针位置
	// 如果仍有待传输数据，启动下一次传输
	if (Manager->_Head != Manager->_Tail)
	{
		DMA_Buffer_Manager_Start(Manager);
	}
	else
	{
		Manager->_Transmitting_Length = 0; // 无更多数据时清空传输长度
	}
}
