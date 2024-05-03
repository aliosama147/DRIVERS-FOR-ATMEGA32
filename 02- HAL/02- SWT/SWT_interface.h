#ifndef _HAL_SWT_INTERFACE_H_
#define _HAL_SWT_INTERFACE_H_

#include "DIO_interface.h"

void SWT_vidInit(_enuGPIOx enuPortNum, _enuPINx enuPinNum);

_enuOUTPUT SWT_enuRead(_enuGPIOx enuPortNum, _enuPINx enuPinNum);

#endif