#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <Windows.h>

typedef struct 
{
	BOOL is_one_win = FALSE;
	BOOL is_two_win = FALSE;
}WINNER;

class GAME
{
public:


	//スクロールの可視範囲
	FLOAT game_bg_tu = 0.25f;
	INT fc_background = 0;

	INT fc_count = 0;

	FLOAT count_tv = 0.0f;
	
	INT fc_finish = 0;
	INT finish_left_y = -600;
	INT finish_right_y = 1920;
	INT left_scr = 20;
	INT right_scr = 10;
	INT fc_right_finish_move = 0;
	INT fc_left_finish_move = 0;

	INT fc_cereate_one = 0;
	INT fc_cereate_two = 0;
	INT fc_ice_time_one = 0;
	INT fc_ice_time_two = 0;

	//スクロールのスピード
#define SCROLL_SPEED  -0.001f

	VOID Game_Scene();

	VOID Loading();
	VOID Process();
	VOID Release();

	enum SCENE_PAHSE
	{
		LOAD,
		PROCESSING,
		RELEASES
	};

};
#endif
