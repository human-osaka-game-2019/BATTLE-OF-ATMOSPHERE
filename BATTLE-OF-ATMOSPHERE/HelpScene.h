#ifndef HELP_SCENE_H
#define HELP_SCENE_H

#include "../BATTLE-OF-ATMOSPHERE/DirectX.h"
#include "../BATTLE-OF-ATMOSPHERE/Main.h"
#include "../BATTLE-OF-ATMOSPHERE/Draw.h"


class HELP
{
public:

	INT m_pos_x = 0;
	INT m_pos_y = 0;

	INT m_スクロール_speed = 10;




	VOID Help_Scene();



	enum SCENE_PAHSE
	{
		LOAD,
		PROCESSING,
		RELEASES
	};

	HELP::SCENE_PAHSE phase = HELP::LOAD;



private:



	VOID Loading();

	VOID Process();

	VOID Release();


};
#endif






