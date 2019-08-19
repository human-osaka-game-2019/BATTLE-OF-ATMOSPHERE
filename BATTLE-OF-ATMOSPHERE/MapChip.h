#ifndef MAPCHIP_H
#define MAPCHIP_H



#include "../BATTLE-OF-ATMOSPHERE/Main.h"

#include<iostream>
#include<stdio.h>

class DRAWMAP {
public:

	void DrawMapChip(int map_size_width, int map_size_height, float texture_width, float texture_height, float mapchip_width, float mapchip_height, float draw_width, float draw_height, float draw_pos_x, float draw_pos_y, int texture, int** map);

	void textureprint(int drawpos_x, int drawpos_y, int mapcip_width, int mapchip_height, float chip_pos_x, float chip_pos_y, float width_num, float height_num, int texture);

	int map[31][28];

};
#endif // !MAPCHIP