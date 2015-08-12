/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %MCP5606B_LIN_IntHandlers.h%
* Instance:         1
* %version:         1 %
* %created_by:      Michele Balbi %
* %date_created:    August 12 2015 %
*=============================================================================*/
/* DESCRIPTION : Header file for LIN initialization functions.		      	  */
/*============================================================================*/
/* FUNCTION COMMENT :                                                         */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 12/08/2015  |                               | Michele Balbi    */
/* Creation of file with functions. 										  */
/*============================================================================*/

#ifndef MPC5606B_LIN_INTHANDLERS_H
#define MPC5606B_LIN_INTHANDLERS_H

/* Includes */
/* -------- */
#include "MPC5606B.h"
#include "conti_typedefs.h"

/* Exported types and constants */
/* ---------------------------- */

extern T_UBYTE rub_received_data;

/* Types definition */
/* typedef */


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
extern void LIN2_Error(void);
extern void LIN0_TXCompleted(void);
extern void LIN0_RXCompleted(void);
extern void LIN2_TXCompleted(void);
extern void LIN2_RXCompleted(void);


/* Functions macros */


/* Exported defines */


#endif
