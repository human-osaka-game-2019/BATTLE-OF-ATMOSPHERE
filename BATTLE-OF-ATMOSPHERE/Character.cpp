#include"../BATTLE-OF-ATMOSPHERE/Character.h"

SPACEMANBASE::JUMP SPACEMANBASE::SpaceManJumpSwitchChange(JUMP jump)
{
	switch (jump)
	{
	case NO_JUMP:
		return ONE_JUMP;
	case ONE_JUMP:
		return TWO_JUMP;
	}
}

VOID SPACEMANONE::SpaceManRelease()
{
	// 仮の地面の座標(890)
	if (SPACEMANONE::m_pos_y >= 890)
	{
		SPACEMANONE::m_jump_power = SPACEMANONE::m_max_jump_power;
		SPACEMANONE::m_jump = NO_JUMP;
		SPACEMANONE::m_is_call = FALSE;
	}
	else
	{
		SPACEMANONE::m_plus_spaceman_speed = 0.0F;
		SPACEMANONE::m_is_dash = FALSE;
	}
}

VOID SPACEMANONE::SpaceManSwitchJump(JUMP jump)
{
	switch (jump)
	{
	case NO_JUMP:

		// ジャンプしていないとき（落下など）自身に重力をかけている
		SPACEMANONE::m_pos_y += SPACEMANONE::m_gravity;
		SPACEMANONE::m_gravity += SPACEMANONE::m_max_gravity;
		break;

	case ONE_JUMP:

		SpaceManJump();
		SPACEMANONE::m_plus_jump_power = 0.0F;

		break;

	case TWO_JUMP:

		if (SPACEMANONE::m_is_call == FALSE)
		{
			SPACEMANONE::m_jump_power = SPACEMANONE::m_max_jump_power;
			SPACEMANONE::m_is_call = TRUE;
		}

		SpaceManJump();

		break;
	}
}

VOID SPACEMANONE::SpaceManJump()
{
	SPACEMANONE::m_pos_y -= SPACEMANONE::m_jump_power;
	SPACEMANONE::m_jump_power -= SPACEMANONE::m_gravity;
}

VOID SPACEMANONE::SpaceManDash()
{
	if (SPACEMANONE::m_is_dash == TRUE) {

		if ((directx.KeyState[DIK_D] == directx.ON &&
			directx.KeyState[DIK_G] == directx.ON) ||
			(directx.KeyState[DIK_A] == directx.ON &&
				directx.KeyState[DIK_G] == directx.ON))
		{

			SPACEMANONE::m_plus_spaceman_speed += SPACEMANONE::m_plus_dash_power;
			SPACEMANONE::m_plus_jump_power += SPACEMANONE::m_plus_dash_power;

			if (SPACEMANONE::m_plus_spaceman_speed >= SPACEMANONE::m_max_plus_spaceman_power)
			{
				SPACEMANONE::m_plus_spaceman_speed = SPACEMANONE::m_max_plus_spaceman_power;
				SPACEMANONE::m_plus_jump_power = SPACEMANONE::m_max_plus_spaceman_power;
			}
		}
		else if (directx.KeyState[DIK_G] == directx.OFF)
		{
			SPACEMANONE::m_plus_spaceman_speed = 0.0F;
			SPACEMANONE::m_plus_jump_power = 0.0F;
		}
	}
}

VOID SPACEMANONE::SpaceManMove()
{
	SPACEMANONE::SpaceManRelease();

	if (directx.KeyState[DIK_D] == directx.ON)
	{
		SPACEMANONE::m_pos_x += (SPACEMANONE::m_spaceman_speed + SPACEMANONE::m_plus_spaceman_speed);
	}
	else if (directx.KeyState[DIK_A] == directx.ON)
	{
		SPACEMANONE::m_pos_x -= (SPACEMANONE::m_spaceman_speed + SPACEMANONE::m_plus_spaceman_speed);
	}

	SPACEMANONE::SpaceManDash();

	if (directx.KeyState[DIK_W] == directx.PRESS)
	{
		SPACEMANONE::m_gravity = SPACEMANONE::m_max_gravity;
		SPACEMANONE::m_jump_power = (SPACEMANONE::m_jump_power + SPACEMANONE::m_plus_jump_power);

		SPACEMANONE::m_jump = SPACEMANONE::SpaceManJumpSwitchChange(SPACEMANONE::m_jump);
	}

	if (directx.KeyState[DIK_S] == directx.ON)
	{
		SPACEMANONE::m_pos_y += SPACEMANONE::m_spaceman_speed;
		SPACEMANONE::m_is_dash = FALSE;
	}
	else if (directx.KeyState[DIK_S] == directx.OFF)
	{
		SPACEMANONE::m_is_dash = TRUE;
	}

	SPACEMANONE::SpaceManSwitchJump(SPACEMANONE::m_jump);

}
