#include "../BATTLE-OF-ATMOSPHERE/MapChip.h"

void DRAWMAP::DrawMapChip(int map_size_width, int map_size_height, float texture_width, float texture_height, float mapchip_width, float mapchip_height, float draw_width, float draw_height, float draw_pos_x, float draw_pos_y, int texture, int** map)
{
	for (int i = 0; i < map_size_height; i++)
	{
		for (int j = 0; j < map_size_width; j++)
		{
			int chip_id = map[i][j];
			if (chip_id == 0)
			{
				continue;
			}

			// テクスチャのサイズとマップチップのサイズから横と縦のチップ数を割り出す
			// (int)g_TextureList[TextureId::MapChip].m_Width       テクスチャのwidth
			//(int)g_TextureList[TextureId::MapChip].m_Height       テクスチャのheight
			//MAPCHIP_WIDTH                                         マップチップの１つのwidth大きさ
			//MAPCHIP_HEIGHT                                        マップチップの１つのheight大きさ
			int width_num = texture_width / mapchip_width;
			int height_num = texture_height / mapchip_height;

			// chip_idからチップのテクスチャ座標を割り出す
			// チップの描画
			//chip_pos_x                                            左上のtuの位置
			//chip_pos_y                                            左上のtvの位置
			//MAPCHIP_WIDTH                                         一マスのwidth大きさ
			//MAPCHIP_HEIGHT                                        一マスのheight大きさ
			float chip_pos_x = (float)(chip_id % width_num) * mapchip_width;
			float chip_pos_y = (float)(chip_id / height_num) * mapchip_height;

			DRAWMAP::textureprint(draw_pos_x + draw_width * j, draw_pos_y + draw_height * i, draw_width, draw_height, chip_pos_x / texture_width, chip_pos_y / texture_height, mapchip_width / texture_width, mapchip_height / texture_height, texture);
		}
	}
}

//マップチップ描画
void DRAWMAP::textureprint(int drawpos_x, int drawpos_y, int mapcip_width, int mapchip_height, float chip_pos_x, float chip_pos_y, float width_num, float height_num, int texture) {

	draw.Draw(drawpos_x, drawpos_y, 0xffffffff, chip_pos_x, chip_pos_y, mapcip_width, mapchip_height, width_num, height_num, texture, 0);

}

