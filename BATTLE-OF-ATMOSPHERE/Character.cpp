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
		char_->x = 96 * 14;
	}
	char_->y = 96 * 6;


	char_->is_ice = FALSE;
	char_->is_ice_hit = FALSE;

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
		
		if (char_->m_direction == UP)
		{
			if (char_->side_direction == RIGHT)
			{
				char_->tu = 0.0f;
				char_->tv = 0.03125f * 1;
			}
			else if (char_->side_direction == LEFT)
			{
				char_->tu = 0.0f;
				char_->tv = 0.0f;
			}
		}
		else if (char_->m_direction == DOWN)
		{
			if (char_->side_direction == RIGHT)
			{
				char_->tu = 0.0f;
				char_->tv = 0.03125f * 1;
			}
			else if (char_->side_direction == LEFT)
			{
				char_->tu = 0.0f;
				char_->tv = 0.0f;
			}
		}



		if (char_->m_direction == RIGHT) {
			char_->tu = 0.0f;
			char_->tv = 0.03125f * 1;
			//    draw.Animetion(&fc_right_jump_one, 8, &char_->tu, &char_->tv, 0.25f, 0.0f, 0.0f, 0.03125f * 20, 0.5f, 0.0f);
		}
		else if (char_->m_direction == LEFT)
		{
			char_->tu = 0.0f;
			char_->tv = 0.0f;
		}
		break;

	case NO_JUMP:

		char_->m_is_call = FALSE;
		char_->m_gravity += 1;
		if (char_->m_direction == RIGHT) {
			char_->tu = 0.0f;
			char_->tv = 0.03125f * 1;
			//    draw.Animetion(&fc_right_jump_one, 8, &char_->tu, &char_->tv, 0.25f, 0.0f, 0.0f, 0.03125f * 20, 0.5f, 0.0f);
		}
		else if (char_->m_direction == LEFT)
		{
			char_->tu = 0.0f;
			char_->tv = 0.0f;
		}

		break;

	case ONE_JUMP:

		char_->m_gravity += 1;

		if (char_->side_direction == RIGHT) {
			char_->tu = 0.25f;
			char_->tv = 0.03125f * 20;
			//    draw.Animetion(&fc_right_jump_one, 8, &char_->tu, &char_->tv, 0.25f, 0.0f, 0.0f, 0.03125f * 20, 0.5f, 0.0f);
		}
		else if (char_->side_direction == LEFT)
		{
			char_->tu = 0.25f;
			char_->tv = 0.03125f * 21;
			//    draw.Animetion(&fc_left_jump_one, 8, &left_jump_one_tu, &left_jump_one_tv, 0.25f, 0.0f, 0.0f, 0.03125f * 21, 0.5f, 0.0f);
		}

		break;

	case TWO_JUMP:

		if (char_->m_is_call == FALSE)
		{
			char_->m_is_call = TRUE;
		}

		char_->m_gravity += 1;

		if (char_->side_direction == RIGHT) {
			char_->tu = 0.25f;
			char_->tv = 0.03125f * 20;
			//    draw.Animetion(&fc_right_jump_one, 8, &char_->tu, &char_->tv, 0.25f, 0.0f, 0.0f, 0.03125f * 20, 0.5f, 0.0f);
		}
		else if (char_->side_direction == LEFT)
		{
			char_->tu = 0.25f;
			char_->tv = 0.03125f * 21;
			//    draw.Animetion(&fc_left_jump_one, 8, &left_jump_one_tu, &left_jump_one_tv, 0.25f, 0.0f, 0.0f, 0.03125f * 21, 0.5f, 0.0f);
		}


		break;

	default:

		char_->m_gravity += 1;

		break;
	}
}

