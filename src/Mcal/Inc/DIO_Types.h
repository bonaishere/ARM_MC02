/**************************************************************************************************
 *	FILE DESCRIPTION
 *	-----------------------------------------------------------------------------------------------
 *	       File:	Dio_Types.h
 *	     Module:
 *
 *	Description:
 *
 *
 *************************************************************************************************/
#ifndef DIO_TYPES_H
#define DIO_TYPES_H
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
    Dio_Channel_A0 = 0x400001u,
    Dio_Channel_A1 = 0x400002u,
    Dio_Channel_A2 = 0x400004u,
    Dio_Channel_A3 = 0x400008u,
    Dio_Channel_A4 = 0x400010u,
    Dio_Channel_A5 = 0x400020u,
    Dio_Channel_A6 = 0x400040u,
    Dio_Channel_A7 = 0x400080u,

    Dio_Channel_B0 = 0x500001u,
    Dio_Channel_B1 = 0x500002u,
    Dio_Channel_B2 = 0x500004u,
    Dio_Channel_B3 = 0x500008u,
    Dio_Channel_B4 = 0x500010u,
    Dio_Channel_B5 = 0x500020u,
    Dio_Channel_B6 = 0x500040u,
    Dio_Channel_B7 = 0x500080u,

    Dio_Channel_C0 = 0x600001u,
    Dio_Channel_C1 = 0x600002u,
    Dio_Channel_C2 = 0x600004u,
    Dio_Channel_C3 = 0x600008u,
    Dio_Channel_C4 = 0x600010u,
    Dio_Channel_C5 = 0x600020u,
    Dio_Channel_C6 = 0x600040u,
    Dio_Channel_C7 = 0x600080u,

    Dio_Channel_D0 = 0x700001u,
    Dio_Channel_D1 = 0x700002u,
    Dio_Channel_D2 = 0x700004u,
    Dio_Channel_D3 = 0x700008u,
    Dio_Channel_D4 = 0x700010u,
    Dio_Channel_D5 = 0x700020u,
    Dio_Channel_D6 = 0x700040u,
    Dio_Channel_D7 = 0x700080u,

    Dio_Channel_E0 = 0x2400001u,
    Dio_Channel_E1 = 0x2400002u,
    Dio_Channel_E2 = 0x2400004u,
    Dio_Channel_E3 = 0x2400008u,
    Dio_Channel_E4 = 0x2400010u,
    Dio_Channel_E5 = 0x2400020u,
    Dio_Channel_E6 = 0x2400040u,
    Dio_Channel_E7 = 0x2400080u,

    Dio_Channel_F0 = 0x2500001u,
    Dio_Channel_F1 = 0x2500002u,
    Dio_Channel_F2 = 0x2500004u,
    Dio_Channel_F3 = 0x2500008u,
    Dio_Channel_F4 = 0x2500010u,
    Dio_Channel_F5 = 0x2500020u,
    Dio_Channel_F6 = 0x2500040u,
    Dio_Channel_F7 = 0x2500080u

}Dio_ChannelType;

typedef enum
{
    Dio_Port_A = 0x40004000u,
    Dio_Port_B = 0x40005000u,
    Dio_Port_C = 0x40006000u,
    Dio_Port_D = 0x40007000u,
    Dio_Port_E = 0x40024000u,
    Dio_Port_F = 0x40025000u

}Dio_PortType;

typedef enum
{
    Dio_Low  = 0x0000,
    Dio_High = 0x0001

}Dio_LevelType;

typedef uint8 Dio_PortLevelType;
 
 #endif    /* DIO_TYPES_H */
 
/**************************************************************************************************
 *	END OF FILE:	Dio_Types.h
 *************************************************************************************************/