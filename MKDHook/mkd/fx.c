#include "fx.h"

fx_handle fx(char* name)
{
	return ((fx_handle(*)(char*))0x366920)(name);
}

fx_handle pfxhandle_spawn_at_bid_next(fx_handle fx, int obj, int boneID)
{
	return ((fx_handle(*)(fx_handle, int, int))0x26AFE0)(fx, obj, boneID);
}

void fx_reset(fx_handle fx)
{
	((void(*)(fx_handle))0x368EF0)(fx);
}

void fx_reset_emit(fx_handle fx)
{
	((void(*)(fx_handle))0x3690A0)(fx);
}
