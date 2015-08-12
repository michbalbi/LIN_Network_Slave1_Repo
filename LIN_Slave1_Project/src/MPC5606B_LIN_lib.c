/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %MPC5606B_LIN_lib.c%
* Instance:         1
* %version:         1 %
* %created_by:      Michele Balbi %
* %date_created:    July 7 2015 %
*=============================================================================*/
/* DESCRIPTION : C file for LIN initialization.                               */
/*============================================================================*/
/* FUNCTION COMMENT : This file configures running modes and clock            */
/*                    initialization for the MCU and its peripherals.         */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 07/07/2015  |                               | Michele Balbi    */
/* 	First Draft.                                                              */
/*============================================================================*/

/* Includes */
/* -------- */
#include "MPC5606B.h"
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
 *  Description          :	Loads received data into master's buffer and
 							triggers header transmission. The master's slave
 							task then sends the loaded data.
 *  Parameters           :  T_UBYTE lub_id,    
 							T_ULONG lul_MSData,
 							T_ULONG lul_LSData,
 							T_UBYTE lub_NumberOfBytes,
 							E_LIN_CHKSUM_TYPE le_ccs
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
 void LIN_Master_SendData(T_UBYTE lub_id, T_ULONG lul_MSData, T_ULONG lul_LSData, T_UBYTE lub_NumberOfBytes, E_LIN_CHKSUM_TYPE le_ccs){
 							 
 	LINFLEX_2.BDRM.R = (T_ULONG)lul_MSData;  		  /* Load buffer data most significant bytes */
  	LINFLEX_2.BDRL.R = (T_ULONG)lul_LSData;  		  /* Load buffer data least significant bytes */
  	LINFLEX_2.BIDR.B.DFL = (lub_NumberOfBytes - 1);	  /* Bytes of data */
  	LINFLEX_2.BIDR.B.DIR = 1;						  /* TX Direction */
  	LINFLEX_2.BIDR.B.CCS = le_ccs;					  /* Checksum type */
  	LINFLEX_2.BIDR.B.ID = lub_id;
  	LINFLEX_2.LINCR2.B.HTRQ = 1;   					  /* Request header transmission */	
 }
 
 /**************************************************************
 *  Name                 :	LIN_Master_AskForData
 *  Description          :	Triggers header transmission. The master will
 							wait for a slave response.
 *  Parameters           :  T_UBYTE lub_id,  
 							T_UBYTE lub_NumberOfBytes,
 							E_LIN_CHKSUM_TYPE le_ccs
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
 void LIN_Master_AskForData(T_UBYTE lub_id, T_UBYTE lub_NumberOfBytes, E_LIN_CHKSUM_TYPE le_ccs){
 							 
  	LINFLEX_2.BIDR.B.DFL = (lub_NumberOfBytes - 1);	  /* Bytes of data */
  	LINFLEX_2.BIDR.B.DIR = 0;						  /* RX Direction */
  	LINFLEX_2.BIDR.B.ID = lub_id;
  	LINFLEX_2.BIDR.B.CCS = le_ccs;					  /* Checksum type */
  	LINFLEX_2.LINCR2.B.HTRQ = 1;   					  /* Request header transmission */	
 }
 
 /**************************************************************
 *  Name                 :	LIN_GetBufferData
 *  Description          :	
 *  Parameters           :  
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
 /*void LIN_GetBufferData(E_LIN_MODULE le_lin_module, T_UBYTE lub_NumberOfBytes){

 }*/
 
 /**************************************************************
 *  Name                 :	LIN_GetBufferData_1Byte
 *  Description          :	Reads 1 byte from data buffer from
 							corresponding LINFLEX module.
 *  Parameters           :  E_LIN_MODULE le_lin_module
 *  Return               :	T_UBYTE
 *  Critical/explanation :  yes
 **************************************************************/
 T_UBYTE LIN_GetBufferData_1Byte(E_LIN_MODULE le_lin_module){
	
	T_UBYTE lub_returned_data=0;
	
	switch(le_lin_module){
		case LIN0:
			lub_returned_data=(T_UBYTE)LINFLEX_0.BDRL.B.DATA0;
			break;
			
		case LIN1:
			lub_returned_data=(T_UBYTE)LINFLEX_1.BDRL.B.DATA0;
			break;
			
		case LIN2:
			lub_returned_data=(T_UBYTE)LINFLEX_2.BDRL.B.DATA0;
			break;
			
		case LIN3:
			lub_returned_data=(T_UBYTE)LINFLEX_3.BDRL.B.DATA0;
			break;
			
		case LIN4:
			lub_returned_data=(T_UBYTE)LINFLEX_4.BDRL.B.DATA0;
			break;
			
		case LIN5:
			lub_returned_data=(T_UBYTE)LINFLEX_5.BDRL.B.DATA0;
			break;
			
		case LIN6:
			lub_returned_data=(T_UBYTE)LINFLEX_6.BDRL.B.DATA0;
			break;
			
		case LIN7:
			lub_returned_data=(T_UBYTE)LINFLEX_7.BDRL.B.DATA0;
			break;
			
		default:
			break;
	}
	
	return lub_returned_data;
	
 }
 
 /**************************************************************
 *  Name                 :	LIN_LoadBufferData
 *  Description          :	Configures selected LINFLEX module
 							with the given baudrate.
 *  Parameters           :  E_LIN_MODULE le_lin_module, 
 							E_LIN_BAUDRATE le_lin_baudrate
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
 void LIN_SetBaudrate(E_LIN_MODULE le_lin_module, E_LIN_BAUDRATE le_lin_baudrate){
 							 
 	switch(le_lin_module){
		case LIN0:
			switch(le_lin_baudrate){
				case BAUDRATE_2400BPS:
					LINFLEX_0.LINFBRR.R = 11u;
					LINFLEX_0.LINIBRR.R = 1666u;
					break;
					
				case BAUDRATE_9600BPS:
					LINFLEX_0.LINFBRR.R = 11u;
					LINFLEX_0.LINIBRR.R = 416u;
					break;
					
				case BAUDRATE_19200BPS:
					LINFLEX_0.LINFBRR.R = 5u;
					LINFLEX_0.LINIBRR.R = 208u;
					break;
					
				case BAUDRATE_115200BPS:
					LINFLEX_0.LINFBRR.R = 12u;
					LINFLEX_0.LINIBRR.R = 34u;
					break;
					
				default:
					break;
			}
			break;
			
		case LIN1:
			switch(le_lin_baudrate){
				case BAUDRATE_2400BPS:
					LINFLEX_1.LINFBRR.R = 11u;
					LINFLEX_1.LINIBRR.R = 1666u;
					break;
					
				case BAUDRATE_9600BPS:
					LINFLEX_1.LINFBRR.R = 11u;
					LINFLEX_1.LINIBRR.R = 416u;
					break;
					
				case BAUDRATE_19200BPS:
					LINFLEX_1.LINFBRR.R = 5u;
					LINFLEX_1.LINIBRR.R = 208u;
					break;
					
				case BAUDRATE_115200BPS:
					LINFLEX_1.LINFBRR.R = 12u;
					LINFLEX_1.LINIBRR.R = 34u;
					break;
					
				default:
					break;
			}
			break;
			
		case LIN2:
			switch(le_lin_baudrate){
				case BAUDRATE_2400BPS:
					LINFLEX_2.LINFBRR.R = 11u;
					LINFLEX_2.LINIBRR.R = 1666u;
					break;
					
				case BAUDRATE_9600BPS:
					LINFLEX_2.LINFBRR.R = 11u;
					LINFLEX_2.LINIBRR.R = 416u;
					break;
					
				case BAUDRATE_19200BPS:
					LINFLEX_2.LINFBRR.R = 5u;
					LINFLEX_2.LINIBRR.R = 208u;
					break;
					
				case BAUDRATE_115200BPS:
					LINFLEX_2.LINFBRR.R = 12u;
					LINFLEX_2.LINIBRR.R = 34u;
					break;
					
				default:
					break;
			}
			break;
			
		case LIN3:
			switch(le_lin_baudrate){
				case BAUDRATE_2400BPS:
					LINFLEX_3.LINFBRR.R = 11u;
					LINFLEX_3.LINIBRR.R = 1666u;
					break;
					
				case BAUDRATE_9600BPS:
					LINFLEX_3.LINFBRR.R = 11u;
					LINFLEX_3.LINIBRR.R = 416u;
					break;
					
				case BAUDRATE_19200BPS:
					LINFLEX_3.LINFBRR.R = 5u;
					LINFLEX_3.LINIBRR.R = 208u;
					break;
					
				case BAUDRATE_115200BPS:
					LINFLEX_3.LINFBRR.R = 12u;
					LINFLEX_3.LINIBRR.R = 34u;
					break;
					
				default:
					break;
			}
			break;
			
		case LIN4:
			switch(le_lin_baudrate){
				case BAUDRATE_2400BPS:
					LINFLEX_4.LINFBRR.R = 11u;
					LINFLEX_4.LINIBRR.R = 1666u;
					break;
					
				case BAUDRATE_9600BPS:
					LINFLEX_4.LINFBRR.R = 11u;
					LINFLEX_4.LINIBRR.R = 416u;
					break;
					
				case BAUDRATE_19200BPS:
					LINFLEX_4.LINFBRR.R = 5u;
					LINFLEX_4.LINIBRR.R = 208u;
					break;
					
				case BAUDRATE_115200BPS:
					LINFLEX_4.LINFBRR.R = 12u;
					LINFLEX_4.LINIBRR.R = 34u;
					break;
					
				default:
					break;
			}
			break;
			
		case LIN5:
			switch(le_lin_baudrate){
				case BAUDRATE_2400BPS:
					LINFLEX_5.LINFBRR.R = 11u;
					LINFLEX_5.LINIBRR.R = 1666u;
					break;
					
				case BAUDRATE_9600BPS:
					LINFLEX_5.LINFBRR.R = 11u;
					LINFLEX_5.LINIBRR.R = 416u;
					break;
					
				case BAUDRATE_19200BPS:
					LINFLEX_5.LINFBRR.R = 5u;
					LINFLEX_5.LINIBRR.R = 208u;
					break;
					
				case BAUDRATE_115200BPS:
					LINFLEX_5.LINFBRR.R = 12u;
					LINFLEX_5.LINIBRR.R = 34u;
					break;
					
				default:
					break;
			}
			break;
			
		case LIN6:
			switch(le_lin_baudrate){
				case BAUDRATE_2400BPS:
					LINFLEX_6.LINFBRR.R = 11u;
					LINFLEX_6.LINIBRR.R = 1666u;
					break;
					
				case BAUDRATE_9600BPS:
					LINFLEX_6.LINFBRR.R = 11u;
					LINFLEX_6.LINIBRR.R = 416u;
					break;
					
				case BAUDRATE_19200BPS:
					LINFLEX_6.LINFBRR.R = 5u;
					LINFLEX_6.LINIBRR.R = 208u;
					break;
					
				case BAUDRATE_115200BPS:
					LINFLEX_6.LINFBRR.R = 12u;
					LINFLEX_6.LINIBRR.R = 34u;
					break;
					
				default:
					break;
			}
			break;
			
		case LIN7:
			switch(le_lin_baudrate){
				case BAUDRATE_2400BPS:
					LINFLEX_7.LINFBRR.R = 11u;
					LINFLEX_7.LINIBRR.R = 1666u;
					break;
					
				case BAUDRATE_9600BPS:
					LINFLEX_7.LINFBRR.R = 11u;
					LINFLEX_7.LINIBRR.R = 416u;
					break;
					
				case BAUDRATE_19200BPS:
					LINFLEX_7.LINFBRR.R = 5u;
					LINFLEX_7.LINIBRR.R = 208u;
					break;
					
				case BAUDRATE_115200BPS:
					LINFLEX_7.LINFBRR.R = 12u;
					LINFLEX_7.LINIBRR.R = 34u;
					break;
					
				default:
					break;
			}
			break;
			
		default:
			break;
	}	
 }
 
 /**************************************************************
 *  Name                 :	LIN_LoadBufferData
 *  Description          :	Loads given data into the selected
 							LINFLEX module's data buffer.
 *  Parameters           :  E_LIN_MODULE le_lin_module,
 							T_ULONG lul_MSData, 
 							T_ULONG lul_LSData
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
 void LIN_LoadBufferData(E_LIN_MODULE le_lin_module, T_ULONG lul_MSData, T_ULONG lul_LSData){
 							 
 	switch(le_lin_module){
		case LIN0:
			LINFLEX_0.BDRM.R=lul_MSData;
			LINFLEX_0.BDRL.R=lul_LSData;
			break;
			
		case LIN1:
			LINFLEX_1.BDRM.R=lul_MSData;
			LINFLEX_1.BDRL.R=lul_LSData;
			break;
			
		case LIN2:
			LINFLEX_2.BDRM.R=lul_MSData;
			LINFLEX_2.BDRL.R=lul_LSData;
			break;
			
		case LIN3:
			LINFLEX_3.BDRM.R=lul_MSData;
			LINFLEX_3.BDRL.R=lul_LSData;
			break;
			
		case LIN4:
			LINFLEX_4.BDRM.R=lul_MSData;
			LINFLEX_4.BDRL.R=lul_LSData;
			break;
			
		case LIN5:
			LINFLEX_5.BDRM.R=lul_MSData;
			LINFLEX_5.BDRL.R=lul_LSData;
			break;
			
		case LIN6:
			LINFLEX_6.BDRM.R=lul_MSData;
			LINFLEX_6.BDRL.R=lul_LSData;
			break;
			
		case LIN7:
			LINFLEX_7.BDRM.R=lul_MSData;
			LINFLEX_7.BDRL.R=lul_LSData;
			break;
			
		default:
			break;
	}	
 }
 
 /**************************************************************
 *  Name                 :	LIN_Slave_Init
 *  Description          :	
 *  Parameters           :  
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
 void LIN_Slave_InitMode(void){
	LINFLEX_0.LINCR1.B.SLEEP = 0;	/* Out of sleep mode */
 	LINFLEX_0.LINCR1.B.INIT = 1;	/* Init mode to modify config registers */
 }
 
 /**************************************************************
 *  Name                 :	LIN_Slave_Config
 *  Description          :	Configures LINFLEX0 as slave.
 *  Parameters           :  
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
 void LIN_Slave_Config(void){
 	LINFLEX_0.UARTCR.B.UART = 0;	/* LIN Mode */
 	LINFLEX_0.LINCR1.B.BF = 0;		/* Generate RX int even if no matched filters */
 	LINFLEX_0.LINCR1.B.MME = 0;		/* Slave Mode */
 	LINFLEX_0.LINCR1.B.SBDT = 0;	/* 11-bit tolerance break delimiter*/
 	LINFLEX_0.LINCR2.B.IOBE = 0;	/* Do not go to idle on bit error*/
 	LINFLEX_0.LINTCSR.B.IOT = 0;	/* Do not go to idle on timeout*/
 	LIN_SetBaudrate(LIN0,BAUDRATE_9600BPS);
 }
 
 /**************************************************************
 *  Name                 :	LIN_Master_Init
 *  Description          :	
 *  Parameters           :  
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
 void LIN_Master_InitMode(E_LIN_MODULE le_lin_module){
	
	switch(le_lin_module){
		case LIN0:
			LINFLEX_0.LINCR1.B.SLEEP = 0;	/* Out of sleep mode */
 			LINFLEX_0.LINCR1.B.INIT = 1;	/* Init mode to modify config registers */
			break;
			
		case LIN1:
			LINFLEX_1.LINCR1.B.SLEEP = 0;	/* Out of sleep mode */
 			LINFLEX_1.LINCR1.B.INIT = 1;	/* Init mode to modify config registers */
			break;
			
		case LIN2:
			LINFLEX_2.LINCR1.B.SLEEP = 0;	/* Out of sleep mode */
 			LINFLEX_2.LINCR1.B.INIT = 1;	/* Init mode to modify config registers */
			break;
			
		case LIN3:
			LINFLEX_3.LINCR1.B.SLEEP = 0;	/* Out of sleep mode */
 			LINFLEX_3.LINCR1.B.INIT = 1;	/* Init mode to modify config registers */
			break;
			
		case LIN4:
			LINFLEX_4.LINCR1.B.SLEEP = 0;	/* Out of sleep mode */
 			LINFLEX_4.LINCR1.B.INIT = 1;	/* Init mode to modify config registers */
 			break;
			
		case LIN5:
			LINFLEX_5.LINCR1.B.SLEEP = 0;	/* Out of sleep mode */
 			LINFLEX_5.LINCR1.B.INIT = 1;	/* Init mode to modify config registers */
			break;
			
		case LIN6:
			LINFLEX_6.LINCR1.B.SLEEP = 0;	/* Out of sleep mode */
 			LINFLEX_6.LINCR1.B.INIT = 1;	/* Init mode to modify config registers */
			break;
			
		case LIN7:
			LINFLEX_7.LINCR1.B.SLEEP = 0;	/* Out of sleep mode */
 			LINFLEX_7.LINCR1.B.INIT = 1;	/* Init mode to modify config registers */
			break;
			
		default:
			break;
	}
	
 }
 
 /**************************************************************
 *  Name                 :	LIN_Master_Init
 *  Description          :	
 *  Parameters           :  
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
 void LIN_Master_Config(E_LIN_MODULE le_lin_module){
	
	switch(le_lin_module){
		case LIN0:
			LINFLEX_0.UARTCR.B.UART = 0;	/* LIN Mode */
 			LINFLEX_0.LINCR1.B.BF = 0;		/* Generate RX int even if no matched filters */
 			LINFLEX_0.LINCR1.B.MME = 1;		/* Master Mode */
 			LINFLEX_0.LINCR1.B.MBL = 0x3; 	/* 13-bit master break */
 			LINFLEX_0.LINCR2.B.IOBE = 0;	/* Do not go to idle on bit error*/
 			LINFLEX_0.LINTCSR.B.IOT = 0;	/* Do not go to idle on timeout*/
 			LIN_SetBaudrate(LIN0,BAUDRATE_9600BPS);
			break;
			
		case LIN1:
 			LINFLEX_1.UARTCR.B.UART = 0;	/* LIN Mode */
 			LINFLEX_1.LINCR1.B.BF = 0;		/* Generate RX int even if no matched filters */
 			LINFLEX_1.LINCR1.B.MME = 1;		/* Master Mode */
 			LINFLEX_1.LINCR1.B.MBL = 0x3; 	/* 13-bit master break */
 			LINFLEX_1.LINCR2.B.IOBE = 0;	/* Do not go to idle on bit error*/
 			LINFLEX_1.LINTCSR.B.IOT = 0;	/* Do not go to idle on timeout*/
 			LIN_SetBaudrate(LIN1,BAUDRATE_9600BPS);
			break;
			
		case LIN2:
 			LINFLEX_2.UARTCR.B.UART = 0;	/* LIN Mode */
 			LINFLEX_2.LINCR1.B.BF = 0;		/* Generate RX int even if no matched filters */
 			LINFLEX_2.LINCR1.B.MME = 1;		/* Master Mode */
 			LINFLEX_2.LINCR1.B.MBL = 0x3; 	/* 13-bit master break */
 			LINFLEX_2.LINCR2.B.IOBE = 0;	/* Do not go to idle on bit error*/
 			LINFLEX_2.LINTCSR.B.IOT = 0;	/* Do not go to idle on timeout*/
 			LIN_SetBaudrate(LIN2,BAUDRATE_9600BPS);
			break;
			
		case LIN3:
 			LINFLEX_3.UARTCR.B.UART = 0;	/* LIN Mode */
 			LINFLEX_3.LINCR1.B.BF = 0;		/* Generate RX int even if no matched filters */
 			LINFLEX_3.LINCR1.B.MME = 1;		/* Master Mode */
 			LINFLEX_3.LINCR1.B.MBL = 0x3; 	/* 13-bit master break */
 			LINFLEX_3.LINCR2.B.IOBE = 0;	/* Do not go to idle on bit error*/
 			LINFLEX_3.LINTCSR.B.IOT = 0;	/* Do not go to idle on timeout*/
 			LIN_SetBaudrate(LIN3,BAUDRATE_9600BPS);
			break;
			
		case LIN4:
 			LINFLEX_4.UARTCR.B.UART = 0;	/* LIN Mode */
 			LINFLEX_4.LINCR1.B.BF = 0;		/* Generate RX int even if no matched filters */
 			LINFLEX_4.LINCR1.B.MME = 1;		/* Master Mode */
 			LINFLEX_4.LINCR1.B.MBL = 0x3; 	/* 13-bit master break */
 			LINFLEX_4.LINCR2.B.IOBE = 0;	/* Do not go to idle on bit error*/
 			LINFLEX_4.LINTCSR.B.IOT = 0;	/* Do not go to idle on timeout*/
 			LIN_SetBaudrate(LIN4,BAUDRATE_9600BPS);
			break;
			
		case LIN5:
 			LINFLEX_5.UARTCR.B.UART = 0;	/* LIN Mode */
 			LINFLEX_5.LINCR1.B.BF = 0;		/* Generate RX int even if no matched filters */
 			LINFLEX_5.LINCR1.B.MME = 1;		/* Master Mode */
 			LINFLEX_5.LINCR1.B.MBL = 0x3; 	/* 13-bit master break */
 			LINFLEX_5.LINCR2.B.IOBE = 0;	/* Do not go to idle on bit error*/
 			LINFLEX_5.LINTCSR.B.IOT = 0;	/* Do not go to idle on timeout*/
 			LIN_SetBaudrate(LIN5,BAUDRATE_9600BPS);
			break;
			
		case LIN6:
 			LINFLEX_6.UARTCR.B.UART = 0;	/* LIN Mode */
 			LINFLEX_6.LINCR1.B.BF = 0;		/* Generate RX int even if no matched filters */
 			LINFLEX_6.LINCR1.B.MME = 1;		/* Master Mode */
 			LINFLEX_6.LINCR1.B.MBL = 0x3; 	/* 13-bit master break */
 			LINFLEX_6.LINCR2.B.IOBE = 0;	/* Do not go to idle on bit error*/
 			LINFLEX_6.LINTCSR.B.IOT = 0;	/* Do not go to idle on timeout*/
 			LIN_SetBaudrate(LIN6,BAUDRATE_9600BPS);
			break;
			
		case LIN7:
 			LINFLEX_7.UARTCR.B.UART = 0;	/* LIN Mode */
 			LINFLEX_7.LINCR1.B.BF = 0;		/* Generate RX int even if no matched filters */
 			LINFLEX_7.LINCR1.B.MME = 1;		/* Master Mode */
 			LINFLEX_7.LINCR1.B.MBL = 0x3; 	/* 13-bit master break */
 			LINFLEX_7.LINCR2.B.IOBE = 0;	/* Do not go to idle on bit error*/
 			LINFLEX_7.LINTCSR.B.IOT = 0;	/* Do not go to idle on timeout*/
 			LIN_SetBaudrate(LIN7,BAUDRATE_9600BPS);
			break;
			
		default:
			break;
	}
	
 }
 
 /**************************************************************
 *  Name                 :	LIN_NormalMode
 *  Description          :	
 *  Parameters           :  
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
 void LIN_NormalMode(E_LIN_MODULE le_lin_module){
	
	switch(le_lin_module){
		case LIN0:
			LINFLEX_0.LINCR1.B.INIT = 0; 	/* LINFLEX normal mode */
			break;
			
		case LIN1:
			LINFLEX_1.LINCR1.B.INIT = 0;
			break;
			
		case LIN2:
			LINFLEX_2.LINCR1.B.INIT = 0;
			break;
			
		case LIN3:
			LINFLEX_3.LINCR1.B.INIT = 0;
			break;
			
		case LIN4:
			LINFLEX_4.LINCR1.B.INIT = 0;
			break;
			
		case LIN5:
			LINFLEX_5.LINCR1.B.INIT = 0;
			break;
			
		case LIN6:
			LINFLEX_6.LINCR1.B.INIT = 0;
			break;
			
		case LIN7:
			LINFLEX_7.LINCR1.B.INIT = 0;
			break;
			
		default:
			break;
	}
	
 }
 
 /**************************************************************
 *  Name                 :	LIN_Slave_FilterConfig
 *  Description          :	
 *  Parameters           :  
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
 void LIN_Slave_FilterConfig(E_LIN_FILTER_NUMBER le_FilterNumber, T_UBYTE lub_id, T_UBYTE lub_NumberOfBytes, E_LIN_CHKSUM_TYPE le_ccs, E_LIN_DATA_DIR le_dir){
	
	LINFLEX_0.IFCR[le_FilterNumber].B.DFL = (lub_NumberOfBytes-1);	/* Number of bytes in the data field */
 	LINFLEX_0.IFCR[le_FilterNumber].B.DIR = le_dir;					/* Direction of the data */
 	LINFLEX_0.IFCR[le_FilterNumber].B.CCS = le_ccs;					/* Enhaced checksum */
 	LINFLEX_0.IFCR[le_FilterNumber].B.ID = lub_id;					/* 0x50 w/o parity bits */
	
 }
 
 /**************************************************************
 *  Name                 :	LIN_Slave_FiltersInit
 *  Description          :	
 *  Parameters           :  
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
 void LIN_Slave_FiltersInit(void){
	
	/* 4 filters are configured for the IDs 0xCF, 0x50, 0x20 and 0xF0 */
 	
 	LINFLEX_0.IFER.R = 0x0; 		/* Deactivate filters 0, 1, 2 and 3 */
 	LINFLEX_0.IFMR.R = 0x0;			/* List mode selected */
 	
 	LIN_Slave_FilterConfig(LIN_FILTER0, 0x0F, 1, CHKSUM_ENHACED, LIN_DATA_RX);
 	LIN_Slave_FilterConfig(LIN_FILTER1, 0x10, 1, CHKSUM_ENHACED, LIN_DATA_RX);
 	LIN_Slave_FilterConfig(LIN_FILTER2, 0x20, 2, CHKSUM_ENHACED, LIN_DATA_TX);
 	LIN_Slave_FilterConfig(LIN_FILTER3, 0x30, 7, CHKSUM_ENHACED, LIN_DATA_TX);
 
 	LINFLEX_0.IFER.B.FACT = 0xFF; 		/* Active filters 0, 1, 2 and 3 */
 }