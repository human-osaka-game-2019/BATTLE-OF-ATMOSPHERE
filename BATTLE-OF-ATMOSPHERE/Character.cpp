#include"../BATTLE-OF-ATMOSPHERE/Character.h"
#include <time.h>

VOID SPACEMAN1P::SpaceManJump()
{

	SPACEMAN1P::m_pos_y -= SPACEMAN1P::m_jump_budget;
	SPACEMAN1P::m_jump_budget -= SPACEMAN1P::m_gravity;
}

VOID SPACEMAN1P::SpaceManMove()
{
	if (SPACEMAN1P::m_pos_y >= 825)
	{
		SPACEMAN1P::m_jump_budget = 9.0F;
		SPACEMAN1P::m_jump = NO_JAMP;
		SPACEMAN1P::m_is_call = FALSE;
	}

	switch (directx.KeyState[DIK_D])
	{
	case directx.ON:
		SPACEMAN1P::m_pos_x += SPACEMAN1P::m_spaceman_speed;
		break;
	case directx.OFF:
		break;
	case directx.RELEASE:
		break;
	default:
		break;
	}

	switch (directx.KeyState[DIK_A])
	{
	case directx.ON:
		SPACEMAN1P::m_pos_x -= SPACEMAN1P::m_spaceman_speed;
		break;
	case directx.OFF:
		break;
	case directx.RELEASE:
		break;
	default:
		break;
	}

	if (directx.KeyState[DIK_W] == directx.PRESS)
	{
		SPACEMAN1P::m_gravity = 0.2;

		switch (SPACEMAN1P::m_jump)
		{
		case NO_JAMP:
			SPACEMAN1P::m_jump = ONE_JAMP;
			break;
		case ONE_JAMP:
			SPACEMAN1P::m_jump = TWO_JAMP;
			break;
		default:
			break;
		}
	}

	if (directx.KeyState[DIK_S] == directx.ON)
	{
		SPACEMAN1P::m_pos_y += SPACEMAN1P::m_spaceman_speed;
	}

	switch (SPACEMAN1P::m_jump)
	{
	case NO_JAMP:

		SPACEMAN1P::m_pos_y += SPACEMAN1P::m_gravity;
		SPACEMAN1P::m_gravity += 0.2;
		break;

	case ONE_JAMP:

		SpaceManJump();
		break;

	case TWO_JAMP:

		if (SPACEMAN1P::m_is_call == FALSE)
		{
			SPACEMAN1P::m_jump_budget = 9.0F;
			SPACEMAN1P::m_is_call = TRUE;
		}

		SpaceManJump();

		break;
	}


}