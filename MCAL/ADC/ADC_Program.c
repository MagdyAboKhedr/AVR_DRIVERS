#include "BIT_MATH.h"
#include "TYPES.h"

#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Config.h"



void ADC_Init(void)
{
	
	#if ADC_REF==ADC_REF_AREF
		CLR_BIT(ADC_ADMUX, 6);
		CLR_BIT(ADC_ADMUX, 7);
	#elif ADC_REF==ADC_REF_AVCC
		SET_BIT(ADC_ADMUX, 6);
		CLR_BIT(ADC_ADMUX, 7);
	#elif ADC_REF==ADC_REF_DEFAULT
		SET_BIT(ADC_ADMUX, 6);
		SET_BIT(ADC_ADMUX, 7);
	#else
	#error "WRONG REF"
	#endif
	
	#if ADC_VAL_REF==ADC_STORE8BIT
		SET_BIT(ADC_ADMUX, 5);
	#elif ADC_VAL_REF==ADC_STORE10BIT 
		CLR_BIT(ADC_ADMUX, 5);
	#else
	#error "WRONG VAL CONFIG"
	#endif
	
	ADC_ADCSRA &= 0b11111000;
	ADC_ADCSRA |= ADC_PRESCALER;
	
	#if ADC_STATE==ADC_ENB
		SET_BIT(ADC_ADCSRA, 7);
	#elif ADC_STATE==ADC_DIS 
		CLR_BIT(ADC_ADCSRA, 7);
	#endif
}

uint8 ADC_ReturnDigitalVal_Synch(uint8 ADC_CH, uint16 *Returned_Val)
{
	uint8 ERROR = OK_;
	uint8 Local_CounterTO = 0;
	if((ADC_CH < 32) && (Returned_Val != NULL))
	{
		ADC_ADMUX &= 0b11100000;
		
		ADC_ADMUX |= ADC_CH;
		
		SET_BIT(ADC_ADCSRA, 6);
		
		while((GET_BIT(ADC_ADCSRA, 4)==0) && (Local_CounterTO< 50000))
		{
			Local_CounterTO++;
		}
		
		if(GET_BIT(ADC_ADCSRA, 4)!=0)
		{
			SET_BIT(ADC_ADCSRA, 4);
			
			*Returned_Val = ADC_u16ADC_REG;
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