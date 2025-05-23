/**
  ******************************************************************************
  * @file    SC32F15GXX.h
  * @author  SOC SA Team
  * @brief   CMSIS Cortex-M0+ Device Peripheral Access Layer Header File.
  *          This file contains all the peripheral register's definitions, bits
  *          definitions and memory mapping for SC32M156XX devices.
  *
  *          This file contains:
  *           - Data structures and the address mapping for all peripherals
  *           - Peripheral's registers declarations and bits definition
  *           - Macros to access peripheral's registers hardware
  *
  ******************************************************************************
  ******************************************************************************
  */

/** @addtogroup CMSIS_Device
  * @{
  */

/** @addtogroup sc32M156XX V0.2
  * @{
  */


#ifndef SC32F15GXX_H
#define SC32F15GXX_H



#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */


/**
  * @brief Configuration of the Cortex-M0+ Processor and Core Peripherals
   */
#define __CM0PLUS_REV             0U /*!< Core Revision r0p0                            */
#define __MPU_PRESENT             1U /*!< Coretex Mo+  provides an MPU                  */
#define __VTOR_PRESENT            1U /*!< Vector  Table  Register supported             */
#define __NVIC_PRIO_BITS          2U /*!< sc32m1xxx uses 2 Bits for the Priority Levels 			*/
#define __Vendor_SysTickConfig    0U /*!< Set to 1 if different SysTick Config is used  */

/**
  * @}
  */

/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */
/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */

#if !defined  (HIRC_VALUE)
#define HIRC_VALUE    ((uint32_t)48000000) /*!< Value of the Internal oscillator in Hz*/
#endif /* HIRC_VALUE */
   
#if !defined  (LXT_VALUE)
#define LXT_VALUE    ((uint32_t)32768) /*!< Default value of the External Low speed oscillator in Hz */
#endif /* LXT_VALUE */

#if !defined  (LIRC_VALUE)
#define LIRC_VALUE    ((uint32_t)32000) /*!< Value of the Internal Low speed oscillator in Hz*/
#endif /* LIRC_VALUE */

/**
 * @brief SC32M156x Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */

/*!< Interrupt Number Definition */
typedef enum
{
    /******  Cortex-M0+ Processor Exceptions Numbers ***************************************************************/
    NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                          */
    HardFault_IRQn              = -13,    /*!< 3 Cortex-M Hard Fault Interrupt                                   */
    SVC_IRQn                    = -5,     /*!< 11 Cortex-M SV Call Interrupt                                     */
    PendSV_IRQn                 = -2,     /*!< 14 Cortex-M Pend SV Interrupt                                     */
    SysTick_IRQn                = -1,     /*!< 15 Cortex-M System Tick Interrupt                                 */
    /******  SC32m156x specific Interrupt Numbers ****************************************************************/
    INT0_IRQn                  = 0,      /*!< INT  0 Interrupt                                                 */
    INT1_7_IRQn                = 1,      /*!< INT Line from 1 to 7  Interrupt                                  */
    INT8_11_IRQn               = 2,      /*!< INT Line from 8 to 11  Interrupt                                 */
    INT12_15_IRQn              = 3,      /*!< INT Line from 12 to 15  Interrupt                                */
    RCC_IRQn                    = 4,      /*!< RCC shut down Interrupts                                          */
    BTM_IRQn                    = 6,      /*!< BTM  Interrupts                                                   */
    UART0_2_IRQn                = 7,      /*!< UART0 and UART2 Interrupts                                        */
    UART1_IRQn                  = 8,      /*!< UART1  Interrupts                                                 */
    SPI0_IRQn                   = 9,      /*!< SPI0 Interrupts                                                   */
    SPI1_TWI1_IRQn              = 10,     /*!< SPI1 and TWI1 Interrupts                                          */
    DMA0_IRQn                   = 11,     /*!< DMA0 Interrupts                                                   */
    DMA1_IRQn                   = 12,     /*!< DMA1 Interrupts                                                   */
    DMA2_IRQn                   = 13,     /*!< DMA2 Interrupts                                                   */
    DMA3_IRQn                   = 14,     /*!< DMA3 Interrupts                                                   */
    TIMER0_IRQn                 = 15,     /*!< TIMER0 global Interrupts                                          */
    TIMER1_IRQn                 = 16,     /*!< TIMER1 global Interrupt                                           */
    TIMER2_IRQn                 = 17,     /*!< TIMER2 global Interrupt                                           */
    TIMER3_IRQn                 = 18,     /*!< TIMER3 global Interrupt                                           */
    QEP0_IRQn                   = 20,     /*!< QEP0 Interrupt                                                    */
    OP1_OP2_IRQn                = 22,     /*!< OP1 and  OP2 Interrupt                                            */
    TWI0_IRQn                   = 23,     /*!< TWI0 Interrupt                                                    */
    QEP1_IRQn                   = 24,     /*!< TWI1 Interrupt                                            	       */
    CAN_IRQn                    = 28,     /*!< CAN  Interrupt                                                    */
    ADC_IRQn                    = 29,     /*!< ADC  Interrupt                                            	       */
    CMP0_1_2_IRQn              = 30,     /*!< CMP0_1_2 to CMP0_1_2  Interrupt                                   	       */
    CMP3_IRQn                   = 31,     /*!< CMP  Interrupt                                                   */
} IRQn_Type;

/**
  * @}
  */

#include "core_cm0plus.h"               /* Cortex-M0+ processor and core peripherals */
#include <stdint.h>




/** @addtogroup Exported_types
  * @{
  */
typedef int32_t s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef const int32_t sc32;  /*!< Read Only */
typedef const int16_t sc16;  /*!< Read Only */
typedef const int8_t sc8;   /*!< Read Only */

typedef __IO int32_t  vs32;
typedef __IO int16_t  vs16;
typedef __IO int8_t   vs8;

typedef __I int32_t vsc32;  /*!< Read Only */
typedef __I int16_t vsc16;  /*!< Read Only */
typedef __I int8_t vsc8;   /*!< Read Only */

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef const uint32_t uc32;  /*!< Read Only */
typedef const uint16_t uc16;  /*!< Read Only */
typedef const uint8_t uc8;   /*!< Read Only */

typedef __IO uint32_t  vu32;
typedef __IO uint16_t vu16;
typedef __IO uint8_t  vu8;

typedef __I uint32_t vuc32;  /*!< Read Only */
typedef __I uint16_t vuc16;  /*!< Read Only */
typedef __I uint8_t vuc8;   /*!< Read Only */

typedef enum
{
    RESET = 0,
    SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
    DISABLE = 0,
    ENABLE = !DISABLE
} FunctionalState;

#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum
{
    SUCCESS = 0,
    ERROR = !SUCCESS
} ErrorStatus;

typedef enum
{
    FALSE = 0,
    TRUE = !FALSE
} boolType;


/** @addtogroup Exported_macros
  * @{
  */
#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

/* Peripheral for APB0=0x40020000
	 Peripheral for APB1=0x40021000
   Peripheral for APB2=0x40022000
*/
/**
  * @brief RCCAPB0 for APB0,Peripheral offset =0x00
  */
typedef struct
{
    __IO uint32_t APB0_CFG;       	 /*!< APB0 Config register,      Address offset: 0x00 */
    __IO uint32_t APB0_RST;          /*!< APB0 Reset register,       Address offset: 0x04 */
} RCCAPB0_TypeDef;

/**
  * @brief RCCAPB1 for APB1,Peripheral offset =0x00
  */
typedef struct
{
    __IO uint32_t APB1_CFG;       	 /*!< APB1 Config register,      Address offset: 0x00 */
    __IO uint32_t APB1_RST;          /*!< APB1 Reset register,       Address offset: 0x04 */
} RCCAPB1_TypeDef;

/**
  * @brief RCCAPB2 for APB2,Peripheral offset =0x00
  */
typedef struct
{
    __IO uint32_t APB2_CFG;       	 /*!< APB2 Config register,      Address offset: 0x00 */
    __IO uint32_t APB2_RST;          /*!< APB2 Reset register,       Address offset: 0x04 */
} RCCAPB2_TypeDef;


/** @addtogroup Peripheral_registers_structures
  * @{
  */
/**
  * @brief UART0-1 for APB0,UART2 for APB1,UART3 for APB2,UART0/2/3 Peripheral offset =0x20,UART1 Peripheral offset=0x80
  */
typedef struct
{
    __IO uint32_t UART_CON;       	 /*!< UART Config register,      	Address offset: 0x00 */
    __IO uint32_t UART_STS;          /*!< UART Status register,       Address offset: 0x04 */
    __IO uint32_t UART_BAUD;         /*!< UART BaudRate register, 		Address offset: 0x08 */
    __IO uint32_t UART_DATA;         /*!< UART Data register,   			Address offset: 0x0C */
    __IO uint32_t UART_IDE;     		 /*!< UART Interrupt /Dma Enable register,   Address offset: 0x10 */
} UART_TypeDef;

/**
  * @brief SPI0 for APB0 ,Peripheral offset =0x40
  */
typedef struct
{
    __IO uint32_t SPI_CON;       	  /*!< SPI Control register,      Address offset: 0x00 */
    __IO uint32_t SPI_STS;          /*!< SPI Status register,       Address offset: 0x04 */
    __IO uint32_t RESERVED;         /*!< Reserved, 									Address offset: 0x08 */
    __IO uint32_t SPI_DATA;         /*!< SPI Data register,   			Address offset: 0x0C */
    __IO uint32_t SPI_IDE;     		  /*!< SPI Interrupt /Dma Enable register,   Address offset: 0x10 */
} SPI_TypeDef;

/**
  * @brief TWI0 for APB0 ,Peripheral offset =0x60
  */
typedef struct
{
    __IO uint32_t TWI_CON;       	  /*!< TWI Config register,      	Address offset: 0x00 */
    __IO uint32_t TWI_STS;          /*!< TWI Status register,       Address offset: 0x04 */
    __IO uint32_t TWI_ADD;          /*!< TWI Adress register, 			Address offset: 0x08 */
    __IO uint32_t TWI_DATA;         /*!< TWI Data register,   			Address offset: 0x0C */
    __IO uint32_t TWI_IDE;     		  /*!< TWI Interrupt /Dma Enable register,   Address offset: 0x10 */
} TWI_TypeDef;

/**
  * @brief SPI1_TWI1 for APB1 ,Peripheral offset =0x40
  */
typedef struct
{
    __IO uint32_t SPI1_TWI1_CON;    /*!< SPI1_TWI1 Control register,      Address offset: 0x00 */
    __IO uint32_t SPI1_TWI1_STS;    /*!< SPI1_TWI1 Status register,       Address offset: 0x04 */
    __IO uint32_t TWI1_ADD;         /*!< TWI1 Address register, 		      Address offset: 0x08 */
    __IO uint32_t SPI1_TWI1_DATA;   /*!< SPI1_TWI1 Data register,   			Address offset: 0x0C */
    __IO uint32_t SPI1_TWI1_IDE;    /*!< SPI1_TWI1 Interrupt /Dma Enable register,   Address offset: 0x10 */
} SPITWI_TypeDef;



/**
  * @brief TIEMR0123 for APB0,, Peripheral offset=0x100+0x40*n(n=0,1,2,3)
  */
typedef struct
{
    __IO uint32_t TIM_CON;       		/*!< TCON register,      Address offset: 0x00 */
    __IO uint32_t TIM_CNT;          /*!< TCNT register,       Address offset: 0x04 */
    __IO uint32_t TIM_RLD;          /*!< TIMER ReLoad register, Address offset: 0x08 */
    __IO uint32_t TIM_STS;          /*!< TIMER Status register,   Address offset: 0x0C */
    __IO uint32_t TIM_PDTA_RCAP;    /*!< TIMER Rise Caputre Key register,   Address offset: 0x10 */
    __IO uint32_t TIM_PDTB_FCAP;    /*!< TIMER fall Caputre register,   Address offset: 0x14 */
    __IO uint32_t TIM_IDE;          /*!< TIMER Interrupt /Dma Enable register,  Address offset: 0x18 */
} TIM_TypeDef;

/**
  * @brief PWM1 for APB2, PWM0 Peripheral offset=0x200,PWM1 Peripheral offset=0x300,
  */
typedef struct
{
    __IO uint32_t TS_CFG;            /*!< TS Control register,             Address offset: 0x00 */

} TS_TypeDef;


/**
  * @brief BTM for APB2,Peripheral offset=0x100
  */
typedef struct
{
    __IO uint32_t BTM_CON;       	  /*!< ADC Control register,      Address offset: 0x00 */
    __IO uint32_t BTM_STS;          /*!< ADC Status register,       Address offset: 0x04 */
} BTM_TypeDef;

/**
  * @brief ADC for APB2,Peripheral offset=0x110
  */
typedef struct
{
    __IO uint32_t ADC_CON;       	  /*!< ADC Control register,      Address offset: 0x00 */
    __IO uint32_t ADC_STS;          /*!< ADC Status register,       Address offset: 0x04 */
    __IO uint32_t ADC_VALUE;        /*!< ADC Value register, 				Address offset: 0x08 */
    __IO uint32_t ADC_CFG;          /*!< ADC Config register,   		Address offset: 0x0C */
    __IO uint32_t ADC_TH_CFG;       /*!< ADC Config register,   		Address offset: 0x10 */
    __IO uint32_t ADC_LOWTH;        /*!< ADC Config register,   		Address offset: 0x14 */
    __IO uint32_t ADC_UPTH;         /*!< ADC Config register,   		Address offset: 0x18 */
    __IO uint32_t ADC_IDE;          /*!< ADC Config register,   		Address offset: 0x1C */
	__IO uint32_t RESERVED0;          /*!< ADC Config register,   		Address offset: 0x20 */
    __IO uint32_t ADC_SQCNT;        /*!< ADC Config register,   		Address offset: 0x24 */
    __IO uint32_t ADC_SQ0;          /*!< ADC Config register,   		Address offset: 0x28 */
} ADC_TypeDef;


/**
  * @brief CMP for APB2,Peripheral offset=0x170
  */
typedef struct
{
    __IO uint32_t CMP_STS;          /*!< CMP Status register,       Address offset: 0x00 */
    __IO uint32_t CMP_CON;          /*!< CMP Status register,       Address offset: 0x04 */
    __IO uint32_t CMP_IDE;          /*!< CMP Config register, 			 Address offset: 0x08 */
    __IO uint32_t CMP_CFG;          /*!< CMP Config register, 			 Address offset: 0x0C */
    __IO uint32_t CMP_CFG1;          /*!< CMP Config register, 			 Address offset: 0x10 */
    __IO uint32_t CMP_CFG2;          /*!< CMP Config register, 			 Address offset: 0x14 */

} CMP_TypeDef;

/**
  * @brief PGA for APB2,Peripheral offset=0x140
  */
typedef struct
{
    __IO uint32_t OP0_CON;          /*!< CMP Control register,       Address offset: 0x00 */
    __IO uint32_t OP1_CON;          /*!< CMP Control register,       Address offset: 0x00 */
    __IO uint32_t RESERVED0;
    __IO uint32_t OP2_CON;
    __IO uint32_t OPX_CFG;
    __IO uint32_t OPX_STS;
    __IO uint32_t OPX_IDE;
} OP_TypeDef;

/**
  * @brief DAC for APB2,Peripheral offset=0x190
  */
typedef struct
{
    __IO uint32_t DAC_STS;           /*!< DAC Channel register,          	Address offset: 0x00 */
    __IO uint32_t DAC_IN;            /*!< DAC Input channel register, 		Address offset: 0x04 */
    __IO uint32_t DAC_CFG;           /*!< DAC Control register, 				  Address offset: 0x08 */
    __IO uint32_t VREF_CFG;          /*!< DAC Config register, 				  	Address offset: 0x0C */
} DAC_VREF_TypeDef;

/**
  * @brief DAC for APB2,Peripheral offset=0x190
  */
typedef struct
{
    __IO uint32_t DAC_STS;           /*!< DAC Channel register,          	Address offset: 0x00 */
    __IO uint32_t DAC_IN;            /*!< DAC Input channel register, 		Address offset: 0x04 */
    __IO uint32_t DAC_CFG;           /*!< DAC Control register, 				  Address offset: 0x08 */
} DAC_TypeDef;

/**
  * @brief DAC for APB2,Peripheral offset=0x19C
  */
typedef struct
{
    __IO uint32_t VREF_CFG;          /*!< DAC Config register, 				  	Address offset: 0x00 */
} VREF_TypeDef;


/**
  * @brief QEP for APB2,Peripheral offset=0x20
  */
typedef struct
{
    __IO uint32_t QEP_CON;          /*!< Display Drive Control register,      Address offset: 0x00 */
    __IO uint32_t QEP_PCNT;         /*!< Display Drive Config register, 	  Address offset: 0x04 */
    __IO uint32_t QEP_PMAX;         /*!< Segment IO Enable register, 		  Address offset: 0x08 */
    __IO uint32_t QEP_STS;          /*!< Segment IO Enable register, 		  Address offset: 0x0C */
    __IO uint32_t QEP_IDE;          /*!< COM IO Enable register register, 	  Address offset: 0x10 */
} QEP_TypeDef;



/*
	 Peripheral for IOPORT=0x40011000
*/
/**
  * @brief GPIO for IOPORT,Peripheral offset=0x100*n(n=0,1,2)
  */
typedef struct
{
    __IO uint32_t PIN;        			/*!< GPIOA,B,C register,               Address offset: 0x00      */
    __IO uint32_t RESERVED0[7];		/*!< Reserved, 									    	 Address offset: 0x04 			*/
    __IO uint32_t PXCON;     			/*!< GPIO port Control register,       Address offset: 0x20     	*/
    __IO uint32_t RESERVED1[7];		/*!< Reserved, 									    	 Address offset: 0x24 			*/
    __IO uint32_t PXPH;       		/*!< GPIO port pull-up/pull-down register, Address offset: 0x40    */
    __IO uint32_t RESERVED2[7];		/*!< Reserved, 									    	 Address offset: 0x44 			*/
    __IO uint32_t PXLEV;  				/*!< GPIO port Level register, 					Address offset: 0x60    	*/
} GPIO_TypeDef;


/**
  * @brief GPIO for IOPORT BIT,Peripheral offset=0x100*n(n=0,1,2)
  */
typedef struct
{
    __IO uint8_t PIN_BIT[16];       /*!< GPIOA,B,C Bit register,               Address offset: 0x00      */
    __IO uint8_t PIN_XR[16];       /*!< GPIOA,B,C Bit register,               Address offset: 0x20      */
} GPIO_BIT_TypeDef;


/**
  * @brief INT for IOPORT,Peripheral offset=0x300
  */
typedef struct
{
    __IO uint32_t INTF_IE;        /*!< INT Fall edge Enable register,   Address offset: 0x00      */
    __IO uint32_t RESERVED0[7];		/*!< Reserved, 									    	 Address offset: 0x04 			*/
    __IO uint32_t INTR_IE;     		/*!< INT Rise edge Enable register register,       Address offset: 0x20     	*/
    __IO uint32_t RESERVED1[7];		/*!< Reserved, 									    	 Address offset: 0x24 			*/
    __IO uint32_t INT_SEL0;       /*!< INT0-7 Port Select register, Address offset: 0x40    */
    __IO uint32_t RESERVED2[7];		/*!< Reserved, 									    	 Address offset: 0x44 			*/
    __IO uint32_t INT_SEL1;       /*!< INT8-15 Port Select register, Address offset: 0x60    */
    __IO uint32_t RESERVED3[7];		/*!< Reserved, 									    	 Address offset: 0x64 			*/
    __IO uint32_t INTF_CON;       /*!< INT Fall Control  register, Address offset: 0x80    */
    __IO uint32_t RESERVED4[7];		/*!< Reserved, 									    	 Address offset: 0x84 			*/
    __IO uint32_t INTR_CON;       /*!< INT Rise Control register, Address offset: 0xA0    */
    __IO uint32_t RESERVED5[7];		/*!< Reserved, 									    	 Address offset: 0xA4 			*/
    __IO uint32_t INTF_STS;       /*!< INT Fall Status  register, Address offset: 0xC0    */
    __IO uint32_t RESERVED6[7];		/*!< Reserved, 									    	 Address offset: 0xC4 			*/
    __IO uint32_t INTR_STS;       /*!< INT Rise status register, Address offset: 0xE0    */
    __IO uint32_t RESERVED7[7];		/*!< Reserved, 									    	 Address offset: 0xE4 			*/
} INT_TypeDef;

/*
	 Peripheral for AHB=0x40000000
*/
/**
  * @brief WDT for AHB,Peripheral offset=0x330
  */
typedef struct
{
    __IO uint32_t RESERVED0[3];     /*!< Reserved,      Address offset: 0x00 */
    __IO uint32_t WDT_CON;      		/*!< WDT Control register, 			Address offset: 0x0C */
    __IO uint32_t WDT_CFG;          /*!< WDT Config register, 			Address offset: 0x10 */
} WDT_TypeDef;

/**
  * @brief IAP for AHB,Peripheral offset=0x3C0
  */
typedef struct
{
    __IO uint32_t IAPKEY;     			/*!< IAP KEY register,      		Address offset: 0x00 */
    __IO uint32_t IAP_SNB;      		/*!< IAP Sector Number register, 			Address offset: 0x04 */
    __IO uint32_t RESERVED0;     		/*!< Reserved,      Address offset: 0x08 */
    __IO uint32_t IAP_CON;          /*!< IAP Control register, 			Address offset: 0x0C */
} IAP_TypeDef;


/**
  * @brief OPT for AHB,Peripheral offset=0x3F8
  */
typedef struct
{
    __IO uint32_t OPINX;     			/*!< IAP KEY register,      		Address offset: 0x00 */
    __IO uint32_t OPREG;      		/*!< IAP Sector Number register, 			Address offset: 0x04 */
} OPT_TypeDef;

/**
  * @brief CRC for AHB,Peripheral offset=0x2000
  */
typedef struct
{
	__IO uint32_t CRC_DR;     			/*!< CRC Data register,      		Address offset: 0x00 */
	__IO uint32_t CRC_CON;      		/*!< CRC Config register, 			Address offset: 0x04 */
	__IO uint32_t CRC_INT;     		  /*!< CRC Inital register,      Address offset: 0x08 */
	__IO uint32_t CRC_POL;          /*!< CRC Poly  register, 			Address offset: 0x0C */
} CRC_TypeDef;


/**
  * @brief RCCAHB for AHB,Peripheral offset =0x3000
  */
typedef struct
{
    __IO uint32_t AHB_CFG;       	 /*!< APB2 Config register,      Address offset: 0x00 */
    __IO uint32_t AHB_RST;         /*!< APB2 Reset register,       Address offset: 0x04 */
} RCCAHB_TypeDef;

/**
  * @brief RCC for AHB,Peripheral offset=0x3014
  */
typedef struct
{
    __IO uint32_t RCC_KEY;        /*!< RCC Config0 register,    Address offset: 0x00 */
    __IO uint32_t RCC_REV;        /*!< Reserved,                Address offset: 0x04 */
    __IO uint32_t RCC_CFG0;       /*!< RCC Config0 register,    Address offset: 0x08 */
    __IO uint32_t RCC_CFG1;       /*!< RCC Config1 register,    Address offset: 0x0C */
    __IO uint32_t RESERVED0;      /*!< Reserved,                Address offset: 0x10 */
    __IO uint32_t RCC_STS;        /*!< RCC Status  register,    Address offset: 0x14 */
    __IO uint32_t RESERVED1;      /*!< Reserved,                Address offset: 0x18 */
    __IO uint32_t SYST_CALIB;     /*!< RCC Calib  register,     Address offset: 0x1C */
    __IO uint32_t NMI_CFG;
} RCC_TypeDef;


/*
	 Peripheral for DMA=AHB+0x10800
*/
/**
  * @brief DMA0..DMA3 Peripheral offset=0x40*n(n=0,1,2,3)
  */
typedef struct
{
    __IO uint32_t DMA_SADR;     		/*!< DMA Source Adress register,    Address offset: 0x00 */
    __IO uint32_t DMA_DADR;      		/*!< DMA Destination Adress register, 		Address offset: 0x04 */
    __IO uint32_t DMA_CFG;     		  /*!< DMA Config register,     Address offset: 0x08 */
    __IO uint32_t DMA_CNT;          /*!< DMA Count  register, 		Address offset: 0x0C */
    __IO uint32_t DMA_STS;          /*!< DMA Status register, 		Address offset: 0x10 */
} DMA_TypeDef;
/**
  * @brief CAN for AHB,Peripheral offset=0x10C00
  */
typedef struct
{
    __IO uint32_t CAN_RX_ID;     		/*!< CAN Receive Buffer ID register,    Address offset: 0x00 */
    __IO uint32_t CAN_RX_CTRL;   		/*!< CAN Receive Control register,      Address offset: 0x04 */
    __IO uint32_t CAN_RBUF[15];     		/*!< CAN Receive Buffer0 register,      Address offset: 0x08 */
	  __IO uint32_t CAN_RBUF0;     		/*!< CAN Receive Buffer0 register,      Address offset: 0x08 */
    __IO uint32_t CAN_RBUF1;     		/*!< CAN Receive Buffer1 register,      Address offset: 0x0C */
    __IO uint32_t CAN_RBUF2;     		/*!< CAN Receive Buffer2 register,      Address offset: 0x10 */
    __IO uint32_t CAN_RBUF3;     		/*!< CAN Receive Buffer3 register,      Address offset: 0x14 */
    __IO uint32_t CAN_RBUF4;     		/*!< CAN Receive Buffer4 register,      Address offset: 0x18 */
    __IO uint32_t CAN_RBUF5;     		/*!< CAN Receive Buffer5 register,      Address offset: 0x1C */
    __IO uint32_t CAN_RBUF6;     		/*!< CAN Receive Buffer6 register,      Address offset: 0x20 */
    __IO uint32_t CAN_RBUF7;     		/*!< CAN Receive Buffer7 register,      Address offset: 0x24 */
    __IO uint32_t CAN_RBUF8;     		/*!< CAN Receive Buffer8 register,      Address offset: 0x28 */
    __IO uint32_t CAN_RBUF9;		  	/*!< CAN Receive Buffer9 register,      Address offset: 0x2C */
    __IO uint32_t CAN_RBUF10;		  	/*!< CAN Receive Buffer10 register,     Address offset: 0x30 */
    __IO uint32_t CAN_RBUF11;			  /*!< CAN Receive Buffer11 register,     Address offset: 0x34 */
    __IO uint32_t CAN_RBUF12;		  	/*!< CAN Receive Buffer12 register,     Address offset: 0x38 */
    __IO uint32_t CAN_RBUF13;			  /*!< CAN Receive Buffer13 register,     Address offset: 0x3C */
    __IO uint32_t CAN_RBUF14;			  /*!< CAN Receive Buffer14 register,     Address offset: 0x40 */
    __IO uint32_t CAN_RBUF15;			  /*!< CAN Receive Buffer15 register,     Address offset: 0x44 */
    __IO uint32_t CAN_RTSL;				  /*!< CAN Receive TimeStampLow register, Address offset: 0x48 */
    __IO uint32_t CAN_RTSH;				  /*!< CAN Receive TimeStampHigh register,Address offset: 0x4C */
} CAN_RX_BUFFER_TypeDef;

