/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %Ind_Control.c%
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
/* 	Creation of Ind_TurnOn(), Ind_TurnOff() functions.                        */
/*============================================================================*/

/* Includes */
/* -------- */
#include "Ind_Control.h"
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
E_LED_STAT re_LEDState = LED_TOGGLING;

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
void Ind_TurnOn(){
	LED_ON(LED1);
}

/**************************************************************
 *  Name                 :	
 *  Description          :
 *  Parameters           :  
 *  Return               :
 *  Critical/explanation :    
 **************************************************************/
void Ind_TurnOff(){
	LED_OFF(LED1);
}

/**************************************************************
 *  Name                 :	
 *  Description          :
 *  Parameters           :  
 *  Return               :
 *  Critical/explanation :    
 **************************************************************/
/*void Ind_SetState(E_LED_STAT le_state){

}*/

/**************************************************************
 *  Name                 :	
 *  Description          :
 *  Parameters           :  
 *  Return               :
 *  Critical/explanation :    
 **************************************************************/
T_UBYTE Ind_GetStatus(){
	return (T_UBYTE)re_LEDState;
}
