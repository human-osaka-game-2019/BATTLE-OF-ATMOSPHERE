#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "../BATTLE-OF-ATMOSPHERE/DirectX.h"
#include "../BATTLE-OF-ATMOSPHERE/Main.h"
#include "../BATTLE-OF-ATMOSPHERE/MapChip.h"


class Game {
public:

	void Game_Scene();

	void Loading();
	void Process();
	void Release();

	enum SCENE_PAHSE {
		LOAD,
		PROCESSING,
		RELEASES
	};

};
#endif
