#ifndef _HAL_KPD_INTERFACE_H_
#define _HAL_KPD_INTERFACE_H_

#include "DIO_interface.h"
#define NOT_PRESSRD 0xFF
void KPD_vidInit();
u8 KPD_u8GetPressedKey();

#endif