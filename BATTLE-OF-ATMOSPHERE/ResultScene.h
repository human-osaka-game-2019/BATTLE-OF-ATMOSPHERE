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
	
	FLOAT m_result_ui_tu_a = 0.5f;
	FLOAT m_result_ui_tu_b = 0.5f;
	FLOAT m_result_ui_tu_c = 0.5f;

	enum Result_SelectUI_ID
	{
		select_ui_retry,
		select_ui_title,

	};

	Result_SelectUI_ID Result_ID;


};
#endif
