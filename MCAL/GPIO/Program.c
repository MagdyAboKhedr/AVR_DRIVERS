#include "BIT_MATH.h"
#include "TYPES.h"



#include "Interface.h"
#include "Private.h"



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
	uint8 error = OK_;
	switch(PORT)
	{
		case PORTA_:
		*VAL = GET_BIT(PORTA, PIN);
		break;
		
		case PORTB_:
		*VAL = GET_BIT(PORTB, PIN);
		break;
		
		case PORTC_:
		*VAL = GET_BIT(PORTC, PIN);
		break;
		
		case PORTD_:
		*VAL = GET_BIT(PORTD, PIN);
		break;
		
		default:
		error = ERROR_DIO;
	}
	return error;
}

