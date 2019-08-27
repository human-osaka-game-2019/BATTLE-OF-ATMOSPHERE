#include "../BATTLE-OF-ATMOSPHERE/Stage.h"
#include "../BATTLE-OF-ATMOSPHERE/MapChip.h"

//DRAWMAP drawmap;
//DRAW draw;


VOID STAGE::InitStage()
{
	/*
	for (INT i = 0; i < map_size_height; i++) {
		for (INT j = 0; j < map_size_width; j++) {
			drawmap.map[i][j].chip_id = drawmap.init_map[i][j];
		}
	}

	DRAWMAP::BLOCK* array_map[map_size_height];

	for (INT i = 0; i < map_size_height;i++) {
		array_map[i] = drawmap.map[i];
	}

	drawmap.DrawMapChip(MAP_SIZE_WIDTH, MAP_SIZE_HEIGHT, TEXTURE_WIDTH, TEXTURE_HEIGHT, MAPCHIP_WIDTH, MAPCHIP_HEIGHT, DRAW_WIDTH, DRAW_HEIGHT, 0.0f, 0.0f, GAME_STAGE, array_map);
	*/

	for (int i = 0; i < BLOCK_QUANTITY; i++)
	{
		block[i].x = -BLOCK_SIZE;
		block[i].y = 0.0f;
	}

	for (int i = 0; i < 5; i++) {
		block[i].x = (6 + i) * BLOCK_SIZE;
		block[i].y = 4 * BLOCK_SIZE;
	}

	for (int i = 0; i < 11; i++) {
		block[i + 5].x = (3 + i) * BLOCK_SIZE;
		block[i + 5].y = 8 * BLOCK_SIZE;
	}
}

VOID STAGE::MakeStage() 
{




}


VOID STAGE::ScrollBlock(BLOCK* block)
{	
	block->y += SCROLL_SPEED_BLOCK;
}


VOID STAGE::FallBlock() 
{




}

VOID STAGE::DrawBlock(BLOCK block)
{
	draw.Draw(block.x,block.y,0xffffffff,block.tu,block.tv,BLOCK_SIZE,BLOCK_SIZE,128.f/248.f, 128.f/248.f,1,0);
}