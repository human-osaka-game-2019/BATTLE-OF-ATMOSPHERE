#ifndef RESULT_SCENE_H
#define RESULT_SCENE_H

#include "../BATTLE-OF-ATMOSPHERE/DirectX.h"
#include "../BATTLE-OF-ATMOSPHERE/Main.h"

class Result {
public:

	void Result_Scene();

	enum SCENE_PHASE {
		LOAD,
		PROCESSING,
		RELEASES
	};

	//リザルトのフェーズの宣言
	Result::SCENE_PHASE Phase = Result::LOAD;




private:

	void Loading();
	void Process();
	void Release();


};
#endif
