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


}

VOID GAME::Process() 
{
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
