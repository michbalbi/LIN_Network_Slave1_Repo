/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %Ind_PeriodicTasks.c%
* Instance:         x
* %version:         1 %
* %created_by:      Michele Balbi %
* %date_created:    August 12 2015 %
*=============================================================================*/
/* DESCRIPTION : C source for LED Indicator functions.                        */
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
/* 	Creation of periodic functions for 1.25, 5 and 10 MS.    	   	    	  */
/*============================================================================*/

/* Includes */
/* -------- */
#include "Ind_PeriodicTasks.h"
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

T_UBYTE yeah=0;

/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	
 *  Description          :
 *  Parameters           :  
 *  Return               :
 *  Critical/explanation :    
 **************************************************************/
/*void Ind_CheckForCommand(){
	if(rub_received_data!=0){
	
	}
}*/

/**************************************************************
 *  Name                 :	
 *  Description          :
 *  Parameters           :  
 *  Return               :
 *  Critical/explanation :    
 **************************************************************/
void Ind_SetState(){
	static T_UBYTE lub_counter=0;
	
	lub_counter++;
	
	if(lub_counter==100){
		switch(re_LEDState){
			case LED_OFF:
				Ind_TurnOff();
				break;
			
			case LED_ON:
				Ind_TurnOn();
				break;
			
			case LED_TOGGLING:
				LED_TOGGLE(LED1);
				break;
			
			default:
				break;
		}
		lub_counter=0;
	}
}
