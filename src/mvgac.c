#include "mvgac.h"
#include <xc.h>

void serial_putchar(const char c)
{
	while (!TXIF);
	TXREG = c;
}

void serial_prints(const char *str)
{
	while (*str != '\0') serial_putchar(*str++);
}
