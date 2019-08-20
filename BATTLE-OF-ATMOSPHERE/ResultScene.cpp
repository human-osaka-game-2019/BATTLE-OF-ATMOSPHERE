#include "../BATTLE-OF-ATMOSPHERE/ResultScene.h"

//リザルトのフェーズの移動
void RESULT::Result_Scene() {

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

//リザルトのテクスチャの読み込み
void RESULT::Loading() {

	phase = PROCESSING;
}

//リザルトの描画処理
void RESULT::Process() {

	//エンターでタイトルへ
	if (directx.KeyState[DIK_RETURN] == directx.PRESS) {
		phase = RELEASES;
	}
}


//リザルトのテクスチャの解放
void RESULT::Release() {

	for (int i = 0; i < TEX_MAX; i++) {
		if (directx.pTexture[i] != nullptr) {
			directx.pTexture[i]->Release();
			directx.pTexture[i] = nullptr;
		}
	}
	phase = LOAD;
	scene = TITLE_SCENE;
}
