#include "Create.h"



VOID CREATE::MakeBlock_Change(CHAR_* char_, BLOCK* create_block, INT ite)
{

	char_->create = true;


	switch (char_->m_direction)
	{
	case RIGHT:

		Right_MakeBlock(char_, create_block, ite);

		break;

	case LEFT:

		Left_MakeBlock(char_, create_block, ite);

		break;

	case UP:

		Up_MakeBlock(char_, create_block, ite);

		break;

	case DOWN:

		Down_MakeBlock(char_, create_block, ite);

		break;
	}





}

VOID CREATE::Right_MakeBlock(CHAR_* char_, BLOCK* block, INT i)
{
	block->x = char_->x + 96 * 2;
	block->y = char_->y - 96 + 96 * i;
}

VOID CREATE::Left_MakeBlock(CHAR_* char_, BLOCK* block, INT i)
{
	block->x = char_->x - 96 * 2;
	block->y = char_->y - 96 + 96 * i;
}

VOID CREATE::Up_MakeBlock(CHAR_* char_, BLOCK* block, INT i)
{
	block->x = char_->x - 96 + 96 * i;
	block->y = char_->y - 96 * 2;
}

VOID CREATE::Down_MakeBlock(CHAR_* char_, BLOCK* block, INT i)
{
	block->x = char_->x - 96 + 96 * i;
	block->y = char_->y + char_->height + 96;
}