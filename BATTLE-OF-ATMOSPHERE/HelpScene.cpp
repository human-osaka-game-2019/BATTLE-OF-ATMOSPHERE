#include "../BATTLE-OF-ATMOSPHERE/HelpScene.h"

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
	draw.LoadTexture("help.png", HELP_BG);
	phase = PROCESSING;
}

//リザルトの描画処理
VOID HELP::Process() 
{
	draw.Draw(0, 0, 0xffffffff, 0.0f, 0.0f, 1920, 1080, 1.0f, 1.0f, HELP_BG);
	//エンターでタイトルへ
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
