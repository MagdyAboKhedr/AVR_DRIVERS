#include "TYPES.h"
#include "BIT_MATH.h"

#include "UART_Private.h"
#include "UART_Config.h"
#include "UART_Interface.h"


/*Static pointer to the passed string needed to be sent using the Asynchronous transmitting function*/
static uint8 *UART_pu8TransmittedString;

/*Static pointer to the passed array needed to be filled using the Asynchronous receiving function*/
static uint8 *UART_pu8ReceivedString;

/*Static variable that will be equal the required length of the received msg*/
static uint8 UART_u8ReceivedMsgSize;

/* Incremented index using in asynchronous transmitting and receiving */
static uint8 UART_u8Index;

static void (*PtrASychCallback) (void) = NULL;

uint16 Local_u16BuadRateCalc;
uint8 Local_UCSRC_Var = 0b10000000;

void UART_voidInit(void)
{
	
	
	#if(UART_u8_MODE == UART_u8_NORMAL_MODE)
		Local_u16BuadRateCalc = ((FCPU/(UART_u32_BAUDRATE*16))-1);
		UART_UBRRL_REG = (uint8)Local_u16BuadRateCalc;
		UART_UBRRH_REG = ((Local_u16BuadRateCalc) >> 8);
		
		if(UART_u8_TX_STATE == UART_ENABLE)
		{
			SET_BIT(UART_UCSRB_REG, UART_UCSRB_TXEN);
		}
		
		if(UART_u8_RX_STATE == UART_ENABLE)
		{
			SET_BIT(UART_UCSRB_REG, UART_UCSRB_RXEN);
		}
		
		
		if(UART_u8_PARITY == UART_EVEN_PARITY)
		{
			SET_BIT(Local_UCSRC_Var, UART_UCSRC_UPM1);
		}
		if(UART_u8_PARITY == UART_ODD_PARITY)
		{
			SET_BIT(Local_UCSRC_Var, UART_UCSRC_UPM1);
			SET_BIT(Local_UCSRC_Var, UART_UCSRC_UPM0);
		}
		
		if(UART_u8_NO_OF_STP_BITS == UART_TWO_BITS)
		{
			SET_BIT(Local_UCSRC_Var, UART_UCSRC_USBS);
		}
		
		switch(UART_u8_DATA_SIZE)
		{
			case UART_SIX_BITS:
			{
				SET_BIT(Local_UCSRC_Var, UART_UCSRC_UCSZ0);
				break;
			}
			
			case UART_SEVEN_BITS:
			{
				SET_BIT(Local_UCSRC_Var, UART_UCSRC_UCSZ1);
				break;
			}
			
			case UART_EIGHT_BITS:
			{
				SET_BIT(Local_UCSRC_Var, UART_UCSRC_UCSZ0);
				SET_BIT(Local_UCSRC_Var, UART_UCSRC_UCSZ1);
				break;
			}
			case UART_NINE_BITS:
			{
				SET_BIT(Local_UCSRC_Var, UART_UCSRC_UCSZ0);
				SET_BIT(Local_UCSRC_Var, UART_UCSRC_UCSZ1);
				SET_BIT(UART_UCSRB_REG, UART_UCSRB_UCSZ2);
				break;
			}
		}
		UART_UCSRC_REG = Local_UCSRC_Var;
	#elif(UART_u8_MODE == UART_DBL_SPD_MODE)
		SET_BIT(UART_UCSRA_REG, UART_UCSRA_U2X);
		UART_u32_BAUDRATE = ((FCPU/(UART_u32_BAUDRATE*8))-1);
		UART_UBRRL_REG = (uint8)Local_u16BuadRateCalc;
		UART_UBRRH_REG = ((Local_u16BuadRateCalc) >> 8);
		
		if(UART_u8_TX_STATE == UART_ENABLE)
		{
			SET_BIT(UART_UCSRB_REG, UART_UCSRB_TXEN);
		}
		
		if(UART_u8_RX_STATE == UART_ENABLE)
		{
			SET_BIT(UART_UCSRB_REG, UART_UCSRB_RXEN);
		}
		
		if(UART_u8_PARITY == UART_EVEN_PARITY)
		{
			SET_BIT(Local_UCSRC_Var, UART_UCSRC_UPM1);
		}
		if(UART_u8_PARITY == UART_ODD_PARITY)
		{
			SET_BIT(Local_UCSRC_Var, UART_UCSRC_UPM1);
			SET_BIT(Local_UCSRC_Var, UART_UCSRC_UPM0);
		}
		
		if(UART_u8_NO_OF_STP_BITS == UART_TWO_BITS)
		{
			SET_BIT(Local_UCSRC_Var, UART_UCSRC_USBS);
		}
		
		switch(UART_u8_DATA_SIZE):
		{
			case UART_SIX_BITS:
			{
				SET_BIT(Local_UCSRC_Var, UART_UCSRC_UCSZ0);
				break;
			}
			
			case UART_SEVEN_BITS:
			{
				SET_BIT(Local_UCSRC_Var, UART_UCSRC_UCSZ1);
				break;
			}
			
			case UART_EIGHT_BITS:
			{
				SET_BIT(Local_UCSRC_Var, UART_UCSRC_UCSZ0);
				SET_BIT(Local_UCSRC_Var, UART_UCSRC_UCSZ1);
				break;
			}
			case UART_NINE_BITS:
			{
				SET_BIT(Local_UCSRC_Var, UART_UCSRC_UCSZ0);
				SET_BIT(Local_UCSRC_Var, UART_UCSRC_UCSZ1);
				SET_BIT(UART_UCSRB_REG, UART_UCSRB_UCSZ2);
				break;
			}
		}
		UART_UCSRC_REG = Local_UCSRC_Var;
		
		#endif
}

