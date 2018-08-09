/*******************************************************************************
* File Name: CBA.h  
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

#if !defined(CY_CONTROL_REG_CBA_H) /* CY_CONTROL_REG_CBA_H */
#define CY_CONTROL_REG_CBA_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} CBA_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    CBA_Write(uint8 control) ;
uint8   CBA_Read(void) ;

void CBA_SaveConfig(void) ;
void CBA_RestoreConfig(void) ;
void CBA_Sleep(void) ; 
void CBA_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define CBA_Control        (* (reg8 *) CBA_Sync_ctrl_reg__CONTROL_REG )
#define CBA_Control_PTR    (  (reg8 *) CBA_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_CBA_H */


/* [] END OF FILE */
