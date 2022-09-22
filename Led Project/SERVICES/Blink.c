/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Blink.c
 *        \brief
 *
 *      \details Source File for Blink Service .
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Blink.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

 //define easy to read names for registers
// #define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define SYSCTL_RCGCGPIO_R		(*((volatile unsigned long *)0x400FE608))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

static uint8 Led_Status = LED_STATUS_OFF;
unsigned long SW1, SW2;  	// input from PF0 and PF4

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
 * \Syntax             : Blinking_Start
 * \Description        : Function to blink the specified led.
 * \Sync\Async         : Synchronous.
 * \Reentrancy         : NonReentrant.
 * \Parameters (in)    : LedId    - The specific led id.
 *					   : Time_On  - Led On time period
 *                     : Time_OFF - Led Off time period
 * \Parameters (inout) : None.
 * \Parameters (out)   : None.
 * \Return value:      : None.
 *******************************************************************************/
void Blinking_Start(Led_ChannelType LedId, uint32 Time_On, uint32 Time_OFF)
{
	PortF_Init();
	while (1) {
		SW1 = GPIO_PORTF_DATA_R & 0x10; 	// read PF4 into SW1
		SW2 = GPIO_PORTF_DATA_R & 0x01; 	// read PF0 into SW2
	if (SW1 == 0x00 & SW2 == 0x00) {
		if (Led_Status != LED_STATUS_OFF)
		{
			Led_TurnOn(LedId);
			SysTick_StartTimer(Time_On);
			GPIO_PORTF_DATA_R = 0x02; // turn on red LED
			Led_Status = LED_STATUS_ON;
		}

		while (Led_Status == LED_STATUS_ON)
			;

		if (Led_Status != LED_STATUS_ON)
		{
			Led_TurnOff(LedId);
			SysTick_StartTimer(Time_OFF);
			GPIO_PORTF_DATA_R = 0x00; // turn off red LED
			Led_Status = LED_STATUS_OFF;
		}

		while (Led_Status == LED_STATUS_OFF)
			;
		return;
	}
	}
}

/******************************************************************************
 * \Syntax             : void Blinking_Stop(void)
 * \Description        : Function to stop Blinking Led.
 * \Sync\Async         : Synchronous.
 * \Reentrancy         : NonReentrant.
 * \Parameters (in)    : None.
 * \Parameters (inout) : None.
 * \Parameters (out)   : None.
 * \Return value:      : None.
 *******************************************************************************/
void Blinking_Stop(void)
{
	/* Stop Blinking*/
	return;
}


/******************************************************************************
 * \Syntax             : void Blinking_Change_Status(void)
 * \Description        : Function to change status of Blinking Led.
 * \Sync\Async         : Synchronous.
 * \Reentrancy         : NonReentrant.
 * \Parameters (in)    : None.
 * \Parameters (inout) : None.
 * \Parameters (out)   : None.
 * \Return value:      : None.
 *******************************************************************************/
void Blinking_Change_Status(void)
{
	if (Led_Status == LED_STATUS_ON)
	{
		Led_Status=LED_STATUS_OFF;
	}
	else
	{
		Led_Status=LED_STATUS_ON;
	}
}

// Subroutine to initialize port F pins for input and output
// PF4 and PF0 are input SW1 and SW2 respectively
// PF3,PF2,PF1 are outputs to the LED
void PortF_Init(void) {
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= 0x00000020;     // 1) F clock
	delay = SYSCTL_RCGC2_R;           // reading register adds a delay   
	GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0  
	GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0       
	GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog function
	GPIO_PORTF_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
	GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4,PF0 input, PF3,PF2,PF1 output   
	GPIO_PORTF_AFSEL_R = 0x00;        // 6) no alternate function
	GPIO_PORTF_PUR_R = 0x11;          // enable pullup resistors on PF4,PF0       
	GPIO_PORTF_DEN_R = 0x1F;          // 7) enable digital pins PF4-PF0        
}
/**********************************************************************************************************************
 *  END OF FILE: Blink.c
 *********************************************************************************************************************/
