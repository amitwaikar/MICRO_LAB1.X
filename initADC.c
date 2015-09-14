#include "pic16f688.h"

void initADC(void)
{
ADCON0 = 0b10000001;    //Right justified
ADCON1 = 0b00000000;    //Fosc/2 ADC clock conversion rate
ADCON0bits.ADON = 1;    //Enable ADC module
}
