#include "../BATTLE-OF-ATMOSPHERE/GameScene.h"
#include <stdlib.h>
#include <time.h>

DrawMap map;

Game::SCENE_PAHSE Phase = Game::LOAD;


//ゲームのフェーズの移動
void Game::Game_Scene() {

	switch (Phase) {
	case LOAD:
		Loading();
		break;
	case PROCESSING:
		Process();
		break;
	case RELEASES:
		Release();
		Phase = LOAD;
		break;
	}
}

//ゲームのテクスチャの読み込み
void Game::Loading() {

	
}

void Game::Process() {
	//リリースのフェーズへ
	if (directx.KeyState[DIK_RETURN] == directx.PRESS) {
		Phase = RELEASES;
	}

}

//ゲームのテクスチャの解放
void Game::Release() {

	//テクスチャの開放
	for (int i = 0; i < TEX_MAX; i++) {
		if (directx.pTexture[i] != nullptr) {
			directx.pTexture[i]->Release();
			directx.pTexture[i] = nullptr;
		}
	}
	//リザルトシーンへ
	scene = RESULT;
}
