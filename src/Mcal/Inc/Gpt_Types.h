/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPT_TYPES_H
#define GPT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define Gpt_ValueType			uint32_t

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	TIMER0,
	TIMER1,
	TIMER2,
	TIMER3,
	TIMER4,
	TIMER5,
	TIMER0W,
	TIMER1W,
	TIMER2W,
	TIMER3W,
	TIMER4W,
	TIMER5W,	
}Gpt_ChannelType;
typedef enum
{
	GPT_COUNT_DOWN,
	GPT_COUNT_UP,
}Gpt_CountDir;
typedef enum
{
	GPT_MODE_NORMAL, //countinous
	GPT_MODE_SLEEP,  //one-shot
}Gpt_ModeType;
typedef enum
{
	GPT_PREDEF_TIMER_1US_16BIT = 0x00,
	GPT_PREDEF_TIMER_1US_24BIT,
	GPT_PREDEF_TIMER_1US_32BIT,
	GPT_PREDEF_TIMER_100US_32BIT
}Gpt_PredefTimerType;

typedef struct
{
	Gpt_ChannelType GptChannelId;
	uint32_t GptChannelTickFrequency;
	uint32_t GptChannelTickValueMax;
	Gpt_ModeType Mode;
}Gpt_ConfigType;

#endif  /* GPT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT_Types.h
 *********************************************************************************************************************/