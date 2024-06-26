#ifndef SPI_CONFIG
#define SPI_CONFIG


#define  SPI_SELECTROLE      SPI_MASTER

#define SPI_INT_STATE		 SPI_DISABLE

#define SPI_DATA_ORDER       SPI_MSB

#define SPI_CLKPOL           SPI_RISINGEDGE

#define SPI_CLKPHASE         SPI_SAMPLE

#define  SPI_CLKRATE         SPI_OVER_64

#if (SPI_CLKRATE == SPI_OVER_4)
#define SPI_SPRBITS            0
#elif (SPI_CLKRATE == SPI_OVER_16)
#define SPI_SPRBITS            1
#elif (SPI_CLKRATE == SPI_OVER_64)
#define SPI_SPRBITS            2
#elif (SPI_CLKRATE == SPI_OVER_128)
#define SPI_SPRBITS            3
#elif (SPI_CLKRATE == SPI_OVER_2_HSPD)
#define SPI_SPRBITS            0
#elif (SPI_CLKRATE == SPI_OVER_8_HSPD)
#define SPI_SPRBITS            1
#elif (SPI_CLKRATE == SPI_OVER_32_HSPD)
#define SPI_SPRBITS            2
#elif (SPI_CLKRATE == SPI_OVER_64_HSPD)
#define SPI_SPRBITS            3
#endif



#define SPI_FAULT_TIMEOUT      50000



#endif