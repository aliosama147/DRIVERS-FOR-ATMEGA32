#ifndef _HAL_DC_MOTOR_INTERFACE_H_
#define _HAL_DC_MOTOR_INTERFACE_H_
#include "DIO_interface.h"
void DC_vidInit(_enuGPIOX enuPIN2Port, _enuPINX enuPinNum);
void DC_vidStart(_enuGPIOX enuPIN2Port, _enuPINX enuPinNum, u8 u8dutycycle);
void DC_vidStop(void);


#endif