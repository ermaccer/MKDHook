#include "settings.h"
#include "pcsx2/inireader.h"
#include "mkdeception.h"

SSETTINGS settings = {};
#ifndef  PS2_BUILD
char PluginData[MaxIniSize] = { 1 };
#endif
void init_settings()
{
#ifndef  PS2_BUILD
	inireader.SetIniPath((char*)PluginData + sizeof(unsigned int), *(unsigned int*)PluginData);

	settings.no_intro = inireader.ReadInteger("Settings", "SkipIntro", 0);
	settings.blaze_enable_fatalities = inireader.ReadInteger("Settings", "BlazeEnableFatalities", 0);
	settings.enable_npc_select = inireader.ReadInteger("Settings", "EnableNPCSelect", 0);

	settings.enable_quick_start = inireader.ReadInteger("Settings", "QuickStart", 0);
	settings.qs_mode = inireader.ReadInteger("Settings", "QSMODE", 1);
	settings.extended_konquest_draw_distance = inireader.ReadInteger("Settings", "ExtendedKonquestDrawDistance", 0);

	_printf("Settings read!\n");
#else
	settings.no_intro = 0;
	settings.blaze_enable_fatalities = 0;
#endif
}
