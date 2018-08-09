/*******************************************************************************
* File Name: B1.c  
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
#include "B1.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 B1__PORT == 15 && ((B1__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: B1_Write
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
void B1_Write(uint8 value) 
{
    uint8 staticBits = (B1_DR & (uint8)(~B1_MASK));
    B1_DR = staticBits | ((uint8)(value << B1_SHIFT) & B1_MASK);
}


/*******************************************************************************
* Function Name: B1_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  B1_DM_STRONG     Strong Drive 
*  B1_DM_OD_HI      Open Drain, Drives High 
*  B1_DM_OD_LO      Open Drain, Drives Low 
*  B1_DM_RES_UP     Resistive Pull Up 
*  B1_DM_RES_DWN    Resistive Pull Down 
*  B1_DM_RES_UPDWN  Resistive Pull Up/Down 
*  B1_DM_DIG_HIZ    High Impedance Digital 
*  B1_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void B1_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(B1_0, mode);
}


/*******************************************************************************
* Function Name: B1_Read
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
*  Macro B1_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 B1_Read(void) 
{
    return (B1_PS & B1_MASK) >> B1_SHIFT;
}


/*******************************************************************************
* Function Name: B1_ReadDataReg
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
uint8 B1_ReadDataReg(void) 
{
    return (B1_DR & B1_MASK) >> B1_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(B1_INTSTAT) 

    /*******************************************************************************
    * Function Name: B1_ClearInterrupt
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
    uint8 B1_ClearInterrupt(void) 
    {
        return (B1_INTSTAT & B1_MASK) >> B1_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
