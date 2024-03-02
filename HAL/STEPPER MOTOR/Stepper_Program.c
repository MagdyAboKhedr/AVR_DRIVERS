
#include "TYPES.h"
#include "MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>


#include "Stepper_Interface.h"
#include "Stepper_Private.h"
#include "Stepper_Config.h"

void Move_StpAngle(uint8 angle)
{
	uint32 steps = (angle * 2048UL) / 360;
	uint32 iter = steps / 4;
	
	for(uint32 i = 0; i<iter; i++)
	{
		DIO_SETVAL_PIN(Stepper_PORT, Stepper_BLUE_PIN,    LOW);
		DIO_SETVAL_PIN(Stepper_PORT, Stepper_PINK_PIN,   HIGH);
		DIO_SETVAL_PIN(Stepper_PORT, Stepper_YELLOW_PIN, HIGH);
		DIO_SETVAL_PIN(Stepper_PORT, Stepper_ORANGE_PIN, HIGH);
		
		_delay_ms(10);
		
		DIO_SETVAL_PIN(Stepper_PORT, Stepper_BLUE_PIN,   HIGH);
		DIO_SETVAL_PIN(Stepper_PORT, Stepper_PINK_PIN,    LOW);
		DIO_SETVAL_PIN(Stepper_PORT, Stepper_YELLOW_PIN, HIGH);
		DIO_SETVAL_PIN(Stepper_PORT, Stepper_ORANGE_PIN, HIGH);
		
		_delay_ms(10);
		
		DIO_SETVAL_PIN(Stepper_PORT, Stepper_BLUE_PIN,   HIGH);
		DIO_SETVAL_PIN(Stepper_PORT, Stepper_PINK_PIN,   HIGH);
		DIO_SETVAL_PIN(Stepper_PORT, Stepper_YELLOW_PIN,  LOW);
		DIO_SETVAL_PIN(Stepper_PORT, Stepper_ORANGE_PIN, HIGH);
		
		_delay_ms(10);
		
		DIO_SETVAL_PIN(Stepper_PORT, Stepper_BLUE_PIN,   HIGH);
		DIO_SETVAL_PIN(Stepper_PORT, Stepper_PINK_PIN,   HIGH);
		DIO_SETVAL_PIN(Stepper_PORT, Stepper_YELLOW_PIN, HIGH);
		DIO_SETVAL_PIN(Stepper_PORT, Stepper_ORANGE_PIN,  LOW);
		
		_delay_ms(10);
	}
}