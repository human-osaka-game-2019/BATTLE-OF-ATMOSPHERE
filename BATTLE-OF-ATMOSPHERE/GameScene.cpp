#include "../BATTLE-OF-ATMOSPHERE/GameScene.h"
#include <stdlib.h>
#include <time.h>

//DRAWMAP drawmap;
STAGE stage;

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
	draw.LoadTexture("battleofatomosphere_block.png", GAME_STAGE);

	stage.InitStage();


	phase = PROCESSING;
}

VOID GAME::Process() 
{
	//ゲーム背景の描画
	draw.Draw(0, 0, 0xffffffff, 0.0f, game_bg_tu, 1920, 1080, 1.0f, 0.25f, GAME_BG);
	
	
	fc_background++;
	//縦スクロールのアニメーション
	if(fc_background >=2)
	{
		game_bg_tu += SCROLL_SPEED;
		fc_background = 0;
		if (game_bg_tu <= -1.0f)
		{
			game_bg_tu = 0.0f;
		}
		//ブロックをスクロールに合わせて落とす処理
		for (int i = 0; i < BLOCK_QUANTITY; i++)
		{
			stage.ScrollBlock(&stage.block[i]);
		}
		//重力
		m_pos_y += m_gravity;
		//仮の当たり判定
		if (m_pos_y >= 825)
		{
			m_pos_y = 825;
		
		}
	}

	//ブロックの描画
	for (int i = 0; i < BLOCK_QUANTITY; i++)
	{
		stage.DrawBlock(stage.block[i]);

	}

	//自機の描画
	draw.Draw(m_pos_x, m_pos_y, 0xffffffff, 0.0f, 0.0f, 128, 256, 1.0f, 1.0f, SPACEMAN);
	//自機の移動
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
