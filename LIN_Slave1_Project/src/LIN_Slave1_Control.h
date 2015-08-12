/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %LIN_Slave1_Control.h%
* Instance:         x
* %version:         1 %
* %created_by:      Michele Balbi %
* %date_created:    August 12 2015 %
*=============================================================================*/
/* DESCRIPTION : Header file for Slave 1 Control module.				      */
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

#ifndef LIN_SLAVE1_CONTROL_H                               /* To avoid double inclusion */
#define LIN_SLAVE1_CONTROL_H

/* Includes */
/* -------- */
#include "conti_typedefs.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */

typedef enum{
	SLAVE_ENABLED,
	SLAVE_DISABLED
}E_LIN_SLAVE_STATE;

typedef enum{
	cmd_NONE,
	cmd_LED_on,
	cmd_LED_off,
	cmd_LED_toggling,
	cmd_disable_slv,
	cmd_enable_slv
}E_LIN_CMD;


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
extern void Slave1_Enable();
extern void Slave1_Disable();
extern T_UBYTE Slave1_GetStatus();
extern void Slave1_SetState();

/* Functions macros */


/* Exported defines */


#endif