typedef struct
{
    __IO uint32_t CAN_TX_ID;     		/*!< CAN Transmit Buffer ID register,  Address offset: 0x50 */
    __IO uint32_t CAN_TX_CTRL;   		/*!< CAN Transmit Control register,    Address offset: 0x54 */
    __IO uint32_t CAN_TBUF[15];     		/*!< CAN Transmit Buffer0 register,    Address offset: 0x58 */
	  __IO uint32_t CAN_TBUF0;     		/*!< CAN Transmit Buffer0 register,    Address offset: 0x58 */
    __IO uint32_t CAN_TBUF1;     		/*!< CAN Transmit Buffer1 register,    Address offset: 0x5C */
    __IO uint32_t CAN_TBUF2;     		/*!< CAN Transmit Buffer2 register,    Address offset: 0x60 */
    __IO uint32_t CAN_TBUF3;     		/*!< CAN Transmit Buffer3 register,    Address offset: 0x64 */
    __IO uint32_t CAN_TBUF4;     		/*!< CAN Transmit Buffer4 register,    Address offset: 0x68 */
    __IO uint32_t CAN_TBUF5;     		/*!< CAN Transmit Buffer5 register,    Address offset: 0x6C */
    __IO uint32_t CAN_TBUF6;     		/*!< CAN Transmit Buffer6 register,    Address offset: 0x70 */
    __IO uint32_t CAN_TBUF7;     		/*!< CAN Transmit Buffer7 register,    Address offset: 0x74 */
    __IO uint32_t CAN_TBUF8;     		/*!< CAN Transmit Buffer8 register,    Address offset: 0x78 */
    __IO uint32_t CAN_TBUF9;     		/*!< CAN Transmit Buffer9 register,    Address offset: 0x7C */
    __IO uint32_t CAN_TBUF10;    		/*!< CAN Transmit Buffer10 register,    Address offset: 0x80 */
    __IO uint32_t CAN_TBUF11;    		/*!< CAN Transmit Buffer11 register,    Address offset: 0x84 */
    __IO uint32_t CAN_TBUF12;    		/*!< CAN Transmit Buffer12 register,    Address offset: 0x88 */
    __IO uint32_t CAN_TBUF13;    		/*!< CAN Transmit Buffer13 register,    Address offset: 0x8C */
    __IO uint32_t CAN_TBUF14;    		/*!< CAN Transmit Buffer14 register,    Address offset: 0x90 */
    __IO uint32_t CAN_TBUF15;    		/*!< CAN Transmit Buffer15 register,    Address offset: 0x94 */
    __IO uint32_t CAN_TTSL;          /*!< CAN TimestampLow Timer register, Address offset: 0xD0 */  /*V0.3新增*/
    __IO uint32_t CAN_TTSH;          /*!< CAN TimestampHigh Timer register,    Address offset: 0xD4 */  
} CAN_TX_BUFFER_TypeDef;

typedef struct
{
    __IO uint32_t CAN_TTSL;        	/*!< CAN Transmit TimeStampLow register,    Address offset: 0x98 */
    __IO uint32_t CAN_TTSH;        	/*!< CAN Transmit TimeStampHigh register,    Address offset: 0x9C */
    __IO uint32_t CAN_CFG_STAT;     /*!< CAN Configure Status register,    Address offset: 0xA0 */
    __IO uint32_t CAN_RTIE;         /*!< CAN Receive and Transmit Interrup register,    Address offset: 0xA4 */
    __IO uint32_t CAN_S_SEG;        /*!< CAN Timing register (slow speed),    Address offset: 0xA8 */
    __IO uint32_t CAN_F_SEG;        /*!< CAN Timing register (fast speed),    Address offset: 0xAC */
    __IO uint32_t CAN_EALCAP;       /*!< CAN Error and Arbitration Lost Capture register,    Address offset: 0xB0 */
    __IO uint32_t CAN_ACFCTRL;      /*!< CAN Acceptance Filter Control register,    Address offset: 0xB4 */
    __IO uint32_t CAN_ACF;          /*!< CAN Acceptance Filter register,    Address offset: 0xB8 */
    __IO uint32_t TTCAN_CFG;        /*!< TTCAN Configure register,    Address offset: 0xBC */
    __IO uint32_t TTCAN_RFMSG;      /*!< TTCAN Reference Message register,    Address offset: 0xC0 */
    __IO uint32_t TTCAN_TRIG_CFG;   /*!< TTCAN Trigge Configure register,    Address offset: 0xC4 */
    __IO uint32_t TTCAN_WTRIG;      /*!< TTCAN Watch Trigger Time register,    Address offset: 0xC8 */
    __IO uint32_t CAN_IDE;          /*!< CAN IDE register, Address offset: 0xCC */
    __IO uint32_t CAN_TIML;          /*!< CAN TimestampLow Timer register, Address offset: 0xD0 */  /*V0.3新增*/
    __IO uint32_t CAN_TIMH;          /*!< CAN TimestampHigh Timer register,    Address offset: 0xD4 */   /*V0.3新增*/
} CAN_TypeDef;


/** @addtogroup Peripheral_memory_map
  * @{
  */
#define FLASH_BASE            (0x08000000UL)  /*!< FLASH base address */
#define EEPROM_BASE           (0X08E00000UL)  /*!< EEPROM base address*/
#define SRAM_BASE             (0x20000000UL)  /*!< SRAM base address */
#define PERIPH_BASE           (0x40000000UL)  /*!< Peripheral base address */
#define IOPORT_BASE           (0x40011000UL)  /*!< IOPORT base address */
#define SRAM_SIZE_MAX         (0x00002000UL)  /*!< maximum SRAM size (up to 32 KBytes) */
//Prviate Peripheral_memory_map
#define	IFB_BASE              (0x08C00000UL)   /*!<Ifb>*/
#define PASSWORD_BASE         (IFB_BASE+0x00000)
#define CODEOPTION_BASE       (IFB_BASE+0x00200)
#define DESIGNOPTION_BASE     (IFB_BASE+0x00400)
#define LDROM_BASE            (IFB_BASE+0x00600)
//===============================================
#define SECTOR_SIZE           512
#define FLASH_SIZE            (SECTOR_SIZE*256)
#define LDROM_SIZE            (SECTOR_SIZE*4)

/*!< Peripheral memory map */
#define AHBPERIPH_BASE         (PERIPH_BASE)
#define APB0PERIPH_BASE        (PERIPH_BASE+0x20000)
#define APB1PERIPH_BASE        (PERIPH_BASE+0x21000)
#define APB2PERIPH_BASE        (PERIPH_BASE+0x22000)
#define DMAPERIPH_BASE         (PERIPH_BASE+0x10800)
#define IOPORTPERIPH_BASE      (PERIPH_BASE+0x11000)

/*!< CAN */
#define CAN_RX_BUFFER_BASE     (CAN_BASE+0x00000000UL)
#define CAN_TX_BUFFER_BASE     (CAN_BASE+0x00000050UL)
#define CAN_FD_T_BASE          (CAN_BASE+0X00000098UL)

/*!< AHB peripherals */
#define WDT_BASE               (AHBPERIPH_BASE +(0x00000330UL))
#define IAP_BASE               (AHBPERIPH_BASE +(0x000003C0UL))
#define OPT_BASE               (AHBPERIPH_BASE +(0x000003F8UL))
#define CRC_BASE               (AHBPERIPH_BASE +(0x00002000UL))
#define RCCAHB_BASE            (AHBPERIPH_BASE +(0x00003000UL))
#define RCC_BASE               (AHBPERIPH_BASE +(0x0000300CUL))
#define CAN_BASE               (AHBPERIPH_BASE +(0x00010C00UL))
/*!< DMA */
#define DMA0_BASE              (DMAPERIPH_BASE +(0x00000000UL))
#define DMA1_BASE              (DMAPERIPH_BASE +(0x00000040UL))
#define DMA2_BASE              (DMAPERIPH_BASE +(0x00000080UL))
#define DMA3_BASE              (DMAPERIPH_BASE +(0x000000C0UL))

/*!< APB0 peripherals */
#define RCCAPB0_BASE           (APB0PERIPH_BASE +(0x00000000UL))
#define UART0_BASE             (APB0PERIPH_BASE +(0x00000020UL))
#define SPI0_BASE              (APB0PERIPH_BASE +(0x00000040UL))
#define TWI0_BASE              (APB0PERIPH_BASE +(0x00000060UL))
#define UART1_BASE             (APB0PERIPH_BASE +(0x00000080UL))
#define TIM0_BASE              (APB0PERIPH_BASE +(0x00000100UL))
#define TIM1_BASE              (APB0PERIPH_BASE +(0x00000140UL))

/*!< APB1 peripherals */
#define RCCAPB1_BASE           (APB1PERIPH_BASE +(0x00000000UL))
#define UART2_BASE             (APB1PERIPH_BASE +(0x00000020UL))
#define SPI1_TWI1_BASE         (APB1PERIPH_BASE +(0x00000040UL))
#define BTM_BASE               (APB1PERIPH_BASE +(0x00000080UL))
#define TIM2_BASE              (APB1PERIPH_BASE +(0x00000100UL))
#define TIM3_BASE              (APB1PERIPH_BASE +(0x00000140UL))

/*!< APB2 peripherals */
#define RCCAPB2_BASE           (APB2PERIPH_BASE +(0x00000000UL))
#define QEP0_BASE              (APB2PERIPH_BASE +(0x00000020UL))
#define QEP1_BASE              (APB2PERIPH_BASE +(0x00000040UL))
#define ADC_BASE               (APB2PERIPH_BASE +(0x00000100UL))
#define CMP0_1_2_BASE         (APB2PERIPH_BASE +(0x00000150UL))

#define CMP3_BASE               (APB2PERIPH_BASE +(0x00000170UL))
#define DAC_VREF_BASE          (APB2PERIPH_BASE +(0x00000190UL))
#define DAC_BASE               (APB2PERIPH_BASE +(0x00000190UL))
#define VREF_BASE              (APB2PERIPH_BASE +(0x0000019CUL))
#define OP_BASE                (APB2PERIPH_BASE +(0x000001B0UL))
#define TS_BASE                (APB2PERIPH_BASE +(0x000001E0UL))


/*!< IOPORT */
#define GPIOA_BASE             (IOPORTPERIPH_BASE +(0x00000000UL))
#define GPIOB_BASE             (IOPORTPERIPH_BASE +(0x00000100UL))
#define GPIOC_BASE             (IOPORTPERIPH_BASE +(0x00000200UL))
#define INT_BASE              (IOPORTPERIPH_BASE +(0x00000800UL))
#define FT_BIT_BASE            (IOPORTPERIPH_BASE +(0x000008C0UL))
#define RT_BIT_BASE            (IOPORTPERIPH_BASE +(0x000008E0UL))
/*!< IOPORT-Bit */
#define GPIOA_BIT_BASE         (GPIOA_BASE+(0x00000000UL))
#define GPIOB_BIT_BASE         (GPIOB_BASE+(0x00000000UL))
#define GPIOC_BIT_BASE         (GPIOC_BASE+(0x00000000UL))
/*!< IOPORT-OverTurn */
#define GPIOA_OT_BASE          (GPIOA_BASE+(0x00000010UL))
#define GPIOB_OT_BASE          (GPIOB_BASE+(0x00000010UL))
#define GPIOC_OT_BASE          (GPIOC_BASE+(0x00000010UL))
/*<PA.SetBit:n=0...15>*/
#define PA_BIT(n)              (*((uint8_t*)((GPIOA_BIT_BASE + (n)))))
#define PB_BIT(n)              (*((uint8_t*)((GPIOB_BIT_BASE + (n)))))
#define PC_BIT(n)              (*((uint8_t*)((GPIOC_BIT_BASE + (n)))))
/*<PA.OverTurn:n=0...15>*/
#define PA_OT(n)               (*((uint8_t*)((GPIOA_OT_BASE + (n)))))=1
#define PB_OT(n)               (*((uint8_t*)((GPIOB_OT_BASE + (n)))))=1
#define PC_OT(n)               (*((uint8_t*)((GPIOC_OT_BASE + (n)))))=1
/*<INTF/INTR.SetBit:n=0...15>*/
#define FT_BIT(n)              (*((uint8_t*)((FT_BIT_BASE + (n)))))
#define RT_BIT(n)              (*((uint8_t*)((RT_BIT_BASE + (n)))))

/** @addtogroup Peripheral_declaration
  * @{
  */
#define	RCC					((RCC_TypeDef *) RCC_BASE)
#define RCCAHB      ((RCCAHB_TypeDef *) RCCAHB_BASE)
#define RCCAPB0     ((RCCAPB0_TypeDef *) RCCAPB0_BASE)
#define RCCAPB1     ((RCCAPB1_TypeDef *) RCCAPB1_BASE)
#define RCCAPB2     ((RCCAPB2_TypeDef *) RCCAPB2_BASE)
#define UART0				((UART_TypeDef *) UART0_BASE)
#define UART1				((UART_TypeDef *) UART1_BASE)
#define UART2				((UART_TypeDef *) UART2_BASE)
#define SPI0				((SPI_TypeDef *) SPI0_BASE)
//#define SPI1_TWI1		((SPI1_TWI1_TypeDef *) SPI1_TWI1_BASE)
#define SPI1	    	((SPI_TypeDef *) SPI1_TWI1_BASE)
#define TWI1		    ((TWI_TypeDef *) SPI1_TWI1_BASE)

#define SPITWI_SPI1		((SPITWI_TypeDef *) SPI1_TWI1_BASE)
#define SPITWI_TWI1		((SPITWI_TypeDef *) SPI1_TWI1_BASE)

#define TWI0				((TWI_TypeDef *) TWI0_BASE)
#define TIM0				((TIM_TypeDef *) TIM0_BASE)
#define TIM1				((TIM_TypeDef *) TIM1_BASE)
#define TIM2				((TIM_TypeDef *) TIM2_BASE)
#define TIM3				((TIM_TypeDef *) TIM3_BASE)
#define BTM					((BTM_TypeDef *) BTM_BASE)
#define ADC					((ADC_TypeDef *) ADC_BASE)
#define CMP     	  ((CMP_TypeDef *) CMP0_1_2_BASE)
#define CMP_0		    ((CMP_TypeDef *) CMP0_1_2_BASE)
#define CMP_1		    ((CMP_TypeDef *) (CMP0_1_2_BASE+0x00000001U))
#define CMP_2		    ((CMP_TypeDef *) (CMP0_1_2_BASE+0x00000002U))
#define CMP3				((CMP_TypeDef *) CMP3_BASE)
#define OP					((OP_TypeDef *) OP_BASE)
#define OP_0		      ((OP_TypeDef *) OP_BASE)
#define OP_1		      ((OP_TypeDef *) (OP_BASE+0x00000001U))
#define OP_2		      ((OP_TypeDef *) (OP_BASE+0x00000002U))
#define DAC_VREF		   ((DAC_VREF_TypeDef *) DAC_VREF_BASE)
#define DAC					((DAC_TypeDef *) DAC_BASE)
#define VREF				((VREF_TypeDef *) VREF_BASE)
#define QEP0        ((QEP_TypeDef *) QEP0_BASE)
#define QEP1        ((QEP_TypeDef *) QEP1_BASE)
#define INT				((INT_TypeDef *) INT_BASE)
#define WDT         ((WDT_TypeDef *) WDT_BASE)
#define IAP         ((IAP_TypeDef *) IAP_BASE)
#define CRC         ((CRC_TypeDef *) CRC_BASE)
#define CAN         ((CAN_TypeDef *) CAN_FD_T_BASE)
#define CAN_RUF     ((CAN_RX_BUFFER_TypeDef*)CAN_RX_BUFFER_BASE)
#define CAN_TUF     ((CAN_TX_BUFFER_TypeDef*)CAN_TX_BUFFER_BASE)
#define DMA0				((DMA_TypeDef *) DMA0_BASE)
#define DMA1				((DMA_TypeDef *) DMA1_BASE)
#define DMA2				((DMA_TypeDef *) DMA2_BASE)
#define DMA3				((DMA_TypeDef *) DMA3_BASE)
#define GPIOA				((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB				((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC				((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOA_BIT   ((GPIO_BIT_TypeDef *) GPIOA_BIT_BASE)
#define GPIOB_BIT   ((GPIO_BIT_TypeDef *) GPIOB_BIT_BASE)
#define GPIOC_BIT   ((GPIO_BIT_TypeDef *) GPIOC_BIT_BASE)
#define TS          ((TS_TypeDef *)TS_BASE)
//----------------------------------------------------------
#define OPT         ((OPT_TypeDef *) OPT_BASE)
//----------------------------------------------------------
/** @addtogroup Peripheral_Registers_Bits_Definition
* @{
*/

/******************************************************************************/
/*                         Peripheral Registers Bits Definition               */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                      RCC                    */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for RCC_CFG0 register  ********************/
#define RCC_CFG0_LXTEN_Pos            (0U)
#define	RCC_CFG0_LXTEN_Msk						(0x1UL << RCC_CFG0_LXTEN_Pos)
#define RCC_CFG0_LXTEN           			RCC_CFG0_LXTEN_Msk

#define RCC_CFG0_LIRCEN_Pos           (1U)
#define	RCC_CFG0_LIRCEN_Msk						(0x1UL << RCC_CFG0_LIRCEN_Pos)
#define RCC_CFG0_LIRCEN           		RCC_CFG0_LIRCEN_Msk

#define RCC_CFG0_CRYHF_Pos            (4U)
#define	RCC_CFG0_CRYHF_Msk						(0x1UL << RCC_CFG0_CRYHF_Pos)
#define RCC_CFG0_CRYHF           			RCC_CFG0_CRYHF_Msk

#define RCC_CFG0_HIRCEN_Pos           (6U)
#define	RCC_CFG0_HIRCEN_Msk						(0x1UL << RCC_CFG0_HIRCEN_Pos)
#define RCC_CFG0_HIRCEN          			RCC_CFG0_HIRCEN_Msk

#define RCC_CFG0_SYSCLKSW_Pos         (7U)
#define	RCC_CFG0_SYSCLKSW_Msk					(0x1UL << RCC_CFG0_SYSCLKSW_Pos)
#define RCC_CFG0_SYSCLKSW          		RCC_CFG0_SYSCLKSW_Msk

#define RCC_CFG0_SYSCLKSEL_Pos         (8U)
#define	RCC_CFG0_SYSCLKSEL_Msk				 (0x3UL << RCC_CFG0_SYSCLKSEL_Pos)
#define RCC_CFG0_SYSCLKSEL         		 RCC_CFG0_SYSCLKSEL_Msk

#define RCC_CFG0_HPLDODP_Pos          (11U)
#define	RCC_CFG0_HPLDOD_Msk						(0x1UL << RCC_CFG0_HPLDODP_Pos)
#define RCC_CFG0_HPLDOD         			 RCC_CFG0_HPLDOD_Msk

#define RCC_CFG0_WAIT_Pos             (12U)
#define	RCC_CFG0_WAIT_Msk					    (0x3UL << RCC_CFG0_WAIT_Pos)
#define RCC_CFG0_WAIT          				RCC_CFG0_WAIT_Msk

#define RCC_CFG0_HIRCDIV1_Pos         (14U)
#define	RCC_CFG0_HIRCDIV1_Msk					(0x1UL << RCC_CFG0_HIRCDIV1_Pos)
#define RCC_CFG0_HIRCDIV1             RCC_CFG0_HIRCDIV1_Msk

#define RCC_CFG0_INTEN_Pos            (15U)
#define	RCC_CFG0_INTEN_Msk						(0x1UL << RCC_CFG0_INTEN_Pos)
#define RCC_CFG0_INTEN                RCC_CFG0_INTEN_Msk

/********************  Bit definition for RCC_CFG1 register  ********************/
#define RCC_CFG1_BTMCLKSEL_Pos         		(0U)
#define	RCC_CFG1_BTMCLKSEL_Msk						(0x1UL << RCC_CFG1_BTMCLKSEL_Pos)
#define RCC_CFG1_BTMCLKSEL           			RCC_CFG1_BTMCLKSEL_Msk

#define RCC_CFG1_STCLKSEL_Pos         		(5U)
#define	RCC_CFG1_STCLKSEL_Msk							(0x3UL << RCC_CFG1_STCLKSEL_Pos)
#define RCC_CFG1_STCLKSEL           			RCC_CFG1_STCLKSEL_Msk

/********************  Bit definition for RCC_STS register  ********************/
#define RCC_STS_CLKFIF_Pos         				(0U)
#define	RCC_STS_CLKFIF_Msk								(0x1UL << RCC_STS_CLKFIF_Pos)
#define RCC_STS_CLKFIF           					RCC_STS_CLKFIF_Msk

#define RCC_STS_SRAMPEIF_Pos         			(3U)
#define	RCC_STS_SRAMPEIF_Msk							(0x1UL << RCC_STS_SRAMPEIF_Pos)
#define RCC_STS_SRAMPEIF          				RCC_STS_SRAMPEIF_Msk

/********************  Bit definition for NMI_CFG register  ********************/
#define NMI_CFG_CSSEN_Pos         			  (0U)
#define	NMI_CFG_CSSEN_Msk							    (0x1UL << NMI_CFG_CSSEN_Pos)
#define NMI_CFG_CSSEN          			    	NMI_CFG_CSSEN_Msk

#define NMI_CFG_INT0EN_Pos         			  (2U)
#define	NMI_CFG_INT0EN_Msk							  (0x1UL << NMI_CFG_INT0EN_Pos)
#define NMI_CFG_INT0EN          			    NMI_CFG_INT0EN_Msk

#define NMI_CFG_SRAMPEEN_Pos         			(3U)
#define	NMI_CFG_SRAMPEEN_Msk							(0x1UL << NMI_CFG_SRAMPEEN_Pos)
#define NMI_CFG_SRAMPEEN          			  NMI_CFG_SRAMPEEN_Msk

#define NMI_CFG_OP2EN_Pos         			  (4U)
#define	NMI_CFG_OP2EN_Msk							    (0x1UL << NMI_CFG_OP2EN_Pos)
#define NMI_CFG_OP2EN          			      NMI_CFG_OP2EN_Msk

#define NMI_CFG_OP1EN_Pos         			  (5U)
#define	NMI_CFG_OP1EN_Msk							    (0x1UL << NMI_CFG_OP1EN_Pos)
#define NMI_CFG_OP1EN          			      NMI_CFG_OP1EN_Msk

#define NMI_CFG_CMP3EN_Pos         			  (6U)
#define	NMI_CFG_CMP3EN_Msk							  (0x1UL << NMI_CFG_CMP3EN_Pos)
#define NMI_CFG_CMP3EN          			      NMI_CFG_CMP3EN_Msk

#define NMI_CFG_CMP0EN_Pos         			  (7U)
#define	NMI_CFG_CMP0EN_Msk							  (0x1UL << NMI_CFG_CMP0EN_Pos)
#define NMI_CFG_CMP0EN          			    NMI_CFG_CMP0EN_Msk

/********************  Bit definition for AHB_CFG register  ********************/
#define AHB_CFG_DMAEN_Pos         				(0U)
#define	AHB_CFG_DMAEN_Msk									(0x1UL << AHB_CFG_DMAEN_Pos)
#define AHB_CFG_DMAEN           					AHB_CFG_DMAEN_Msk

#define AHB_CFG_CRCEN_Pos         				(1U)
#define	AHB_CFG_CRCEN_Msk									(0x1UL << AHB_CFG_CRCEN_Pos)
#define AHB_CFG_CRCEN           					AHB_CFG_CRCEN_Msk

#define AHB_CFG_IFBEN_Pos         				(2U)
#define	AHB_CFG_IFBEN_Msk								  (0x1UL << AHB_CFG_IFBEN_Pos)
#define AHB_CFG_IFBEN           					AHB_CFG_IFBEN_Msk

#define AHB_CFG_CANEN_Pos         				(4U)
#define	AHB_CFG_CANEN_Msk								  (0x1UL << AHB_CFG_CANEN_Pos)
#define AHB_CFG_CANEN           					AHB_CFG_CANEN_Msk

#define AHB_CFG_CLKDIV_Pos         				(20U)
#define	AHB_CFG_CLKDIV_Msk								(0x7UL << AHB_CFG_CLKDIV_Pos)
#define AHB_CFG_CLKDIV           					AHB_CFG_CLKDIV_Msk

/********************  Bit definition for AHB_RST register  ********************/
#define AHB_RST_DMARST_Pos         				(0U)
#define	AHB_RST_DMARST_Msk								(0x1UL << AHB_RST_DMARST_Pos)
#define AHB_RST_DMARST           					AHB_RST_DMARST_Msk

#define AHB_RST_CRCRST_Pos         				(1U)
#define	AHB_RST_CRCRST_Msk								(0x1UL << AHB_RST_CRCRST_Pos)
#define AHB_RST_CRCRST           					AHB_RST_CRCRST_Msk

#define AHB_RST_CANRST_Pos         				(4U)
#define	AHB_RST_CANRST_Msk								(0x1UL << AHB_RST_CANRST_Pos)
#define AHB_RST_CANRST           					AHB_RST_CANRST_Msk


/********************  Bit definition for APB0_CFG register  ********************/
#define APB0_CFG_TIM0EN_Pos         			(0U)
#define	APB0_CFG_TIM0EN_Msk								(0x1UL << APB0_CFG_TIM0EN_Pos)
#define APB0_CFG_TIM0EN           				APB0_CFG_TIM0EN_Msk

#define APB0_CFG_TIM1EN_Pos         			(1U)
#define	APB0_CFG_TIM1EN_Msk								(0x1UL << APB0_CFG_TIM1EN_Pos)
#define APB0_CFG_TIM1EN           				APB0_CFG_TIM1EN_Msk

#define APB0_CFG_TWI0EN_Pos         			(4U)
#define	APB0_CFG_TWI0EN_Msk								(0x1UL << APB0_CFG_TWI0EN_Pos)
#define APB0_CFG_TWI0EN           				APB0_CFG_TWI0EN_Msk