BOOL SPACEMAN::BlastHitCheck(CHAR_ char_, BLAST_STATUS blast_status)
{
	if ((blast_status.x < char_.x + char_.width) && (blast_status.y < char_.y + char_.height) && (blast_status.x + blast_status.size > char_.x) && (blast_status.y + blast_status.size > char_.y))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

VOID SPACEMAN::SpaceManPush(CHAR_* char_me, CHAR_* char_you, BLAST_STATUS* blast_status)
{
	switch (char_me->m_direction)
	{
	case RIGHT:
		blast_status->x = char_me->x + 96.0f;
		blast_status->y = char_me->y + 48.0f;
		blast_status->tu = 128.0f * 1 / 2048.f;
		blast_status->tv = 128.0f * 0 / 2048.f;
		//draw.Draw(blast_status->x, blast_status->y, 0xffffffff, 0.0f, 0.0f, blast_status->size, blast_status->size, 1.0f, 1.0f, BLAST);
		break;
	case LEFT:
		blast_status->x = char_me->x - 96.0f;
		blast_status->y = char_me->y + 48.0f;
		blast_status->tu = 128.0f * 1 / 2048.f;
		blast_status->tv = 128.0f * 1 / 2048.f;
		//draw.Draw(blast_status->x, blast_status->y, 0xffffffff, 0.0f, 0.0f, blast_status->size, blast_status->size, 1.0f, 1.0f, BLAST);
		break;
	case UP:
		blast_status->x = char_me->x;
		blast_status->y = char_me->y - 96.0f;
		blast_status->tu = 128.0f * 1 / 2048.f;
		blast_status->tv = 128.0f * 2 / 2048.f;
		char_me->m_gravity = 5;
		//draw.Draw(blast_status->x, blast_status->y, 0xffffffff, 0.0f, 0.0f, blast_status->size, blast_status->size, 1.0f, 1.0f, BLAST);
		break;
	case DOWN:
		blast_status->x = char_me->x;
		blast_status->y = char_me->y + 192.0f;
		blast_status->tu = 128.0f * 1 / 2048.f;
		blast_status->tv = 128.0f * 3 / 2048.f;
		//draw.Draw(blast_status->x, blast_status->y, 0xffffffff, 0.0f, 0.0f, blast_status->size, blast_status->size, 1.0f, 1.0f, BLAST);
		break;
	}

	draw.Draw(blast_status->x, blast_status->y, 0xffffffff, blast_status->tu, blast_status->tv, blast_status->size, blast_status->size,128.0f/ 2048, 128.0f/2048, BLAST);

	if (BlastHitCheck(*char_you, *blast_status) == TRUE)
	{
		if (char_you->m_is_guard == FALSE)
		{
			char_you->m_is_hit = TRUE;

			switch (char_me->m_direction)
			{
			case RIGHT:
				blast_status->blast_power_x = 80;
				blast_status->blast_power_y = 0;
				break;
			case LEFT:
				blast_status->blast_power_x = -80;
				blast_status->blast_power_y = 0;
				break;
			case UP:
				blast_status->blast_power_x = 0;
				blast_status->blast_power_y = -80;
				break;
			case DOWN:
				blast_status->blast_power_x = 0;
				blast_status->blast_power_y = 80;
				break;
			}
		}
	}

	char_me->m_fc_push = 30;

}

VOID SPACEMAN::SpaceManBlastHit(CHAR_* char_, BLAST_STATUS* blast_status)
{
	if (blast_status->blast_power_x != 0 || blast_status->blast_power_y != 0)
	{
		if (blast_status->blast_power_x != 0)
		{
			char_->x += blast_status->blast_power_x;

			if (blast_status->blast_power_x > 0)
			{
				blast_status->blast_power_x -= 20;
				char_->tu = 0.5f;
				char_->tv = 0.03125f * 6;
			}
			else
			{
				blast_status->blast_power_x += 20;
				char_->tu = 0.5f;

				char_->tv = 0.03125f * 6;
			}

		}

		if (blast_status->blast_power_y != 0)
		{
			char_->y += blast_status->blast_power_y;

			if (blast_status->blast_power_y > 0)
			{
				blast_status->blast_power_y -= 20;
			}
			else
			{
				blast_status->blast_power_y += 20;
			}
		}

	}
	else 
	{
		char_->m_is_hit = FALSE;
	}

}

VOID SPACEMAN::SpaceManDash(CHAR_* char_)
{
	if (char_->m_is_dash == TRUE) {

		if (char_->player == ONE_PLAYER)
		{
			if ((directx.KeyState[DIK_D] == directx.ON && directx.KeyState[DIK_G] == directx.ON) ||
				(directx.KeyState[DIK_A] == directx.ON && directx.KeyState[DIK_G] == directx.ON))
			{
				char_->m_plus_spaceman_speed += m_plus_dash_power;
				char_->m_plus_jump_power += m_plus_dash_power;

				if (char_->m_plus_spaceman_speed >= m_max_plus_spaceman_power)
				{
					char_->m_plus_spaceman_speed = m_max_plus_spaceman_power;
					char_->m_plus_jump_power = m_max_plus_spaceman_power;
				}
			}
			else if (directx.KeyState[DIK_G] == directx.OFF)
			{
				char_->m_plus_spaceman_speed = 0.0F;
				char_->m_plus_jump_power = 0.0F;
			}

		}

		if (char_->player == TWO_PLAYER)
		{
			if ((directx.KeyState[DIK_RIGHT] == directx.ON && directx.KeyState[DIK_L] == directx.ON) || 
				(directx.KeyState[DIK_LEFT] == directx.ON && directx.KeyState[DIK_L] == directx.ON))
			{
				char_->m_plus_spaceman_speed += m_plus_dash_power;
				char_->m_plus_jump_power += m_plus_dash_power;

				if (char_->m_plus_spaceman_speed >= m_max_plus_spaceman_power)
				{
					char_->m_plus_spaceman_speed = m_max_plus_spaceman_power;
					char_->m_plus_jump_power = m_max_plus_spaceman_power;
				}
			}
			else if (directx.KeyState[DIK_L] == directx.OFF)
			{
				char_->m_plus_spaceman_speed = 0.0F;
				char_->m_plus_jump_power = 0.0F;
			}
		}
	}
}

VOID SPACEMAN::SpaceManMove(CHAR_* char_, CHAR_* char_you, BLAST_STATUS* blast_status)
{	/*FLOAT save_x = char_->x;
	FLOAT save_y = char_->y;*/

	char_->save_x = char_->x;
	char_->save_y = char_->y;

	if (char_->player == ONE_PLAYER) {

		if (char_->m_direction == RIGHT || char_->m_direction == LEFT)
		{
			char_->side_direction = char_->m_direction;
		}

		SpaceManSwitchJump(char_);

		if (char_you->m_is_hit == TRUE)
		{
			SpaceManBlastHit(char_you, blast_status);
		}
		else if (char_->is_ice_hit == TRUE)
		{
			if (char_->m_direction == UP)
			{
				if (char_->side_direction == RIGHT) {
					char_->tu = 0.0f;
					char_->tv = 0.03125f * 22;
				}
				else if (char_->side_direction == LEFT) {
					char_->tu = 0.0f;
					char_->tv = 0.03125f * 23;
				}
			}else
			if (char_->m_direction == DOWN)
			{
				if (char_->side_direction == RIGHT) {
					char_->tu = 0.0f;
					char_->tv = 0.03125f * 22;
				}
				else if (char_->side_direction == LEFT) {
					char_->tu = 0.0f;
					char_->tv = 0.03125f * 23;
				}
			}

			if (char_->m_direction == RIGHT) {
				char_->tu = 0.0f;
				char_->tv = 0.03125f * 22;
			}
			else if(char_->m_direction == LEFT){
				char_->tu = 0.0f;
				char_->tv = 0.03125f * 23;
			}
			
			char_->fc_ice--;
			if (char_->fc_ice <= 0)
			{
				char_->is_ice_hit = FALSE;
			}
		}
		else
		{
			if (directx.KeyState[DIK_S] == directx.OFF) {
				if (directx.KeyState[DIK_D] == directx.ON)
				{
					char_->x += (char_->m_spaceman_speed + char_->m_plus_spaceman_speed);

					char_->m_direction = RIGHT;
					/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					if (char_->m_action == ONE_JUMP || char_->m_action == TWO_JUMP)
					{
						char_->tu = 0.25f;
						char_->tv = 0.03125f * 20;
					}
					else
					{
						char_->tu = 0.0f;
						char_->tv = 0.03125f * 1;
					}
					//draw.Animetion(&fc_right_slide_one, 8, &char_->tu, &char_->tv, 0.25f, 0.0f, 0.0f, 0.03125f * 17, 0.5f, 0.0f);
				}
				else if (directx.KeyState[DIK_A] == directx.ON)
				{
					char_->x -= (char_->m_spaceman_speed + char_->m_plus_spaceman_speed);
					char_->m_direction = LEFT;
					/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					if (char_->m_action == ONE_JUMP || char_->m_action == TWO_JUMP)
					{
						char_->tu = 0.25f;
						char_->tv = 0.03125f * 21;
					}
					else
					{
						char_->tu = 0.0f;
						char_->tv = 0.03125f * 0;
					}
					//draw.Animetion(&fc_left_slide_one, 8, &char_->tu, &char_->tv, 0.25f, 0.0f, 0.0f, 0.03125f * 18, 0.5f, 0.0f);
				}

				SpaceManDash(char_);

				char_->m_fc_push--;

				if (directx.KeyState[DIK_LCONTROL] == directx.PRESS)
				{
					if (char_->m_fc_push <= 0)
					{
						SpaceManPush(char_, char_you, blast_status);
						/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
						if (char_->m_direction == RIGHT && (char_->m_action == ONE_JUMP || char_->m_action == TWO_JUMP))
						{
							char_->tu = 0.5f;
							char_->tv = 0.03125f * 19;
						}
						else if (char_->m_direction == LEFT && (char_->m_action == ONE_JUMP || char_->m_action == TWO_JUMP))
						{
							char_->tu = 0.5f;
							char_->tv = 0.03125f * 4;
						}
						else if (char_->m_direction == RIGHT)
						{
							char_->tu = 0.5f;
							char_->tv =  0.03125f * 1;
						}
						else if (char_->m_direction == LEFT)
						{
							char_->tu = 0.5f;
							char_->tv = 0.03125f * 0;
						}
					}
				}
			}
			if ((directx.KeyState[DIK_W] == directx.PRESS) && (char_->m_is_call == FALSE))
			{
				char_->m_gravity = -30;
				SpaceManJumpSwitchChange(&char_->m_action);
				char_->m_direction = UP;
			}

			
			{
				if (directx.KeyState[DIK_S] == directx.ON)
				{
					if (char_->m_action == NO_JUMP || char_->m_action == FALL) 
					{
						char_->m_is_dash = FALSE;
						char_->m_is_guard = TRUE;
						/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
						if (char_->side_direction == RIGHT) {
							char_->tu = 0.5f;
							char_->tv = 0.03125f * 15;
						}
						else if (char_->side_direction == LEFT)
						{
							char_->tu = 0.5f;
							char_->tv = 0.03125f * 16;
						}
					}
				
					char_->m_direction = DOWN;
					

				}
				else if (directx.KeyState[DIK_S] == directx.RELEASE)
				{
					if (char_->m_action == NO_JUMP || char_->m_action == FALL)
					{
						char_->m_is_guard = FALSE;
						char_->m_is_dash = TRUE;
						if (char_->side_direction == RIGHT)
						{
							char_->tu = 0.0f;
							char_->tv = 0.03125f * 1;
						}
						else if (char_->side_direction == LEFT)
						{
							char_->tu = 0.0f;
							char_->tv = 0.03125f * 0;
						}
					}
				}
			}
		}
	}

	if (char_->player == TWO_PLAYER) {

		if (char_->m_direction == RIGHT || char_->m_direction == LEFT)
		{
			char_->side_direction = char_->m_direction;
		}
		SpaceManSwitchJump(char_);

		if (char_you->m_is_hit == TRUE)
		{
			SpaceManBlastHit(char_you, blast_status);
		}
		else if (char_->is_ice_hit == TRUE)
		{
			if (char_->m_direction == UP)
			{
				if (char_->side_direction == RIGHT) {
					char_->tu = 0.0f;
					char_->tv = 0.03125f * 22;
				}
				else if (char_->side_direction == LEFT) {
					char_->tu = 0.0f;
					char_->tv = 0.03125f * 23;
				}
			}
			if (char_->m_direction == DOWN)
			{
				if (char_->side_direction == RIGHT) {
					char_->tu = 0.0f;
					char_->tv = 0.03125f * 22;
				}
				else if (char_->side_direction == LEFT) {
					char_->tu = 0.0f;
					char_->tv = 0.03125f * 23;
				}
			}

			if (char_->m_direction == RIGHT) {
				char_->tu = 0.0f;
				char_->tv = 0.03125f * 22;
			}
			else if (char_->m_direction == LEFT) {
				char_->tu = 0.0f;
				char_->tv = 0.03125f * 23;
			}

			char_->fc_ice--;
			if (char_->fc_ice <= 0) 
			{
				char_->is_ice_hit = FALSE;
			}
		}
		else
		{
			if (directx.KeyState[DIK_DOWN] == directx.OFF) {

				if (directx.KeyState[DIK_RIGHT] == directx.ON)
				{
					char_->x += (char_->m_spaceman_speed + char_->m_plus_spaceman_speed);
					char_->m_direction = RIGHT;
					/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					if (char_->m_action == ONE_JUMP || char_->m_action == TWO_JUMP)
					{
						char_->tu = 0.25f;
						char_->tv = 0.03125f * 20;
					}
					else
					{
						char_->tu = 0.0f;
						char_->tv = 0.03125f * 1;
					}
					//draw.Animetion(&fc_right_slide_one, 8, &char_->tu, &char_->tv, 0.25f, 0.0f, 0.0f, 0.03125f * 17, 0.5f, 0.0f);
				}
				else if (directx.KeyState[DIK_LEFT] == directx.ON)
				{
					char_->x -= (char_->m_spaceman_speed + char_->m_plus_spaceman_speed);
					char_->m_direction = LEFT;
					/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					if (char_->m_action == ONE_JUMP || char_->m_action == TWO_JUMP)
					{
						char_->tu = 0.25f;
						char_->tv = 0.03125f * 21;
					}
					else
					{
						char_->tu = 0.0f;
						char_->tv = 0.03125f * 0;
					}
					//draw.Animetion(&fc_left_slide_one, 8, &char_->tu, &char_->tv, 0.25f, 0.0f, 0.0f, 0.03125f * 18, 0.5f, 0.0f);

				}

				SpaceManDash(char_);

				char_->m_fc_push--;

				if (directx.KeyState[DIK_RCONTROL] == directx.PRESS)
				{
					if (char_->m_fc_push <= 0)
					{
						SpaceManPush(char_, char_you, blast_status);
						/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
						if (char_->m_direction == RIGHT && (char_->m_action == ONE_JUMP || char_->m_action == TWO_JUMP))
						{
							char_->tu = 0.5f;
							char_->tv = 0.03125f * 19;
						}
						else if (char_->m_direction == LEFT && (char_->m_action == ONE_JUMP || char_->m_action == TWO_JUMP))
						{
							char_->tu = 0.5f;
							char_->tv = 0.03125f * 4;
						}
						else if (char_->m_direction == RIGHT)
						{
							char_->tu = 0.5f;
							char_->tv =  0.03125f * 1;
						}
						else if (char_->m_direction == LEFT)
						{
							char_->tu = 0.5f;
							char_->tv = 0.03125f * 0;
						}
					}
				}
			}
			if ((directx.KeyState[DIK_UP] == directx.PRESS) && (char_->m_is_call == FALSE))
			{
				char_->m_gravity = -30;
				SpaceManJumpSwitchChange(&char_->m_action);

				char_->m_direction = UP;
			}

			if (char_->m_action == NO_JUMP || char_->m_action == FALL) {
				if (directx.KeyState[DIK_DOWN] == directx.ON)
				{
					char_->m_is_dash = FALSE;
					char_->m_is_guard = TRUE;
					/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					if (char_->side_direction == RIGHT) {
						char_->tu = 0.5f;
						char_->tv = 0.03125f * 15;
					}
					else if (char_->side_direction == LEFT)
					{
						char_->tu = 0.5f;
						char_->tv = 0.03125f * 16;
					}
					char_->m_direction = DOWN;
				}

				
			}else if (directx.KeyState[DIK_DOWN] == directx.RELEASE)
				{
				if (char_->m_action == NO_JUMP || char_->m_action == FALL)
				{
					char_->m_is_guard = FALSE;
					char_->m_is_dash = TRUE;
					if (char_->side_direction == RIGHT)
					{
						char_->tu = 0.0f;
						char_->tv = 0.03125f * 1;
					}
					else if (char_->side_direction == LEFT)
					{
						char_->tu = 0.0f;
						char_->tv = 0.03125f * 0;
					}
				}
			}
			
		}
	}
	Move(char_, char_->save_x, char_->save_y);
}
	


VOID SPACEMAN::Move(CHAR_* char_, FLOAT save_x, FLOAT save_y)
{

	//重力移動
	char_->y += char_->m_gravity;



	//キー入力



	//当たり判定用の処理（毎フレームごとに更新）
	char_->vec_x = save_x - char_->x;
	char_->vec_y = save_y - char_->y;
}
