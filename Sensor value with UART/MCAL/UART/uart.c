 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.c
 *
 * Description: Source file for the UART AVR driver CONFIGURABLE
 *
 * Author: BISHOY KAMEL
 *
 *******************************************************************************/

#include "uart.h"
#include "avr/io.h" /* To use the UART Registers */
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * A function to setup the UART with the given baud rate and number of send bits and parity
 * checker and number of stop bits .
 */
void UART_init(const UART_ConfigType* config)
{
	/*double speed mode*/
	UCSRA = ( 1 << U2X );

	/*Enable Transmitter and Receiver*/
	UCSRB = ( 1 << RXEN ) | ( 1 << TXEN );

	/*Select register UCSRC*/
	UCSRC = ( 1 << URSEL );

	/*Parity checker*/
	UCSRC |= ( ( config -> parity & 1 ) << UPM0 ) | ( ( config -> parity & 2 )<< UPM1 );

	/*Number of stop bits*/
	UCSRC |= ( config->stop_bit) << USBS ;

	/*Character size*/
	UCSRC |= ( ( config -> bit_data & 1 ) << UCSZ0 ) | ( ( config -> bit_data & 2 ) << UCSZ1);

	/* Setup the baud rate value
	 * UBRRL = 1st 8 bits of rate
	 * UBRRh = The other bits
	 */
	UBRRL = (uint8) config -> baud_rate ;
	UBRRH = (config -> baud_rate) >> 8;
}

/*
 * Description :
 * A function to send a given byte using UART
 */
void UART_sendByte(const uint8 data)
{
	/*Polling till the UDR register is empty*/
	while(BIT_IS_CLEAR(UCSRA,UDRE));

	/*send the data*/
	UDR=data;

}

/*
 * Description :
 * A function to return the received byte
 */
uint8 UART_recieveByte(void)
{
	/*Polling till the receive is completed*/
	while(BIT_IS_CLEAR(UCSRA,RXC));

	/*get the data from UDR register and return it*/
	return UDR;

}

/*
 * Description :
 * A function to send a given string , u don't need to add anything after the end of string
 * but don't send a string that contain #
 */
void UART_sendString(const uint8 *str)
{
	int counter;

	/*Sending our string*/
	for(counter=0;str[counter]!='\0';counter++)
		UART_sendByte(str[counter]);

	/*Sending # as an indication for the end of string*/
	UART_sendByte('#');

}

/*
 * Description :
 * A function that receive a string ended by #
 */
void UART_receiveString(uint8 *str)
{
	int counter;

	/*Receive the first byte*/
	str[0]=UART_recieveByte();

	/*Receive the remaining bytes till #*/
	while(str[counter]!='#')
	{
		counter++;
		str[counter]=UART_recieveByte();
	}

	/*replace # with NULL*/
	str[counter]='\0';
}
