#ifndef MVGAC_INCLUDE_FBUF_H_
#define MVGAC_INCLUDE_FBUF_H_

#include <xc.h>

/* ext pullup */
#define FBUF0_PIN_OE	       E0
#define FBUF0_OUTPUT_DRIVE()   PIN_DRIVE_LOW(FBUF0_PIN_OE)
#define FBUF0_OUTPUT_RELEASE() PIN_SET_INPUT(FBUF0_PIN_OE)

void write(uint16_t adr, uint8_t data);
void read(uint16_t adr);

#endif
