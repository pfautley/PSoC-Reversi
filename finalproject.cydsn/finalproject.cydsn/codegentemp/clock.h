/*******************************************************************************
* File Name: clock.h  
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

#if !defined(CY_PINS_clock_H) /* Pins clock_H */
#define CY_PINS_clock_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "clock_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 clock__PORT == 15 && ((clock__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    clock_Write(uint8 value) ;
void    clock_SetDriveMode(uint8 mode) ;
uint8   clock_ReadDataReg(void) ;
uint8   clock_Read(void) ;
uint8   clock_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define clock_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define clock_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define clock_DM_RES_UP          PIN_DM_RES_UP
#define clock_DM_RES_DWN         PIN_DM_RES_DWN
#define clock_DM_OD_LO           PIN_DM_OD_LO
#define clock_DM_OD_HI           PIN_DM_OD_HI
#define clock_DM_STRONG          PIN_DM_STRONG
#define clock_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define clock_MASK               clock__MASK
#define clock_SHIFT              clock__SHIFT
#define clock_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define clock_PS                     (* (reg8 *) clock__PS)
/* Data Register */
#define clock_DR                     (* (reg8 *) clock__DR)
/* Port Number */
#define clock_PRT_NUM                (* (reg8 *) clock__PRT) 
/* Connect to Analog Globals */                                                  
#define clock_AG                     (* (reg8 *) clock__AG)                       
/* Analog MUX bux enable */
#define clock_AMUX                   (* (reg8 *) clock__AMUX) 
/* Bidirectional Enable */                                                        
#define clock_BIE                    (* (reg8 *) clock__BIE)
/* Bit-mask for Aliased Register Access */
#define clock_BIT_MASK               (* (reg8 *) clock__BIT_MASK)
/* Bypass Enable */
#define clock_BYP                    (* (reg8 *) clock__BYP)
/* Port wide control signals */                                                   
#define clock_CTL                    (* (reg8 *) clock__CTL)
/* Drive Modes */
#define clock_DM0                    (* (reg8 *) clock__DM0) 
#define clock_DM1                    (* (reg8 *) clock__DM1)
#define clock_DM2                    (* (reg8 *) clock__DM2) 
/* Input Buffer Disable Override */
#define clock_INP_DIS                (* (reg8 *) clock__INP_DIS)
/* LCD Common or Segment Drive */
#define clock_LCD_COM_SEG            (* (reg8 *) clock__LCD_COM_SEG)
/* Enable Segment LCD */
#define clock_LCD_EN                 (* (reg8 *) clock__LCD_EN)
/* Slew Rate Control */
#define clock_SLW                    (* (reg8 *) clock__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define clock_PRTDSI__CAPS_SEL       (* (reg8 *) clock__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define clock_PRTDSI__DBL_SYNC_IN    (* (reg8 *) clock__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define clock_PRTDSI__OE_SEL0        (* (reg8 *) clock__PRTDSI__OE_SEL0) 
#define clock_PRTDSI__OE_SEL1        (* (reg8 *) clock__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define clock_PRTDSI__OUT_SEL0       (* (reg8 *) clock__PRTDSI__OUT_SEL0) 
#define clock_PRTDSI__OUT_SEL1       (* (reg8 *) clock__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define clock_PRTDSI__SYNC_OUT       (* (reg8 *) clock__PRTDSI__SYNC_OUT) 


#if defined(clock__INTSTAT)  /* Interrupt Registers */

    #define clock_INTSTAT                (* (reg8 *) clock__INTSTAT)
    #define clock_SNAP                   (* (reg8 *) clock__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_clock_H */


/* [] END OF FILE */
