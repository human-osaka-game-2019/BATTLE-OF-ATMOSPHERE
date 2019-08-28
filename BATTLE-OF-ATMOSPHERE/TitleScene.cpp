#include "../BATTLE-OF-ATMOSPHERE/TitleScene.h"
#include"../BATTLE-OF-ATMOSPHERE/MapChip.h"


//タイトルのフェーズの宣言
TITLE::SCENE_PHASE phase = TITLE::LOAD;
//
//MapchipLoading Mp;
//DrawMap map;

//タイトルのフェーズの移動
VOID TITLE::Title_Scene() 
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

//タイトルのテクスチャの読み込み
VOID TITLE::Loading() 
{
	draw.LoadTexture("title_bg.png", TITLE_BG);
	draw.LoadTexture("title_ui.png", TITLE_UI);
	draw.LoadTexture("title_logo.png", TITLE_LOGO);
	phase = PROCESSING;
	
	current_id = title_ui_exit;
	nextscene = GAME_SCENE;
}

//タイトルの描画処理
VOID TITLE::Process() 
{
	draw.Draw(0, 0, 0xffffffff, 0.0f, 0.0f, 1920, 1080, 1.0f, 1.0f, TITLE_BG);
	//タイトルUIの描画
	draw.Draw(600, 610, 0xffffffff, m_title_ui_tu_start, 0.0f,600,200, 0.5f, 0.25f, TITLE_UI);
	draw.Draw(600, 710, 0xffffffff, m_title_ui_tu_help, 0.25f,600,200, 0.5f, 0.25f, TITLE_UI);
	draw.Draw(600, 810, 0xffffffff, m_title_ui_tu_exit, 0.5f, 600,200, 0.5f, 0.25f, TITLE_UI);

	draw.Draw(460, 100, 0xffffffff, 0.0f, 0.0f, 1000, 500, 1.0f, 1.0f, TITLE_LOGO);

	if (directx.KeyState[DIK_DOWN] == directx.PRESS)
	{
		// ボタンを押されたら選択UIをいったんリセット
		m_title_ui_tu_start = 0.0f;
		m_title_ui_tu_help = 0.0f;
		m_title_ui_tu_exit = 0.0f;

		//それぞれのUIがアニメーション、そのシーンへ遷移
		switch (current_id)
		{
		case title_ui_start:
			current_id = title_ui_help;
			m_title_ui_tu_help += 0.5f;
			nextscene = HELP_SCENE;
			break;
		case title_ui_help:
			current_id = title_ui_exit;
			m_title_ui_tu_exit += 0.5f;
			nextscene = EXIT_SCENE;
			break;
		case title_ui_exit:
			current_id = title_ui_start;
			m_title_ui_tu_start += 0.5f;
			nextscene = GAME_SCENE;
			break;
		default:
			break;
		}

	}
	//エンターでゲームへ
	if (directx.KeyState[DIK_RETURN] == directx.PRESS) 
	{
		m_title_ui_tu_start = 0.5f;
		m_title_ui_tu_help = 0.0f;
		m_title_ui_tu_exit = 0.0f;
		phase = RELEASES;

	}
}

//タイトルのテクスチャの解放
VOID TITLE::Release() 
{

	for (INT i = 0; i < TEX_MAX; i++) 
	{
		if (directx.pTexture[i] != nullptr) 
		{
			directx.pTexture[i]->Release();
			directx.pTexture[i] = nullptr;
		}
	}

	if (nextscene == GAME_SCENE) 
	{
		scene = GAME_SCENE;
	}
	if (nextscene == HELP_SCENE) 
	{
		scene = HELP_SCENE;
	}
	if (nextscene == EXIT_SCENE) 
	{
		PostQuitMessage(0);
	}

}
