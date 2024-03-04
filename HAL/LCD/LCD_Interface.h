#ifndef LCD_INTERFACE_
#define LCD_INTERFACE_


#define LCD_LINE_1 	1
#define LCD_LINE_2	2


void LCD_voidInit(void);

void LCD_u8SendCMND(uint8 u8_cmnd);

void LCD_u8SendChar(uint8 u8_ch);

void LCD_u8SendString(uint8 *u8_ch);

void LCD_u8SendNUM(uint8 u8_num);

uint8 LCD_u8GoToXY(uint8 u8_X, uint8 u8_Y);

void LCD_SendSpecialChar(uint8 u8_numChar, uint8 *u8_SpecCh, uint8 u8_X, uint8 u8_Y);

void LCD_CLR(void);

#endif