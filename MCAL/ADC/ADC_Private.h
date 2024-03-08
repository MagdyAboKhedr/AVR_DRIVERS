#ifndef ADC_PRIVATE_
#define ADC_PRIVATE_

#define ADC_ADMUX		*((volatile uint8 *)0x27)
#define ADC_ADCSRA  	*((volatile uint8 *)0x26)
#define ADC_ADCH 	 	*((volatile uint8 *)0x25)
#define ADC_ADCL 	 	*((volatile uint8 *)0x24)
#define ADC_SFIOR		*((volatile uint8 *)0x50)

#define ADC_u16ADC_REG  *((volatile uint16 *)0x24)

#define ADC_REF_AREF 	0
#define ADC_REF_AVCC	1
#define ADC_REF_DEFAULT	2

#define ADC_STORE8BIT	0
#define ADC_STORE10BIT	1

#define ADC_PRESCALER_2	  0
#define ADC_PRESCALER_4	  2
#define ADC_PRESCALER_8	  3
#define ADC_PRESCALER_16  4
#define ADC_PRESCALER_32  5
#define ADC_PRESCALER_64  6
#define ADC_PRESCALER_128 7

#define ADC_ENB	0
#define ADC_DIS	1

#endif