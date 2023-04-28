#include "generic.h"
#include "ps2mem.h"
#include "mips.h"
#include "characters/character_list.h"
#include "stage.h"
#include "settings.h"

void init_generic()
{
	makeJal(0x215D38, patch_freeze_reaction);
	makeJal(0x1906A8, patch_freeze_sound);

	makeJal(0x132CA8, hook_delete_player);
	makeJal(0x18D794, hook_delete_player);
	makeJal(0x18D79C, hook_delete_player);
	makeJal(0x3C7250, hook_delete_player);
	makeJal(0x3C7258, hook_delete_player);

	makeJal(0x170218, fatality_lock);
	makeJal(0x384674, fatality_lock);

	int val = (int)&hook_plyr_start_proc;

	patchInt(0x13406C, lui(a1, HIWORD(val)));
	patchInt(0x134078, ori(a1, a1, LOWORD(val)));

	patchInt(0x134080, lui(a1, HIWORD(val)));
	patchInt(0x13408C, ori(a1, a1, LOWORD(val)));

}

void patch_freeze_reaction()
{
	freeze_player();

	player_data* plyr_data = *(player_data**)(PLAYER_DATA);
	player_data* p2_data = *(player_data**)(P2_PLAYER_DATA);

	int chrID_p2 = p2_data->characterID;
	int chrID_p1 = plyr_data->characterID;
	
	// add more ids to play the freeze reaction

	if (chrID_p2 == SUBZERO || chrID_p2 == FROST)
	{
		patchShort(0x215D88, chrID_p2);
	}
	else if (chrID_p1 == SUBZERO || chrID_p1 == FROST)
	{
		patchShort(0x215D88, chrID_p1);
	}


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

int fatality_lock()
{
	player_info* p1 = (player_info*)PLAYER1_INFO;
	player_info* p2 = (player_info*)PLAYER2_INFO;

	if (p1 && p2)
	{
		if (p1->characterID == BLAZE || p2->characterID == BLAZE)
		{
			if (!settings.blaze_enable_fatalities)
			return 0;
		}

	}




	return ((int(*)())0x16FCF0)();
}

float hook_plyr_start_proc()
{
	blaze_reset_event();
	return ((float(*)())0x1315D0)();
}

void hook_delete_player(int id)
{
	blaze_destroy_event(id);
	delete_player(id);
}
