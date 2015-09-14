#include "pic16f688.h"

int ADC_read(void)
 {
 unsigned int val=0;
 ADCON0bits.GO_nDONE = 1;           //Start ADC conversion
 while(ADCON0bits.GO_nDONE != 0);   //Wait till end of conversion
 val = ((ADRESH << 8) | ADRESL);    //Store 10-bit ADC value
 return val;
 }

