/*******************************************************************************
* File Name: green_PM.c
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

#include "green.h"

/* Check for removal by optimization */
#if !defined(green_Sync_ctrl_reg__REMOVED)

static green_BACKUP_STRUCT  green_backup = {0u};

    
/*******************************************************************************
* Function Name: green_SaveConfig
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
void green_SaveConfig(void) 
{
    green_backup.controlState = green_Control;
}


/*******************************************************************************
* Function Name: green_RestoreConfig
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
void green_RestoreConfig(void) 
{
     green_Control = green_backup.controlState;
}


/*******************************************************************************
* Function Name: green_Sleep
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
void green_Sleep(void) 
{
    green_SaveConfig();
}


/*******************************************************************************
* Function Name: green_Wakeup
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
void green_Wakeup(void)  
{
    green_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
