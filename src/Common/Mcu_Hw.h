/**************************************************************************************************
 *	FILE DESCRIPTION
 *	-----------------------------------------------------------------------------------------------
 *	       File:	Mcu_Hw.h
 *	     Module:
 *
 *	Description:
 *
 *
 *************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H
/**************************************************************************************************
 *	INCLUDES
 *************************************************************************************************/
#include "Std_Types.h"
 
/**************************************************************************************************
 *	GLOBAL DATA TYPES AND STRUCTURES
 *************************************************************************************************/

//Nested Vectored Interrupt Controller (NVIC) Registers
typedef struct
{
     uint32 EN[5];
     uint32 reserved0[27];
     uint32 DIS[5];
     uint32 reserved1[27];
     uint32 PEND[5];
     uint32 reserved2[27];
     uint32 UNPEND[5];
     uint32 reserved3[27];
     uint32 ACTIVE[5];
     uint32 reserved4[59];

     union
     {
     uint32 R;
        struct             //the diadvantage of this way is that it will act in a wrong way 
        {                           //if the compiler was Big Endian
            uint32          :5;     // ":" it is used to give the var a bit field
            uint32 INTA     :3;
            uint32          :5;
            uint32 INTB     :3;
            uint32          :5;
            uint32 INTC     :3;
            uint32          :5;
            uint32 INTD     :3;
        }BF;
     }PRI[35];

     uint32 reserved5[669];
     uint32 SWIDETRIG;
} NVIC_Registers;


// SCB registers
typedef struct
{
    uint32 CPUID;

    union
    {
        uint32 R;
        struct             //the diadvantage of this way is that it will act in a wrong way 
        {                           //if the compiler was Big Endian
            uint32 VECACT   :8;     // ":" it is used to give the var a bit field
            uint32          :3;
            uint32 RETBASE  :1;
            uint32 VECPEND  :8;
            uint32          :2;
            uint32 ISRPEND  :1;
            uint32 ISRPRE   :1;
            uint32          :1;
            uint32 PENDSTCLR:1;
            uint32 PENDSTSET:1;
            uint32 UNPENDSV :1;
            uint32 PENDSV   :1;
            uint32          :2;
            uint32 NMISET   :1;
        }BF;
    }INTCTRL;

    uint32 VTABLE;

    union
    {
        uint32 R;
        struct             //the diadvantage of this way is that it will act in a wrong way 
        {                           //if the compiler was Big Endian
            uint32 VECTRESET    :1;     // ":" it is used to give the var a bit field
            uint32 VECTCLRACT   :1;
            uint32 SYSRESREQ    :1;
            uint32              :5;
            uint32 PRIGROUP     :3;
            uint32              :4;
            uint32 ENDIANESS    :1;
            uint32 VECTKEY      :16;
        }BF;
    }APINT;

    uint32 SYSCTRL;
    uint32 CFGCTRL;
    uint32 SYSPRI1;
    uint32 SYSPRI2;
    uint32 SYSPRI3;
    uint32 SYSHNDCTRL;
    uint32 FAULTSTAT;
    uint32 HFAULTSTAT;
    uint32 reserved2;
    uint32 MMADDR;
    uint32 FAULTADDR;
}SCB_Registers;




//GPIO
typedef struct
{
    uint32 GPIODATA[256];
    uint32 GPIODIR;
    uint32 GPIOIS;
    uint32 GPIOIBE;
    uint32 GPIOIEV;
    uint32 GPIOIM;
    uint32 GPIORIS;
    uint32 GPIOMIS;
    uint32 GPIOICR;
    uint32 GPIOAFSEL;
    uint32 reserved0[55];
    uint32 GPIODR2R;
    uint32 GPIODR4R;
    uint32 GPIODR8R;
    uint32 GPIOODR;
    uint32 GPIOPUR;
    uint32 GPIOPDR;
    uint32 GPIOSLR;
    uint32 GPIODEN;
    uint32 GPIOLOCK;
    uint32 GPIOCR;
    uint32 GPIOAMSEL;
    uint32 GPIOPCTL;
    uint32 GPIOADCCTL;
    uint32 GPIODMACTL;
    uint32 reserved1[678];
    uint32 GPIOPeriphID4;
    uint32 GPIOPeriphID5;
    uint32 GPIOPeriphID6;
    uint32 GPIOPeriphID7;
    uint32 GPIOPeriphID0;
    uint32 GPIOPeriphID1;
    uint32 GPIOPeriphID2;
    uint32 GPIOPeriphID3;
    uint32 GPIOPCellID0;
    uint32 GPIOPCellID1;
    uint32 GPIOPCellID2;
    uint32 GPIOPCellID3;

}GPIO_Registers;

