/*******************************************************************************
* File Name: blue.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_blue_H) /* CY_CONTROL_REG_blue_H */
#define CY_CONTROL_REG_blue_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} blue_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    blue_Write(uint8 control) ;
uint8   blue_Read(void) ;

void blue_SaveConfig(void) ;
void blue_RestoreConfig(void) ;
void blue_Sleep(void) ; 
void blue_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define blue_Control        (* (reg8 *) blue_Sync_ctrl_reg__CONTROL_REG )
#define blue_Control_PTR    (  (reg8 *) blue_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_blue_H */


/* [] END OF FILE */
