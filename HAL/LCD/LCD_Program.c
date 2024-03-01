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

void LCD_u8SendCMND(u8 u8_cmnd)
{
	DIO_SETVAL_PIN(LCD_CONTROL_PORT, LCD_RS, LOW);
	
	DIO_SETVAL_PIN(LCD_CONTROL_PORT, LCD_RW, LOW);
	
	DIO_SETVAL_PORT(LCD_DATA_PORT, u8_cmnd);
	
	DIO_SETVAL_PIN(LCD_CONTROL_PORT, LCD_E, HIGH);
	
	_delay_us(1);
	
	DIO_SETVAL_PIN(LCD_CONTROL_PORT, LCD_E, LOW);

	
}

void LCD_u8SendChar(u8 u8_ch)
{
	DIO_SETVAL_PIN(LCD_CONTROL_PORT, LCD_RS, HIGH);
	
	DIO_SETVAL_PIN(LCD_CONTROL_PORT, LCD_RW, LOW);
	
	DIO_SETVAL_PORT(LCD_DATA_PORT, u8_ch);
	
	DIO_SETVAL_PIN(LCD_CONTROL_PORT, LCD_E, HIGH);
	
	_delay_us(1);
	
	DIO_SETVAL_PIN(LCD_CONTROL_PORT, LCD_E, LOW);
}