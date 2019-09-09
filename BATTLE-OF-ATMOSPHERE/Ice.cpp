#include "Ice.h"
#include"Main.h"

VOID ICE::Init_Ice(ICE_SHOT* ice_shot)
{
	ice_shot->x = 100000;
	ice_shot->y = 100000;
	ice_shot->width = 96.0f;
	ice_shot->height = 96.0f;
}
VOID ICE::UseIce(CHAR_* char_, ICE_SHOT* ice_shot)
{
	ice_shot->is_ice_move = TRUE;
	ShotIce_Change(char_, ice_shot);
	ice_shot->ice_direction = char_->m_direction;
	char_->is_ice = TRUE;
}
VOID ICE::ShotIce_Change(CHAR_* char_, ICE_SHOT* ice_shot)
{
	switch (char_->m_direction)
	{
	case RIGHT:
		Right_ShotIce(char_, ice_shot);
		break;
	case LEFT:
		Left_ShotIce(char_, ice_shot);
		break;
	case UP:
		Up_ShotIce(char_, ice_shot);
		break;
	case DOWN:
		Down_ShotIce(char_, ice_shot);
		break;
	}
}
VOID ICE::MoveIce(CHAR_* char_, ICE_SHOT* ice_shot)
{
	EvaporatingIce(char_, ice_shot);
	switch (ice_shot->ice_direction)
	{
	case RIGHT:
		ice_shot->x += 10;
		ice_shot->y += SCROLL_SPEED_BLOCK;
		break;
	case LEFT:
		ice_shot->x -= 10;
		ice_shot->y += SCROLL_SPEED_BLOCK;
		break;
	case UP:
		ice_shot->y -= 10;
		ice_shot->y += SCROLL_SPEED_BLOCK;
		break;
	case DOWN:
		ice_shot->y += 10;
		ice_shot->y += SCROLL_SPEED_BLOCK;
		break;
	}
}
BOOL ICE::IceHitCharCheck(CHAR_ char_, ICE_SHOT ice_shot)
{
	if ((ice_shot.x < char_.x + char_.width && ice_shot.y < char_.y + char_.height) && (ice_shot.x + ice_shot.width > char_.x && ice_shot.y + ice_shot.height > char_.y))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
BOOL ICE::IceHitBlockCheck(BLOCK block, ICE_SHOT ice_shot)
{
	if ((ice_shot.x < block.x + block.width && ice_shot.y < block.y + block.height) && (ice_shot.x + ice_shot.width > block.x && ice_shot.y + ice_shot.height > block.y))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
VOID ICE::EvaporatingIce(CHAR_* char_, ICE_SHOT* ice_shot)
{
	if (ice_shot->x < 0 || ice_shot->x>1920 || ice_shot->y < 0 || ice_shot->y>1080)
	{
		ice_shot->is_ice_move = FALSE;
		char_->is_ice = FALSE;
		ice_shot->x = -10000000;
		ice_shot->y = -10000000;
	}

}
VOID ICE::HitIceChar(CHAR_* char_, ICE_SHOT* ice_shot)
{
	char_->is_ice_hit = TRUE;
	ice_shot->is_ice_move = FALSE;
	char_->fc_ice = 3 * 60;
	ice_shot->x = -10000000;
	ice_shot->y = -10000000;
}
VOID ICE::Right_ShotIce(CHAR_* char_, ICE_SHOT* ice_shot)
{
	ice_shot->x = char_->x + char_->width;
	ice_shot->y = char_->y + char_->height / 2 - ice_shot->height / 2;
}
VOID ICE::Left_ShotIce(CHAR_* char_, ICE_SHOT* ice_shot)
{
	ice_shot->x = char_->x - ice_shot->width;
	ice_shot->y = char_->y + char_->height / 2 - ice_shot->height / 2;
}
VOID ICE::Up_ShotIce(CHAR_* char_, ICE_SHOT* ice_shot)
{
	ice_shot->x = char_->x;
	ice_shot->y = char_->y - char_->height / 2;
}
VOID ICE::Down_ShotIce(CHAR_* char_, ICE_SHOT* ice_shot)
{
	ice_shot->x = char_->x;
	ice_shot->y = char_->y + char_->height;
}

