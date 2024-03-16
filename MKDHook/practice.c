#include "practice.h"
#include "mips.h"
#include "ps2mem.h"

player_info* cached_info = 0;

void init_practice_hook()
{
	cached_info = 0;
	makeJal(0x1A3154, display_pratice_damage);
	makeJal(0x1A32D4, display_pratice_damage);

	makeJal(0x189680, practice_sprintf_hook);
}

void display_pratice_damage(player_info* info)
{
	cached_info = info;

	((void(*)(player_info*))0x1895C0)(info);
}

void practice_sprintf_hook(char* dst, char* fmt, int damageValue)
{
	int hitRegion = 7;

	if (cached_info)
	{
		player_data* pData = (player_data*)cached_info->pData;
		if (pData)
		{
			hitRegion = pData->lastHitLevel;
		}
	}
	if (damageValue > 0)
		((void(*)(char*, char*, int, char*))0x1E9660)(dst, "%d  %s", damageValue, practice_get_hit_level_name(hitRegion));
	else
		((void(*)(char*, char*, int))0x1E9660)(dst, "%d", damageValue);
}

char* practice_get_hit_level_name(int lvl)
{
	switch (lvl)
	{
	case 0:
		return "HIGH";
	case 1:
		return "LOW";
	case 2:
		return "UNBLOCKABLE";
	case 3:
	case 4:
	case 5:
		return "MID";
	case 6:
		return "THROW";
	case 7:
		return "S. HIGH";
	case 8:
		return "S. LOW";
	case 9:
		return "S. MID";
	default:
		break;
	}

	return "SPECIAL";
}
