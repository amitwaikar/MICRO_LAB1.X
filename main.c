/* Microprocessor 2 and Embedded systems - Lab 1
 * File:   main.c
 * Author: Amit Waikar
 * Created on September 12, 2015, 5:38 PM
 */
#include "pic16f688.h"
#include <stdio.h>
#include <stdlib.h>
#include "initADC.h"    //User defined library
#include "ADC_read.h"   //User defined library

//-----Device congiguration
#pragma config WDTE=OFF, MCLRE=OFF

#define threshold 850
#define LED_ON PORTCbits.RC0 = 1
#define LED_OFF PORTCbits.RC0 = 0

void main(void)
{
    OSCCON = 0b01110001;    //8Mz internal clock
    int x;
    TRISCbits.TRISC0 = 0;   //RC0-->LED as output
    TRISAbits.TRISA0 = 1;   //RA0-->Analog input
    initADC();              //Initialize ADC

    while(1)
    {
        x = ADC_read();
        if(x<threshold)   //Well lighted environment
            LED_OFF;
        else              //Dark environment
            LED_ON;
    }
}