#define APB0_CFG_SPI0EN_Pos         			(5U)
#define	APB0_CFG_SPI0EN_Msk								(0x1UL << APB0_CFG_SPI0EN_Pos)
#define APB0_CFG_SPI0EN           				APB0_CFG_SPI0EN_Msk

#define APB0_CFG_UART0EN_Pos         			(6U)
#define	APB0_CFG_UART0EN_Msk							(0x1UL << APB0_CFG_UART0EN_Pos)
#define APB0_CFG_UART0EN           				APB0_CFG_UART0EN_Msk

#define APB0_CFG_UART1EN_Pos         			(7U)
#define	APB0_CFG_UART1EN_Msk							(0x1UL << APB0_CFG_UART1EN_Pos)
#define APB0_CFG_UART1EN           				APB0_CFG_UART1EN_Msk

#define APB0_CFG_CLKDIV_Pos         			(20U)
#define	APB0_CFG_CLKDIV_Msk								(0x7UL << APB0_CFG_CLKDIV_Pos)
#define APB0_CFG_CLKDIV           				APB0_CFG_CLKDIV_Msk

#define APB0_CFG_ENAPB_Pos         				(23U)
#define	APB0_CFG_ENAPB_Msk								(0x1UL << APB0_CFG_ENAPB_Pos)
#define APB0_CFG_ENAPB           					APB0_CFG_ENAPB_Msk

/********************  Bit definition for APB0_RST register  ********************/
#define APB0_RST_TIM0RST_Pos         			(0U)
#define	APB0_RST_TIM0RST_Msk							(0x1UL << APB0_RST_TIM0RST_Pos)
#define APB0_RST_TIM0RST           				APB0_RST_TIM0RST_Msk

#define APB0_RST_TIM1RST_Pos         			(1U)
#define	APB0_RST_TIM1RST_Msk							(0x1UL << APB0_RST_TIM1RST_Pos)
#define APB0_RST_TIM1RST           				APB0_RST_TIM1RST_Msk

#define APB0_RST_TWI0RST_Pos         			(4U)
#define	APB0_RST_TWI0RST_Msk							(0x1UL << APB0_RST_TWI0RST_Pos)
#define APB0_RST_TWI0RST           				APB0_RST_TWI0RST_Msk

#define APB0_RST_SPI0RST_Pos         			(5U)
#define	APB0_RST_SPI0RST_Msk							(0x1UL << APB0_RST_SPI0RST_Pos)
#define APB0_RST_SPI0RST           				APB0_RST_SPI0RST_Msk

#define APB0_RST_UART0RST_Pos         		(6U)
#define	APB0_RST_UART0RST_Msk							(0x1UL << APB0_RST_UART0RST_Pos)
#define APB0_RST_UART0RST           			APB0_RST_UART0RST_Msk

#define APB0_RST_UART1RST_Pos         		(7U)
#define	APB0_RST_UART1RST_Msk							(0x1UL << APB0_RST_UART1RST_Pos)
#define APB0_RST_UART1RST           			APB0_RST_UART1RST_Msk

/********************  Bit definition for APB1_CFG register  ********************/
#define APB1_CFG_TIM2EN_Pos         			(0U)
#define	APB1_CFG_TIM2EN_Msk								(0x1UL << APB1_CFG_TIM2EN_Pos)
#define APB1_CFG_TIM2EN           				APB1_CFG_TIM2EN_Msk

#define APB1_CFG_TIM3EN_Pos         			(1U)
#define	APB1_CFG_TIM3EN_Msk								(0x1UL << APB1_CFG_TIM3EN_Pos)
#define APB1_CFG_TIM3EN           				APB1_CFG_TIM3EN_Msk

#define APB1_CFG_SPI1_TWI1EN_Pos         	(4U)
#define	APB1_CFG_SPI1_TWI1EN_Msk					(0x1UL << APB1_CFG_SPI1_TWI1EN_Pos)
#define APB1_CFG_SPI1_TWI1EN           		APB1_CFG_SPI1_TWI1EN_Msk

#define APB1_CFG_UART2EN_Pos         			(7U)
#define	APB1_CFG_UART2EN_Msk							(0x1UL << APB1_CFG_UART2EN_Pos)
#define APB1_CFG_UART2EN           				APB1_CFG_UART2EN_Msk

#define APB1_CFG_CLKDIV_Pos         			(20U)
#define	APB1_CFG_CLKDIV_Msk								(0x7UL << APB1_CFG_CLKDIV_Pos)
#define APB1_CFG_CLKDIV           				APB1_CFG_CLKDIV_Msk

#define APB1_CFG_ENAPB_Pos         				(23U)
#define	APB1_CFG_ENAPB_Msk								(0x1UL << APB1_CFG_ENAPB_Pos)
#define APB1_CFG_ENAPB           					APB1_CFG_ENAPB_Msk

/********************  Bit definition for APB1_RST register  ********************/
#define APB1_RST_TIM2RST_Pos         			(0U)
#define	APB1_RST_TIM2RST_Msk              (0x1UL << APB1_RST_TIM2RST_Pos)
#define APB1_RST_TIM2RST                  APB1_RST_TIM2RST_Msk

#define APB1_RST_TIM3RST_Pos              (1U)
#define	APB1_RST_TIM3RST_Msk              (0x1UL << APB1_RST_TIM3RST_Pos)
#define APB1_RST_TIM3RST           				APB1_RST_TIM3RST_Msk

#define APB1_RST_SPI1_TWI1RST_Pos         (4U)
#define	APB1_RST_SPI1_TWI1RST_Msk         (0x1UL << APB1_RST_SPI1_TWI1RST_Pos)
#define APB1_RST_SPI1_TWI1RST             APB1_RST_SPI1_TWI1RST_Msk

#define APB1_RST_UART2RST_Pos             (7U)
#define	APB1_RST_UART2RST_Msk             (0x1UL << APB1_RST_UART2RST_Pos)          
#define APB1_RST_UART2RST                  APB1_RST_UART2RST_Msk

/********************  Bit definition for APB2_CFG register  ********************/
#define APB2_CFG_QEP0EN_Pos         			(2U)
#define	APB2_CFG_QEP0EN_Msk							  (0x1UL << APB2_CFG_QEP0EN_Pos)
#define APB2_CFG_QEP0EN           				APB2_CFG_QEP0EN_Msk

#define APB2_CFG_QEP1EN_Pos         			(3U)
#define	APB2_CFG_QEP1EN_Msk							  (0x1UL << APB2_CFG_QEP1EN_Pos)
#define APB2_CFG_QEP1EN           				APB2_CFG_QEP1EN_Msk

#define APB2_CFG_ADCEN_Pos         			  (6U)
#define	APB2_CFG_ADCEN_Msk							  (0x1UL << APB2_CFG_ADCEN_Pos)
#define APB2_CFG_ADCEN           			   	APB2_CFG_ADCEN_Msk

#define APB2_CFG_CLKDIV_Pos         			(20U)
#define	APB2_CFG_CLKDIV_Msk								(0x7UL << APB2_CFG_CLKDIV_Pos)
#define APB2_CFG_CLKDIV           				APB2_CFG_CLKDIV_Msk

#define APB2_CFG_ENAPB_Pos         				(23U)
#define	APB2_CFG_ENAPB_Msk								(0x1UL << APB2_CFG_ENAPB_Pos)
#define APB2_CFG_ENAPB           					APB2_CFG_ENAPB_Msk

/********************  Bit definition for APB2_RST register  ********************/

#define APB2_RST_QEP0RST_Pos         		  (2U)
#define	APB2_RST_QEP0RST_Msk							(0x1UL << APB2_RST_QEP0RST_Pos)
#define APB2_RST_QEP0RST           			  APB2_RST_QEP0RST_Msk

#define APB2_RST_QEP1RST_Pos         		  (3U)
#define	APB2_RST_QEP1RST_Msk							(0x1UL << APB2_RST_QEP1RST_Pos)
#define APB2_RST_QEP1RST           			  APB2_RST_QEP1RST_Msk

#define APB2_CFG_ADCRST_Pos         			(6U)
#define	APB2_CFG_ADCRST_Msk							  (0x1UL << APB2_CFG_ADCRST_Pos)
#define APB2_CFG_ADCRST           			   APB2_CFG_ADCRST_Msk

/******************************************************************************/
/*                                                                            */
/*                      ADC                    */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for ADC_CON register  ********************/
#define ADC_CON_ADCS_Pos                  (0U)
#define	ADC_CON_ADCS_Msk                  (0x1UL << ADC_CON_ADCS_Pos)
#define ADC_CON_ADCS                      ADC_CON_ADCS_Msk

#define ADC_CON_REFSEL_Pos                 (4U)
#define	ADC_CON_REFSEL_Msk                 (0x1UL << ADC_CON_REFSEL_Pos)
#define ADC_CON_REFSEL                     ADC_CON_REFSEL_Msk

#define ADC_CON_CONT_Pos                  (5U)
#define	ADC_CON_CONT_Msk                  (0x1UL << ADC_CON_CONT_Pos)
#define ADC_CON_CONT                      ADC_CON_CONT_Msk

#define ADC_CON_ADCEN_Pos                 (7U)
#define	ADC_CON_ADCEN_Msk                 (0x1UL << ADC_CON_ADCEN_Pos)
#define ADC_CON_ADCEN                     ADC_CON_ADCEN_Msk

#define ADC_CON_LOWSP_Pos                 (8U)
#define	ADC_CON_LOWSP_Msk                 (0x7UL << ADC_CON_LOWSP_Pos)
#define ADC_CON_LOWSP                     ADC_CON_LOWSP_Msk

#define ADC_CON_ADCISA_Pos                 (16U)
#define	ADC_CON_ADCISA_Msk                 (0x1FUL << ADC_CON_ADCISA_Pos)
#define ADC_CON_ADCISA                     ADC_CON_ADCISA_Msk

/********************  Bit definition for ADC_IDE register  ********************/
#define ADC_IDE_EOCIE_Pos         					  (0U)
#define	ADC_IDE_EOCIE_Msk										  (0x01UL << ADC_IDE_EOCIE_Pos)
#define ADC_IDE_EOCIE          							  ADC_IDE_EOCIE_Msk

#define ADC_IDE_EOSIE0_Pos         					  (1U)
#define	ADC_IDE_EOSIE0_Msk										(0x01UL << ADC_IDE_EOSIE0_Pos)
#define ADC_IDE_EOSIE0          							ADC_IDE_EOSIE0_Msk

#define ADC_IDE_DMAEN_Pos         					  (6U)
#define	ADC_IDE_DMAEN_Msk										  (0x01UL << ADC_IDE_DMAEN_Pos)
#define ADC_IDE_DMAEN          						  	ADC_IDE_DMAEN_Msk

#define ADC_IDE_INTEN_Pos         					  (7U)
#define	ADC_IDE_INTEN_Msk										  (0x01UL << ADC_IDE_INTEN_Pos)
#define ADC_IDE_INTEN          						  	ADC_IDE_INTEN_Msk

#define ADC_IDE_UPTHIE_Pos         					  (8U)
#define	ADC_IDE_UPTHIE_Msk										(0x01UL << ADC_IDE_UPTHIE_Pos)
#define ADC_IDE_UPTHIE          							ADC_IDE_UPTHIE_Msk

#define ADC_IDE_LOWTHIE_Pos         					(9U)
#define	ADC_IDE_LOWTHIE_Msk										(0x01UL << ADC_IDE_LOWTHIE_Pos)
#define ADC_IDE_LOWTHIE          							ADC_IDE_LOWTHIE_Msk

/********************  Bit definition for ADC_IDE register  ********************/
#define ADC_VALUE_ADCVA_Pos                             (0U)
#define	ADC_VALUE_ADCVA_Msk                             (0x3FUL << ADC_VALUE_ADCVA_Pos)
#define ADC_VALUE_ADCVA                                 ADC_VALUE_ADCVA_Msk

#define ADC_VALUE_OVERRUN_Pos                           (31U)
#define	ADC_VALUE_OVERRUN_Msk                           (0x01 << ADC_VALUE_OVERRUN_Pos)
#define ADC_VALUE_OVERRUN                               ADC_VALUE_OVERRUN_Msk

/********************  Bit definition for ADC_TH_CFG register  ********************/
#define ADC_TH_CFG_AIN0_Pos                  (0U)
#define	ADC_TH_CFG_AIN0_Msk                  (0x1L << ADC_TH_CFG_AIN0_Pos)          
#define ADC_TH_CFG_AIN0                      ADC_TH_CFG_AIN0_Msk

#define ADC_TH_CFG_AIN1_Pos                  (1U)
#define	ADC_TH_CFG_AIN1_Msk                  (0x1L << ADC_TH_CFG_AIN1_Pos)
#define ADC_TH_CFG_AIN1                      ADC_TH_CFG_AIN1_Msk

#define ADC_TH_CFG_AIN2_Pos                  (2U)
#define	ADC_TH_CFG_AIN2_Msk                  (0x1L << ADC_TH_CFG_AIN2_Pos)
#define ADC_TH_CFG_AIN2                      ADC_TH_CFG_AIN2_Msk

#define ADC_TH_CFG_AIN3_Pos                  (3U)
#define	ADC_TH_CFG_AIN3_Msk                  (0x1L << ADC_TH_CFG_AIN3_Pos)
#define ADC_TH_CFG_AIN3                      ADC_TH_CFG_AIN3_Msk

#define ADC_TH_CFG_AIN4_Pos                  (4U)
#define	ADC_TH_CFG_AIN4_Msk                  (0x1L << ADC_TH_CFG_AIN4_Pos)
#define ADC_TH_CFG_AIN4                      ADC_TH_CFG_AIN4_Msk

#define ADC_TH_CFG_AIN5_Pos                  (5U)
#define	ADC_TH_CFG_AIN5_Msk                  (0x1L << ADC_TH_CFG_AIN5_Pos)
#define ADC_TH_CFG_AIN5                      ADC_TH_CFG_AIN5_Msk

#define ADC_TH_CFG_AIN6_Pos                  (6U)
#define	ADC_TH_CFG_AIN6_Msk                  (0x1L << ADC_TH_CFG_AIN6_Pos)
#define ADC_TH_CFG_AIN6                      ADC_TH_CFG_AIN6_Msk

#define ADC_TH_CFG_AIN7_Pos                  (7U)
#define	ADC_TH_CFG_AIN7_Msk                  (0x1L << ADC_TH_CFG_AIN7_Pos)
#define ADC_TH_CFG_AIN7                      ADC_TH_CFG_AIN7_Msk

#define ADC_TH_CFG_AIN8_Pos                  (8U)
#define	ADC_TH_CFG_AIN8_Msk                  (0x1L << ADC_TH_CFG_AIN8_Pos)
#define ADC_TH_CFG_AIN8                      ADC_TH_CFG_AIN8_Msk

#define ADC_TH_CFG_AIN9_Pos                  (9U)
#define	ADC_TH_CFG_AIN9_Msk                  (0x1L << ADC_TH_CFG_AIN9_Pos)
#define ADC_TH_CFG_AIN9                      ADC_TH_CFG_AIN9_Msk

#define ADC_TH_CFG_AIN10_Pos                  (10U)
#define	ADC_TH_CFG_AIN10_Msk                  (0x1L << ADC_TH_CFG_AIN10_Pos)
#define ADC_TH_CFG_AIN10                      ADC_TH_CFG_AIN10_Msk

#define ADC_TH_CFG_AIN11_Pos                  (11U)
#define	ADC_TH_CFG_AIN11_Msk                  (0x1L << ADC_TH_CFG_AIN11_Pos)
#define ADC_TH_CFG_AIN11                      ADC_TH_CFG_AIN11_Msk

#define ADC_TH_CFG_AIN12_Pos                  (12U)
#define	ADC_TH_CFG_AIN12_Msk                  (0x1L << ADC_TH_CFG_AIN12_Pos)
#define ADC_TH_CFG_AIN12                      ADC_TH_CFG_AIN12_Msk

#define ADC_TH_CFG_AIN13_Pos                  (13U)
#define	ADC_TH_CFG_AIN13_Msk                  (0x1L << ADC_TH_CFG_AIN13_Pos)
#define ADC_TH_CFG_AIN13                      ADC_TH_CFG_AIN13_Msk

#define ADC_TH_CFG_AIN14_Pos                  (14U)
#define	ADC_TH_CFG_AIN14_Msk                  (0x1L << ADC_TH_CFG_AIN14_Pos)
#define ADC_TH_CFG_AIN14                      ADC_TH_CFG_AIN14_Msk

#define ADC_TH_CFG_AIN15_Pos                  (15U)
#define	ADC_TH_CFG_AIN15_Msk                  (0x1L << ADC_TH_CFG_AIN15_Pos)
#define ADC_TH_CFG_AIN15                      ADC_TH_CFG_AIN15_Msk


/********************  Bit definition for ADC_CFG register  ********************/
#define ADC_CFG_AIN0_Pos                  (0U)
#define	ADC_CFG_AIN0_Msk                  (0x1L << ADC_CFG_AIN0_Pos)
#define ADC_CFG_AIN0                      ADC_CFG_AIN0_Msk

#define ADC_CFG_AIN1_Pos                  (1U)
#define	ADC_CFG_AIN1_Msk                  (0x1L << ADC_CFG_AIN1_Pos)
#define ADC_CFG_AIN1                      ADC_CFG_AIN1_Msk

#define ADC_CFG_AIN2_Pos                  (2U)
#define	ADC_CFG_AIN2_Msk                  (0x1L << ADC_CFG_AIN2_Pos)
#define ADC_CFG_AIN2                      ADC_CFG_AIN2_Msk

#define ADC_CFG_AIN3_Pos                  (3U)
#define	ADC_CFG_AIN3_Msk                  (0x1L << ADC_CFG_AIN3_Pos)
#define ADC_CFG_AIN3                      ADC_CFG_AIN3_Msk

#define ADC_CFG_AIN4_Pos                  (4U)
#define	ADC_CFG_AIN4_Msk                  (0x1L << ADC_CFG_AIN4_Pos)
#define ADC_CFG_AIN4                      ADC_CFG_AIN4_Msk

#define ADC_CFG_AIN5_Pos                  (5U)
#define	ADC_CFG_AIN5_Msk                  (0x1L << ADC_CFG_AIN5_Pos)
#define ADC_CFG_AIN5                      ADC_CFG_AIN5_Msk

#define ADC_CFG_AIN6_Pos                  (6U)
#define	ADC_CFG_AIN6_Msk                  (0x1L << ADC_CFG_AIN6_Pos)
#define ADC_CFG_AIN6                      ADC_CFG_AIN6_Msk

#define ADC_CFG_AIN7_Pos                  (7U)
#define	ADC_CFG_AIN7_Msk                  (0x1L << ADC_CFG_AIN7_Pos)
#define ADC_CFG_AIN7                      ADC_CFG_AIN7_Msk

#define ADC_CFG_AIN8_Pos                  (8U)
#define	ADC_CFG_AIN8_Msk                  (0x1L << ADC_CFG_AIN8_Pos)
#define ADC_CFG_AIN8                      ADC_CFG_AIN8_Msk

#define ADC_CFG_AIN9_Pos                  (9U)
#define	ADC_CFG_AIN9_Msk                  (0x1L << ADC_CFG_AIN9_Pos)
#define ADC_CFG_AIN9                      ADC_CFG_AIN9_Msk

#define ADC_CFG_AIN10_Pos                  (10U)
#define	ADC_CFG_AIN10_Msk                  (0x1L << ADC_CFG_AIN10_Pos)
#define ADC_CFG_AIN10                      ADC_CFG_AIN10_Msk

#define ADC_CFG_AIN11_Pos                  (11U)
#define	ADC_CFG_AIN11_Msk                  (0x1L << ADC_CFG_AIN11_Pos)
#define ADC_CFG_AIN11                      ADC_CFG_AIN11_Msk

#define ADC_CFG_AIN12_Pos                  (12U)
#define	ADC_CFG_AIN12_Msk                  (0x1L << ADC_CFG_AIN12_Pos)
#define ADC_CFG_AIN12                      ADC_CFG_AIN12_Msk

#define ADC_CFG_AIN13_Pos                  (13U)
#define	ADC_CFG_AIN13_Msk                  (0x1L << ADC_CFG_AIN13_Pos)
#define ADC_CFG_AIN13                      ADC_CFG_AIN13_Msk

#define ADC_CFG_AIN14_Pos                  (14U)
#define	ADC_CFG_AIN14_Msk                  (0x1L << ADC_CFG_AIN14_Pos)
#define ADC_CFG_AIN14                      ADC_CFG_AIN14_Msk

#define ADC_CFG_AIN15_Pos                  (15U)
#define	ADC_CFG_AIN15_Msk                  (0x1L << ADC_CFG_AIN15_Pos)
#define ADC_CFG_AIN15                      ADC_CFG_AIN15_Msk


/********************  Bit definition for ADC_STS register  ********************/ 
#define ADC_STS_EOCIF_Pos         					  (0U)
#define	ADC_STS_EOCIF_Msk										  (0x01UL << ADC_STS_EOCIF_Pos)          
#define ADC_STS_EOCIF          							  ADC_STS_EOCIF_Msk

#define ADC_STS_EOSIF0_Pos                  (1U)
#define ADC_STS_EOSIF0_Msk                  (0x1L << ADC_STS_EOSIF0_Pos)
#define ADC_STS_EOSIF0                      ADC_STS_EOSIF0_Msk

#define ADC_STS_BUSY_Pos                  (7U)
#define ADC_STS_BUSY_Msk                  (0x2L << ADC_STS_BUSY_Pos)
#define ADC_STS_BUSY                      ADC_STS_BUSY_Msk

#define ADC_STS_UPTHIF_Pos                  (7U)
#define ADC_STS_UPTHIF_Msk                  (0x2L << ADC_STS_UPTHIF_Pos)
#define ADC_STS_UPTHIF                      ADC_STS_UPTHIF_Msk

#define ADC_STS_LOWTHIF_Pos                  (7U)
#define ADC_STS_LOWTHIF_Msk                  (0x2L << ADC_STS_LOWTHIF_Pos)
#define ADC_STS_LOWTHIF                      ADC_STS_LOWTHIF_Msk

/********************  Bit definition for ADC_ADCV register  ********************/
#define ADC_ADCV_OVERRUN_Pos                (31U)
#define	ADC_ADCV_OVERRUN_Msk                (0x1L << ADC_ADCV_OVERRUN_Pos)
#define ADC_ADCV_OVERRUN                    ADC_ADCV_OVERRUN_Msk

#define ADC_ADCV_ADCVA_Pos                 (0U)
#define	ADC_ADCV_ADCVA_Msk                 (0xFFFL << ADC_ADCV_ADCVA_Pos)          
#define ADC_ADCV_ADCVA                     ADC_ADCV_ADCVA_Msk

/******************************************************************************/
/*                                                                            */
/*                      BTM                    */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for BTM_CON register  ********************/
#define BTM_CON_BTMFS_Pos         				(0U)
#define	BTM_CON_BTMFS_Msk									(0x0FL << BTM_CON_BTMFS_Pos)
#define BTM_CON_BTMFS          						BTM_CON_BTMFS_Msk

#define BTM_CON_INTEN_Pos         				(6U)
#define	BTM_CON_INTEN_Msk									(0x1L << BTM_CON_INTEN_Pos)
#define BTM_CON_INTEN          						BTM_CON_INTEN_Msk

#define BTM_CON_BTMEN_Pos         				(7U)
#define	BTM_CON_BTMEN_Msk									(0x1L << BTM_CON_BTMEN_Pos)
#define BTM_CON_BTMEN          						BTM_CON_BTMEN_Msk

/********************  Bit definition for BTM_STS register  ********************/
#define BTM_STS_BTMIF_Pos         				(0U)
#define	BTM_STS_BTMIF_Msk						(0x1L << BTM_STS_BTMIF_Pos)
#define BTM_STS_BTMIF          					BTM_STS_BTMIF_Msk

/******************************************************************************/
/*                                                                            */
/*                            CMP0_1_2                                    */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for CMP_CFG register  ********************/
#define CMPX_CFG_CMPNS_Pos             (0U)
#define	CMPX_CFG_CMPNS_Msk             (0x3L << CMPX_CFG_CMPNS_Pos)
#define CMPX_CFG_CMPNS                 CMPX_CFG_CMPNS_Msk

#define CMPX_CFG_CMPPS_Pos             (2U)
#define	CMPX_CFG_CMPPS_Msk             (0x3L << CMPX_CFG_CMPPS_Pos)
#define CMPX_CFG_CMPPS                 CMPX_CFG_CMPPS_Msk

#define CMPX_CFG_CMPIM_Pos             (5U)
#define	CMPX_CFG_CMPIM_Msk             (0x3L << CMPX_CFG_CMPIM_Pos)
#define CMPX_CFG_CMPIM                 CMPX_CFG_CMPIM_Msk

#define CMPX_CFG_CMPEN_Pos             (7U)
#define	CMPX_CFG_CMPEN_Msk             (0x1L << CMPX_CFG_CMPEN_Pos)
#define CMPX_CFG_CMPEN                 CMPX_CFG_CMPEN_Msk

#define CMPX_CFG_CMPRF_Pos             (8U)
#define CMPX_CFG_CMPRF_Msk             (0x0FL << CMPX_CFG_CMPRF_Pos)
#define CMPX_CFG_CMPRF                 CMPX_CFG_CMPRF_Msk

/********************  Bit definition for CMP_STS register  ********************/
#define CMP_STS_CMP0IF_Pos             (0U)
#define	CMP_STS_CMP0IF_Msk             (0x1L << CMP_STS_CMP0IF_Pos)
#define CMP_STS_CMP0IF                 CMP_STS_CMP0IF_Msk

#define CMP_STS_CMP1IF_Pos             (1U)
#define	CMP_STS_CMP1IF_Msk             (0x1L << CMP_STS_CMP1IF_Pos)
#define CMP_STS_CMP1IF                 CMP_STS_CMP1IF_Msk

#define CMP_STS_CMP2IF_Pos             (2U)
#define	CMP_STS_CMP2IF_Msk             (0x1L << CMP_STS_CMP2IF_Pos)
#define CMP_STS_CMP2IF                 CMP_STS_CMP2IF_Msk

#define CMP_STS_CMP0STA_Pos           (3U)
#define	CMP_STS_CMP0STA_Msk           (0x1L << CMP_STS_CMP0STA_Pos)
#define CMP_STS_CMP0STA               CMP_STS_CMP0STA_Msk

#define CMP_STS_CMP1STA_Pos             (4U)
#define	CMP_STS_CMP1STA_Msk             (0x1L << CMP_STS_CMP1STA_Pos)
#define CMP_STS_CMP1STA                 CMP_STS_CMP1STA_Msk

