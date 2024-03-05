#include "BIT_MATH.h"
#include "TYPES.h"

#include "EXTI_Interface.h"
#include "EXTI_Config.h"
#include "EXTI_Private.h"



static void (*Local_EXTI_u8ARRPF[3])(void)={NULL, NULL, NULL};

void GINT_ENB(void)
{
	SET_BIT(SREG_REG, 7);
}

uint8 EXTI_ENB(uint8 EXTI_INDX, uint8 EXTI_MODE)
{
	uint8 ERROR = OK_;
	switch(EXTI_INDX)
	{
		case EXTI_0: 
			switch(EXTI_MODE)
			{
				case EXTI_LOW_LEVEL:
					CLR_BIT(MCUCR_REG, 0);
					CLR_BIT(MCUCR_REG, 1);
					
					SET_BIT(GICR_REG, 6);
					break;
				case EXTI_ANY_CHANGE:
					CLR_BIT(MCUCR_REG, 1);
					SET_BIT(MCUCR_REG, 0);
					
					SET_BIT(GICR_REG, 6);
					break;
				case EXTI_FALLING_EDGE:
					SET_BIT(MCUCR_REG, 1);
					CLR_BIT(MCUCR_REG, 0);
					
					SET_BIT(GICR_REG, 6);
					break;
				case EXTI_RISING_EDGE:
					SET_BIT(MCUCR_REG, 0);
					SET_BIT(MCUCR_REG, 1);
					
					SET_BIT(GICR_REG, 6);
					break;
				default: ERROR = ERROR_DIO;
			}
		break;
		case EXTI_1: 
			switch(EXTI_MODE)
			{
				case EXTI_LOW_LEVEL:
					CLR_BIT(MCUCR_REG, 3);
					CLR_BIT(MCUCR_REG, 2);
					
					SET_BIT(GICR_REG, 7);
					break;
				case EXTI_ANY_CHANGE:
					CLR_BIT(MCUCR_REG, 3);
					SET_BIT(MCUCR_REG, 2);
					
					SET_BIT(GICR_REG, 7);
					break;
				case EXTI_FALLING_EDGE:
					SET_BIT(MCUCR_REG, 3);
					CLR_BIT(MCUCR_REG, 2);
					
					SET_BIT(GICR_REG, 7);
					break;
				case EXTI_RISING_EDGE:
					SET_BIT(MCUCR_REG, 3);
					SET_BIT(MCUCR_REG, 2);
					
					SET_BIT(GICR_REG, 7);
					break;
				default: ERROR = ERROR_DIO;
			}
		break;
		case EXTI_2: 
			switch(EXTI_MODE)
			{
				case EXTI_FALLING_EDGE:
					CLR_BIT(MCUCSR_REG, 6);
					
					SET_BIT(GICR_REG, 5);
					break;
				case EXTI_RISING_EDGE:
					SET_BIT(MCUCSR_REG, 6);
					
					SET_BIT(GICR_REG, 5);
					break;
				default: ERROR = ERROR_DIO;
			}
		break;
		default: ERROR = ERROR_DIO;
		
	}
	return ERROR;
}

uint8 EXTI_DIS(uint8 EXTI_INDX)
{
	uint8 ERROR = OK_;
	switch (EXTI_INDX)
	{
		case EXTI_0: 
			CLR_BIT(GICR_REG, 6);
			break;
		case EXTI_1:
			CLR_BIT(GICR_REG, 7);
			break;
		case EXTI_2:
			CLR_BIT(GICR_REG, 5);
			break;
		default: ERROR = ERROR_DIO;
	}
	
	return ERROR;
}

uint8 EXTI_SETCALLBCK(uint8 EXTI_INDX, void (*PtrF)(void))
{
	uint8 ERROR = OK_;
	if((EXTI_INDX <= EXTI_2) && (PtrF != NULL))
	{
		Local_EXTI_u8ARRPF[EXTI_INDX] = PtrF;
	}
	else
	{
		ERROR = ERROR_DIO;
	}
	
	return ERROR;
	
}


void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(Local_EXTI_u8ARRPF[0] != NULL)
	{
		Local_EXTI_u8ARRPF[0]();
	}
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(Local_EXTI_u8ARRPF[1] != NULL)
	{
		Local_EXTI_u8ARRPF[1]();
	}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(Local_EXTI_u8ARRPF[2] != NULL)
	{
		Local_EXTI_u8ARRPF[2]();
	}
}
