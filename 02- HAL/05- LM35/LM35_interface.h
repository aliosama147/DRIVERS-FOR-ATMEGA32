

#ifndef _HAL_LM35_INTERFACE_H
#define _HAL_LM35_INTERFACE_H

#include "ADC_interface.h"

void LM35_vidInit(_enuADCChannels enuADCChannel);

u8 LM35_u8Read(void);

#endif