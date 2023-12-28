/******************************************************************************
 *
 * Module: ADC_Types
 *
 * File Name: ADC_Types.h
 *
 * Description: header file for the AVR ADC ADC_Types Module
 *
 * Author: BISHOY KAMEL
 *
 *******************************************************************************/

#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_

/*******************************************************************************
 *                           GLOBAL DATA PROTOTYPES                            *
 *******************************************************************************/

typedef enum
{
	AREF = 0,
	AVCC = 1,
	INTERNAL = 3,
}ADC_RefrenceVoltage;

typedef enum
{
	PRESCALER_2 = 0,
	PRESCALER_4 = 2,
	PRESCALER_8 = 3,
	PRESCALER_16 = 4,
	PRESCALER_32 = 5,
	PRESCALER_64 = 6,
	PRESCALER_128 = 7,

}ADC_Prescaler;

typedef struct
{
	ADC_RefrenceVoltage refrenceVoltage;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


#endif /* ADC_TYPES_H_ */
