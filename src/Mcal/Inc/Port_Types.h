/**************************************************************************************************
 *	FILE DESCRIPTION
 *	-----------------------------------------------------------------------------------------------
 *	       File:	Port_Types.h
 *	     Module:
 *
 *	Description:
 *
 *
 *************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H
/**************************************************************************************************
 *	INCLUDES
 *************************************************************************************************/
#include "Std_Types.h"

/**************************************************************************************************
 *	GLOBAL CONSTANT MACROS
 *************************************************************************************************/
 
/**************************************************************************************************
 *	GLOBAL FUNCTION MACROS
 *************************************************************************************************/
 
/**************************************************************************************************
 *	GLOBAL DATA TYPES AND STRUCTURES
 *************************************************************************************************/
typedef enum
{
    Port_Pin_A0 = 0x40000u,
    Port_Pin_A1 = 0x40001u,
    Port_Pin_A2 = 0x40002u,
    Port_Pin_A3 = 0x40003u,
    Port_Pin_A4 = 0x40004u,
    Port_Pin_A5 = 0x40005u,
    Port_Pin_A6 = 0x40006u,
    Port_Pin_A7 = 0x40007u,

    Port_Pin_B0 = 0x50000u,
    Port_Pin_B1 = 0x50001u,
    Port_Pin_B2 = 0x50002u,
    Port_Pin_B3 = 0x50002u,
    Port_Pin_B4 = 0x50003u,
    Port_Pin_B5 = 0x50004u,
    Port_Pin_B6 = 0x50005u,
    Port_Pin_B7 = 0x50007u,

    Port_Pin_C0 = 0x60000u,
    Port_Pin_C1 = 0x60001u,
    Port_Pin_C2 = 0x60002u,
    Port_Pin_C3 = 0x60003u,
    Port_Pin_C4 = 0x60004u,
    Port_Pin_C5 = 0x60005u,
    Port_Pin_C6 = 0x60006u,
    Port_Pin_C7 = 0x60006u,

    Port_Pin_D0 = 0x70000u,
    Port_Pin_D1 = 0x70001u,
    Port_Pin_D2 = 0x70002u,
    Port_Pin_D3 = 0x70003u,
    Port_Pin_D4 = 0x70004u,
    Port_Pin_D5 = 0x70005u,
    Port_Pin_D6 = 0x70006u,
    Port_Pin_D7 = 0x70007u,

    Port_Pin_E0 = 0x240000u,
    Port_Pin_E1 = 0x240001u,
    Port_Pin_E2 = 0x240002u,
    Port_Pin_E3 = 0x240003u,
    Port_Pin_E4 = 0x240004u,
    Port_Pin_E5 = 0x240005u,
    Port_Pin_E6 = 0x240006u,
    Port_Pin_E7 = 0x240007u,

    Port_Pin_F0 = 0x250000u,
    Port_Pin_F1 = 0x250001u,
    Port_Pin_F2 = 0x250002u,
    Port_Pin_F3 = 0x250003u,
    Port_Pin_F4 = 0x250004u,
    Port_Pin_F5 = 0x250005u,
    Port_Pin_F6 = 0x250006u,
    Port_Pin_F7 = 0x250007u

}Port_PinType;

typedef enum
{
    Port_PinInput = 0,
    Port_PinOutput= 1

}Port_PinDirectionType;

