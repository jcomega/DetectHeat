/* 
 * File:   RTTTLtone.h
 * Author: Jean-Christophe
 *
 * Created on 15 janvier 2014, 18:46
 */

#ifndef RTTTLtone_H
#define	RTTTLtone_H


#define PIEZZO_OUT              SET_PIEZZO_OUT
#define CONF_PIEZZO_OUT        TRIS_PIEZZO_OUT
//#define PIEZZO_OUT              SET_CONFIG_MODE_2
//#define CONF_PIEZZO_OUT        TRIS_CONFIG_MODE_2

#define GetPeripheralClock32Mhz()    ((32000000ul) / 4)

/*************************************************
* Public Constants
*************************************************/

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  GetPeripheralClock32Mhz()/123
#define NOTE_C3  GetPeripheralClock32Mhz()/131
#define NOTE_CS3 GetPeripheralClock32Mhz()/139
#define NOTE_D3  GetPeripheralClock32Mhz()/147
#define NOTE_DS3 GetPeripheralClock32Mhz()/156
#define NOTE_E3  GetPeripheralClock32Mhz()/165
#define NOTE_F3  GetPeripheralClock32Mhz()/175
#define NOTE_FS3 GetPeripheralClock32Mhz()/185
#define NOTE_G3  GetPeripheralClock32Mhz()/196
#define NOTE_GS3 GetPeripheralClock32Mhz()/208
#define NOTE_A3  GetPeripheralClock32Mhz()/220
#define NOTE_AS3 GetPeripheralClock32Mhz()/233
#define NOTE_B3  GetPeripheralClock32Mhz()/247
#define NOTE_C4  GetPeripheralClock32Mhz()/262
#define NOTE_CS4 GetPeripheralClock32Mhz()/277
#define NOTE_D4  GetPeripheralClock32Mhz()/294
#define NOTE_DS4 GetPeripheralClock32Mhz()/311
#define NOTE_E4  GetPeripheralClock32Mhz()/330
#define NOTE_F4  GetPeripheralClock32Mhz()/349
#define NOTE_FS4 GetPeripheralClock32Mhz()/370
#define NOTE_G4  GetPeripheralClock32Mhz()/392
#define NOTE_GS4 GetPeripheralClock32Mhz()/415
#define NOTE_A4  GetPeripheralClock32Mhz()/440
#define NOTE_AS4 GetPeripheralClock32Mhz()/466
#define NOTE_B4  GetPeripheralClock32Mhz()/494
#define NOTE_C5  GetPeripheralClock32Mhz()/523
#define NOTE_CS5 GetPeripheralClock32Mhz()/554
#define NOTE_D5  GetPeripheralClock32Mhz()/587
#define NOTE_DS5 GetPeripheralClock32Mhz()/622
#define NOTE_E5  GetPeripheralClock32Mhz()/659
#define NOTE_F5  GetPeripheralClock32Mhz()/698
#define NOTE_FS5 GetPeripheralClock32Mhz()/740
#define NOTE_G5  GetPeripheralClock32Mhz()/784
#define NOTE_GS5 GetPeripheralClock32Mhz()/831
#define NOTE_A5  GetPeripheralClock32Mhz()/880
#define NOTE_AS5 GetPeripheralClock32Mhz()/932
#define NOTE_B5  GetPeripheralClock32Mhz()/988
#define NOTE_C6  GetPeripheralClock32Mhz()/1047
#define NOTE_CS6 GetPeripheralClock32Mhz()/1109
#define NOTE_D6  GetPeripheralClock32Mhz()/1175
#define NOTE_DS6 GetPeripheralClock32Mhz()/1245
#define NOTE_E6  GetPeripheralClock32Mhz()/1319
#define NOTE_F6  GetPeripheralClock32Mhz()/1397
#define NOTE_FS6 GetPeripheralClock32Mhz()/1480
#define NOTE_G6  GetPeripheralClock32Mhz()/1568
#define NOTE_GS6 GetPeripheralClock32Mhz()/1661
#define NOTE_A6  GetPeripheralClock32Mhz()/1760
#define NOTE_AS6 GetPeripheralClock32Mhz()/1865
#define NOTE_B6  GetPeripheralClock32Mhz()/1976
#define NOTE_C7  GetPeripheralClock32Mhz()/2093
#define NOTE_CS7 GetPeripheralClock32Mhz()/2217
#define NOTE_D7  GetPeripheralClock32Mhz()/2349
#define NOTE_DS7 GetPeripheralClock32Mhz()/2489
#define NOTE_E7  GetPeripheralClock32Mhz()/2637
#define NOTE_F7  GetPeripheralClock32Mhz()/2794
#define NOTE_FS7 GetPeripheralClock32Mhz()/2960
#define NOTE_G7  GetPeripheralClock32Mhz()/3136
#define NOTE_GS7 GetPeripheralClock32Mhz()/3322
#define NOTE_A7  GetPeripheralClock32Mhz()/3520
#define NOTE_AS7 GetPeripheralClock32Mhz()/3729
#define NOTE_B7  GetPeripheralClock32Mhz()/3951
#define NOTE_C8  GetPeripheralClock32Mhz()/4186
#define NOTE_CS8 GetPeripheralClock32Mhz()/4435
#define NOTE_D8  GetPeripheralClock32Mhz()/4699
#define NOTE_DS8 GetPeripheralClock32Mhz()/4978

#define isdigit(n) (n >= '0' && n <= '9')

//void RTTTL_Player(void);
void RTTTL_Start_PlayNote(unsigned short note, unsigned char octave, unsigned int duration);
unsigned char RTTTL_IsPlaying_PlayNote(void);
void RTTTL_Stop_PlayNote(void);
void RTTTL_Beep(void);
void RTTTL_Init(void);
void play_rtttl(rom const char *p);
void play(void);

# define RTTTL_Enable() \
                            PIE2bits.TMR3IE = 1;\
                            PIR2bits.TMR3IF = 0;\
                            T3CONbits.TMR3ON  = 1;
# define RTTTL_Disable() \
                            PIE2bits.TMR3IE = 0;\
                            PIR2bits.TMR3IF = 0;\
                            T3CONbits.TMR3ON  = 0;

#endif	/* RTTTLtone_H */

