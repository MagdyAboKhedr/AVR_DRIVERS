#ifndef UART_INTERFACE
#define UART_INTERFACE


void UART_voidInit(void);

uint8 UART_SendChar(uint8 u8_data);

uint8 UART_SendStringAsynch(uint8 *u8_data, void(*NotifFunc)(void));

uint8 UART_SendStringSynch(uint8 *u8_data);

uint8 UART_RecieveChar(uint8 *u8_data);

uint8 UART_RecieveStringAsynch(uint8 *u8_data, uint8 Copy_MsgLength, void(*NotifFunc)(void));
		   
uint8 UART_RecieveStringSynch(uint8 *u8_data, uint8 Copy_MsgLength);



#endif