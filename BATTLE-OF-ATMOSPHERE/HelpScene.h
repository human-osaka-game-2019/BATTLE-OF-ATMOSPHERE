#ifndef HELP_SCENE_H
#define HELP_SCENE_H

#include <Windows.h>

class HELP
{
public:

	VOID Help_Scene();

	enum SCENE_PHASE
	{
		LOAD,
		PROCESSING,
		RELEASES
	};

	//リザルトのフェーズの宣言
	HELP::SCENE_PHASE phase = HELP::LOAD;

private:

	VOID Loading();
	VOID Process();
	VOID Release();


};
#endif
