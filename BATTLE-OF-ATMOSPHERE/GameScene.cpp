#include "../BATTLE-OF-ATMOSPHERE/GameScene.h"
#include <stdlib.h>
#include <time.h>

DRAWMAP map;

GAME::SCENE_PAHSE phase = GAME::LOAD;


//ゲームのフェーズの移動
VOID GAME::Game_Scene() 
{

	switch (phase) 
	{
	case LOAD:
		Loading();
		break;
	case PROCESSING:
		Process();
		break;
	case RELEASES:
		Release();
		phase = LOAD;
		break;
	}
}

//ゲームのテクスチャの読み込み
VOID GAME::Loading() 
{
	draw.LoadTexture("game_bg.png", GAME_BG);
	draw.LoadTexture("spaceman.png", SPACEMAN);
	phase = PROCESSING;
}

VOID GAME::Process() 
{
	draw.Draw(0, 0, 0xffffffff, 0.0f, game_bg_tu, 1920, 1080, 1.0f, 0.25f, GAME_BG);
	flamecount++;

	if(flamecount>=60)
	{
		game_bg_tu += 0.01;
	}
	if (game_bg_tu >= 0.5)
	{
		game_bg_tu = 0.0f;
		flamecount = 0;
	}
	m_pos_y += m_gravity;
	if (m_pos_y >= 900)
	{
		m_pos_y = 900;
	
	}

	draw.Draw(m_pos_x, m_pos_y, 0xffffffff, 0.0f, 0.0f, 100, 100, 1.0f, 1.0f, SPACEMAN);

	if (directx.KeyState[DIK_RIGHT] == directx.ON)
	{
		m_pos_x += m_spaceman_speed;
	
	}
	if (directx.KeyState[DIK_LEFT] == directx.ON)
	{
		m_pos_x -= m_spaceman_speed;

	}

	//リリースのフェーズへ
	if (directx.KeyState[DIK_RETURN] == directx.PRESS)
	{
		phase = RELEASES;
	}

}

//ゲームのテクスチャの解放
VOID GAME::Release() {

	//テクスチャの開放
	for (INT i = 0; i < TEX_MAX; i++) 
	{
		if (directx.pTexture[i] != nullptr) 
		{
			directx.pTexture[i]->Release();
			directx.pTexture[i] = nullptr;
		}
	}
	//リザルトシーンへ
	scene = RESULT_SCENE;
}
