#include "TYPES.h"
#include "BIT_MATH.h"

#include "Timer_Interface.h"
#include "Timer_Config.h"
#include "Timer_Private.h"


static void (*Timer_pfcallback[1])(void)=[NULL];

void TIMER0_VoidInit(void)
{
	//Choose Timer0 Mode
	#if TIMER0_MODE == TIMER0_NORMAL_MODE
		CLR_BIT(TIMERS_uint8_TIMER0_TCCR0, 6);
		CLR_BIT(TIMERS_uint8_TIMER0_TCCR0, 3);
		
	//enable OVF Interrupt 
		SET_BIT(TIMERS_uint8_TIMER0_TIMSK, 0);
	//set preload value
		TIMERS_uint8_TIMER0_TCNT0 = TIMER_TIMER0_PRELOADVAL_NORMAL_MODE;
	//set prescaler
		TIMERS_uint8_TIMER0_TCCR0 &= TIMER0_PRE_CLR;
		TIMERS_uint8_TIMER0_TCCR0 |= TIMER0_PRESCALER;
	#elif
		CLR_BIT(TIMERS_uint8_TIMER0_TCCR0, 6);
		SET_BIT(TIMERS_uint8_TIMER0_TCCR0, 3);
	//enable compare match flag interrupt
		SET_BIT(TIMERS_uint8_TIMER0_TIMSK, 1);
	//set compare match value
		TIMERS_uint8_TIMER0_OCR0 = TIMER_TIMER0_Compare_Match_Val;
	//set prescaler
		TIMERS_uint8_TIMER0_TCCR0 &= TIMER0_PRE_CLR;
		TIMERS_uint8_TIMER0_TCCR0 |= TIMER0_PRESCALER;
	#elif
	#error "WRONG TIMER0 MODE"
	#endif
	 
}

uint8 Set_CallBack(uint8 TIMER0_INDX, void(*Copy_pf)(void))
{
	uint8 ERROR = OK_;
	if(Copy_pf != NULL)
	{
		if(TIMER0_INDX == TIMER0_NORMAL_MODE)
		{
				Timer_pfcallback[0] = Copy_pf;
		}
		else if(TIMER0_INDX == TIMER0_CTC_MODE)
		{
				Timer_pfcallback[1] = Copy_pf;
		}
		else
		{
			ERROR = ERROR_DIO;
		}
	
	}
	else
	{
		ERROR = ERROR_DIO;
	}
	
	
	return ERROR;
}


void __vector_11(void) 	__attribute__((signal));
void __vector_11(void)
{
	static uint16 Local_Timer0_Normal_Counter = 0;
	if(Timer_pfcallback[0] != NULL)
	{
		Local_Timer0_Normal_Counter++;
		if(Local_Timer0_Normal_Counter == TIMER_TIMER0_OVFVAL_NORMAL_MODE)
		{
			TIMERS_uint8_TIMER0_TCNT0 = TIMER_TIMER0_PRELOADVAL_NORMAL_MODE;
			Local_Timer0_Normal_Counter = 0;
			Timer_pfcallback[0]();
		}
	}
}

void __vector_10(void) 	__attribute__((signal));
void __vector_10(void)
{
	static uint16 Local_Timer0_Normal_Counter = 0;
	if(Timer_pfcallback[1] != NULL)
	{
		Local_Timer0_Normal_Counter++;
		if(Local_Timer0_Normal_Counter == TIMER_TIMER0_DESIRED_TIME_CTC_MODE_ISR)
		{
			Local_Timer0_Normal_Counter = 0;
			Timer_pfcallback[0]();
		}
	}
}