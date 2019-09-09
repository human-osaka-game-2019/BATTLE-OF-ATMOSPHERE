#ifndef HELP_SCENE_H
#define HELP_SCENE_H
#include "DirectX.h"
#include "Main.h"
#include "Draw.h"
class HELP
{
public:
	INT m_scroll_x = 0;
	INT m_scroll_y = 0;
	INT m_scroll_speed = 30;
	BOOL help_front = TRUE;
	BOOL scroll_move = FALSE;

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
