/*******************************************************************************
* File Name: CBA_PM.c
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

#include "CBA.h"

/* Check for removal by optimization */
#if !defined(CBA_Sync_ctrl_reg__REMOVED)

static CBA_BACKUP_STRUCT  CBA_backup = {0u};

    
/*******************************************************************************
* Function Name: CBA_SaveConfig
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
void CBA_SaveConfig(void) 
{
    CBA_backup.controlState = CBA_Control;
}


/*******************************************************************************
* Function Name: CBA_RestoreConfig
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
void CBA_RestoreConfig(void) 
{
     CBA_Control = CBA_backup.controlState;
}


/*******************************************************************************
* Function Name: CBA_Sleep
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
void CBA_Sleep(void) 
{
    CBA_SaveConfig();
}


/*******************************************************************************
* Function Name: CBA_Wakeup
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
void CBA_Wakeup(void)  
{
    CBA_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
