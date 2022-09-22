/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Button.c
 *        \brief  
 *
 *      \details  Source File for Button Module .
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Button.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

 /*******************************************************************************
 * Service Name: Button_Init
 * Service ID[hex]: 0x00
 * Sync/Async: Asynchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: void
 * Description: Function to initialize the connected channel using Port MCAL
 *******************************************************************************/
void Button_Init(void)
{
	/* Intialize Port Driver according to user Configurations*/
	Port_Init(&Port_Configurations);
}

/******************************************************************************
 * \Syntax          : Button_State Button_GetState(Button_ChannelType ButtonChannel, Button_AttachType ButtonAttach)
 * \Description     : Function to Get Status Specific Button .
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : ButtonChannel - Button Id.
 *					  ButtonAttach  - The connection type (PULL_UP or PULL_DOWN)
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
Button_State Button_GetState(Button_ChannelType ButtonChannel, Button_AttachType ButtonAttach)
{
	Dio_LevelType level = DIO_LEVEL_LOW;
	
	Button_State button_State ;
	
	if (ButtonAttach == PINATTACH_PULLUP)
	{
		level = DIO_LEVEL_HIGH;
	}
		
	else if (ButtonAttach == PINATTACH_PULLDOWN)
	{
		level = DIO_LEVEL_LOW;
	}
		
	
	if (Dio_ReadChannel(ButtonChannel) == level)
	{
		/* Delay to avoid bouncing */
		for(int i = 0; i < 1000; i++);
		
		if (Dio_ReadChannel(ButtonChannel) == level)
		{
			button_State = BUTTON_RELEASED;
		}
		else
		{
			button_State = BUTTON_PRESSED;
		}
	}
	else
	{
		
		button_State =  BUTTON_PRESSED;
	}
	
	return button_State;
}
/**********************************************************************************************************************
 *  END OF FILE: Button.c
 *********************************************************************************************************************/
