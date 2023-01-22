#include "content.h"

int is_bgnd_locked(int id)
{
	return ((int(*)(int))0x192580)(id);
}

int is_char_locked(int id, int param)
{
	return ((int(*)(int, int))0x13DF20)(id, param);
}
