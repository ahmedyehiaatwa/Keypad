/*
 * Keypad.c
 *
 * Created: 09/06/2021 23:38:59
 * Author : Ahmed
 */ 

#include "Keypad.h"
#include "LCD.h"

int main(void)
{
    uint8_t value = 0;
	
	LCD_Init();
	KeyPad_Init();
	
	
	
    while (1) 
    {
		value = KeyPad_GetValue();
		
		if(value)
		{
			LCD_WriteChar(value);
			value = 0;
		}
    }
}

