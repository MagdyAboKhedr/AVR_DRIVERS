#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H

#define TIMERS_uint8_TIMER0_TCCR0 		*((volatile uint8*) 0x53)
#define TIMERS_uint8_TIMER0_TCNT0 		*((volatile uint8*) 0x52)
#define TIMERS_uint8_TIMER0_OCR0 		*((volatile uint8*) 0x5C)
#define TIMERS_uint8_TIMER0_TIMSK 		*((volatile uint8*) 0x59)
#define TIMERS_uint8_TIMER0_TIFR 		*((volatile uint8*) 0x58)


#define TIMER_NO_CLK                 0
#define TIMER_CLK                    1
#define TIMER_DIV8                   2
#define TIMER_DIV64                  3
#define TIMER_DIV256                 4
#define TIMER_DIV1024                5
#define TIMER_EXT_CLK_RISING         6
#define TIMER_EXT_CLK_FALLING        7

#define TIMER0_PRE_CLR 				0b11111000



#endif