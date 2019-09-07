﻿#include "Main.h"
#include "Jet.h"

VOID JET::UseJet(CHAR_* char_)
{

	if (char_->player == ONE_PLAYER)
	{
		if (directx.KeyState[DIK_S] == directx.ON)
		{
			char_->m_fc_charge++;
			if (char_->m_fc_charge >= 120)
			{
				char_->m_charge = TRUE;
				char_->m_fc_charge = 0;
			}
		}

	}
	else if (char_->player == TWO_PLAYER)
	{
		if (directx.KeyState[DIK_DOWN] == directx.ON)
		{
			char_->m_fc_charge++;
			if (char_->m_fc_charge >= 120)
			{
				char_->m_charge = TRUE;
				char_->m_fc_charge = 0;
			}
		}
	}

	if (char_->m_charge == TRUE)
	{
		if (char_->m_fc_jet >= 0)
		{
			if (char_->player == ONE_PLAYER) {
				if (directx.KeyState[DIK_LSHIFT] == directx.PRESS)
				{
					switch (char_->m_direction)
					{
					case RIGHT:
						char_->m_jet_right = TRUE;
						char_->m_jet_speed = 20.0f;
						break;
					case LEFT:
						char_->m_jet_left = TRUE;
						char_->m_jet_speed = 20.0f;
						break;
					case UP:
						char_->m_jet_up = TRUE;
						char_->m_jet_speed = 30.0f;
						break;
					}
				}
			}
			else if (char_->player == TWO_PLAYER)
			{
				if (directx.KeyState[DIK_RSHIFT] == directx.PRESS)
				{
					switch (char_->m_direction)
					{
					case RIGHT:
						char_->m_jet_right = TRUE;
						char_->m_jet_speed = 20.0f;
						break;
					case LEFT:
						char_->m_jet_left = TRUE;
						char_->m_jet_speed = 20.0f;
						break;
					case UP:
						char_->m_jet_up = TRUE;
						char_->m_jet_speed = 30.0f;
						break;
					}
				}
			}
		}
	}

	if (char_->m_jet_right == FALSE && char_->m_jet_left == FALSE && char_->m_jet_up == FALSE)
	{
		char_->m_fc_jet = 0;
	}
	else
	{
		char_->m_fc_jet++;
	}


	if (char_->m_fc_jet < 80)
	{

		if (char_->m_jet_right == TRUE)
		{
			char_->m_jet_speed -= 0.1f;
			char_->x += char_->m_jet_speed;
			char_->y -= char_->m_gravity;
		}

		if (char_->m_jet_left == TRUE)
		{
			char_->m_jet_speed -= 0.1f;
			char_->x -= char_->m_jet_speed;
			char_->y -= char_->m_gravity;
		}

		if (char_->m_jet_up == TRUE)
		{
			char_->m_jet_speed -= 0.1f;
			char_->y -= char_->m_jet_speed;
		}

	}
	if (char_->m_fc_jet >= 80)
	{
		char_->m_fc_jet = 0;
		char_->m_gravity = 0;
		char_->m_charge = false;
		char_->m_jet_right = false;
		char_->m_jet_left = false;
		char_->m_jet_up = false;
	}

}