typedef enum
{
    Port_PinDigital =16,
    Port_PinAnalog  =17,
     
    PA0_U0RX    =1u,
    PA0_CAN1RX  =8u,
    PA1_U0TX    =1u,
    PA1_CAN1TX  =8u,
    PA2_SSI0CLK =2u,
    PA3_SSI0FSS =2u,
    PA4_SSI0RX  =2u,
    PA5_SSI0TX  =2u,
    PA6_I2C1SCL =3u,
    PA6_M1PWM2  =5u,
    PA7_I2C1SDA =3u,
    PA7_M1PWM3  =5u,
    PB0_U1RX    =1u,
    PB0_T2CCP0  =7u,
    PB1_U1TX    =1u,
    PB1_T2CCP1  =7u,
    PB2_I2C0SCL =3u,
    PB2_T3CCP0  =7u,
    PB3_I2C0SDA =3u,
    PB3_T3CCP1  =7u,
    PB4_SSI2CLK =2u,
    PB4_M0PWM2  =4u,
    PB4_T1CCP0  =7u,
    PB4_CAN0RX  =8u,
    PB5_SSI2FSS =2u,
    PB5_M0PWM3  =4u,
    PB5_T1CCP1  =7u,
    PB5_CAN0TX  =8u,
    PB6_SSI2RX  =2u,
    PB6_M0PWM0  =4u,
    PB6_T0CCP0  =7u,
    PB7_SSI2TX  =2u,
    PB7_M0PWM1  =4u,
    PB7_T0CCP1  =7u,
    PC0_TCK_SWCLK =1u,
    PC0_T4CCP0  =7u,
    PC1_TCK_SWDIO =1u,
    PC1_T4CCP1  =7u,
    PC2_TDI     =1u,
    PC2_T5CCP0  =7u,
    PC3_TDO_SWO =1u,
    PC3_T5CCP1  =7u,
    PC4_U4RX    =1u,
    PC4_U1RX    =2u,
    PC4_M0PWM6  =4u,
    PC4_IDX1    =6u,
    PC4_WT0CCP0 =7u,
    PC4_U1RTS   =8u,
    PC5_U4TX    =1u,
    PC5_U1TX    =2u,
    PC5_M0PWM7  =4u,
    PC5_PHA1    =6u,
    PC5_WT0CCP1 =7u,
    PC5_U1CTS   =8u,
    PC6_U3RX    =1u,
    PC6_PHB1    =6u,
    PC6_WT1CCP0 =7u,
    PC6_USB0EPEN =8u,
    PC7_U3TX    =1u,
    PC7_WT1CCP1 =7u,
    PC7_USB0PFLT =8u,
    PD0_SSI3CLK =1u,
    PD0_SSI1CLK =2u,
    PD0_I2C3SCL =3u,
    PD0_M0PWM6  =4u,
    PD0_M1PWM0  =5u,
    PD0_WT2CCP0 =7u,
    PD1_SSI3FSS =1u,
    PD1_SSI1FSS =2u,
    PD1_I2C3SDA =3u,
    PD1_M0PWM7 =4u,
    PD1_M1PWM1  =5u,
    PD1_WT2CCP1 =7u,
    PD2_SSI3RX  =1u,
    PD2_SSI1RX  =2u,
    PD2_M0FAULT0 =4u,
    PD2_WT3CCP0 =7u,
    PD2_USB0EPEN =8u,
    PD3_SSI3TX  =1u,
    PD3_SSI1TX  =2u,
    PD3_IDX0    =6u,
    PD3_WT3CCP1 =7u,
    PD3_USB0PFLT =8u,
    PD4_U6RX =1u,
    PD4_WT4CCP0 =7u,
    PD5_U6TX =1u,
    PD5_WT4CCP1 =7u,
    PD6_U2RX =1u,
    PD6_M0FAULT0 =4u,
    PD6_PHA0 =6u,
    PD6_WT5CCP0 =7u,
    PD7_U2TX =1u,
    PD7_PHB0 =6u,
    PD7_WT5CCP1 =7u,
    PD7_NMI =8u,
    PE0_U7RX =1u,
    PE1_U7TX =1u,
    PE4_U5RX =1u,
    PE4_I2C2SCL =3u,
    PE4_M0PWM4 =4u,
    PE4_M1PWM2 =5u,
    PE4_CAN0RX =8u,
    PE5_U5TX =1u,
    PE5_I2C2SDA =3u,
    PE5_M0PWM5 =4u,
    PE5_M1PWM2 =5u,
    PE5_CAN0TX =8u,
    PF0_U1RTS =1u,
    PF0_SSI1RX =2u,
    PF0_CAN0RX =3u,
    PF0_M1PWM4 =5u,
    PF0_PHA0 =6u,
    PF0_T0CCP0 =7u,
    PF0_NMI =8u,
    PF0_C0O =9u,
    PF1_U1CTS =1u,
    PF1_SSI1TX =2u,
    PF1_M1PWM5 =5u,
    PF1_PHB0 =6u,
    PF1_T0CCP1 =7u,
    PF1_C1O =9u,
    PF1_TRD1 =14u,
    PF2_SSI1CLK =2u,
    PF2_M0FAULT0 =4u,
    PF2_M1PWM6 =5u,
    PF2_T1CCP0 =7u,
    PF2_TRD10 =14u,
    PF3_SSI1FSS =2u,
    PF3_CAN0TX =3u,
    PF3_M1PWM7 =5u,
    PF3_T1CCP1 =7u,
    PF3_TRCLK =14u,
    PF4_M1FAULT0 =5u,
    PF4_IDX0 =6u,
    PF4_T2CCP0 =7u,
    PF4_USB0EPEN =8u

}Port_PinModeType;

typedef enum
{
    Port_PinInternalAttachDefault,
    Port_PinOpenDrain = 0x50Cu,
    Port_PinPullUp    = 0x510u,
    Port_PinPullDown  = 0x514u

}Port_PinInternalAttachType;

typedef enum
{
    Port_PinOutputCurrentDefault,
    Port_2ma = 0x500u,
    Port_4ma = 0x504u,
    Port_8ma = 0x508u

}Port_PinOutputCurrentType;

typedef struct
{
    Port_PinType pin;
    Port_PinDirectionType direction;
    Port_PinModeType mode;
    Port_PinInternalAttachType internalAttach;
    Port_PinOutputCurrentType outputcurrent;

}Port_ConfigType;

 #endif    /* PORT_TYPES_H */
 
/**************************************************************************************************
 *	END OF FILE:	Port_Types.h
 *************************************************************************************************/