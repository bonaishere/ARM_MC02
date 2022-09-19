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
#include "IntCtrl.h"
 
/**************************************************************************************************
 *	LOCAL MACROS CONSTANT\FUNCTION
 *************************************************************************************************/

/**************************************************************************************************
 *	LOCAL DATA
 *************************************************************************************************/
 
/**************************************************************************************************
 *	GLOBAL DATA
 *************************************************************************************************/
 
/**************************************************************************************************
 *	LOCAL FUNCTION PROTOTYPES
 *************************************************************************************************/
 void NVIC_SetPRIx(const IntCtrl_ConfigType *ConfigPtr);
 void NVIC_SetENx(const IntCtrl_ConfigType *ConfigPtr);
/**************************************************************************************************
 *	LOCAL FUNCTIONS
 *************************************************************************************************/
 
/**************************************************************************************************
 *	GLOBAL FUNCTIONS
 *************************************************************************************************/

/********************************************************************
 *	\Syntax				: void IntCtrl_Init(void)
 *	\Description		: Initialize NVIC\SCB Module by passing the
 *                        the configuration into NVIC\SCB registers
 *	\Sync\Async			: Synchronous
 *	\Reentrancy			: None Reentrant
 *	\Parameters (in)	: None
 *	\Parameters (out)	: None
 *	\Return value		: None
 *
 *******************************************************************/
 void IntCtrl_Init(void)
 {

  //  /*Enabling FAULTMASK and PRIMASK using MSR or CPS*/
  //  __asm("CPSIE f");
  //  __asm("CPSIE i");

  //  SCB->CFGCTRL |= 0x10;        /*Enable SWTRIG by setting MAINPEND (bit 1)*/

  //  NVIC->SWIDETRIG |= 0x00000001; /*This field holds the interrupt ID 
  //                                   of the required SGI. For example, a 
  //                                   value of 0x3 generates an interrupt on IRQ3*/
   
   /*onfigure Grouping\Subgrouping system in APINT register in SCB*/
   SCB->APINT.BF.VECTKEY = 0xFA05;
   SCB->APINT.BF.PRIGROUP = PRIGROUPING;

  for (uint8 i = 0; i < ACTIVATED_INT_NUM; i++)
  {
    /*Assign Group\Subgroup priority in NVIC_PRIx and SCB_SYSPRIx registers*/
    NVIC_SetPRIx(&intCtrl_Cofig[i]);

    /*Enable\Disable based on your configuration in NVIC_ENx and SCB_Sys register*/
    NVIC_SetENx(&intCtrl_Cofig[i]);

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
 void NVIC_SetPRIx(const IntCtrl_ConfigType *ConfigPtr)
 {
    uint32 bitOffset;
    uint32 offset;
    
    	bitOffset = ((((ConfigPtr->vectorName) % 4) * 8) +5) ;
		offset= (ConfigPtr->vectorName) / 4;

		#if		(PRIGROUPING == XXX)
    		NVIC->PRI[(ConfigPtr->vectorName) / 4].R |= (ConfigPtr->groupPriority << bitOffset);
		#elif	(PRIGROUPING == XXY)
    		NVIC->PRI[(ConfigPtr->vectorName) / 4].R |= (ConfigPtr->groupPriority << (bitOffset+1));
    		NVIC->PRI[(ConfigPtr->vectorName) / 4].R |= (ConfigPtr->subGroupPriority << bitOffset);
    	#elif	(PRIGROUPING == XYY)	
			NVIC->PRI[(ConfigPtr->vectorName) / 4].R |= (ConfigPtr->groupPriority << (bitOffset+2));
			NVIC->PRI[(ConfigPtr->vectorName) / 4].R |= (ConfigPtr->subGroupPriority << bitOffset);
   		#elif	(PRIGROUPING == YYY)
    		NVIC->PRI[(ConfigPtr->vectorName) / 4].R |= (ConfigPtr->subGroupPriority << bitOffset);
    	#endif
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
 void NVIC_SetENx(const IntCtrl_ConfigType *ConfigPtr)
 {
	uint32 bitOffset;

	bitOffset = (ConfigPtr->vectorName %32) ;
	NVIC->EN[ConfigPtr->vectorName /32] |= ((1u) << bitOffset);
 }
/**************************************************************************************************
 *	END OF FILE: Std_Types.h
 *************************************************************************************************/