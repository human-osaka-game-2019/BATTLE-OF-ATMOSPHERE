#ifndef RESULT_SCENE_H
#define RESULT_SCENE_H

#include "../BATTLE-OF-ATMOSPHERE/DirectX.h"
#include "../BATTLE-OF-ATMOSPHERE/Main.h"
#include"../BATTLE-OF-ATMOSPHERE/Draw.h"

class RESULT 
{
public:

	VOID Result_Scene();

	enum SCENE_PHASE 
	{
		LOAD,
		PROCESSING,
		RELEASES
	};

	//リザルトのフェーズの宣言
	RESULT::SCENE_PHASE phase = RESULT::LOAD;




private:

	VOID Loading();
	VOID Process();
	VOID Release();


};
#endif
