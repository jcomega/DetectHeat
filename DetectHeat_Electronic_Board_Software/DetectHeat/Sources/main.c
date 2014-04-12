//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \file main.c
 *	\brief File definition for the project DetectHeat
 *  \version v0.0.0
 *  \date 05/05/12
 *  \author Jean-Christophe Papelard
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
//		version	|  Date		|  Author   		| 	Modification
//--------------------------------------------------------------------------------------------------------------------------------------------
//		v0.0.1	|  05/05/12	| Jean-Christophe Papelard	|	Creation
//		v1.0.0	|  11/02/14	| Jean-Christophe Papelard	|	First final version
//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
//	External dependency definition
//--------------------------------------------------------------------------------------------------------------------------------------------

#include "../Includes/device.h"  // header file
#include "../Includes/Interrupts.h"
#include "../Includes/UARTintC.h"
//#include "../Includes/BlueCom.h"
#include "../Includes/Tick.h"
//#include "../Includes/BC_pwm.h"
#include "../Includes/RTTTLtone.h"
#include "../Includes/Gest_Energy.h"
#include <stdio.h>

//--------------------------------------------------------------------------------------------------------------------------------------------
//	Programme Functionnality
//--------------------------------------------------------------------------------------------------------------------------------------------
// Timer 0 : timer for  1s
// Timer 1 : For Tick.c (tick timer): 1mS
// Timer 2 : PWM generator 8bit : xx Khz
// Timer 3 : For RTTTLtone.c (sound generator works only at 32Mhz )
//  Watchdog for wake up after sleep : 2.18 minutes

//--------------------------------------------------------------------------------------------------------------------------------------------
//	PIC Fuses references definition
//--------------------------------------------------------------------------------------------------------------------------------------------

#pragma config IESO = OFF,FCMEN = OFF, PCLKEN = OFF, PLLEN = OFF, FOSC = IRC// CONFIG1H
#pragma config BOREN = OFF// CONFIG2L
#pragma config WDTEN = ON, WDTPS = 32768 // CONFIG2H  max timer 2.18minute watchdog ON for wake up deep sleep
#pragma config MCLRE = ON,HFOFST = ON// CONFIG3H
#pragma config XINST = OFF, LVP = OFF, STVREN = ON// CONFIG4L

//--------------------------------------------------------------------------------------------------------------------------------------------
//	Global Variables definition
//--------------------------------------------------------------------------------------------------------------------------------------------
#pragma udata   // declare statically allocated uinitialized variables
//extern BOARD_STRUCTURE Board_Struct;
//extern UART_DATA BlueCom_Data_TX, BlueCom_Data_RX;
//extern RGB_PWM_LED_STRUCTURE BlueCom_outputRGB;
extern const rom char song[];
extern ENERGY_STRUCTURE    GEN_Energy_data;
const rom char start_str[]="Board start !\r\n";


//#define OFFSET_TEMP1 3
//#define WAKEUP_NUMBER1 1
#define OFFSET_TEMP1 10
#define WAKEUP_NUMBER1 20

