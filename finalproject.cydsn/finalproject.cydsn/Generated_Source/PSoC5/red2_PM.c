/*******************************************************************************
* File Name: red2_PM.c
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

#include "red2.h"

/* Check for removal by optimization */
#if !defined(red2_Sync_ctrl_reg__REMOVED)

static red2_BACKUP_STRUCT  red2_backup = {0u};

    
/*******************************************************************************
* Function Name: red2_SaveConfig
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
void red2_SaveConfig(void) 
{
    red2_backup.controlState = red2_Control;
}


/*******************************************************************************
* Function Name: red2_RestoreConfig
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
void red2_RestoreConfig(void) 
{
     red2_Control = red2_backup.controlState;
}


/*******************************************************************************
* Function Name: red2_Sleep
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
void red2_Sleep(void) 
{
    red2_SaveConfig();
}


/*******************************************************************************
* Function Name: red2_Wakeup
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
void red2_Wakeup(void)  
{
    red2_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
