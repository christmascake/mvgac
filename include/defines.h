#ifndef MVGAC_INCLUDE_DEFINES_H_
#define MVGAC_INCLUDE_DEFINES_H_

#include <xc.h>

#define _XTAL_FREQ 20000000 // 20 MHz

#define HIGH_BYTE(n) ((uint8_t)(((uint16_t)(n) >> 8) & 0xFFU))
#define LOW_BYTE(n)  ((uint8_t)((uint16_t)(n) & 0xFFU))

#define TRIS_ALL_READ	0xFF
#define TRIS_ALL_OUTPUT 0x00

#define PIN_CAT_IMPL(p, n) p##n
#define PIN_CAT(p, n)	   PIN_CAT_IMPL(p, n)

#define PIN_PORT(pin)	 PIN_CAT(R, pin)
#define PIN_TRIS(pin)	 PIN_CAT(TRIS, pin)
#define PORT_LATCH(port) PIN_CAT(PORT, port)
#define PORT_TRIS(port)	 PIN_CAT(TRIS, port)

#define PIN_SET_INPUT(pin)         \
	do {                       \
		PIN_TRIS(pin) = 1; \
	} while (0)

#define PIN_SET_OUTPUT(pin)        \
	do {                       \
		PIN_TRIS(pin) = 0; \
	} while (0)

#define PIN_DRIVE_LOW(pin)         \
	do {                       \
		PIN_PORT(pin) = 0; \
		PIN_TRIS(pin) = 0; \
	} while (0)

#define PIN_DRIVE_HIGH(pin)        \
	do {                       \
		PIN_PORT(pin) = 1; \
		PIN_TRIS(pin) = 0; \
	} while (0)

#define PORT_SET_INPUT(port)                     \
	do {                                     \
		PORT_TRIS(port) = TRIS_ALL_READ; \
	} while (0)

#define PORT_SET_OUTPUT(port)                      \
	do {                                       \
		PORT_TRIS(port) = TRIS_ALL_OUTPUT; \
	} while (0)

#define PORT_DRIVE_VALUE(port, val)       \
	do {                              \
		PORT_LATCH(port) = (val); \
		PORT_SET_OUTPUT(port);    \
	} while (0)

#define PORT_READ(port) (PORT_LATCH(port))

#endif
