#ifndef MAPCHIP_H
#define MAPCHIP_H

#include "../BATTLE-OF-ATMOSPHERE/Main.h"

#include<iostream>
#include<stdio.h>

#define MAP_SIZE_WIDTH (30.f)		// MAPの横幅(値はチップ数)
#define MAP_SIZE_HEIGHT (17.f)		// MAPの縦幅(値はチップ数)
#define MAPCHIP_WIDTH (64.f)		// マップチップの横幅
#define MAPCHIP_HEIGHT (64.f)		// マップチップの縦幅
#define TEXTURE_WIDTH (128.f)       // 読み込んだテクスチャの横幅
#define TEXTURE_HEIGHT (128.f)      // 読み込んだテクスチャの縦幅
#define DRAW_WIDTH (64.f)           // 描画する横幅
#define DRAW_HEIGHT (64.f)          // 描画する縦幅


const INT map_size_width = 30;
const INT map_size_height = 17;

class DRAWMAP {
public:

	struct BLOCK {
		INT chip_id;
		float x, y;
	};

	VOID DrawMapChip(INT map_size_width, INT map_size_height, FLOAT texture_width, FLOAT texture_height, FLOAT mapchip_width, FLOAT mapchip_height, FLOAT draw_width, FLOAT draw_height, FLOAT draw_pos_x, FLOAT draw_pos_y, INT texture, BLOCK** map);

	VOID TexturePrint(INT drawpos_x, INT drawpos_y, INT mapcip_width, INT mapchip_height, FLOAT chip_pos_x, FLOAT chip_pos_y, FLOAT width_num, FLOAT height_num, INT texture);

	DRAWMAP::BLOCK map[map_size_height][map_size_width];
	
	INT init_map[map_size_height][map_size_width]
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};

};
#endif // !MAPCHIP