#include "BIT_MATH.h"
#include "TYPES.h"
#define F_CPU 8000000UL
#include <util/delay.h>


#include "Interface.h"


#include "KPD_Interface.h"
#include "KPD_Private.h"
#include "KPD_Config.h"
#include <stdlib.h>

const uint8 Local_u8KEYPAD[4][4] = KPD_KEYS;

const uint8 KPD_ROWSPINS[4] = {KPD_u8_R1_PIN, KPD_u8_R2_PIN, KPD_u8_R3_PIN, KPD_u8_R4_PIN};
const uint8 KPD_COLSPINS[4] = {KPD_u8_C1_PIN, KPD_u8_C2_PIN, KPD_u8_C3_PIN, KPD_u8_C4_PIN};


uint8 KPD_u8GetKey(uint8 *Returned_KEY)
{
		uint8 Local_ERROR = OK_;
		uint8 Local_RowsCount, Local_ColCount, Local_PinVal, Local_Flag = 0;
		if(Returned_KEY != NULL)
		{
			*Returned_KEY = KPD_u8_NOTPRESSED;
			for(Local_RowsCount=0; Local_RowsCount <= 3; Local_RowsCount++)
			{
				DIO_SETVAL_PIN(KPD_u8_PORT, KPD_ROWSPINS[Local_RowsCount], LOW);
				for(Local_ColCount=0; Local_ColCount <= 3; Local_ColCount++)
				{
					DIO_GETVAL(KPD_u8_PORT, KPD_COLSPINS[Local_ColCount], &Local_PinVal);
					if(Local_PinVal == LOW)
					{
						_delay_ms(25);
						DIO_GETVAL(KPD_u8_PORT, KPD_COLSPINS[Local_ColCount], &Local_PinVal);
						while(Local_PinVal == LOW)
						{
							DIO_GETVAL(KPD_u8_PORT, KPD_COLSPINS[Local_ColCount], &Local_PinVal);
						}
						*Returned_KEY = Local_u8KEYPAD[Local_RowsCount][Local_ColCount];
						Local_Flag = 1;
						break;
					}
				}
				DIO_SETVAL_PIN(KPD_u8_PORT, KPD_ROWSPINS[Local_RowsCount], HIGH);
				if(Local_Flag == 1)
				{
					break;
				}
			}
		}
		else
		{
			Local_ERROR = ERROR_DIO; 
		}
		return Local_ERROR;
		
}
