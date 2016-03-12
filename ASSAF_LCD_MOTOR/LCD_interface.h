/*
 * LCD_interface.h
 *
 *  Created on: Mar 9, 2016
 *      Author: Anwar
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

extern u8 LCD_u8WriteCommand(u8 command);
extern u8 LCD_u8WriteData(u8 data);
extern void LCD_voidInit(void);


extern void LCD_voidStartSecondLine(void);
extern void LCD_voidReturnHome(void);
extern void LCD_Clear(void);

/*Comment:!array of ,resolution with index determines address in cgram given in command*/
extern void LCD_WriteCGRAM(u8 *PtrToPattern,u8 Local_u8Resolution,u8 Local_LetterIndx);

/*Comment:!go to DDRam*/
extern void LCD_SetToDDRAM(u8 Local_DdramAddress);


#endif /* LCD_INTERFACE_H_ */




