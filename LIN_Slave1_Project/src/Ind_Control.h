/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %Ind_Control.h%
* Instance:         x
* %version:         1 %
* %created_by:      Michele Balbi %
* %date_created:    August 12 2015 %
*=============================================================================*/
/* DESCRIPTION : Header file for Indicator Control module.				      */
/*============================================================================*/
/* FUNCTION COMMENT :   										              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 12/08/2015  |                               | Michele Balbi    */
/* First Draft 																  */
/*============================================================================*/

#ifndef IND_CONTROL_H                               /* To avoid double inclusion */
#define IND_CONTROL_H

/* Includes */
/* -------- */
#include "conti_typedefs.h"

/* Exported types and constants */
/* ---------------------------- */



/* Types definition */
/* typedef */

typedef enum{
	LED_OFF,
	LED_ON,
	LED_TOGGLING
}E_LED_STAT;

extern E_LED_STAT re_LEDState;

/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTES */


/* WORDS */


/* LONGS and STRUCTURES */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* Functions prototypes */
extern void Ind_TurnOn();
extern void Ind_TurnOff();
extern T_UBYTE Ind_GetStatus();
/*extern void Ind_SetState(E_LED_STAT le_state);*/

/* Functions macros */


/* Exported defines */
#define INDICATOR LED1

#endif


