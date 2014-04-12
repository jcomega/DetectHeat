/*****************************************************************************/
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#include "../Includes/device.h"
#include "../Includes/Gest_Energy.h"



#pragma udata   // declare statically allocated uinitialized variables

ENERGY_STRUCTURE    GEN_Energy_data;



#pragma code    // declare executable instructions

//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  GEN_SetPicFrequency(unsigned char Freq_Value)
 *  \brief This fonction change the PIC frequency and the pheripheric parameter
 *  \param Speed mode
 *  \return none
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
void GEN_SetPicFrequency(unsigned char Freq_Value)
{
    static unsigned char Prev_Freq_Value = 0; //no previous value


    if (Freq_Value == Prev_Freq_Value) return;

    switch (Freq_Value)
    {
        case FREQ_32MHZ:
            // set PIC frequency @ 32Mhz
        GEN_Energy_data.PIC_Freq = FREQ_32MHZ;
        Prev_Freq_Value = FREQ_32MHZ;
        OSCCONbits.IRCF = 0b110;    // On PIC18F14K22: IRCFx = 110 -> 8Mhz
        OSCTUNEbits.PLLEN = 1;      // x4 PLL enabled --> 32Mz
        // Timer 0
        GEN_Energy_data.Timer0_T0CON = T0CON_32MHZ;
        GEN_Energy_data.Timer0_TMR0H = TMR0H_32MHZ;
        GEN_Energy_data.Timer0_TMR0L = TMR0L_32MHZ;
        // Update important value to update timer
        T0CON = GEN_Energy_data.Timer0_T0CON;
        // Timer 1
        GEN_Energy_data.Timer1_TMR1H = TMR1H_32MHZ;
        GEN_Energy_data.Timer1_TMR1L = TMR1L_32MHZ;

        //UART
        GEN_Energy_data.Uart_SPBRG = SPBRG_VAL_32MHZ;
        SPBRG = SPBRG_VAL_32MHZ;
        break;

        case FREQ_4MHZ:
            // set PIC frequency @ 4Mhz
        GEN_Energy_data.PIC_Freq = FREQ_4MHZ;
        Prev_Freq_Value = FREQ_4MHZ;
        OSCCONbits.IRCF = 0b101;    // On PIC18F14K22: IRCFx = 101 -> 4 Mhz
        OSCTUNEbits.PLLEN = 0;      // x4 PLL off
        // Timer 0
        GEN_Energy_data.Timer0_T0CON = T0CON_4MHZ;
        GEN_Energy_data.Timer0_TMR0H = TMR0H_4MHZ;
        GEN_Energy_data.Timer0_TMR0L = TMR0L_4MHZ;
        // Update important value to update timer
        T0CON = GEN_Energy_data.Timer0_T0CON;
        // Timer 1
        GEN_Energy_data.Timer1_TMR1H = TMR1H_4MHZ;
        GEN_Energy_data.Timer1_TMR1L = TMR1L_4MHZ;
        //UART
        GEN_Energy_data.Uart_SPBRG = SPBRG_VAL_4MHZ;
        SPBRG = SPBRG_VAL_4MHZ;
        break;

        default:
            // FREQ_32MHZ mode
        GEN_Energy_data.PIC_Freq = FREQ_32MHZ;
        Prev_Freq_Value = FREQ_32MHZ;
        OSCCONbits.IRCF = 0b110;    // On PIC18F14K22: IRCFx = 110 -> 8Mhz
        OSCTUNEbits.PLLEN = 1;      // x4 PLL enabled --> 32Mz
        // Timer 0
        GEN_Energy_data.Timer0_T0CON = T0CON_32MHZ;
        GEN_Energy_data.Timer0_TMR0H = TMR0H_32MHZ;
        GEN_Energy_data.Timer0_TMR0L = TMR0L_32MHZ;
        // Update important value to update timer
        T0CON = GEN_Energy_data.Timer0_T0CON;
        // Timer 1
        GEN_Energy_data.Timer1_TMR1H = TMR1H_32MHZ;
        GEN_Energy_data.Timer1_TMR1L = TMR1L_32MHZ;
        //UART
        GEN_Energy_data.Uart_SPBRG = SPBRG_VAL_32MHZ;
        SPBRG = SPBRG_VAL_32MHZ;
        break;
    }

}

//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  unsigned char GEN_GetPicFrequency()
 *  \brief This fonction change the PIC frequency
 *
 *  \return PIC fequency
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
unsigned char GEN_GetPicFrequency()
{
    return  GEN_Energy_data.PIC_Freq;
}