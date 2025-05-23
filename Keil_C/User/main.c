/**
 *****************************************************************************************************
  * @copyright	(c)  Shenzhen Saiyuan Microelectronics Co., Ltd
  * @file	         main.c
  * @author	 
  * @version 	
  * @date	
  * @brief	         
  * @details         Contains the MCU initialization function and its H file
 *****************************************************************************************************
 * @attention
 *
 *****************************************************************************************************
 */
/*******************Includes************************************************************************/

#include "SC_Init.h"
#include "SC_it.h"
#include "..\Drivers\SCDriver_list.h"
#include "HeadFiles\SysFunVarDefine.h"
#include "FreeRTOS.h"
#include "task.h"
#include "UART_Circular_Buffer.h"
#include "print.h"

/**************************************Generated by EasyCodeCube*************************************/
//Forbid editing areas between the labels !!!

/*************************************.Generated by EasyCodeCube.************************************/

void task(void *parm) {
	for(;;) {
        //print("start: head: %u; tail: %u;\n", uart.tx_buffer.head, uart.tx_buffer.tail);
        print("Hello, world, UART, DMA, FreeRTOS, ProYRB!\n");
        //print("End: head: %u; tail: %u;\n", uart.tx_buffer.head, uart.tx_buffer.tail);
        //UART_Buffer_WriteMulti(&uart, (const uint8_t *)msg, strlen(msg));
        //UART_Buffer_WriteMulti(&uart, (const uint8_t *)msg, strlen(msg));
	    vTaskDelay(500);
	    GPIO_TogglePins(GPIOB, GPIO_Pin_15);
	}
}

/**
  * @brief This function implements main function.
  * @note 
  * @param
  */
int main(void)
{
    /*<Generated by EasyCodeCube begin>*/
    /*<UserCodeStart>*//*<SinOne-Tag><36>*/
    
    IcResourceInit();
    UART_CircularBuffer_Init(&uart);

    /*<UserCodeEnd>*//*<SinOne-Tag><36>*/
    /*<UserCodeStart>*//*<SinOne-Tag><4>*/

    xTaskCreate(task, "task", 256, NULL, 1, NULL);
    vTaskStartScheduler();
    
    /*****MainLoop*****/
    while(1) {
        /*<UserCodeStart>*//*<SinOne-Tag><14>*/
        /***User program***/
        /*<UserCodeEnd>*//*<SinOne-Tag><14>*/
        /*<Begin-Inserted by EasyCodeCube for Condition>*/
    }
    /*<UserCodeEnd>*//*<SinOne-Tag><4>*/
    /*<Generated by EasyCodeCube end>*/
}
