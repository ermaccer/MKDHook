#include "qs.h"
#include "mkdeception.h"
#include "character.h"
#include "stage.h"

void p_quickstart()
{
	player_info* plr1 = (player_info*)PLAYER1_INFO;
	player_info* plr2 = (player_info*)PLAYER2_INFO;

	((void(*)(int))0x1357F0)(PLAYER1_INFO);
	((void(*)(int))0x1357F0)(PLAYER2_INFO);
	((void(*)(int))0x27C330)(PLAYER1_INFO);
	((void(*)(int))0x27C330)(PLAYER2_INFO);
	((void(*)(int))0x27BF60)(0);
	((void(*)(int))0x27BF60)(1);


	plr1->id = 0;
	plr1->state = 1;
	plr2->id = 1;
	if (!(settings.qs_mode == MODE_PRACTICE))
		plr2->state = 1;

	*(int*)0x628F34 = 1;

	set_game_mode(settings.qs_mode);

	((void(*)())0x195920)();

}
