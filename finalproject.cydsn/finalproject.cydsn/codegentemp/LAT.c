/*******************************************************************************
* File Name: LAT.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "LAT.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 LAT__PORT == 15 && ((LAT__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: LAT_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void LAT_Write(uint8 value) 
{
    uint8 staticBits = (LAT_DR & (uint8)(~LAT_MASK));
    LAT_DR = staticBits | ((uint8)(value << LAT_SHIFT) & LAT_MASK);
}


/*******************************************************************************
* Function Name: LAT_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  LAT_DM_STRONG     Strong Drive 
*  LAT_DM_OD_HI      Open Drain, Drives High 
*  LAT_DM_OD_LO      Open Drain, Drives Low 
*  LAT_DM_RES_UP     Resistive Pull Up 
*  LAT_DM_RES_DWN    Resistive Pull Down 
*  LAT_DM_RES_UPDWN  Resistive Pull Up/Down 
*  LAT_DM_DIG_HIZ    High Impedance Digital 
*  LAT_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void LAT_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(LAT_0, mode);
}


/*******************************************************************************
* Function Name: LAT_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro LAT_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LAT_Read(void) 
{
    return (LAT_PS & LAT_MASK) >> LAT_SHIFT;
}


/*******************************************************************************
* Function Name: LAT_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 LAT_ReadDataReg(void) 
{
    return (LAT_DR & LAT_MASK) >> LAT_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LAT_INTSTAT) 

    /*******************************************************************************
    * Function Name: LAT_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 LAT_ClearInterrupt(void) 
    {
        return (LAT_INTSTAT & LAT_MASK) >> LAT_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
