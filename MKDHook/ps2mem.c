#include "ps2mem.h"

void makeJal(unsigned int addr, void* func)
{
	*(int*)addr = ((0x0C000000 | (((unsigned int)func & 0x0fffffff) >> 2)));
}
