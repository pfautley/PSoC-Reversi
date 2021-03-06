/*******************************************************************************
* File Name: B1.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_B1_H) /* Pins B1_H */
#define CY_PINS_B1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "B1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 B1__PORT == 15 && ((B1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    B1_Write(uint8 value) ;
void    B1_SetDriveMode(uint8 mode) ;
uint8   B1_ReadDataReg(void) ;
uint8   B1_Read(void) ;
uint8   B1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define B1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define B1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define B1_DM_RES_UP          PIN_DM_RES_UP
#define B1_DM_RES_DWN         PIN_DM_RES_DWN
#define B1_DM_OD_LO           PIN_DM_OD_LO
#define B1_DM_OD_HI           PIN_DM_OD_HI
#define B1_DM_STRONG          PIN_DM_STRONG
#define B1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define B1_MASK               B1__MASK
#define B1_SHIFT              B1__SHIFT
#define B1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define B1_PS                     (* (reg8 *) B1__PS)
/* Data Register */
#define B1_DR                     (* (reg8 *) B1__DR)
/* Port Number */
#define B1_PRT_NUM                (* (reg8 *) B1__PRT) 
/* Connect to Analog Globals */                                                  
#define B1_AG                     (* (reg8 *) B1__AG)                       
/* Analog MUX bux enable */
#define B1_AMUX                   (* (reg8 *) B1__AMUX) 
/* Bidirectional Enable */                                                        
#define B1_BIE                    (* (reg8 *) B1__BIE)
/* Bit-mask for Aliased Register Access */
#define B1_BIT_MASK               (* (reg8 *) B1__BIT_MASK)
/* Bypass Enable */
#define B1_BYP                    (* (reg8 *) B1__BYP)
/* Port wide control signals */                                                   
#define B1_CTL                    (* (reg8 *) B1__CTL)
/* Drive Modes */
#define B1_DM0                    (* (reg8 *) B1__DM0) 
#define B1_DM1                    (* (reg8 *) B1__DM1)
#define B1_DM2                    (* (reg8 *) B1__DM2) 
/* Input Buffer Disable Override */
#define B1_INP_DIS                (* (reg8 *) B1__INP_DIS)
/* LCD Common or Segment Drive */
#define B1_LCD_COM_SEG            (* (reg8 *) B1__LCD_COM_SEG)
/* Enable Segment LCD */
#define B1_LCD_EN                 (* (reg8 *) B1__LCD_EN)
/* Slew Rate Control */
#define B1_SLW                    (* (reg8 *) B1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define B1_PRTDSI__CAPS_SEL       (* (reg8 *) B1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define B1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) B1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define B1_PRTDSI__OE_SEL0        (* (reg8 *) B1__PRTDSI__OE_SEL0) 
#define B1_PRTDSI__OE_SEL1        (* (reg8 *) B1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define B1_PRTDSI__OUT_SEL0       (* (reg8 *) B1__PRTDSI__OUT_SEL0) 
#define B1_PRTDSI__OUT_SEL1       (* (reg8 *) B1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define B1_PRTDSI__SYNC_OUT       (* (reg8 *) B1__PRTDSI__SYNC_OUT) 


#if defined(B1__INTSTAT)  /* Interrupt Registers */

    #define B1_INTSTAT                (* (reg8 *) B1__INTSTAT)
    #define B1_SNAP                   (* (reg8 *) B1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_B1_H */


/* [] END OF FILE */
