#include"../BATTLE-OF-ATMOSPHERE/Character.h"

BOOL SpaceManJudge(FLOAT me_pos_x, FLOAT you_pos_x, FLOAT me_pos_y, FLOAT you_pos_y, FLOAT me_width, FLOAT me_height, FLOAT you_width, FLOAT you_height)
{
	if (me_pos_x <= you_pos_x + you_width && you_pos_x <= me_pos_x + me_width && me_pos_y <= you_pos_y + you_height && you_pos_y <= me_pos_y + me_height)
	{
		return TRUE;
	}

	return FALSE;
}

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
		SPACEMANBASE::m_plus_spaceman_speed = 0.0f;
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
		SPACEMANBASE::m_plus_jump_power = 0.0f;

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//引数にクラスのインスタンスを

VOID SPACEMANONE::SpaceManPush()
{
	if (directx.KeyState[DIK_LCONTROL] == directx.PRESS)
	{
		switch (SPACEMANONE::m_key_memory)
		{
		case KEY::LEFT:
			SPACEMANONE::m_spaceman_pos_x = SPACEMANONE::m_spaceman_pos_x - 96.0f;
			SPACEMANONE::m_spaceman_width = 192.0f;
			break;
		case KEY::RIGHT:
			SPACEMANONE::m_spaceman_width = 192.0f;
			break;
		case KEY::UP:
			break;
		}
	}
	else if (directx.KeyState[DIK_LCONTROL] == directx.RELEASE)
	{
		switch (SPACEMANONE::m_key_memory)
		{
		case KEY::LEFT:
			SPACEMANONE::m_spaceman_pos_x = SPACEMANONE::m_spaceman_pos_x + 96.0f;
			SPACEMANONE::m_spaceman_width = 96.0f;
			break;
		case KEY::RIGHT:
			SPACEMANONE::m_spaceman_width = 96.0f;
			break;
		case KEY::UP:
			break;
		}
	}
}

VOID SPACEMANTWO::SpaceManPush()
{
	if (directx.KeyState[DIK_RCONTROL] == directx.PRESS)
	{
		switch (SPACEMANTWO::m_key_memory)
		{
		case KEY::LEFT:
			SPACEMANTWO::m_spaceman_pos_x = SPACEMANTWO::m_spaceman_pos_x - 96.0f;
			SPACEMANTWO::m_spaceman_width = 192.0f;
			break;
		case KEY::RIGHT:
			SPACEMANTWO::m_spaceman_width = 192.0f;
			break;
		case KEY::UP:
			break;
		}
	}
	else if (directx.KeyState[DIK_RCONTROL] == directx.RELEASE)
	{
		switch (SPACEMANTWO::m_key_memory)
		{
		case KEY::LEFT:
			SPACEMANTWO::m_spaceman_pos_x = SPACEMANTWO::m_spaceman_pos_x + 96.0f;
			SPACEMANTWO::m_spaceman_width = 96.0f;
			break;
		case KEY::RIGHT:
			SPACEMANTWO::m_spaceman_width = 96.0f;
			break;
		case KEY::UP:
			break;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VOID SPACEMANONE::SpaceManCrouch()
{
	if (directx.KeyState[DIK_S] == directx.ON)
	{
		SPACEMANONE::m_is_move = FALSE;
	}
	else if (directx.KeyState[DIK_S] == directx.RELEASE)
	{
		SPACEMANONE::m_is_move = TRUE;
	}
}

VOID SPACEMANTWO::SpaceManCrouch()
{
	if (directx.KeyState[DIK_DOWN] == directx.ON)
	{
		SPACEMANTWO::m_is_move = FALSE;
	}
	else if (directx.KeyState[DIK_DOWN] == directx.RELEASE)
	{
		SPACEMANTWO::m_is_move = TRUE;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VOID SPACEMANONE::SpaceManDash()
{
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
		SPACEMANONE::m_plus_spaceman_speed = 0.0f;
		SPACEMANONE::m_plus_jump_power = 0.0f;
	}
}


VOID SPACEMANTWO::SpaceManDash()
{
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
		SPACEMANTWO::m_plus_spaceman_speed = 0.0f;
		SPACEMANTWO::m_plus_jump_power = 0.0f;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VOID SPACEMANONE::SpaceManMove(SPACEMANBASE& spacemanbase)
{
	SPACEMANONE::SpaceManRelease();

	if (SPACEMANONE::m_is_move == TRUE)
	{

		if (directx.KeyState[DIK_D] == directx.ON)
		{
			SPACEMANONE::m_key_memory = KEY::RIGHT;
			SPACEMANONE::m_spaceman_pos_x += (SPACEMANONE::m_spaceman_speed + SPACEMANONE::m_plus_spaceman_speed);
		}
		else if (directx.KeyState[DIK_A] == directx.ON)
		{
			SPACEMANONE::m_key_memory = KEY::LEFT;
			SPACEMANONE::m_spaceman_pos_x -= (SPACEMANONE::m_spaceman_speed + SPACEMANONE::m_plus_spaceman_speed);
		}

		SPACEMANONE::SpaceManDash();

		if (directx.KeyState[DIK_W] == directx.PRESS)
		{
			SPACEMANONE::m_key_memory = KEY::UP;
			SPACEMANONE::m_gravity = SPACEMANONE::m_max_gravity;
			SPACEMANONE::m_jump_power = (SPACEMANONE::m_jump_power + SPACEMANONE::m_plus_jump_power);

			SPACEMANONE::m_jump = SPACEMANONE::SpaceManJumpSwitchChange(SPACEMANONE::m_jump);
		}

	}

	SPACEMANONE::SpaceManCrouch();

	SPACEMANONE::SpaceManSwitchJump(SPACEMANONE::m_jump);

}


VOID SPACEMANTWO::SpaceManMove(SPACEMANBASE& spacemanbase)
{
	SPACEMANTWO::SpaceManRelease();

	if (SPACEMANTWO::m_is_move == TRUE)
	{

		if (directx.KeyState[DIK_RIGHT] == directx.ON)
		{
			SPACEMANTWO::m_key_memory = KEY::RIGHT;
			SPACEMANTWO::m_spaceman_pos_x += (SPACEMANTWO::m_spaceman_speed + SPACEMANTWO::m_plus_spaceman_speed);
		}
		else if (directx.KeyState[DIK_LEFT] == directx.ON)
		{
			SPACEMANTWO::m_key_memory = KEY::LEFT;
			SPACEMANTWO::m_spaceman_pos_x -= (SPACEMANTWO::m_spaceman_speed + SPACEMANTWO::m_plus_spaceman_speed);
		}

		SPACEMANTWO::SpaceManDash();

		if (directx.KeyState[DIK_UP] == directx.PRESS)
		{
			SPACEMANTWO::m_key_memory = KEY::UP;
			SPACEMANTWO::m_gravity = SPACEMANTWO::m_max_gravity;
			SPACEMANTWO::m_jump_power = (SPACEMANTWO::m_jump_power + SPACEMANTWO::m_plus_jump_power);

			SPACEMANTWO::m_jump = SPACEMANTWO::SpaceManJumpSwitchChange(SPACEMANTWO::m_jump);
		}

	}

	SPACEMANTWO::SpaceManCrouch();

	SPACEMANTWO::SpaceManSwitchJump(SPACEMANTWO::m_jump);

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
