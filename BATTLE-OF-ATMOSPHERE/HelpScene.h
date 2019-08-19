#ifndef HELP_SCENE_H
#define HELP_SCENE_H

#include "../BATTLE-OF-ATMOSPHERE/DirectX.h"
#include "../BATTLE-OF-ATMOSPHERE/Main.h"

class HELP {
public:

	void Help_Scene();

	enum SCENE_PHASE {
		LOAD,
		PROCESSING,
		RELEASES
	};

	//リザルトのフェーズの宣言
	HELP::SCENE_PHASE phase = HELP::LOAD;

private:

	void Loading();
	void Process();
	void Release();


};
#endif
