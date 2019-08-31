#include"../BATTLE-OF-ATMOSPHERE/Character.h"

VOID SPACEMANBASE::SpaceManJump()
{
	SPACEMANBASE::m_spaceman_pos_y -= SPACEMANBASE::m_jump_power;
	SPACEMANBASE::m_jump_power -= SPACEMANBASE::m_gravity;
}

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

VOID SPACEMANBASE::SpaceManRelease()
{
	// 仮の地面の座標(890)
	if (SPACEMANBASE::m_spaceman_pos_y >= 890)
	{
		SPACEMANBASE::m_jump_power = SPACEMANBASE::m_max_jump_power;
		SPACEMANBASE::m_jump = NO_JUMP;
		SPACEMANBASE::m_is_call = FALSE;
	}
	else
	{
		SPACEMANBASE::m_plus_spaceman_speed = 0.0F;
		SPACEMANBASE::m_is_dash = FALSE;
	}
}

VOID SPACEMANBASE::SpaceManSwitchJump(JUMP jump)
{
	switch (jump)
	{
	case NO_JUMP:

		// ジャンプしていないとき（落下など）自身に重力をかけている
		SPACEMANBASE::m_spaceman_pos_y += SPACEMANBASE::m_gravity;
		SPACEMANBASE::m_gravity += SPACEMANBASE::m_max_gravity;
		break;

	case ONE_JUMP:

		SPACEMANBASE::SpaceManJump();
		SPACEMANBASE::m_plus_jump_power = 0.0F;

		break;

	case TWO_JUMP:

		if (SPACEMANBASE::m_is_call == FALSE)
		{
			SPACEMANBASE::m_jump_power = SPACEMANBASE::m_max_jump_power;
			SPACEMANBASE::m_is_call = TRUE;
		}

		SPACEMANBASE::SpaceManJump();

		break;

	default:
		SPACEMANBASE::SpaceManJump();
		break;
	}
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
		SPACEMANONE::m_spaceman_pos_x += (SPACEMANONE::m_spaceman_speed + SPACEMANONE::m_plus_spaceman_speed);
	}
	else if (directx.KeyState[DIK_A] == directx.ON)
	{
		SPACEMANONE::m_spaceman_pos_x -= (SPACEMANONE::m_spaceman_speed + SPACEMANONE::m_plus_spaceman_speed);
	}

	SPACEMANONE::SpaceManDash();

	if (directx.KeyState[DIK_W] == directx.PRESS)
	{
		SPACEMANONE::m_gravity = SPACEMANONE::m_max_gravity;
		SPACEMANONE::m_jump_power = (SPACEMANONE::m_jump_power + SPACEMANONE::m_plus_jump_power);

		SPACEMANONE::m_jump = SPACEMANONE::SpaceManJumpSwitchChange(SPACEMANONE::m_jump);
	}

	SPACEMANONE::SpaceManSwitchJump(SPACEMANONE::m_jump);

	if (directx.KeyState[DIK_S] == directx.ON)
	{
		SPACEMANONE::m_spaceman_pos_y += SPACEMANONE::m_spaceman_speed;
		SPACEMANONE::m_is_dash = FALSE;
	}
	else if (directx.KeyState[DIK_S] == directx.OFF)
	{
		SPACEMANONE::m_is_dash = TRUE;
	}

}

VOID SPACEMANTWO::SpaceManDash()
{
	if (SPACEMANTWO::m_is_dash == TRUE) {

		if ((directx.KeyState[DIK_RIGHT] == directx.ON &&
			directx.KeyState[DIK_L] == directx.ON) ||
			(directx.KeyState[DIK_LEFT] == directx.ON &&
				directx.KeyState[DIK_L] == directx.ON))
		{

			SPACEMANTWO::m_plus_spaceman_speed += SPACEMANTWO::m_plus_dash_power;
			SPACEMANTWO::m_plus_jump_power += SPACEMANTWO::m_plus_dash_power;

			if (SPACEMANTWO::m_plus_spaceman_speed >= SPACEMANTWO::m_max_plus_spaceman_power)
			{
				SPACEMANTWO::m_plus_spaceman_speed = SPACEMANTWO::m_max_plus_spaceman_power;
				SPACEMANTWO::m_plus_jump_power = SPACEMANTWO::m_max_plus_spaceman_power;
			}
		}
		else if (directx.KeyState[DIK_L] == directx.OFF)
		{
			SPACEMANTWO::m_plus_spaceman_speed = 0.0F;
			SPACEMANTWO::m_plus_jump_power = 0.0F;
		}
	}
}

VOID SPACEMANTWO::SpaceManMove()
{
	SPACEMANTWO::SpaceManRelease();

	if (directx.KeyState[DIK_RIGHT] == directx.ON)
	{
		SPACEMANTWO::m_spaceman_pos_x += (SPACEMANTWO::m_spaceman_speed + SPACEMANTWO::m_plus_spaceman_speed);
	}
	else if (directx.KeyState[DIK_LEFT] == directx.ON)
	{
		SPACEMANTWO::m_spaceman_pos_x -= (SPACEMANTWO::m_spaceman_speed + SPACEMANTWO::m_plus_spaceman_speed);
	}

	SPACEMANTWO::SpaceManDash();

	if (directx.KeyState[DIK_UP] == directx.PRESS)
	{
		SPACEMANTWO::m_gravity = SPACEMANTWO::m_max_gravity;
		SPACEMANTWO::m_jump_power = (SPACEMANTWO::m_jump_power + SPACEMANTWO::m_plus_jump_power);

		SPACEMANTWO::m_jump = SPACEMANTWO::SpaceManJumpSwitchChange(SPACEMANTWO::m_jump);
	}

	if (directx.KeyState[DIK_DOWN] == directx.ON)
	{
		SPACEMANTWO::m_spaceman_pos_y += SPACEMANTWO::m_spaceman_speed;
		SPACEMANTWO::m_is_dash = FALSE;
	}
	else if (directx.KeyState[DIK_DOWN] == directx.OFF)
	{
		SPACEMANTWO::m_is_dash = TRUE;
	}

	SPACEMANTWO::SpaceManSwitchJump(SPACEMANTWO::m_jump);

}