/*******************************************************************************
* File Name: OEpin.c  
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
#include "OEpin.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 OEpin__PORT == 15 && ((OEpin__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: OEpin_Write
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
void OEpin_Write(uint8 value) 
{
    uint8 staticBits = (OEpin_DR & (uint8)(~OEpin_MASK));
    OEpin_DR = staticBits | ((uint8)(value << OEpin_SHIFT) & OEpin_MASK);
}


/*******************************************************************************
* Function Name: OEpin_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  OEpin_DM_STRONG     Strong Drive 
*  OEpin_DM_OD_HI      Open Drain, Drives High 
*  OEpin_DM_OD_LO      Open Drain, Drives Low 
*  OEpin_DM_RES_UP     Resistive Pull Up 
*  OEpin_DM_RES_DWN    Resistive Pull Down 
*  OEpin_DM_RES_UPDWN  Resistive Pull Up/Down 
*  OEpin_DM_DIG_HIZ    High Impedance Digital 
*  OEpin_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void OEpin_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(OEpin_0, mode);
}


/*******************************************************************************
* Function Name: OEpin_Read
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
*  Macro OEpin_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 OEpin_Read(void) 
{
    return (OEpin_PS & OEpin_MASK) >> OEpin_SHIFT;
}


/*******************************************************************************
* Function Name: OEpin_ReadDataReg
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
uint8 OEpin_ReadDataReg(void) 
{
    return (OEpin_DR & OEpin_MASK) >> OEpin_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(OEpin_INTSTAT) 

    /*******************************************************************************
    * Function Name: OEpin_ClearInterrupt
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
    uint8 OEpin_ClearInterrupt(void) 
    {
        return (OEpin_INTSTAT & OEpin_MASK) >> OEpin_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
