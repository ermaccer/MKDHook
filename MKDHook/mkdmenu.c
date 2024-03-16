#include "mkdmenu.h"
#include <stdio.h>
#include "mips.h"
#include "ps2mem.h"
#include "characters/kitana.h"
#include "scripthook.h"

#ifndef PS2_BUILD
CVector camPos;
CVector camRot;

struct Menu TheMenu;
float headOffset = 0.0f;
float headDistance = 0.0f;

float headOffset3 =1.0f;
float headDistance3 = -2.15f;

int m_nCurrentPos = 0;
int m_nCurrentMenuOpen = MENU_DEFAULT;
int hook_timer = 0;

int m_bScaleModifier = 0;
float m_nP1Scale = 1.0;
float m_nP2Scale = 1.0;

int m_bFirstPersonCam = 0;
int m_bThirdPersonCam = 0;
int m_bFreeCamera = 0;
int m_bKonquestFPCam = 0;
int m_bKonquestFPCamView = 0;
int m_bFreezeWorld = 0;


int menuAssoc[MENU_MAX_STRINGS * 2] =
{
	MENU_BAR_0,
	MENU_BAR_1,
	MENU_BAR_2,
	MENU_BAR_3,
	MENU_BAR_4,
	MENU_BAR_5,
	MENU_BAR_6,
	MENU_BAR_7,
	MENU_BAR_8,
	MENU_BAR_9,
};

int menuStrings[MENU_MAX_STRINGS] = {};
int titleBar;

const char* menuNames[MENU_MAX_STRINGS] =
{
	"Player",
	"Camera",
	"Speed",
	"Misc.",
};

const char* menuNamesPlayer[MENU_MAX_STRINGS] =
{
	"P1 Scale Modifier",
	"P2 Scale Modifier",
	"Enable Scale Modifier",
	"Reset Scale Values"
};

const char* menuNamesCamera[MENU_MAX_STRINGS] =
{
	"First Person Camera",
	"Third Person Camera",
	"Set FOV to 72 (default)",
	"Set FOV to 80 (ws default)",
	"Set FOV to 95",
	"Set FOV to 110",
	"Set FOV to 120",
	"Free Camera"
};

const char* menuNamesMisc[MENU_MAX_STRINGS] =
{
	"Kill HUD",
	"Disable Fatality Camera",
	"Enable Fatality Camera",
	"Chubbozo Mode",
	"Skinny Mode",
};

const char* menuNamesSpeed[MENU_MAX_STRINGS] =
{
	"Slowmotion",
	"Freeze World",
	"Reset Speed",
};

struct Menu GetMenu()
{
	return TheMenu;
}

int Menu_Init(int id, int font, char* text, int x, int y, int unk)
{
	int result = string_left_xy(id, font, text, x, y, unk);
	int offset = 0;
	titleBar = string_left_xy(MENU_BAR_0 - 1, 0, "MKDHook by ermaccer", x, y - 40, 88);
	TheMenu.m_bIsReady = 0;
	for (int i = 0; i < MENU_MAX_STRINGS; i++)
	{
		int offset = i + 1;
		static char tmp[128] = {};
		sprintf(tmp, "", i);
		menuStrings[i] = string_left_xy(menuAssoc[i], 0, tmp, x, y - 60 - (15 * (offset)), 88);
	}
	TheMenu.m_bIsReady = 1;
	TheMenu.m_bActive = 0;
	TheMenu.plrPos.x = 0;
	TheMenu.plrPos.y = 0;
	TheMenu.plrPos.z = 0;
	m_bFirstPersonCam = 0;
	m_bFreeCamera = 0;
	m_bThirdPersonCam = 0;
	hook_timer = get_game_tick();
	m_nCurrentPos = 0;
	m_bScaleModifier = 0;
	return result;
}

