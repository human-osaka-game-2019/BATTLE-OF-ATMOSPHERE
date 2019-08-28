#include "../BATTLE-OF-ATMOSPHERE/ResultScene.h"

//リザルトのフェーズの移動
VOID RESULT::Result_Scene() 
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

//リザルトのテクスチャの読み込み
VOID RESULT::Loading()
{
	draw.LoadTexture("result_bg.png", RESULT_BG);
	draw.LoadTexture("title_ui.png", TITLE_UI);
	phase = PROCESSING;
}

//リザルトの描画処理
VOID RESULT::Process()
{
	draw.Draw(0, 0, 0xffffffff, 0.0f, 0.0f, 1920, 1080, 1.0f, 1.0f, RESULT_BG);
	draw.Draw(100, 900, 0xffffffff, m_result_ui_tu_a, 0.5f, 370, 170, 0.5f, 0.25f, TITLE_UI);
	//draw.Draw(775, 900, 0xffffffff, result_ui_tu_b, 0.25f, 370, 170, 0.5f, 0.25f, TITLE_UI);
	draw.Draw(1450, 900, 0xffffffff, m_result_ui_tu_c, 0.0f, 370, 170, 0.5f, 0.25f, TITLE_UI);

	if (directx.KeyState[DIK_RIGHT] == directx.PRESS)
	{
		switch (Result_ID)
		{
			m_result_ui_tu_a = 0.0f;
			m_result_ui_tu_b = 0.0f;
			m_result_ui_tu_c = 0.0f;

		case select_ui_retry:
			Result_ID = select_ui_title;
			m_result_ui_tu_c = 0.5f;
			m_result_ui_tu_a -= 0.5f;
			break;
		default:
			break;
		}
	}
	if (directx.KeyState[DIK_LEFT] == directx.PRESS)
		switch (Result_ID)
		{
		case select_ui_title:
			Result_ID = select_ui_retry;
			m_result_ui_tu_a = 0.5f;
			m_result_ui_tu_c -= 0.5f;
			break;
		default:
			break;
		}
	if (directx.KeyState[DIK_RETURN] == directx.PRESS)

		switch (Result_ID)
		{
		case select_ui_title:
			scene = TITLE_SCENE;
			break;
		case select_ui_retry:
			scene = GAME_SCENE;
		default:
			break;
		}





	//エンターでタイトルへ
	if (directx.KeyState[DIK_RETURN] == directx.PRESS)
	{
		phase = RELEASES;
	}
}


//リザルトのテクスチャの解放
VOID RESULT::Release()
{

	for (INT i = 0; i < TEX_MAX; i++)
	{
		if (directx.pTexture[i] != nullptr)
		{
			directx.pTexture[i]->Release();
			directx.pTexture[i] = nullptr;
		}
	}
	phase = LOAD;
	scene = TITLE_SCENE;
}

