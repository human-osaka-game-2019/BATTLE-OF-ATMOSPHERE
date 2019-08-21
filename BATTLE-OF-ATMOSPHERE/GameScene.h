#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "../BATTLE-OF-ATMOSPHERE/DirectX.h"
#include "../BATTLE-OF-ATMOSPHERE/Main.h"
#include "../BATTLE-OF-ATMOSPHERE/MapChip.h"
#include "../BATTLE-OF-ATMOSPHERE/Draw.h"

class GAME 
{
public:

	INT m_pos_x = 0;
	INT m_pos_y = 0;

	INT m_spaceman_speed = 4;
	FLOAT game_bg_tu = 0.25f;
	INT flamecount = 0;
	
	#define SCROLL_SPEED  0.005f

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
