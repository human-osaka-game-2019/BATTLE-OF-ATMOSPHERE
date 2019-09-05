#include "GameScene.h"

#include <stdlib.h>
#include <time.h>

#include "Main.h"
#include "Stage.h"
#include "Character.h"
#include "Collision.h"
#include "Create.h"

extern STAGE stage;
extern SPACEMAN spaceman;
extern COLLISION collision;
extern CREATE create;

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
	draw.LoadTexture("game_bg.png", GAME_BG);
	draw.LoadTexture("spaceman_1p.png", CHARCTER);
	draw.LoadTexture("spaceman_2p.png", CHARCTER_TWO);
	draw.LoadTexture("block.png", GAME_STAGE);
	draw.LoadTexture("RIGHT_BLAST.png", R_BLAST);
	draw.LoadTexture("LEFT_BLAST.png", L_BLAST);
	draw.LoadTexture("UP_BLAST.png", U_BLAST);
	draw.LoadTexture("DOWN_BLAST.png", D_BLAST);

	stage.InitBlock();

	spaceman.SpaceManInit(&spaceman.char_one);
	spaceman.SpaceManInit(&spaceman.char_two);

	srand((unsigned int)time(NULL));

	phase = PROCESSING;
}

VOID GAME::Process()
{
	//ゲーム背景の描画
	draw.Draw(0, 0, 0xffffffff, 0.0f, game_bg_tu, 1920, 1080, 1.0f, 0.25f, GAME_BG);

	fc_background++;
	//縦スクロールのアニメーション
	if (fc_background >= 2)
	{
		game_bg_tu += SCROLL_SPEED;
		fc_background = 0;
		if (game_bg_tu <= -1.0f)
		{
			game_bg_tu = 0.0f;
		}
	}


	if (spaceman.char_one.create == TRUE)
	{
		fc_cereate_one--;

		if (fc_cereate_one == 0)
		{
			spaceman.char_one.create = FALSE;
			for (INT i = 0; i < CREATE_BLOCK_QUANITITY - 3; i++)
			{
				stage.create_block[i].x = -10000;
				stage.create_block[i].y = -10000;
			}
		}
	}

	if (spaceman.char_two.create == TRUE)
	{
		fc_cereate_two--;

		if (fc_cereate_two == 0)
		{
			spaceman.char_two.create = FALSE;
			for (INT i = 3; i < CREATE_BLOCK_QUANITITY; i++)
			{
				stage.create_block[i].x = -10000;
				stage.create_block[i].y = -10000;
			}
		}
	}



	//ブロックをスクロールに合わせて落とす処理
	for (INT i = 0; i < BLOCK_QUANTITY; i++)
	{
		stage.ScrollBlock(&stage.block[i]);
	}
	for (INT i = 0; i < CREATE_BLOCK_QUANITITY; i++)
	{
		stage.ScrollBlock(&stage.create_block[i]);
	}

	//重力
	spaceman.SpaceManMove(&spaceman.char_one,&spaceman.char_two,&spaceman.blast_one);
	spaceman.SpaceManMove(&spaceman.char_two,&spaceman.char_one,&spaceman.blast_two);

	//ブロックとの当たり判定
	for (INT i = 0; i < BLOCK_QUANTITY; i++)
	{
		collision.Hit_Block(stage.block[i], &spaceman.char_one);
		collision.Hit_Block(stage.block[i], &spaceman.char_two);
	}

	//クリエイトブロックとの当たり判定
	for (INT i = 0; i < CREATE_BLOCK_QUANITITY; i++) 
	{
		collision.Hit_Block(stage.create_block[i], &spaceman.char_one);
		collision.Hit_Block(stage.create_block[i], &spaceman.char_two);
	}

	//ウィンドウとの
	if (spaceman.char_one.y < -(BLOCK_SIZE * 3))
	{
		spaceman.char_one.m_gravity = 0;
		spaceman.char_one.y = -(BLOCK_SIZE * 3);
	}
	if (spaceman.char_two.y < -(BLOCK_SIZE * 3))
	{
		spaceman.char_two.m_gravity = 0;

		spaceman.char_two.y = -(BLOCK_SIZE * 3);
	}

	if (spaceman.char_one.x < -(BLOCK_SIZE * 3))
	{
		spaceman.char_one.x = -(BLOCK_SIZE * 3);
	}

	for (INT i = 0; i < BLOCK_X_MAX; i++)
	{
		stage.m_is_stage[i] = FALSE;
	}

	//ブロックを上に移動する処理
	for (INT i = 0; i < BLOCK_QUANTITY; i++)
	{
		stage.MakeStage(&stage.block[i]);
	}
	//charとcharの当たり判定
	collision.Hit_Char(&spaceman.char_one, &spaceman.char_two);
	collision.Hit_Char(&spaceman.char_two, &spaceman.char_one);

	//クリエイトを使った時の座標移動
	if ((directx.KeyState[DIK_LSHIFT] == directx.PRESS) && (spaceman.char_one.create == false))
	{
		for (INT i = 0; i < CREATE_BLOCK_QUANITITY - 3; i++) {
			create.MakeBlock_Change(&spaceman.char_one, &stage.create_block[i], i);
			fc_cereate_one = 5 * 60;
		}
	}
	if ((directx.KeyState[DIK_RSHIFT] == directx.PRESS) && (spaceman.char_two.create == false))
	{
		for (INT i = 3; i < CREATE_BLOCK_QUANITITY; i++) {
			create.MakeBlock_Change(&spaceman.char_two, &stage.create_block[i], i - 3);
			fc_cereate_two = 5 * 60;

		}
	}

	//ブロックの描画
	for (INT i = 0; i < BLOCK_QUANTITY; i++)
	{
		stage.DrawBlock(stage.block[i]);
	}
	//クリエイトブロックの描画
	for (INT i = 0; i < CREATE_BLOCK_QUANITITY; i++)
	{
		stage.DrawBlock(stage.create_block[i]);
	}

	//自機の描画1p
	draw.Draw(spaceman.char_one.x, spaceman.char_one.y, 0xffffffff, spaceman.char_one.tu, spaceman.char_one.tv, spaceman.char_one.width, spaceman.char_one.height, 1.0f, 1.0f, CHARCTER);
	//自機の描画2p
	draw.Draw(spaceman.char_two.x, spaceman.char_two.y, 0xffffffff, spaceman.char_two.tu, spaceman.char_two.tv, spaceman.char_two.width, spaceman.char_two.height, 1.0f, 1.0f, CHARCTER_TWO);


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
