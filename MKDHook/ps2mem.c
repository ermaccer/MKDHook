#include "ps2mem.h"
#pragma GCC push_options
#pragma GCC optimize ("O3")
void makeJal(unsigned int addr, void* func)
{
	*(int*)addr = ((0x0C000000 | (((unsigned int)func & 0x0fffffff) >> 2)));
}

void patchInt(unsigned int addr, int data)
{
	asm volatile ("sw $a1, 0($a0)");
	//*(int*)(addr) = data;
}

void patchFloat(unsigned int addr, float data)
{
	*(float*)(addr) = data;
}

void makeJmp(unsigned int addr, void* func)
{
	*(int*)addr = (0x08000000 | (((unsigned int)(func) & 0x0FFFFFFC) >> 2));
}

void NOP(unsigned int addr)
{
	patchInt(addr, 0);
}

void patchShort(unsigned int addr, short data)
{
	asm volatile ("sh $a1, 0($a0)");
	//*(short*)(addr) = data;
}
#pragma GCC pop_options