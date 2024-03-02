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


}