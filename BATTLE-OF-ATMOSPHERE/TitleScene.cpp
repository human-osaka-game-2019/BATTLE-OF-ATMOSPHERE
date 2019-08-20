#include "../BATTLE-OF-ATMOSPHERE/TitleScene.h"
#include"../BATTLE-OF-ATMOSPHERE/MapChip.h"

//タイトルのフェーズの宣言
TITLE::SCENE_PHASE phase = TITLE::LOAD;
//
//MapchipLoading Mp;
//DrawMap map;

//タイトルのフェーズの移動
void TITLE::Title_Scene() {

	switch (phase) {
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
void TITLE::Loading() {

	phase = PROCESSING;

}

//タイトルの描画処理
void TITLE::Process() {

	//エンターでゲームへ
	if (directx.KeyState[DIK_RETURN] == directx.PRESS) {
		phase = RELEASES;

	}
}

//タイトルのテクスチャの解放
void TITLE::Release() {

	for (int i = 0; i < TEX_MAX; i++) {
		if (directx.pTexture[i] != nullptr) {
			directx.pTexture[i]->Release();
			directx.pTexture[i] = nullptr;
		}
	}

		scene = GAME_SCENE;

}
