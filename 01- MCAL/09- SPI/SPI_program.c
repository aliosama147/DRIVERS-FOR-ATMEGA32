#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_vidInit(void)
{
	/* Adjust Mode */
	#if SPI_MODE == MASTER
		SET_BIT(SPCR, MSTR);
		DIO_vidSetPinMode(GPIOB, PIN4, OUTPUT);
		DIO_vidSetPinMode(GPIOB, PIN5, OUTPUT);
		DIO_vidSetPinMode(GPIOB, PIN7, OUTPUT);
		DIO_vidWritePin(GPIOB, PIN4, HIGH);
	#else 
		CLR_BIT(SPCR, MSTR);
		DIO_vidSetPinMode(GPIOB, PIN6, OUTPUT);
	#endif
	/* Adjust Data Order */
	#if SPI_DATAORDER == LSB 
		SET_BIT(SPCR, DORD);
	#else 
		CLR_BIT(SPCR, DORD);
	#endif
	/* Adjust Operating Level */
	#if SPI_OPERATINGLEVEL == IDEL_LOW
		CLR_BIT(SPCR, CPOL);
	#else 
		SET_BIT(SPCR, CPOL);
	#endif
	/* Adjust Clock Phase */
	#if SPI_CLOCKPHASE == RISING
		CLR_BIT(SPCR, CPHA);
	#else 
		SET_BIT(SPCR, CPHA);
	#endif
	/* Adjust Speed */
	#if SPI_SPEEDMODE == NORMAL_SPEED
		CLR_BIT(SPSR, SPI2X);
		/*Adjust Prescaler */
		#if   SPI_FREQUENCY_PRESCALER == FN_4
			CLR_BIT(SPCR, SPR0);
			CLR_BIT(SPCR, SPR1);
		#elif SPI_FREQUENCY_PRESCALER == FN_16
			SET_BIT(SPCR, SPR0);
			CLR_BIT(SPCR, SPR1);
		#elif SPI_FREQUENCY_PRESCALER == FN_64
			CLR_BIT(SPCR, SPR0);
			SET_BIT(SPCR, SPR1);
		#elif SPI_FREQUENCY_PRESCALER == FN_128
			SET_BIT(SPCR, SPR0);
			SET_BIT(SPCR, SPR1);
		#endif
	#else 
		SET_BIT(SPSR, SPI2X);
		/*Adjust Prescaler */
		#if   SPI_FREQUENCY_PRESCALER == FD_2
			CLR_BIT(SPCR, SPR0);
			CLR_BIT(SPCR, SPR1);
		#elif SPI_FREQUENCY_PRESCALER == FD_8
			SET_BIT(SPCR, SPR0);
			CLR_BIT(SPCR, SPR1);
		#elif SPI_FREQUENCY_PRESCALER == FD_32
			CLR_BIT(SPCR, SPR0);
			SET_BIT(SPCR, SPR1);
		#elif SPI_FREQUENCY_PRESCALER == FD_64
			SET_BIT(SPCR, SPR0);
			SET_BIT(SPCR, SPR1);
		#endif
	#endif
		
}

u8 SPI_u8SendReceive(u8 copy_Data)
{
	/* Enable  */
	SET_BIT(SPCR, SPE);
	DIO_vidWritePin(GPIOB, PIN4, LOW);
	SPDR = copy_Data;
	while(GET_BIT(SPSR,SPIF)==0);
	DIO_vidWritePin(GPIOB, PIN4, HIGH);
	return SPDR;
}

void SPI_vidSendString(u8 *copy_ptr)
{
	u8 temp;
	while((*copy_ptr) != '\0')
	{
		temp = SPI_u8SendReceive(*copy_ptr);
		copy_ptr++;
	}
}