#include "TYPES.h"
#include "BIT_MATH.h"

#include "UART_Private.h"
#include "UART_Config.h"
#include "UART_Interface.h"





void UART_voidInit(void)
{
	uint16 Local_u16BuadRateCalc;
	uint8 Local_UCSRC_Var = 0b10000000;
	
	#if(UART_u8_MODE == UART_u8_NORMAL_MODE)
		Local_u16BuadRateCalc = ((FCPU/(UART_u32_BAUDRATE*16))-1);
		UART_UBRRL_REG = (uint8)Local_u16BuadRateCalc;
		UART_UBRRH_REG = ((Local_u16BuadRateCalc) >> 8);
		
		if(UART_u8_TX_STATE == UART_u8_ENABLE)
		{
			SET_BIT(UART_UCSRB_REG, UART_UCSRB_TXEN);
		}
		
		if(UART_u8_RX_STATE == UART_u8_ENABLE)
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
			case UART_u8_SIX_BITS:
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
	#if(UART_u8_MODE == UART_DBL_SPD_MODE)
		SET_BIT(UART_UCSRA_REG, UART_UCSRA_U2X);
		Local_u16BaudRateCalc = ((FCPU/(UART_u32_BAUDRATE*8))-1);
		UART_UBRRL_REG = (uint8)Local_u16BuadRateCalc;
		UART_UBRRH_REG = ((Local_u16BuadRateCalc) >> 8);
		
		if(UART_u8_TX_STATE == UART_u8_ENABLE)
		{
			SET_BIT(UART_UCSRB_REG, UART_UCSRB_TXEN);
		}
		
		if(UART_u8_RX_STATE == UART_u8_ENABLE)
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
			case UART_u8_SIX_BITS:
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

uint8 UART_RecieveChar(uint8 *u8_data);