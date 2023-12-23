#include "script.h"
#include "..\scripthook.h"
#include "..\types.h"

int snd_req(int id)
{
	return ((int(*)(int))0x12B2B0)(id);
}

int snd_req_vol(int id, float vol)
{
	return ((int(*)(int, float))0x12B1C0)(id, vol);
}

void snd_stop(int sound)
{
    ((void(*)(int))0x12AE20)(sound);
}

void set_music(int id)
{
	((void(*)(int))0x3A4CE0)(id);
}

int am_i_flipped()
{
	return ((int(*)())0x1F0890)();
}

int am_i_flipped_direct(int obj)
{
	// original method crashes on ps2
	// so this is improved crashfree one

	int flags = *(int*)(obj + 8);
	return (flags >> 17) & 1;
}

void swap_active_proc()
{
	((void(*)())0x135670)();
}

int get_cur_proc_pobj()
{
	int apdata = *(int*)AP_DATA;

	if (!apdata)
		return 0;

	int pobj = *(int*)(apdata + 12);

	//if (pobj)
	//{
	//	if (!((*(int*)pobj + 4) == *(int*)(apdata + 16)))
	//		pobj = 0;
	//}


	return pobj;
}

void freeze_player()
{
	((int(*)())0x1903B0)();
}

void init_ground_move()
{
	((int(*)())0x1F36D0)();
}

int plyr_aux_weapon_release(int a1)
{
	return ((int(*)(int))0x228420)(a1);
}

int plyr_aux_weapon_grab(int a1, int a2)
{
	return ((int(*)(int, int))0x228430)(a1, a2);
}

void pfx_bind_emitter_num_to_obj_bone(int pfx, int obj, int boneID, int pfxID)
{
	((void(*)(int, int, int, int))0x217480)(pfx, obj, boneID, pfxID);
}

int get_new_emitter_obj(int frameID)
{
	int obj = get_new_mkobj(frameID);
	if (obj)
	{
		set_obj_flag(obj, 1, 1);
		insert_particle_mkobj(obj);
	}
	return obj;
}

void execute_rx_cleanup(int pData)
{
	((int(*)(int))0x20D760)(pData);
}

void reaction_xfer_him(int id, int a2, float a3)
{
	((void(*)(int, int, float))0x20E9D0)(id, a2, a3);
}

void force_away(int a1, int a2)
{
	((void(*)(int, int))0x1F8890)(a1, a2);
}
