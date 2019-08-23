#include"../BATTLE-OF-ATMOSPHERE/Character.h"
#include <time.h>

VOID SPACEMAN1P::SpaceManJump()
{

	SPACEMAN1P::m_pos_y -= SPACEMAN1P::jump_budget;
	SPACEMAN1P::jump_budget -= SPACEMAN1P::m_gravity;
}

VOID SPACEMAN1P::SpaceManMove()
{

	if (directx.KeyState[DIK_D] == directx.ON)
	{
		SPACEMAN1P::m_pos_x += SPACEMAN1P::m_spaceman_speed;

	}

	if (directx.KeyState[DIK_A] == directx.ON)
	{
		SPACEMAN1P::m_pos_x -= SPACEMAN1P::m_spaceman_speed;

	}

	if (directx.KeyState[DIK_W] == directx.PRESS)
	{
		SPACEMAN1P::m_coordinate_storing = SPACEMAN1P::m_pos_y;
		SPACEMAN1P::m_gravity = 0.25;
		SPACEMAN1P::m_is_jump = true;
	}

	if (directx.KeyState[DIK_S] == directx.ON)
	{
		SPACEMAN1P::m_pos_y += SPACEMAN1P::m_spaceman_speed;
	}

	if (SPACEMAN1P::m_is_jump == true)
	{
		SpaceManJump();
	}
	else
	{
		SPACEMAN1P::m_pos_y += SPACEMAN1P::m_gravity;
		SPACEMAN1P::m_gravity += 0.25;
	}

	if (SPACEMAN1P::m_pos_y >= 825)
	{
		SPACEMAN1P::jump_budget = 15.0F;
		SPACEMAN1P::m_is_jump = false;
	}


}