// General Prpose TIMERs registers
typedef struct
{
    uint32 GPTMCFG;
    uint32 GPTMTAMR;
    uint32 GPTMTBMR;
    uint32 GPTMCTL;
    uint32 GPTMSYNC;
    uint32 reserved1;
    uint32 GPTMIMR;
    uint32 GPTMRIS;
    uint32 GPTMMIS;
    uint32 GPTMICR;
    uint32 GPTMTAILR;
    uint32 GPTMTBILR;
    uint32 GPTMTAMATCHR;
    uint32 GPTMTAMBTCHR;
    uint32 GPTMTAPR;
    uint32 GPTMTBPR;
    uint32 GPTMTAPMR;
    uint32 GPTMTBPMR;
    uint32 GPTMTAR;
    uint32 GPTMTBR;
    uint32 GPTMTAV;
    uint32 GPTMTBV;
    uint32 GPTMTCPD;
    uint32 GPTMTAPS;
    uint32 GPTMTBPS;
    uint32 GPTMTAPV;
    uint32 GPTMTBPV;
    uint32 reserved2[918];
    uint32 GPTMPP;

} Gpt_Registers;

typedef struct
{
    uint32 reserved0[383];
    uint32 RCGCWD;
    uint32 RCGCTIMER;
    uint32 RCGCGPIO;
    uint32 RCGCDMA;
    uint32 reserved1;
    uint32 RCGCHIB;
    uint32 RCGCUART;
    uint32 RCGCSSI;
    uint32 RCGCI2C;
    uint32 reserved2;
    uint32 RCGCUSB;
    uint32 reserved3[2];
    uint32 RCGCCAN;
    uint32 RCGCADC;
    uint32 RCGCACMP;
    uint32 RCGCPWM;
    uint32 RCGCQEI;
    uint32 reserved4[4];
    uint32 RCGCEEPROM;
    uint32 RCGCWTIMER;
    uint32 reserved5[232];
    uint32 PRWD;
    uint32 PRTIMER;
    uint32 PRGPIO;
    uint32 PRDMA;
    uint32 reserved6;
    uint32 PRHIB;
    uint32 PRUART;
    uint32 PRSSI;
    uint32 PRI2C;
    uint32 reserved7;
    uint32 PRUSB;
    uint32 reserved8[2];
    uint32 PRCAN;
    uint32 PRADC;
    uint32 PRACMP;
    uint32 PRPWM;
    uint32 PRQEI;
    uint32 reserved9[4];
    uint32 PREEPROM;
    uint32 PRWTIMER;

} SysCtrl_Registers;
/**************************************************************************************************
 *	GLOBAL CONSTANT MACROS
 *************************************************************************************************/



 #define CORTEXM4_PERI_BASE_ADDRESS     0xE000E000u
 #define NVIC_OFFSET                    0x100u
 #define SCB_OFFSET                     0xD00u

 #define GPIO_COMMON_BASE               0x40000000u
 #define GPIO_A_BASE                    0x40004000u
 #define GPIO_B_BASE                    0x40005000u
 #define GPIO_C_BASE                    0x40006000u
 #define GPIO_D_BASE                    0x40007000u
 #define GPIO_E_BASE                    0x40024000u
 #define GPIO_F_BASE                    0x40025000u

 // GPT Base addresses
 #define TIMER0_BASE                    0x40030000u
 #define TIMER1_BASE                    0x40031000u
 #define TIMER2_BASE                    0x40032000u
 #define TIMER3_BASE                    0x40033000u
 #define TIMER4_BASE                    0x40035000u
 #define TIMER5_BASE                    0x40035000u
 
 #define WIDETIMER0_BASE                0x40036000u
 #define WIDETIMER1_BASE                0x40037000u
 #define WIDETIMER2_BASE                0x4004C000u
 #define WIDETIMER3_BASE                0x4004D000u
 #define WIDETIMER4_BASE                0x4004E000u
 #define WIDETIMER5_BASE                0x4004F000u

//SysCtrl
 #define SysCtrl_BASE                   0x400FE000u
 #define RCGC_OFFSET                    0x600u
 #define PR_OFFSET                      0xA00u



 //Nested Vectored Interrupt Controller (NVIC) Registers
 #define NVIC                           ((volatile NVIC_Registers *)(CORTEXM4_PERI_BASE_ADDRESS + NVIC_OFFSET))

//  #define EN0                            *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
//  #define EN1                            *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x104))
//  #define EN2                            *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x108))
//  #define EN3                            *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x10C))
//  #define EN4                            *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x110))

//  #define DIS0                           *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x180))
//  #define DIS1                           *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x184))
//  #define DIS2                           *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x188))
//  #define DIS3                           *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x18C))
//  #define DIS4                           *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x190))

//  #define PEND0                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x200))
//  #define PEND1                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x204))
//  #define PEND2                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x208))
//  #define PEND3                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x20C))
//  #define PEND4                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x210))

//  #define UNPEND0                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x280))
//  #define UNPEND1                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x284))
//  #define UNPEND2                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x288))
//  #define UNPEND3                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x28C))
//  #define UNPEND4                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x290))
 
