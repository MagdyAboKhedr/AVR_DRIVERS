
#include "BIT_MATH.h"
#include "TYPES.h"

#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"



/*Static pointer to the passed string needed to be sent using the Asynchronous transmitting function*/
static uint8 *SPI_pu8TransmittedString;

/*Static pointer to the passed array needed to be filled using the Asynchronous receiving function*/
static uint8 *SPI_pu8ReceivedString;

/*Static variable that will be equal the required length of the received msg*/
static uint8 SPI_u8NoOfBytes;

/* Incremented index using in asynchronous transmitting and receiving */
static uint8 SPI_u8Index;

/* Static Global callback function whic refers to the function needed to be called after finishing transmission the buffer*/
static void (*PtrASychCallback) (void) = NULL;



uint8 SPI_voidInit(void)
{
	#if SPI_SELECTROLE == SPI_MASTER
		SET_BIT(SPI_SPCR_REG, SPI_SPCR_MSTR);
	#endif
	
	#if SPI_DATA_ORDER == SPI_LSB
		SET_BIT(SPI_SPCR_REG, SPI_SPCR_DORD);
	#endif
	
	#if SPI_CLKPOL == SPI_FALLINGEDGE
		SET_BIT(SPI_SPCR_REG, SPI_SPCR_CPOL);
	#endif
	
	#if SPI_CLKPHASE == SPI_SETUP
		SET_BIT(SPI_SPCR_REG, SPI_SPCR_CPHA);
	#endif
	
	SPI_SPCR_REG |= SPI_SPRBITS;
	
	#if SPI_CLKRATE > 3
		SET_BIT(SPI_SPSR_REG, SPI_SPSR_SPI2X);
	#endif
	
	SET_BIT(SPI_SPCR_REG, SPI_SPCR_SPE);
}


uint8 SPI_uint8SynchSendReceieve(uint8 Local_uint8Data, uint8 *Local_uint8RecieveData)
{
	uint8 Local_Error = OK_;
	uint16 Local_u16Timeout = 0;

	if (Local_uint8RecieveData != NULL)
	{
		SPI_SPDR_REG = Local_uint8Data;
		while (GET_BIT(SPI_SPSR_REG,SPI_SPSR_SPIF) == 0 && Local_u16Timeout < SPI_FAULT_TIMEOUT)
		{
			Local_u16Timeout++;
		}
		if (Local_u16Timeout == SPI_FAULT_TIMEOUT)
		{
			Local_Error = ERROR_DIO;
		}
			
		*Local_uint8RecieveData = SPI_SPDR_REG;
	}
	else
	{
		Local_Error = ERROR_DIO;
	}
	
	return Local_Error;

}


uint8 SPI_uint8AsynchSendReceieve(uint8 *Local_uint8Data, uint8 *Local_uint8RecieveData, uint8 Local_NoBytes, void (*NotifFunc)(void))
{
	uint8 Local_Error = OK_;

	if (Local_uint8Data != NULL && Local_uint8RecieveData != NULL && NotifFunc != NULL)
	{
		SPI_pu8TransmittedString = Local_uint8Data;
		SPI_pu8ReceivedString = Local_uint8RecieveData;
		PtrASychCallback = NotifFunc;
		SPI_u8NoOfBytes = Local_NoBytes;
		SPI_SPDR_REG = SPI_pu8TransmittedString[SPI_u8Index];
		SET_BIT(SPI_SPCR_REG,SPI_SPCR_SPIE);
	}
	else
	{
		Local_Error = ERROR_DIO;
	}
	/*Function return*/
	return Local_Error;

}



void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
	
	SPI_pu8ReceivedString[SPI_u8Index] = SPI_SPDR_REG;
	if (SPI_u8Index == SPI_u8NoOfBytes)
	{
		SPI_u8Index = 0;
		SPI_u8NoOfBytes = 0;
		CLEAR_BIT(SPI_SPCR_REG,SPI_SPCR_SPIE);
		PtrASychCallback();
	}
	else
	{
		SPI_u8Index++;
		SPI_SPDR_REG = SPI_pu8TransmittedString[SPI_u8Index];
	}
	return;

}