const rom char song3[7][450] ={
{"alarm:d=4,o=7,b=270:c,16p,c,16p,c,16p,c,16p,d,1p,c,16p,c,16p,c,16p,c,16p,e,1p,c,16p,c,16p,c,16p,c,16p,f,1p,c,16p,c,16p,c,16p,c,16p,g,1p,c,16p,c,16p,c,16p,c,16p,a,1p"},
{"Triple:d=8,o=6,b=335:c,e,g,c,e,g,c,e,g,c6,e6,g6,c6,e6,g6,c6,e6,g6,c7,e7,g7,c7,e7,g7,c7,e7,g7"},
{"alarm:d=4,o=7,b=270:c,16p,c,16p,c,16p,c,16p,d,1p,c,16p,c,16p,c,16p,c,16p,e,1p,c,16p,c,16p,c,16p,c,16p,f,1p,c,16p,c,16p,c,16p,c,16p,g,1p,c,16p,c,16p,c,16p,c,16p,a,1p"},
{"Indiana:d=4,o=6,b=250:e,8p,8f,8g,8p,1c6,8p.,d,8p,8e,1f,p.,g,8p,8a,8b,8p,1f6,p,a,8p,8b,2c6,2d6,2e6,e,8p,8f,8g,8p,1c6,p,d6,8p,8e6,1f.6,g,8p,8g,e.6,8p,d6,8p,8g,e.6,8p,d6,8p,8g,f.6,8p,e6,8p,8d6,2c6"},
{"smb:d=4,o=5,b=100:16e6,16e6,32p,8e6,16c6,8e6,8g6,8p,8g,8p,8c6,16p,8g,16p,8e,16p,8a,8b,16a#,8a,16g.,16e6,16g6,8a6,16f6,8g6,8e6,16c6,16d6,8b,16p,8c6,16p,8g,16p,8e,16p,8a,8b,16a#,8a,16g.,16e6,16g6,8a6,16f6,8g6,8e6,16c6,16d6,8b,8p,16g6,16f#6,16f6,16d#6,16p,16e6,16p,16g#,16a,16c6,16p,16a,16c6,16d6,8p,16g6,16f#6,16f6,16d#6,16p,16e6,16p,16c7,16p,16c7,16c7,p,16g6,16f#6,16f6,16d#6,16p,16e6,16p,16g#,16a,16c6,16p,16a,16c6,16d6,8p,16d#6,8p,16d6,8p,16c6"},
{"Zelda1:d=4,o=5,b=125:a#,f.,8a#,16a#,16c6,16d6,16d#6,2f6,8p,8f6,16f.6,16f#6,16g#.6,2a#.6,16a#.6,16g#6,16f#.6,8g#.6,16f#.6,2f6,f6,8d#6,16d#6,16f6,2f#6,8f6,8d#6,8c#6,16c#6,16d#6,2f6,8d#6,8c#6,8c6,16c6,16d6,2e6,g6,8f6,16f,16f,8f,16f,16f,8f,16f,16f,8f,8f,a#,f.,8a#,16a#,16c6,16d6,16d#6,2f6,8p,8f6,16f.6,16f#6,16g#.6,2a#.6,c#7,c7,2a6,f6,2f#.6,a#6,a6,2f6,f6,2f#.6,a#6,a6,2f6,d6,2d#.6,f#6,f6,2c#6,a#,c6,16d6,2e6,g6,8f6,16f,16f,8f,16f,16f,8f,16f,16f,8f,8f"},
{"dkong:d=4,o=5,b=160:2c,8d.,d#.,c.,16b,16c6,16b,16c6,16b,16c6,16b,16c6,16b,16c6,16b,16c6,16b,2c6"}};


/** D E C L A R A T I O N S *******************************************/
#pragma code    // declare executable instructions

