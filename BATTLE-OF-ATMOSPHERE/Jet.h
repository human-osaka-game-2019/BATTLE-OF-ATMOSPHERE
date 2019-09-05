#ifndef JET_H_
#define JET_H_


#include "Character.h"

class JET
{
public:
	BOOL m_jet_right = FALSE;
	BOOL m_jet_left = FALSE;
	BOOL m_jet_up = FALSE;
	INT m_fc_jet = 0;
	INT m_fc_charge = 0;
	FLOAT m_jet_speed = 6.0f;
	BOOL m_charge = FALSE;

	VOID UseJet(JET*,CHAR_*);
};

#endif