//------------------------------------------------------------------------------
/*! \file tick.c
 *  \brief Tick system Module
 *  \brief 
 *  \version v1.7.0
 *  \date 05/10/12
 *  \author LCT-JCP (PIC18F version)
 */
//------------------------------------------------------------------------------

//-------------DEPENDENCE  ---------------------------------------------------//


#include "../Includes/device.h"
#include "../Includes/tick.h"
#include "../Includes/Gest_Energy.h"


//-------------VARRIABLE -----------------------------------------------------//

// Table contenant les valeurs courante des ticks
unsigned int wTICK_Table[TICK_MAX]; //65,735s max
extern ENERGY_STRUCTURE    GEN_Energy_data;

//-------------PROTOTYPE DES FONCTIONS NON EXPORTEES -------------------------//

//-------------DEFINITION DES FONCTIONS --------------------------------------//

//------------------------------------------------------------------------------
/*! \fn    bool TICK_Init(void)
 *  \brief  Fonction d'initialisation du module
 *
 *  Initialise le timer et les varrialbes globales
 *  \return bool : true si l'initialisation a reussi, false sinon
 */
//------------------------------------------------------------------------------
void TICK_Init(void)
{
   // index
   int i;
   // initialisation du timer
    // Set up Interrupts for timer
    PIR1bits.TMR1IF = 0;          // clear roll-over interrupt flag
    IPR1bits.TMR1IP = 1;         // Timer0 is high priority interrupt
    PIE1bits.TMR1IE = 1;          // enable the Timer0 interrupt.
    // Timer1 Registers:
    // Prescaler=1:1; TMR1 Preset=33536; Freq=250,00Hz; Period=4,00 ms
    T1CONbits.T1CKPS1 = 0;// bits 5-4  Prescaler Rate Select bits
    T1CONbits.T1CKPS0 = 0;
    T1CONbits.T1OSCEN = 1;// bit 3 Timer1 Oscillator Enable Control: bit 1=on
    T1CONbits.T1SYNC  = 1;// bit 2 Timer1 External Clock Input Synchronization Control bit: 1=Do not synchronize external clock input
    T1CONbits.TMR1CS  = 0;// bit 1 Timer1 Clock Source Select bit: 0=Internal clock (FOSC/4) / 1 = External clock from pin T1CKI (on the rising edge)
    T1CONbits.TMR1ON  = 0;// bit 0 enables timer

   // initialisation de tout les ticks
   for (i=0;i<TICK_MAX;i++)wTICK_Table[i]=0;
    TMR1H = GEN_Energy_data.Timer1_TMR1H;                      // 1ms config;     // preset for timer1 MSB register
    TMR1L = GEN_Energy_data.Timer1_TMR1H;                      // 1ms config;     // preset for timer1 LSB register
   PIR1bits.TMR1IF = 0;          // clear (reset) flag
   T1CONbits.TMR1ON  = 1;// bit 0 enables timer
}

//------------------------------------------------------------------------------
/*! \fn    void TICK_IT(void)
 *  \brief  Fonction de gestion des tick sur interruption timer
 *
 *  Increment tout les tick actifs
 *  \return void
 */
//------------------------------------------------------------------------------
void TICK_IT(void)
{
   // index
   unsigned char index;
   
   PIR1bits.TMR1IF = 0;          // clear (reset) flag
    TMR1H = GEN_Energy_data.Timer1_TMR1H;                      // 1ms config;     // preset for timer1 MSB register
    TMR1L = GEN_Energy_data.Timer1_TMR1H;                      // 1ms config;     // preset for timer1 LSB register
   // parcour la table des tick
   for(index = 0 ; index < TICK_MAX ; index++){
      // si la valeur n'est pas nul decrement
      if( wTICK_Table[index] > 0 ) wTICK_Table[index]--;
   }
}

//------------------------------------------------------------------------------
/*! \fn    void TICK_Set(byte bId, word wValue)
 *  \brief  Mise à jour d'un tick
 *
 *  met à jour la valeur d'un tick
 *  \param bId : Id du tick a metre a jour
 *  \param wValue : Nouvelle valeur du tick
 *  \return void
 */
//------------------------------------------------------------------------------

void TICK_Set(TICK_Name_T eId, unsigned int wValue)
{
   // si le tick existe
   if(eId<TICK_MAX)
      // metre a jour la valeur
      wTICK_Table[eId]=wValue;
}

//------------------------------------------------------------------------------
/*! \fn    word TICK_Get(byte bId)
 *  \brief  lecture de la valeur d'un tick
 *
 *  \return word : renvoie la valeur du type dont l'Id est passé en argument
 */
//------------------------------------------------------------------------------
unsigned int TICK_Get(TICK_Name_T eId)
{
   // si le tick existe
   if(eId<TICK_MAX)
      return  wTICK_Table[eId];
   else return 0;
}

//------------------------------------------------------------------------------
/*! \fn    byte TICK_Is_Elapse(byte bId)
 *  \brief  Es ce que la valeur du tick est à 0
 *
 *  \param bId : Identifiant du tick 
 *  \return Bool : renvoie 1 si la valeur est null 0 sinon
 */
//------------------------------------------------------------------------------
Bool TICK_Is_Elapse(TICK_Name_T eId)
{
   // si le tick existe
   if(eId<TICK_MAX)
   {
      // si la valeur est null
      if(wTICK_Table[eId]==0)return true;
      else return false;
   }
	//sinon
   return false;
}

//------------------------------------------------------------------------------
/*! \fn    void TICK_Close
 *  \brief  Es ce que la valeur du tick est à 0
 *
 *  \param bId : Identifiant du tick 
 *  \return void
 */
//------------------------------------------------------------------------------
void TICK_Close( void )
{
    unsigned char i;
   PIR1bits.TMR1IF = 0;          // clear (reset) flag
    T1CONbits.TMR1ON = 0;           // close timer
   // initialisation de tout les ticks
   for (i=0;i<TICK_MAX;i++)wTICK_Table[i]=0;
}