#define CMP_STS_CMP2STA_Pos             (5U)
#define	CMP_STS_CMP2STA_Msk             (0x1L << CMP_STS_CMP2STA_Pos)
#define CMP_STS_CMP2STA                 CMP_STS_CMP2STA_Msk

/********************  Bit definition for CMP_CON register  ********************/
#define CMP_CON_HYS_Pos         	    (0U)
#define	CMP_CON_HYS_Msk					  	(0x3L << CMP_CON_HYS_Pos)
#define CMP_CON_HYS          			   CMP_CON_HYS_Msk

#define CMP_CON_REFSEL_Pos         (7U)
#define	CMP_CON_REFSEL_Msk					(0x1L << CMP_CON_REFSEL_Pos)
#define CMP_CON_REFSEL          		CMP_CON_REFSEL_Msk
/********************  Bit definition for CMP_IDE register  ********************/
#define CMP_IDE_CMP0IE_Pos         	  (0U)
#define	CMP_IDE_CMP0IE_Msk						(0x1L << CMP_IDE_CMP0IE_Pos)
#define CMP_IDE_CMP0IE          			 CMP_IDE_CMP0IE_Msk

#define CMP_IDE_CMP1IE_Pos         	  (1U)
#define	CMP_IDE_CMP1IE_Msk						(0x1L << CMP_IDE_CMP1IE_Pos)
#define CMP_IDE_CMP1IE          			CMP_IDE_CMP1IE_Msk

#define CMP_IDE_CMP2IE_Pos          	(2U)
#define	CMP_IDE_CMP2IE_Msk						(0x1L << CMP_IDE_CMP2IE_Pos)
#define CMP_IDE_CMP2IE          			CMP_IDE_CMP2IE_Msk

#define CMP_IDE_INTEN_Pos         	  (7U)
#define	CMP_IDE_INTEN_Msk						(0x1UL << CMP_IDE_INTEN_Pos)
#define CMP_IDE_INTEN        			  CMP_IDE_INTEN_Msk


/******************************************************************************/
/*                                                                            */
/*                                    CMP3                                     */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for CMP_CFG register  ********************/
#define CMP_CFG_CMPNS_Pos         		(0U)
#define	CMP_CFG_CMPNS_Msk				    (0x3L << CMP_CFG_CMPNS_Pos)
#define CMP_CFG_CMPNS          		 	CMP_CFG_CMPNS_Msk

#define CMP_CFG_CMPPS_Pos         		(2U)
#define	CMP_CFG_CMPPS_Msk						(0x3L << CMP_CFG_CMPPS_Pos)
#define CMP_CFG_CMPPS          			CMP_CFG_CMPPS_Msk

#define CMP_CFG_CMPIM_Pos         		(5U)
#define	CMP_CFG_CMPIM_Msk						(0x3L << CMP_CFG_CMPIM_Pos)
#define CMP_CFG_CMPIM          			CMP_CFG_CMPIM_Msk

#define CMP_CFG_CMPEN_Pos         		(7U)
#define	CMP_CFG_CMPEN_Msk						(0x1L << CMP_CFG_CMPEN_Pos)
#define CMP_CFG_CMPEN        				CMP_CFG_CMPEN_Msk

#define CMP_CFG_CMPRF_Pos         	 	(8U)
#define CMP_CFG_CMPRF_Msk					  (0x0FL << CMP_CFG_CMPRF_Pos)
#define CMP_CFG_CMPRF        			  CMP_CFG_CMPRF_Msk

/********************  Bit definition for CMP_STS register  ********************/
#define CMP_STS_CMP0IF_Pos         	(0U)
#define	CMP_STS_CMP0IF_Msk						(0x1L << CMP_STS_CMP0IF_Pos)
#define CMP_STS_CMP0IF          			CMP_STS_CMP0IF_Msk

#define CMP_STS_CMP1IF_Pos         	(1U)
#define	CMP_STS_CMP1IF_Msk						(0x1L << CMP_STS_CMP1IF_Pos)
#define CMP_STS_CMP1IF          			CMP_STS_CMP1IF_Msk

#define CMP_STS_CMP2IF_Pos          	(2U)
#define	CMP_STS_CMP2IF_Msk						(0x1L << CMP_STS_CMP2IF_Pos)
#define CMP_STS_CMP2IF          			CMP_STS_CMP2IF_Msk

#define CMP_STS_CMP3IF_Pos         	 (0U)
#define	CMP_STS_CMP3IF_Msk					(0x1L << CMP_STS_CMP3IF_Pos)
#define CMP_STS_CMP3IF          			CMP_STS_CMP3IF_Msk

#define CMP_STS_CMP0STA_Pos         	(3U)
#define	CMP_STS_CMP0STA_Msk					(0x1L << CMP_STS_CMP0STA_Pos)
#define CMP_STS_CMP0STA         		  CMP_STS_CMP0STA_Msk

#define CMP_STS_CMP1STA_Pos         	(4U)
#define	CMP_STS_CMP1STA_Msk					(0x1L << CMP_STS_CMP1STA_Pos)
#define CMP_STS_CMP1STA          		CMP_STS_CMP1STA_Msk

#define CMP_STS_CMP2STA_Pos         	(5U)
#define	CMP_STS_CMP2STA_Msk					(0x1L << CMP_STS_CMP2STA_Pos)
#define CMP_STS_CMP2STA         		  CMP_STS_CMP2STA_Msk

#define CMP_STS_CMP3STA_Pos         	(1U)
#define	CMP_STS_CMP3STA_Msk					(0x1L << CMP_STS_CMP3STA_Pos)
#define CMP_STS_CMP3STA         		  CMP_STS_CMP3STA_Msk

#define CMP3_IDE_INTEN_Pos         	  (7U)
#define	CMP3_IDE_INTEN_Msk						(0x1L << CMP3_IDE_INTEN_Pos)
#define CMP3_IDE_INTEN          			 CMP3_IDE_INTEN_Msk
/******************************************************************************/
/*                                                                            */
/*                      CRC                   */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for CRC_CON register  ********************/
#define CRC_CON_CRCRST_Pos         				(0U)
#define	CRC_CON_CRCRST_Msk								(0x1L << CRC_CON_CRCRST_Pos)
#define CRC_CON_CRCRST          					CRC_CON_CRCRST_Msk

#define CRC_CON_POLYSIZE_Pos         			(6U)
#define	CRC_CON_POLYSIZE_Msk							(0x3L << CRC_CON_POLYSIZE_Pos)
#define CRC_CON_POLYSIZE          				CRC_CON_POLYSIZE_Msk
/********************  Bit definition for CRC_INT register  ********************/
#define CRC_INT_INIT_Pos         				  (0U)
#define	CRC_INT_INIT_Msk								(0xFFFFFFFFL << CRC_INT_INIT_Pos)
#define CRC_INT_INIT          					CRC_INT_INIT_Msk

/******************************************************************************/
/*                                                                            */
/*                      DMA                   																*/
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DMA_CFG register  ********************/
#define DMA_CFG_PL_Pos         						(0U)
#define	DMA_CFG_PL_Msk										(0x3L << DMA_CFG_PL_Pos)
#define DMA_CFG_PL          							DMA_CFG_PL_Msk

#define DMA_CFG_TXWIDTH_Pos         			(2U)
#define	DMA_CFG_TXWIDTH_Msk							(0x3L << DMA_CFG_TXWIDTH_Pos)
#define DMA_CFG_TXWIDTH          				DMA_CFG_TXWIDTH_Msk

#define DMA_CFG_CIRC_Pos         					(4U)
#define	DMA_CFG_CIRC_Msk									(0x1L << DMA_CFG_CIRC_Pos)
#define DMA_CFG_CIRC          						DMA_CFG_CIRC_Msk

#define DMA_CFG_PAUSE_Pos         				(5U)
#define	DMA_CFG_PAUSE_Msk									(0x1L << DMA_CFG_PAUSE_Pos)
#define DMA_CFG_PAUSE          						DMA_CFG_PAUSE_Msk

#define DMA_CFG_CHRST_Pos         				(6U)
#define	DMA_CFG_CHRST_Msk									(0x1L << DMA_CFG_CHRST_Pos)
#define DMA_CFG_CHRST          						DMA_CFG_CHRST_Msk

#define DMA_CFG_CHEN_Pos         					(7U)
#define	DMA_CFG_CHEN_Msk									(0x1L << DMA_CFG_CHEN_Pos)
#define DMA_CFG_CHEN          						DMA_CFG_CHEN_Msk

#define DMA_CFG_DAINC_Pos         				(8U)
#define	DMA_CFG_DAINC_Msk									(0x3L << DMA_CFG_DAINC_Pos)
#define DMA_CFG_DAINC         						DMA_CFG_DAINC_Msk

#define DMA_CFG_SAINC_Pos         				(10U)
#define	DMA_CFG_SAINC_Msk									(0x3L << DMA_CFG_SAINC_Pos)
#define DMA_CFG_SAINC         						DMA_CFG_SAINC_Msk

#define DMA_CFG_BURSIZE_Pos         			(12U)
#define	DMA_CFG_BURSIZE_Msk								(0x7L << DMA_CFG_BURSIZE_Pos)
#define DMA_CFG_BURSIZE         					DMA_CFG_BURSIZE_Msk

#define DMA_CFG_TPTYPE_Pos         				(15U)
#define	DMA_CFG_TPTYPE_Msk								(0x1L << DMA_CFG_TPTYPE_Pos)
#define DMA_CFG_TPTYPE        						DMA_CFG_TPTYPE_Msk

#define DMA_CFG_INTEN_Pos         				(16U)
#define	DMA_CFG_INTEN_Msk									(0x1L << DMA_CFG_INTEN_Pos)
#define DMA_CFG_INTEN        							DMA_CFG_INTEN_Msk

#define DMA_CFG_TCIE_Pos         					(17U)
#define	DMA_CFG_TCIE_Msk									(0x1L << DMA_CFG_TCIE_Pos)
#define DMA_CFG_TCIE        							DMA_CFG_TCIE_Msk

#define DMA_CFG_HTIE_Pos         					(18U)
#define	DMA_CFG_HTIE_Msk									(0x1L << DMA_CFG_HTIE_Pos)
#define DMA_CFG_HTIE        							DMA_CFG_HTIE_Msk

#define DMA_CFG_TEIE_Pos         					(19U)
#define	DMA_CFG_TEIE_Msk									(0x1L << DMA_CFG_TEIE_Pos)
#define DMA_CFG_TEIE        							DMA_CFG_TEIE_Msk

#define DMA_CFG_CHRQ_Pos         					(23U)
#define	DMA_CFG_CHRQ_Msk									(0x1L << DMA_CFG_CHRQ_Pos)
#define DMA_CFG_CHRQ        							DMA_CFG_CHRQ_Msk

#define DMA_CFG_REQSRC_Pos         				(24U)
#define	DMA_CFG_REQSRC_Msk								(0x3FL << DMA_CFG_REQSRC_Pos)
#define DMA_CFG_REQSRC        						DMA_CFG_REQSRC_Msk

/********************  Bit definition for DMA_STS register  ********************/
#define DMA_STS_GIF_Pos         					(0U)
#define	DMA_STS_GIF_Msk										(0x1L << DMA_STS_GIF_Pos)
#define DMA_STS_GIF        								DMA_STS_GIF_Msk

#define DMA_STS_TCIF_Pos         					(1U)
#define	DMA_STS_TCIF_Msk									(0x1L << DMA_STS_TCIF_Pos)
#define DMA_STS_TCIF        							DMA_STS_TCIF_Msk

#define DMA_STS_HTIF_Pos         					(2U)
#define	DMA_STS_HTIF_Msk									(0x1L << DMA_STS_HTIF_Pos)
#define DMA_STS_HTIF        							DMA_STS_HTIF_Msk

#define DMA_STS_TEIF_Pos         					(3U)
#define	DMA_STS_TEIF_Msk									(0x1L << DMA_STS_TEIF_Pos)
#define DMA_STS_TEIF        							DMA_STS_TEIF_Msk

#define DMA_STS_STATUS_Pos         				(4U)
#define	DMA_STS_STATUS_Msk								(0x0FL << DMA_STS_STATUS_Pos)
#define DMA_STS_STATUS        						DMA_STS_STATUS_Msk

#define DMA_STS_SWREQ_Pos         				(8U)
#define	DMA_STS_SWREQ_Msk									(0x1L << DMA_STS_SWREQ_Pos)
#define DMA_STS_SWREQ       							DMA_STS_SWREQ_Msk

/******************************************************************************/
/*                                                                            */
/*                      IAP                   																*/
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for IAP_CON register  ********************/
#define IAP_CON_CMD_Pos         					(0U)
#define	IAP_CON_CMD_Msk										(0x3L << IAP_CON_CMD_Pos)
#define IAP_CON_CMD          							IAP_CON_CMD_Msk

#define IAP_CON_PRG_Pos         					(4U)
#define	IAP_CON_PRG_Msk										(0x1L << IAP_CON_PRG_Pos)
#define IAP_CON_PRG         							IAP_CON_PRG_Msk

#define IAP_CON_SERASE_Pos         				(5U)
#define	IAP_CON_SERASE_Msk								(0x1L << IAP_CON_SERASE_Pos)
#define IAP_CON_SERASE         						IAP_CON_SERASE_Msk

#define IAP_CON_ERASE_Pos         				(7U)
#define	IAP_CON_ERASE_Msk									(0x1L << IAP_CON_ERASE_Pos)
#define IAP_CON_ERASE         						IAP_CON_ERASE_Msk

#define IAP_CON_RST_Pos    					      (8U)
#define	IAP_CON_RST_Msk										(0x1L << IAP_CON_RST_Pos)
#define IAP_CON_RST         							IAP_CON_RST_Msk

#define IAP_CON_BTLD_Pos         					(9U)
#define	IAP_CON_BTLD_Msk									(0x3L << IAP_CON_BTLD_Pos)
#define IAP_CON_BTLD         							IAP_CON_BTLD_Msk

#define IAP_CON_DMAEN_Pos                 (11U)
#define IAP_CON_DMAEN_Msk                 (0x1L<<IAP_CON_DMAEN_Pos)
#define IAP_CON_DMAEN                     IAP_CON_DMAEN_Msk

#define IAP_CON_CONT_Pos                  (16U)
#define IAP_CON_CONT_Msk                  (0x3FL<<IAP_CON_CONT_Pos)
#define IAP_CON_CONT                      IAP_CON_CONT_Msk

#define IAP_CON_LOCK_Pos         					(31U)
#define	IAP_CON_LOCK_Msk									(0x1UL << IAP_CON_LOCK_Pos)
#define IAP_CON_LOCK         							IAP_CON_LOCK_Msk

/******************************************************************************/
/*                                                                            */
/*                      INT                  																*/
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for INT_FIE register  ********************/
#define INT_FIE_ENF0_Pos         			(0U)
#define	INT_FIE_ENF0_Msk						    (0x1L << INT_FIE_ENF0_Pos)
#define INT_FIE_ENF0          					INT_FIE_ENF0_Msk

#define INT_FIE_ENF1_Pos         			(1U)
#define	INT_FIE_ENF1_Msk						    (0x1L << INT_FIE_ENF1_Pos)
#define INT_FIE_ENF1          					INT_FIE_ENF1_Msk

#define INT_FIE_ENF2_Pos         			(2U)
#define	INT_FIE_ENF2_Msk						    (0x1L << INT_FIE_ENF2_Pos)
#define INT_FIE_ENF2          					INT_FIE_ENF2_Msk

#define INT_FIE_ENF3_Pos         			(3U)
#define	INT_FIE_ENF3_Msk						    (0x1L << INT_FIE_ENF3_Pos)
#define INT_FIE_ENF3          					INT_FIE_ENF3_Msk

#define INT_FIE_ENF4_Pos         				(4U)
#define	INT_FIE_ENF4_Msk						(0x1L << INT_FIE_ENF4_Pos)
#define INT_FIE_ENF4          					INT_FIE_ENF4_Msk

#define INT_FIE_ENF5_Pos         				(5U)
#define	INT_FIE_ENF5_Msk						(0x1L << INT_FIE_ENF5_Pos)
#define INT_FIE_ENF5          					INT_FIE_ENF5_Msk

#define INT_FIE_ENF6_Pos         				(6U)
#define	INT_FIE_ENF6_Msk						(0x1L << INT_FIE_ENF6_Pos)
#define INT_FIE_ENF6          					INT_FIE_ENF6_Msk

#define INT_FIE_ENF7_Pos         				(7U)
#define	INT_FIE_ENF7_Msk						(0x1L << INT_FIE_ENF7_Pos)
#define INT_FIE_ENF7          					INT_FIE_ENF7_Msk

#define INT_FIE_ENF8_Pos         				(8U)
#define	INT_FIE_ENF8_Msk						(0x1L << INT_FIE_ENF8_Pos)
#define INT_FIE_ENF8          					INT_FIE_ENF8_Msk

#define INT_FIE_ENF9_Pos         				(9U)
#define	INT_FIE_ENF9_Msk						(0x1L << INT_FIE_ENF9_Pos)
#define INT_FIE_ENF9          					INT_FIE_ENF9_Msk

#define INT_FIE_ENF10_Pos         				(10U)
#define	INT_FIE_ENF10_Msk						(0x1L << INT_FIE_ENF10_Pos)
#define INT_FIE_ENF10          				INT_FIE_ENF10_Msk

#define INT_FIE_ENF11_Pos         				(11U)
#define	INT_FIE_ENF11_Msk						(0x1L << INT_FIE_ENF11_Pos)
#define INT_FIE_ENF11          				INT_FIE_ENF11_Msk

#define INT_FIE_ENF12_Pos         				(12U)
#define	INT_FIE_ENF12_Msk						(0x1L << INT_FIE_ENF12_Pos)
#define INT_FIE_ENF12          				INT_FIE_ENF12_Msk

#define INT_FIE_ENF13_Pos         				(13U)
#define	INT_FIE_ENF13_Msk						(0x1L << INT_FIE_ENF13_Pos)
#define INT_FIE_ENF13          				INT_FIE_ENF13_Msk

#define INT_FIE_ENF14_Pos         				(14U)
#define	INT_FIE_ENF14_Msk						(0x1L << INT_FIE_ENF14_Pos)
#define INT_FIE_ENF14          				INT_FIE_ENF14_Msk

#define INT_FIE_ENF15_Pos         				(15U)
#define	INT_FIE_ENF15_Msk						(0x1L << INT_FIE_ENF15_Pos)
#define INT_FIE_ENF15          				INT_FIE_ENF15_Msk
/********************  Bit definition for INT_RIE register  ********************/
#define INT_RIE_ENR0_Pos         				(0U)
#define	INT_RIE_ENR0_Msk									(0x1L << INT_RIE_ENR0_Pos)
#define INT_RIE_ENR0          						INT_RIE_ENR0_Msk

#define INT_RIE_ENR1_Pos         				(1U)
#define	INT_RIE_ENR1_Msk									(0x1L << INT_RIE_ENR1_Pos)
#define INT_RIE_ENR1          						INT_RIE_ENR1_Msk

#define INT_RIE_ENR2_Pos         				(2U)
#define	INT_RIE_ENR2_Msk									(0x1L << INT_RIE_ENR2_Pos)
#define INT_RIE_ENR2          						INT_RIE_ENR2_Msk

#define INT_RIE_ENR3_Pos         				(3U)
#define	INT_RIE_ENR3_Msk									(0x1L << INT_RIE_ENR3_Pos)
#define INT_RIE_ENR3          						INT_RIE_ENR3_Msk

#define INT_RIE_ENR4_Pos         				(4U)
#define	INT_RIE_ENR4_Msk									(0x1L << INT_RIE_ENR4_Pos)
#define INT_RIE_ENR4          						INT_RIE_ENR4_Msk

#define INT_RIE_ENR5_Pos         				(5U)
#define	INT_RIE_ENR5_Msk									(0x1L << INT_RIE_ENR5_Pos)
#define INT_RIE_ENR5          						INT_RIE_ENR5_Msk

#define INT_RIE_ENR6_Pos         				(6U)
#define	INT_RIE_ENR6_Msk									(0x1L << INT_RIE_ENR6_Pos)
#define INT_RIE_ENR6          						INT_RIE_ENR6_Msk

#define INT_RIE_ENR7_Pos         				(7U)
#define	INT_RIE_ENR7_Msk									(0x1L << INT_RIE_ENR7_Pos)
#define INT_RIE_ENR7          						INT_RIE_ENR7_Msk

#define INT_RIE_ENR8_Pos         				(8U)
#define	INT_RIE_ENR8_Msk									(0x1L << INT_RIE_ENR8_Pos)
#define INT_RIE_ENR8          						INT_RIE_ENR8_Msk

#define INT_RIE_ENR9_Pos         				(9U)
#define	INT_RIE_ENR9_Msk									(0x1L << INT_RIE_ENR9_Pos)
#define INT_RIE_ENR9          						INT_RIE_ENR9_Msk

#define INT_RIE_ENR10_Pos         				(10U)
#define	INT_RIE_ENR10_Msk								(0x1L << INT_RIE_ENR10_Pos)
#define INT_RIE_ENR10          					INT_RIE_ENR10_Msk

#define INT_RIE_ENR11_Pos         				(11U)
#define	INT_RIE_ENR11_Msk								(0x1L << INT_RIE_ENR11_Pos)
#define INT_RIE_ENR11          					INT_RIE_ENR11_Msk

#define INT_RIE_ENR12_Pos         				(12U)
#define	INT_RIE_ENR12_Msk								(0x1L << INT_RIE_ENR12_Pos)
#define INT_RIE_ENR12          					INT_RIE_ENR12_Msk

#define INT_RIE_ENR13_Pos         				(13U)
#define	INT_RIE_ENR13_Msk								(0x1L << INT_RIE_ENR13_Pos)
#define INT_RIE_ENR13          					INT_RIE_ENR13_Msk

#define INT_RIE_ENR14_Pos         				(14U)
#define	INT_RIE_ENR14_Msk								(0x1L << INT_RIE_ENR14_Pos)
#define INT_RIE_ENR14          					INT_RIE_ENR14_Msk

#define INT_RIE_ENR15_Pos         				(15U)
#define	INT_RIE_ENR15_Msk								(0x1L << INT_RIE_ENR15_Pos)
#define INT_RIE_ENR15          					INT_RIE_ENR15_Msk

/********************  Bit definition for INT_SEL0 register  ********************/
#define INT_SEL0_INT0SEL_Pos         		(0U)
#define	INT_SEL0_INT0SEL_Msk							(0x0FL << INT_SEL0_INT0SEL_Pos)
#define INT_SEL0_INT0SEL          				INT_SEL0_INT0SEL_Msk

#define INT_SEL0_INT1SEL_Pos         		(4U)
#define	INT_SEL0_INT1SEL_Msk							(0x0FL << INT_SEL0_INT1SEL_Pos)
#define INT_SEL0_INT1SEL          				INT_SEL0_INT1SEL_Msk

#define INT_SEL0_INT2SEL_Pos         		(8U)
#define	INT_SEL0_INT2SEL_Msk							(0x0FL << INT_SEL0_INT2SEL_Pos)
#define INT_SEL0_INT2SEL          				INT_SEL0_INT2SEL_Msk

#define INT_SEL0_INT3SEL_Pos         		(12U)
#define	INT_SEL0_INT3SEL_Msk							(0x0FL << INT_SEL0_INT3SEL_Pos)
#define INT_SEL0_INT3SEL          				INT_SEL0_INT3SEL_Msk

#define INT_SEL0_INT4SEL_Pos         		(16U)
#define	INT_SEL0_INT4SEL_Msk							(0x0FL << INT_SEL0_INT4SEL_Pos)
#define INT_SEL0_INT4SEL          				INT_SEL0_INT4SEL_Msk

#define INT_SEL0_INT5SEL_Pos         		(20U)
#define	INT_SEL0_INT5SEL_Msk							(0x0FL << INT_SEL0_INT5SEL_Pos)
#define INT_SEL0_INT5SEL          				INT_SEL0_INT5SEL_Msk

#define INT_SEL0_INT6SEL_Pos         		(24U)
#define	INT_SEL0_INT6SEL_Msk							(0x0FL << INT_SEL0_INT6SEL_Pos)
#define INT_SEL0_INT6SEL          				INT_SEL0_INT6SEL_Msk

#define INT_SEL0_INT7SEL_Pos         		(28U)
#define	INT_SEL0_INT7SEL_Msk							(0x0FL << INT_SEL0_INT7SEL_Pos)
#define INT_SEL0_INT7SEL          				INT_SEL0_INT7SEL_Msk

/********************  Bit definition for INT_SEL1 register  ********************/
#define INT_SEL1_INT8SEL_Pos         		(0U)
#define	INT_SEL1_INT8SEL_Msk							(0x0FL << INT_SEL1_INT8SEL_Pos)
#define INT_SEL1_INT8SEL          				INT_SEL1_INT8SEL_Msk

#define INT_SEL1_INT9SEL_Pos         		(4U)
#define	INT_SEL1_INT9SEL_Msk							(0x0FL << INT_SEL1_INT9SEL_Pos)
#define INT_SEL1_INT9SEL          				INT_SEL1_INT9SEL_Msk

#define INT_SEL1_INT10SEL_Pos         		(8U)
#define	INT_SEL1_INT10SEL_Msk						(0x0FL << INT_SEL1_INT10SEL_Pos)
#define INT_SEL1_INT10SEL          			INT_SEL1_INT10SEL_Msk

#define INT_SEL1_INT11SEL_Pos         		(12U)
#define	INT_SEL1_INT11SEL_Msk						(0x0FL << INT_SEL1_INT11SEL_Pos)
#define INT_SEL1_INT11SEL          			INT_SEL1_INT11SEL_Msk

#define INT_SEL1_INT12SEL_Pos         		(16U)
#define	INT_SEL1_INT12SEL_Msk						(0x0FL << INT_SEL1_INT12SEL_Pos)
#define INT_SEL1_INT12SEL          			INT_SEL1_INT12SEL_Msk

#define INT_SEL1_INT13SEL_Pos         		(20U)
#define	INT_SEL1_INT13SEL_Msk						(0x0FL << INT_SEL1_INT13SEL_Pos)
#define INT_SEL1_INT13SEL          			INT_SEL1_INT13SEL_Msk

#define INT_SEL1_INT14SEL_Pos         		(24U)
#define	INT_SEL1_INT14SEL_Msk						(0x0FL << INT_SEL1_INT14SEL_Pos)
#define INT_SEL1_INT14SEL          			INT_SEL1_INT14SEL_Msk

#define INT_SEL1_INT15SEL_Pos         		(28U)
#define	INT_SEL1_INT15SEL_Msk						(0x0FL << INT_SEL1_INT15SEL_Pos)
#define INT_SEL1_INT15SEL          			INT_SEL1_INT15SEL_Msk


