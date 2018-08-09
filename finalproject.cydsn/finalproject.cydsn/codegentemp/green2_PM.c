/*******************************************************************************
* File Name: green2_PM.c
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

#include "green2.h"

/* Check for removal by optimization */
#if !defined(green2_Sync_ctrl_reg__REMOVED)

static green2_BACKUP_STRUCT  green2_backup = {0u};

    
/*******************************************************************************
* Function Name: green2_SaveConfig
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
void green2_SaveConfig(void) 
{
    green2_backup.controlState = green2_Control;
}


/*******************************************************************************
* Function Name: green2_RestoreConfig
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
void green2_RestoreConfig(void) 
{
     green2_Control = green2_backup.controlState;
}


/*******************************************************************************
* Function Name: green2_Sleep
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
void green2_Sleep(void) 
{
    green2_SaveConfig();
}


/*******************************************************************************
* Function Name: green2_Wakeup
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
void green2_Wakeup(void)  
{
    green2_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
