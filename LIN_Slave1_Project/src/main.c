/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %main.c%
* Instance:         1
* %version:         1 %
* %created_by:      Michele Balbi %
* %date_created:    July 13 2015 %
*=============================================================================*/
/* DESCRIPTION : C source template file for the scheduler application.        */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source code which prepares    */
/* the environment for the execution of the scheduler.                        */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/2015  |                               | Michele Balbi    */
/* 	First draft of the file. Includes used libraries.                         */
/*============================================================================*/

/* Includes */
/* -------- */
#include "MPC5606B.h"
#include "conti_typedefs.h"
#include "MPC5606B_GPIO_lib.h"
#include "MPC5606B_ClkInit.h"
#include "MPC5606B_INTERRUPTS_lib.h"
#include "MPC5606B_PIT_lib.h"
#include "MPC5606B_LIN_lib.h"
#include "MPC5606B_LIN_lib_IntHandlers.h"
#include "MemAlloc_Cfg.h"
#include "Sch.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */



/* Exported functions prototypes */
/* ----------------------------- */

/* Inline functions */
/* ---------------- */


/* Private functions */
/* ----------------- */


/* Exported functions */
/* ------------------ */



/* ---------------- MAIN FUNCTION -------------------------- */
/**************************************************************
 *  Name                 :	main
 *  Description          :
 *  Parameters           :	void
 *  Return               :	void
 *  Critical/explanation :  The main routine initializes the
 							peripherals used in this system.
 **************************************************************/
int main(void) {
	
	initModesAndClock();    /* Initialize mode entries and system clock */
	disableWatchdog();      /* Disable watchdog */
	initPeriClkGen();       /* Initialize peripheral clock generation for DSPIs */
	
	MemAllocInit(&MemAllocConfig);
	
	GPIO_Init();
	
	/* Interrupts init, SW Mode */
    INT_SW_VECTOR_MODE();
    
    Sch_Init(&cs_SchConfig);
    
    Ints_InstallIntHandler(&Sch_OSTick, PIT0_Vector, PRIORITY13);
    
    Ints_InstallIntHandler(&LIN0_TXCompleted, LINFLEX0_TX_Vector, PRIORITY10);
	Ints_InstallIntHandler(&LIN0_RXCompleted, LINFLEX0_RX_Vector, PRIORITY10);
	Ints_InstallIntHandler(&LIN2_TXCompleted, LINFLEX2_TX_Vector, PRIORITY10);
	Ints_InstallIntHandler(&LIN2_RXCompleted, LINFLEX2_RX_Vector, PRIORITY10);
	Ints_InstallIntHandler(&LIN2_Error, LINFLEX2_ERR_Vector, PRIORITY10);
    
    Ints_Init();
    /*INTC_InstallINTCInterruptHandler(&Sch_OSTick, PIT0_Vector, PRIORITY13);
    INT_LOWER_CPR(PRIORITY0);
    INTC_InitINTCInterrupts(); */
    
    LIN_Master_InitMode(LIN2);
 	LIN_Slave_InitMode();
 	
 	LIN_Master_Config(LIN2);
 	LIN_Slave_Config();
 	
 	LINFLEX_2.LINIER.B.DRIE = 1;	/* Data reception */
	LINFLEX_2.LINIER.B.DTIE = 1;	/* Data transmission */
	LINFLEX_2.LINIER.B.HRIE = 1;	/*  */	
	LINFLEX_2.LINIER.B.CEIE = 1;	/*  */	
	LINFLEX_2.LINIER.B.HEIE = 1;	/*  */
	LINFLEX_2.LINIER.B.BEIE = 1;	/*  */
	
	LINFLEX_0.LINIER.B.DRIE = 1;	/* Data reception */
	LINFLEX_0.LINIER.B.DTIE = 1;	/* Data transmission */
	LINFLEX_0.LINIER.B.HRIE = 1;	/*  */	
	LINFLEX_0.LINIER.B.CEIE = 1;	/*  */	
	LINFLEX_0.LINIER.B.HEIE = 1;	/*  */	
	LINFLEX_0.LINIER.B.BEIE = 0;	/*  */
 	
 	/* 4 filters are configured for the IDs 0xCF, 0x50, 0x20 and 0xF0 */
 	LIN_Slave_FiltersInit();
 	
 	LIN_NormalMode(LIN0);
 	LIN_NormalMode(LIN2);
  	
  	/*transmitting=1;
 	LIN_Master_SendData((T_UBYTE)0x10, (T_ULONG)0, (T_ULONG)0xAF, (T_UBYTE)1, CHKSUM_ENHACED);
 	while(transmitting==1){ 	};
 	transmitting=1;
 	LIN_Master_AskForData((T_UBYTE)0x30, (T_UBYTE)7, CHKSUM_ENHACED);*/
    
    Sch_Start(); 
	
	while(1) {
		; 
	} /* Execution shall never reach this for*/
	
	return 0;
}