/********************  Bit definition for INT_FCON register  ********************/
#define INT_FCON_FT0_Pos         				(0U)
#define	INT_FCON_FT0_Msk									(0x1L << INT_FCON_FT0_Pos)
#define INT_FCON_FT0          						INT_FCON_FT0_Msk

#define INT_FCON_FT1_Pos         				(1U)
#define	INT_FCON_FT1_Msk									(0x1L << INT_FCON_FT1_Pos)
#define INT_FCON_FT1          						INT_FCON_FT1_Msk

#define INT_FCON_FT2_Pos         				(2U)
#define	INT_FCON_FT2_Msk									(0x1L << INT_FCON_FT2_Pos)
#define INT_FCON_FT2          						INT_FCON_FT2_Msk

#define INT_FCON_FT3_Pos         				(3U)
#define	INT_FCON_FT3_Msk									(0x1L << INT_FCON_FT3_Pos)
#define INT_FCON_FT3          						INT_FCON_FT3_Msk

#define INT_FCON_FT4_Pos         				(4U)
#define	INT_FCON_FT4_Msk									(0x1L << INT_FCON_FT4_Pos)
#define INT_FCON_FT4          						INT_FCON_FT4_Msk

#define INT_FCON_FT5_Pos         				(5U)
#define	INT_FCON_FT5_Msk									(0x1L << INT_FCON_FT5_Pos)
#define INT_FCON_FT5          						INT_FCON_FT5_Msk

#define INT_FCON_FT6_Pos         				(6U)
#define	INT_FCON_FT6_Msk									(0x1L << INT_FCON_FT6_Pos)
#define INT_FCON_FT6          						INT_FCON_FT6_Msk

#define INT_FCON_FT7_Pos         				(7U)
#define	INT_FCON_FT7_Msk									(0x1L << INT_FCON_FT7_Pos)
#define INT_FCON_FT          						INT_FCON_FT7_Msk

#define INT_FCON_FT8_Pos         				(8U)
#define	INT_FCON_FT8_Msk									(0x1L << INT_FCON_FT8_Pos)
#define INT_FCON_FT8          						INT_FCON_FT8_Msk

#define INT_FCON_FT9_Pos         				(9U)
#define	INT_FCON_FT9_Msk									(0x1L << INT_FCON_FT9_Pos)
#define INT_FCON_FT9          						INT_FCON_FT9_Msk

#define INT_FCON_FT10_Pos         				(10U)
#define	INT_FCON_FT10_Msk								(0x1L << INT_FCON_FT10_Pos)
#define INT_FCON_FT10          					INT_FCON_FT10_Msk

#define INT_FCON_FT11_Pos         				(11U)
#define	INT_FCON_FT11_Msk								(0x1L << INT_FCON_FT11_Pos)
#define INT_FCON_FT11          					INT_FCON_FT11_Msk

#define INT_FCON_FT12_Pos         				(12U)
#define	INT_FCON_FT12_Msk								(0x1L << INT_FCON_FT12_Pos)
#define INT_FCON_FT12          					INT_FCON_FT12_Msk

#define INT_FCON_FT13_Pos         				(13U)
#define	INT_FCON_FT13_Msk								(0x1L << INT_FCON_FT13_Pos)
#define INT_FCON_FT13          					INT_FCON_FT13_Msk

#define INT_FCON_FT14_Pos         				(14U)
#define	INT_FCON_FT14_Msk								(0x1L << INT_FCON_FT14_Pos)
#define INT_FCON_FT14          					INT_FCON_FT14_Msk

#define INT_FCON_FT15_Pos         				(15U)
#define	INT_FCON_FT15_Msk								(0x1L << INT_FCON_FT15_Pos)
#define INT_FCON_FT15          					INT_FCON_FT15_Msk

/********************  Bit definition for INT_RCON register  ********************/
#define INT_RCON_RT0_Pos         				(0U)
#define	INT_RCON_RT0_Msk									(0x1L << INT_RCON_RT0_Pos)
#define INT_RCON_RT0          						INT_RCON_RT0_Msk

#define INT_RCON_RT1_Pos         				(1U)
#define	INT_RCON_RT_Msk									(0x1L << INT_RCON_RT1_Pos)
#define INT_RCON_RT1          						INT_RCON_RT_Msk

#define INT_RCON_RT2_Pos         				(2U)
#define	INT_RCON_RT2_Msk									(0x1L << INT_RCON_RT2_Pos)
#define INT_RCON_RT2          						INT_RCON_RT2_Msk

#define INT_RCON_RT3_Pos         				(3U)
#define	INT_RCON_RT3_Msk									(0x1L << INT_RCON_RT3_Pos)
#define INT_RCON_RT3          						INT_RCON_RT3_Msk

#define INT_RCON_RT4_Pos         				(4U)
#define	INT_RCON_RT4_Msk									(0x1L << INT_RCON_RT4_Pos)
#define INT_RCON_RT4          						INT_RCON_RT4_Msk

#define INT_RCON_RT5_Pos         				(5U)
#define	INT_RCON_RT5_Msk									(0x1L << INT_RCON_RT5_Pos)
#define INT_RCON_RT5          						INT_RCON_RT5_Msk

#define INT_RCON_RT6_Pos         				(6U)
#define	INT_RCON_RT6_Msk									(0x1L << INT_RCON_RT6_Pos)
#define INT_RCON_RT6          						INT_RCON_RT6_Msk

#define INT_RCON_RT7_Pos         				(7U)
#define	INT_RCON_RT7_Msk									(0x1L << INT_RCON_RT7_Pos)
#define INT_RCON_RT          						INT_RCON_RT7_Msk

#define INT_RCON_RT8_Pos         				(8U)
#define	INT_RCON_RT8_Msk									(0x1L << INT_RCON_RT8_Pos)
#define INT_RCON_RT8          						INT_RCON_RT8_Msk

#define INT_RCON_RT9_Pos         				(9U)
#define	INT_RCON_RT9_Msk									(0x1L << INT_RCON_RT9_Pos)
#define INT_RCON_RT9          						INT_RCON_RT9_Msk

#define INT_RCON_RT10_Pos         				(10U)
#define	INT_RCON_RT10_Msk								(0x1L << INT_RCON_RT10_Pos)
#define INT_RCON_RT10          					INT_RCON_RT10_Msk

#define INT_RCON_RT11_Pos         				(11U)
#define	INT_RCON_RT11_Msk								(0x1L << INT_RCON_RT11_Pos)
#define INT_RCON_RT11          					INT_RCON_RT11_Msk

#define INT_RCON_RT12_Pos         				(12U)
#define	INT_RCON_RT12_Msk								(0x1L << INT_RCON_RT12_Pos)
#define INT_RCON_RT12          					INT_RCON_RT12_Msk

#define INT_RCON_RT13_Pos         				(13U)
#define	INT_RCON_RT13_Msk								(0x1L << INT_RCON_RT13_Pos)
#define INT_RCON_RT13          					INT_RCON_RT13_Msk

#define INT_RCON_RT14_Pos         				(14U)
#define	INT_RCON_RT14_Msk								(0x1L << INT_RCON_RT14_Pos)
#define INT_RCON_RT14          					INT_RCON_RT14_Msk

#define INT_RCON_RT15_Pos         				(15U)
#define	INT_RCON_RT15_Msk								(0x1L << INT_RCON_RT15_Pos)
#define INT_RCON_RT15          					INT_RCON_RT15_Msk

/********************  Bit definition for INT_FSTS register  ********************/
#define INT_FSTS_FIF0_Pos         				(0U)
#define	INT_FSTS_FIF0_Msk						(0x1L << INT_FSTS_FIF0_Pos)
#define INT_FSTS_FIF0          				INT_FSTS_FIF0_Msk

#define INT_FSTS_FIF1_Pos         				(1U)
#define	INT_FSTS_FIF1_Msk						(0x1L << INT_FSTS_FIF1_Pos)
#define INT_FSTS_FIF1          				INT_FSTS_FIF1_Msk

#define INT_FSTS_FIF2_Pos         				(2U)
#define	INT_FSTS_FIF2_Msk						(0x1L << INT_FSTS_FIF2_Pos)
#define INT_FSTS_FIF2          				INT_FSTS_FIF2_Msk

#define INT_FSTS_FIF3_Pos         				(3U)
#define	INT_FSTS_FIF3_Msk						(0x1L << INT_FSTS_FIF3_Pos)
#define INT_FSTS_FIF3          				INT_FSTS_FIF3_Msk

#define INT_FSTS_FIF4_Pos         				(4U)
#define	INT_FSTS_FIF4_Msk						(0x1L << INT_FSTS_FIF4_Pos)
#define INT_FSTS_FIF4          				INT_FSTS_FIF4_Msk

#define INT_FSTS_FIF5_Pos         				(5U)
#define	INT_FSTS_FIF5_Msk						(0x1L << INT_FSTS_FIF5_Pos)
#define INT_FSTS_FIF5          				INT_FSTS_FIF5_Msk

#define INT_FSTS_FIF6_Pos         				(6U)
#define	INT_FSTS_FIF6_Msk						(0x1L << INT_FSTS_FIF6_Pos)
#define INT_FSTS_FIF6          				INT_FSTS_FIF6_Msk

#define INT_FSTS_FIF7_Pos         				(7U)
#define	INT_FSTS_FIF7_Msk						(0x1L << INT_FSTS_FIF7_Pos)
#define INT_FSTS_FIF          					INT_FSTS_FIF7_Msk

#define INT_FSTS_FIF8_Pos         				(8U)
#define	INT_FSTS_FIF8_Msk								(0x1L << INT_FSTS_FIF8_Pos)
#define INT_FSTS_FIF8          					INT_FSTS_FIF8_Msk

#define INT_FSTS_FIF9_Pos         				(9U)
#define	INT_FSTS_FIF9_Msk								(0x1L << INT_FSTS_FIF9_Pos)
#define INT_FSTS_FIF9          					INT_FSTS_FIF9_Msk

#define INT_FSTS_FIF10_Pos         			(10U)
#define	INT_FSTS_FIF10_Msk								(0x1L << INT_FSTS_FIF10_Pos)
#define INT_FSTS_FIF10          					INT_FSTS_FIF10_Msk

#define INT_FSTS_FIF11_Pos         			(11U)
#define	INT_FSTS_FIF11_Msk								(0x1L << INT_FSTS_FIF11_Pos)
#define INT_FSTS_FIF11          					INT_FSTS_FIF11_Msk

#define INT_FSTS_FIF12_Pos         			(12U)
#define	INT_FSTS_FIF12_Msk								(0x1L << INT_FSTS_FIF12_Pos)
#define INT_FSTS_FIF12          					INT_FSTS_FIF12_Msk

#define INT_FSTS_FIF13_Pos         			(13U)
#define	INT_FSTS_FIF13_Msk								(0x1L << INT_FSTS_FIF13_Pos)
#define INT_FSTS_FIF13          					INT_FSTS_FIF13_Msk

#define INT_FSTS_FIF14_Pos         			(14U)
#define	INT_FSTS_FIF14_Msk								(0x1L << INT_FSTS_FIF14_Pos)
#define INT_FSTS_FIF14          					INT_FSTS_FIF14_Msk

#define INT_FSTS_FIF15_Pos         			(15U)
#define	INT_FSTS_FIF15_Msk								(0x1L << INT_FSTS_FIF15_Pos)
#define INT_FSTS_FIF15          					INT_FSTS_FIF15_Msk

/********************  Bit definition for INT_RSTS register  ********************/
#define INT_RSTS_RIF0_Pos         				(0U)
#define	INT_RSTS_RIF0_Msk								(0x1L << INT_RSTS_RIF0_Pos)
#define INT_RSTS_RIF0          					INT_RSTS_RIF0_Msk

#define INT_RSTS_RIF1_Pos         				(1U)
#define	INT_RSTS_RIF_Msk									(0x1L << INT_RSTS_RIF1_Pos)
#define INT_RSTS_RIF1          					INT_RSTS_RIF_Msk

#define INT_RSTS_RIF2_Pos         				(2U)
#define	INT_RSTS_RIF2_Msk								(0x1L << INT_RSTS_RIF2_Pos)
#define INT_RSTS_RIF2          					INT_RSTS_RIF2_Msk

#define INT_RSTS_RIF3_Pos         				(3U)
#define	INT_RSTS_RIF3_Msk								(0x1L << INT_RSTS_RIF3_Pos)
#define INT_RSTS_RIF3          					INT_RSTS_RIF3_Msk

#define INT_RSTS_RIF4_Pos         				(4U)
#define	INT_RSTS_RIF4_Msk								(0x1L << INT_RSTS_RIF4_Pos)
#define INT_RSTS_RIF4          					INT_RSTS_RIF4_Msk

#define INT_RSTS_RIF5_Pos         				(5U)
#define	INT_RSTS_RIF5_Msk								(0x1L << INT_RSTS_RIF5_Pos)
#define INT_RSTS_RIF5          					INT_RSTS_RIF5_Msk

#define INT_RSTS_RIF6_Pos         				(6U)
#define	INT_RSTS_RIF6_Msk								(0x1L << INT_RSTS_RIF6_Pos)
#define INT_RSTS_RIF6          					INT_RSTS_RIF6_Msk

#define INT_RSTS_RIF7_Pos         				(7U)
#define	INT_RSTS_RIF7_Msk								(0x1L << INT_RSTS_RIF7_Pos)
#define INT_RSTS_RIF          						INT_RSTS_RIF7_Msk

#define INT_RSTS_RIF8_Pos         				(8U)
#define	INT_RSTS_RIF8_Msk								(0x1L << INT_RSTS_RIF8_Pos)
#define INT_RSTS_RIF8          					INT_RSTS_RIF8_Msk

#define INT_RSTS_RIF9_Pos         				(9U)
#define	INT_RSTS_RIF9_Msk								(0x1L << INT_RSTS_RIF9_Pos)
#define INT_RSTS_RIF9          					INT_RSTS_RIF9_Msk

#define INT_RSTS_RIF10_Pos         			(10U)
#define	INT_RSTS_RIF10_Msk								(0x1L << INT_RSTS_RIF10_Pos)
#define INT_RSTS_RIF10          					INT_RSTS_RIF10_Msk

#define INT_RSTS_RIF11_Pos         			(11U)
#define	INT_RSTS_RIF11_Msk								(0x1L << INT_RSTS_RIF11_Pos)
#define INT_RSTS_RIF11          					INT_RSTS_RIF11_Msk

#define INT_RSTS_RIF12_Pos         			(12U)
#define	INT_RSTS_RIF12_Msk								(0x1L << INT_RSTS_RIF12_Pos)
#define INT_RSTS_RIF12          					INT_RSTS_RIF12_Msk

#define INT_RSTS_RIF13_Pos         			(13U)
#define	INT_RSTS_RIF13_Msk								(0x1L << INT_RSTS_RIF13_Pos)
#define INT_RSTS_RIF13          					INT_RSTS_RIF13_Msk

#define INT_RSTS_RIF14_Pos         			(14U)
#define	INT_RSTS_RIF14_Msk								(0x1L << INT_RSTS_RIF14_Pos)
#define INT_RSTS_RIF14          					INT_RSTS_RIF14_Msk

#define INT_RSTS_RIF15_Pos         			(15U)
#define	INT_RSTS_RIF15_Msk								(0x1L << INT_RSTS_RIF15_Pos)
#define INT_RSTS_RIF15          					INT_RSTS_RIF15

/******************************************************************************/
/*                                                                            */
/*                        OP                  																*/
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for OP_CON register  ********************/
#define OP_CON_OPOSEL_Pos           (0U)
#define	OP_CON_OPOSEL_Msk						(0x1L << OP_CON_OPOSEL_Pos)
#define OP_CON_OPOSEL 							OP_CON_OPOSEL_Msk

#define OP_CON_OPNSEL_Pos           (2U)
#define	OP_CON_OPNSEL_Msk						(0x3L << OP_CON_OPNSEL_Pos)
#define OP_CON_OPNSEL 							OP_CON_OPNSEL_Msk

#define OP_CON_OPPSEL_Pos           (4U)
#define	OP_CON_OPPSEL_Msk						(0x3L << OP_CON_OPPSEL_Pos)
#define OP_CON_OPPSEL 							OP_CON_OPPSEL_Msk

#define OP_CON_ENOP_Pos         		  (7U)
#define	OP_CON_ENOP_Msk							  (0x1L << OP_CON_ENOP_Pos)
#define OP_CON_ENOP          					OP_CON_ENOP_Msk

#define OP_CON_PGAGAN_Pos							(8U)
#define	OP_CON_PGAGAN_Msk							(0x3L << OP_CON_PGAGAN_Pos)
#define OP_CON_PGAGAN								  OP_CON_PGAGAN_Msk

#define OP_CON_MODE_Pos							(11U)
#define	OP_CON_MODE_Msk							(0x1L << OP_CON_MODE_Pos)
#define OP_CON_MODE								  OP_CON_MODE_Msk

#define OP_CON_OPRF_Pos							(12U)
#define	OP_CON_OPRF_Msk							(0xFL << OP_CON_OPRF_Pos)
#define OP_CON_OPRF								  OP_CON_OPRF_Msk

#define OP_CON_TRIMOFFSETP_Pos				(16U)
#define	OP_CON_TRIMOFFSETP_Msk				(0x1FL << OP_CON_TRIMOFFSETP_Pos)
#define OP_CON_TRIMOFFSETP          	OP_CON_TRIMOFFSETP_Msk

#define OP_CON_PGAOFC_Pos         		(23U)
#define	OP_CON_PGAOFC_Msk							(0x1L << OP_CON_PGAOFC_Pos)
#define OP_CON_PGAOFC          				OP_CON_PGAOFC_Msk

#define OP_CON_TRIMOFFSETN_Pos				(24U)
#define	OP_CON_TRIMOFFSETN_Msk				(0x1FL << OP_CON_TRIMOFFSETN_Pos)
#define OP_CON_TRIMOFFSETN          	OP_CON_TRIMOFFSETN_Msk

#define OP_CON_FDBRSEL_Pos         		(30U)
#define	OP_CON_FDBRSEL_Msk						(0x1L << OP_CON_FDBRSEL_Pos)
#define OP_CON_FDBRSEL          			OP_CON_FDBRSEL_Msk
/********************  Bit definition for OP_CFG register  ********************/
#define OP_CFG_OPCMPIM1_Pos         	(2U)
#define	OP_CFG_OPCMPIM1_Msk						(0x3L << OP_CFG_OPCMPIM1_Pos)
#define OP_CFG_OPCMPIM1          			OP_CFG_OPCMPIM1_Msk

#define OP_CFG_OPCMPIM2_Pos         	(4U)
#define	OP_CFG_OPCMPIM2_Msk						(0x3L << OP_CFG_OPCMPIM2_Pos)
#define OP_CFG_OPCMPIM2          			OP_CFG_OPCMPIM2_Msk

#define OP_CFG_REFSEL_Pos         	 (7U)
#define	OP_CFG_REFSEL_Msk						 (0x1L << OP_CFG_REFSEL_Pos)
#define OP_CFG_REFSEL          		   OP_CFG_REFSEL_Msk
/********************  Bit definition for OP_STS register  ********************/
#define OP_STS_OPCMP1IF_Pos         	(1U)
#define	OP_STS_OPCMP1IF_Msk						(0x1L << OP_STS_OPCMP1IF_Pos)
#define OP_STS_OPCMP1IF          			OP_STS_OPCMP1IF_Msk

#define OP_STS_OPCMP2IF_Pos         	(2U)
#define	OP_STS_OPCMP2IF_Msk						(0x1L << OP_STS_OPCMP2IF_Pos)
#define OP_STS_OPCMP2IF          			OP_STS_OPCMP2IF_Msk

#define OP_STS_OPCMP1STA_Pos         	(4U)
#define	OP_STS_OPCMP1STA_Msk					(0x1L << OP_STS_OPCMP1STA_Pos)
#define OP_STS_OPCMP1STA          		 OP_STS_OPCMP1STA_Msk

#define OP_STS_OPCMP2STA_Pos         	(5U)
#define	OP_STS_OPCMP2STA_Msk					(0x1L << OP_STS_OPCMP2STA_Pos)
#define OP_STS_OPCMP2STA          		 OP_STS_OPCMP2STA_Msk
/********************  Bit definition for OP_STS register  ********************/
#define OP_IDE_OPCMP1IE_Pos         	(1U)
#define	OP_IDE_OPCMP1IE_Msk						(0x1L << OP_IDE_OPCMP1IE_Pos)
#define OP_IDE_OPCMP1IE          			OP_IDE_OPCMP1IE_Msk

#define OP_IDE_OPCMP2IE_Pos         	(2U)
#define	OP_IDE_OPCMP2IE_Msk						(0x1L << OP_IDE_OPCMP2IE_Pos)
#define OP_IDE_OPCMP2IE          			OP_IDE_OPCMP2IE_Msk

#define OP_IDE_INTEN_Pos         	    (7U)
#define	OP_IDE_INTEN_Msk					    (0x1L << OP_IDE_INTEN_Pos)
#define OP_IDE_INTEN          		     OP_IDE_INTEN_Msk
/******************************************************************************/
/*                                                                            */
/*                                QEP          																*/
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for QEP_CON register  ********************/
#define QEP_CON_QSRC_Pos         	    (0U)
#define	QEP_CON_QSRC_Msk						  (0x3L << QEP_CON_QSRC_Pos)
#define QEP_CON_QSRC          			   QEP_CON_QSRC_Msk

#define QEP_CON_RPCEN_Pos         	  (2U)
#define	QEP_CON_RPCEN_Msk						  (0x1L << QEP_CON_RPCEN_Pos)
#define QEP_CON_RPCEN          			   QEP_CON_RPCEN_Msk

#define QEP_CON_FPCEN_Pos         	  (3U)
#define	QEP_CON_FPCEN_Msk						  (0x1L << QEP_CON_FPCEN_Pos)
#define QEP_CON_FPCEN          			   QEP_CON_FPCEN_Msk

#define QEP_CON_QAGATE_Pos         	  (4U)
#define	QEP_CON_QAGATE_Msk						(0x1L << QEP_CON_QAGATE_Pos)
#define QEP_CON_QAGATE          			 QEP_CON_QAGATE_Msk

#define QEP_CON_QBGATE_Pos         	  (5U)
#define	QEP_CON_QBGATE_Msk						(0x1L << QEP_CON_QBGATE_Pos)
#define QEP_CON_QBGATE          			 QEP_CON_QBGATE_Msk

#define QEP_CON_IGATE_Pos         	  (6U)
#define	QEP_CON_IGATE_Msk						  (0x1L << QEP_CON_IGATE_Pos)
#define QEP_CON_IGATE          			   QEP_CON_IGATE_Msk

#define QEP_CON_QEPEN_Pos         	  (7U)
#define	QEP_CON_QEPEN_Msk						  (0x1L << QEP_CON_QEPEN_Pos)
#define QEP_CON_QEPEN          			   QEP_CON_QEPEN_Msk

#define QEP_CON_QFDIV_Pos         	  (8U)
#define	QEP_CON_QFDIV_Msk						  (0x7L << QEP_CON_QFDIV_Pos)
#define QEP_CON_QFDIV          			   QEP_CON_QFDIV_Msk

#define QEP_CON_QAP_Pos         	    (12U)
#define	QEP_CON_QAP_Msk						    (0x1L << QEP_CON_QAP_Pos)
#define QEP_CON_QAP          			     QEP_CON_QAP_Msk

#define QEP_CON_QBP_Pos         	    (13U)
#define	QEP_CON_QBP_Msk						    (0x1L << QEP_CON_QBP_Pos)
#define QEP_CON_QBP          			     QEP_CON_QBP_Msk

#define QEP_CON_PCRM_Pos         	    (14U)
#define	QEP_CON_PCRM_Msk						  (0x1L << QEP_CON_PCRM_Pos)
#define QEP_CON_PCRM          			   QEP_CON_PCRM_Msk

#define QEP_CON_SWAP_Pos         	    (15U)
#define	QEP_CON_SWAP_Msk						  (0x1L << QEP_CON_SWAP_Pos)
#define QEP_CON_SWAP          			   QEP_CON_SWAP_Msk

#define QEP_CON_QIP_Pos         	    (16U)
#define	QEP_CON_QIP_Msk						   (0x1L << QEP_CON_QIP_Pos)
#define QEP_CON_QIP          			   QEP_CON_QIP_Msk

#define QEP_CON_SPOS_Pos         	    (21U)
#define	QEP_CON_SPOS_Msk						  (0x3L << QEP_CON_SPOS_Pos)
#define QEP_CON_SPOS          			   QEP_CON_SPOS_Msk
/********************  Bit definition for QEP_STS register  ********************/
#define QEP_STS_PCUIF_Pos         	  (0U)
#define	QEP_STS_PCUIF_Msk						  (0x1L << QEP_STS_PCUIF_Pos)
#define QEP_STS_PCUIF          			   QEP_STS_PCUIF_Msk

#define QEP_STS_PCOIF_Pos         	  (1U)
#define	QEP_STS_PCOIF_Msk						  (0x1L << QEP_STS_PCOIF_Pos)
#define QEP_STS_PCOIF          			   QEP_STS_PCOIF_Msk

#define QEP_STS_IERIF_Pos         	  (2U)
#define	QEP_STS_IERIF_Msk						  (0x1L << QEP_STS_IERIF_Pos)
#define QEP_STS_IERIF          			   QEP_STS_IERIF_Msk

#define QEP_STS_UPEVNTIF_Pos         	(3U)
#define	QEP_STS_UPEVNTIF_Msk					(0x1L << QEP_STS_UPEVNTIF_Pos)
#define QEP_STS_UPEVNTIF          		QEP_STS_UPEVNTIF_Msk

#define QEP_STS_DQIF_Pos         	   (4U)
#define	QEP_STS_DQIF_Msk					   (0x1L << QEP_STS_DQIF_Pos)
#define QEP_STS_DQIF          			 QEP_STS_DQIF_Msk
/********************  Bit definition for QEP_IDE register  ********************/
#define QEP_IDE_PCUIE_Pos         	  (0U)
#define	QEP_IDE_PCUIE_Msk						  (0x1L << QEP_IDE_PCUIE_Pos)
#define QEP_IDE_PCUIE          			   QEP_IDE_PCUIE_Msk

#define QEP_IDE_PCOIE_Pos         	  (1U)
#define	QEP_IDE_PCOIE_Msk						  (0x1L << QEP_IDE_PCOIE_Pos)
#define QEP_IDE_PCOIE          			   QEP_IDE_PCOIE_Msk

