#ifndef EXTI_INTERFACE_
#define EXTI_INTERFACE_


#define EXTI_0	0
#define EXTI_1	1
#define EXTI_2	2

#define EXTI_LOW_LEVEL	  0
#define EXTI_ANY_CHANGE	  1
#define EXTI_FALLING_EDGE 2
#define EXTI_RISING_EDGE  3

void GINT_ENB(void);

uint8 EXTI_ENB(uint8 EXTI_INDX, uint8 EXTI_MODE);

uint8 EXTI_DIS(uint8 EXTI_INDX);

uint8 EXTI_SETCALLBCK(uint8 EXTI_INDX, void (*PtrF)(void));

#endif
