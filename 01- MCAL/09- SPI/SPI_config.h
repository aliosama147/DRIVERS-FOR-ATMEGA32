#ifndef _MCAL_SPI_CONFIG_H
#define _MCAL_SPI_CONFIG_H

/* Options : MASTER or Slave */
#define SPI_MODE                 MASTER

/* Options : MSB or LSB */
#define SPI_DATAORDER            LSB

/* Options : IDEL_LOW or IDEL_HIGH */
#define SPI_OPERATINGLEVEL       IDEL_LOW

/* Options : RISING or FALLING */
#define SPI_CLOCKPHASE           RISING

/* Options : NORMAL_SPEED or DOUBLE_SPEED */
#define SPI_SPEEDMODE            NORMAL_SPEED

/* Options : FN_4, FN_16, FN_64, FN_128 for Normal Speed 
			 FD_2, FD_8 , FD_32, FD_64  for Double Speed
*/			 
#define SPI_FREQUENCY_PRESCALER  FN_4


#endif 