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

	INT fc_cereate_one = 0;
	INT fc_cereate_two = 0;


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
