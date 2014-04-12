/* 
 * File:   Gest_Energy.h
 * Author: Jean-Christophe P
 *
 * Created on 16 janvier 2014, 18:46
 */

#ifndef Gest_Energy_H
#define	Gest_Energy_H

#define FREQ_32MHZ      1
#define FREQ_4MHZ       2
#define SLEEP           3

typedef struct {
unsigned char PIC_Freq;
    // timers
unsigned char Timer0_T0CON;
unsigned char Timer0_TMR0H;
unsigned char Timer0_TMR0L;
//unsigned char Timer1_T1CON;
unsigned char Timer1_TMR1H;
unsigned char Timer1_TMR1L;

unsigned char Timer2_PR2;
//unsigned char Timer3_T3CON;
unsigned char Timer3_TMR3H;
unsigned char Timer3_TMR3L;

// Uart
unsigned char Uart_SPBRG;
}ENERGY_STRUCTURE;


//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  GEN_SetPicFrequency(unsigned char Freq_Value)
 *  \brief This fonction change the PIC frequency and the pheripheric parameter
 *  \param Speed mode
 *  \return none
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
void GEN_SetPicFrequency(unsigned char Freq_Value);


//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  unsigned char GEN_GetPicFrequency()
 *  \brief This fonction change the PIC frequency
 *
 *  \return PIC fequency
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
unsigned char GEN_GetPicFrequency();

//--------------------------------------------------------------------------------------------------------------------------------------------
/** \name 		Variable define for PIC @ 32 Mhz
*
 */
//--------------------------------------------------------------------------------------------------------------------------------------------

#define PIC_PROSFREQ_32MHZ  (32000000ul)
#define PIC_PERIPH_32MHZ  (8000000ul)

// Timer 0 configuration  : 1s config
#define T0CON_32MHZ         0b10000110;   // bits 2-0  PS2:PS0: Prescaler Select bits
#define TMR0H_32MHZ         11
#define TMR0L_32MHZ         220



// Timer 1 configuration  : 1ms config
//#define T1CON_32MHZ
#define TMR1H_32MHZ         224;     // preset for timer1 MSB register     //1mS configuration @ 32Mhz
#define TMR1L_32MHZ         192;     // preset for timer1 LSB register

// Timer 2 configuration  : PWM generator
//#define T2CON_32MHZ 0b01111101    // T2CON config register
#define PR2_32MHZ         250;     // preset for timer1 MSB register     //1mS configuration @ 32Mhz

// Timer 3 configuration  : RTTTL tone music generator
//#define T3CON_32MHZ
#define TMR3H_32MHZ         0xB8;     // preset for timer3 MSB register     //1mS configuration @ 32Mhz
#define TMR3L_32MHZ         0xFA;     // preset for timer3 LSB register

//
#define UARTINTC_BAUDRATE_32MHZ 9600
#define SPBRG_V1_32MHZ  (PIC_PROSFREQ_32MHZ / UARTINTC_BAUDRATE_32MHZ)
#define SPBRG_V2_32MHZ  SPBRG_V1_32MHZ/16
#define SPBRG_VAL_32MHZ  (SPBRG_V2_32MHZ - 1)
# if (SPBRG_VAL_32MHZ > 255)
  #error Calculated SPBRG_32MHZ value is out of range
#elif (SPBRG_VAL_32MHZ < 10)
  #error Calculated SPBRG_32MHZ value is out of range
#endif


//--------------------------------------------------------------------------------------------------------------------------------------------
/** \name 		Variable define for PIC @ 4 Mhz
*
 */
//--------------------------------------------------------------------------------------------------------------------------------------------

#define PIC_PROSFREQ_4MHZ  (4000000ul)
#define PIC_PERIPH_4MHZ  (1000000ul)

// Timer 0 configuration  : 1s config
#define T0CON_4MHZ         0b10000011;   //T0CON config
#define TMR0H_4MHZ         11
#define TMR0L_4MHZ         220



// Timer 1 configuration  : 1ms config
//#define T1CON_32MHZ
#define TMR1H_4MHZ         252;     // preset for timer1 MSB register     //1mS configuration @ 4Mhz
#define TMR1L_4MHZ         24;     // preset for timer1 LSB register

// Timer 2 configuration  : PWM generator
//#define T2CON_32MHZ 0b01111101    // T2CON config register
#define PR2_4MHZ         250;     // preset for timer1 MSB register     
// Timer 3 configuration  : RTTTL tone music generator
//#define T3CON_32MHZ
#define TMR3H_4MHZ         0xB8;     // preset for timer3 MSB register     //1mS configuration @ 32Mhz
#define TMR3L_4MHZ         0xFA;     // preset for timer3 LSB register

//
#define UARTINTC_BAUDRATE_4MHZ 9600
#define SPBRG_V1_4MHZ  (PIC_PROSFREQ_4MHZ / UARTINTC_BAUDRATE_4MHZ)
#define SPBRG_V2_4MHZ  SPBRG_V1_4MHZ/16
#define SPBRG_VAL_4MHZ  (SPBRG_V2_4MHZ - 1)
# if (SPBRG_VAL_4MHZ > 255)
  #error Calculated SPBRG_4MHZ value is out of range
#elif (SPBRG_VAL_4MHZ < 10)
  #error Calculated SPBRG_4MHZ value is out of range
#endif



#endif	/* Gest_Energy_H */
