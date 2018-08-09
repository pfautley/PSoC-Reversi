/*******************************************************************************
* File Name: blue2_PM.c
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

#include "blue2.h"

/* Check for removal by optimization */
#if !defined(blue2_Sync_ctrl_reg__REMOVED)

static blue2_BACKUP_STRUCT  blue2_backup = {0u};

    
/*******************************************************************************
* Function Name: blue2_SaveConfig
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
void blue2_SaveConfig(void) 
{
    blue2_backup.controlState = blue2_Control;
}


/*******************************************************************************
* Function Name: blue2_RestoreConfig
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
void blue2_RestoreConfig(void) 
{
     blue2_Control = blue2_backup.controlState;
}


/*******************************************************************************
* Function Name: blue2_Sleep
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
void blue2_Sleep(void) 
{
    blue2_SaveConfig();
}


/*******************************************************************************
* Function Name: blue2_Wakeup
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
void blue2_Wakeup(void)  
{
    blue2_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
