/*******************************************************************************
* File Name: Latch_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Latch.h"

/* Check for removal by optimization */
#if !defined(Latch_Sync_ctrl_reg__REMOVED)

static Latch_BACKUP_STRUCT  Latch_backup = {0u};

    
/*******************************************************************************
* Function Name: Latch_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Latch_SaveConfig(void) 
{
    Latch_backup.controlState = Latch_Control;
}


/*******************************************************************************
* Function Name: Latch_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void Latch_RestoreConfig(void) 
{
     Latch_Control = Latch_backup.controlState;
}


/*******************************************************************************
* Function Name: Latch_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Latch_Sleep(void) 
{
    Latch_SaveConfig();
}


/*******************************************************************************
* Function Name: Latch_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Latch_Wakeup(void)  
{
    Latch_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
