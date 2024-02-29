#ifndef PRIVATE_
#define PRIVATE_



/*
	REGISTER FOR PORTA, DDRA, PINA
	1.SET PORT ADDRESS
	2.SET DDR ADDRESS
	3.SET PIN ADDRESS
*/

#define PORTA *((volatile uint8 *)0x3B)
#define DDRA *((volatile uint8 *)0x3A)
#define PINA *((volatile uint8 *)0x39)


/*
	REGISTER FOR PORTB, DDRB, PINB
	1.SET PORT ADDRESS
	2.SET DDR ADDRESS
	3.SET PIN ADDRESS
*/

#define PORTB *((volatile uint8 *)0x38)
#define DDRB *((volatile uint8 *)0x37)
#define PINB *((volatile uint8 *)0x36)


/*
	REGISTER FOR PORTC, DDRC, PINC
	1.SET PORT ADDRESS
	2.SET DDR ADDRESS
	3.SET PIN ADDRESS
*/

#define PORTC *((volatile uint8 *)0x35)
#define DDRC *((volatile uint8 *)0x34)
#define PINC *((volatile uint8 *)0x33)


/*
	REGISTER FOR PORTD, DDRD, PIND
	1.SET PORT ADDRESS
	2.SET DDR ADDRESS
	3.SET PIN ADDRESS
*/

#define PORTD *((volatile uint8 *)0x32)
#define DDRD *((volatile uint8 *)0x31)
#define PIND *((volatile uint8 *)0x30)





#endif
