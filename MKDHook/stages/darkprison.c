#include "darkprison.h"

struct mk_file_entry dkp_entry_table[DKP_FILES] = {
	{"darkprison.ssf"	,0, 4},


	{"darkprison.sec", 0, 1},
	{"darkprison.mko", 0, 3},
	{"darkprison_fx.mko", 0, 3},
	{"dkp_kon_cage.sec", 0, 1},
	{"dkp_kon_cyrax.sec", 0, 1},
	{"dkp_kon_drahmin.sec", 0, 1},
	{"dkp_kon_frost.sec", 0, 1},
	{"dkp_kon_fujin.sec", 0, 1},
	{"dkp_kon_goro.sec", 0, 1},
	{"dkp_kon_hsu.sec", 0, 1},
	{"dkp_kon_jax.sec", 0, 1},
	{"dkp_kon_kai.sec", 0, 1},
	{"dkp_kon_kano.sec", 0, 1},
	{"dkp_kon_khameleon.sec", 0, 1},
	{"dkp_kon_kintaro.sec", 0, 1},
	{"dkp_kon_kitana.sec", 0, 1},
	{"dkp_kon_kunglao.sec", 0, 1},
	{"dkp_kon_mavado.sec", 0, 1},
	{"dkp_kon_mokap.sec", 0, 1},
	{"dkp_kon_moloc.sec", 0, 1},
	{"dkp_kon_motaro.sec", 0, 1},
	{"dkp_kon_nitara.sec", 0, 1},
	{"dkp_kon_quanchi.sec", 0, 1},
	{"dkp_kon_rain.sec", 0, 1},
	{"dkp_kon_reiko.sec", 0, 1},
	{"dkp_kon_reptile.sec", 0, 1},
	{"dkp_kon_sareena.sec", 0, 1},
	{"dkp_kon_sektor.sec", 0, 1},
	{"dkp_kon_shangmk5.sec", 0, 1},
	{"dkp_kon_shaok.sec", 0, 1},
	{"dkp_kon_sheeva.sec", 0, 1},
	{"dkp_kon_shinnok.sec", 0, 1},
	{"dkp_kon_sonya.sec", 0, 1},
	{"dkp_kon_spec_forc.sec", 0, 1},
	{"dkp_kon_stryker.sec", 0, 1},
	{"darkprison_anims.sec", 0, 2},
};

// I:\ps2dvd\art\darkprison.ssf
struct mk_toc_entry dkp_file_table[DKP_FILES + 1] = {
		{&dkp_entry_table[0]	,0,0 },

		{&dkp_entry_table[1],	 0, 2202240 }, // darkprison.sec
		{&dkp_entry_table[2],	 0, 154264  }, // darkprison.mko
		{&dkp_entry_table[3],	 0, 4232    }, // darkprison_fx.mko
		{&dkp_entry_table[4],	 0, 108672  }, // dkp_kon_cage.sec
		{&dkp_entry_table[5],	 0, 128512  }, // dkp_kon_cyrax.sec
		{&dkp_entry_table[6],	 0, 99968   }, // dkp_kon_drahmin.sec
		{&dkp_entry_table[7],	 0, 97920   }, // dkp_kon_frost.sec
		{&dkp_entry_table[8],	 0, 102784  }, // dkp_kon_fujin.sec
		{&dkp_entry_table[9],	 0, 106752  }, // dkp_kon_goro.sec
		{&dkp_entry_table[10],	 0, 106496  }, // dkp_kon_hsu.sec
		{&dkp_entry_table[11],	 0, 102784  }, // dkp_kon_jax.sec
		{&dkp_entry_table[12],	 0, 99840   }, // dkp_kon_kai.sec
		{&dkp_entry_table[13],	 0, 103552  }, // dkp_kon_kano.sec
		{&dkp_entry_table[14],	 0, 103680  }, // dkp_kon_khameleon.sec
		{&dkp_entry_table[15],	 0, 124800  }, // dkp_kon_kintaro.sec
		{&dkp_entry_table[16],	 0, 94848   }, // dkp_kon_kitana.sec
		{&dkp_entry_table[17],	 0, 108928  }, // dkp_kon_kunglao.sec
		{&dkp_entry_table[18],	 0, 114304  }, // dkp_kon_mavado.sec
		{&dkp_entry_table[19],	 0, 102144  }, // dkp_kon_mokap.sec
		{&dkp_entry_table[20],	 0, 113280  }, // dkp_kon_moloc.sec
		{&dkp_entry_table[21],	 0, 117760  }, // dkp_kon_motaro.sec
		{&dkp_entry_table[22],	 0, 116992  }, // dkp_kon_nitara.sec
		{&dkp_entry_table[23],	 0, 99584   }, // dkp_kon_quanchi.sec
		{&dkp_entry_table[24],	 0, 95232   }, // dkp_kon_rain.sec
		{&dkp_entry_table[25],	 0, 107008  }, // dkp_kon_reiko.sec
		{&dkp_entry_table[26],	 0, 95616   }, // dkp_kon_reptile.sec
		{&dkp_entry_table[27],	 0, 102912  }, // dkp_kon_sareena.sec
		{&dkp_entry_table[28],	 0, 128512  }, // dkp_kon_sektor.sec
		{&dkp_entry_table[29],	 0, 110336  }, // dkp_kon_shangmk5.sec
		{&dkp_entry_table[30],	 0, 128256  }, // dkp_kon_shaok.sec
		{&dkp_entry_table[31],	 0, 107008  }, // dkp_kon_sheeva.sec
		{&dkp_entry_table[32],	 0, 102656  }, // dkp_kon_shinnok.sec
		{&dkp_entry_table[33],	 0, 106112  }, // dkp_kon_sonya.sec
		{&dkp_entry_table[34],	 0, 112128  }, // dkp_kon_spec_forc.sec
		{&dkp_entry_table[35],	 0, 105728  }, // dkp_kon_stryker.sec
		{&dkp_entry_table[36],	 0, 251520  }, // darkprison_anims.sec


		{0,0,0}
};

void init_dkp_toc()
{
	int baseSize = 2048;
	for (int i = 0; i < DKP_FILES; i++)
	{
		dkp_entry_table[i].belong = &dkp_file_table[0];
	}


	for (int i = 1; i < DKP_FILES; i++)
	{
		dkp_file_table[i].previousSize = baseSize;
		baseSize += (dkp_file_table[i].size + 2048 - 1) & -2048;
	}
}