void Menu_Draw()
{
	if (!TheMenu.m_bIsReady)
		return;

	if (TheMenu.m_bActive)
	{
		pfx_2d_obj_set_alpha_by_id(MENU_BAR_0 - 1, 255);

		int str = TOTAL_MENU_DEFAULT;
		if (m_nCurrentMenuOpen == MENU_DEFAULT)
			str = TOTAL_MENU_DEFAULT;
		if (m_nCurrentMenuOpen == MENU_PLAYER)
			str = TOTAL_PLAYER;
		if (m_nCurrentMenuOpen == MENU_MISC)
			str = TOTAL_MISC;
		if (m_nCurrentMenuOpen == MENU_CAMERA)
			str = TOTAL_CAMERA;
		if (m_nCurrentMenuOpen == MENU_SPEED)
			str = TOTAL_MISC;
		for (int i = 0; i < str; i++)
		{
			if (m_nCurrentMenuOpen == MENU_DEFAULT)
				update_string_obj(menuStrings[i], 0, menuNames[i]);
			if (m_nCurrentMenuOpen == MENU_PLAYER)
			{
				char tmp[256] = {};
				switch (m_nCurrentPos)
				{
				case 0:
					sprintf(tmp, "%s %d", "Value - ", (int)(m_nP1Scale * 100));
					break;
				case 1:
					sprintf(tmp, "%s %d", "Value - ", (int)(m_nP2Scale * 100));
					break;
				case 2:
					sprintf(tmp, "%s %s", "Value - ", TRUE_FALSE(m_bScaleModifier));
					break;
				}
			
				update_string_obj(menuStrings[i], 0, menuNamesPlayer[i]);
				update_string_obj(menuStrings[TOTAL_PLAYER + 1], 0, tmp);
			}
			if (m_nCurrentMenuOpen == MENU_CAMERA)
			{
				char tmp[256] = {};
				switch (m_nCurrentPos)
				{
				case 0:
					sprintf(tmp, "%s %s", "Value - ", TRUE_FALSE(m_bFirstPersonCam));
					break;
				case 1:
					sprintf(tmp, "%s %s", "Value - ", TRUE_FALSE(m_bThirdPersonCam));
					break;
				case FREE_CAMERA:
					sprintf(tmp, "%s %s", "Value - ", TRUE_FALSE(m_bFreeCamera));
					break;
				default:
					sprintf(tmp, "Changes current field of view.");
					break;
				}
				update_string_obj(menuStrings[TOTAL_CAMERA + 1], 0, tmp);
				update_string_obj(menuStrings[i], 0, menuNamesCamera[i]);
			}
			if (m_nCurrentMenuOpen == MENU_SPEED)
			{
				char tmp[256] = {};
				update_string_obj(menuStrings[TOTAL_PLAYER + 1], 0, tmp);
				update_string_obj(menuStrings[i], 0, menuNamesSpeed[i]);
			}
			if (m_nCurrentMenuOpen == MENU_MISC)
			{
				char tmp[256] = {};
				update_string_obj(menuStrings[TOTAL_PLAYER + 1], 0, tmp);
				update_string_obj(menuStrings[i], 0, menuNamesMisc[i]);
			}

			if (m_nCurrentPos == i)
				pfx_2d_obj_set_alpha_by_id(menuAssoc[i], 255);
			else
				pfx_2d_obj_set_alpha_by_id(menuAssoc[i], 128);
		
		
		
		}
	}
	else
	{
		pfx_2d_obj_set_alpha_by_id(MENU_BAR_0 - 1, 0);
	
		for (int i = 0; i < MENU_MAX_STRINGS; i++)
		{
			pfx_2d_obj_set_alpha_by_id(menuAssoc[i], 0);
		}
	}

}


