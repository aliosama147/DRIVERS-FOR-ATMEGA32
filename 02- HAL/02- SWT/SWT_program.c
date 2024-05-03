#include "Types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SWT_interface.h"
#include "SWT_private.h"
#include "SWT_config.h"

void SWT_vidInit(_enuGPIOx enuPortNum, _enuPINx enuPinNum)
{
    DIO_vidSetPinMode(enuPortNum, enuPinNum, INPUT);
    #if ENABLE_PULLUP == 1
        DIO_vidWritePin(enuPortNum, enuPinNum, HIGH);
    #endif
}

_enuOUTPUT SWT_enuRead(_enuGPIOx enuPortNum, _enuPINx enuPinNum)
{
    _enuOUTPUT enuOUTPUT;
    enuOUTPUT = DIO_enuReadPin(enuPortNum, enuPinNum);
    return enuOUTPUT;
}