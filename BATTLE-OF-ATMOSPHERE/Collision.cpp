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
			else//左に行く
				if (movement_x > 0)
				{
					char_->x = block.x + block.width;
				}
		}
	}
}



VOID COLLISION::Hit_Char(CHAR_* char_one_, CHAR_* char_two_)
{
	if ((char_one_->x + char_one_->width > char_two_->x) && (char_one_->x < char_two_->x + char_two_->width) && (char_one_->y + char_one_->height > char_two_->y) && (char_one_->y < char_two_->y + char_two_->height)) {

		if (char_one_->m_action != NO_JUMP)
		{
			char_one_->y = char_two_->y - char_two_->height;
		}
	}
}

VOID COLLISION::Hit_Item(CHAR_* char_, ITEM_* item)
{
	if ((char_->x + char_->width > item->x) && (char_->x < item->x + item->width) && (char_->y + char_->height > item->y) && (char_->y < item->y + item->height))
	{









	}



}