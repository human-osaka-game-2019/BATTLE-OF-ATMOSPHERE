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

class TITLE 
{
public:

	VOID Title_Scene();

	enum SCENE_PHASE 
	{
		LOAD,
		PROCESSING,
		RELEASES
	};

private:

	//プロトタイプ宣言
	VOID Loading();
	VOID Process();
	VOID Release();

};

#endif