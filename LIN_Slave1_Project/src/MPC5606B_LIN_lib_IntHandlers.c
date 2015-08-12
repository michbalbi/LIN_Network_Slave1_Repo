/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %MPC5606B_LIN_lib.c%
* Instance:         1
* %version:         1 %
* %created_by:      Michele Balbi %
* %date_created:    August 12 2015 %
*=============================================================================*/
/* DESCRIPTION : C file for LIN Interrupt Handlers.                           */
/*============================================================================*/
/* FUNCTION COMMENT :                                                         */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 12/08/2015  |                               | Michele Balbi    */
/* 	First Draft.                                                              */
/*============================================================================*/

/* Includes */
/* -------- */
#include "MPC5606B.h"
#include "MPC5606B_LIN_lib_IntHandlers.h"
#include "MPC5606B_LIN_lib.h"

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
 *  Name                 :	LIN_Master_SendData
 *  Description          :	
 *  Parameters           :  
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
T_UBYTE rub_received_data;
T_UBYTE transmitting;

void LIN2_Error(void){
	LINFLEX_2.LINESR.B.BEF=1;
}

/**************************************************************
 *  Name                 :	LIN_Master_SendData
 *  Description          :	
 *  Parameters           :  
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
void LIN0_TXCompleted(void){
	T_UBYTE lub_LED_status;
	T_UBYTE lub_slave_status;
	T_ULONG lul_packed_data;
	
	if(LINFLEX_0.LINSR.B.DTF==1){
		
		LINFLEX_0.LINSR.B.DTF=1;
	}else{
		switch(LINFLEX_0.IFMI.B.IFMI){
				
			case 3:
				lub_LED_status=Ind_GetStatus();
				lub_slave_status=Slave1_GetStatus();
				lul_packed_data = ((lub_slave_status<<8)|lub_LED_status);
				
				LIN_LoadBufferData(LIN0, (T_ULONG)0, (T_ULONG)lul_packed_data);
				LINFLEX_0.LINCR2.B.DTRQ=1;
				break;
				
			case 4:
				/* 0x00004C4D4D4205 */
				LIN_LoadBufferData(LIN0, (T_ULONG)0x0000004C, (T_ULONG)0x4D4D4205);
				LINFLEX_0.LINCR2.B.DTRQ=1;
				break;
			
			default:
				break;
		}
	}
}

/**************************************************************
 *  Name                 :	LIN_Master_SendData
 *  Description          :	
 *  Parameters           :  
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
void LIN0_RXCompleted(void){
	if(LINFLEX_0.LINSR.B.RMB==1){
	
		switch(LINFLEX_0.IFMI.B.IFMI){
		
			case 1:
				rub_received_data=LIN_GetBufferData_1Byte(LIN0);
				transmitting=0;
				break;
				
			case 2:
				rub_received_data=LIN_GetBufferData_1Byte(LIN0);
				transmitting=0;
				break;
			
			default:
				break;
		}
	
		LINFLEX_0.LINSR.B.RMB=1;
		LINFLEX_0.LINSR.B.DRF=1;
	}else{
	
	}
}

/**************************************************************
 *  Name                 :	LIN_Master_SendData
 *  Description          :	
 *  Parameters           :  
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
void LIN2_TXCompleted(void){
	if(LINFLEX_2.LINSR.B.DTF==1){
		
		LINFLEX_2.LINSR.B.DTF=1;
	}
}

/**************************************************************
 *  Name                 :	LIN_Master_SendData
 *  Description          :	
 *  Parameters           :  
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
void LIN2_RXCompleted(void){
	if(LINFLEX_2.LINSR.B.RMB==1){
	
		transmitting=0;
		LINFLEX_2.LINSR.B.RMB=1;
		LINFLEX_2.LINSR.B.DRF=1;
	}	
}
 
 