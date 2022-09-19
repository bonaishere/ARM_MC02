/**************************************************************************************************
 *	FILE DESCRIPTION
 *	---------------------------------------------------------------------------------------------*/
/**		\file
 *		\brief
 *
 *		\details
 *
 *
 *************************************************************************************************/
  
/**************************************************************************************************
 *	INCLUDES
 *************************************************************************************************/
#include "Gpt.h"
/**************************************************************************************************
 *	LOCAL MACROS CONSTANT\FUNCTION
 *************************************************************************************************/
 
/**************************************************************************************************
 *	LOCAL DATA
 *************************************************************************************************/
 Gpt_Notification callBacksArray[12] = {NULL};

/**************************************************************************************************
 *	GLOBAL DATA
 *************************************************************************************************/
 
/**************************************************************************************************
 *	LOCAL FUNCTION PROTOTYPES
 *************************************************************************************************/ 
 void Gpt_SetTimerModuleInit(Gpt_ConfigType *ConfigPtr);
 void Gpt_SetTimerMode(Gpt_ConfigType *ConfigPtr);

/**************************************************************************************************
 *	LOCAL FUNCTIONS
 *************************************************************************************************/
 
/**************************************************************************************************
 *	GLOBAL FUNCTIONS
 *************************************************************************************************/
 
/********************************************************************
 *	\Syntax				:
 *	\Description		:
 *
 *	\Sync\Async			:
 *	\Reentrancy			:
 *	\Parameters (in)	:
 *	\Parameters (out)	:
 *	\Return value		:
 *
 *******************************************************************/
 void Gpt_Init()
 {
    for (uint16 i = 0; i < ACTIVATED_TIMERS_NUM; i++)
    {
        Gpt_SetTimerModuleInit(&gpt_config[i]);
        Gpt_SetTimerMode(&gpt_config[i]);
    }

    // #if(GPT_PREDEF_TIMER_1US_16BIT)
    // //enable GPT_PREDEF_TIMER_1US_16BIT at value 0
    // #endif
 }

  
/********************************************************************
 *	\Syntax				:
 *	\Description		:
 *
 *	\Sync\Async			:
 *	\Reentrancy			:
 *	\Parameters (in)	:
 *	\Parameters (out)	:
 *	\Return value		:
 *
 *******************************************************************/
void Gpt_SetTimerModuleInit(Gpt_ConfigType *ConfigPtr)
{
    // uint32 timer = 0x40000000u | ((uint32)(ConfigPtr->channelID)<<12u);

    //Disable timer
    TIMER(ConfigPtr->channelID)->GPTMCTL = 0;
    //None Concatenated
    TIMER(ConfigPtr->channelID)->GPTMCFG = 0x00u;
    //CountDown
    TIMER(ConfigPtr->channelID)->GPTMTAMR &= ~(1u << 4u);
    //Disable Interrupts
    // TIMER(ConfigPtr->channelID)->GPTMIMR = 0;
}

void Gpt_SetTimerMode(Gpt_ConfigType *ConfigPtr)
{
    // uint32 timer = 0x40000000u | ((uint32)(ConfigPtr->channelID)<<12u);

    switch (ConfigPtr->channelMode)
    {
    case Gpt_OneShot:
        TIMER(ConfigPtr->channelID)->GPTMTAMR |= 1u << 0u;
        break;
    case Gpt_Periodic:
        TIMER(ConfigPtr->channelID)->GPTMTAMR |= 1u << 1u;
        break;
    }
}

/********************************************************************
 *	\Syntax				:
 *	\Description		:
 *
 *	\Sync\Async			:
 *	\Reentrancy			:
 *	\Parameters (in)	:
 *	\Parameters (out)	:
 *	\Return value		:
 *
 *******************************************************************/
 void Gpt_EnableNotification(Gpt_ConfigType *ConfigPtr, Gpt_Notification callBackPtr)
{
//   uint32 timer = 0x40000000u | ((uint32)(ConfigPtr->channelID)<<12u);
  uint8 j=0;
	Gpt_ChannelType i=Gpt_Timer0;
    
	/* set call back to global array*/
	
	while(i <= Gpt_WideTimer5)
	{
		callBacksArray[j] = callBackPtr;
		i++;
        
		if (i==Gpt_WideTimer1)
			{
				i=Gpt_WideTimer2;
			}
			j++;
	}
		
  TIMER(ConfigPtr->channelID)->GPTMIMR |= 1;         /*enable time out interrupt*/
}


/********************************************************************
 *	\Syntax				:
 *	\Description		:
 *
 *	\Sync\Async			:
 *	\Reentrancy			:
 *	\Parameters (in)	:
 *	\Parameters (out)	:
 *	\Return value		:
 *
 *******************************************************************/
void Gpt_DisableNotification(Gpt_ConfigType *ConfigPtr)
{
    // uint32 timer = 0x40000000u | ((uint32)(ConfigPtr->channelID)<<12u);
    TIMER(ConfigPtr->channelID)->GPTMICR = 0x10F1F;        /*disable interrupts*/
}

/********************************************************************
 *	\Syntax				:
 *	\Description		:
 *
 *	\Sync\Async			:
 *	\Reentrancy			:
 *	\Parameters (in)	:
 *	\Parameters (out)	:
 *	\Return value		:
 *
 *******************************************************************/
void Gpt_StartTimer(Gpt_ConfigType *ConfigPtr, Gpt_ValueType loadValue)
{
    // uint32 timer = 0x40000000u | ((uint32)(ConfigPtr->channelID)<<12u);

    TIMER(ConfigPtr->channelID)->GPTMTAILR = loadValue * 0xF423FF;
    TIMER(ConfigPtr->channelID)->GPTMICR |= (1<<0);        /* TimerA timeout flag bit clears*/
    // TIMER(ConfigPtr->channelID)->GPTMCTL |= (1u << 0);
}

/********************************************************************
 *	\Syntax				:
 *	\Description		:
 *
 *	\Sync\Async			:
 *	\Reentrancy			:
 *	\Parameters (in)	:
 *	\Parameters (out)	:
 *	\Return value		:
 *
 *******************************************************************/
void TIMER1A_Handler(void)
{

    Gpt_Notification callback = callBacksArray[1];

    if (callback != NULL)
    {   
        TIMER1->GPTMICR |= 1 << 0;      /*clear interrupt status flag*/
        callback();                     /*jump to callback*/
    }
}

/**************************************************************************************************
 *	END OF FILE:    Gpt.c
 *************************************************************************************************/