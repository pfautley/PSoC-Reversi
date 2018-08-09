/*******************************************************************************
* File Name: OEpin.h  
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

#if !defined(CY_PINS_OEpin_H) /* Pins OEpin_H */
#define CY_PINS_OEpin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "OEpin_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 OEpin__PORT == 15 && ((OEpin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    OEpin_Write(uint8 value) ;
void    OEpin_SetDriveMode(uint8 mode) ;
uint8   OEpin_ReadDataReg(void) ;
uint8   OEpin_Read(void) ;
uint8   OEpin_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define OEpin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define OEpin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define OEpin_DM_RES_UP          PIN_DM_RES_UP
#define OEpin_DM_RES_DWN         PIN_DM_RES_DWN
#define OEpin_DM_OD_LO           PIN_DM_OD_LO
#define OEpin_DM_OD_HI           PIN_DM_OD_HI
#define OEpin_DM_STRONG          PIN_DM_STRONG
#define OEpin_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define OEpin_MASK               OEpin__MASK
#define OEpin_SHIFT              OEpin__SHIFT
#define OEpin_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define OEpin_PS                     (* (reg8 *) OEpin__PS)
/* Data Register */
#define OEpin_DR                     (* (reg8 *) OEpin__DR)
/* Port Number */
#define OEpin_PRT_NUM                (* (reg8 *) OEpin__PRT) 
/* Connect to Analog Globals */                                                  
#define OEpin_AG                     (* (reg8 *) OEpin__AG)                       
/* Analog MUX bux enable */
#define OEpin_AMUX                   (* (reg8 *) OEpin__AMUX) 
/* Bidirectional Enable */                                                        
#define OEpin_BIE                    (* (reg8 *) OEpin__BIE)
/* Bit-mask for Aliased Register Access */
#define OEpin_BIT_MASK               (* (reg8 *) OEpin__BIT_MASK)
/* Bypass Enable */
#define OEpin_BYP                    (* (reg8 *) OEpin__BYP)
/* Port wide control signals */                                                   
#define OEpin_CTL                    (* (reg8 *) OEpin__CTL)
/* Drive Modes */
#define OEpin_DM0                    (* (reg8 *) OEpin__DM0) 
#define OEpin_DM1                    (* (reg8 *) OEpin__DM1)
#define OEpin_DM2                    (* (reg8 *) OEpin__DM2) 
/* Input Buffer Disable Override */
#define OEpin_INP_DIS                (* (reg8 *) OEpin__INP_DIS)
/* LCD Common or Segment Drive */
#define OEpin_LCD_COM_SEG            (* (reg8 *) OEpin__LCD_COM_SEG)
/* Enable Segment LCD */
#define OEpin_LCD_EN                 (* (reg8 *) OEpin__LCD_EN)
/* Slew Rate Control */
#define OEpin_SLW                    (* (reg8 *) OEpin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define OEpin_PRTDSI__CAPS_SEL       (* (reg8 *) OEpin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define OEpin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) OEpin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define OEpin_PRTDSI__OE_SEL0        (* (reg8 *) OEpin__PRTDSI__OE_SEL0) 
#define OEpin_PRTDSI__OE_SEL1        (* (reg8 *) OEpin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define OEpin_PRTDSI__OUT_SEL0       (* (reg8 *) OEpin__PRTDSI__OUT_SEL0) 
#define OEpin_PRTDSI__OUT_SEL1       (* (reg8 *) OEpin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define OEpin_PRTDSI__SYNC_OUT       (* (reg8 *) OEpin__PRTDSI__SYNC_OUT) 


#if defined(OEpin__INTSTAT)  /* Interrupt Registers */

    #define OEpin_INTSTAT                (* (reg8 *) OEpin__INTSTAT)
    #define OEpin_SNAP                   (* (reg8 *) OEpin__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_OEpin_H */


/* [] END OF FILE */
