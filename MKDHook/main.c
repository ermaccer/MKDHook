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

int CompatibleCRCList[] = { 0x7C22850A };

void dummy() {}
int dummy_true() { return 1; }

void init()
{
   Menu_Init_Vars();
   init_mkdhook_vars();

   // skip intro
   *(int*)0x197258 = 0;
   *(int*)0x196F58 = 0;
   makeJmp(0x197698, (void*)0x19776C);

   makeJal(0x1238C4, hook_render);
   makeJal(0x1A3EFC, Menu_Init);

   init_pselect_hook();
   init_character_hook();
   init_stage_hook();
   init_ladder_hook();
   init_moves_hook();
   init_script_hook();
   init_sound_hook();
   init_reactions_hook();
   patch_misc_anims_toc();

   dump_reactions_table();

   _printf("MKDHook init! %x\n", &debugVar[0]);
}

int main()
{
    return 0;
}
