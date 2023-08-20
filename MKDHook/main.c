#include <stdio.h>
#include "ps2mem.h"
#include "mkdeception.h"
#include "character.h"
#include "mkdhook.h"
#include "mkdmenu.h"
#include "stage.h"
#include "ladder.h"
#include "moves.h"
#include "scripthook.h"
#include "misc/pselect.h"
#include "misc/misc_anims.h"
#include "sound.h"
#include "reactions.h"
#include "sound_bank.h"
#include "misc/fatalityanims.h"
#include "settings.h"
#include "generic.h"
#include "voice.h"
#include "chess.h"
#include "build_config.h"
#include "qs.h"

#ifndef PS2_BUILD
int CompatibleCRCList[] = { 0x7C22850A };
#endif

int version_hook(int id, int font, char* text, int x, int y, int unk)
{

#ifdef PS2_BUILD
    static const char* versionText = "UMKD V4 BY ERMACCER (PS2)" ;
#else
    static const char* versionText = "UMKD V4 BY ERMACCER ";
#endif // PS2_BUILD

    return string_left_xy(id, font, versionText, x - 350, y + 40, unk);
}


void init()
{
   init_settings();
#ifndef PS2_BUILD
   Menu_Init_Vars();
#endif
   init_mkdhook_vars();


   if (settings.no_intro)
   {
       *(int*)0x197258 = 0; //960000
       *(int*)0x196F58 = 0;
       makeJmp(0x197698, (void*)0x19776C);
   }


   makeJal(0x1238C4, hook_render);
#ifndef PS2_BUILD
   makeJal(0x1A3EFC, Menu_Init);
#endif

   init_pselect_hook();
   init_character_hook();
   init_stage_hook();
   init_ladder_hook();
   init_moves_hook();
   init_script_hook();
   init_sound_hook();
   init_sound_bank_hook();
   init_reactions_hook();
   patch_misc_anims_toc();
   init_fatanims_hook();
   init_generic();
   init_voice_hook();
   init_chess_hook();

   makeJal(0x15C1D4, version_hook);
   makeJal(0x15C1F8, version_hook);

#ifndef PS2_BUILD
   _printf("MKDHook init! Debug var ptr: %X\n", &debugVar);

    if (settings.enable_quick_start)
        makeJmp(0x240220, p_quickstart);
#endif
}

#ifdef PS2_BUILD
// needs to be 03 because O0 ironically does some funky stuff with this function
void __attribute__((optimize("O3"))) INVOKER()
{
    asm("ei\n");
    asm("addiu $ra, -4\n");

    init();
}
#endif // PS2_BUILD




int __attribute__((optimize("O3"))) main()
{
    return 0;
}