#define QEP_IDE_IERIE_Pos         	  (2U)
#define	QEP_IDE_IERIE_Msk						  (0x1L << QEP_IDE_IERIE_Pos)
#define QEP_IDE_IERIE          			   QEP_IDE_IERIE_Msk

#define QEP_IDE_UPEVNTIE_Pos         	(3U)
#define	QEP_IDE_UPEVNTIE_Msk					(0x1L << QEP_IDE_UPEVNTIE_Pos)
#define QEP_IDE_UPEVNTIE          		QEP_IDE_UPEVNTIE_Msk

#define QEP_IDE_INTEN_Pos         	  (7U)
#define	QEP_IDE_INTEN_Msk					    (0x1L << QEP_IDE_INTEN_Pos)
#define QEP_IDE_INTEN          			  QEP_IDE_INTEN_Msk

/********************  Bit definition for TS_CON register  ********************/
#define TS_CFG_CHOP_Pos         				      (0U)
#define	TS_CFG_CHOP_Msk									      (0x1L << TS_CFG_CHOP_Pos)
#define TS_CFG_CHOP          						      TS_CFG_CHOP_Msk

#define TS_CFG_EN_Pos       				         (7U)
#define TS_CFG_EN_Msk         				      (0x1L << TS_CFG_EN_Pos)
#define TS_CFG_EN          						TS_CFG_EN_Msk


/******************************************************************************/
/*                                                                            */
/*                      SPI0                 																*/
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for SPI0_CON register  ********************/
#define SPI0_CON_MSTR_Pos         					(0U)
#define	SPI0_CON_MSTR_Msk										(0x1L << SPI0_CON_MSTR_Pos)
#define SPI0_CON_MSTR          							SPI0_CON_MSTR_Msk

#define SPI0_CON_SPMD_Pos         					(1U)
#define	SPI0_CON_SPMD_Msk										(0x1L << SPI0_CON_SPMD_Pos)
#define SPI0_CON_SPMD          							SPI0_CON_SPMD_Msk

#define SPI0_CON_DORD_Pos         					(2U)
#define	SPI0_CON_DORD_Msk										(0x1L << SPI0_CON_DORD_Pos)
#define SPI0_CON_DORD          							SPI0_CON_DORD_Msk

#define SPI0_CON_CPHA_Pos         					(3U)
#define	SPI0_CON_CPHA_Msk										(0x1L << SPI0_CON_CPHA_Pos)
#define SPI0_CON_CPHA          							SPI0_CON_CPHA_Msk

#define SPI0_CON_CPOL_Pos         					(4U)
#define	SPI0_CON_CPOL_Msk										(0x1L << SPI0_CON_CPOL_Pos)
#define SPI0_CON_CPOL          							SPI0_CON_CPOL_Msk

#define SPI0_CON_SPEN_Pos         					(7U)
#define	SPI0_CON_SPEN_Msk										(0x1L << SPI0_CON_SPEN_Pos)
#define SPI0_CON_SPEN          							SPI0_CON_SPEN_Msk

#define SPI0_CON_SPR_Pos         						(8U)
#define	SPI0_CON_SPR_Msk										(0x0FL << SPI0_CON_SPR_Pos)
#define SPI0_CON_SPR          							SPI0_CON_SPR_Msk

#define SPI0_CON_SPOS_Pos         					(13U)
#define	SPI0_CON_SPOS_Msk										(0x1L << SPI0_CON_SPOS_Pos)
#define SPI0_CON_SPOS          							SPI0_CON_SPOS_Msk
/********************  Bit definition for SPI0_STS register  ********************/
#define SPI0_STS_SPIF_Pos         					(0U)
#define	SPI0_STS_SPIF_Msk										(0x1L << SPI0_STS_SPIF_Pos)
#define SPI0_STS_SPIF          							SPI0_STS_SPIF_Msk

#define SPI0_STS_RXNEIF_Pos         				(1U)
#define	SPI0_STS_RXNEIF_Msk									(0x1L << SPI0_STS_RXNEIF_Pos)
#define SPI0_STS_RXNEIF          						SPI0_STS_RXNEIF_Msk

#define SPI0_STS_TXEIF_Pos         					(2U)
#define	SPI0_STS_TXEIF_Msk									(0x1L << SPI0_STS_TXEIF_Pos)
#define SPI0_STS_TXEIF          						SPI0_STS_TXEIF_Msk

#define SPI0_STS_RXFIF_Pos         					(3U)
#define	SPI0_STS_RXFIF_Msk									(0x1L << SPI0_STS_RXFIF_Pos)
#define SPI0_STS_RXFIF          						SPI0_STS_RXFIF_Msk

#define SPI0_STS_RXHIF_Pos         					(4U)
#define	SPI0_STS_RXHIF_Msk									(0x1L << SPI0_STS_RXHIF_Pos)
#define SPI0_STS_RXHIF          						SPI0_STS_RXHIF_Msk

#define SPI0_STS_TXHIF_Pos         					(5U)
#define	SPI0_STS_TXHIF_Msk										(0x1L << SPI0_STS_TXHIF_Pos)
#define SPI0_STS_TXHIF          							SPI0_STS_TXHIF_Msk

#define SPI0_STS_WCOL_Pos         					(7U)
#define	SPI0_STS_WCOL_Msk										(0x1L << SPI0_STS_WCOL_Pos)
#define SPI0_STS_WCOL          							SPI0_STS_WCOL_Msk
/********************  Bit definition for SPI0_IDE register  ********************/
#define SPI0_IDE_INTEN_Pos         					(0U)
#define	SPI0_IDE_INTEN_Msk									(0x1L << SPI0_IDE_INTEN_Pos)
#define SPI0_IDE_INTEN         							SPI0_IDE_INTEN_Msk

#define SPI0_IDE_RXNEIE_Pos         				(1U)
#define	SPI0_IDE_RXNEIE_Msk									(0x1L << SPI0_IDE_RXNEIE_Pos)
#define SPI0_IDE_RXNEIE         						SPI0_IDE_RXNEIE_Msk

#define SPI0_IDE_TBIE_Pos         					(2U)
#define	SPI0_IDE_TBIE_Msk										(0x1L << SPI0_IDE_TBIE_Pos)
#define SPI0_IDE_TBIE        								SPI0_IDE_TBIE_Msk

#define SPI0_IDE_RXIE_Pos         					(3U)
#define	SPI0_IDE_RXIE_Msk										(0x1L << SPI0_IDE_RXIE_Pos)
#define SPI0_IDE_RXIE        								SPI0_IDE_RXIE_Msk

#define SPI0_IDE_RXHIE_Pos         					(4U)
#define	SPI0_IDE_RXHIE_Msk									(0x1L << SPI0_IDE_RXHIE_Pos)
#define SPI0_IDE_RXHIE        							SPI0_IDE_RXHIE_Msk

#define SPI0_IDE_TXHIE_Pos         					(5U)
#define	SPI0_IDE_TXHIE_Msk									(0x1L << SPI0_IDE_TXHIE_Pos)
#define SPI0_IDE_TXHIE        							SPI0_IDE_TXHIE_Msk

#define SPI0_IDE_RXDMAEN_Pos         				(6U)
#define	SPI0_IDE_RXDMAEN_Msk								(0x1L << SPI0_IDE_RXDMAEN_Pos)
#define SPI0_IDE_RXDMAEN        						SPI0_IDE_RXDMAEN_Msk

#define SPI0_IDE_TXDMAEN_Pos         				(7U)
#define	SPI0_IDE_TXDMAEN_Msk								(0x1L << SPI0_IDE_TXDMAEN_Pos)
#define SPI0_IDE_TXDMAEN        						SPI0_IDE_TXDMAEN_Msk
/******************************************************************************/
/*                                                                            */
/*                      SPI1                 																*/
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for SPI1_CON register  ********************/
#define TWI1_CON_STRETCH_Pos         					(0U)
#define	TWI1_CON_STRETCH_Msk									(0x1L << TWI1_CON_STRETCH_Pos)
#define TWI1_CON_STRETCH        							TWI1_CON_STRETCH_Msk

#define TWI1_CON_AA_Pos         					(1U)
#define	TWI1_CON_AA_Msk									(0x1L << TWI1_CON_AA_Pos)
#define TWI1_CON_AA       							TWI1_CON_AA_Msk

#define TWI1_CON_STOP_Pos         					(4U)
#define	TWI1_CON_STOP_Msk									(0x1L << TWI1_CON_STOP_Pos)
#define TWI1_CON_STOP       							TWI1_CON_STOP_Msk

#define TWI1_CON_START_Pos         					(5U)
#define	TWI1_CON_START_Msk									(0x1L << TWI1_CON_START_Pos)
#define TWI1_CON_START       							TWI1_CON_START_Msk

#define SPI1_TWI1_CON_QTWEN_Pos         				(7U)
#define	SPI1_TWI1_CON_QTWEN_Msk									(0x1L << SPI1_TWI1_CON_QTWEN_Pos)
#define SPI1_TWI1_CON_QTWEN       							SPI1_TWI1_CON_QTWEN_Msk

#define SPI1_TWI1_CON_QTWCK_Pos         				(8U)
#define	SPI1_TWI1_CON_QTWCK_Msk									(0xFL << SPI1_TWI1_CON_QTWCK_Pos)
#define SPI1_TWI1_CON_QTWCK       							SPI1_TWI1_CON_QTWCK_Msk

#define SPI1_TWI1_CON_SPOS_Pos         				(13U)
#define	SPI1_TWI1_CON_SPOS_Msk									(0x3L << SPI1_TWI1_CON_SPOS_Pos)
#define SPI1_TWI1_CON_SPOS       							SPI1_TWI1_CON_SPOS_Msk

#define SPI1_CON_MSTR_Pos         					(16U)
#define	SPI1_CON_MSTR_Msk										(0x1UL << SPI1_CON_MSTR_Pos)
#define SPI1_CON_MSTR          							SPI1_CON_MSTR_Msk

#define SPI1_CON_SPMD_Pos         					(17U)
#define	SPI1_CON_SPMD_Msk										(0x1L << SPI1_CON_SPMD_Pos)
#define SPI1_CON_SPMD          							SPI1_CON_SPMD_Msk

#define SPI1_CON_DORD_Pos         					(18U)
#define	SPI1_CON_DORD_Msk										(0x1L << SPI1_CON_DORD_Pos)
#define SPI1_CON_DORD          							SPI1_CON_DORD_Msk

#define SPI1_CON_CPHA_Pos         					(19U)
#define	SPI1_CON_CPHA_Msk										(0x1L << SPI1_CON_CPHA_Pos)
#define SPI1_CON_CPHA          							SPI1_CON_CPHA_Msk

#define SPI1_CON_CPOL_Pos         					(20U)
#define	SPI1_CON_CPOL_Msk										(0x1L << SPI1_CON_CPOL_Pos)
#define SPI1_CON_CPOL          							SPI1_CON_CPOL_Msk

#define SPI1_TWI1_CON_MODE_Pos         					  (22U)
#define	SPI1_TWI1_CON_MODE_Msk										(0x03L << SPI1_TWI1_CON_MODE_Pos)
#define SPI1_TWI1_CON_MODE          							SPI1_TWI1_CON_MODE_Msk


/********************  Bit definition for SPI1_STS register  ********************/
#define SPI1_TWI1_STS_QTWIF_Pos         				(0U)
#define	SPI1_TWI1_STS_QTWIF_Msk									(0x1L << SPI1_TWI1_STS_QTWIF_Pos)
#define SPI1_TWI1_STS_QTWIF        							SPI1_TWI1_STS_QTWIF_Msk

#define TWI1_STS_TXERXE_Pos         					(1U)
#define	TWI1_STS_TXERXE_Msk										(0x1L << TWI1_STS_TXERXE_Pos)
#define TWI1_STS_TXERXE         							TWI1_STS_TXERXE_Msk

#define TWI1_STS_GCA_Pos         					  (2U)
#define	TWI1_STS_GCA_Msk										(0x1L << TWI1_STS_GCA_Pos)
#define TWI1_STS_GCA         						  	TWI1_STS_GCA_Msk

#define TWI1_STS_TMSTR_Pos         					  (3U)
#define	TWI1_STS_TMSTR_Msk										(0x1L << TWI1_STS_TMSTR_Pos)
#define TWI1_STS_TMSTR         						  	TWI1_STS_TMSTR_Msk

#define SPI1_STS_TXEIF_Pos         					(6U)
#define	SPI1_STS_TXEIF_Msk									(0x1L << SPI1_STS_TXEIF_Pos)
#define SPI1_STS_TXEIF          						SPI1_STS_TXEIF_Msk

#define SPI1_STS_WCOL_Pos         					(7U)
#define	SPI1_STS_WCOL_Msk										(0x1L << SPI1_STS_WCOL_Pos)
#define SPI1_STS_WCOL           						SPI1_STS_WCOL_Msk

#define TWI1_STS_STATE_Pos         					(8U)
#define	TWI1_STS_STATE_Msk									(0x7L << TWI1_STS_STATE_Pos)
#define TWI1_STS_STATE           						TWI1_STS_STATE_Msk

#define TWI1_STS_NBYTES_Pos         					(16U)
#define	TWI1_STS_NBYTES_Msk										(0xFFL << TWI1_STS_NBYTES_Pos)
#define TWI1_STS_NBYTES           						TWI1_STS_NBYTES_Msk

/********************  Bit definition for SPI1_ADD register  ********************/
#define TWI1_ADD_GC_Pos         					  (0U)
#define	TWI1_ADD_GC_Msk									    (0x1L << TWI1_ADD_GC_Pos)
#define TWI1_ADD_GC         							  TWI1_ADD_GC_Msk

#define TWI1_ADD_QTWADD_Pos         				  (1U)
#define	TWI1_ADD_QTWADD_Msk									  (0x7FL << TWI1_ADD_QTWADD_Pos)
#define TWI1_ADD_QTWADD         							TWI1_ADD_QTWADD_Msk

/********************  Bit definition for SPI1_DATA register  ********************/
#define TWI1_DATA_QTWIDAT_Pos         					  (0U)
#define	TWI1_DATA_QTWIDAT_Msk									    (0xFFFFL << TWI1_DATA_QTWIDAT_Pos)
#define TWI1_DATA_QTWIDAT         						   	TWI1_DATA_QTWIDAT_Msk
/********************  Bit definition for SPI1_IDE register  ********************/
#define SPI1_TWI1_IDE_INTEN_Pos         					(0U)
#define	SPI1_TWI1_IDE_INTEN_Msk								    (0x1L << SPI1_TWI1_IDE_INTEN_Pos)
#define SPI1_TWI1_IDE_INTEN         						   SPI1_TWI1_IDE_INTEN_Msk

#define SPI1_IDE_TBIE_Pos         					(1U)
#define	SPI1_IDE_TBIE_Msk									  (0x1L << SPI1_IDE_TBIE_Pos)
#define SPI1_IDE_TBIE          						  SPI1_IDE_TBIE_Msk

#define SPI1_IDE_RXDMAEN_Pos         				(6U)
#define	SPI1_IDE_RXDMAEN_Msk								(0x1L <<  SPI1_IDE_RXDMAEN_Pos)
#define SPI1_IDE_RXDMAEN         						 SPI1_IDE_RXDMAEN_Msk

#define SPI1_IDE_TXDMAEN_Pos         				(7U)
#define	SPI1_IDE_TXDMAEN_Msk								(0x1L << SPI1_IDE_TXDMAEN_Pos)
#define SPI1_IDE_TXDMAEN         						SPI1_IDE_TXDMAEN_Msk
/******************************************************************************/
/*                                                                            */
/*                      TIM                																*/
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for TIM_CON register  ********************/
#define TIM_CON_CPRL_Pos         						(0U)
#define	TIM_CON_CPRL_Msk										(0x1L << TIM_CON_CPRL_Pos)
#define TIM_CON_CPRL         								TIM_CON_CPRL_Msk

#define TIM_CON_CTSEL_Pos         					(1U)
#define	TIM_CON_CTSEL_Msk										(0x1L << TIM_CON_CTSEL_Pos)
#define TIM_CON_CTSEL         							TIM_CON_CTSEL_Msk

#define TIM_CON_EXENR_Pos         					(2U)
#define	TIM_CON_EXENR_Msk										(0x1L << TIM_CON_EXENR_Pos)
#define TIM_CON_EXENR         							TIM_CON_EXENR_Msk

#define TIM_CON_EXENF_Pos         					(3U)
#define	TIM_CON_EXENF_Msk										(0x1L << TIM_CON_EXENF_Pos)
#define TIM_CON_EXENF         							TIM_CON_EXENF_Msk

#define TIM_CON_FSEL_Pos         						(4U)
#define	TIM_CON_FSEL_Msk										(0x1L << TIM_CON_FSEL_Pos)
#define TIM_CON_FSEL        								TIM_CON_FSEL_Msk

#define TIM_CON_EXENX_Pos         					(5U)
#define	TIM_CON_EXENX_Msk										(0x1L << TIM_CON_EXENX_Pos)
#define TIM_CON_EXENX        								TIM_CON_EXENX_Msk

#define TIM_CON_DEC_Pos         						(6U)
#define	TIM_CON_DEC_Msk											(0x1L << TIM_CON_DEC_Pos)
#define TIM_CON_DEC        									TIM_CON_DEC_Msk

#define TIM_CON_TR_Pos         							(7U)
#define	TIM_CON_TR_Msk											(0x1L << TIM_CON_TR_Pos)
#define TIM_CON_TR        									TIM_CON_TR_Msk

#define TIM_CON_TIMCLK_Pos         					(8U)
#define	TIM_CON_TIMCLK_Msk									(0x7L << TIM_CON_TIMCLK_Pos)
#define TIM_CON_TIMCLK         							TIM_CON_TIMCLK_Msk

#define TIM_CON_INVNB_Pos         					(11U)
#define	TIM_CON_INVNB_Msk										(0x1L << TIM_CON_INVNB_Pos)
#define TIM_CON_INVNB         							TIM_CON_INVNB_Msk

#define TIM_CON_INVNA_Pos         					(12U)
#define	TIM_CON_INVNA_Msk										(0x1L << TIM_CON_INVNA_Pos)
#define TIM_CON_INVNA         							TIM_CON_INVNA_Msk

#define TIM_CON_EPWMNB_Pos         					(13U)
#define	TIM_CON_EPWMNB_Msk									(0x1L << TIM_CON_EPWMNB_Pos)
#define TIM_CON_EPWMNB         							TIM_CON_EPWMNB_Msk

#define TIM_CON_EPWMNA_Pos         					(14U)
#define	TIM_CON_EPWMNA_Msk									(0x1L << TIM_CON_EPWMNA_Pos)
#define TIM_CON_EPWMNA         							TIM_CON_EPWMNA_Msk

#define TIM_CON_TXOE_Pos         						(15U)
#define	TIM_CON_TXOE_Msk										(0x1L << TIM_CON_TXOE_Pos)
#define TIM_CON_TXOE         								TIM_CON_TXOE_Msk

#define TIM_CON_SPOS_Pos         						(21U)
#define	TIM_CON_SPOS_Msk										(0x3L << TIM_CON_SPOS_Pos)
#define TIM_CON_SPOS         								TIM_CON_SPOS_Msk
/********************  Bit definition for TIM_STS register  ********************/
#define TIM_STS_TIF_Pos         						(0U)
#define	TIM_STS_TIF_Msk											(0x1L << TIM_STS_TIF_Pos)
#define TIM_STS_TIF         								TIM_STS_TIF_Msk

#define TIM_STS_EXIR_Pos         						(1U)
#define	TIM_STS_EXIR_Msk										(0x1L << TIM_STS_EXIR_Pos)
#define TIM_STS_EXIR         								TIM_STS_EXIR_Msk

#define TIM_STS_EXIF_Pos         						(2U)
#define	TIM_STS_EXIF_Msk										(0x1L << TIM_STS_EXIF_Pos)
#define TIM_STS_EXIF        								TIM_STS_EXIF_Msk
/********************  Bit definition for TIM_IDE register  ********************/
#define TIM_IDE_INTEN_Pos         					(0U)
#define	TIM_IDE_INTEN_Msk										(0x1L << TIM_IDE_INTEN_Pos)
#define TIM_IDE_INTEN         							TIM_IDE_INTEN_Msk

#define TIM_IDE_TIE_Pos         						(1U)
#define	TIM_IDE_TIE_Msk											(0x1L << TIM_IDE_TIE_Pos)
#define TIM_IDE_TIE         								TIM_IDE_TIE_Msk

#define TIM_IDE_EXIRE_Pos         					(2U)
#define	TIM_IDE_EXIRE_Msk										(0x1L << TIM_IDE_EXIRE_Pos)
#define TIM_IDE_EXIRE         							TIM_IDE_EXIRE_Msk

#define TIM_IDE_EXIFE_Pos         					(3U)
#define	TIM_IDE_EXIFE_Msk										(0x1L << TIM_IDE_EXIFE_Pos)
#define TIM_IDE_EXIFE         							TIM_IDE_EXIFE_Msk

#define TIM_IDE_TIDE_Pos         						(4U)
#define	TIM_IDE_TIDE_Msk										(0x1L << TIM_IDE_TIDE_Pos)
#define TIM_IDE_TIDE         								TIM_IDE_TIDE_Msk

#define TIM_IDE_CAPRDE_Pos         					(5)
#define	TIM_IDE_CAPRDE_Msk									(0x1L << TIM_IDE_CAPRDE_Pos)
#define TIM_IDE_CAPRDE        							TIM_IDE_CAPRDE_Msk

#define TIM_IDE_CAPFDE_Pos         					(6U)
#define	TIM_IDE_CAPFDE_Msk									(0x1L << TIM_IDE_CAPFDE_Pos)
#define TIM_IDE_CAPFDE        							TIM_IDE_CAPFDE_Msk
/******************************************************************************/
/*                                                                            */
/*                      DAC_VREF              						      							*/
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DAC_CFG register  ********************/
#define DAC_CFG_DACEN_Pos         						(0U)
#define	DAC_CFG_DACEN_Msk										  (0x1L << DAC_CFG_DACEN_Pos)
#define DAC_CFG_DACEN         								DAC_CFG_DACEN_Msk

#define DAC_CFG_OUT0EN_Pos         						(1U)
#define	DAC_CFG_OUT0EN_Msk										(0x1L << DAC_CFG_OUT0EN_Pos)
#define DAC_CFG_OUT0EN         								DAC_CFG_OUT0EN_Msk

#define DAC_CFG_OUT1EN_Pos         						(2U)
#define	DAC_CFG_OUT1EN_Msk										(0x1L << DAC_CFG_OUT1EN_Pos)
#define DAC_CFG_OUT1EN         								DAC_CFG_OUT1EN_Msk

#define DAC_CFG_REFSEL_Pos         						(3U)
#define	DAC_CFG_REFSEL_Msk										(0x1L << DAC_CFG_REFSEL_Pos)
#define DAC_CFG_REFSEL         								DAC_CFG_REFSEL_Msk

/********************  Bit definition for DAC_STS register  ********************/
#define DAC_STS_OVFIF_Pos         						(0U)
#define	DAC_CFG_OVFIF_Msk										  (0x1L << DAC_STS_OVFIF_Pos)
#define DAC_STS_OVFIF         								DAC_CFG_OVFIF_Msk

/********************  Bit definition for VREF_CFG register  ********************/
#define VREF_CFG_VREFCFG0_Pos         				(0U)
#define	VREF_CFG_VREFCFG0_Msk									(0x1L << VREF_CFG_VREFCFG0_Pos)
#define VREF_CFG_VREFCFG0         						VREF_CFG_VREFCFG0_Msk

#define VREF_CFG_VREFCFG1_Pos         				(1U)
#define	VREF_CFG_VREFCFG1_Msk									(0x1L << VREF_CFG_VREFCFG1_Pos)
#define VREF_CFG_VREFCFG1         						VREF_CFG_VREFCFG1_Msk

#define VREF_CFG_VREFS_Pos         						(2U)
#define	VREF_CFG_VREFS_Msk										(0x3L << VREF_CFG_VREFS_Pos)
#define VREF_CFG_VREFS         								VREF_CFG_VREFS_Msk

#define VREF_CFG_VMIDEN_Pos         					(5U)
#define	VREF_CFG_VMIDEN_Msk										(0x1L << VREF_CFG_VMIDEN_Pos)
#define VREF_CFG_VMIDEN         							VREF_CFG_VMIDEN_Msk

#define VREF_CFG_DIVEN_Pos         					(6U)
#define	VREF_CFG_DIVEN_Msk										(0x1L << VREF_CFG_DIVEN_Pos)
#define VREF_CFG_DIVEN         							VREF_CFG_DIVEN_Msk
/******************************************************************************/
/*                                                                            */
/*                      TWI               																*/
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for TWI_CON register  ********************/
#define TWI_CON_STRETCH_Pos         					(0U)
#define	TWI_CON_STRETCH_Msk										(0x1L << TWI_CON_STRETCH_Pos)
#define TWI_CON_STRETCH         							TWI_CON_STRETCH_Msk

#define TWI_CON_AA_Pos         								(1U)
#define	TWI_CON_AA_Msk												(0x1L << TWI_CON_AA_Pos)
#define TWI_CON_AA         										TWI_CON_AA_Msk

#define TWI_CON_STO_Pos         							(4U)
#define	TWI_CON_STO_Msk												(0x1L << TWI_CON_STO_Pos)
#define TWI_CON_STO         									TWI_CON_STO_Msk

#define TWI_CON_STA_Pos         							(5U)
#define	TWI_CON_STA_Msk												(0x1L << TWI_CON_STA_Pos)
#define TWI_CON_STA         									TWI_CON_STA_Msk

#define TWI_CON_TWEN_Pos         							(7U)
#define	TWI_CON_TWEN_Msk											(0x1L << TWI_CON_TWEN_Pos)
#define TWI_CON_TWEN         									TWI_CON_TWEN_Msk

#define TWI_CON_TWCK_Pos         							(8U)
#define	TWI_CON_TWCK_Msk											(0x0FL << TWI_CON_TWCK_Pos)
#define TWI_CON_TWCK         									TWI_CON_TWCK_Msk

#define TWI_CON_SPOS_Pos         							(13U)
#define	TWI_CON_SPOS_Msk											(0x1L << TWI_CON_SPOS_Pos)
#define TWI_CON_SPOS         									TWI_CON_SPOS_Msk
/********************  Bit definition for TWI_STS register  ********************/
#define TWI_STS_TWIF_Pos         							(0U)
#define	TWI_STS_TWIF_Msk											(0x1L << TWI_STS_TWIF_Pos)
#define TWI_STS_TWIF         									TWI_STS_TWIF_Msk

