#include "fbuf.h"

#include "control.h"
#include "defines.h"
#include "pins.h"
#include "decoder.h"
#include "mvgac.h"

void write(uint16_t adr, uint8_t data)
{
	SHARED_BUS_DRIVE_VALUE(LOW_BYTE(adr));
	decoder_write(DECODER_FBUF0_ADR_LOW_WRITE);

#ifdef DEBUG_SERIAL
	serial_prints("fbuf0_low_byte_written: '");
	serial_putchar(LOW_BYTE(adr));
	serial_prints("'\n");
#endif

	SHARED_BUS_DRIVE_VALUE(HIGH_BYTE(adr));
	decoder_write(DECODER_FBUF0_ADR_HIGH_WRITE);

#ifdef DEBUG_SERIAL
	serial_prints("fbuf0_high_byte_written: '");
	serial_putchar(HIGH_BYTE(adr));
	serial_prints("'\n");
#endif

	// TODO: encapsulate this
	SHARED_BUS_DRIVE_VALUE(0b0);
	decoder_write(DECODER_CONTROL_WRITE);
	CONTROL_OUTPUT_DRIVE();

	SHARED_BUS_DRIVE_VALUE(data);
	decoder_write(DECODER_FBUF0_WRITE);
	SHARED_BUS_RELEASE();
}

void read(uint16_t adr)
{
	SHARED_BUS_DRIVE_VALUE(LOW_BYTE(adr));
	decoder_write(DECODER_FBUF0_ADR_LOW_WRITE);

	SHARED_BUS_DRIVE_VALUE(HIGH_BYTE(adr));
	decoder_write(DECODER_FBUF0_ADR_HIGH_WRITE);

	// TODO: encapsulate this
	SHARED_BUS_DRIVE_VALUE(0b0);
	decoder_write(DECODER_CONTROL_WRITE);
	CONTROL_OUTPUT_DRIVE();

	SHARED_BUS_RELEASE();
	FBUF0_OUTPUT_DRIVE();
}
