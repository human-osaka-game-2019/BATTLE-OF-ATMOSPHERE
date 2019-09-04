#ifndef COLLISION_H_
#define COLLISION_H_

#include <Windows.h>

#include "Stage.h"
#include "Character.h"

class COLLISION
{
public:

	VOID Hit_Block(BLOCK block, CHAR_* char_);

	VOID Hit_Move(BLOCK block, CHAR_* char_, FLOAT movement_x, FLOAT movement_y);

	VOID Hit_Char(CHAR_* char_one, CHAR_* char_two);

	VOID Hit_Item(CHAR_* char_, ITEM_* item);

};

#endif