void Menu_Process()
{
	if (check_switch(0, PAD_L3))
		Menu_Toggle();

	if (GetAsyncKeyState(72))
		Menu_Toggle_FreezeWorld();

	if (GetAsyncKeyState(71))
		Menu_Toggle_FreeCam();

#ifdef SOUNDDEBUG_KEY
	if (GetAsyncKeyState(67))
		test_sound();

	if (GetAsyncKeyState(70))
	{
		player_info* plr1 = (player_info*)PLAYER1_INFO;
		player_info* plr2 = (player_info*)PLAYER2_INFO;

		if (plr1 && plr2)
		{
			//plr1->life = 0.01f;
			plr2->life = 0.01f;
		}
	}

	// FATALITY TESTER
	if (GetAsyncKeyState(49))
	{
		player_info* plr1 = (player_info*)PLAYER1_INFO;
		player_info* plr2 = (player_info*)PLAYER2_INFO;

		if (plr1 && plr2)
		{
			*(int*)0x5D63A4 = plr1->pData;
			*(int*)0x5D63A0 = plr1->pObject;
			
			*(int*)0x5D6398 = plr2->pData;
			*(int*)0x5D639C = plr2->pObject;
			*(int*)0x5D64FC = 1;

			xfer_proc(plr1->vm_proc, DO_FATALITY_ONE);
		}
	}

	if (GetAsyncKeyState(50))
	{
		player_info* plr1 = (player_info*)PLAYER1_INFO;
		player_info* plr2 = (player_info*)PLAYER2_INFO;

		if (plr1 && plr2)
		{
			*(int*)0x5D63A4 = plr1->pData;
			*(int*)0x5D63A0 = plr1->pObject;

			*(int*)0x5D6398 = plr2->pData;
			*(int*)0x5D639C = plr2->pObject;
			*(int*)0x5D64FC = 1;

			xfer_proc(plr1->vm_proc, DO_FATALITY_TWO);
		}
	}


	// MOVE TESTER
	if (GetAsyncKeyState(51))
	{
		if (get_game_tick() - hook_timer <= 10) return;
		hook_timer = get_game_tick();

		player_info* plr1 = (player_info*)PLAYER1_INFO;
		player_info* plr2 = (player_info*)PLAYER2_INFO;

		if (plr1 && plr2)
		{
			int mko = ((int(*)(int))0x21B440)(plr1->vm_proc);
			*(int*)(mko + 40) = debugVar[3];
			// rx 2101b0
			// p2 210120
			// p1 210170
			xfer_proc(plr1->vm_proc, 0x210170);
		}
	}


#endif

	if (TheMenu.m_bActive)
	{
		if (check_switch(0, PAD_CROSS))
			Menu_KeyCross();
		
		if (check_switch(0, PAD_TRIANGLE))
			Menu_KeyTriangle();
	
		if (check_switch(0, PAD_CIRCLE))
			Menu_KeyCircle();
	
		if (check_switch(0, PAD_UP))
			Menu_KeyUp();
	
		if (check_switch(0, PAD_DOWN))
			Menu_KeyDown();
	
		int str = TOTAL_MENU_DEFAULT;
	
		if (m_nCurrentMenuOpen == MENU_PLAYER)
			str = TOTAL_PLAYER;
		if (m_nCurrentMenuOpen == MENU_MISC)
			str = TOTAL_MISC;
		if (m_nCurrentMenuOpen == MENU_CAMERA)
			str = TOTAL_CAMERA;
		if (m_nCurrentMenuOpen == MENU_SPEED)
			str = TOTAL_SPEED;

		if (m_nCurrentPos < 0) m_nCurrentPos = str - 1;
		if (m_nCurrentPos >= str) m_nCurrentPos = 0;
	}
	Menu_Draw();
	Menu_Process_Toggles();
}

void Menu_Process_Toggles()
{
	if (m_bScaleModifier)
	{
		update_player1_scale();
		update_player2_scale();
	}
	if (m_bFirstPersonCam || m_bThirdPersonCam)
		Menu_ProcessCustomCams();
	else
		Menu_ProcessFreeCamera();
}

void Menu_Toggle()
{
	if (get_game_tick() - hook_timer <= 15) return;
	hook_timer = get_game_tick();
	TheMenu.m_bActive = !TheMenu.m_bActive;

	if (TheMenu.m_bActive)
		pause(1);
	else
		pause(0);
}

void Menu_KeyUp()
{
	if (get_game_tick() - hook_timer <= 10) return;
	hook_timer = get_game_tick();
	m_nCurrentPos -= 1;
}

void Menu_KeyDown()
{
	if (get_game_tick() - hook_timer <= 10) return;
	hook_timer = get_game_tick();
	m_nCurrentPos += 1;
}

void Menu_KeyCross()
{
	if (get_game_tick() - hook_timer <= 10) return;
	hook_timer = get_game_tick();
	Menu_ClearStrings();
	if (m_nCurrentMenuOpen == MENU_DEFAULT)
		m_nCurrentMenuOpen = m_nCurrentPos;
	else
	{
	if (m_nCurrentMenuOpen == MENU_PLAYER)
		Menu_ProcessPlayer();
	if (m_nCurrentMenuOpen == MENU_MISC)
		Menu_ProcessMisc();
	if (m_nCurrentMenuOpen == MENU_CAMERA)
		Menu_ProcessCamera();
	if (m_nCurrentMenuOpen == MENU_SPEED)
		Menu_ProcessSpeed();
	}

}

