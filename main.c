#include <xc.h>

#include "mvgac.h"
#include "pins.h"
#include "fbuf.h"
#include "decoder.h"
#include "control.h"

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

void init(void);

void main(void)
{
	init();
	write(0b1100110010101010, '$');
	read(0b1100110010101010);
	SHARED_BUS_RELEASE();

	serial_putchar(SHARED_BUS_READ_VALUE());

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

	//serial
	TRISC6 = 0;
	TRISC7 = 1;

	BRGH  = 1;
	SPBRG = 129;

	SYNC = 0;
	SPEN = 1;
	TXEN = 1;
}
