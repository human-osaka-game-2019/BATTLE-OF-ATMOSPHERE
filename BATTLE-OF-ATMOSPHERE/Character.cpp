#include "Character.h"

#include "Main.h"

VOID SPACEMAN::SpaceManInit(CHAR_* char_)
{
	if (char_->player == ONE_PLAYER)
	{
		char_->x = 96 * 5;
	}
	if (char_->player == TWO_PLAYER)
	{
		char_->x = 96 * 11;
	}
	char_->y = 96 * 6;
}

VOID SPACEMAN::SpaceManJumpSwitchChange(JUMP* jump)
{
	switch (*jump)
	{
	case FALL:
		*jump = ONE_JUMP;
		break;
	case ONE_JUMP:
		*jump = TWO_JUMP;
		break;
	}
}

VOID SPACEMAN::SpaceManSwitchJump(CHAR_* char_)
{
	switch (char_->m_action)
	{
	case FALL:

		char_->m_gravity += 1;

		break;

	case NO_JUMP:

		// ジャンプしていないとき（落下など）自身に重力をかけている
		char_->m_is_call = FALSE;
		char_->m_gravity = 0;

		break;

	case ONE_JUMP:

		char_->m_gravity += 1;

		break;

	case TWO_JUMP:

		if (char_->m_is_call == FALSE)
		{
			char_->m_is_call = TRUE;
		}

		char_->m_gravity += 1;

		break;
	}
}

VOID SPACEMAN::SpaceManDash(CHAR_* char_)
{
	if (char_->m_is_dash == TRUE) {

		if ((directx.KeyState[DIK_D] == directx.ON && directx.KeyState[DIK_G] == directx.ON) || (directx.KeyState[DIK_A] == directx.ON && directx.KeyState[DIK_G] == directx.ON))
		{
			char_->m_plus_spaceman_speed += char_->m_plus_dash_power;
			char_->m_plus_jump_power += char_->m_plus_dash_power;

			if (char_->m_plus_spaceman_speed >= char_->m_max_plus_spaceman_power)
			{
				char_->m_plus_spaceman_speed = char_->m_max_plus_spaceman_power;
				char_->m_plus_jump_power = char_->m_max_plus_spaceman_power;
			}
		}
		else if (directx.KeyState[DIK_G] == directx.OFF)
		{
			char_->m_plus_spaceman_speed = 0.0F;
			char_->m_plus_jump_power = 0.0F;
		}
	}
}

VOID SPACEMAN::SpaceManMove(CHAR_* char_)
{
	/*FLOAT save_x = char_->x;
	FLOAT save_y = char_->y;*/

	char_->save_x = char_->x;
	char_->save_y = char_->y;

	if (char_->player == ONE_PLAYER) {

		SpaceManSwitchJump(char_);

		if (directx.KeyState[DIK_D] == directx.ON)
		{
			char_->x += (char_->m_spaceman_speed + char_->m_plus_spaceman_speed);
			char_->m_direction = RIGHT;
		}
		else if (directx.KeyState[DIK_A] == directx.ON)
		{
			char_->x -= (char_->m_spaceman_speed + char_->m_plus_spaceman_speed);
			char_->m_direction = LEFT;
		}

		SpaceManDash(char_);

		if ((directx.KeyState[DIK_W] == directx.PRESS) && (char_->m_is_call == FALSE))
		{
			char_->m_gravity = -30;
			SpaceManJumpSwitchChange(&char_->m_action);
			char_->m_direction = UP;
		}

		if (directx.KeyState[DIK_S] == directx.ON)
		{
			char_->m_is_dash = FALSE;
			char_->m_direction = DOWN;
		}
		else if (directx.KeyState[DIK_S] == directx.OFF)
		{
			char_->m_is_dash = TRUE;
		}
	}

	if (char_->player == TWO_PLAYER) {
		SpaceManSwitchJump(char_);

		if (directx.KeyState[DIK_RIGHT] == directx.ON)
		{
			char_->x += (char_->m_spaceman_speed + char_->m_plus_spaceman_speed);
			char_->m_direction = RIGHT;
		}
		else if (directx.KeyState[DIK_LEFT] == directx.ON)
		{
			char_->x -= (char_->m_spaceman_speed + char_->m_plus_spaceman_speed);
			char_->m_direction = LEFT;
		}

		SpaceManDash(char_);

		if ((directx.KeyState[DIK_UP] == directx.PRESS) && (char_->m_is_call == FALSE))
		{
			char_->m_gravity = -30;
			SpaceManJumpSwitchChange(&char_->m_action);
			char_->m_direction = UP;
		}

		if (directx.KeyState[DIK_DOWN] == directx.ON)
		{
			char_->m_is_dash = FALSE;
			char_->m_direction = DOWN;
		}
		else if (directx.KeyState[DIK_DOWN] == directx.OFF)
		{
			char_->m_is_dash = TRUE;
		}
	}

	Move(char_, char_->save_x, char_->save_y);

	//Move(char_,save_x,save_y);

}

VOID SPACEMAN::Move(CHAR_* char_, FLOAT save_x, FLOAT save_y)
{

	//重力移動
	char_->y += char_->m_gravity;



	//キー入力




	char_->vec_x = save_x - char_->x;
	char_->vec_y = save_y - char_->y;
}