#define TWI_STS_TXERXE_Pos         						(1U)
#define	TWI_STS_TXERXE_Msk										(0x1L << TWI_STS_TXERXE_Pos)
#define TWI_STS_TXERXE         								TWI_STS_TXERXE_Msk

#define TWI_STS_GCA_Pos         							(2U)
#define	TWI_STS_GCA_Msk												(0x1L << TWI_STS_GCA_Pos)
#define TWI_STS_GCA         									TWI_STS_GCA_Msk

#define TWI_STS_MSTR_Pos         							(3U)
#define	TWI_STS_MSTR_Msk											(0x1L << TWI_STS_MSTR_Pos)
#define TWI_STS_MSTR         									TWI_STS_MSTR_Msk

#define TWI_STS_STATE_Pos         						(8U)
#define	TWI_STS_STATE_Msk											(0x7L << TWI_STS_STATE_Pos)
#define TWI_STS_STATE         								TWI_STS_STATE_Msk

#define TWI_STS_NBYTES_Pos         						(16U)
#define	TWI_STS_NBYTES_Msk										(0xFFL << TWI_STS_NBYTES_Pos)
#define TWI_STS_NBYTES         								TWI_STS_NBYTES_Msk

/********************  Bit definition for TWI_STS register  ********************/
#define TWI_ADD_GC_Pos         							(0U)
#define	TWI_ADD_GC_Msk											(0x1L << TWI_ADD_GC_Pos)
#define TWI_ADD_GC         									TWI_ADD_GC_Msk

#define TWI_ADD_TWA_Pos         						(1U)
#define	TWI_ADD_TWA_Msk										(0x7FL << TWI_ADD_TWA_Pos)
#define TWI_ADD_TWA         								TWI_ADD_TWA_Msk


/********************  Bit definition for TWI_IDE register  ********************/
#define TWI_IDE_INTEN_Pos         						(0U)
#define	TWI_IDE_INTEN_Msk											(0x1L << TWI_IDE_INTEN_Pos)
#define TWI_IDE_INTEN         								TWI_IDE_INTEN_Msk

#define TWI_IDE_RXDMAEN_Pos         					(6U)
#define	TWI_IDE_RXDMAEN_Msk										(0x1L << TWI_IDE_RXDMAEN_Pos)
#define TWI_IDE_RXDMAEN         							TWI_IDE_RXDMAEN_Msk

#define TWI_IDE_TXDMAEN_Pos         					(7U)
#define	TWI_IDE_TXDMAEN_Msk										(0x1L << TWI_IDE_TXDMAEN_Pos)
#define TWI_IDE_TXDMAEN        								TWI_IDE_TXDMAEN_Msk

/******************************************************************************/
/*                                                                            */
/*                      UART               																*/
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for UART_CON register  ********************/
#define UART_CON_SM01_Pos         				   (0U)
#define	UART_CON_SM01_Msk							       (0x3L << UART_CON_SM01_Pos)
#define UART_CON_SM01         						   UART_CON_SM01_Msk

#define UART_CON_SM2_Pos         					   (2U)
#define	UART_CON_SM2_Msk							       (0x1L << UART_CON_SM2_Pos)
#define UART_CON_SM2         						     UART_CON_SM2_Msk

#define UART_CON_PERSCALER_Pos         			 (4U)
#define	UART_CON_PERSCALER_Msk						   (0x1L << UART_CON_PERSCALER_Pos)
#define UART_CON_PERSCALER         					 UART_CON_PERSCALER_Msk

#define UART_CON_RXEN_Pos         					 (6U)
#define	UART_CON_RXEN_Msk							       (0x1L << UART_CON_RXEN_Pos)
#define UART_CON_RXEN         					    	UART_CON_RXEN_Msk

#define UART_CON_TXEN_Pos         					(7U)
#define	UART_CON_TXEN_Msk							(0x1L << UART_CON_TXEN_Pos)
#define UART_CON_TXEN         						UART_CON_TXEN_Msk

#define UART_CON_FUNCSEL_Pos         				(8U)
#define	UART_CON_FUNCSEL_Msk						(0x1L << UART_CON_FUNCSEL_Pos)
#define UART_CON_FUNCSEL        					UART_CON_FUNCSEL_Msk

#define UART_CON_SPOS_Pos         					(14U)
#define	UART_CON_SPOS_Msk							(0x3L << UART_CON_SPOS_Pos)
#define UART_CON_SPOS         						UART_CON_SPOS_Msk

#define UART_CON_SLVEN_Pos         					(16U)
#define	UART_CON_SLVEN_Msk							(0x1L << UART_CON_SLVEN_Pos)
#define UART_CON_SLVEN         						UART_CON_SLVEN_Msk

#define UART_CON_SLVAREN_Pos         				(17U)
#define	UART_CON_SLVAREN_Msk						(0x1L << UART_CON_SLVAREN_Pos)
#define UART_CON_SLVAREN         					UART_CON_SLVAREN_Msk

#define UART_CON_LBDL_Pos							(18U)
#define	UART_CON_LBDL_Msk							(0x1L << UART_CON_LBDL_Pos)
#define UART_CON_LBDL         						UART_CON_LBDL_Msk

#define UART_CON_BKTR_Pos							(24U)
#define	UART_CON_BKTR_Msk							(0x1L << UART_CON_BKTR_Pos)
#define UART_CON_BKTR         						UART_CON_BKTR_Msk

#define UART_CON_BKSIZE_Pos							(26U)
#define	UART_CON_BKSIZE_Msk							(0x1L << UART_CON_BKSIZE_Pos)
#define UART_CON_BKSIZE         					UART_CON_BKSIZE_Msk

/********************  Bit definition for UART_STS register  ********************/
#define UART_STS_RXIF_Pos         					(0U)
#define	UART_STS_RXIF_Msk							 (0x1L << UART_STS_RXIF_Pos)
#define UART_STS_RXIF         						UART_STS_RXIF_Msk

#define UART_STS_TXIF_Pos         					(1U)
#define	UART_STS_TXIF_Msk							(0x1L << UART_STS_TXIF_Pos)
#define UART_STS_TXIF         						UART_STS_TXIF_Msk

#define UART_STS_WKIF_Pos         					(4U)
#define	UART_STS_WKIF_Msk							(0x1L << UART_STS_WKIF_Pos)
#define UART_STS_WKIF         						UART_STS_WKIF_Msk

#define UART_STS_BKIF_Pos         			(8U)
#define	UART_STS_BKIF_Msk							(0x1L << UART_STS_BKIF_Pos)
#define UART_STS_BKIF         						UART_STS_BKIF_Msk

#define UART_STS_SLVHEIF_Pos         		(9U)
#define	UART_STS_SLVHEIF_Msk						(0x1L << UART_STS_SLVHEIF_Pos)
#define UART_STS_SLVHEIF         					UART_STS_SLVHEIF_Msk

#define UART_STS_SLVSYNIF_Pos         	(10U)
#define	UART_STS_SLVSYNIF_Msk						(0x1L << UART_STS_SLVSYNIF_Pos)
#define UART_STS_SLVSYNIF         		  UART_STS_SLVSYNIF_Msk

#define UART_STS_SYNCIF_Pos         	(11U)
#define	UART_STS_SYNCIF_Msk						(0x1L << UART_STS_SYNCIF_Pos)
#define UART_STS_SYNCIF         			UART_STS_SYNCIF_Msk
/********************  Bit definition for UART_IDE register  ********************/
#define UART_IDE_INTEN_Pos            (0U)
#define	UART_IDE_INTEN_Msk            (0x1L << UART_IDE_INTEN_Pos)
#define UART_IDE_INTEN                UART_IDE_INTEN_Msk

#define UART_IDE_RXIE_Pos              (1U)
#define	UART_IDE_RXIE_Msk							 (0x1L << UART_IDE_RXIE_Pos)
#define UART_IDE_RXIE         				 UART_IDE_RXIE_Msk

#define UART_IDE_TXIE_Pos             (2U)
#define	UART_IDE_TXIE_Msk							(0x1L << UART_IDE_TXIE_Pos)
#define UART_IDE_TXIE                 UART_IDE_TXIE_Msk

#define UART_IDE_WKIE_Pos             (4U)
#define	UART_IDE_WKIE_Msk							(0x1L << UART_IDE_WKIE_Pos)
#define UART_IDE_WKIE                 UART_IDE_WKIE_Msk

#define UART_IDE_RXDMAEN_Pos          (6U)
#define	UART_IDE_RXDMAEN_Msk          (0x1L << UART_IDE_RXDMAEN_Pos)
#define UART_IDE_RXDMAEN              UART_IDE_RXDMAEN_Msk

#define UART_IDE_TXDMAEN_Pos         				(7U)
#define	UART_IDE_TXDMAEN_Msk						(0x1L << UART_IDE_TXDMAEN_Pos)
#define UART_IDE_TXDMAEN         					UART_IDE_TXDMAEN_Msk

#define UART_IDE_BKIE_Pos         					(8U)
#define	UART_IDE_BKIE_Msk							(0x1L << UART_IDE_BKIE_Pos)
#define UART_IDE_BKIE         						UART_IDE_BKIE_Msk

#define UART_IDE_SLVHEIE_Pos         				(9U)
#define	UART_IDE_SLVHEIE_Msk						(0x1L << UART_IDE_SLVHEIE_Pos)
#define UART_IDE_SLVHEIE         					UART_IDE_SLVHEIE_Msk

#define UART_IDE_SYNCIE_Pos         				(11U)
#define	UART_IDE_SYNCIE_Msk						(0x1L << UART_IDE_SYNCIE_Pos)
#define UART_IDE_SYNCIE         					UART_IDE_SYNCIE_Msk

/******************************************************************************/
/*                                                                            */
/*                      WDT               																		*/
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for WDT_CON register  ********************/
#define WDT_CON_CLRWDT_Pos         					(0U)
#define	WDT_CON_CLRWDT_Msk									(0x1L << WDT_CON_CLRWDT_Pos)
#define WDT_CON_CLRWDT         							WDT_CON_CLRWDT_Msk

/********************  Bit definition for WDT_CFG register  ********************/
#define WDT_CFG_WDTCKS_Pos         					(0U)
#define	WDT_CFG_WDTCKS_Msk									(0x7L << WDT_CFG_WDTCKS_Pos)
#define WDT_CFG_WDTCKS         							WDT_CFG_WDTCKS_Msk


/******************************************************************************/
/*                                                                            */
/*                      CAN               																		*/
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for CAN_RX_ID register  ********************/
#define CAN_RX_ID_SdID_Pos            (0U)
#define	CAN_RX_ID_SdID_Msk            (0x7FFL << CAN_RX_ID_SdID_Pos)
#define CAN_RX_ID_SdID                 CAN_RX_ID_SdID_Msk

#define CAN_RX_ID_ExID_Pos            (0U)
#define	CAN_RX_ID_ExID_Msk            (0x1FFFFFFFL << CAN_RX_ID_ExID_Pos)
#define CAN_RX_ID_ExID                 CAN_RX_ID_ExID_Msk

/********************  Bit definition for CAN_RX_CTRL register  ********************/
#define CAN_RX_CTRL_DLC_Pos            (0U)
#define	CAN_RX_CTRL_DLC_Msk            (0xFL << CAN_RX_CTRL_DLC_Pos)
#define CAN_RX_CTRL_DLC                 CAN_RX_CTRL_DLC_Msk

#define CAN_RX_CTRL_BRS_Pos             (4U)
#define	CAN_RX_CTRL_BRS_Msk             (0x1L << CAN_RX_CTRL_BRS_Pos)
#define CAN_RX_CTRL_BRS                  CAN_RX_CTRL_BRS_Msk

#define CAN_RX_CTRL_FDF_Pos             (5U)
#define	CAN_RX_CTRL_FDF_Msk             (0x1L << CAN_RX_CTRL_FDF_Pos)
#define CAN_RX_CTRL_FDF                  CAN_RX_CTRL_FDF_Msk

#define CAN_RX_CTRL_RTR_Pos             (6U)
#define	CAN_RX_CTRL_RTR_Msk							(0x1L << CAN_RX_CTRL_RTR_Pos)
#define CAN_RX_CTRL_RTR                  CAN_RX_CTRL_RTR_Msk

#define CAN_RX_CTRL_IDE_Pos             (7U)
#define	CAN_RX_CTRL_IDE_Msk							(0x1L << CAN_RX_CTRL_IDE_Pos)
#define CAN_RX_CTRL_IDE                  CAN_RX_CTRL_IDE_Msk

#define CAN_RX_CTRL_TX_Pos              (12U)
#define	CAN_RX_CTRL_TX_Msk							(0x1L << CAN_RX_CTRL_TX_Pos)
#define CAN_RX_CTRL_TX                   CAN_RX_CTRL_TX_Msk

#define CAN_RX_CTRL_KOER_Pos            (13U)
#define	CAN_RX_CTRL_KOER_Msk            (0x1L << CAN_RX_CTRL_KOER_Pos)
#define CAN_RX_CTRL_KOER                 CAN_RX_CTRL_KOER_Msk

#define CAN_RX_CTRL_CYCLE_TIME_Pos      (16U)
#define	CAN_RX_CTRL_CYCLE_TIME_Msk      (0xFFFFL << CAN_RX_CTRL_CYCLE_TIME_Pos)
#define CAN_RX_CTRL_CYCLE_TIME           CAN_RX_CTRL_CYCLE_TIME_Msk

/********************  Bit definition for CAN_RBUF register  ********************/
#define CAN_RBUF_D1_Pos                 (0U)
#define	CAN_RBUF_D1_Msk                 (0xFFL << CAN_RBUF_D1_Pos)
#define CAN_RBUF_D1                      CAN_RBUF_D1_Msk

#define CAN_RBUF_D2_Pos                 (8U)
#define	CAN_RBUF_D2_Msk                 (0xFFL << CAN_RBUF_D2_Pos)
#define CAN_RBUF_D2                      CAN_RBUF_D2_Msk

#define CAN_RBUF_D3_Pos                 (16U)
#define	CAN_RBUF_D3_Msk                 (0xFFL << CAN_RBUF_D3_Pos)
#define CAN_RBUF_D3                      CAN_RBUF_D3_Msk

#define CAN_RBUF_D4_Pos                 (24U)
#define	CAN_RBUF_D4_Msk                 (0xFFL << CAN_RBUF_D4_Pos)
#define CAN_RBUF_D4                      CAN_RBUF_D4_Msk

/********************  Bit definition for CAN_RTSL register  ********************/
#define CAN_RTSL_RTS_Pos               (0U)
#define	CAN_RTSL_RTS_Msk               (0xFFFFFFFFL << CAN_RTSL_RTS_Pos)
#define CAN_RTSL_RTS                    CAN_RTSL_RTS_Msk

/********************  Bit definition for CAN_RTSH register  ********************/
#define CAN_RTSH_RTS_Pos               (0U)
#define	CAN_RTSH_RTS_Msk               (0xFFFFFFFFL << CAN_RTSH_RTS_Pos)
#define CAN_RTSH_RTS                    CAN_RTSH_RTS_Msk

/********************  Bit definition for CAN_TX_ID register  ********************/
#define CAN_TX_ID_SdID_Pos             (0U)
#define	CAN_TX_ID_SdID_Msk             (0x7FFL << CAN_TX_ID_SdID_Pos)
#define CAN_TX_ID_SdID                  CAN_TX_ID_SdID_Msk

#define CAN_TX_ID_ExID_Pos             (0U)
#define	CAN_TX_ID_ExID_Msk             (0x1FFFFFFFL << CAN_TX_ID_ExID_Pos)
#define CAN_TX_ID_ExID                  CAN_TX_ID_ExID_Msk

#define CAN_TX_ID_TTSEN_Pos            (31U)
#define CAN_TX_ID_TTSEN_Msk            (0x1L) << CAN_TX_ID_TTSEN_Pos
#define CAN_TX_ID_TTSEN                 CAN_TX_ID_TTSEN_Msk

/********************  Bit definition for CAN_TX_CTRL register  ********************/
#define CAN_TX_CTRL_DLC_Pos            (0U)
#define	CAN_TX_CTRL_DLC_Msk            (0xFL << CAN_TX_CTRL_DLC_Pos)
#define CAN_TX_CTRL_DLC                 CAN_TX_CTRL_DLC_Msk

#define CAN_TX_CTRL_BRS_Pos         				(4U)
#define	CAN_TX_CTRL_BRS_Msk									(0x1L << CAN_TX_CTRL_BRS_Pos)
#define CAN_TX_CTRL_BRS        							CAN_TX_CTRL_BRS_Msk

#define CAN_TX_CTRL_FDF_Pos         				(5U)
#define	CAN_TX_CTRL_FDF_Msk									(0x1L << CAN_TX_CTRL_FDF_Pos)
#define CAN_TX_CTRL_FDF        							CAN_TX_CTRL_FDF_Msk

#define CAN_TX_CTRL_RTR_Pos         				(6U)
#define	CAN_TX_CTRL_RTR_Msk									(0x1L << CAN_TX_CTRL_RTR_Pos)
#define CAN_TX_CTRL_RTR        							CAN_TX_CTRL_RTR_Msk

#define CAN_TX_CTRL_IDE_Pos         				(7U)
#define	CAN_TX_CTRL_IDE_Msk									(0x1L << CAN_TX_CTRL_IDE_Pos)
#define CAN_TX_CTRL_IDE        							CAN_TX_CTRL_IDE_Msk

/********************  Bit definition for CAN_TBUF register  ********************/
#define CAN_TBUF_D1_Pos         			    	(0U)
#define	CAN_TBUF_D1_Msk								   	  (0xFFL << CAN_TBUF_D1_Pos)
#define CAN_TBUF_D1        						    	CAN_TBUF_D1_Msk

#define CAN_TBUF_D2_Pos         			    	(8U)
#define	CAN_TBUF_D2_Msk								  	  (0xFFL << CAN_TBUF_D2_Pos)
#define CAN_TBUF_D2        						    	CAN_TBUF_D2_Msk

#define CAN_TBUF_D3_Pos         			    	(16U)
#define	CAN_TBUF_D3_Msk								  	  (0xFFL << CAN_TBUF_D3_Pos)
#define CAN_TBUF_D3        						    	CAN_TBUF_D3_Msk

#define CAN_TBUF_D4_Pos         			    	(24U)
#define	CAN_TBUF_D4_Msk								  	  (0xFFL << CAN_TBUF_D4_Pos)
#define CAN_TBUF_D4        						    	CAN_TBUF_D4_Msk

/********************  Bit definition for CAN_TTSL register  ********************/
#define CAN_TTSL_RTS_Pos         			    	(0U)
#define	CAN_TTSL_RTS_Msk								    (0xFFFFFFFFL << CAN_TTSL_RTS_Pos)
#define CAN_TTSL_RTS       						    	CAN_TTSL_RTS_Msk

/********************  Bit definition for CAN_TTSH register  ********************/
#define CAN_TTSH_RTS_Pos         			    	(0U)
#define	CAN_TTSH_RTS_Msk								    (0xFFFFFFFFL << CAN_TTSH_RTS_Pos)
#define CAN_TTSH_RTS       						    	CAN_TTSH_RTS_Msk

/********************  Bit definition for CAN_CFG_STAT register  ********************/
#define CAN_CFG_STAT_BUSOFF_Pos         		(0U)
#define	CAN_CFG_STAT_BUSOFF_Msk						  (0x1L << CAN_CFG_STAT_BUSOFF_Pos)
#define CAN_CFG_STAT_BUSOFF       					CAN_CFG_STAT_BUSOFF_Msk

#define CAN_CFG_STAT_TACTIVE_Pos         		(1U)
#define	CAN_CFG_STAT_TACTIVE_Msk						(0x1L << CAN_CFG_STAT_TACTIVE_Pos)
#define CAN_CFG_STAT_TACTIVE       					CAN_CFG_STAT_TACTIVE_Msk

#define CAN_CFG_STAT_RACTIVE_Pos         		(2U)
#define	CAN_CFG_STAT_RACTIVE_Msk						(0x1L << CAN_CFG_STAT_RACTIVE_Pos)
#define CAN_CFG_STAT_RACTIVE       					CAN_CFG_STAT_RACTIVE_Msk

#define CAN_CFG_STAT_TSSS_Pos         		  (3U)
#define	CAN_CFG_STAT_TSSS_Msk				    		(0x1L << CAN_CFG_STAT_TSSS_Pos)
#define CAN_CFG_STAT_TSSS       		   			CAN_CFG_STAT_TSSS_Msk

#define CAN_CFG_STAT_TPSS_Pos         		  (4U)
#define	CAN_CFG_STAT_TPSS_Msk				    		(0x1L << CAN_CFG_STAT_TPSS_Pos)
#define CAN_CFG_STAT_TPSS       		   			CAN_CFG_STAT_TPSS_Msk

#define CAN_CFG_STAT_TPSS_Pos         		  (4U)
#define	CAN_CFG_STAT_TPSS_Msk				    		(0x1L << CAN_CFG_STAT_TPSS_Pos)
#define CAN_CFG_STAT_TPSS       		   			CAN_CFG_STAT_TPSS_Msk

#define CAN_CFG_STAT_LBMI_Pos         		  (5U)
#define	CAN_CFG_STAT_LBMI_Msk				    		(0x1L << CAN_CFG_STAT_LBMI_Pos)
#define CAN_CFG_STAT_LBMI       		   			CAN_CFG_STAT_LBMI_Msk

#define CAN_CFG_STAT_LBME_Pos         		  (6U)
#define	CAN_CFG_STAT_LBME_Msk				    		(0x1L << CAN_CFG_STAT_LBME_Pos)
#define CAN_CFG_STAT_LBME       		   			CAN_CFG_STAT_LBME_Msk

#define CAN_CFG_STAT_RESET_Pos         		  (7U)
#define	CAN_CFG_STAT_RESET_Msk				    	(0x1L << CAN_CFG_STAT_RESET_Pos)
#define CAN_CFG_STAT_RESET       		   			CAN_CFG_STAT_RESET_Msk

#define CAN_CFG_STAT_TSA_Pos         		    (8U)
#define	CAN_CFG_STAT_TSA_Msk				      	(0x1L << CAN_CFG_STAT_TSA_Pos)
#define CAN_CFG_STAT_TSA       		   		  	CAN_CFG_STAT_TSA_Msk

#define CAN_CFG_STAT_TSALL_Pos         		  (9U)
#define	CAN_CFG_STAT_TSALL_Msk				    	(0x1L << CAN_CFG_STAT_TSALL_Pos)
#define CAN_CFG_STAT_TSALL       		   		 	CAN_CFG_STAT_TSALL_Msk

#define CAN_CFG_STAT_TSONE_Pos         		  (10U)
#define	CAN_CFG_STAT_TSONE_Msk				    	(0x1L << CAN_CFG_STAT_TSONE_Pos)
#define CAN_CFG_STAT_TSONE       		   		 	CAN_CFG_STAT_TSONE_Msk

#define CAN_CFG_STAT_TPA_Pos         		    (11U)
#define	CAN_CFG_STAT_TPA_Msk				      	(0x1L << CAN_CFG_STAT_TPA_Pos)
#define CAN_CFG_STAT_TPA       		   		  	CAN_CFG_STAT_TPA_Msk

#define CAN_CFG_STAT_TPE_Pos         		    (12U)
#define	CAN_CFG_STAT_TPE_Msk				      	(0x1L << CAN_CFG_STAT_TPE_Pos)
#define CAN_CFG_STAT_TPE       		   		  	CAN_CFG_STAT_TPE_Msk

#define CAN_CFG_STAT_STBY_Pos         		  (13U)
#define	CAN_CFG_STAT_STBY_Msk				      	(0x1L << CAN_CFG_STAT_STBY_Pos)
#define CAN_CFG_STAT_STBY       		   		 	CAN_CFG_STAT_STBY_Msk

#define CAN_CFG_STAT_LOM_Pos         		    (14U)
#define	CAN_CFG_STAT_LOM_Msk				      	(0x1L << CAN_CFG_STAT_LOM_Pos)
#define CAN_CFG_STAT_LOM       		   		  	CAN_CFG_STAT_LOM_Msk

#define CAN_CFG_STAT_TBSEL_Pos         		  (15U)
#define	CAN_CFG_STAT_TBSEL_Msk				     	(0x1L << CAN_CFG_STAT_TBSEL_Pos)
#define CAN_CFG_STAT_TBSEL       		   	  	CAN_CFG_STAT_TBSEL_Msk

#define CAN_CFG_STAT_TSSTAT_Pos         	  (16U)
#define	CAN_CFG_STAT_TSSTAT_Msk				     	(0x3L << CAN_CFG_STAT_TSSTAT_Pos)
#define CAN_CFG_STAT_TSSTAT       		   	  CAN_CFG_STAT_TSSTAT_Msk

#define CAN_CFG_STAT_TTTBM_Pos         	    (20U)
#define	CAN_CFG_STAT_TTTBM_Msk				     	(0x1L << CAN_CFG_STAT_TTTBM_Pos)
#define CAN_CFG_STAT_TTTBM      		   	    CAN_CFG_STAT_TTTBM_Msk

#define CAN_CFG_STAT_TSMODE_Pos         	  (21U)
#define	CAN_CFG_STAT_TSMODE_Msk				     	(0x1L << CAN_CFG_STAT_TSMODE_Pos)
#define CAN_CFG_STAT_TSMODE      		   	    CAN_CFG_STAT_TSMODE_Msk

#define CAN_CFG_STAT_TSNEXT_Pos         	  (22U)
#define	CAN_CFG_STAT_TSNEXT_Msk				     	(0x1L << CAN_CFG_STAT_TSNEXT_Pos)
#define CAN_CFG_STAT_TSNEXT      		   	    CAN_CFG_STAT_TSNEXT_Msk

#define CAN_CFG_STAT_FD_ISO_Pos         	  (23U)
#define	CAN_CFG_STAT_FD_ISO_Msk				     	(0x1L << CAN_CFG_STAT_FD_ISO_Pos)
#define CAN_CFG_STAT_FD_ISO      		   	    CAN_CFG_STAT_FD_ISO_Msk

#define CAN_CFG_STAT_RSTAT_Pos         	    (24U)
#define	CAN_CFG_STAT_RSTAT_Msk				     	(0x3L << CAN_CFG_STAT_RSTAT_Pos)
#define CAN_CFG_STAT_RSTAT      		   	    CAN_CFG_STAT_RSTAT_Msk

#define CAN_CFG_STAT_RBALL_Pos         	    (27U)
#define	CAN_CFG_STAT_RBALL_Msk				     	(0x1L << CAN_CFG_STAT_RBALL_Pos)
#define CAN_CFG_STAT_RBALL      		   	    CAN_CFG_STAT_RBALL_Msk

