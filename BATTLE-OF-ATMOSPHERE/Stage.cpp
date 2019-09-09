#include "Stage.h"

#include "MapChip.h"

//DRAWMAP drawmap;
//DRAW draw;

VOID STAGE::SlotChange(CHAR_ char_one, CHAR_ char_two)
{
	
}

VOID STAGE::PopItem(ITEMSTATE* item_state)
{
	INT item_x_pos;
	INT item_y_pos;
	item_state->is_pop = TRUE;
	item_x_pos= rand() % (BLOCK_X_MAX - 1);
	item_y_pos = rand() % (BLOCK_Y_MAX - 5);
	item_state->x = item_x_pos * BLOCK_SIZE;
	item_state->y = item_y_pos * BLOCK_SIZE;
}

VOID STAGE::InitStageBlock()
{
	for (INT i = 0; i < 8; i++)
	{
		block[i].x = (6 + i) * BLOCK_SIZE;
		block[i].y = -4 * BLOCK_SIZE;
	}

	for (INT i = 0; i < 10; i++) 
	{
		block[i + 8].x = (5 + i) * BLOCK_SIZE;
		block[i + 8].y = 2 * BLOCK_SIZE;
	}
	for (INT i = 0; i < 14; i++) 
	{
		block[i + 19].x = (3 + i) * BLOCK_SIZE;
		block[i + 19].y = 8 * BLOCK_SIZE;
	}

	for (INT i = 0; i < 5; i++)
	{
		block[i + 33].x = i * BLOCK_SIZE;
		block[i + 33].y = -10 * BLOCK_SIZE;
	}

	for (INT i = 0; i < 5; i++)
	{
		block[i + 38].x = (15 + i) * BLOCK_SIZE;
		block[i + 38].y = -10 * BLOCK_SIZE;
	}
}

VOID STAGE::ItemReset(ITEMSTATE* item_state)
{
	if (item_state->y > WINDOW_HEIGHT+(BLOCK_SIZE * 2))
	{
		item_state->item_gravity = 0.1f;
		item_state->is_pop = FALSE;
	}

}

VOID STAGE::InitBlock()
{
	//ブロックの初期値
	for (INT i = 0; i < BLOCK_QUANTITY; i++)
	{
		block[i].x = -10000.f;//初期値適当
		block[i].y = -10000.f;//初期値適当
		block[i].tu = 0.0f;
		block[i].tv = 0.0f;
		block[i].width = BLOCK_SIZE;
		block[i].height = BLOCK_SIZE;
	}
	//クリエイトブロックの初期値
	for (INT i = 0; i < CREATE_BLOCK_QUANITITY; i++)
	{
		create_block[i].x = -10000.f;//初期値適当
		create_block[i].y = -10000.f;//初期値適当
		create_block[i].tu = 96.f / 192.f;
		create_block[i].tv = 0.0f;
		create_block[i].width = BLOCK_SIZE;
		create_block[i].height = BLOCK_SIZE;
	}

	InitStageBlock();
}

VOID STAGE::MakeStage(BLOCK* block)
{
	if (block->y >= WINDOW_HEIGHT + (BLOCK_SIZE * 8))
	{
		do
		{
			block->x_num = rand() % (BLOCK_X_MAX - 1);

		} while (m_is_stage[block->x_num] == TRUE);

		m_is_stage[block->x_num] = TRUE;
		block->x = (block->x_num) * BLOCK_SIZE;
		block->y = -(BLOCK_SIZE * 4);
	}
}


VOID STAGE::ScrollBlock(BLOCK* block)
{
	block->y += SCROLL_SPEED_BLOCK;
}

VOID STAGE::FallBlock()
{




}

VOID STAGE::DrawBlock(BLOCK block)
{
	draw.Draw(block.x, block.y, 0xffffffff, block.tu, block.tv, block.width, block.height, 96.f / 192.f, 96.f / 192.f, GAME_STAGE, 0);
}

