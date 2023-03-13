#pragma once
typedef struct {
	int no_intro;
	int enable_npc_select;
}SSETTINGS;


enum
{
	MaxIniSize = 5000
};



extern char PluginData[MaxIniSize];
extern SSETTINGS settings;


void init_settings();