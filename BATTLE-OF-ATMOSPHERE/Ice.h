#ifndef ICE_H_
#define ICE_H_
#include <Windows.h>
#include "Character.h"
#include"GameScene.h"
#include"Stage.h"
typedef struct
{
	DIRECTION ice_direction;
	BOOL is_ice_move = FALSE;
	FLOAT x, y;//適当な値で初期化
	FLOAT width, height;
}ICE_SHOT;
class ICE
{
public:
	BOOL IceHitCharCheck(CHAR_ char_, ICE_SHOT ice_shot);
	BOOL IceHitBlockCheck(BLOCK block, ICE_SHOT ice_shot);
	VOID Init_Ice(ITEM_* item, ICE_SHOT* ice_shot);
	VOID UseIce(CHAR_* char_, ICE_SHOT* ice_shot);
	VOID ShotIce_Change(CHAR_* char_, ICE_SHOT* ice_shot);
	VOID EvaporatingIce(CHAR_* char_, ICE_SHOT* ice_shot);
	VOID Right_ShotIce(CHAR_* char_, ICE_SHOT* ice_shot);
	VOID Left_ShotIce(CHAR_* char_, ICE_SHOT* ice_shot);
	VOID Up_ShotIce(CHAR_* char_, ICE_SHOT* ice_shot);
	VOID Down_ShotIce(CHAR_* char_, ICE_SHOT* ice_shot);
	VOID MoveIce(CHAR_* char_, ICE_SHOT* ice_shot);
	VOID HitIceChar(CHAR_* char_, ICE_SHOT* ice_shot);
	ICE_SHOT ice_shot_one = { RIGHT,FALSE,100000,100000,96.0f,96.0f };
	ICE_SHOT ice_shot_two = { LEFT,FALSE,-100000,-100000,96.0f,96.0f };
};
#endif