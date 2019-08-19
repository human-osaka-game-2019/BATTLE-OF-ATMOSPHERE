#include "../BATTLE-OF-ATMOSPHERE/TitleScene.h"
#include"../BATTLE-OF-ATMOSPHERE/MapChip.h"

//タイトルのフェーズの宣言
Title::SCENE_PHASE Phase = Title::LOAD;
//
//MapchipLoading Mp;
//DrawMap map;

//タイトルのフェーズの移動
void Title::Title_Scene() {

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

//タイトルのテクスチャの読み込み
void Title::Loading() {

	Phase = PROCESSING;

}

//タイトルの描画処理
void Title::Process() {

	//エンターでゲームへ
	if (directx.KeyState[DIK_RETURN] == directx.PRESS) {
		Phase = RELEASES;

	}
}

//タイトルのテクスチャの解放
void Title::Release() {

	for (int i = 0; i < TEX_MAX; i++) {
		if (directx.pTexture[i] != nullptr) {
			directx.pTexture[i]->Release();
			directx.pTexture[i] = nullptr;
		}
	}

	if (nextscene == GAME) {
		scene = GAME;
	}
	if (nextscene == HELP) {
		scene = HELP;
	}
	if (nextscene == EXIT) {
		PostQuitMessage(0);
	}
}
