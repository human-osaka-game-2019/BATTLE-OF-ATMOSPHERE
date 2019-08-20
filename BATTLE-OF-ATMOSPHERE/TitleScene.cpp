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
	phase = PROCESSING;

}

//タイトルの描画処理
VOID TITLE::Process() 
{
	draw.Draw(0, 0, 0xffffffff, 0.0f, 0.0f, 1920, 1080, 1.0f, 1.0f, TITLE_BG);
	//エンターでゲームへ
	if (directx.KeyState[DIK_RETURN] == directx.PRESS) 
	{
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

		scene = GAME_SCENE;

}
