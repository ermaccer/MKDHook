#include "settings.h"
#include "pcsx2/inireader.h"
#include "mkdeception.h"

char PluginData[MaxIniSize] = { 1 };
SSETTINGS settings;

void init_settings()
{
	inireader.SetIniPath((char*)PluginData + sizeof(unsigned int), *(unsigned int*)PluginData);

	settings.no_intro = inireader.ReadInteger("Settings", "SkipIntro", 0);
	_printf("Settings read!\n");
}
