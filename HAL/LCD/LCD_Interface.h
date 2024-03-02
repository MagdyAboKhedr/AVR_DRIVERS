#ifndef LCD_INTERFACE_
#define LCD_INTERFACE_



void LCD_voidInit(void);

void LCD_u8SendCMND(uint8 u8_cmnd);

void LCD_u8SendChar(uint8 u8_ch);

void LCD_u8SendString(uint8 *u8_ch);

void LCD_u8SendNUM(uint8 u8_num);


#endif