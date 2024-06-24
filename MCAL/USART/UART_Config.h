#ifndef UART_CONFIG
#define UART_CONFIG


//Frequency used in uC
#define FCPU               			8000000

//Buad Rate used
#define UART_u32_BAUDRATE   		9600
#define UBRR_Value 					(((FCPU / (UART_u32_BAUDRATE * 16UL))) - 1)

#define UART_u8_MODE				UART_NORMAL_MODE

#define UART_u8_TX_STATE         	UART_ENABLE
#define UART_u8_RX_STATE         	UART_ENABLE

#define UART_u8_PARITY				UART_NO_PARITY

#define UART_u8_NO_OF_STP_BITS  	UART_ONE_BIT

#define UART_u8_DATA_SIZE			UART_EIGHT_BITS

#define UART_u16_FAULT_TIMEOUT    	40000

#endif