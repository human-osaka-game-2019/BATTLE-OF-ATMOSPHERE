#ifndef CREATE_H_
#define CREATE_H_

#include <Windows.h>

#include "Character.h"


class ICE
{
public:

	VOID Init_Ice(ITEM_* item);

	VOID ShotIce_Change(CHAR_* char_, ITEM_* item);

	VOID Right_ShotIce(CHAR_* char_, ITEM_* item);

	VOID Left_ShotIce(CHAR_* char_, ITEM_* item);

	VOID Up_ShotIce(CHAR_* char_, ITEM_* item);

	VOID Down_ShotIce(CHAR_* char_, ITEM_* item);










};



#endif