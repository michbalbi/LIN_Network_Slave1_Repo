/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %MCP5606B_LIN_lib.h%
* Instance:         1
* %version:         1 %
* %created_by:      Michele Balbi %
* %date_created:    July 7 2015 %
*=============================================================================*/
/* DESCRIPTION : Header file for LIN initialization functions.		      	  */
/*============================================================================*/
/* FUNCTION COMMENT :   Contains prototypes and necessary defines for LIN     */
/* 						init functions.           							  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 07/07/2015  |                               | Michele Balbi    */
/* Creation of file with functions. 										  */
/*============================================================================*/

#ifndef MPC5606B_LIN_LIB_H
#define MPC5606B_LIN_LIB_H

/* Includes */
/* -------- */
#include "MPC5606B.h"
#include "conti_typedefs.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */

typedef enum {
	LIN_DATA_RX,
	LIN_DATA_TX
}E_LIN_DATA_DIR;

typedef enum {
	LIN0,
	LIN1,
	LIN2,
	LIN3,
	LIN4,
	LIN5,
	LIN6,
	LIN7
}E_LIN_MODULE;

typedef enum {
	CHKSUM_ENHACED,
	CHKSUM_CLASSIC
}E_LIN_CHKSUM_TYPE;

typedef enum {
	BAUDRATE_2400BPS,
	BAUDRATE_9600BPS,
	BAUDRATE_19200BPS,
	BAUDRATE_115200BPS
}E_LIN_BAUDRATE;

typedef enum {
	LIN_FILTER0,
	LIN_FILTER1,
	LIN_FILTER2,
	LIN_FILTER3,
	LIN_FILTER4,
	LIN_FILTER5,
	LIN_FILTER6,
	LIN_FILTER7,
	LIN_FILTER8,
	LIN_FILTER9,
	LIN_FILTER10,
	LIN_FILTER11,
	LIN_FILTER12,
	LIN_FILTER13,
	LIN_FILTER14,
	LIN_FILTER15
}E_LIN_FILTER_NUMBER;

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
extern void LIN_Master_SendData(T_UBYTE lub_id, T_ULONG lul_MSData, T_ULONG lul_LSData, T_UBYTE lub_NumberOfBytes, E_LIN_CHKSUM_TYPE le_ccs);
extern void LIN_Master_AskForData(T_UBYTE lub_id, T_UBYTE lub_NumberOfBytes, E_LIN_CHKSUM_TYPE le_ccs);
extern T_UBYTE LIN_GetBufferData_1Byte(E_LIN_MODULE le_lin_module);
extern void LIN_LoadBufferData(E_LIN_MODULE le_lin_module, T_ULONG lul_MSData, T_ULONG lul_LSData);
extern void LIN_Slave_InitMode(void);
extern void LIN_Slave_Config(void);
extern void LIN_Master_InitMode(E_LIN_MODULE le_lin_module);
extern void LIN_Master_Config(E_LIN_MODULE le_lin_module);
extern void LIN_NormalMode(E_LIN_MODULE le_lin_module);
extern void LIN_Slave_FilterConfig(E_LIN_FILTER_NUMBER le_FilterNumber, T_UBYTE lub_id, T_UBYTE lub_NumberOfBytes, E_LIN_CHKSUM_TYPE le_ccs, E_LIN_DATA_DIR le_dir);
extern void LIN_Slave_FiltersInit(void);



/* Functions macros */


/* Exported defines */


#endif
