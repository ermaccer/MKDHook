#include "subzero.h"
#include "..\mkdeception.h"
#include "..\ps2mem.h"
#include "..\mips.h"
#include "..\scripthook.h"

struct scan_action scan_subzero_4 = {
	4628,
	0x300001E,
	23,
	MOVE_BACKWARDS,
	MOVE_FORWARD,
	-1,
	0,
	0
};


void fat_sz_start_iceblock()
{
	static float blockSize = 0.8f;

	patchShort(0x267E4C, *(short*)((int)&blockSize + 2));
	patchShort(0x267E54, *(short*)((int)&blockSize));

	((void(*)())0x22E820)();
}