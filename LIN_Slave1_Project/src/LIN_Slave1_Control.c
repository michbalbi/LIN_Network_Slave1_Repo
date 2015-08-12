/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %LIN_Slave1_Control.c%
* Instance:         x
* %version:         1 %
* %created_by:      Michele Balbi %
* %date_created:    August 12 2015 %
*=============================================================================*/
/* DESCRIPTION : C source for LIN Slave1 functions.                           */
/*============================================================================*/
/* FUNCTION COMMENT : 														  */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 12/08/2015  |                               | Michele Balbi    */
/* 	Creation of various functions.                        					  */
/*============================================================================*/

/* Includes */
/* -------- */
#include "LIN_Slave1_Control.h"
#include "Ind_Control.h"
#include "MPC5606B_LIN_lib_IntHandlers.h"
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
E_LIN_SLAVE_STATE re_Slave1State = SLAVE_ENABLED;

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
 *  Name                 :	
 *  Description          :
 *  Parameters           :  
 *  Return               :
 *  Critical/explanation :    
 **************************************************************/
void Slave1_Enable(){
	
}

/**************************************************************
 *  Name                 :	
 *  Description          :
 *  Parameters           :  
 *  Return               :
 *  Critical/explanation :    
 **************************************************************/
void Slave1_Disable(){
	
}

/**************************************************************
 *  Name                 :	
 *  Description          :
 *  Parameters           :  
 *  Return               :
 *  Critical/explanation :    
 **************************************************************/
void Slave1_SetState(){
	switch(re_Slave1State){
		case SLAVE_DISABLED:
			Slave1_Disable();
			break;
		
		case SLAVE_ENABLED:
			Slave1_Enable();
			break;
		
		default:
			break;
	}
}

/**************************************************************
 *  Name                 :	
 *  Description          :
 *  Parameters           :  
 *  Return               :
 *  Critical/explanation :    
 **************************************************************/
void Slave1_CheckForCommand(){

	switch((E_LIN_CMD)rub_received_data){
		case cmd_NONE:
			break;
			
		case cmd_LED_on:
			re_LEDState = LED_ON;
			break;
		
		case cmd_LED_off:
			re_LEDState = LED_OFF;
			break;
			
		case cmd_LED_toggling:
			re_LEDState = LED_TOGGLING;
			break;
		
		case cmd_enable_slv:
			re_Slave1State = SLAVE_ENABLED;
			break;
			
		case cmd_disable_slv:
			re_Slave1State = SLAVE_DISABLED;
			break;
		
		default:
			break;
	
	}
	/*if((E_LIN_CMD)rub_received_data!=cmd_NONE){
		if((E_LIN_CMD)rub_received_data==cmd_LED_on){
			Ind_SetState(LED_ON);
		}
	}*/
}

/**************************************************************
 *  Name                 :	
 *  Description          :
 *  Parameters           :  
 *  Return               :
 *  Critical/explanation :    
 **************************************************************/
T_UBYTE Slave1_GetStatus(){
	return (T_UBYTE)re_Slave1State;
}
