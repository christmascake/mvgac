#ifndef MVGAC_INCLUDE_DECODER_H_
#define MVGAC_INCLUDE_DECODER_H_

#include "defines.h"

/* ext pulldown */
// WARNING: making these all the same port may be necessary for speed (?)
#define DECODER_PIN_OE A5
#define DECODER_PIN_S0 A0
#define DECODER_PIN_S1 B1
#define DECODER_PIN_S2 B2
#define DECODER_PIN_S3 B3

enum DECODER_FLAGS {
	DECODER_CONTROL_WRITE,
	DECODER_FBUF0_WRITE,
	DECODER_FBUF0_ADR_LOW_WRITE,
	DECODER_FBUF0_ADR_HIGH_WRITE
};

// WARNING: port reading glitch thing that i don't understand means we have to
// set tris to output first before writing to port (?)
#define DECODER_DRIVE_VALUE(val)                                \
	do {                                                    \
		PIN_SET_OUTPUT(DECODER_PIN_S0);                 \
		PIN_SET_OUTPUT(DECODER_PIN_S1);                 \
		PIN_SET_OUTPUT(DECODER_PIN_S2);                 \
		PIN_SET_OUTPUT(DECODER_PIN_S3);                 \
		PIN_PORT(DECODER_PIN_S0) = (((val) >> 0) & 1U); \
		PIN_PORT(DECODER_PIN_S1) = (((val) >> 1) & 1U); \
		PIN_PORT(DECODER_PIN_S2) = (((val) >> 2) & 1U); \
		PIN_PORT(DECODER_PIN_S3) = (((val) >> 3) & 1U); \
	} while (0)

#define DECODER_INPUT_RELEASE()                \
	do {                                   \
		PIN_SET_INPUT(DECODER_PIN_S0); \
		PIN_SET_INPUT(DECODER_PIN_S1); \
		PIN_SET_INPUT(DECODER_PIN_S2); \
		PIN_SET_INPUT(DECODER_PIN_S3); \
	} while (0)

#define DECODER_OUTPUT_DRIVE()	 PIN_DRIVE_LOW(DECODER_PIN_OE)
#define DECODER_OUTPUT_RELEASE() PIN_SET_INPUT(DECODER_PIN_OE)

void decoder_write(enum DECODER_FLAGS flag);

#endif