void Menu_KeyCircle()
{
	if (get_game_tick() - hook_timer <= 10) return;
	hook_timer = get_game_tick();
	if (!(m_nCurrentMenuOpen == MENU_DEFAULT))
	m_nCurrentMenuOpen = MENU_DEFAULT;
	Menu_ClearStrings();
}

void Menu_KeyTriangle()
{
	if (get_game_tick() - hook_timer <= 10) return;
	hook_timer = get_game_tick();

	if (m_nCurrentMenuOpen == MENU_PLAYER)
		Menu_ProcessPlayerReverse();
}

void Menu_ProcessPlayer()
{
	switch (m_nCurrentPos)
	{
	case 0:
		m_nP1Scale += 0.1f;
		break;
	case 1:
		m_nP2Scale += 0.1f;
		break;
	case 2:
		m_bScaleModifier= !m_bScaleModifier;
		break;
	case 3:
		m_nP1Scale = 1.0f;
		m_nP2Scale = 1.0f;
		break;
	default:
		break;
	}
}

void Menu_ProcessPlayerReverse()
{
	switch (m_nCurrentPos)
	{
	case 0:
		m_nP1Scale -= 0.1f;
		if (m_nP1Scale < 0)
			m_nP1Scale = 0;
		break;
	case 1:
		m_nP2Scale -= 0.1f;

		if (m_nP2Scale < 0)
			m_nP2Scale = 0;
		break;
	default:
		break;
	}
}

void Menu_ProcessMisc()
{
	switch (m_nCurrentPos)
	{
	case 0:
		init_fatality_world();
		break;
	case 1:
		disable_fatality_camera();
		break;
	case 2:
		enable_fatality_camera();
		break;
	case 3:
		enable_chubbozo_mode();
		break;
	case 4:
		enable_skinny_mode();
		break;
	case 5:
		enable_bigheads();
		break;
	default:
		break;
	}
}

void Menu_ProcessSpeed()
{
	switch (m_nCurrentPos)
	{
	case 0:
		set_game_speed(0.5f);
		break;
	case 1:
		set_game_speed(0.0f);
		break;
	case 2:
		set_game_speed(1.0f);
		break;
	default:
		break;
	}
}

void Menu_ProcessCamera()
{
	switch (m_nCurrentPos)
	{
	case 0:
		m_bFirstPersonCam = !m_bFirstPersonCam;
		break;
	case 1:
		m_bThirdPersonCam = !m_bThirdPersonCam;
		break;
	case FOV_72:
		setFov(72.0f);
		cam_recalc_midpoint();
		break;
	case FOV_90:
		setFov(80.0f);
		cam_recalc_midpoint();
		break;
	case FOV_95:
		setFov(95.0f);
		cam_recalc_midpoint();
		break;
	case FOV_110:
		setFov(110.0f);
		cam_recalc_midpoint();
		break;
	case FOV_120:
		setFov(120.0f);
		cam_recalc_midpoint();
		break;
	case FREE_CAMERA:
		m_bFreeCamera = !m_bFreeCamera;
		break;
	default:
		break;
	}
}

void Menu_ClearStrings()
{
	pfx_2d_obj_set_alpha_by_id(MENU_BAR_0 - 1, 0);

	for (int i = 0; i < MENU_MAX_STRINGS; i++)
	{
		pfx_2d_obj_set_alpha_by_id(menuAssoc[i], 0);
	}
}

void Menu_Unset()
{
	TheMenu.m_bIsReady = 0;
}

void Menu_ProcessCustomCams()
{
	player_info plr1 = *(player_info*)PLAYER1_INFO;
	player_info plr2 = *(player_info*)PLAYER2_INFO;
	if (plr1.pObject && plr2.pObject)
	{
		CVector headPos;
		CVector rightMat;
		CVector forwardMat;
		CVector headPosP2;
		static int id = 16;
		if (m_bThirdPersonCam)
			id = 14;
		else
			id = 16;

		get_bone_pos(plr1.pObject, id, &headPos);
		get_bone_pos(plr2.pObject, id, &headPosP2);

		get_matrix_right(plr1.pObject, &rightMat);
		get_matrix_forward(plr1.pObject, &forwardMat);

		if (m_bFirstPersonCam)
		{
			headPos.x += rightMat.x * headOffset;
			headPos.y += rightMat.y * headOffset;
			headPos.z += rightMat.z * headOffset;

			headPos.x += forwardMat.x * headDistance;
			headPos.y += forwardMat.y * headDistance;
			headPos.z += forwardMat.z * headDistance;
		}
		else
		{
			headPos.y += headOffset3;

			headPos.x += forwardMat.x * headDistance3;
			headPos.y += forwardMat.y * headDistance3;
			headPos.z += forwardMat.z * headDistance3;
		}

		set_cam_position(&headPos);
		set_cam_target(&headPosP2);
	}
}

