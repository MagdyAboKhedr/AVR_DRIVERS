#include "TYPES.h"
#include "MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#include "Interface.h"

#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Config.h"
void LCD_voidInit(void)
{
	LCD_u8SendCMND(FUNCTION_SET_CMND);
	
	LCD_u8SendCMND(DISPLAY_ONOFF_CMND);
	
	LCD_u8SendCMND(DISPLAY_CLR_CMND);
	
	LCD_u8SendCMND(ENTRY_MODE_CMND);
	
}

void LCD_u8SendCMND(uint8 u8_cmnd)
{
	DIO_SETVAL_PIN(LCD_CONTROL_PORT, LCD_RS, LOW);
	
	DIO_SETVAL_PIN(LCD_CONTROL_PORT, LCD_RW, LOW);
	
	DIO_SETVAL_PORT(LCD_DATA_PORT, u8_cmnd);
	
	DIO_SETVAL_PIN(LCD_CONTROL_PORT, LCD_E, HIGH);
	
	_delay_us(1);
	
	DIO_SETVAL_PIN(LCD_CONTROL_PORT, LCD_E, LOW);

	
}

void LCD_u8SendChar(uint8 u8_ch)
{
	DIO_SETVAL_PIN(LCD_CONTROL_PORT, LCD_RS, HIGH);
	
	DIO_SETVAL_PIN(LCD_CONTROL_PORT, LCD_RW, LOW);
	
	DIO_SETVAL_PORT(LCD_DATA_PORT, u8_ch);
	
	DIO_SETVAL_PIN(LCD_CONTROL_PORT, LCD_E, HIGH);
	
	_delay_us(1);
	
	DIO_SETVAL_PIN(LCD_CONTROL_PORT, LCD_E, LOW);
}


void LCD_u8SendString(uint8 *u8_ch)
{
	uint8 i=0;
	
	while(u8_ch[i] != '\0')
	{
		LCD_u8SendChar(u8_ch[i]);

		i++;

		_delay_ms(2);
	}
	
}

void LCD_u8SendNUM(uint8 u8_num)
{
	uint8 count=0;
	uint8 temp, count_;
	uint8 div = 1;
	temp = u8_num;
	while(temp != 0)
	{
		temp/=10;
		count++;
	}
	count_ = count;

	while(count_ != 1)
	{
		div *= 10;
		count_--;
	}

	while(count != 0)
	{
		LCD_u8SendChar((u8_num / div) + 48);
		u8_num %= div;
		div /= 10;

		count--;

	}
}

uint8 LCD_u8GoToXY(uint8 u8_X, uint8 u8_Y)
{
	uint8 error = OK_;
	if(u8_X < 39)
	{
		switch(u8_Y)
		{
			case LCD_LINE_1:LCD_u8SendCMND(0x80 + u8_X);break;
			case LCD_LINE_2:LCD_u8SendCMND(0xC0 + u8_X);break;
			default : error = ERROR_DIO;
		}
	}
	else
	{	
		error = ERROR_DIO;
	}
	
	return error;
	
}

void LCD_CLR(void)
{
	LCD_u8SendCMND(0b00000001);
}



void LCD_SendSpecialChar(uint8 u8_numChar, uint8 *u8_SpecCh, uint8 u8_X, uint8 u8_Y)
{
	uint8 CGRAMADD = u8_numChar * 8;
	LCD_u8SendCMND(CGRAMADD + 64);
	for(uint8 i=0; i<8; i++)
	{
		LCD_u8SendChar(u8_SpecCh[i]);
	}

	LCD_u8GoToXY(u8_X, u8_Y);

	LCD_u8SendChar(u8_numChar);

}