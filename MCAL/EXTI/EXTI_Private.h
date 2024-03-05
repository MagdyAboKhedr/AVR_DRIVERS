#ifndef EXTI_PRIVATE_
#define EXTI_PRIVATE_

#define SREG_REG 	*((volatile uint8 *)0x5F)

#define MCUCR_REG 	*((volatile uint8 *)0x55)
#define MCUCSR_REG 	*((volatile uint8 *)0x54)
#define GICR_REG 	*((volatile uint8 *)0x5B)


#endif
