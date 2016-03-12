/*
 * LCD_prog.c
 *
 *  Created on: Mar 9, 2016
 *      Author: Anwar
 */

#include"types.h"
#include"LCD_config.h"
#include"DIO_interface.h"
#include"LCD_interface.h"
#include"LCD_private.h"
#include"Delay.h"
#include"util.h"



extern void LCD_voidInit(void) {
	//Delay(20);
	LCD_u8WriteCommand(LCD_u8INTISEQ);
	Delay(5);
	LCD_u8WriteCommand(LCD_u8INTISEQ);
	Delay(1);
	LCD_u8WriteCommand(LCD_u8INTISEQ);

	//////////////
	LCD_u8WriteCommand(LCD_u8FNSET);
	LCD_u8WriteCommand(LCD_ENTRYMODE);
	LCD_u8WriteCommand(LCD_ONOFF);
}

extern u8 LCD_u8WriteCommand(u8 command) {
	DIO_u8WritePinVal(LCD_u8D0, GET_BIT(command, 0));
	DIO_u8WritePinVal(LCD_u8D1, GET_BIT(command, 1));
	DIO_u8WritePinVal(LCD_u8D2, GET_BIT(command, 2));
	DIO_u8WritePinVal(LCD_u8D3, GET_BIT(command, 3));

	DIO_u8WritePinVal(LCD_u8D4, GET_BIT(command, 4));
	DIO_u8WritePinVal(LCD_u8D5, GET_BIT(command, 5));
	DIO_u8WritePinVal(LCD_u8D6, GET_BIT(command, 6));
	DIO_u8WritePinVal(LCD_u8D7, GET_BIT(command, 7));

	DIO_u8WritePinVal(LCD_u8RS, 0);
	DIO_u8WritePinVal(LCD_u8Readwrite, 0);
	DIO_u8WritePinVal(LCD_u8ENABLE, 1);
	//Delay(10);
	DIO_u8WritePinVal(LCD_u8ENABLE, 0);
	return 0;
}
//////////////////////////////////////////////////////////
extern u8 LCD_u8WriteData(u8 data) {
	DIO_u8WritePinVal(LCD_u8D0, GET_BIT(data, 0));
	DIO_u8WritePinVal(LCD_u8D1, GET_BIT(data, 1));
	DIO_u8WritePinVal(LCD_u8D2, GET_BIT(data, 2));
	DIO_u8WritePinVal(LCD_u8D3, GET_BIT(data, 3));

	DIO_u8WritePinVal(LCD_u8D4, GET_BIT(data, 4));
	DIO_u8WritePinVal(LCD_u8D5, GET_BIT(data, 5));
	DIO_u8WritePinVal(LCD_u8D6, GET_BIT(data, 6));
	DIO_u8WritePinVal(LCD_u8D7, GET_BIT(data, 7));

	DIO_u8WritePinVal(LCD_u8RS, 1);
	DIO_u8WritePinVal(LCD_u8Readwrite, 0);

	DIO_u8WritePinVal(LCD_u8ENABLE, 1);
	//Delay(10);
	DIO_u8WritePinVal(LCD_u8ENABLE, 0);
	return 0;
}

extern void LCD_Clear(void) {
	LCD_u8WriteCommand(LCD_u8LCDCLEAR);
}
////////////////////////////////////////////
extern void LCD_voidReturnHome(void) {
	LCD_u8WriteCommand(LCD_u8GOHOME);
}
/////////////////////////////////////////////
extern void LCD_voidStartSecondLine(void) {
	LCD_u8WriteCommand(LCD_u8NEWLINE);
}
//////////////////////////////////////////////////////////////////////
extern void LCD_WriteCGRAM(u8 *PtrToPattern, u8 Local_u8Resolution,
		u8 Local_LetterIndx) {
	u8 local_Address = LCD_u8CGRAMMSK & (Local_LetterIndx * Local_u8Resolution);
	LCD_u8WriteCommand(LCD_u8SETCGRAM | local_Address);
	for (u8 i = 0; i < Local_u8Resolution; i++) {
		LCD_u8WriteData(PtrToPattern[i]);
	}
}
///////////////////////////////////////////////////////////////////////////////////
extern void LCD_SetToDDRAM(u8 Local_DdramAddress)
{
u8 local_Address = LCD_u8DDRAMMask & Local_DdramAddress;
LCD_u8WriteCommand(LCD_u8SETDDRAM | local_Address);
}



