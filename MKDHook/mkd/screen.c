#include "screen.h"

void load_screen(const char* screenPath, int slot, int procData, int unloadSlot)
{
	((void(*)(const char*, int, int, int))0x3578F0)(screenPath, slot, procData, unloadSlot);
}

void refresh_screen()
{
	((void(*)())0x357520)();
}
