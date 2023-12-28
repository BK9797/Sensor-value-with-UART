 /******************************************************************************
 *
 * Module: Sensor value with UART
 *
 * File Name: main.c
 *
 * Description: main file for the AVR Sensor value with UART
 *
 * Author: BISHOY KAMEL
 *******************************************************************************/


#include"ADC.h"
#include "std_types.h"
#include"lcd.h"
#include"uart.h"
#include"gpio.h"
#include<util/delay.h>

int main()
{

	ADC_ConfigType Z={AREF,PRESCALER_16};
	ADC_Init(&Z);
	ADC_ReadChannel(7);

	UART_ConfigType conf_UART;
	conf_UART.baud_rate=RATE_9600;
	conf_UART.bit_data=BitData_8;
	conf_UART.parity=NONE;
	conf_UART.stop_bit=BIT_1;
	UART_init(&conf_UART);

	LCD_init();
	LCD_displayString("Temperature=");

	while(1)
	{
		uint16 S7,Temp;
		uint16 Data;


		S7=ADC_ReadChannel(7);
		Temp=(S7*150*5)/(1023*1.5);

		UART_sendByte(Temp);
		Data= UART_recieveByte();

		LCD_moveCursor(1,0);
	    LCD_integerToString(Data);

		_delay_ms(100);
	}
}
