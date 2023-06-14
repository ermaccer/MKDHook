#pragma once
// GC/MKU GORO
#include "..\toc.h"
#include "..\mkd\core.h"
#include "..\mkd\plr_info.h"

#define NUM_GOROMAPBONES 12


typedef struct {
	int src;
	int dest;
}goro_bone_map;


#define GORO_FILES 20



extern weapon_entry goro_gauntlet_ll_p1;
extern weapon_entry goro_gauntlet_lr_p1;
extern weapon_entry goro_gauntlet_ll_p2;
extern weapon_entry goro_gauntlet_lr_p2;

extern moveset goro_wp_mv_p1;
extern moveset goro_wp_mv_p2;
extern int	   goro_wp_dsc_ptrs[3];


extern weapon_mdl_description gauntlet_lr;
extern weapon_mdl_description gauntlet_ll;


extern int gauntlet_weapon_bones[2];
extern int gauntlet_trail_bones[2];
extern int gauntlet_trail_anchors[18];
extern int gauntlet_trail_tails[3];



extern struct mk_file_entry goro_entry_table[GORO_FILES];
extern struct mk_toc_entry goro_file_table[GORO_FILES + 1];

extern struct mk_file_entry goro_alt_entry_table[GORO_FILES];
extern struct mk_toc_entry goro_alt_file_table[GORO_FILES + 1];

extern struct scan_action_fatality scan_goro_1;
extern struct scan_action scan_goro_2;
extern struct scan_action_dual_one_fatality scan_goro_3;

extern struct scan_suicide scan_goro_suicide;

void init_goro_toc();
void init_goro_patches();


void start_goro_arms_fixup();
void start_goro_extra_weapons();
void set_goro_flipped_bones();
void goro_arms_bone_copy(int obj);
void goro_destroy_event(int id);
void goro_reset_event();