#ifndef SPI_PRIVATE
#define SPI_PRIVATE





#define SPI_ENABLE         	  0
#define SPI_DISABLE        	  1
	  
	  
#define SPI_LSB            	  0
#define SPI_MSB            	  1
	  
	  
#define SPI_MASTER         	  0
#define SPI_SLAVE          	  1
	  
	  
#define SPI_RISINGEDGE     	  0
#define SPI_FALLINGEDGE    	  1
	  
	  
#define SPI_SAMPLE         	  0
#define SPI_SETUP          	  1



#define SPI_OVER_4            0
#define SPI_OVER_16           1
#define SPI_OVER_64           2
#define SPI_OVER_128          3
#define SPI_OVER_2_HSPD       4
#define SPI_OVER_8_HSPD       5
#define SPI_OVER_32_HSPD      6
#define SPI_OVER_64_HSPD      7







#define SPI_SPCR_REG 			*((volatile uint8 *)0x2D) //SPI Control Register
#define SPI_SPCR_SPR0					0
#define SPI_SPCR_SPR1					1
#define SPI_SPCR_CPHA					2
#define SPI_SPCR_CPOL					3
#define SPI_SPCR_MSTR					4
#define SPI_SPCR_DORD					5
#define SPI_SPCR_SPE					6
#define SPI_SPCR_SPIE					7

#define SPI_SPSR_REG 			*((volatile uint8 *)0x2E) //SPI Status Register
#define SPI_SPSR_SPI2X					0
#define SPI_SPSR_WCOL					6
#define SPI_SPSR_SPIF					7

#define SPI_SPDR_REG			*((volatile uint8 *)0x2F)//SPI Data Register

#endif