#define CAN_CFG_STAT_RREL_Pos         	    (28U)
#define	CAN_CFG_STAT_RREL_Msk				     	  (0x1L << CAN_CFG_STAT_RREL_Pos)
#define CAN_CFG_STAT_RREL      		   	      CAN_CFG_STAT_RREL_Msk

#define CAN_CFG_STAT_ROV_Pos          	    (29U)
#define	CAN_CFG_STAT_ROV_Msk				     	  (0x1L << CAN_CFG_STAT_ROV_Pos)
#define CAN_CFG_STAT_ROV      		   	      CAN_CFG_STAT_ROV_Msk

#define CAN_CFG_STAT_ROM_Pos          	    (30U)
#define	CAN_CFG_STAT_ROM_Msk				     	  (0x1L << CAN_CFG_STAT_ROM_Pos)
#define CAN_CFG_STAT_ROM      		   	      CAN_CFG_STAT_ROM_Msk

#define CAN_CFG_STAT_SACK_Pos          	    (31U)
#define	CAN_CFG_STAT_SACK_Msk				     	  (0x1L << CAN_CFG_STAT_SACK_Pos)
#define CAN_CFG_STAT_SACK      		   	      CAN_CFG_STAT_SACK_Msk

/********************  Bit definition for CAN_RTIE register  ********************/
#define CAN_RTIE_TSFF_Pos         	      	(0U)
#define	CAN_RTIE_TSFF_Msk						        (0x1L << CAN_RTIE_TSFF_Pos)
#define CAN_RTIE_TSFF       				      	CAN_RTIE_TSFF_Msk

#define CAN_RTIE_EIE_Pos          	      	(1U)
#define	CAN_RTIE_EIE_Msk						        (0x1L << CAN_RTIE_EIE_Pos)
#define CAN_RTIE_EIE        				      	CAN_RTIE_EIE_Msk

#define CAN_RTIE_TSIE_Pos          	      	(2U)
#define	CAN_RTIE_TSIE_Msk						        (0x1L << CAN_RTIE_TSIE_Pos)
#define CAN_RTIE_TSIE        				      	CAN_RTIE_TSIE_Msk

#define CAN_RTIE_TPIE_Pos          	      	(3U)
#define	CAN_RTIE_TPIE_Msk						        (0x1L << CAN_RTIE_TPIE_Pos)
#define CAN_RTIE_TPIE        				      	CAN_RTIE_TPIE_Msk

#define CAN_RTIE_RAFIE_Pos          	     	(4U)
#define	CAN_RTIE_RAFIE_Msk						      (0x1L << CAN_RTIE_RAFIE_Pos)
#define CAN_RTIE_RAFIE        				     	CAN_RTIE_RAFIE_Msk

#define CAN_RTIE_RFIE_Pos          	      	(5U)
#define	CAN_RTIE_RFIE_Msk						        (0x1L << CAN_RTIE_RFIE_Pos)
#define CAN_RTIE_RFIE        				      	CAN_RTIE_RFIE_Msk

#define CAN_RTIE_ROIE_Pos          	      	(6U)
#define	CAN_RTIE_ROIE_Msk						        (0x1L << CAN_RTIE_ROIE_Pos)
#define CAN_RTIE_ROIE        				      	CAN_RTIE_ROIE_Msk

#define CAN_RTIE_RIE_Pos          	      	(7U)
#define	CAN_RTIE_RIE_Msk						        (0x1L << CAN_RTIE_RIE_Pos)
#define CAN_RTIE_RIE        				      	CAN_RTIE_RIE_Msk

#define CAN_RTIE_AIF_Pos          	      	(8U)
#define	CAN_RTIE_AIF_Msk						        (0x1L << CAN_RTIE_AIF_Pos)
#define CAN_RTIE_AIF        				      	CAN_RTIE_AIF_Msk

#define CAN_RTIE_EIF_Pos          	      	(9U)
#define	CAN_RTIE_EIF_Msk						        (0x1L << CAN_RTIE_EIF_Pos)
#define CAN_RTIE_EIF        				      	CAN_RTIE_EIF_Msk

#define CAN_RTIE_TSIF_Pos          	      	(10U)
#define	CAN_RTIE_TSIF_Msk						        (0x1L << CAN_RTIE_TSIF_Pos)
#define CAN_RTIE_TSIF        				      	CAN_RTIE_TSIF_Msk

#define CAN_RTIE_TPIF_Pos          	      	(11U)
#define	CAN_RTIE_TPIF_Msk						        (0x1L << CAN_RTIE_TPIF_Pos)
#define CAN_RTIE_TPIF        				      	CAN_RTIE_TPIF_Msk

#define CAN_RTIE_RAFIF_Pos          	     	(12U)
#define	CAN_RTIE_RAFIF_Msk						      (0x1L << CAN_RTIE_RAFIF_Pos)
#define CAN_RTIE_RAFIF        				     	CAN_RTIE_RAFIF_Msk

#define CAN_RTIE_RFIF_Pos          	      	(13U)
#define	CAN_RTIE_RFIF_Msk						        (0x1L << CAN_RTIE_RFIF_Pos)
#define CAN_RTIE_RFIF        				      	CAN_RTIE_RFIF_Msk

#define CAN_RTIE_ROIF_Pos          	      	(14U)
#define	CAN_RTIE_ROIF_Msk						        (0x1L << CAN_RTIE_ROIF_Pos)
#define CAN_RTIE_ROIF        				      	CAN_RTIE_ROIF_Msk

#define CAN_RTIE_RIF_Pos          	      	(15U)
#define	CAN_RTIE_RIF_Msk						        (0x1L << CAN_RTIE_RIF_Pos)
#define CAN_RTIE_RIF        				      	CAN_RTIE_RIF_Msk

#define CAN_RTIE_BEIF_Pos          	      	(16U)
#define	CAN_RTIE_BEIF_Msk						        (0x1L << CAN_RTIE_BEIF_Pos)
#define CAN_RTIE_BEIF        				      	CAN_RTIE_BEIF_Msk

#define CAN_RTIE_BEIE_Pos          	      	(17U)
#define	CAN_RTIE_BEIE_Msk						        (0x1L << CAN_RTIE_BEIE_Pos)
#define CAN_RTIE_BEIE        				      	CAN_RTIE_BEIE_Msk

#define CAN_RTIE_ALIF_Pos          	      	(18U)
#define	CAN_RTIE_ALIF_Msk						        (0x1L << CAN_RTIE_ALIF_Pos)
#define CAN_RTIE_ALIF        				      	CAN_RTIE_ALIF_Msk

#define CAN_RTIE_ALIE_Pos          	      	(19U)
#define	CAN_RTIE_ALIE_Msk						        (0x1L << CAN_RTIE_ALIE_Pos)
#define CAN_RTIE_ALIE        				      	CAN_RTIE_ALIE_Msk

#define CAN_RTIE_EPIF_Pos          	      	(20U)
#define	CAN_RTIE_EPIF_Msk						        (0x1L << CAN_RTIE_EPIF_Pos)
#define CAN_RTIE_EPIF        				      	CAN_RTIE_EPIF_Msk

#define CAN_RTIE_EPIE_Pos          	      	(21U)
#define	CAN_RTIE_EPIE_Msk						        (0x1L << CAN_RTIE_EPIE_Pos)
#define CAN_RTIE_EPIE        				      	CAN_RTIE_EPIE_Msk

#define CAN_RTIE_EPASS_Pos          	     	(22U)
#define	CAN_RTIE_EPASS_Msk						      (0x1L << CAN_RTIE_EPASS_Pos)
#define CAN_RTIE_EPASS        				     	CAN_RTIE_EPASS_Msk

#define CAN_RTIE_EWARN_Pos          	     	(23U)
#define	CAN_RTIE_EWARN_Msk						      (0x1L << CAN_RTIE_EWARN_Pos)
#define CAN_RTIE_EWARN        				     	CAN_RTIE_EWARN_Msk

#define CAN_RTIE_EWL_Pos          	       	(24U)
#define	CAN_RTIE_EWL_Msk						        (0xFL << CAN_RTIE_EWL_Pos)
#define CAN_RTIE_EWL        				      	CAN_RTIE_EWL_Msk

#define CAN_RTIE_AFWL_Pos          	       	(28U)
#define	CAN_RTIE_AFWL_Msk						        (0xFL << CAN_RTIE_AFWL_Pos)
#define CAN_RTIE_AFWL        				      	CAN_RTIE_AFWL_Msk

/********************  Bit definition for CAN_S_SEG register  ********************/
#define CAN_S_SEG_1_Pos         	        	(0U)
#define	CAN_S_SEG_1_Msk						          (0xFFL << CAN_S_SEG_1_Pos)
#define CAN_S_SEG_1       				        	CAN_S_SEG_1_Msk

#define CAN_S_SEG_2_Pos         	        	(8U)
#define	CAN_S_SEG_2_Msk						          (0x7FL << CAN_S_SEG_2_Pos)
#define CAN_S_SEG_2       				        	CAN_S_SEG_2_Msk

#define CAN_S_SJW_Pos         	          	(16U)
#define	CAN_S_SJW_Msk						            (0x7FL << CAN_S_SJW_Pos)
#define CAN_S_SJW       				          	CAN_S_SJW_Msk

#define CAN_S_PRESC_Pos         	         	(24U)
#define	CAN_S_PRESC_Msk						          (0xFFL << CAN_S_PRESC_Pos)
#define CAN_S_PRESC       				         	CAN_S_PRESC_Msk

/********************  Bit definition for CAN_F_SEG register  ********************/
#define CAN_F_SEG_1_Pos         	        	(0U)
#define	CAN_F_SEG_1_Msk						          (0x1FL << CAN_F_SEG_1_Pos)
#define CAN_F_SEG_1       				        	CAN_F_SEG_1_Msk

#define CAN_F_SEG_2_Pos         	        	(8U)
#define	CAN_F_SEG_2_Msk						          (0xFL << CAN_F_SEG_2_Pos)
#define CAN_F_SEG_2       				        	CAN_F_SEG_2_Msk

#define CAN_F_SJW_Pos         	          	(16U)
#define	CAN_F_SJW_Msk						            (0xFL << CAN_F_SJW_Pos)
#define CAN_F_SJW       				          	CAN_F_SJW_Msk

#define CAN_F_PRESC_Pos         	         	(24U)
#define	CAN_F_PRESC_Msk						          (0xFFL << CAN_F_PRESC_Pos)
#define CAN_F_PRESC       				         	CAN_F_PRESC_Msk

/********************  Bit definition for CAN_EALCAP register  ********************/
#define CAN_EALCAP_ALC_Pos                   (0U)
#define CAN_EALCAP_ALC_Msk                   (0x1FL << CAN_EALCAP_ALC_Pos)          
#define CAN_EALCAP_ALC                        CAN_EALCAP_ALC_Msk

#define CAN_EALCAP_KOER_Pos                  (5U)
#define CAN_EALCAP_KOER_Msk                  (0xEL << CAN_EALCAP_KOER_Pos)          
#define CAN_EALCAP_KOER                       CAN_EALCAP_KOER_Msk
#define CAN_EALCAP_SSPOFF_Pos         	   (8U)
#define	CAN_EALCAP_SSPOFF_Msk						   (0x7FL << CAN_EALCAP_SSPOFF_Pos)
#define CAN_EALCAP_SSPOFF       				    CAN_EALCAP_SSPOFF_Msk

#define CAN_EALCAP_TDCEN_Pos                 (15U)
#define CAN_EALCAP_TDCEN_Msk                 (0x1L << CAN_EALCAP_TDCEN_Pos)          
#define CAN_EALCAP_TDCEN                      CAN_EALCAP_TDCEN_Msk

#define CAN_EALCAP_RECNT_Pos                  (16U)
#define CAN_EALCAP_RECNT_Msk                  (0xFFL << CAN_EALCAP_RECNT_Pos)          
#define CAN_EALCAP_RECNT                       CAN_EALCAP_RECNT_Msk

#define CAN_EALCAP_TECNT_Pos                  (24U)
#define CAN_EALCAP_TECNT_Msk                  (0xFFL << CAN_EALCAP_TECNT_Pos)          
#define CAN_EALCAP_TECNT                       CAN_EALCAP_TECNT_Msk

/********************  Bit definition for CAN_ACFCTRL register  ********************/
#define CAN_ACFCTRL_ACFADR_Pos         	   (0U)
#define	CAN_ACFCTRL_ACFADR_Msk						 (0xFL << CAN_ACFCTRL_ACFADR_Pos)
#define CAN_ACFCTRL_ACFADR       				    CAN_ACFCTRL_ACFADR_Msk

#define CAN_ACFCTRL_SELMASK_Pos         	 (5U)
#define	CAN_ACFCTRL_SELMASK_Msk						 (0x1L << CAN_ACFCTRL_SELMASK_Pos)
#define CAN_ACFCTRL_SELMASK       				  CAN_ACFCTRL_SELMASK_Msk

#define CAN_ACFCTRL_TIMEEN_Pos         	   (8U)
#define	CAN_ACFCTRL_TIMEEN_Msk						 (0x1L << CAN_ACFCTRL_TIMEEN_Pos)
#define CAN_ACFCTRL_TIMEEN       				    CAN_ACFCTRL_TIMEEN_Msk

#define CAN_ACFCTRL_TIMEPOS_Pos         	  (9U)
#define	CAN_ACFCTRL_TIMEPOS_Msk						 (0x1L << CAN_ACFCTRL_TIMEPOS_Pos)
#define CAN_ACFCTRL_TIMEPOS       				  CAN_ACFCTRL_TIMEPOS_Msk

#define CAN_ACFCTRL_AE_0_Pos         	  (16U)
#define	CAN_ACFCTRL_AE_0_Msk						(0x1L << CAN_ACFCTRL_AE_0_Pos)
#define CAN_ACFCTRL_AE_0       				   CAN_ACFCTRL_AE_0_Msk

#define CAN_ACFCTRL_AE_1_Pos         	  (17U)
#define	CAN_ACFCTRL_AE_1_Msk						(0x1L << CAN_ACFCTRL_AE_1_Pos)
#define CAN_ACFCTRL_AE_1       				   CAN_ACFCTRL_AE_1_Msk

#define CAN_ACFCTRL_AE_2_Pos         	  (18U)
#define	CAN_ACFCTRL_AE_2_Msk						(0x1L << CAN_ACFCTRL_AE_2_Pos)
#define CAN_ACFCTRL_AE_2       				   CAN_ACFCTRL_AE_2_Msk

#define CAN_ACFCTRL_AE_3_Pos         	  (19U)
#define	CAN_ACFCTRL_AE_3_Msk						(0x1L << CAN_ACFCTRL_AE_3_Pos)
#define CAN_ACFCTRL_AE_3       				   CAN_ACFCTRL_AE_3_Msk

#define CAN_ACFCTRL_AE_4_Pos         	  (20U)
#define	CAN_ACFCTRL_AE_4_Msk						(0x1L << CAN_ACFCTRL_AE_4_Pos)
#define CAN_ACFCTRL_AE_4       				   CAN_ACFCTRL_AE_4_Msk

#define CAN_ACFCTRL_AE_5_Pos         	  (21U)
#define	CAN_ACFCTRL_AE_5_Msk						(0x1L << CAN_ACFCTRL_AE_5_Pos)
#define CAN_ACFCTRL_AE_5       				   CAN_ACFCTRL_AE_5_Msk

#define CAN_ACFCTRL_AE_6_Pos         	  (22U)
#define	CAN_ACFCTRL_AE_6_Msk						(0x1L << CAN_ACFCTRL_AE_6_Pos)
#define CAN_ACFCTRL_AE_6       				   CAN_ACFCTRL_AE_6_Msk

#define CAN_ACFCTRL_AE_7_Pos         	  (23U)
#define	CAN_ACFCTRL_AE_7_Msk						(0x1L << CAN_ACFCTRL_AE_7_Pos)
#define CAN_ACFCTRL_AE_7       				   CAN_ACFCTRL_AE_7_Msk

#define CAN_ACFCTRL_AE_8_Pos         	  (23U)
#define	CAN_ACFCTRL_AE_8_Msk						(0x1L << CAN_ACFCTRL_AE_8_Pos)
#define CAN_ACFCTRL_AE_8       				   CAN_ACFCTRL_AE_8_Msk

#define CAN_ACFCTRL_AE_9_Pos         	  (24U)
#define	CAN_ACFCTRL_AE_9_Msk						(0x1L << CAN_ACFCTRL_AE_9_Pos)
#define CAN_ACFCTRL_AE_9       				   CAN_ACFCTRL_AE_9_Msk

#define CAN_ACFCTRL_AE_10_Pos         	  (25U)
#define	CAN_ACFCTRL_AE_10_Msk						(0x1L << CAN_ACFCTRL_AE_10_Pos)
#define CAN_ACFCTRL_AE_10       				   CAN_ACFCTRL_AE_10_Msk

#define CAN_ACFCTRL_AE_11_Pos         	  (26U)
#define	CAN_ACFCTRL_AE_11_Msk						(0x1L << CAN_ACFCTRL_AE_11_Pos)
#define CAN_ACFCTRL_AE_11       				   CAN_ACFCTRL_AE_11_Msk

#define CAN_ACFCTRL_AE_12_Pos         	  (27U)
#define	CAN_ACFCTRL_AE_12_Msk						(0x1L << CAN_ACFCTRL_AE_12_Pos)
#define CAN_ACFCTRL_AE_12       				   CAN_ACFCTRL_AE_12_Msk

#define CAN_ACFCTRL_AE_13_Pos         	  (29U)
#define	CAN_ACFCTRL_AE_13_Msk						(0x1L << CAN_ACFCTRL_AE_13_Pos)
#define CAN_ACFCTRL_AE_13       				   CAN_ACFCTRL_AE_13_Msk

#define CAN_ACFCTRL_AE_14_Pos         	  (30U)
#define	CAN_ACFCTRL_AE_14_Msk						(0x1L << CAN_ACFCTRL_AE_14_Pos)
#define CAN_ACFCTRL_AE_14       				   CAN_ACFCTRL_AE_14_Msk

#define CAN_ACFCTRL_AE_15_Pos         	  (31U)
#define	CAN_ACFCTRL_AE_15_Msk						(0x1L << CAN_ACFCTRL_AE_15_Pos)
#define CAN_ACFCTRL_AE_15       				   CAN_ACFCTRL_AE_15_Msk

/********************  Bit definition for CAN_ACF register  ********************/
#define CAN_ACF_AMASK_ACODE_Pos         	(0U)
#define	CAN_ACF_AMASK_ACODE_Msk				    (0xFFFFFFL << CAN_ACF_AMASK_ACODE_Pos)
#define CAN_ACF_AMASK_ACODE       			   CAN_ACF_AMASK_ACODE_Msk

#define CAN_ACF_AIDE_Pos         	        (29U)
#define	CAN_ACF_AIDE_Msk				          (0x1L << CAN_ACF_AIDE_Pos)
#define CAN_ACF_AIDE       			           CAN_ACF_AIDE_Msk

#define CAN_ACF_AIDEE_Pos         	      (30U)
#define	CAN_ACF_AIDEE_Msk				          (0x1L << CAN_ACF_AIDEE_Pos)
#define CAN_ACF_AIDEE       			         CAN_ACF_AIDEE_Msk

/********************  Bit definition for TTCAN_CFG register  ********************/
#define TTCAN_CFG_VER_1_Pos               (0U)
#define TTCAN_CFG_VER_1_Msk               (0xFFL<<TTCAN_CFG_VER_1_Pos)
#define TTCAN_CFG_VER_1                    TTCAN_CFG_VER_1_Msk

#define TTCAN_CFG_VER_0_Pos               (8U)
#define TTCAN_CFG_VER_0_Msk               (0xFFL<<TTCAN_CFG_VER_0_Pos)
#define TTCAN_CFG_VER_0                    TTCAN_CFG_VER_0_Msk

#define TTCAN_CFG_TBPTR_Pos               (16U)
#define TTCAN_CFG_TBPTR_Msk                (0x1FL<<TTCAN_CFG_TBPTR_Pos)
#define TTCAN_CFG_TBPTR                    TTCAN_CFG_TBPTR_Msk

#define TTCAN_CFG_TBF_Pos                (22U)
#define TTCAN_CFG_TBF_Msk                (0x1L<<TTCAN_CFG_TBF_Pos)
#define TTCAN_CFG_TBF                     TTCAN_CFG_TBF_Msk

#define TTCAN_CFG_TBE_Pos               (23U)
#define TTCAN_CFG_TBE_Msk               (0x1L<<TTCAN_CFG_TBE_Pos)
#define TTCAN_CFG_TBE                    TTCAN_CFG_TBE_Msk

#define TTCAN_CFG_TTEN_Pos              (24U)
#define TTCAN_CFG_TTEN_Msk              (0x1L<<TTCAN_CFG_TTEN_Pos)
#define TTCAN_CFG_TTEN                   TTCAN_CFG_TTEN_Msk

#define TTCAN_CFG_T_PRESC_Pos           (25U)
#define TTCAN_CFG_T_PRESC_Msk           (0x3L<<TTCAN_CFG_T_PRESC_Pos)
#define TTCAN_CFG_T_PRESC                TTCAN_CFG_T_PRESC_Msk

#define TTCAN_CFG_TTIF_Pos              (27U)
#define TTCAN_CFG_TTIF_Msk              (0x1L<<TTCAN_CFG_TTIF_Pos)
#define TTCAN_CFG_TTIF                   TTCAN_CFG_TTIF_Msk

#define TTCAN_CFG_TTIE_Pos              (28U)
#define TTCAN_CFG_TTIE_Msk              (0x1L<<TTCAN_CFG_TTIE_Pos)
#define TTCAN_CFG_TTIE                   TTCAN_CFG_TTIE_Msk

#define TTCAN_CFG_TEIF_Pos              (29U)
#define TTCAN_CFG_TEIF_Msk              (0x1L<<TTCAN_CFG_TEIF_Pos)
#define TTCAN_CFG_TEIF                   TTCAN_CFG_TEIF_Msk

#define TTCAN_CFG_WTIF_Pos              (30U)
#define TTCAN_CFG_WTIF_Msk              (0x1L<<TTCAN_CFG_WTIF_Pos)
#define TTCAN_CFG_WTIF                   TTCAN_CFG_WTIF_Msk

#define TTCAN_CFG_WTIE_Pos              (31U)
#define TTCAN_CFG_WTIE_Msk              (0x1L<<TTCAN_CFG_WTIE_Pos)
#define TTCAN_CFG_WTIE                   TTCAN_CFG_WTIE_Msk

/********************  Bit definition for TTCAN_RFMSG register  ********************/
#define TTCAN_RFMSG_REF_ID_Pos           (0U)
#define TTCAN_RFMSG_REF_ID_Msk           (0x1FFFFFFL<<TTCAN_RFMSG_REF_ID_Pos)
#define TTCAN_RFMSG_REF_ID                TTCAN_RFMSG_REF_ID_Msk

#define TTCAN_RFMSG_REF_IDE_Pos          (31U)
#define TTCAN_RFMSG_REF_IDE_Msk          (0x1L<<TTCAN_RFMSG_REF_IDE_Pos)
#define TTCAN_RFMSG_REF_IDE               TTCAN_RFMSG_REF_IDE_Msk

/********************  Bit definition for TTCAN_TRIG_CFG register  ********************/
#define TTCAN_TRIG_CFG_TTPTR_Pos           (0U)
#define TTCAN_TRIG_CFG_TTPTR_Msk           (0x3FL<<TTCAN_TRIG_CFG_TTPTR_Pos)
#define TTCAN_TRIG_CFG_TTPTR                TTCAN_TRIG_CFG_TTPTR_Msk

#define TTCAN_TRIG_CFG_TTYPE_Pos           (8U)
#define TTCAN_TRIG_CFG_TTYPE_Msk           (0x7FL<<TTCAN_TRIG_CFG_TTYPE_Pos)
#define TTCAN_TRIG_CFG_TTYPE                TTCAN_TRIG_CFG_TTYPE_Msk

#define TTCAN_TRIG_CFG_TEW_Pos           (12U)
#define TTCAN_TRIG_CFG_TEW_Msk           (0xFL<<TTCAN_TRIG_CFG_TEW_Pos)
#define TTCAN_TRIG_CFG_TEW                TTCAN_TRIG_CFG_TEW_Msk

#define TTCAN_TRIG_CFG_TT_TRIG_Pos       (16U)
#define TTCAN_TRIG_CFG_TT_TRIG_Msk       (0x3FL<<TTCAN_TRIG_CFG_TT_TRIG_Pos)
#define TTCAN_TRIG_CFG_TT_TRIG            TTCAN_TRIG_CFG_TT_TRIG_Msk

/********************  Bit definition for TTCAN_WTRIG register  ********************/
#define TTCAN_WTRIG_TT_WTRIG_Pos       (0U)
#define TTCAN_WTRIG_TT_WTRIG_Msk       (0xFFFFL<<TTCAN_WTRIG_TT_WTRIG_Pos)
#define TTCAN_WTRIG_TT_WTRIG            TTCAN_WTRIG_TT_WTRIG_Msk

/********************  Bit definition for CAN_IDE register  ********************/
#define CAN_IDE_INTEN_Pos       (0U)
#define CAN_IDE_INTEN_Msk       (0x1L<<CAN_IDE_INTEN_Pos)
#define CAN_IDE_INTEN            CAN_IDE_INTEN_Msk

#define CAN_IDE_TIMEN_Pos       (11U)
#define CAN_IDE_TIMEN_Msk       (0x1L<<CAN_IDE_TIMEN_Pos)
#define CAN_IDE_TIMEN           CAN_IDE_TIMEN_Msk

#define CAN_IDE_RXEN_Pos       (14U)
#define CAN_IDE_RXEN_Msk       (0x1L<<CAN_IDE_RXEN_Pos)
#define CAN_IDE_RXEN            CAN_IDE_RXEN_Msk

#define CAN_IDE_TXEN_Pos       (15U)
#define CAN_IDE_TXEN_Msk       (0x1L<<CAN_IDE_TXEN_Pos)
#define CAN_IDE_TXEN            CAN_IDE_TXEN_Msk

#define CAN_IDE_FD_ENABLE_Pos       (31U)
#define CAN_IDE_FD_ENABLE_Msk       (0x1L<<CAN_IDE_FD_ENABLE_Pos)
#define CAN_IDE_FD_ENABLE            CAN_IDE_FD_ENABLE_Msk



/** @addtogroup Exported_macros
  * @{
  */

/**
  * @}
  */

/**
 * @}
 */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SC32M156xx_H */

/**
  * @}
  */

/**
* @}
*/

/************************ (C) COPYRIGHT SIN ONE CHIP *****END OF FILE****/
