#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "../BATTLE-OF-ATMOSPHERE/DirectX.h"
#include "../BATTLE-OF-ATMOSPHERE/Main.h"
#include "../BATTLE-OF-ATMOSPHERE/MapChip.h"
#include "../BATTLE-OF-ATMOSPHERE/Draw.h"

class GAME 
{
public:

	//座標
	INT m_pos_x = 0;
	INT m_pos_y = 0;

	//自機移動スピード
	INT m_spaceman_speed = 4;
	//スクロールの可視範囲
	FLOAT game_bg_tu = 0.25f;
	
	INT flamecount = 0;
	
	//スクロールのスピード
	#define SCROLL_SPEED  -0.001f

	//月の重力
	INT m_gravity = 1.6;
	
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
