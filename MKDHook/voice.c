#include "voice.h"
#include "mips.h"
#include "ps2mem.h"

static int voice_table[TOTAL_VOICES] = {
	2353, // mlna
	3273, // sz
	1157, // brc
	2905, // shuj_k
	973, // ashrah
	1065, // baraka
	1249, // dairu
	1433, //ermac
	1525, // hotaru
	1617, // jade
	1801, // kabal
	1893, // kenshi
	1985, // kira
	2077, // kobra
	2169, // li mei
	2261, // liu kang
	2445, // nwolf
	2537, // raiden
	2629, // scorp
	2721, // sebek
	2813, // shuj
	2997, // sindel
	3089, //smoke noob
	3365, // tanya
	1709, // jkelly 
	1341, // onaga
	7252, // shao kahn
	0,
};

void init_voice_hook()
{
	patchShort(0x12B6A0, TOTAL_VOICES);
	
	int val = (int)&voice_table[0];
	patchInt(0x12B6AC, lui(v0, HIWORD(val)));
	patchInt(0x12B6B4, ori(v0, v0, LOWORD(val)));
}
