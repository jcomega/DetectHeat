//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \file device.h
 *	\brief File definition for the project
 *  \version v0.0.0
 *  \date 05/05/12
 *  \author Jean-Christophe Papelard
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
//		version	|  Date		|  Author   		| 	Modification
//--------------------------------------------------------------------------------------------------------------------------------------------
//		v0.0.1	|  05/05/12	| Jean-Christophe Papelard	|	Creation
//--------------------------------------------------------------------------------------------------------------------------------------------

#ifndef DEVICE_H
#define DEVICE_H

#include "p18lf14k22.h"

//#define VERSION_SOFT_DETECTHEAT		06 	// 1.0.
#define SOFT_REVISION_1     0
#define SOFT_REVISION_2     0
#define SOFT_REVISION_3     0
// Version = SOFT_REVISION_1.SOFT_REVISION_2.SOFT_REVISION_3
// example : 0.9.3

#define BOARD_TYPE DETECT_HEAT_UART             // select type of board
#define POWER_SUPPLY_MODE CONFIG_CONST_4MHZ    // select power supply mode

//remplace the previous code by :
#define DETECT_HEAT             1    // Sdandard Detect_Heat configuration
#define DETECT_HEAT_UART        2    // TBD


#define CONFIG_CONST_32MHZ      1   //full 8*4 Mhz (Pll ON) : 5mA @ 3V
#define CONFIG_CONST_4MHZ       2   // Standard eco mod : constant @ 4Mhz  :


//--------------------------------------------------------------------------------------------------------------------------------------------
/** \name 		P R O T O T Y P E S
*
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
void Timer0_Init(void);
void ADC_Init(void);
unsigned int ADC_Convert(unsigned char ANchannel);
void Before_Sleep(void);
void After_Sleep(void);

unsigned int Vcc_measure(void);

//--------------------------------------------------------------------------------------------------------------------------------------------
/** \name 		 D E C L A R A T I O N S
*
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
typedef enum {false, true} Bool;

//--------------------------------------------------------------------------------------------------------------------------------------------
/** \name 		Definition  for main flag for this programme :
*
 */
//--------------------------------------------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------------------------------------
/** \name 		External references definition for PORT I/O :
*
 */
//--------------------------------------------------------------------------------------------------------------------------------------------

//@{

    #define READ_DIGITAL_INPUT0 PORTAbits.RA2
    #define READ_DIGITAL_INPUT1 PORTAbits.RA3

    #define TRIS_DIGITAL_OUTPUT0 TRISBbits.TRISB6
    #define READ_DIGITAL_OUTPUT0 PORTBbits.RB6
    #define SET_DIGITAL_OUTPUT0 LATBbits.LATB6

//@{
//! \name UART for config,debug,bluetooth:
    #define TX_COM_TRIS TRISBbits.TRISB7
    #define RX_COM_TRIS TRISBbits.TRISB5
//@}
//  INPUT/OUTPUT FOR PGD/PGC
    #define TRIS_PGD       TRISAbits.TRISA0
    #define SET_PGD        LATAbits.LATA0
    #define READ_PGD       PORTAbits.RA0

    #define TRIS_PGC       TRISAbits.TRISA1
    #define SET_PGC        LATAbits.LATA1
    #define READ_PGC       PORTAbits.RA1

//  INPUT/OUTPUT FOR BUTTON INPUT
    #define TRIS_BUTTON_IN       TRISAbits.TRISA2
    #define SET_BUTTON_IN        LATAbits.LATA2
    #define READ_BUTTON_IN       PORTAbits.RA2

//  INPUT/OUTPUT FOR COMMAND OUTPUT
    #define TRIS_CMD_OUT       TRISAbits.TRISA5
    #define SET_CMD_OUT        LATAbits.LATA5
    #define READ_CMD_OUT       PORTAbits.RA5

//  INPUT/OUTPUT FOR PIEZZO BUZZER
    #define TRIS_PIEZZO_OUT       TRISBbits.TRISB4
    #define SET_PIEZZO_OUT        LATBbits.LATB4
    #define READ_PIEZZO_OUT       PORTBbits.RB4

//  INPUT/OUTPUT FOR LED STATUS
    #define TRIS_LED_OUT       TRISBbits.TRISB6
    #define SET_LED_OUT        LATBbits.LATB6
    #define READ_LED_OUT       PORTBbits.RB6

// INPUT/OUTPUT FOR PHOTO RESISTOR
    #define TRIS_PHOTO_VCC        TRISCbits.TRISC3
    #define SET_PHOTO_VCC         LATCbits.LATC3
    #define READ_PHOTO_VCC        PORTCbits.RC3

    #define TRIS_PHOTO_ANALOG    TRISAbits.TRISA4
    #define ANA_PHOTO_ANALOG     3                  //AN3