//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  void main (void)
 *  \brief Main function
 *
 *  \return void
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
void main (void)
{
char Cpt_time_hot=0;
static unsigned char valeur_song=0;
char tmp_str[50];
unsigned char temp;
unsigned int Vana_calcul, Temp_calcul_cold, Temp_calcul_hot;

OSCCON = 0;

#if (POWER_SUPPLY_MODE == CONFIG_CONST_32MHZ)
// 5mA @ 3V
GEN_SetPicFrequency(FREQ_32MHZ);
#elif (POWER_SUPPLY_MODE == CONFIG_CONST_4MHZ)
//5mA
GEN_SetPicFrequency(FREQ_4MHZ);
#else
// 5mA @ 3V
GEN_SetPicFrequency(FREQ_32MHZ);
#endif
while(!OSCCONbits.HFIOFS);  //wait HF frequency is stable

// Init Timer0
TICK_Init();             // now enables timer interrupt.

//Init Timer1 for 1s
//Timer0_Init();

//Voltage reference config
//VREFCON1bits.D1EN = 1;
VREFCON0bits.FVR1S0 = 0;   // Internal 2.048v ref
VREFCON0bits.FVR1S1 = 1;   // Internal 2.048v ref
VREFCON0bits.FVR1EN = 1;
while(!VREFCON0bits.FVR1ST);

// Init ADC
ADC_Init(); //

// Set up global interrupts
RCONbits.IPEN = 1;          // Enable priority levels on interrupts
INTCONbits.GIEL = 1;        // Low priority interrupts allowed
INTCONbits.GIEH = 1;        // Interrupting enabled.

//disabled all pullup
WPUA = 0;
WPUB = 0;
INTCON2bits.RABPU = 1; // disable pull up

// UART config
UARTIntInit();

// output configuration
TRIS_LED_OUT = OUTPUT_PIN;
TRIS_PIEZZO_OUT = OUTPUT_PIN;

// Photoresistor configuration
TRIS_PHOTO_VCC = OUTPUT_PIN; // output for VCC photoresistor
SET_PHOTO_VCC = 1; //
ANSELbits.ANS3 = 1; // analog input enable on AN3
TRIS_PHOTO_ANALOG = INPUT_PIN;// input config for analog

// MPC9700 "temp_cold" configuration
TRIS_TEMP_COLD_VCC = OUTPUT_PIN; // output for VCC
SET_TEMP_COLD_VCC = 1; //
ANSELbits.ANS5 = 1; // analog input enable on AN5
TRIS_TEMP_COLD_ANALOG = INPUT_PIN;// input config for analog

// MPC9700 "temp_hot" configuration
TRIS_TEMP_HOT_VCC = OUTPUT_PIN; // output for VCC
SET_TEMP_HOT_VCC = 1; //
ANSELHbits.ANS9 = 1; // analog input enable on AN9
TRIS_TEMP_HOT_ANALOG = INPUT_PIN;// input config for analog

// config BUTTON INPUT
INTCON2bits.RABPU = 0; // enable pull up on port A
ANSELbits.ANS2 = 0; // digital input enable on AN2
WPUAbits.WPUA2 = 1; // pullup enable on RA2
TRIS_BUTTON_IN = INPUT_PIN; // RA2 = input
// INT2 configuration
INTCON2bits.INTEDG2 = 0;
INTCON3bits.INT2E = 1;
INTCON3bits.INT2P = 1;
INTCON3bits.INT2F = 0;


// SPECIAL FOR FOR VERSION : 1 RELAY + 1 LED RGB OUTPUT
//PWM_Init();                     // Init PWM generator

RTTTL_Init();    // init RTTTL module and timer 3

SET_LED_OUT = 1;    // LED on during stating

TRIS_CONFIG_MODE_2 = OUTPUT_PIN;
SET_CONFIG_MODE_2 = 0;
TRIS_CONFIG_MODE_1 = OUTPUT_PIN;
SET_CONFIG_MODE_1 = 0;
TRIS_CONFIG_MODE_3 = OUTPUT_PIN;
SET_CONFIG_MODE_3 = 0;

//if (!RCONbits.TO)
//{
//    SET_LED_OUT = 1;
//    while(1);
//
//}

TICK_Set(TICK_MAIN_MESURE,500);
UART1_put_stringROM(start_str); // hello word message !

        
while (1)
    {

      if(TICK_Is_Elapse(TICK_MAIN_MESURE))
      {
      //start mesure
        Vana_calcul = ADC_Convert(ANA_TEMP_COLD_ANALOG);
        Vana_calcul = (unsigned int)(Vana_calcul<<1);  //(Vana_calcul*2048)/1024  // en mV
        Temp_calcul_cold = (unsigned int)((Vana_calcul-500)/10); // Calcul température
        Vana_calcul = ADC_Convert(ANA_TEMP_HOT_ANALOG);
        Vana_calcul = (unsigned int)(Vana_calcul<<1);  //(Vana_calcul*2048)/1024  // en mV
        Temp_calcul_hot = (unsigned int)((Vana_calcul-500)/10); // Calcul température affichage en
        //sprintf(tmp_str,"Vcc=%d mV| Cold=%d deg | Hot=%d deg\r\n",Vcc_measure(), Temp_calcul_cold ,Temp_calcul_hot);

        for (temp=0;temp<45;temp++) tmp_str[temp] =0;   //clear text string

        // calcul
        if (Temp_calcul_hot > (Temp_calcul_cold + OFFSET_TEMP1))
        {
            if (Cpt_time_hot> WAKEUP_NUMBER1)
            {
                GEN_SetPicFrequency(FREQ_32MHZ);
                play_rtttl(song3[valeur_song]);
                GEN_SetPicFrequency(FREQ_4MHZ);
                valeur_song++;
                if (valeur_song>6) valeur_song=0;
            }
            Cpt_time_hot ++;
            sprintf(tmp_str,"Vcc=%d mV| Hot=%d deg | Cold=%d deg | >%ddeg num:%d\r\n",Vcc_measure(), Temp_calcul_hot,Temp_calcul_cold,OFFSET_TEMP1,Cpt_time_hot);

        }
        else
        {
            Cpt_time_hot = 0 ; // normal temperature, reset counter
            sprintf(tmp_str,"Vcc=%d mV| Hot=%d deg | Cold=%d deg | no detect\r\n",Vcc_measure(), Temp_calcul_hot,Temp_calcul_cold);
        }

        //Prepare Sleeping
        Before_Sleep();
        //Sleep !
        OSCCONbits.IDLEN = 0;   // sleep mode
        Sleep();    // start sleep mode
        // wakeup ! by button or watchdog
        After_Sleep();

        // Send data
        //sprintf(tmp_str,"Cpt_wakeup=%d | Cold=%d deg | Hot=%d deg\r\n",Cpt_wakeup, Temp_calcul_cold ,Temp_calcul_hot);
        UART1_put_stringRAM(tmp_str);
       
        // set tick for strating mesure after x ms
        TICK_Set(TICK_MAIN_MESURE,100);
        //SET_LED_OUT = 1;

      }

      if(TICK_Is_Elapse(TICK_BUTTON_SCAN))
      {
        TICK_Set(TICK_BUTTON_SCAN,10);  //10ms // anti rebond

        if (READ_BUTTON_IN == 0) // if the button has been pressed
        {
            Cpt_time_hot = -1 ; //reset compteur Cpt_time_hot or stop alarm
             SET_LED_OUT = 1;

        }
      }

      // Bluetooth Reception gestion
//      BCM_ReceiveUART();  // read RX buffer if a byte or trame has been receved
//
//      if(Board_Struct.FlagRx) // if data trame has been receved
//        {
//          Board_Struct.FlagRx=0;  // reset flag
//          BCM_Decode();  //decode trame only if a true message has been receved
//        }
//
//      if (Board_Struct.FlagTx) // if data trame must be send
//      {
//          Board_Struct.FlagTx = 0; //reset flag
//          BCM_Encode();
//          BCM_Transmit(&BlueCom_Data_TX); // transmit command return + data
//      }

      ClrWdt(); //reset watctdog
        //IDLE MODE
        //OSCCONbits.IDLEN = 1;   // IDLE mode
        //Sleep();    // start idle mode
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  void ADC_Init(void)
 *  \brief This fonction initialise the ADC
 *
 *  \return void
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
void ADC_Init(void)
{ // initialize the Analog-To-Digital converter.
    ANSEL = 0;	//turn off all other analog inputs
    ANSELH = 0;
    // Sets bits VCFG1 and VCFG0 in ADCON1 so the ADC voltage reference is VSS to VDD
    ADCON1bits.PVCFG = 0b10;  // Positive voltage reference supplied internally through FVR
    ADCON1bits.NVCFG = 0b00; // VSS for vref-
    // The ADC clock must as short as possible but still greater than the
    // minimum TAD time, datasheet parameter 130.  At the time this lesson was
    // written TAD minimum for the PIC18F45K20 is 1.4us.
    // At 1MHz clock, selecting ADCS = FOSC/2 = 500kHz.  One clock period
    // 1 / 500kHz = 2us, which greater than minimum required 1.4us.
    // So ADCON2 bits ADCS2-0 = 000
    //
    // The ACQT aquisition time should take into accound the internal aquisition
    // time TACQ of the ADC, datasheet paramter 130, and the settling time of
    // of the application circuit connected to the ADC pin.  Since the actual
    // settling time of the RC circuit with the demo board potentiometer is very
    // long but accuracy is not very important to this demo, we'll set ACQT2-0 to
    // 20TAD = 111
    //
    // ADFM = 1 A/D result is right justified
    // Special Function Register
    ADCON2 = 0b10111110;

    // Select channel 0 (AN0) to read the potentiometer voltage
    ADCON0bits.CHS = 0 ; //AN0
    //and turn on ADC
    ADCON0bits.ADON = 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  unsigned int ADC_Convert(unsigned char ANchannel)
 *  \brief This fonction read a analog input
 *  \param ANchannel : Anx select
 *  \return
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
unsigned int ADC_Convert(unsigned char ANchannel)
{ // start an ADC conversion and return the result
    unsigned int result=0;
    ADCON0bits.CHS = ANchannel ; //select channel
    ADCON0bits.ADON = 1;

    ADCON0bits.GO_DONE = 1;             // start conversion
    while (ADCON0bits.GO_DONE == 1);    // wait for it to complete
    //result = (result | ADRESH) << 8;
    //result = result |  ADRESL;
    ADCON0bits.ADON = 0;  //adc off
    result = (((unsigned int)ADRESH)<<8)|(ADRESL);
    return result;                      // return high byte of result
}

//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  void Timer0_Init(void)
 *  \brief This fonction initialise the timer 0
 *
 *  \return
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
void Timer0_Init(void)
{
   // initialisation du timer
    // Set up Interrupts for timer
    INTCONbits.TMR0IF = 0;          // clear roll-over interrupt flag
    INTCON2bits.TMR0IP = 0;         // Timer0 is low priority interrupt
    INTCONbits.TMR0IE = 1;          // enable the Timer0 interrupt.
    // Set up timer itself
    /*
    // Timer0 Registers:// 16-Bit Mode; Prescaler=1:128; TMRH Preset=B; TMRL Preset=DC; Freq=1,00Hz; Period=1 000,00 ms
    T0CONbits.TMR0ON = 0;// Timer0 On/Off Control bit:1=Enables Timer0 / 0=Stops Timer0
    T0CONbits.T08BIT = 0;// Timer0 8-bit/16-bit Control bit: 1=8-bit timer/counter / 0=16-bit timer/counter
    T0CONbits.T0CS   = 0;// TMR0 Clock Source Select bit: 0=Internal Clock (CLKO) / 1=Transition on T0CKI pin
    T0CONbits.T0SE   = 0;// TMR0 Source Edge Select bit: 0=low/high / 1=high/low
    T0CONbits.PSA    = 0;// Prescaler Assignment bit: 0=Prescaler is assigned; 1=NOT assigned/bypassed
    T0CONbits.T0PS2  = 1;// bits 2-0  PS2:PS0: Prescaler Select bits
    T0CONbits.T0PS1  = 1;
    T0CONbits.T0PS0  = 0;
    */
    T0CON = GEN_Energy_data.Timer0_T0CON;
   // initialisation de tout les ticks
    TMR0H = GEN_Energy_data.Timer0_TMR0H;                      // 1s config
    TMR0L = GEN_Energy_data.Timer0_TMR0L;

    INTCONbits.TMR0IF = 0;          // clear (reset) flag
    T0CONbits.TMR0ON = 1;           // start timer
}
#define Timer0_On() T0CONbits.TMR0ON = 1
#define Timer0_Off() T0CONbits.TMR0ON = 0

//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  void Before_Sleep(void)
 *  \brief This fonction prepare the PIC for sleep mode and/or configures the PIC pins for low energy
 *
 *  \return
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
void Before_Sleep(void)
{
    SET_TEMP_HOT_VCC = 0;  //set off temperature hot MCP9700
    SET_PHOTO_VCC = 0; //set off photoresistor
    SET_TEMP_COLD_VCC = 0;  //set off temperature cold MCP9700
    SET_LED_OUT = 0;    //LED OFF
    SET_PIEZZO_OUT = 0;
    SET_CMD_OUT = 0;

    TRIS_TEMP_COLD_ANALOG = OUTPUT_PIN ;
    TRIS_TEMP_HOT_ANALOG = OUTPUT_PIN ;
    TRIS_PHOTO_ANALOG = OUTPUT_PIN ;
    LATCbits.LATC7 = 0; //SET_TEMP_HOT_ANALOG
    LATCbits.LATC1 = 0; //SET_TEMP_COLD_ANALOG
    LATAbits.LATA4 = 0; //SET_PHOTO_ANALOG

    TRIS_CONFIG_MODE_1 = OUTPUT_PIN ;   // previously configurated
    TRIS_CONFIG_MODE_2 = OUTPUT_PIN ;   // previously configurated
    TRIS_CONFIG_MODE_3 = OUTPUT_PIN ;   // previously configurated
    SET_CONFIG_MODE_1 = 0 ;
    SET_CONFIG_MODE_2 = 0 ;
    SET_CONFIG_MODE_3 = 0 ;

    //RS232
    TX_COM_TRIS = OUTPUT_PIN ;
    RX_COM_TRIS  = INPUT_PIN ;

    // PIN prog
    TRIS_PGD  = OUTPUT_PIN ;
    TRIS_PGC  = OUTPUT_PIN ;


//      OSCCONbits.IRCF = 0b000;    // On PIC18F14K22: IRCFx = 110 -> 8Mhz
//      OSCTUNEbits.PLLEN = 0;      // x4 PLL enabled --> 32Mz
//      OSCCON2bits.PRI_SD = 0;
//      OSCTUNEbits.INTSRC = 0;
    //ANSEL =  0b11111111;  //DIGITAL input
    //ANSELH = 0b00001111 ; //DIGITAL input
    Timer0_Off();
    VREFCON0bits.FVR1EN = 0; // Vref Off
    ADCON0bits.ADON = 0;  //adc off

}
//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  void After_Sleep(void)
 *  \brief This fonction wakeup the PIC pin after sleep mode
 *
 *  \return
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
void After_Sleep(void)
{
// Photoresistor configuration
TRIS_PHOTO_VCC = OUTPUT_PIN; // output for VCC photoresistor
SET_PHOTO_VCC = 1; //
ANSELbits.ANS3 = 1; // analog input enable on AN3
TRIS_PHOTO_ANALOG = INPUT_PIN;// input config for analog

// MPC9700 "temp_cold" configuration
TRIS_TEMP_COLD_VCC = OUTPUT_PIN; // output for VCC
SET_TEMP_COLD_VCC = 1; //
ANSELbits.ANS5 = 1; // analog input enable on AN5
TRIS_TEMP_COLD_ANALOG = INPUT_PIN;// input config for analog

// MPC9700 "temp_hot" configuration
TRIS_TEMP_HOT_VCC = OUTPUT_PIN; // output for VCC
SET_TEMP_HOT_VCC = 1; //
ANSELHbits.ANS9 = 1; // analog input enable on AN9
TRIS_TEMP_HOT_ANALOG = INPUT_PIN;// input config for analog

// output configuration
//TRIS_LED_OUT = OUTPUT_PIN;
//TRIS_PIEZZO_OUT = OUTPUT_PIN;

TRIS_CONFIG_MODE_1 = OUTPUT_PIN ;
TRIS_CONFIG_MODE_1 = OUTPUT_PIN ;
TRIS_CONFIG_MODE_1 = OUTPUT_PIN ;
SET_CONFIG_MODE_1 = 0 ;
SET_CONFIG_MODE_2 = 0 ;
SET_CONFIG_MODE_3 = 0 ;

//RS232
TX_COM_TRIS = OUTPUT_PIN ;
RX_COM_TRIS  = INPUT_PIN ;

ADCON0bits.ADON = 1;  //adc on

VREFCON0bits.FVR1EN = 1;
while(!VREFCON0bits.FVR1ST);


}

//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  unsigned intVcc_measure(void)
 *  \brief This fonction mesure vcc
 *
 *  \return Vcc mesure in mV (unsigned int)
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
unsigned int Vcc_measure(void) {
    unsigned int ref = 0;
    unsigned int vdd_int = 0;
    unsigned char save1,save2,save3,save4;
    //save previous value
    save1 = VREFCON0;
    save2 = ADCON0;
    save3 = ADCON1;
    save4 = ADCON2;

//init
    VREFCON0bits.FVR1S0 = 1;   // Internal 1024mv ref
    VREFCON0bits.FVR1S1 = 0;   // Internal 1024mv ref
    VREFCON0bits.FVR1EN = 1;                // Enable FVR module
    while(!VREFCON0bits.FVR1ST);              // Wait for FVR to be stable

    ADCON2bits.ADFM = 1;        // Right justify result
    ADCON0bits.CHS = 0b1111;   // FVR is ADC input
    ADCON1bits.PVCFG = 0b00;    // Positive ref is Vdd (default)
    ADCON1bits.NVCFG = 0b00;    // Negative ref is GND (default)
    ADCON0bits.ADON = 1;        // Turn on ADC module
// end of init
    ADCON2bits.ADFM = 1;        // Right justify result
    ADCON0bits.GO = 1;
    while (!ADCON0bits.DONE);

    ref = (((unsigned int)ADRESH)<<8)|(ADRESL);

    // Fixed point math only
    //float vdd = (1024.0 / adc_val) * 1.024;
    vdd_int = 1048576L / ref;

    //restaure previous values
    VREFCON0 = save1;
    ADCON0 = save2;
    ADCON1 = save3;
    ADCON2 = save4;

    return vdd_int;
}
