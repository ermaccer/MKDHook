#pragma once
// MKU JAX
#include "..\toc.h"
#include "..\moves.h"
#include "..\mkdeception.h"


#define JAX_FILES 20
#define JAX_TAUNT_NUM 15
#define JAX_TAUNT_START 557


extern struct mk_file_entry jax_entry_table[JAX_FILES];
extern struct mk_toc_entry jax_file_table[JAX_FILES + 1];


extern struct mk_file_entry jax_alt_entry_table[JAX_FILES];
extern struct mk_toc_entry jax_alt_file_table[JAX_FILES + 1];

extern struct scan_action scan_jax_1;
extern struct scan_fatality scan_jax_2;
extern struct scan_action scan_jax_3;
extern struct scan_action scan_jax_4;

void init_jax_toc();
void init_jax_patches();

int jax_grab_aux_weapon(int a1, int a2);
void jax_start_blast();
void jax_blast_color_patch(int obj, char* color);
int jax_blast_position_patch(int obj);
void random_jax_taunt();