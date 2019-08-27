#ifndef STAGE_H_
#define STAGE_H_

#include "../BATTLE-OF-ATMOSPHERE/DirectX.h"
#include "../BATTLE-OF-ATMOSPHERE/Main.h"

//ブロックの大きさ
#define BLOCK_SIZE 100.f
//ブロックの個数
#define BLOCK_QUANTITY 100
//スクロールのスピード
#define SCROLL_SPEED  -0.001f
//ブロックのスクロールするスピード
#define SCROLL_SPEED_BLOCK 1.0f

class STAGE {
public:

	struct BLOCK {
		float x, y,tu,tv;
	};




	VOID InitStage();

	VOID MakeStage();

	VOID ScrollBlock(BLOCK* block);

	VOID FallBlock();

	VOID DrawBlock(BLOCK block);

	
	BLOCK block[BLOCK_QUANTITY];



};

#endif
