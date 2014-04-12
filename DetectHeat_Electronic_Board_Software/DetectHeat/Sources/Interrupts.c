//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \file Interrupts.c
 *	\brief File definition for Interrupts
 *  \version v0.0.0
 *  \date 05/05/12
 *  \author Jean-Christophe Papelard
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
//		version	|  Date		|  Author   		| 	Modification
//--------------------------------------------------------------------------------------------------------------------------------------------
//		v0.0.1	|  05/05/12	| Jean-Christophe Papelard	|	First version
//--------------------------------------------------------------------------------------------------------------------------------------------

#include "../Includes/device.h"  // header file
#include "../Includes/Gest_Energy.h"
#include "../Includes/Interrupts.h"  // header file
#include "../Includes/UARTintC.h"
#include "../Includes/tick.h"
#include "../Includes/Bluecom.h"
//#include "../Includes/BC_pwm.h"
#include "../Includes/RTTTLtone.h"


//--------------------------------------------------------------------------------------------------------------------------------------------
//	Global Variables definition
//--------------------------------------------------------------------------------------------------------------------------------------------
#pragma udata   // declare statically allocated uinitialized variables

extern ENERGY_STRUCTURE GEN_Energy_data;
//extern UART_DATA BlueCom_Data_TX, BlueCom_Data_RX;
//extern RGB_PWM_LED_STRUCTURE BlueCom_outputRGB;
extern unsigned char Buzzer_On;

//--------------------------------------------------------------------------------------------------------------------------------------------
/** \name 	High priority interrupt vector
*
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
#pragma code InterruptVectorHigh = 0x08
void InterruptVectorHigh (void)
{
  _asm
    goto InterruptServiceHigh //jump to interrupt routine
  _endasm
}

//--------------------------------------------------------------------------------------------------------------------------------------------
/** \name 	Low priority interrupt vector
*
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
#pragma code InterruptVectorLow = 0x18
void InterruptVectorLow (void)
{
  _asm
    goto InterruptServiceLow //jump to interrupt routine
  _endasm
}

// -------------------- Iterrupt Service Routines --------------------------
#pragma interrupt InterruptServiceHigh  // "interrupt" pragma also for high priority
//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  void InterruptServiceHigh(void)
 *  \brief This fonction manage the high Interrupt Service
 *
 *  \return void
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
void InterruptServiceHigh(void)
{
        //Interrupt programme for UART gestion (TX+RX)
        PIE1bits.TMR2IE = 0;          // desactive interruption PWM
        UARTIntISR();
        PIE1bits.TMR2IE = 1;          // active interruption PWM


        if  (PIR1bits.TMR1IF)        // Timer 1 interrupt flag
       {
           PIR1bits.TMR1IF = 0;
           TICK_IT();  //update tick timer
       }
        if  (INTCON3bits.INT2F)        // Timer 1 interrupt flag
       {
           INTCON3bits.INT2F = 0;
           //INT2 on falling edge
           //...
       }


    // Check for another interrupt, examples:
    // if (PIR1bits.TMR1IF)     // Timer 1
    // if (PIR1bits.ADIF)       // ADC

}  // return from high-priority interrupt

#pragma interruptlow InterruptServiceLow// "interruptlow" pragma for low priority
//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  void InterruptServiceLow(void)
 *  \brief This fonction manage the Low Interrupt Service
 *
 *  \return void
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
void InterruptServiceLow(void)
{
    // Check to see what caused the interrupt
    // (Necessary when more than 1 interrupt at a priority level)
      if (PIR1bits.TMR2IF == 1)          // timer 2 interrupt flag
      {
        PIR1bits.TMR2IF = 0;     // clears TMR2IF       bit 1 TMR2IF: TMR2 to PR2 Match Interrupt Flag bit
        //PWM_Generator();

      }

       if  (INTCONbits.TMR0IF)  // Timer 0 interrupt flag
       {    
        INTCONbits.TMR0IF = 0;
        TMR0H = GEN_Energy_data.Timer0_TMR0H;                      // 1s config
        TMR0L = GEN_Energy_data.Timer0_TMR0L;

        //if (READ_LED_OUT==1) { SET_LED_OUT = 0; }
        //else { SET_LED_OUT = 1;  }
       }


       if  (PIR2bits.TMR3IF)        // TImer 3 interrupt flag
       {
           PIR2bits.TMR3IF = 0;
           RTTTL_Beep();
       }

      // Timer2 Interrupt- Freq = 10000.00 Hz - Period = 0.000100 seconds

    // Check for another interrupt, examples:
    // if (PIR1bits.TMR1IF)     // Timer 1
    // if (PIR1bits.ADIF)       // ADC
}
