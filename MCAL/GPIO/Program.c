#include "BIT_MATH.h"
#include "TYPES.h"

#include <stdlib.h>


#include "Interface.h"
#include "Private.h"
#include "Config.h"


void DIO_voidInit(void)
{
	DDRA = Conc(PA7_INTIAL_DIRECTION,PA6_INTIAL_DIRECTION,PA5_INTIAL_DIRECTION,PA4_INTIAL_DIRECTION,
						   PA3_INTIAL_DIRECTION,PA2_INTIAL_DIRECTION,PA1_INTIAL_DIRECTION,PA0_INTIAL_DIRECTION);
						   
	DDRB = Conc(PB7_INTIAL_DIRECTION,PB6_INTIAL_DIRECTION,PB5_INTIAL_DIRECTION,PB4_INTIAL_DIRECTION,
						   PB3_INTIAL_DIRECTION,PB2_INTIAL_DIRECTION,PB1_INTIAL_DIRECTION,PB0_INTIAL_DIRECTION);
    
	DDRC = Conc(PC7_INTIAL_DIRECTION,PC6_INTIAL_DIRECTION,PC5_INTIAL_DIRECTION,PC4_INTIAL_DIRECTION,
						   PC3_INTIAL_DIRECTION,PC2_INTIAL_DIRECTION,PC1_INTIAL_DIRECTION,PC0_INTIAL_DIRECTION);
	
	DDRD = Conc(PD7_INTIAL_DIRECTION,PD6_INTIAL_DIRECTION,PD5_INTIAL_DIRECTION,PD4_INTIAL_DIRECTION,
						   PD3_INTIAL_DIRECTION,PD2_INTIAL_DIRECTION,PD1_INTIAL_DIRECTION,PD0_INTIAL_DIRECTION);
						   
	
	
	PORTA = Conc(PA7_INTIAL_VALUE,PA6_INTIAL_VALUE,PA5_INTIAL_VALUE,PA4_INTIAL_VALUE,
						   PA3_INTIAL_VALUE,PA2_INTIAL_VALUE,PA1_INTIAL_VALUE,PA0_INTIAL_VALUE);
						   
	PORTB = Conc(PB7_INTIAL_VALUE,PB6_INTIAL_VALUE,PB5_INTIAL_VALUE,PB4_INTIAL_VALUE,
						   PB3_INTIAL_VALUE,PB2_INTIAL_VALUE,PB1_INTIAL_VALUE,PB0_INTIAL_VALUE);
						   
	PORTC = Conc(PC7_INTIAL_VALUE,PC6_INTIAL_VALUE,PC5_INTIAL_VALUE,PC4_INTIAL_VALUE,
						   PC3_INTIAL_VALUE,PC2_INTIAL_VALUE,PC1_INTIAL_VALUE,PC0_INTIAL_VALUE);
						   
	PORTD = Conc(PD7_INTIAL_VALUE,PD6_INTIAL_VALUE,PD5_INTIAL_VALUE,PD4_INTIAL_VALUE,
						   PD3_INTIAL_VALUE,PD2_INTIAL_VALUE,PD1_INTIAL_VALUE,PD0_INTIAL_VALUE);
}

enum ERROR_CHECK DIO_SETDIR_PORT(uint8 PORT, uint8 DIR)
{
	uint8 error = OK_;
	switch(PORT)
	{
		case PORTA_:
		DDRA = DIR;
		break;
		
		case PORTB_:
		DDRB = DIR;
		break;
		
		case PORTC_:
		DDRC = DIR;
		break;
		
		case PORTD_:
		DDRD = DIR;
		break;
		
		default:
		error = ERROR_DIO;		
	}	
	return error;	
}

enum ERROR_CHECK DIO_SETVAL_PORT(uint8 PORT, uint8 VAL)
{
	uint8 error = OK_;
	switch(PORT)
	{
		case PORTA_:
		PORTA = VAL;
		break;
		
		case PORTB_:
		PORTB = VAL;
		break;
		
		case PORTC_:
		PORTC = VAL;
		break;
		
		case PORTD_:
		PORTD = VAL;
		break;
		
		default:
		error = ERROR_DIO;
	}
	return error;
}

