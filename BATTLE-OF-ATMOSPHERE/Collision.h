#ifndef COLLISION_H_
#define COLLISION_H_

#include <Windows.h>

#include "Stage.h"
#include "Character.h"
#include"DirectX.h"

class COLLISION
{
public:

	VOID HitBlockItem(BLOCK block, ITEMSTATE* item_state);

	VOID Hit_Block(BLOCK block, CHAR_* char_);

	VOID HitWindow(CHAR_* char_);

	VOID Hit_Move(BLOCK block, CHAR_* char_, FLOAT movement_x, FLOAT movement_y);

	VOID Hit_Char(CHAR_* char_one, CHAR_* char_two);

};

#endif