void Menu_ProcessFreeCamera()
{
	int camera = *(int*)0x5D6698;
	if (m_bFreeCamera)
	{
		if (camera)
		{
			static float camSpeed = 0.15f;

			CVector rightMat;
			CVector forwardMat;
			get_matrix_right(camera, &rightMat);
			get_matrix_forward(camera, &forwardMat);

			if (GetAsyncKeyState(90))
				camSpeed = 0.035f;
			else
				camSpeed = 0.15f;

			if (GetAsyncKeyState(87))
			{
				camPos.x += camSpeed * forwardMat.x;
				camPos.y += camSpeed * forwardMat.y;
				camPos.z += camSpeed * forwardMat.z;
			}

			if (GetAsyncKeyState(83))
			{
				camPos.x -= camSpeed * forwardMat.x;
				camPos.y -= camSpeed * forwardMat.y;
				camPos.z -= camSpeed * forwardMat.z;
			}
			if (GetAsyncKeyState(65))
			{
				camPos.x += camSpeed * rightMat.x;
				camPos.y += camSpeed * rightMat.y;
				camPos.z += camSpeed * rightMat.z;
			}
			if (GetAsyncKeyState(68))
			{
				camPos.x -= camSpeed * rightMat.x;
				camPos.y -= camSpeed * rightMat.y;
				camPos.z -= camSpeed * rightMat.z;
			}
			if (GetAsyncKeyState(81))
				camPos.y += camSpeed;
			if (GetAsyncKeyState(69))
				camPos.y -= camSpeed;

			if (GetAsyncKeyState(37))
				camRot.y += camSpeed / 4.0f;
			if (GetAsyncKeyState(39))
				camRot.y -= camSpeed / 4.0f;

			if (GetAsyncKeyState(38))
				camRot.x -= camSpeed / 4.0f;
			if (GetAsyncKeyState(40))
				camRot.x += camSpeed / 4.0f;

			if (GetAsyncKeyState(88))
				camRot.z -= camSpeed / 4.0f;
			if (GetAsyncKeyState(67))
				camRot.z += camSpeed / 4.0f;

			set_cam_position(&camPos);
			set_cam_rotation(&camRot);

		}
	}
	else
	{
		if (camera)
		{
			camPos = *(CVector*)(camera + 160);
			camRot = *(CVector*)(camera + 208);
		}

	}

}

void Menu_Toggle_FreeCam()
{
	if (get_game_tick() - hook_timer <= 15) return;
	hook_timer = get_game_tick();
	m_bFreeCamera = !m_bFreeCamera;
}

void Menu_Toggle_KFP()
{
	if (get_game_tick() - hook_timer <= 15) return;
	hook_timer = get_game_tick();
	m_bKonquestFPCam = !m_bKonquestFPCam;
	setFov(100.0f);
}

void Menu_Toggle_KFP_Look()
{
	if (get_game_tick() - hook_timer <= 15) return;
	hook_timer = get_game_tick();
	m_bKonquestFPCamView = !m_bKonquestFPCamView;
}


void Menu_Toggle_KHud()
{
	if (get_game_tick() - hook_timer <= 15) return;
	hook_timer = get_game_tick();
	konquest_hide_hud();
}

void Menu_Toggle_FreezeWorld()
{
	if (get_game_tick() - hook_timer <= 15) return;
	hook_timer = get_game_tick();
	m_bFreezeWorld = !m_bFreezeWorld;

	if (m_bFreezeWorld)
		set_game_speed(0.0f);
	else
		set_game_speed(1.0f);
}

void setFov(float value)
{
	*(float*)(0x5D4DD4) = value;
}

