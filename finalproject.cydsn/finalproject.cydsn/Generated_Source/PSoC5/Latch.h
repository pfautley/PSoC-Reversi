/*******************************************************************************
* File Name: Latch.h  
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

#if !defined(CY_CONTROL_REG_Latch_H) /* CY_CONTROL_REG_Latch_H */
#define CY_CONTROL_REG_Latch_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} Latch_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    Latch_Write(uint8 control) ;
uint8   Latch_Read(void) ;

void Latch_SaveConfig(void) ;
void Latch_RestoreConfig(void) ;
void Latch_Sleep(void) ; 
void Latch_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define Latch_Control        (* (reg8 *) Latch_Sync_ctrl_reg__CONTROL_REG )
#define Latch_Control_PTR    (  (reg8 *) Latch_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_Latch_H */


/* [] END OF FILE */
