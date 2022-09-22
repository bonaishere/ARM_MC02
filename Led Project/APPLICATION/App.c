/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  App.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "App.h"
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

/******************************************************************************
 * \Syntax             : int main (void)
 * \Description        : The Application Entry Point
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Non Reentrant
 * \Parameters (in)    : None
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value:      : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
int main(void)
{
	/* Intialize all modules according to user configurations */
	System_Init();

	/* Get Blinking Time Off from user */
	uint32 Time_On = Time_GetOn();
	Time_On = Time_GetTimerTicks(Time_On);
	/* Get Blinking Time On from user */
	uint32 Time_OFF = Time_GetOff();
	Time_OFF = Time_GetTimerTicks(Time_OFF);

	while (1)
	{
		Blinking_Start(LED_1, Time_On, Time_OFF);
	}

	return 0;
}

/**********************************************************************************************************************
 *  END OF FILE: App.c
 *********************************************************************************************************************/