enum ERROR_CHECK DIO_SETDIR_PIN(uint8 PORT,uint8 PIN, uint8 DIR)
{
	uint8 error = OK_;
	switch(PORT)
	{
		case PORTA_:
		if(DIR == OUTPUT)
		{
			SET_BIT(DDRA, PIN);
		}
		else if(DIR == INPUT)
		{
			CLR_BIT(DDRA, PIN);
		}
		else
		{
			error = ERROR_DIO;
		}
		break;
		
		case PORTB_:
		if(DIR == OUTPUT)
		{
			SET_BIT(DDRB, PIN);
		}
		else if(DIR == INPUT)
		{
			CLR_BIT(DDRB, PIN);
		}
		else
		{
			error = ERROR_DIO;
		}
		
		break;
		
		case PORTC_:
		if(DIR == OUTPUT)
		{
			SET_BIT(DDRC, PIN);
		}
		else if(DIR == INPUT)
		{
			CLR_BIT(DDRC, PIN);
		}
		else
		{
			error = ERROR_DIO;
		}
		break;
		
		case PORTD_:
		if(DIR == OUTPUT)
		{
			SET_BIT(DDRD, PIN);
		}
		else if(DIR == INPUT)
		{
			CLR_BIT(DDRD, PIN);
		}
		else
		{
			error = ERROR_DIO;
		}
		break;
		
		default:
		error = ERROR_DIO;
	}
	return error;
}

enum ERROR_CHECK DIO_SETVAL_PIN(uint8 PORT,uint8 PIN, uint8 VAL)
{
	uint8 error = OK_;
	switch(PORT)
	{
		case PORTA_:
		if(VAL == HIGH)
		{
			SET_BIT(PORTA, PIN);
		}
		else if(VAL == LOW)
		{
			CLR_BIT(PORTA, PIN);
		}
		else
		{
			error = ERROR_DIO;
		}
		break;
		
		case PORTB_:
		if(VAL == HIGH)
		{
			SET_BIT(PORTB, PIN);
		}
		else if(VAL == LOW)
		{
			CLR_BIT(PORTB, PIN);
		}
		else
		{
			error = ERROR_DIO;
		}
		break;
		
		case PORTC_:
		if(VAL == HIGH)
		{
			SET_BIT(PORTC, PIN);
		}
		else if(VAL == LOW)
		{
			CLR_BIT(PORTC, PIN);
		}
		else
		{
			error = ERROR_DIO;
		}		
		break;
		
		case PORTD_:
		if(VAL == HIGH)
		{
			SET_BIT(PORTD, PIN);
		}
		else if(VAL == LOW)
		{
			CLR_BIT(PORTD, PIN);
		}
		else
		{
			error = ERROR_DIO;
		}
		break;
		
		default:
		error = ERROR_DIO;
	}
	return error;
}

enum ERROR_CHECK DIO_GETVAL(uint8 PORT,uint8 PIN, uint8* VAL)
{
	uint8 Local_pinVal;
	uint8 error = OK_;
	if((PORT <= PORTD) && (PIN <= PIN7) && (VAL != NULL))
	{
	switch(PORT)
	{
		case PORTA_:
		Local_pinVal = GET_BIT(PINA, PIN);
		if(Local_pinVal == 0)
		{
			*VAL = LOW;
		}
		else
		{
			*VAL = HIGH;
		}
		break;
		
		case PORTB_:
		Local_pinVal = GET_BIT(PINB, PIN);
		if(Local_pinVal == 0)
		{
			*VAL = LOW;
		}
		else
		{
			*VAL = HIGH;
		}
		break;
		
		case PORTC_:
		Local_pinVal = GET_BIT(PINC, PIN);
		if(Local_pinVal == 0)
		{
			*VAL = LOW;
		}
		else
		{
			*VAL = HIGH;
		}
		break;
		
		case PORTD_:
		Local_pinVal = GET_BIT(PIND, PIN);
		if(Local_pinVal == 0)
		{
			*VAL = LOW;
		}
		else
		{
			*VAL = HIGH;
		}
		break;
	}
	}
	else
	{
		error = ERROR_DIO;
	}
	return error;
}

