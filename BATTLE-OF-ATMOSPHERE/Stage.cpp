#include "../BATTLE-OF-ATMOSPHERE/Stage.h"
#include "../BATTLE-OF-ATMOSPHERE/MapChip.h"

DRAWMAP drawmap;

VOID STAGE::InitStage()
{
	for (INT i = 0; i < map_size_height; i++) {
		for (INT j = 0; j < map_size_width; j++) {
			drawmap.map[i][j].chip_id = drawmap.init_map[i][j];
		}
	}

	DRAWMAP::BLOCK* array_map[map_size_height];

	for (INT i = 0; i < map_size_height;i++) {
		array_map[i] = drawmap.map[i] ;
	}

	drawmap.DrawMapChip(MAP_SIZE_WIDTH, MAP_SIZE_HEIGHT, TEXTURE_WIDTH, TEXTURE_HEIGHT, MAPCHIP_WIDTH, MAPCHIP_HEIGHT, DRAW_WIDTH, DRAW_HEIGHT, 0.0f, 0.0f, GAME_STAGE, array_map);
	
}

VOID STAGE::MakeStage() 
{




}

VOID STAGE::FallBlock() 
{





}