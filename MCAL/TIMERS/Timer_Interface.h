#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H


#define TIMER0_NORMAL_MODE 		0
#define TIMER0_CTC_MODE 		1
#define TIMER0_PWM_MODE 		2
#define TIMER0_FAST_PWM_MODE 	3


void TIMER0_VoidInit(void);

uint8 Set_CallBack(uint8 TIMER0_INDX, void(*Copy_pf)(void));

#endif