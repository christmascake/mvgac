#include "decoder.h"

void decoder_write(enum DECODER_FLAGS flag)
{
	DECODER_DRIVE_VALUE(flag);
	DECODER_OUTPUT_DRIVE();
	NOP();
	DECODER_OUTPUT_RELEASE();
}
