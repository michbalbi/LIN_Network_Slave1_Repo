/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %Sch_Tasks.c%
* Instance:         1
* %version:         1 %
* %created_by:      Michele Balbi %
* %date_created:    July 13 2015 %
*=============================================================================*/
/* DESCRIPTION : C source code for the scheduler's configured tasks.          */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source used in the scheduler's*/
/* tasks.                                                                     */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 13/07/2015  |                               | Michele Balbi    */
/* 	First draft.                                                              */
/*============================================================================*/

/* Includes */
/* -------- */
#include "conti_typedefs.h"
#include "Sch_Tasks.h"
#include "Ind_PeriodicTasks.h"
#include "MPC5606B_LIN_lib.h"
#include "LIN_Slave1_Control.h"
#include "MPC5606B_GPIO_lib.h"

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
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/

void Sch_Task_1p25MS(void){
	Slave1_CheckForCommand();
}

void Sch_Task_5MS(void){
	Ind_SetState();
	Slave1_SetState();
}

void Sch_Task_10MS(void){
	static T_UWORD i=0;
	static T_UBYTE stop_send=0;
	
	i++;
	
	if(i==300 && stop_send==0){
		LIN_Master_SendData((T_UBYTE)0x10, (T_ULONG)0, (T_ULONG)0x01, (T_UBYTE)1, CHKSUM_ENHACED);
	}
	
	if(i==600 && stop_send==0){
		LIN_Master_SendData((T_UBYTE)0x0F, (T_ULONG)0, (T_ULONG)0x02, (T_UBYTE)1, CHKSUM_ENHACED);	
	}
	
	if(i==900 && stop_send==0){
		LIN_Master_SendData((T_UBYTE)0x10, (T_ULONG)0, (T_ULONG)0x03, (T_UBYTE)1, CHKSUM_ENHACED);	
	}
	
	if(i==1200 && stop_send==0){
	/* LIN_Master_AskForData(T_UBYTE lub_id, T_UBYTE lub_NumberOfBytes, E_LIN_CHKSUM_TYPE le_ccs); */
		LIN_Master_AskForData((T_UBYTE)0x30, (T_UBYTE)7, CHKSUM_ENHACED);
		stop_send=1;
	}
	
}

void Sch_Task_40MS(void){
	
}