/*
 * ADC_interface.h
 *
 *  Created on: Mar 10, 2016
 *      Author: Anwar
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
/*Comment:vref sources*/
#define ADC_u8VREFSOURCE0 0
#define ADC_u8VREFSOURCE1 1
#define ADC_u8VREFSOURCE2 2
#define ADC_u8VREFSOURCE3 3
/*Comment:result adJusment*/
#define ADC_u8ADJUSTLEFT 1
#define ADC_u8ADJUSTRIGHT 0
/*Comment:ADC channel*/
#define ADC_u8CHANNEL0 0
#define ADC_u8CHANNEL1 1
#define ADC_u8CHANNEL2 2
#define ADC_u8CHANNEL3 3
#define ADC_u8CHANNEL4 4
#define ADC_u8CHANNEL5 5
#define ADC_u8CHANNEL6 6
#define ADC_u8CHANNEL7 7
/*Comment:ADC enabled*/
#define ADC_u8ADCDISABLED 0
#define ADC_u8ADCENABLED 1
/*Comment:ADC interrupt*/
#define ADC_INTERRUPTDISABLED 0
#define ADC_INTERRUPTENABLED 1
/*Comment:ADC trigger*/
#define ADC_AUTOTRIGDISABLED 0
#define ADC_AUTOTRIGENABLED 1
/*Comment:ADC prescaler*/
#define ADC_PRESCALER0 0
#define ADC_PRESCALER1 1
#define ADC_PRESCALER2 2
#define ADC_PRESCALER3 3
#define ADC_PRESCALER4 4
#define ADC_PRESCALER5 5
#define ADC_PRESCALER6 6
#define ADC_PRESCALER7 7

/*Comment:ADC TRIG sources*/
#define ADC_TRIGSOURCE0 0
#define ADC_TRIGSOURCE1 1
#define ADC_TRIGSOURCE2 2
#define ADC_TRIGSOURCE3 3
#define ADC_TRIGSOURCE4 4
#define ADC_TRIGSOURCE5 5
#define ADC_TRIGSOURCE6 6
#define ADC_TRIGSOURCE7 7
/*Comment:!ADC GROUPS*/
#define ADC_u8GROUPA 0
#define ADC_u8GROUPB 1

extern void ADC_voidInit(void);

extern u8 ADC_u8ReadChannelOne(u8 Copy_ChannelNo, u8* Copy_ChannelCead);

extern u8 ADC_u8ReadChannelMulti(u8 Copy_ChannelNo,u8* Copy_ChannelRead);

extern u8 ADC_u8ReadGroup(u8 Copy_Group);

extern void ADC_voidADCEnable(void);

extern void ADC_voidADCDisable(void);

#endif /* ADC_INTERFACE_H_ */
