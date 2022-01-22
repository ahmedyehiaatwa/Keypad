/*
 * Keypad.c
 *
 *  Author: Ahmed
 */ 

#include "Keypad.h"
#define F_CPU 16000000
#include <util/delay.h>

uint8_t KEYPAD_VALUES[4][4] = {{'7' , '8', '9' , '/'} ,  
							 {'4' , '5' , '6' , '*'},  
							 {'1' , '2' , '3' , '-'},
						     {'c' , '0' , '=' , '+'}};
								 

void KeyPad_Init(void)
{
	DIO_SetPinDir(KEYPAD_COL_PORT, KEYPAD_COL0,DIO_PIN_OUTPUT);
	DIO_SetPinDir(KEYPAD_COL_PORT, KEYPAD_COL1,DIO_PIN_OUTPUT);
	DIO_SetPinDir(KEYPAD_COL_PORT, KEYPAD_COL2,DIO_PIN_OUTPUT);
	
	DIO_SetPinDir(KEYPAD_ROW_PORT, KEYPAD_ROW0,DIO_PIN_OUTPUT);
	DIO_SetPinDir(KEYPAD_ROW_PORT, KEYPAD_ROW1,DIO_PIN_OUTPUT);
	DIO_SetPinDir(KEYPAD_ROW_PORT, KEYPAD_ROW2,DIO_PIN_OUTPUT);
	
	DIO_SetPinValue(KEYPAD_COL_PORT, KEYPAD_COL0, DIO_PIN_HIGH);
	DIO_SetPinValue(KEYPAD_COL_PORT, KEYPAD_COL1, DIO_PIN_HIGH);
	DIO_SetPinValue(KEYPAD_COL_PORT, KEYPAD_COL2, DIO_PIN_HIGH);
	
	DIO_SetPullUp(KEYPAD_ROW_PORT, KEYPAD_ROW0);
	DIO_SetPullUp(KEYPAD_ROW_PORT, KEYPAD_ROW1);
	DIO_SetPullUp(KEYPAD_ROW_PORT, KEYPAD_ROW2);
}

uint8_t KeyPad_GetValue(void)
{
	uint8_t Col_Loc=0;
	uint8_t Row_Loc=0;
	
	uint8_t Button_Value=0;
	uint8_t Temp = 1;
	
	for(Col_Loc = COL_INIT; Col_Loc <= COL_FINAL;Col_Loc++)
	{
		DIO_SetPinValue(KEYPAD_ROW_PORT, Col_Loc, DIO_PIN_LOW);
		
		for(Row_Loc = ROW_INIT; Row_Loc <= ROW_FINAL ; Row_Loc++)
		{
			DIO_ReadPinValue(KEYPAD_ROW_PORT, Row_Loc , &Temp);
			if(Temp == 0)
			{
				Button_Value = KEYPAD_VALUES[Row_Loc-ROW_INIT][Col_Loc-COL_INIT];
				
				while(Temp == 0)
				{
					DIO_ReadPinValue(KEYPAD_ROW_PORT,Row_Loc, &Temp);
				}
				_delay_ms(10);
			}
		}
		
		DIO_SetPinValue(KEYPAD_ROW_PORT, Col_Loc, DIO_PIN_HIGH);
	}
	return Button_Value;
}