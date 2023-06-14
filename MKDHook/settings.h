#pragma once
#include "build_config.h"

typedef struct {
	int no_intro;
	int enable_npc_select;
	int blaze_enable_fatalities;
	int enable_quick_start;
	int qs_mode;
}SSETTINGS;


#ifndef  PS2_BUILD

enum
{
	MaxIniSize = 5000
};

extern char PluginData[MaxIniSize];

#endif // ! PS2_BUILD

extern SSETTINGS settings;


void init_settings();