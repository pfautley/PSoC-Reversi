/*******************************************************************************
* File Name: clock.c  
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
#include "clock.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 clock__PORT == 15 && ((clock__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: clock_Write
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
void clock_Write(uint8 value) 
{
    uint8 staticBits = (clock_DR & (uint8)(~clock_MASK));
    clock_DR = staticBits | ((uint8)(value << clock_SHIFT) & clock_MASK);
}


/*******************************************************************************
* Function Name: clock_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  clock_DM_STRONG     Strong Drive 
*  clock_DM_OD_HI      Open Drain, Drives High 
*  clock_DM_OD_LO      Open Drain, Drives Low 
*  clock_DM_RES_UP     Resistive Pull Up 
*  clock_DM_RES_DWN    Resistive Pull Down 
*  clock_DM_RES_UPDWN  Resistive Pull Up/Down 
*  clock_DM_DIG_HIZ    High Impedance Digital 
*  clock_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void clock_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(clock_0, mode);
}


/*******************************************************************************
* Function Name: clock_Read
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
*  Macro clock_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 clock_Read(void) 
{
    return (clock_PS & clock_MASK) >> clock_SHIFT;
}


/*******************************************************************************
* Function Name: clock_ReadDataReg
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
uint8 clock_ReadDataReg(void) 
{
    return (clock_DR & clock_MASK) >> clock_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(clock_INTSTAT) 

    /*******************************************************************************
    * Function Name: clock_ClearInterrupt
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
    uint8 clock_ClearInterrupt(void) 
    {
        return (clock_INTSTAT & clock_MASK) >> clock_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
