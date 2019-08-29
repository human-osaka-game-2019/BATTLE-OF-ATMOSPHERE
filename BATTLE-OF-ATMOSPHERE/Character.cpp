#include"../BATTLE-OF-ATMOSPHERE/Character.h"

VOID SPACEMAN1P::SpaceManRelease()
{
	// 仮の地面の座標(890)
	if (SPACEMAN1P::m_pos_y >= 890)
	{
		SPACEMAN1P::m_jump_power = SPACEMAN1P::m_max_jump_power;
		SPACEMAN1P::m_jump = NO_JAMP;
		SPACEMAN1P::m_is_call = FALSE;
	}
	else
	{
		SPACEMAN1P::m_plus_spaceman_speed = 0.0F;
		SPACEMAN1P::m_is_dash = FALSE;
	}
}

VOID SPACEMAN1P::SpaceManJumpSwitchChange(INT* jump)
{
	switch (*jump)
	{
	case NO_JAMP:
		*jump = ONE_JAMP;
		break;
	case ONE_JAMP:
		*jump = TWO_JAMP;
		break;
	}
}

VOID SPACEMAN1P::SpaceManSwitchJump(INT jump)
{
	switch (jump)
	{
	case NO_JAMP:

		// ジャンプしていないとき（落下など）自身に重力をかけている
		SPACEMAN1P::m_pos_y += SPACEMAN1P::m_gravity;
		SPACEMAN1P::m_gravity += SPACEMAN1P::m_max_gravity;
		break;

	case ONE_JAMP:

		SpaceManJump();
		SPACEMAN1P::m_plus_jump_power = 0.0F;

		break;

	case TWO_JAMP:

		if (SPACEMAN1P::m_is_call == FALSE)
		{
			SPACEMAN1P::m_jump_power = SPACEMAN1P::m_max_jump_power;
			SPACEMAN1P::m_is_call = TRUE;
		}

		SpaceManJump();

		break;
	}
}

VOID SPACEMAN1P::SpaceManJump()
{
	SPACEMAN1P::m_pos_y -= SPACEMAN1P::m_jump_power;
	SPACEMAN1P::m_jump_power -= SPACEMAN1P::m_gravity;
}

VOID SPACEMAN1P::SpaceManDash()
{
	if (SPACEMAN1P::m_is_dash == TRUE) {

		if ((directx.KeyState[DIK_D] == directx.ON &&
			directx.KeyState[DIK_G] == directx.ON) ||
			(directx.KeyState[DIK_A] == directx.ON &&
				directx.KeyState[DIK_G] == directx.ON))
		{

			SPACEMAN1P::m_plus_spaceman_speed += SPACEMAN1P::m_plus_dash_power;
			SPACEMAN1P::m_plus_jump_power += SPACEMAN1P::m_plus_dash_power;

			if (SPACEMAN1P::m_plus_spaceman_speed >= SPACEMAN1P::m_max_plus_spaceman_power)
			{
				SPACEMAN1P::m_plus_spaceman_speed = SPACEMAN1P::m_max_plus_spaceman_power;
				SPACEMAN1P::m_plus_jump_power = SPACEMAN1P::m_max_plus_spaceman_power;
			}
		}
		else if (directx.KeyState[DIK_G] == directx.OFF)
		{
			SPACEMAN1P::m_plus_spaceman_speed = 0.0F;
			SPACEMAN1P::m_plus_jump_power = 0.0F;
		}
	}
}

VOID SPACEMAN1P::SpaceManMove()
{
	SPACEMAN1P::SpaceManRelease();

	if (directx.KeyState[DIK_D] == directx.ON)
	{
		SPACEMAN1P::m_pos_x += (SPACEMAN1P::m_spaceman_speed + SPACEMAN1P::m_plus_spaceman_speed);
	}
	else if (directx.KeyState[DIK_A] == directx.ON)
	{
		SPACEMAN1P::m_pos_x -= (SPACEMAN1P::m_spaceman_speed + SPACEMAN1P::m_plus_spaceman_speed);
	}

	SPACEMAN1P::SpaceManDash();

	if (directx.KeyState[DIK_W] == directx.PRESS)
	{
		SPACEMAN1P::m_gravity = SPACEMAN1P::m_max_gravity;
		SPACEMAN1P::m_jump_power = (SPACEMAN1P::m_jump_power + SPACEMAN1P::m_plus_jump_power);

		SPACEMAN1P::SpaceManJumpSwitchChange(&m_jump);
	}

	if (directx.KeyState[DIK_S] == directx.ON)
	{
		SPACEMAN1P::m_pos_y += SPACEMAN1P::m_spaceman_speed;
		SPACEMAN1P::m_is_dash = FALSE;
	}
	else if (directx.KeyState[DIK_S] == directx.OFF)
	{
		SPACEMAN1P::m_is_dash = TRUE;
	}

	SPACEMAN1P::SpaceManSwitchJump(SPACEMAN1P::m_jump);

}
