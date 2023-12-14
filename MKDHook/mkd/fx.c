#include "fx.h"

fx_handle fx(char* name)
{
	return ((fx_handle(*)(char*))0x366920)(name);
}

fx_handle pfxhandle_spawn_at_bid_next(fx_handle fx, int obj, int boneID)
{
	return ((fx_handle(*)(fx_handle, int, int))0x26AFE0)(fx, obj, boneID);
}

fx_handle pfxhandle_spawn_at_bid_next_render(fx_handle fx, int obj, int boneID)
{
	return ((fx_handle(*)(fx_handle, int, int))0x26AF20)(fx, obj, boneID);
}

fx_handle resume_effect_at_obj_bid(int obj, int boneID, fx_handle fx, int unk, int unk2)
{
	return ((fx_handle(*)(int, int, fx_handle, int ,int))0x27F990)(obj, boneID, fx, unk, unk2);
}

fx_handle fx_by_owner(char* name, int who)
{
	return ((fx_handle(*)(char*, int))0x36BC30)(name, who);
}

void fx_reset(fx_handle fx)
{
	((void(*)(fx_handle))0x368EF0)(fx);
}

void fx_reset_emit(fx_handle fx)
{
	((void(*)(fx_handle))0x3690A0)(fx);
}

void fx_pause_emit(fx_handle fx)
{
	((void(*)(fx_handle))0x3693B0)(fx);
}
