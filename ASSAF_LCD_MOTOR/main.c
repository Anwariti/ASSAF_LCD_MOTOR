/*
 * main.c
 *
 *  Created on: Mar 11, 2016
 *      Author: Anwar
 */

#include"types.h"
#include"DIO_interface.h"
#include"ADC_interface.h"
#include"LCD_interface.h"
#include"TACTILE_SWITCH_interface.h"
#include"Delay.h"
/////////////////////////////////////////////
void LCD_Display(u8 Local_DIR, u8 Local_Speed);
void LCD_DisplayName(void);
void stepper_move(u8 Direction);
void stopstepper(void);
/////////////////////////////////////////////
#define MAX 50
#define MOTOR_STEPPER_PIN0 20
#define MOTOR_STEPPER_PIN1 19
#define MOTOR_STEPPER_PIN2 21
#define MOTOR_STEPPER_PIN3 22
#define LEFT_DIRECTION 0
#define WRIGHT_DIRECTION 1
///////////////////////////////////////////////
u8 arr[][8] = { { 0b00000110, 0b00000100, 0b00001110, 0b00000000, 0b00000100,
		0b00000100, 0b00000100, 0b00000100 },
		{ 0b00000000, 0b00000000, 0b00000101, 0b00000001, 0b00011111,
				0b00000000, 0b00000000, 0b00000000 }, { 0b00000000, 0b00000000,
				0b00001100, 0b00010100, 0b00011111, 0b00000100, 0b00011000,
				0b00000000 }, { 0b00000000, 0b00000000, 0b00000000, 0b00000001,
				0b00000010, 0b00000100, 0b00001000, 0b00010000 } };
u8 stepperpins[4] = { MOTOR_STEPPER_PIN0, MOTOR_STEPPER_PIN1,
MOTOR_STEPPER_PIN2, MOTOR_STEPPER_PIN3 };

u8 stepperpins1[4] = { MOTOR_STEPPER_PIN3, MOTOR_STEPPER_PIN2,
MOTOR_STEPPER_PIN1, MOTOR_STEPPER_PIN0 };
///////////////////////////////////////////////
void main() {
	u8 ADC_Reading = 0;
	u8 SWITCH_Reading = 0;
	u8 Max_Count = MAX;
	u8 Count = 0;
	u8 direction = WRIGHT_DIRECTION;
	DIO_voidInit();
	ADC_voidInit();
	ADC_voidADCEnable();
	LCD_voidInit();
	LCD_WriteCGRAM(arr[0], 8, 0);
	LCD_WriteCGRAM(arr[1], 8, 1);
	LCD_WriteCGRAM(arr[2], 8, 2);
	LCD_WriteCGRAM(arr[3], 8, 3);

	while (1) {
		TACTILE_u8GetState(TACTILE_u8SWITCH1, &SWITCH_Reading);
		if (SWITCH_Reading == TACTILE_u8SWITCHPRESSED) {
			LCD_DisplayName();
			stopstepper();
		} else {
			ADC_u8ReadChannelOne(0, &ADC_Reading);
			if (ADC_Reading <= 25) {
				LCD_Display('L', '5');
				direction = WRIGHT_DIRECTION;
				Max_Count = MAX / 5;
			} else if (ADC_Reading <= 50) {
				LCD_Display('L', '4');
				direction = WRIGHT_DIRECTION;
				Max_Count = MAX / 4;
			} else if (ADC_Reading <= 75) {
				LCD_Display('L', '3');
				direction = WRIGHT_DIRECTION;
				Max_Count = MAX / 3;
			} else if (ADC_Reading <= 100) {
				LCD_Display('L', '2');
				direction = WRIGHT_DIRECTION;
				Max_Count = MAX / 2;
			} else if (ADC_Reading <= 120) {
				LCD_Display('L', '1');
				Max_Count = MAX / 1;
				direction = WRIGHT_DIRECTION;
			} else if (ADC_Reading <= 130) {
				LCD_Display('0', '0');
				Count = 0;
				stopstepper();
			} else if (ADC_Reading <= 150) {
				LCD_Display('R', '1');
				Max_Count = MAX / 1;
				direction = LEFT_DIRECTION;
			} else if (ADC_Reading <= 175) {
				LCD_Display('R', '2');
				Max_Count = MAX / 2;
				direction = LEFT_DIRECTION;
			} else if (ADC_Reading <= 200) {
				LCD_Display('R', '3');
				Max_Count = MAX / 3;
				direction = LEFT_DIRECTION;
			} else if (ADC_Reading <= 225) {
				LCD_Display('R', '4');
				Max_Count = MAX / 4;
				direction = LEFT_DIRECTION;
			} else {
				LCD_Display('R', '5');
				Max_Count = MAX / 5;
				direction = LEFT_DIRECTION;
			}
			Count++;
			if (Count >= Max_Count) {
				stepper_move(direction);
				Count = 0;
			}
		}
	}
}
///////////////////////////////////////////////////////
void LCD_Display(u8 Local_DIR, u8 Local_Speed) {
	LCD_voidReturnHome();
	LCD_u8WriteData('D');
	LCD_u8WriteData('I');
	LCD_u8WriteData('R');
	LCD_u8WriteData(Local_DIR);
	LCD_voidStartSecondLine();
	LCD_u8WriteData(Local_Speed);
}
//////////////////////////////////////////////////////
void LCD_DisplayName(void) {
	LCD_voidReturnHome();
	LCD_SetToDDRAM(0x00);
	LCD_u8WriteData(0x03);
	LCD_u8WriteData(0x02);
	LCD_u8WriteData(0x01);
	LCD_u8WriteData(0x00);
	LCD_voidStartSecondLine();
	LCD_u8WriteData(' ');
}
///////////////////////////////////////////////////////////////////////
void stopstepper(void) {
	DIO_u8WritePinVal(stepperpins[0], 0);
	DIO_u8WritePinVal(stepperpins[1], 0);
	DIO_u8WritePinVal(stepperpins[2], 0);
	DIO_u8WritePinVal(stepperpins[3], 0);
}
//////////////////////////////////////////////////////////////////////
void stepper_move(u8 Direction) {
	static u8 i = 0;
	stopstepper();
	switch (Direction) {
	case LEFT_DIRECTION:
		DIO_u8WritePinVal(stepperpins[i], 1);
		break;
	case WRIGHT_DIRECTION:
		DIO_u8WritePinVal(stepperpins1[i], 1);
		break;
	}
	i++;
	i = i % 4;
}

