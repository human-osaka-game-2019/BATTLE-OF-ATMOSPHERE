#include "Main.h"
#include "Jet.h"

VOID UseJet(JET* jet, CHAR_* char_)
{
	if (jet->m_jet_right == FALSE & jet->m_jet_left == FALSE & jet->m_jet_up == FALSE)
	{
		jet->m_fc_jet = 0;
	}
	else
	{
		jet->m_fc_jet++;
	}

	if (directx.KeyState[DIK_DOWN] == directx.ON)
	{
		jet->m_fc_charge++;
		if (jet->m_fc_charge >= 120)
		{
			jet->m_charge = TRUE;
			jet->m_fc_charge = 0;
		}
	}

	if (jet->m_charge == TRUE)
	{
		if (jet->m_fc_jet >= 0)
		{
			if (directx.KeyState[DIK_RSHIFT] == directx.PRESS)
			{
				switch (char_->m_direction)
				{
				case RIGHT:
					jet->m_jet_right = TRUE;
					break;
				case LEFT:
					jet->m_jet_left = TRUE;
					break;
				case UP:
						jet->m_jet_up = TRUE;
					break;

				}
			}
		}
	}


	if (jet->m_fc_jet <= 80)
	{
		if (jet->m_jet_right == true)
		{
			char_->x += jet->m_jet_speed;
		}

		if (jet->m_jet_left == true)
		{
			char_->x -= jet->m_jet_speed;

		}

		if (jet->m_jet_up == true)
		{
			char_->y -= jet->m_jet_speed;
		}

	}
	if (jet->m_fc_jet > 80)
	{
		jet->m_fc_jet = 0;
		jet->m_charge = false;
		jet->m_jet_right = false;
		jet->m_jet_left = false;
		jet->m_jet_up = false;
	}

}