// INPUT/OUTPUT FOR TEMPERATURE SENSOR
    #define TRIS_TEMP_COLD_ANALOG    TRISCbits.TRISC1
    #define ANA_TEMP_COLD_ANALOG     5                  //AN5

    #define TRIS_TEMP_HOT_ANALOG     TRISCbits.TRISC7
    #define ANA_TEMP_HOT_ANALOG      9                  //AN9

    #define TRIS_TEMP_COLD_VCC       TRISCbits.TRISC0
    #define SET_TEMP_COLD_VCC        LATCbits.LATC0
    #define READ_TEMP_COLD_VCC       PORTCbits.RC0

    #define TRIS_TEMP_HOT_VCC        TRISCbits.TRISC2
    #define SET_TEMP_HOT_VCC         LATCbits.LATC2
    #define READ_TEMP_HOT_VCC        PORTCbits.RC2

//  INPUT/OUTPUT FOR CONFIG MODE
    #define TRIS_CONFIG_MODE_1       TRISCbits.TRISC4
    #define SET_CONFIG_MODE_1        LATCbits.LATC4
    #define READ_CONFIG_MODE_1       PORTCbits.RC4
    #define PWM_OUTPUT1              LATCbits.LATC4    // PWM output for red (test)

    #define TRIS_CONFIG_MODE_2       TRISCbits.TRISC5
    #define SET_CONFIG_MODE_2        LATCbits.LATC5
    #define READ_CONFIG_MODE_2       PORTCbits.RC5
    #define PWM_OUTPUT2              LATCbits.LATC5    // PWM output for green (test)

    #define TRIS_CONFIG_MODE_3       TRISCbits.TRISC6
    #define SET_CONFIG_MODE_3        LATCbits.LATC6
    #define READ_CONFIG_MODE_3       PORTCbits.RC6
    #define PWM_OUTPUT3              LATCbits.LATC6    // PWM output for blue (test)

    #define INPUT_PIN 1
    #define OUTPUT_PIN 0


    #define VCC_BAT_ANALOG     0b1111                  //AN3
//@}
//--------------------------------------------------------------------------------------------------------------------------------------------
//	Enumeration definition
//--------------------------------------------------------------------------------------------------------------------------------------------

typedef enum
{
BC_STATUS_OK= 1,
BC_STATUS_FAIL,
BC_STATUS_DEGRADED,
BC_STATUS_OTHER
}BOARD_Status;

//--------------------------------------------------------------------------------------------------------------------------------------------
/** \name 		E X T E R N S : declare variables accessible by other files.
*
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
typedef struct {
BOARD_Status Board_Status;

unsigned char FlagRx;    // = 1 if a message has been receved
unsigned char FlagTx;    // = 1 if a message must be transmit

}BOARD_STRUCTURE;

typedef struct {

unsigned char Command_return;
unsigned char Data0;
unsigned char Data1;
unsigned char Data2;
unsigned char Data3;
unsigned char Data4;
unsigned char Data5;
unsigned char Data6;
unsigned char Data7;
}UART_DATA;


typedef struct {

unsigned char pwm_red;      // PWM value for red
unsigned char pwm_green;    // PWM value for green
unsigned char pwm_blue;     // PWM value for blue

unsigned char status;  // 1= output active
}RGB_PWM_LED_STRUCTURE;

//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  GetSystemClock()
*  \brief This macro returns the system clock frequency in Hertz.
*			value is 8 MHz x 4 PLL for PIC24F
*			value is 8 MHz/2 x 18 PLL for PIC32
*                       value is x MHz x 4 PLL for PIC18F
*/
//--------------------------------------------------------------------------------------------------------------------------------------------

#if (POWER_SUPPLY_MODE == CONFIG_CONST_32MHZ)
// 5mA @ 3V
        #define GetSystemClock()    (32000000ul)
#elif (POWER_SUPPLY_MODE == CONFIG_CONST_4MHZ)
//5mA
        #define GetSystemClock()    (4000000ul)
#else
// 5mA @ 3V
        #define GetSystemClock()    (32000000ul)
#endif

// you must define too : UARTIntC.h     UART_CLOCK_FREQ

//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  GetPeripheralClock()
*  \brief This macro returns the peripheral clock frequency used in Hertz.
*			 value for PIC24 is <PRE>(GetSystemClock()/2) </PRE>
*			value for PIC32 is <PRE>(GetSystemClock()/(1<<OSCCONbits.PBDIV)) </PRE>
*
*/
//--------------------------------------------------------------------------------------------------------------------------------------------
        #define GetPeripheralClock()    (GetSystemClock() / 4)

//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  GetInstructionClock()
*  \brief This macro returns instruction clock frequency  used in Hertz.
*			 value for PIC24 is <PRE>(GetSystemClock()/2) </PRE>
*			value for PIC32 is <PRE>(GetSystemClock()) </PRE>
*                       value for PIC18 is <PRE>(GetSystemClock()/4) </PRE>
*/
//--------------------------------------------------------------------------------------------------------------------------------------------
        #define GetInstructionClock()   (GetSystemClock() / 4)


#endif