uint8 UART_SendChar(uint8 u8_data)
{
	uint8 Local_Error = OK_;
	uint16 Local_TOCounter = 0;
	
	UART_UDR_REG = u8_data;
	while(GET_BIT(UART_UCSRA_REG, UART_UCSRA_UDRE) == 0 && Local_TOCounter < UART_u16_FAULT_TIMEOUT)
	{
		Local_TOCounter++;
	}
	if(Local_TOCounter == UART_u16_FAULT_TIMEOUT)
	{
		Local_Error = ERROR_DIO;
	}
	
	return Local_Error;
}

uint8 UART_SendStringAsynch(uint8 *u8_data, void(*NotifFunc)(void))
{
	uint8 Local_Error = OK_;
	
	if(u8_data != NULL && NotifFunc != NULL)
	{
		UART_u8Index = 0;
		
		SET_BIT(UART_UCSRB_REG, UART_UCSRB_TXCIE); 
		
		UART_pu8TransmittedString = u8_data;
		
		PtrASychCallback = NotifFunc;
	}
	else
	{
		Local_Error = ERROR_DIO;
	}
	
	return Local_Error;
	
}

uint8 UART_SendStringSynch(uint8 *u8_data)
{
	
	uint8 Local_Error = OK_;
	uint16 Local_TOCounter = 0;
	
	if(u8_data != NULL)
	{
		while(*u8_data != '\0')
		{
			Local_TOCounter = 0;
			UART_UDR_REG = *u8_data;
			
			while(GET_BIT(UART_UCSRA_REG, UART_UCSRA_TXC) && Local_TOCounter < UART_u16_FAULT_TIMEOUT)
			{
				Local_TOCounter++;
			}
			
			if(Local_TOCounter != UART_u16_FAULT_TIMEOUT)
			{
				u8_data++;
			}
			else
			{
				Local_Error = ERROR_DIO;
				break;
			}
		}

	}
	else
	{
		Local_Error = ERROR_DIO;
	}
	return Local_Error;
}

uint8 UART_RecieveChar(uint8 *u8_data)
{
	uint8 Local_Error = OK_;
	uint16 Local_TOCounter = 0;
	if(u8_data != NULL)
	{
		if(GET_BIT(UART_UCSRA_REG, UART_UCSRA_RXC) == 0 && Local_TOCounter < UART_u16_FAULT_TIMEOUT)
		{
			Local_TOCounter++;
		}
		if(Local_TOCounter == UART_u16_FAULT_TIMEOUT)
		{
			Local_Error = ERROR_DIO;
		}
		else
		{
			*u8_data = UART_UDR_REG;
		}
	}
	else
	{
		Local_Error = ERROR_DIO;
	}
	
	return Local_Error;
}

uint8 UART_RecieveStringAsynch(uint8 *u8_data, uint8 Copy_MsgLength, void(*NotifFunc)(void))
{
	uint8 Local_Error = OK_;
	
	if(u8_data != NULL && NotifFunc != NULL)
	{
		UART_u8Index = 0;
		UART_pu8ReceivedString = u8_data;
		UART_u8ReceivedMsgSize = Copy_MsgLength;
		
		PtrASychCallback = NotifFunc;
		
		
		SET_BIT(UART_UCSRB_REG, UART_UCSRB_RXCIE);
	}
	else
	{
		Local_Error = ERROR_DIO;
	}
	
	return Local_Error;
}
		   
uint8 UART_RecieveStringSynch(uint8 *u8_data, uint8 Copy_MsgLength)
{
	uint8 Local_Error = OK_;
	uint8 Local_index = 0;
	uint16 Local_TOCounter = 0;
	
	if(u8_data != NULL)
	{
		for(Local_index=0; Local_index<Copy_MsgLength; Local_index++)
		{
			while(GET_BIT(UART_UCSRA_REG, UART_UCSRA_RXC) && Local_TOCounter < UART_u16_FAULT_TIMEOUT)
			{
				Local_TOCounter++;
			}
			if(Local_TOCounter != UART_u16_FAULT_TIMEOUT)
			{
				u8_data[Local_index] = UART_UDR_REG;
			}
			else
			{
				Local_Error = ERROR_DIO;
				break;
			}
		}
	}
	else
	{
		Local_Error = ERROR_DIO;
	}
	
	return Local_Error;
}







void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{
	if(UART_pu8TransmittedString[UART_u8Index] != '\0')
	{
		UART_UDR_REG = UART_pu8TransmittedString[UART_u8Index];
	}
	else
	{
		UART_u8Index = 0;
		PtrASychCallback();
		CLR_BIT(UART_UCSRB_REG, UART_UCSRB_TXCIE);
	}
	
	UART_u8Index++;
}

void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	
	UART_pu8ReceivedString[UART_u8Index] = UART_UDR_REG;
	
	UART_u8Index++;
			
	if(UART_u8Index == UART_u8ReceivedMsgSize)
	{
		UART_u8Index = 0;
		PtrASychCallback();
		CLR_BIT(UART_UCSRB_REG, UART_UCSRB_RXCIE);
	}
}