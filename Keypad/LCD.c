/*
 * LCD.c
 *
 *  Author: Ahmed
 */ 


#include   "LCD.h"



void LCD_Init(void)
{	
		DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT , LCD_RS_PIN , DIO_PIN_OUTPUT);
		DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT , LCD_RW_PIN , DIO_PIN_OUTPUT);
		DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_OUTPUT);
		
		DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT , LCD_D4, DIO_PIN_OUTPUT);
		DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT , LCD_D5, DIO_PIN_OUTPUT);
		DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT , LCD_D6, DIO_PIN_OUTPUT);
		DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT , LCD_D7, DIO_PIN_OUTPUT);
	
	   _delay_ms(100);
	   
	    LCD_WriteCommand(0X33);
	    LCD_WriteCommand(0X32);
		LCD_WriteCommand(0X28);
		LCD_WriteCommand(0X0C);
		LCD_WriteCommand(0X01);
		LCD_WriteCommand(0X06);
		LCD_WriteCommand(0X02);
	
}

void LCD_WriteCommand(uint8_t cmd)
{
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_RS_PIN , DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_RW_PIN , DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	PORTA = (cmd & 0xf0) | (PORTA & 0x0f);
	
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	PORTA = (cmd << 4) | (PORTA & 0x0f);
		
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
	_delay_ms(10);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	_delay_ms(5);
}

void LCD_WriteChar(uint8_t data)
{
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_RS_PIN , DIO_PIN_HIGH);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_RW_PIN , DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	PORTA = (data & 0xf0) | (PORTA & 0x0f);
	
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	PORTA = (data << 4) | (PORTA & 0x0f);
	
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
	_delay_ms(10);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	_delay_ms(5);
}

void LCD_WriteString(uint8_t* str)
{
	uint8_t  cnt = 0;
	
	while(str[cnt] != '\0')
	{
		LCD_WriteChar(str[cnt]);
		cnt++;
	}
}

/*Your Assignment*/
void LCD_WriteInteger(sint32_t  num)
{
	
}
/****************/

void LCD_GoToLocation(uint8_t row , uint8_t col)
{
	uint8_t Loc[2] = {0x80 , 0xc0};
	
	LCD_WriteCommand(Loc[row]+col);
}

void LCD_Clear(void)
{
	LCD_WriteCommand(0X01);
}

