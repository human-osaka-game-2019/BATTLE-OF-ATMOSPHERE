#include "GameScene.h"

#include <stdlib.h>
#include <time.h>

#include "Main.h"
#include "Stage.h"
#include "Character.h"
#include "Collision.h"
#include "Create.h"
#include "Ice.h"
#include "Jet.h"

extern STAGE stage;
extern SPACEMAN spaceman;
extern COLLISION collision;
extern CREATE create;
extern JET jet;
extern ICE ice;


WINNER winner;

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
	draw.LoadTexture("spaceman_one.png", CHARCTER);
	draw.LoadTexture("spaceman_two.png", CHARCTER_TWO);
	draw.LoadTexture("block.png", GAME_STAGE);
	draw.LoadTexture("RIGHT_BLAST.png", R_BLAST);
	draw.LoadTexture("LEFT_BLAST.png", L_BLAST);
	draw.LoadTexture("UP_BLAST.png", U_BLAST);
	draw.LoadTexture("DOWN_BLAST.png", D_BLAST);
	draw.LoadTexture("ice_ball.png", ICE_BALL);
	draw.LoadTexture("slot.png", SLOT);

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

	fc_ice_time_one++;
	fc_ice_time_two++;

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

	jet.UseJet(&spaceman.char_one);
	jet.UseJet(&spaceman.char_two);

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

	if (fc_ice_time_one >= 60 * 5) {
		spaceman.char_one.is_ice = FALSE;
	}
	if (fc_ice_time_two >= 60 * 5) {
		spaceman.char_two.is_ice = FALSE;
	}

	if (spaceman.char_one.is_ice_hit == FALSE) {
		if ((directx.KeyState[DIK_LALT] == directx.PRESS) && (spaceman.char_one.is_ice == FALSE))
		{
			ice.UseIce(&spaceman.char_one, &ice.ice_shot_one);
			fc_ice_time_one = 0;
		}
	}
	if (spaceman.char_two.is_ice_hit == FALSE) {
		if ((directx.KeyState[DIK_RALT] == directx.PRESS) && (spaceman.char_two.is_ice == FALSE))
		{
			ice.UseIce(&spaceman.char_two, &ice.ice_shot_two);
			fc_ice_time_two = 0;
		}
	}
	if (ice.ice_shot_one.is_ice_move == TRUE)
	{
		if (spaceman.char_one.m_direction == RIGHT) {
			draw.Draw(ice.ice_shot_one.x, ice.ice_shot_one.y, 0xffffffff, 0.0f, 0.0f, ice.ice_shot_one.width, ice.ice_shot_one.height, 1.0f, 1.0f, ICE_BALL);
			ice.MoveIce(&spaceman.char_one, &ice.ice_shot_one);
		}
		else 
		{
			draw.Draw(ice.ice_shot_one.x, ice.ice_shot_one.y, 0xffffffff, 0.0f, 0.0f, ice.ice_shot_one.width, ice.ice_shot_one.height, 1.0f, 1.0f, ICE_BALL,180);
			ice.MoveIce(&spaceman.char_one, &ice.ice_shot_one);
		}
	}
	if (ice.ice_shot_two.is_ice_move == TRUE)
	{
		if (spaceman.char_two.m_direction == RIGHT) {
			draw.Draw(ice.ice_shot_two.x, ice.ice_shot_two.y, 0xffffffff, 0.0f, 0.0f, ice.ice_shot_two.width, ice.ice_shot_two.height, 1.0f, 1.0f, ICE_BALL);
			ice.MoveIce(&spaceman.char_two, &ice.ice_shot_two);
		}
		else
		{
			draw.Draw(ice.ice_shot_two.x, ice.ice_shot_two.y, 0xffffffff, 0.0f, 0.0f, ice.ice_shot_two.width, ice.ice_shot_two.height, 1.0f, 1.0f, ICE_BALL,180);
			ice.MoveIce(&spaceman.char_two, &ice.ice_shot_two);
		}
	}
	for (INT i = 0; i < BLOCK_QUANTITY; i++)
	{
		if (ice.IceHitBlockCheck(stage.block[i], ice.ice_shot_one) == TRUE)
		{
			//spaceman.char_one.is_ice = FALSE;
			ice.ice_shot_one.is_ice_move = FALSE;
		}
		if (ice.IceHitBlockCheck(stage.block[i], ice.ice_shot_two) == TRUE)
		{
			//spaceman.char_one.is_ice = FALSE;
			ice.ice_shot_two.is_ice_move = FALSE;
		}
	}



	if (ice.IceHitCharCheck(spaceman.char_two, ice.ice_shot_one) == TRUE)
	{
		//spaceman.char_one.is_ice = FALSE;
		ice.HitIceChar(&spaceman.char_two, &ice.ice_shot_one);
	}
	if (ice.IceHitCharCheck(spaceman.char_one, ice.ice_shot_two) == TRUE)
	{
		//spaceman.char_two.is_ice = FALSE;
		ice.HitIceChar(&spaceman.char_one, &ice.ice_shot_two);
	}

	//ウィンドウとの
	collision.HitWindow(&spaceman.char_one);
	collision.HitWindow(&spaceman.char_two);

	for (INT i = 0; i < BLOCK_X_MAX; i++)
	{
		stage.m_is_stage[i] = FALSE;
	}

	//ブロックを上に移動する処理
	for (INT i = 0; i < BLOCK_QUANTITY; i++)
	{
		if (stage.block[i].y >= BLOCK_SIZE * 2)
		{
			for (INT j = 0; j < BLOCK_QUANTITY; j++)
			{
				stage.MakeStage(&stage.block[j]);


			}

			break;
		}

	}

	if (stage.fc_item_pop <= 0)
	{
		for (INT i = 0; i < 10; i++)
		{
			if (spaceman.item_state[i].is_pop == FALSE)
			{
				stage.PopItem(&spaceman.item_state[i]);
				stage.fc_item_pop = 6 * 60;
				break;
			}

		}
	}
	else
	{
		stage.fc_item_pop--;
	}
	//charとcharの当たり判定
	collision.Hit_Char(&spaceman.char_one, &spaceman.char_two);
	collision.Hit_Char(&spaceman.char_two, &spaceman.char_one);

	if (spaceman.char_one.is_ice_hit == FALSE) {
		//クリエイトを使った時の座標移動
		if ((directx.KeyState[DIK_LSHIFT] == directx.PRESS) && (spaceman.char_one.create == false))
		{
			for (INT i = 0; i < CREATE_BLOCK_QUANITITY - 3; i++) {
				create.MakeBlock_Change(&spaceman.char_one, &stage.create_block[i], i);
				fc_cereate_one = 5 * 60;
			}
		}
	}
	if (spaceman.char_two.is_ice_hit == FALSE) {
		if ((directx.KeyState[DIK_RSHIFT] == directx.PRESS) && (spaceman.char_two.create == false))
		{
			for (INT i = 3; i < CREATE_BLOCK_QUANITITY; i++) {
				create.MakeBlock_Change(&spaceman.char_two, &stage.create_block[i], i - 3);
				fc_cereate_two = 5 * 60;

			}
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

	for (INT i = 0; i < 10; i++)
	{
		if (spaceman.item_state[i].is_pop == TRUE)
		{
			for (INT j = 0; j < BLOCK_QUANTITY; j++) 
			{
				collision.HitBlockItem(stage.block[j], &spaceman.item_state[i]);
			}
			stage.ItemReset(&spaceman.item_state[i]);
			spaceman.item_state[i].y += spaceman.item_state[i].item_gravity;
			draw.Draw(spaceman.item_state[i].x, spaceman.item_state[i].y, 0xffffffff, 0, 0, spaceman.item_state[i].width, spaceman.item_state[i].height, 1, 1, ICE_BALL);
			spaceman.item_state[i].item_gravity += 0.1f;
		}
	}

	//自機の描画1p
	draw.Draw(spaceman.char_one.x, spaceman.char_one.y, 0xffffffff, spaceman.char_one.tu, spaceman.char_one.tv, spaceman.char_one.width, spaceman.char_one.height, 0.25f, 0.03125f, CHARCTER);
	//自機の描画2p
	draw.Draw(spaceman.char_two.x, spaceman.char_two.y, 0xffffffff, spaceman.char_two.tu, spaceman.char_two.tv, spaceman.char_two.width, spaceman.char_two.height, 0.25f,0.03125f , CHARCTER_TWO);

	draw.Draw(0, 0, 0xffffffff, 0.0f, 0.0f, 128, 128, 1.0f, 1.0f, SLOT);
	draw.Draw(WINDOW_WIDTH - 128, 0, 0xffffffff, 0.0f, 0.0f, 128, 128, 1.0f, 1.0f, SLOT);

	//どちらが勝利したか判断している
	if (spaceman.char_one.y > WINDOW_HEIGHT + (BLOCK_SIZE * 3))
	{
		winner.is_two_win = TRUE;
		phase = RELEASES;
	}
	else if (spaceman.char_two.y > WINDOW_HEIGHT + (BLOCK_SIZE * 3))
	{
		winner.is_one_win = TRUE;
		phase = RELEASES;
	}

}

//ゲームのテクスチャの解放
VOID GAME::Release() {

	for (INT i = 0; i < 10; i++)
	{
		spaceman.item_state[i].is_pop = FALSE;
	}
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
