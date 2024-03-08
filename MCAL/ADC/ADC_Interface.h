#ifndef ADC_INTERFACE_
#define ADC_INTERFACE_


#define ADC_STATE ADC_ENB


#define ADC_CH0		0
#define ADC_CH1		1
#define ADC_CH2		2
#define ADC_CH3		3
#define ADC_CH4		4
#define ADC_CH5		5
#define ADC_CH6		6
#define ADC_CH7		7

void ADC_Init(void);

uint8 ADC_ReturnDigitalVal_Synch(uint8 ADC_CH, uint16 *Returned_Val);

uint8 ADC_ReturnDigitalVal_Asynch(uint8 ADC_CH, void(* Local_pfNotif)(uint16));

uint8 ADC_GetADCRegVAL (uint16 *Local_ADCVal);

#endif