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

#include "../Includes/BlueCom.h"
#include "../Includes/UARTintC.h"
//#include "../Includes/BC_pwm.h"
#include "../Includes/device.h"
#include "DetectHeat/Includes/GenericTypeDefs.h"


//--------------------------------------------------------------------------------------------------------------------------------------------
//	Global Variables definition
//--------------------------------------------------------------------------------------------------------------------------------------------
#pragma udata   // declare statically allocated uinitialized variables

unsigned char uBCM_RxBuffer[BLUECOM_RX_BUFFER_SIZE];

//unsigned char uMsgData[BLUECOM_TX_DATA_LENGTH];
BOARD_STRUCTURE Board_Struct;
UART_DATA BlueCom_Data_TX, BlueCom_Data_RX;
RGB_PWM_LED_STRUCTURE BlueCom_outputRGB;

#pragma code    // declare executable instructions

//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  unsigned char BCM_ReceiveUART(void)
 *  \brief This fonction read uart fifo and decode trame
 *
 *  \return 1 if data has been receved
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
unsigned char BCM_ReceiveUART(void)
{
    unsigned char uData;
    unsigned int wCpt;
    static unsigned char uRxBuffer[BLUECOM_RX_BUFFER_SIZE];
    static unsigned char uRxIdx;

    if (vUARTIntStatus.UARTIntRxBufferEmpty)             // if fifo is empty, quit this function
        return 0;

    while(!vUARTIntStatus.UARTIntRxBufferEmpty)
    {
        UARTIntGetChar(&uData);

        if(uRxIdx==0)
        {							// Waiting for STX ?
            if (uData==STX)
                uRxBuffer[uRxIdx++]=uData;		// Place data in buffer, update index and exit
            continue;
        }
        if(uRxIdx==1)
        {							// Waiting for NBR ?
            uRxBuffer[uRxIdx++]=uData;			// Place data in buffer
  
            continue;
        }
        if(uRxIdx==(uRxBuffer[1]-1))        //if(uRxIdx==(uRxBuffer[1]-1))
        {							// Last byte ?
            uRxBuffer[uRxIdx]=uData;			// Place data in buffer
            uRxIdx=0;					// Reset index to indicate that waiting for stx
            Board_Struct.FlagRx=1;                                   // Set flag message received at 1
            for (wCpt=0;wCpt<uRxBuffer[1];wCpt++) {
                uBCM_RxBuffer[wCpt]=uRxBuffer[wCpt];}	//copy buffer irq into normal buffer
            continue;
        }
        if (uRxIdx>=BLUECOM_RX_BUFFER_SIZE)
        {							// Test is buffer is full
            uRxIdx=0;					// buffer is full, reset index to abort
            continue;
        }							// and exit
        uRxBuffer[uRxIdx++]=uData;				// Place data in buffer, update index and exit (normal data)

        if (vUARTIntStatus.UARTIntRxError)
        {							// if overrun,
            uRxIdx=0;
            vUARTIntStatus.UARTIntRxError=0;
        }
    }

    return 1;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  unsigned char BCM_Decode(void)
 *  \brief This fonction decode trame and command the system
 *
 *  \return 1 if a information has been decoded, 0 if the information is bad
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
unsigned char BCM_Decode(void)
{
	if ((uBCM_RxBuffer[0]!=STX) || (uBCM_RxBuffer[1]!=BLUECOM_RX_TRAME_LENGTH) || (uBCM_RxBuffer[BLUECOM_RX_TRAME_LENGTH-1]!=ETX) ) return(0);   // bad trame receved

        BlueCom_Data_RX.Command_return = uBCM_RxBuffer[2];
        BlueCom_Data_RX.Data0 = uBCM_RxBuffer[3];
        BlueCom_Data_RX.Data1 = uBCM_RxBuffer[4];
        BlueCom_Data_RX.Data2 = uBCM_RxBuffer[5];
        BlueCom_Data_RX.Data3 = uBCM_RxBuffer[6];
        BlueCom_Data_RX.Data4 = uBCM_RxBuffer[7];
        BlueCom_Data_RX.Data5 = uBCM_RxBuffer[8];
        BlueCom_Data_RX.Data6 = uBCM_RxBuffer[9];
        BlueCom_Data_RX.Data7 = uBCM_RxBuffer[10];

    switch (BlueCom_Data_RX.Command_return)
    {
    // Application configurations
        case CMD_STATUS_SYSTEMS:
            BlueCom_Data_TX.Command_return = CMD_STATUS_SYSTEMS;
            Board_Struct.FlagTx = 1; //set to 1, because the reponse trame must be transmit
        break;
    //////////////////////////
    // input/output
        case CMD_SET_DIGITAL_OUTPUT:
//            if (BlueCom_Data_RX.Data0==1) { SET_DIGITAL_OUTPUT0 =1; RtccAlarmOutput0.Flag_manual_disable =  true; }
//            else if (BlueCom_Data_RX.Data0==0) { SET_DIGITAL_OUTPUT0 =0; RtccAlarmOutput0.Flag_manual_disable =  true; }
//                 if (uData1==1) SET_DIGITAL_OUTPUT1 =1;
//                else if (uData1==0) SET_DIGITAL_OUTPUT1 =0;
//                ...
            BlueCom_Data_TX.Command_return = CMD_SET_DIGITAL_OUTPUT;
            Board_Struct.FlagTx = 1; //set to 1, because the reponse trame must be transmit
        break;

        case CMD_SET_PWM:
//            PWM_Setvalue(BlueCom_Data_RX.Data0,0); // set PWM value for output 0
//            PWM_Setvalue(BlueCom_Data_RX.Data1,1); // set PWM value for output 1
//            PWM_Setvalue(BlueCom_Data_RX.Data2,2); // set PWM value for output 2
//            PWM_Setvalue(BlueCom_Data_RX.Data3,3); // set PWM value for output 3
//            PWM_Setvalue(BlueCom_Data_RX.Data4,4); // set PWM value for output 4
//            PWM_Setvalue(BlueCom_Data_RX.Data5,5); // set PWM value for output 5
//            PWM_Setvalue(BlueCom_Data_RX.Data6,6); // set PWM value for output 6
//            PWM_Setvalue(BlueCom_Data_RX.Data7,7); // set PWM value for output 7
        break;

        case CMD_SET_RGB_OUTPUT:

        break;

        case CMD_READ_DIGITAL_INPUT:
            BlueCom_Data_TX.Command_return = CMD_READ_DIGITAL_INPUT;
            Board_Struct.FlagTx = 1; //set to 1, because the reponse trame must be transmit
        break;

    }

    return 1;
}

//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  unsigned char BCM_TransmitUART(unsigned char uCommand, unsigned char *uDataPtr, unsigned char uNbrData )
 *  \brief This fonction put trame in uart fifo and transmit
 *
 *  \return 1 if data has been transmit
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
unsigned char BCM_TransmitUART(unsigned char uCommand, unsigned char *uDataPtr, unsigned char uNbrData )
{
    unsigned char uCpt;
    //add data in TX fifo software
    UARTIntPutChar(STX ); // STX=2
    UARTIntPutChar(uNbrData +5 );  //number of bytes int the message
    UARTIntPutChar(uCommand );  //command return for le trame

    for (uCpt=0;uCpt<uNbrData;uCpt++)
    {
        UARTIntPutChar( *uDataPtr++ );
    }

    UARTIntPutChar(0x00 );  //CKS (xor of message without cks and etx)
    UARTIntPutChar(ETX ); //ETX=3 : end of message

return(1);
}

//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  unsigned char BCM_Transmit(UART_DATA* pBC_struct)
 *  \brief This fonction read data and put trame in transmit buffer
 *
 *  \return 1 if data has been transmit
     */
//--------------------------------------------------------------------------------------------------------------------------------------------
unsigned char BCM_Transmit(UART_DATA* pBC_struct)
{
    //add data in TX fifo software
    UARTIntPutChar(STX ); // STX=2
    UARTIntPutChar(BLUECOM_TX_TRAME_LENGTH );  //number of bytes int the message
    UARTIntPutChar(pBC_struct->Command_return );  //command return for le trame
    UARTIntPutChar(pBC_struct->Data0 );  //data
    UARTIntPutChar(pBC_struct->Data1 );  //data
    UARTIntPutChar(pBC_struct->Data2 );  //data
    UARTIntPutChar(pBC_struct->Data3 );  //data
    UARTIntPutChar(pBC_struct->Data4 );  //data
    UARTIntPutChar(pBC_struct->Data5 );  //data
    UARTIntPutChar(pBC_struct->Data6 );  //data
    UARTIntPutChar(pBC_struct->Data7 );  //data

    UARTIntPutChar(0x00 );  //CKS (xor of message without cks and etx)
    UARTIntPutChar(ETX ); //ETX=3 : end of message

return(1);
}

//--------------------------------------------------------------------------------------------------------------------------------------------
/*! \fn  unsigned char BCM_Encode(void)
 *  \brief This fonction encode the futur trame with data and command from the system
 *
 *  \return 1 if a information has been decoded, 0 if the information is bad
 */
//--------------------------------------------------------------------------------------------------------------------------------------------
unsigned char BCM_Encode(void)
{

    switch (BlueCom_Data_TX.Command_return)
    {
    // Application configurations
        case CMD_STATUS_SYSTEMS:
            BlueCom_Data_TX.Data0 = BOARD_TYPE; // type of board
            BlueCom_Data_TX.Data1 = Board_Struct.Board_Status;   //board status;
            BlueCom_Data_TX.Data2 = 0xFF;   //Reserved
            BlueCom_Data_TX.Data3 = 0xFF;   //Reserved
            BlueCom_Data_TX.Data4 = 0xFF;   //Reserved
            BlueCom_Data_TX.Data5 = SOFT_REVISION_1;   //Soft_Revision_1
            BlueCom_Data_TX.Data6 = SOFT_REVISION_2;   //Soft_Revision_2
            BlueCom_Data_TX.Data7 = SOFT_REVISION_3;   //Soft_Revision_3
        break;
    // input/output
        case CMD_SET_DIGITAL_OUTPUT:
            /*
            // read output status directly on the port
            BlueCom_Data_TX.Data0 = READ_DIGITAL_OUTPUT0;
            BlueCom_Data_TX.Data1 = 0xFF;   //READ_DIGITAL_OUTPUT1;
            BlueCom_Data_TX.Data2 = 0xFF;   //READ_DIGITAL_OUTPUT2;
            BlueCom_Data_TX.Data3 = 0xFF;   //READ_DIGITAL_OUTPUT3;
            BlueCom_Data_TX.Data4 = 0xFF;   //READ_DIGITAL_OUTPUT4;
            BlueCom_Data_TX.Data5 = 0xFF;   //READ_DIGITAL_OUTPUT5;
            BlueCom_Data_TX.Data6 = 0xFF;   //READ_DIGITAL_OUTPUT6;
            BlueCom_Data_TX.Data7 = 0xFF;   //READ_DIGITAL_OUTPUT7;
             */
        break;

        case CMD_READ_DIGITAL_INPUT:
            
            // read input status directly on the port
            BlueCom_Data_TX.Data0 = READ_DIGITAL_INPUT0;
            BlueCom_Data_TX.Data1 = READ_DIGITAL_INPUT1;
            BlueCom_Data_TX.Data2 = 0xFF;   //READ_DIGITAL_INPUT2;
            BlueCom_Data_TX.Data3 = 0xFF;   //READ_DIGITAL_INPUT3;
            BlueCom_Data_TX.Data4 = 0xFF;   //READ_DIGITAL_INPUT4;
            BlueCom_Data_TX.Data5 = 0xFF;   //READ_DIGITAL_INPUT5;
            BlueCom_Data_TX.Data6 = 0xFF;   //READ_DIGITAL_INPUT6;
            BlueCom_Data_TX.Data7 = 0xFF;   //READ_DIGITAL_INPUT7;
             
        break;

        case CMD_SET_PWM:
//            BlueCom_Data_TX.Data0 = PWM_Readvalue(0); // read PWM value for output 0
//            BlueCom_Data_TX.Data1 = PWM_Readvalue(1);
//            BlueCom_Data_TX.Data2 = PWM_Readvalue(2);
//            BlueCom_Data_TX.Data3 = PWM_Readvalue(3);
//            BlueCom_Data_TX.Data4 = PWM_Readvalue(4);
//            BlueCom_Data_TX.Data5 = PWM_Readvalue(5);
//            BlueCom_Data_TX.Data6 = PWM_Readvalue(6);
//            BlueCom_Data_TX.Data7 = PWM_Readvalue(7);
        break;

        case CMD_SET_RGB_OUTPUT:
            
            BlueCom_Data_TX.Data0 = BlueCom_outputRGB.pwm_red; // read PWM value for output 0
            BlueCom_Data_TX.Data1 = BlueCom_outputRGB.pwm_green;
            BlueCom_Data_TX.Data2 = BlueCom_outputRGB.pwm_blue;
            BlueCom_Data_TX.Data3 = 0xFF;
            BlueCom_Data_TX.Data4 = 0xFF;
            BlueCom_Data_TX.Data5 = 0xFF;
            BlueCom_Data_TX.Data6 = 0xFF;
            BlueCom_Data_TX.Data7 = BlueCom_outputRGB.status;
        break;


    }
}

