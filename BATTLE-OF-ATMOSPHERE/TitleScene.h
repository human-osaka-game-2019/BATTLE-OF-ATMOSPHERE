#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include "../BATTLE-OF-ATMOSPHERE/TitleScene.h"
#include "../BATTLE-OF-ATMOSPHERE/Main.h"

#define MAP_SIZE_WIDTH (28)		// MAPの横幅(値はチップ数)
#define MAP_SIZE_HEIGHT (31)	// MAPの縦幅(値はチップ数)
#define MAPCHIP_WIDTH (32)		// マップチップの横幅
#define MAPCHIP_HEIGHT (32)		// マップチップの縦幅
#define TEXTURE_WIDTH (256)     // 読み込んだテクスチャの横幅
#define TEXTURE_HEIGHT (256)    // 読み込んだテクスチャの縦幅
#define DRAW_WIDTH (16)         // 描画する横幅
#define DRAW_HEIGHT (16)        // 描画する縦幅

class Title {
public:

	void Title_Scene();

	enum SCENE_PHASE {
		LOAD,
		PROCESSING,
		RELEASES
	};

private:

	//プロトタイプ宣言
	void Loading();
	void Process();
	void Release();

	int flamecount_title_logo = 0;
	float title_logo_tu = 0.0f;
	float title_select_ui_tu_a = 0.5f;
	float title_select_ui_tu_b = 0.0f;
	float title_select_ui_tu_c = 0.0f;
	int flamecount_pacman = 0;

	float pacman_y = 795;
	float title_pacman_tu = 0.0f;

	// ゲームかヘルプか、１ｐか２ｐの勝利を見分ける変数
	SCENE nextscene = GAME;

	enum SelectUI_ID
	{
		select_ui_start,
		select_ui_help,
		select_ui_exit,
	};

	SelectUI_ID currentID;

};

#endif