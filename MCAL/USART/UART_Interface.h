#ifndef UART_INTERFACE
#define UART_INTERFACE


void UART_voidInit(void);

uint8 UART_SendChar(uint8 u8_data);

uint8 UART_RecieveChar(uint8 *u8_data);



#endif