#include "../BATTLE-OF-ATMOSPHERE/ResultScene.h"

//リザルトのフェーズの移動
void Result::Result_Scene() {

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

//リザルトのテクスチャの読み込み
void Result::Loading() {

	Phase = PROCESSING;
}

//リザルトの描画処理
void Result::Process() {

	//エンターでタイトルへ
	if (directx.KeyState[DIK_RETURN] == directx.PRESS) {
		Phase = RELEASES;
	}
}


//リザルトのテクスチャの解放
void Result::Release() {

	for (int i = 0; i < TEX_MAX; i++) {
		if (directx.pTexture[i] != nullptr) {
			directx.pTexture[i]->Release();
			directx.pTexture[i] = nullptr;
		}
	}
	Phase = LOAD;
	scene = TITLE;
}
