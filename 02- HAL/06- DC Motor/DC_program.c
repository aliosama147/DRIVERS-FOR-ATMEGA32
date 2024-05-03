#include "Types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "TMR0_interface.h"

#include "DC_interface.h"
#include "DC_config.h"
#include "DC_private.h"

void DC_vidInit(_enuGPIOX enuPIN2Port, _enuPINX enuPinNum)
{
    TMR0_voidInit();
    DIO_vidSetPinMode(enuPIN2Port, enuPinNum, OUTPUT);
}

void DC_vidStart(_enuGPIOX enuPIN2Port, _enuPINX enuPinNum,u8 u8dutycycle)
{
    DIO_vidWritePin(enuPIN2Port, enuPinNum, LOW);
    TMR0_GenerateFastPWM(u8dutycycle);
    TMR0_voidStart(TMR0_CLK_8);
}

void DC_vidStop(void)
{
    TMR0_voidStopTMR0();
}