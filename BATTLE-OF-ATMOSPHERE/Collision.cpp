#include "Collision.h"

extern SPACEMAN spaceman;

INT Gravity;
INT Jump = 0;

VOID COLLISION::Hit_Block(BLOCK block, CHAR_* char_)
{
	if (char_->m_action == NO_JUMP)
	{
		char_->m_action = FALL;
	}
	if (char_->vec_y == 0 && char_->vec_x == 0 && char_->m_action == FALL)
	{
		char_->m_action = NO_JUMP;
	}
	Hit_Move(block, char_, char_->vec_x, 0);
	Hit_Move(block, char_, 0, char_->vec_y);
}

VOID COLLISION::HitWindow(CHAR_* char_)
{
	if (char_->y < -(BLOCK_SIZE * 2))
	{
		char_->m_gravity = 0;
		char_->y = -(BLOCK_SIZE * 2);
	}

	if (char_->x < -(BLOCK_SIZE * 2))
	{
		char_->x = -(BLOCK_SIZE * 2);
	}

	if (char_->x > WINDOW_WIDTH +(BLOCK_SIZE * 2))
	{
		char_->x = WINDOW_WIDTH +(BLOCK_SIZE * 2);
	}
}

VOID COLLISION::Hit_Move(BLOCK block, CHAR_* char_, FLOAT movement_x, FLOAT movement_y)
{

	if ((block.x < char_->x + char_->width) && (char_->x < block.x + block.width) && (block.y < char_->y + char_->height) && (char_->y < block.y + block.height))
	{
		if ((char_->save_y + char_->height <= block.y) || (char_->save_y >= block.y + block.height)) {
			if (movement_y < 0)
			{
				char_->y = block.y - char_->height;
				char_->m_action = NO_JUMP;
				char_->m_gravity = 0;
				char_->m_is_call = FALSE;
			}
			else if (movement_y > 0)
			{
				char_->y = block.y + block.height;
				char_->m_gravity = 0;
			}
		}
		else
			//if(char_->save_x > block.x + block.width || char_->save_x + char_->width > block.x)
		{
			if (movement_x < 0)
			{
				char_->x = block.x - char_->width;
			}
			else if (movement_x > 0)
			{
				char_->x = block.x + block.width;
			}
		}
	}
}



VOID COLLISION::Hit_Char(CHAR_* char_one_, CHAR_* char_two_)
{
		if ((char_one_->x + char_one_->width > char_two_->x) && (char_one_->x < char_two_->x + char_two_->width) && (char_one_->y + char_one_->height > char_two_->y) && (char_one_->y < char_two_->y + char_two_->height)) {

			///////y軸
			if (char_one_->save_y + char_one_->height <= char_two_->save_y || char_two_->save_y + char_two_->height <= char_one_->save_y) {
				if (char_one_->save_y + char_one_->height <= char_two_->save_y)
				{
					char_one_->y = char_two_->y - char_one_->height;
					char_one_->m_gravity = 0;
					char_one_->m_action = NO_JUMP;
				}
				if (char_two_->save_y + char_two_->height <= char_one_->save_y)
				{
					char_two_->y = char_one_->y - char_two_->height;
					char_two_->m_gravity = 0;
					char_two_->m_action = NO_JUMP;
				}
			}
			else
			{
				///////x軸
				//１pが右から左へ
				if (char_one_->vec_x < 0 && char_two_->vec_x == 0)
				{
					char_two_->x = char_one_->x + char_one_->width;
				}
				//１pが左から右へ
				if (char_one_->vec_x > 0 && char_two_->vec_x == 0)
				{
					char_two_->x = char_one_->x - char_two_->width;
				}
				//２pが右から左へ
				if (char_two_->vec_x < 0 && char_one_->vec_x == 0)
				{
					char_one_->x = char_two_->x + char_two_->width;
				}
				//２pが左から右へ
				if (char_two_->vec_x > 0 && char_one_->vec_x == 0)
				{
					char_one_->x = char_two_->x - char_one_->width;
				}
				//１p左で両方動いているとき
				if (char_two_->vec_x * -1 == char_one_->vec_x && char_one_->vec_x <= 0)
				{
					FLOAT overlapped_half = char_one_->vec_x * -1 + char_two_->vec_x / 2;
					char_one_->x -= overlapped_half;
					char_two_->x += overlapped_half;
				}
				//２p左で両方動いているとき
				if (char_two_->vec_x * -1 == char_one_->vec_x && char_two_->vec_x <= 0)
				{
					FLOAT overlapped_half = char_one_->vec_x * -1 + char_two_->vec_x / 2;
					char_one_->x -= overlapped_half;
					char_two_->x += overlapped_half;
				}
			}
		}
}

VOID COLLISION::HitBlockItem(BLOCK block, ITEMSTATE* item_state)
{
	if ((block.x < item_state->x + item_state->width && block.y < item_state->y + item_state->height)
		&& (block.x + block.width > item_state->x && block.y + block.width > item_state->y))
	{
		item_state->item_gravity = 0;
		item_state->y = block.y - item_state->height;
	}
	else if ((block.x == item_state->x + item_state->width && block.y == item_state->y + item_state->height)
		&& (block.x + block.width == item_state->x && block.y + block.width == item_state->y))
	{
		item_state->item_gravity = 0;
		item_state->y += item_state->height;
	}
};
