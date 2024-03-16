#include "generic.h"
#include "ps2mem.h"
#include "mips.h"
#include "characters/character_list.h"
#include "stage.h"
#include "settings.h"
#include "scripthook.h"

void init_generic()
{
	//makeJal(0x215D7C, patch_freeze_reaction);
	makeJmp(0x215D90, freeze_reaction_patch);
	makeJmp(0x215DA0, freeze_reaction_patchP2);

	makeJal(0x25D03C, patch_lightning_sound);

	makeJal(0x206968, patch_weapon_grab);
	makeJal(0x2069DC, patch_weapon_show);
	makeJal(0x2066E4, patch_weapon_hide);
	makeJal(0x20C3E8, patch_weapon_hide);
	makeJal(0x20C0B0, patch_weapon_hide);



	makeJal(0x132CA8, hook_delete_player);
	makeJal(0x18D794, hook_delete_player);
	makeJal(0x18D79C, hook_delete_player);
	makeJal(0x3C7250, hook_delete_player);
	makeJal(0x3C7258, hook_delete_player);


	makeJal(0x170218, fatality_lock);
	makeJal(0x384674, fatality_lock);

	makeJal(0x22FA28, death_traps_lock);
	makeJal(0x3E2108, death_traps_lock);
	makeJal(0x3E24B4, death_traps_lock);

	int val = (int)&hook_plyr_start_proc;

	patchInt(0x13406C, lui(a1, HIWORD(val)));
	patchInt(0x134078, ori(a1, a1, LOWORD(val)));

	patchInt(0x134080, lui(a1, HIWORD(val)));
	patchInt(0x13408C, ori(a1, a1, LOWORD(val)));
	


}

void patch_freeze_reaction()
{
	player_data* plyr_data = *(player_data**)(PLAYER_DATA);
	player_data* p2_data = *(player_data**)(P2_PLAYER_DATA);

	int chrID_p2 = p2_data->characterID;
	int chrID_p1 = plyr_data->characterID;

	// add more ids to play the freeze reaction

	if (chrID_p2 == SUBZERO || chrID_p2 == FROST)
		patchShort(0x215D88, chrID_p2);
	else if (chrID_p1 == SUBZERO || chrID_p1 == FROST)
		patchShort(0x215D88, chrID_p1);

	init_ground_move();
}

void patch_freeze_sound()
{
	// TODO
	player_data* p2_data = *(player_data**)(P2_PLAYER_DATA);
	int id = p2_data->characterID;

	// fix sound properly, in mku they added a sound call to mko but forgot about sound id in freeze function
	// so when opponent is subzero and you freeze him, the freezing sound will play twice
	snd_req(SOUND_FROST_FREEZE);
}


void patch_weapon_grab(int data, int obj)
{
	plyr_weapon_grab(data, obj);
	player_data* pData = (player_data*)data;

	if (pData->characterID == GORO)
	{
		goro_grab_weapon(data);
	}
}


void patch_weapon_show(int data, int unk, int entry)
{
	plyr_weapon_show(data, unk, entry);
	player_data* pData = (player_data*)data;
	if (pData->characterID == GORO)
	{
		goro_show_weapon(data, unk);
	}
}

void patch_weapon_hide(int data, int unk, int entry)
{
	plyr_weapon_hide(data, unk, entry);
	player_data* pData = (player_data*)data;
	if (pData->characterID == GORO)
	{
		goro_hide_weapon(data, unk);
	}
}

void patch_lightning_sound(int id)
{
	int apdata = *(int*)AP_DATA;
	int procID = *(int*)(apdata + 8);
	int plrID = 0;

	if (*(int*)(*(int*)(apdata + 20) + 4))
		plrID = 1;

	int chrID = get_character_id(plrID);

	if (chrID == RAIN)
		snd_req(7576);
	else
		snd_req(686);
}

void goro_grab_weapon(int data)
{
	if (*(int*)(data + 432) == 1)
	{
		plyr_weapon_grab_direct(data, (int)&goro_gauntlet_ll_p2);
		plyr_weapon_grab_direct(data, (int)&goro_gauntlet_lr_p2);
	}
	else
	{
		plyr_weapon_grab_direct(data, (int)&goro_gauntlet_ll_p1);
		plyr_weapon_grab_direct(data, (int)&goro_gauntlet_lr_p1);
	}
}

void goro_show_weapon(int data, int unk)
{
	if (*(int*)(data + 432) == 1)
	{
		plyr_weapon_show(data, unk, (int)&goro_gauntlet_ll_p2);
	}
	else
	{
		plyr_weapon_show(data, unk, (int)&goro_gauntlet_ll_p1);
	}
}

void goro_hide_weapon(int data, int unk)
{
	if (*(int*)(data + 432) == 1)
	{
		plyr_weapon_hide(data, unk, (int)&goro_gauntlet_ll_p2);
	}
	else
	{
		plyr_weapon_hide(data, unk, (int)&goro_gauntlet_ll_p1);
	}
}

void render_fgnd_mkobjs()
{
	((void(*)())0x13D3F0)();
}

int fatality_lock()
{
	player_info* p1 = (player_info*)PLAYER1_INFO;
	player_info* p2 = (player_info*)PLAYER2_INFO;

	if (p1 && p2)
	{
		if (p1->characterID == KUNG_LAO && p1->life == 0.0f && p1->flags & 1)
			kunglao_fatality_hide_hat(0, p1->pObject);
		if (p2->characterID == KUNG_LAO && p2->life == 0.0f && p2->flags & 1)
			kunglao_fatality_hide_hat(1, p2->pObject);

		if (p1->characterID == BLAZE || p2->characterID == BLAZE)
		{
			if (!settings.blaze_enable_fatalities)
				return 0;
		}

	}

	return ((int(*)())0x16FCF0)();
}

int death_traps_lock()
{
	player_info* p1 = (player_info*)PLAYER1_INFO;
	player_info* p2 = (player_info*)PLAYER2_INFO;

	int bgnd = *(int*)(CUR_BGND);
	if (p1 && p2)
	{
		if (p1->characterID == BLAZE || p2->characterID == BLAZE)
		{
			if (bgnd == BGS_SKYTEMPLE || bgnd == BGS_LOWERMINES || bgnd == BGS_DARKPRISON || bgnd == BGS_FORTRESS)
			return 0;
		}
	}

	return ((int(*)())0x189A30)();
}

float hook_plyr_start_proc()
{
	blaze_reset_event();
	shangtsung_reset_event();
	sektor_reset_event();
	return ((float(*)())0x1315D0)();
}

void hook_delete_player(int id)
{
	player_info* p1 = (player_info*)(PLAYER1_INFO);
	player_info* p2 = (player_info*)(PLAYER2_INFO);
	if (p1->characterID == BLAZE)
		blaze_destroy_event(p1->id);
	if (p2->characterID == BLAZE)
		blaze_destroy_event(p2->id);

	//if (p1->characterID == GORO)
	//	goro_destroy_event(p1->id);
	//if (p2->characterID == GORO)
	//	goro_destroy_event(p2->id);

	delete_player(id);
}

void update_character(player_info* info)
{
	if (!info)
		return;
	if (!info->pObject)
		return;

	switch (info->characterID)
	{
	case GORO:
		goro_arms_bone_copy(info->pObject);
		break;
	case SEKTOR:
		sektor_update_chest(info->id, info->pObject, info->flags);
		break;
	default:
		break;
	}

}

void update_characters()
{
	player_info* p1 = (player_info*)(PLAYER1_INFO);
	player_info* p2 = (player_info*)(PLAYER2_INFO);

	update_character(p1);
	update_character(p2);
}