//  #define ACTIVE0                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x300))
//  #define ACTIVE1                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x304))
//  #define ACTIVE2                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x308))
//  #define ACTIVE3                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x30C))
//  #define ACTIVE4                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x310))
  
//  #define PRI0                           *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x400))
//  #define PRI1                           *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x404))
//  #define PRI2                           *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x408))
//  #define PRI3                           *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x40C))
//  #define PRI4                           *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x410))
//  #define PRI5                           *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x414))
//  #define PRI6                           *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x418))
//  #define PRI7                           *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x41C))
//  #define PRI8                           *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x420))
//  #define PRI9                           *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x424))
//  #define PRI10                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x428))
//  #define PRI11                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x42C))
//  #define PRI12                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x430))
//  #define PRI13                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x434))
//  #define PRI14                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x438))
//  #define PRI15                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x43C))
//  #define PRI16                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x440))
//  #define PRI17                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x444))
//  #define PRI18                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x448))
//  #define PRI19                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x44C))
//  #define PRI20                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x450))
//  #define PRI21                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x454))
//  #define PRI22                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x458))
//  #define PRI23                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x45C))
//  #define PRI24                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x460))
//  #define PRI25                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x464))
//  #define PRI26                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x468))
//  #define PRI27                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x46C))
//  #define PRI28                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x470))
//  #define PRI29                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x474))
//  #define PRI30                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x478))
//  #define PRI31                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x47C))
//  #define PRI32                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x480))
//  #define PRI33                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x484))
//  #define PRI34                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x488))

//  #define SWIDETRIG                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xF00))
 
 //System Control Block (SCB) Registers
 #define SCB                            ((volatile SCB_Registers *)(CORTEXM4_PERI_BASE_ADDRESS + SCB_OFFSET))

//  #define ACTLR                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x008))
//  #define CPUID                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD00))
//  #define INTCTRL                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
//  #define VTABLE                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD08))
//  #define APINT                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
//  #define SYSCTRL                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD10))
//  #define CFGCTRL                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD14))
//  #define SYSPRI1                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD18))
//  #define SYSPRI2                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD1C))
//  #define SYSPRI3                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD20))
//  #define SYSHNDCTRL                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD24))
//  #define FAULTSTAT                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD28))
//  #define HFAULTSTAT                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD2C))
//  #define MMADDR                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD34))
//  #define FAULTADDR                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD38))

//GPIO Register
//GPIO
 #define GPIO(GPIO_BASE)                ((volatile GPIO_Registers *)(GPIO_BASE))

 #define GPIOA                          ((volatile GPIO_Registers *)(GPIO_A_BASE))
 #define GPIOB                          ((volatile GPIO_Registers *)(GPIO_B_BASE))
 #define GPIOC                          ((volatile GPIO_Registers *)(GPIO_C_BASE))
 #define GPIOD                          ((volatile GPIO_Registers *)(GPIO_D_BASE))
 #define GPIOE                          ((volatile GPIO_Registers *)(GPIO_E_BASE))
 #define GPIOF                          ((volatile GPIO_Registers *)(GPIO_F_BASE))

//General Purpose TIMERs
 #define TIMER(TIMER_BASE)              ((volatile Gpt_Registers *)(TIMER_BASE))

 #define TIMER0                         ((volatile Gpt_Registers *)(TIMER0_BASE))
 #define TIMER1                         ((volatile Gpt_Registers *)(TIMER1_BASE))
 #define TIMER2                         ((volatile Gpt_Registers *)(TIMER2_BASE))
 #define TIMER3                         ((volatile Gpt_Registers *)(TIMER3_BASE))
 #define TIMER4                         ((volatile Gpt_Registers *)(TIMER4_BASE))
 #define TIMER5                         ((volatile Gpt_Registers *)(TIMER5_BASE))

 #define WIDETIMER(WIDETIMER_BASE)      ((volatile Gpt_Registers *)(WIDETIMER_BASE))

 #define WIDETIMER0                     ((volatile Gpt_Registers *)(WIDETIMER0_BASE))
 #define WIDETIMER1                     ((volatile Gpt_Registers *)(WIDETIMER1_BASE))
 #define WIDETIMER2                     ((volatile Gpt_Registers *)(WIDETIMER2_BASE))
 #define WIDETIMER3                     ((volatile Gpt_Registers *)(WIDETIMER3_BASE))
 #define WIDETIMER4                     ((volatile Gpt_Registers *)(WIDETIMER4_BASE))
 #define WIDETIMER5                     ((volatile Gpt_Registers *)(WIDETIMER5_BASE))

//SysCtrl
 #define SysCtrl                        ((volatile SysCtrl_Registers *)(SysCtrl_BASE))


/**************************************************************************************************
 *	GLOBAL FUNCTION MACROS
 *************************************************************************************************/


 

 #endif    /* MCU_HW_H */
 
/**************************************************************************************************
 *	END OF FILE:	Mcu_Hw.h
 *************************************************************************************************/