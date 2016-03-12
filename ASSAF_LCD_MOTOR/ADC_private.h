/*
 * ADC_private.h
 *
 *  Created on: Mar 10, 2016
 *      Author: Anwar
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/*Comment:REFRENCE 6-7 ,,, adjust 5,,,,mux 0-4*/
#define ADMUX ((volatile u8*)0x27)
#define ADC_u8AREFOFFSET 6
#define ADC_u8ADJUSTOFSSET 5
#define ADC_u8MUXOFSSET 0

/*Comment:7::enable-6::startconversion-5:autotrig-4interruptflag-3interruptenable-0:2prescaler*/
#define ADCSRA ((volatile u8*)0x26) //
#define ADC_u8ADCENABLEOFFSET      7
#define ADC_u8ADCSTRTCONVOFFSET 6
#define ADC_u8ADCAUTOTRIGOFFSET 5
#define ADC_u8ADCFLAGOFFSET 4
#define ADC_u8ADCINTENABLEOFFSET 3
#define ADC_u8ADCPRESCALERFFSET 0

#define ADCH ((volatile u8*)0x25)
#define ADCL ((volatile u8*)0x24)

#define SFIOR ((volatile u8*)0x50)
#define ADC_u8ADCTRIGSOURCEOFFSET 5


#define ADC_MAXCHANNEL 8


#endif /* ADC_PRIVATE_H_ */
