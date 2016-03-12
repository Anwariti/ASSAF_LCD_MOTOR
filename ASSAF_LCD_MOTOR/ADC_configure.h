/*
 * ADC_configure.h
 *
 *  Created on: Mar 10, 2016
 *      Author: Anwar
 */

#ifndef ADC_CONFIGURE_H_
#define ADC_CONFIGURE_H_

/*Comment!:VREF source [0:3]*/
#define ADC_u8VREFSOURCE ADC_u8VREFSOURCE1
/*Comment!:RESULT ADJUSMENT left or right*/
#define ADC_u8ADJUSTSTATE ADC_u8ADJUSTLEFT

/*Comment!:enable or disable INTERRUPT*/
#define ADC_u8ADCINITSTATE ADC_u8ADCDISABLED
/*Comment!:enable or disable INTERRUPT*/
#define ADC_u8UNTERRUPTSTATE ADC_INTERRUPTDISABLED
/*Comment!:enable or disable autotrig */
#define ADC_AUTOTRIGSTATE ADC_AUTOTRIGDISABLED
/*Comment!: ADC PRESCALERS [0:7]*/
#define ADC_PRESCALER ADC_PRESCALER0

/*Comment!:groupA channels[0:7]*/
#define ADC_GROUPA0 ADC_u8CHANNEL0
#define ADC_GROUPA1 ADC_u8CHANNEL1
#define ADC_GROUPA2 ADC_u8CHANNEL2
#define ADC_GROUPA3 ADC_u8CHANNEL3
/*Comment!:groupB channels[0:7]*/
#define ADC_GROUPB0 ADC_u8CHANNEL4
#define ADC_GROUPB1 ADC_u8CHANNEL5
#define ADC_GROUPB2 ADC_u8CHANNEL6
#define ADC_GROUPB3 ADC_u8CHANNEL7

/*Comment!:ADC trig source [0:7]*/
#if ADC_AUTOTRIGSTATE==ADC_AUTOTRIGENABLED
#define ADC_TRIGSOURCE ADC_TRIGSOURCE0
#endif

#endif /* ADC_CONFIGURE_H_ */
