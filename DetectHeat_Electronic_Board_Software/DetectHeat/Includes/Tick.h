//------------------------------------------------------------------------------
/*! \file Tick.h
 *  \brief Tick system Module
 *  \brief 
 *  \version v1.5.0
 *  \date 26/07/12
 *  \author LCT-JCP (PIC18F version)
 */
//------------------------------------------------------------------------------
// Version  | Date     | Author         | Modification
//------------------------------------------------------------------------------

#ifndef __TICK_H__
#define __TICK_H__

//-------------DEPENDENCE  ---------------------------------------------------//

// Ajout des types standards
//#include "typedef.h"

//-------------DEFINITION ET CONFIGURATION -----------------------------------//

//! liste des tick connus
typedef enum {
	TICK_MAIN_MESURE,
        TICK_BUTTON_SCAN,
        TICK_NOTE_DURATION,
   TICK_MAX
} TICK_Name_T;

//-------------PROTOTYPE DES FONCTIONS EXPORTEES -----------------------------//

// Fonction d'initialisation du module
void TICK_Init(void);

// Fonction de gestion des tick sur IT timer
void TICK_IT(void);

// Es ce qu'un Tick est arriv� � 0
Bool TICK_Is_Elapse(TICK_Name_T eId);

// definir un Tick
void TICK_Set(TICK_Name_T eId, unsigned int wValue);

// lire la valeur d'un Tick
unsigned int TICK_Get(TICK_Name_T eId);

void TICK_Close( void );

#define Timer1_On() T1CONbits.TMR1ON = 1           // open timer
#define Timer1_Off() T1CONbits.TMR1ON = 0           // close timer

//-------------VARRIABLES EXPORTEES ------------------------------------------//

#endif
