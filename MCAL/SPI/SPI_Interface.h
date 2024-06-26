#ifndef SPI_INTERFACE
#define SPI_INTERFACE


uint8 SPI_voidInit(void);


uint8 SPI_uint8SynchSendReceieve(uint8 Local_uint8Data, uint8 *Local_uint8RecieveData);


uint8 SPI_uint8AsynchSendReceieve(uint8 *Local_uint8Data, uint8 *Local_uint8RecieveData, uint8 Local_NoBytes, void (*NotifFunc)(void));

#endif