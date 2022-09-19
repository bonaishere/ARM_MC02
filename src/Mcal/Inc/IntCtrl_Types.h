/**************************************************************************************************
 *	FILE DESCRIPTION
 *	-----------------------------------------------------------------------------------------------
 *	       File:	IntCtrl_Types.h
 *	     Module:
 *
 *	Description:
 *
 *
 *************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H
/**************************************************************************************************
 *	INCLUDES
 *************************************************************************************************/
 #include "Std_Types.h"

/**************************************************************************************************
 *	GLOBAL CONSTANT MACROS
 *************************************************************************************************/

 #define XXX            0x0u
 #define XXY            0x5u
 #define XYY            0x6u
 #define YYY            0x7u
/**************************************************************************************************
 *	GLOBAL FUNCTION MACROS
 *************************************************************************************************/
 
/**************************************************************************************************
 *	GLOBAL DATA TYPES AND STRUCTURES
 *************************************************************************************************/
typedef enum
{
    SP                              ,
    Reset                           ,
    NMI                             ,
    HardFault                       ,
    MemoryManagemen                 ,
    BusFault                        ,
    UsageFault                      ,
    SVCall                     = 11 ,
    DebugMonitor                    ,
    PendSV                     = 14 ,
    SysTick
    
}IntCtrl_ExceptionType;

typedef enum
{
    GPIO_Port_A                     ,
    GPIO_Port_B                     ,
    GPIO_Port_C                     ,
    GPIO_Port_D                     ,
    GPIO_Port_E                     ,
    UART0                           ,
    UART1                           ,
    SSI0                            ,
    I2C0                            ,
    PWM0_Fault                      ,
    PWM0_Generator_0                ,
    PWM0_Generator_1                ,
    PWM0_Generator_2                ,
    QEI0                            ,
    ADC0_Sequence_0                 ,
    ADC0_Sequence_1                 ,
    ADC0_Sequence_2                 ,
    ADC0_Sequence_3                 ,
    Watchdog_Timers_0_1             ,
    Bit32_16_Timer_0A               ,
    Bit32_16_Timer_0B               ,
    Bit32_16_Timer_1A               ,
    Bit32_16_Timer_1B               ,
    Bit32_16_Timer_2A               ,
    Bit32_16_Timer_2B               ,
    Analog_Comparator_0             ,
    Analog_Comparator_1             ,
    System_Control             = 28 ,
    ROM_Control                     ,
    GPIO_Port_F                     ,
    UART2                      = 33 ,
    SSI1                            ,
    Bit32_16_Timer_3A               ,
    Bit32_16_Timer_3B               ,
    I2C1                            ,
    QEI1                            ,
    CAN0                            ,
    CAN1                            ,
    Hibernation_Module         = 43 ,
    USB                             ,
    PWM0_Generator_3                ,
    DMA_Software                    ,
    DMA_Error                       ,
    ADC1_Sequence_0                 ,
    ADC1_Sequence_1                 ,
    ADC1_Sequence_2                 ,
    ADC1_Sequence_3                 ,
    SSI2                       = 57 ,
    SSI3                            ,
    UART3                           ,
    UART4                           ,
    UART5                           ,
    UART6                           ,
    UART7                           ,
    I2C2                       = 68 ,
    I2C3                            ,
    Bit32_16_Timer_4A               ,
    Bit32_16_Timer_4B               ,
    Bit32_16_Timer_5A          = 92 ,
    Bit32_16_Timer_5B               ,
    Bit64_32_Timer_0A               ,
    Bit64_32_Timer_0B               ,
    Bit64_32_Timer_1A               ,
    Bit64_32_Timer_1B               ,
    Bit64_32_Timer_2A               ,
    Bit64_32_Timer_2B               ,
    Bit64_32_Timer_3A               ,
    Bit64_32_Timer_3B               ,
    Bit64_32_Timer_4A               ,
    Bit64_32_Timer_4B               ,
    Bit64_32_Timer_5A               ,
    Bit64_32_Timer_5B               ,
    System_Exception                ,
    PWM1_Generator_0          = 134 ,
    PWM1_Generator_1                ,
    PWM1_Generator_2                ,
    PWM1_Generator_3                ,
    PWM1_Fault

}IntCtrl_InterruptType;
 
typedef struct
{
    IntCtrl_InterruptType vectorName;
		uint8 _COMPILER_PADDING[3];
    uint32 groupPriority;
    uint32 subGroupPriority;

}IntCtrl_ConfigType;


 #endif    /* INTCTRL_TYPES_H */
 
/**************************************************************************************************
 *	END OF FILE:	IntCtrl_Types.h
 *************************************************************************************************/