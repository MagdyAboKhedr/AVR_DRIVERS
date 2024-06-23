#ifndef UART_PRIVATE
#define UART_PRIVATE

//UART MODES
#define UART_NORMAL_MODE              0
#define UART_DBL_SPD_MODE             1


#define UART_ENABLE                   1
#define UART_DISABLE 				  0

//UART PARIT
#define UART_NO_PARITY                0
#define UART_EVEN_PARITY              1
#define UART_ODD_PARITY               2

//UART DATA Size
#define UART_ONE_BIT                  0
#define UART_TWO_BITS                 1
#define UART_FIVE_BITS                2
#define UART_SIX_BITS                 3
#define UART_SEVEN_BITS               4
#define UART_EIGHT_BITS               5
#define UART_NINE_BITS                6



#define UART_UDR_REG 			*((volatile uint8 *)0x2C) //Data register

#define UART_UCSRA_REG 			*((volatile uint8 *)0x2B) //Control and Status register A
#define UART_UCSRA_RXC			7
#define UART_UCSRA_TXC			6
#define UART_UCSRA_UDRE			5
#define UART_UCSRA_FE			4
#define UART_UCSRA_DOR			3
#define UART_UCSRA_PE			2
#define UART_UCSRA_U2X			1
#define UART_UCSRA_MPCM			0

#define UART_UCSRB_REG			*((volatile uint8 *)0x2A) //Control and Status register B
#define UART_UCSRB_RXCIE		7
#define UART_UCSRB_TXCIE		6
#define UART_UCSRB_UDRIE		5
#define UART_UCSRB_RXEN			4
#define UART_UCSRB_TXEN			3
#define UART_UCSRB_UCSZ2		2
#define UART_UCSRB_RXB			1
#define UART_UCSRB_TXB			0

#define UART_UCSRC_REG 			*((volatile uint8 *)0x40) //Control and Status register C
#define UART_UCSRC_URSEL		7
#define UART_UCSRC_UMSEL		6
#define UART_UCSRC_UPM1			5
#define UART_UCSRC_UPM0			4
#define UART_UCSRC_USBS			3
#define UART_UCSRC_UCSZ1		2
#define UART_UCSRC_UCSZ0		1
#define UART_UCSRC_UCPOL		0




#define UART_UBRRH_REG 			*((volatile uint8 *)0x40) //Control and Status register C
#define UART_UBRRL_REG 			*((volatile uint8 *)0x29) //Control and Status register C

#endif