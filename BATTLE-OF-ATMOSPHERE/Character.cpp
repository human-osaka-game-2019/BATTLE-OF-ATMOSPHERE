#include"../BATTLE-OF-ATMOSPHERE/Character.h"
#include <time.h>

VOID SPACEMANBASE::SpaceManRelease()
{
	//着地時にジャンプ関係の変数を初期化
	if (SPACEMANBASE::m_pos_y >= 890)
	{
		SPACEMANBASE::m_jump_power = SPACEMANBASE::m_max_jump_power;
		SPACEMANBASE::m_jump = NO_JAMP;
		SPACEMANBASE::m_is_call = FALSE;
		SPACEMANBASE::m_is_dash = TRUE;
	}
	else
	{
		SPACEMANBASE::m_plus_spaceman_speed = 0.0F;
		SPACEMANBASE::m_is_dash = FALSE;
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

			SPACEMAN1P::m_plus_spaceman_speed += 0.05F;
			SPACEMAN1P::m_plus_jump_power += 0.05F;

			if (SPACEMAN1P::m_plus_spaceman_speed >= 5.0F)
			{
				SPACEMAN1P::m_plus_spaceman_speed = 5.0F;
				SPACEMAN1P::m_plus_jump_power = 5.0F;
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

	if (directx.KeyState[DIK_A] == directx.ON)
	{
		SPACEMAN1P::m_pos_x -= (SPACEMAN1P::m_spaceman_speed + SPACEMAN1P::m_plus_spaceman_speed);
	}

	SpaceManDash();

	if (directx.KeyState[DIK_W] == directx.PRESS)
	{
		SPACEMAN1P::m_gravity = SPACEMAN1P::m_max_gravity;
		SPACEMAN1P::m_jump_power = (SPACEMAN1P::m_jump_power + SPACEMAN1P::m_plus_jump_power);

		switch (SPACEMAN1P::m_jump)
		{
		case NO_JAMP:
			SPACEMAN1P::m_jump = ONE_JAMP;
			break;
		case ONE_JAMP:
			SPACEMAN1P::m_jump = TWO_JAMP;
			break;
		}
	}

	if (directx.KeyState[DIK_S] == directx.ON)
	{
		SPACEMAN1P::m_pos_y += SPACEMAN1P::m_spaceman_speed;
		SPACEMAN1P::m_is_dash = FALSE;
	}

	switch (SPACEMAN1P::m_jump)
	{
	case NO_JAMP:

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
