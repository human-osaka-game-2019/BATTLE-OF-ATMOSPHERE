#ifndef CREATE_H_
#define CREATE_H_


#include <Windows.h>

#include "Character.h"
#include "Stage.h"


class CREATE
{
public:

	VOID MakeBlock_Change(CHAR_* char_, BLOCK* block, INT ite);



	VOID Right_MakeBlock(CHAR_* char_, BLOCK* block, INT i);

	VOID Left_MakeBlock(CHAR_* char_, BLOCK* block, INT i);

	VOID Up_MakeBlock(CHAR_* char_, BLOCK* block, INT i);

	VOID Down_MakeBlock(CHAR_* char_, BLOCK* block, INT i);





};



#endif