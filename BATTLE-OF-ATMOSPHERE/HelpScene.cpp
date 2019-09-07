#include "HelpScene.h"
#include <time.h>
//リザルトのフェーズの移動
VOID HELP::Help_Scene()
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
VOID HELP::Loading()
{
	draw.LoadTexture("Help_1.png", HELP_BG);
	draw.LoadTexture("Help_2.png", HELP_BG2);
	phase = PROCESSING;
}
//リザルトの描画処理
VOID HELP::Process()
{
	draw.Draw(0, 0, 0xffffffff, 0.0f, 0.0f, 1920, 1020, 1.0f, 1.0f, HELP_BG);
	draw.Draw(m_pos_x, m_pos_y, 0xffffffff, 0.0f, 0.0f, 1920, 1020, 1.0f, 1.0f, HELP_BG2);
	//エンターでタイトルへ
	if (m_pos_y >= 825)
	{
		m_pos_y = 825;
	}
	draw.Draw(m_pos_x, m_pos_y, 0xffffffff, 0.0f, 0.0f, 1920, 1020, 1.0f, 1.0f, HELP_BG);
	if (directx.KeyState[DIK_RIGHT] <= directx.ON)
	{
		m_pos_x += m_スクロール_speed;
	}
	draw.Draw(m_pos_x, m_pos_y, 0xffffffff, 0.0f, 0.0f, 1920, 1020, 1.0f, 1.0f, HELP_BG2);
	if (directx.KeyState[DIK_LEFT] <= directx.ON)
	{
		m_pos_x -= m_スクロール_speed;
	}
	if (directx.KeyState[DIK_RETURN] == directx.PRESS)
	{
		phase = RELEASES;
	}
}
//リザルトのテクスチャの解放
VOID HELP::Release()
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