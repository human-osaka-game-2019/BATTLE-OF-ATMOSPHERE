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
	draw.LoadTexture("Texture/spaceman.png", SPACEMAN);
}

VOID GAME::Process() 
{
	m_pos_y += m_gravity;
	if (m_pos_y >= 900)
	{
		m_pos_y = 900;
	
	}

	draw.Draw(m_pos_x, m_pos_y, 0xffffffff, 0.0f, 0.0f, 100, 100, 1.0f, 1.0f, SPACEMAN);

	if (directx.KeyState[DIK_RIGHT] == directx.PRESS)
	{
		m_pos_x += m_spaceman_speed;
		/*if (m_pos_x>=)
		{
		
		
		}*/
	
	}
	if (directx.KeyState[DIK_LEFT] == directx.PRESS)
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
