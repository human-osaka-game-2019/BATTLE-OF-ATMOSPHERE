﻿#ifndef IMPACT_H_
#define IMPACT_H_

#include <Windows.h>

#include "Character.h"
#include"GameScene.h"
#include"Stage.h"

typedef struct
{
	DIRECTION ice_direction;
	BOOL is_ice_move = FALSE;
	FLOAT x, y = -1000000;//適当な値で初期化
	FLOAT width, height = 96.0f;
}IMPACT_SHOT;

class IMPACT
{
public:

	BOOL IceHitCharCheck(CHAR_ char_, IMPACT_SHOT ice_shot);

	BOOL IceHitBlockCheck(BLOCK block, IMPACT_SHOT ice_shot);

	VOID Init_Ice(ITEM_* item);

	VOID UseIce(CHAR_* char_, IMPACT_SHOT* ice_shot);

	VOID ShotIce_Change(CHAR_* char_, IMPACT_SHOT* ice_shot);

	VOID EvaporatingIce(IMPACT_SHOT* ice_shot);

	VOID Right_ShotIce(CHAR_* char_, IMPACT_SHOT* ice_shot);

	VOID Left_ShotIce(CHAR_* char_, IMPACT_SHOT* ice_shot);

	VOID Up_ShotIce(CHAR_* char_, IMPACT_SHOT* ice_shot);

	VOID Down_ShotIce(CHAR_* char_, IMPACT_SHOT* ice_shot);

	VOID MoveIce(CHAR_* char_, IMPACT_SHOT* ice_shot);

	VOID HitIceChar(CHAR_* char_, IMPACT_SHOT* ice_shot);

	IMPACT_SHOT ice_shot_one = { RIGHT,FALSE };
	IMPACT_SHOT ice_shot_two = { LEFT,FALSE };

};



#endif