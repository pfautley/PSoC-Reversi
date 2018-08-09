/*******************************************************************************
* File Name: red_PM.c
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

#include "red.h"

/* Check for removal by optimization */
#if !defined(red_Sync_ctrl_reg__REMOVED)

static red_BACKUP_STRUCT  red_backup = {0u};

    
/*******************************************************************************
* Function Name: red_SaveConfig
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
void red_SaveConfig(void) 
{
    red_backup.controlState = red_Control;
}


/*******************************************************************************
* Function Name: red_RestoreConfig
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
void red_RestoreConfig(void) 
{
     red_Control = red_backup.controlState;
}


/*******************************************************************************
* Function Name: red_Sleep
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
void red_Sleep(void) 
{
    red_SaveConfig();
}


/*******************************************************************************
* Function Name: red_Wakeup
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
void red_Wakeup(void)  
{
    red_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
