#include <xc.h>

#include "defines.h"
#include "pins.h"

#pragma config FOSC  = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE  = OFF // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF // Low-Voltage In-Circuit Serial Programming Enable bit
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM
// code protection off)
#pragma config WRT = \
	OFF // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CP = \
	OFF // Flash Program Memory Code Protection bit (Code protection off)

// Define your clock frequency for the built-in delay functions
#define _XTAL_FREQ 20000000 // 20 MHz

void init(void);

void main(void)
{
	init();
	SHARED_BUS_READ_VALUE();
	DECODER_DRIVE_VALUE(0b1010);
	while (1);
}

void init(void)
{
	ADCON1 = ADCON1_ALL_DIGITAL;

	FBUF0_OUTPUT_RELEASE();
	CONTROL_OUTPUT_RELEASE();
	SHARED_BUS_RELEASE();
	DECODER_INPUT_RELEASE();
	DECODER_OUTPUT_RELEASE();
}