void Menu_Init_Vars()
{
		m_bFreeCamera = 0;
		m_bKonquestFPCam = 0;
		m_bKonquestFPCamView = 0;
}

void Menu_K_Reset()
{
	m_bKonquestFPCam = 0;
	m_bKonquestFPCamView = 0;
}

void disable_fatality_camera()
{
	NOP(0x26E1FC);
	NOP(0x26E1E0);
	NOP(0x26D9C8);
	NOP(0x26D9AC);
}

void enable_fatality_camera()
{
	patchInt(0x26E1FC, jal(0x12C3E0));
	patchInt(0x26E1E0, jal(0x17CF00));
	patchInt(0x26D9C8, jal(0x12C3E0));
	patchInt(0x26D9AC, jal(0x17CF00));
}

void enable_chubbozo_mode()
{
	player_info plr1 = *(player_info*)PLAYER1_INFO;
	player_info plr2 = *(player_info*)PLAYER2_INFO;
	if (plr1.pObject)
		kitana_kod_stretcher(plr1.pObject, 1.2f);

	if (plr2.pObject)
		kitana_kod_stretcher(plr2.pObject, 1.2f);

}

void enable_skinny_mode()
{
	player_info plr1 = *(player_info*)PLAYER1_INFO;
	player_info plr2 = *(player_info*)PLAYER2_INFO;
	if (plr1.pObject)
		kitana_kod_stretcher(plr1.pObject, -0.4f);

	if (plr2.pObject)
		kitana_kod_stretcher(plr2.pObject, -0.4f);
}

void enable_bigheads()
{
	player_info plr1 = *(player_info*)PLAYER1_INFO;
	player_info plr2 = *(player_info*)PLAYER2_INFO;
	if (plr1.pObject)
	{
		scale_bone(plr1.pObject, 17, 2.5f);

	}
	if (plr2.pObject)
	{
			scale_bone(plr1.pObject, 17, 2.5f);
	}

}

void update_player1_scale()
{
	player_info plr1 = *(player_info*)PLAYER1_INFO;
	if (plr1.pObject)
	{
		int obj = plr1.pObject;
		float scale = m_nP1Scale;

		{
			*(char*)(obj + 8) = *(char*)(obj + 8) & 0xFFFFFFBF | 0x40;

			{
				*(float*)(obj + 240) = scale;
				*(float*)(obj + 244) = scale;
				*(float*)(obj + 248) = scale;
			}
		}
	}
}

void update_player2_scale()
{
	player_info plr2 = *(player_info*)PLAYER2_INFO;
	if (plr2.pObject)
	{
		int obj = plr2.pObject;
		float scale = m_nP2Scale;

		{
			*(char*)(obj + 8) = *(char*)(obj + 8) & 0xFFFFFFBF | 0x40;

			{
				*(float*)(obj + 240) = scale;
				*(float*)(obj + 244) = scale;
				*(float*)(obj + 248) = scale;
			}
		}
	}
}
void test_sound()
{
	if (get_game_tick() - hook_timer <= 15) return;
	hook_timer = get_game_tick();

	snd_req(debugVar[0]);
}
void konquest_camera()
{
	int monk = get_monk();
	int camera = *(int*)0x5D6698;
	if (monk)
	{
		static CVector k_camRot;
		CVector pos = *(CVector*)(monk + 160);
		get_bone_pos(monk, 10, &pos);
		setFov(100.0f);
		set_cam_position(&pos);

		if (check_switch(0, PAD_R3))
			Menu_Toggle_KFP_Look();

		if (camera && !m_bKonquestFPCamView)
			k_camRot = *(CVector*)(camera + 208);
		else if (m_bKonquestFPCamView)
		{
			float x, y;
			get_stick_pos(0, 1, &x, &y);
			k_camRot.y += -x * 0.065f;
			k_camRot.x += y * 0.065f;
			set_cam_rotation(&k_camRot);
		}
	}
}

void Konquest_Process_Cameras()
{
	if (GetAsyncKeyState(71))
		Menu_Toggle_FreeCam();
	if (GetAsyncKeyState(70))
		Menu_Toggle_KFP();

	if (check_switch(0, PAD_L3))
		Menu_Toggle_KHud();

	if (m_bKonquestFPCam)
		konquest_camera();

	Menu_ProcessFreeCamera();
}

#endif // !PS2_BUILD

