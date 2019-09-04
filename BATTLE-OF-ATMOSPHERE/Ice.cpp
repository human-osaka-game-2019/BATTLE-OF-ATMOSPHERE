#include "Ice.h"




VOID ICE::Init_Ice(ITEM_* item)
{
	item->x = -10000;
	item->y = -10000;
	item->width = 96.f;
	item->height = 96.f;
	item->tu;
	item->tv;
}

VOID ICE::ShotIce_Change(CHAR_* char_, ITEM_* item)
{
	switch (char_->m_direction)
	{
	case RIGHT:

		Right_ShotIce(char_, item);

		break;

	case LEFT:

		Left_ShotIce(char_, item);

		break;

	case UP:

		Up_ShotIce(char_, item);

		break;

	case DOWN:

		Down_ShotIce(char_, item);

		break;

	}
}

VOID ICE::Right_ShotIce(CHAR_* char_, ITEM_* item)
{
	item->x = char_->x + char_->width;
	item->y = char_->y + char_->height / 2 - item->height / 2;
}


VOID ICE::Left_ShotIce(CHAR_* char_, ITEM_* item)
{
	item->x = char_->x - item->width;
	item->y = char_->y + char_->height / 2 - item->height / 2;
}


VOID ICE::Up_ShotIce(CHAR_* char_, ITEM_* item)
{




}


VOID ICE::Down_ShotIce(CHAR_* char_, ITEM_* item)
{




}


