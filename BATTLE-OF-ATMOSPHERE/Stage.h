#ifndef STAGE_H_
#define STAGE_H_

#include <Windows.h>

//ブロックの大きさ
#define BLOCK_SIZE 96.f
//ブロックの個数
#define BLOCK_QUANTITY 20
//クリエイトブロックの個数
#define CREATE_BLOCK_QUANITITY 6
//スクロールのスピード
#define SCROLL_SPEED  -0.001f
//ブロックのスクロールするスピード
#define SCROLL_SPEED_BLOCK 1.0f

typedef struct {
	float x, y, width, height, tu, tv;
}BLOCK;

class STAGE {
public:





	VOID InitStageBlock();

	VOID InitBlock();

	VOID MakeStage(BLOCK* block);

	VOID ScrollBlock(BLOCK* block);

	VOID FallBlock();

	VOID DrawBlock(BLOCK block);

	BLOCK block[BLOCK_QUANTITY];

	BLOCK create_block[CREATE_BLOCK_QUANITITY];

};

#endif
