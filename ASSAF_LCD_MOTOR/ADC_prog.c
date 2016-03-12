/*
 * ADC_prog.c
 *
 *  Created on: Mar 10, 2016
 *      Author: Anwar
 */

#include"types.h"
#include"util.h"
#include"ADC_private.h"
#include"ADC_configure.h"
#include"ADC_interface.h"
#include"DIO_interface.h"

const u8 ADC_GroupChannel[][4] = { { ADC_GROUPA0, ADC_GROUPA1, ADC_GROUPA2,
ADC_GROUPA3 }, { ADC_GROUPB0, ADC_GROUPB1, ADC_GROUPB2, ADC_GROUPB3 } };

extern void ADC_voidInit(void) {
	/*Comment!:ADMUX register vref and adjusment configuration*/
	*ADMUX = 0x00;
	SET_REGFROM(*ADMUX, ADC_u8VREFSOURCE, ADC_u8AREFOFFSET);
	SET_REGFROM(*ADMUX, ADC_u8ADJUSTSTATE, ADC_u8ADJUSTOFSSET);
	/*ADC CONTROl and STATUS :enabled or disabled,interrupt,autotrig,prescaler*/
	*ADCSRA = 0x00;
	SET_REGFROM(*ADCSRA, ADC_u8ADCINITSTATE, ADC_u8ADCENABLEOFFSET);
	SET_REGFROM(*ADCSRA, ADC_u8UNTERRUPTSTATE, ADC_u8AREFOFFSET);
	SET_REGFROM(*ADCSRA, ADC_AUTOTRIGSTATE, ADC_u8ADCAUTOTRIGOFFSET);
	SET_REGFROM(*ADCSRA, ADC_PRESCALER, ADC_u8ADCPRESCALERFFSET);
	/*SFIOR : IF auto trig enabled */
#if ADC_AUTOTRIGSTATE==ADC_INTERRUPTENABLED
	*SFIOR=0x00;
	SET_REGFROM(*SFIOR,ADC_TRIGSOURCE,ADC_u8ADCTRIGSOURCEOFFSET );
#endif
	*ADCH = 0x00;
	*ADCL = 0x00;
}

extern u8 ADC_u8ReadChannelOne(u8 Copy_ChannelNo, u8* Copy_ChannelRead) {
	u8 local_errorstate = u8ERROR;
	if (Copy_ChannelNo < ADC_MAXCHANNEL) {
		local_errorstate = u8OK;
		/*Comment:!choose chanel from ADMUX Register*/
		SET_REGFROM(*ADMUX, Copy_ChannelNo, ADC_u8MUXOFSSET);
		/*Comment:!make channel input*/
		DIO_u8WritePinDir(Copy_ChannelNo, DIO_u8INPUT);
		/*Comment:!start conversion*/
		SET_BIT(*ADCSRA, ADC_u8ADCSTRTCONVOFFSET);
		/*Comment:!wait till complete*/
		while (GET_BIT(*ADCSRA,ADC_u8ADCFLAGOFFSET) == 0);
		/*Comment:!CLear flag*/
		CLR_BIT(*ADCSRA, ADC_u8ADCFLAGOFFSET);
		/*Comment:!retutn value*/
		*Copy_ChannelRead = *ADCH;
	}
	return local_errorstate;
}

extern u8 ADC_u8ReadChannelMulti(u8 Copy_ChannelNo, u8* Copy_ChannelRead) {
	u8 local_errorstate = u8ERROR;
	u16 local_returnval = 0;
	if (Copy_ChannelNo < ADC_MAXCHANNEL) {
		local_errorstate = u8OK;
		/*Comment:!choose chanel from ADMUX Register*/
		SET_REGFROM(*ADMUX, Copy_ChannelNo, ADC_u8MUXOFSSET);
		/*Comment:!make channel input*/
		DIO_u8WritePinDir(Copy_ChannelNo, DIO_u8INPUT);
		/*Comment:!8 readings*/
		for (u8 i = 0; i < 8; i++) {
			/*Comment:!start conversion*/
			SET_BIT(*ADCSRA, ADC_u8ADCSTRTCONVOFFSET);
			/*Comment:!wait till complete*/
			while (GET_BIT(*ADCSRA,ADC_u8ADCFLAGOFFSET) == 0)
				;
			/*Comment:!CLear flag*/
			CLR_BIT(*ADCSRA, ADC_u8ADCFLAGOFFSET);
			/*Comment:!retutn value*/
			local_returnval += *ADCH;
		}
		*Copy_ChannelRead = local_returnval / 8;
	}
	return local_errorstate;
}

extern void ADC_voidADCEnable(void) {
	SET_BIT(*ADCSRA, ADC_u8ADCENABLEOFFSET);
}

extern void ADC_voidADCDisable(void) {
	CLR_BIT(*ADCSRA, ADC_u8ADCENABLEOFFSET);
}

