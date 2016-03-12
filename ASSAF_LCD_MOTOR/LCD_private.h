/*
 * LCD_private.h
 *
 *  Created on: Mar 9, 2016
 *      Author: Anwar
 */

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#define LCD_u8INTISEQ 0b00110000


#define LCD_u8LCDCLEAR 0b00000001
#define LCD_u8GOHOME   0b00000010
#define LCD_u8NEWLINE  0b11000000

#define LCD_u8SETCGRAM 0b01000000
#define LCD_u8CGRAMMSK 0b0011111

#define LCD_u8SETDDRAM  0b10000000
#define LCD_u8DDRAMMask 0b01111111


//////////////////////////////////
//more to be done
#define LCD_u8FNSET   0b00111000
#define LCD_ENTRYMODE 0b00000110
#define LCD_ONOFF	  0b00001100
///////////////////////////////////

#endif /* LCD_PRIVATE_H_ */
