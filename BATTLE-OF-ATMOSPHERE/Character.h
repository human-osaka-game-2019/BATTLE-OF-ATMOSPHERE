#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "../BATTLE-OF-ATMOSPHERE/DirectX.h"
#include "../BATTLE-OF-ATMOSPHERE/Main.h"
#include "../BATTLE-OF-ATMOSPHERE/MapChip.h"

enum JAMP
{
	NO_JAMP,
	ONE_JAMP,
	TWO_JAMP
};

/**
* @brief 自機のステータスのベース
*/
class SPACEMANBASE
{
public:
	INT m_spaceman_speed = 5.0F;		//! 自機の移動速度
	FLOAT m_gravity = 0.2F;				//! 自機にかかる重力(月と同じ)
	FLOAT m_pos_x = 0.0F;				//! 自機のX座標
	FLOAT m_pos_y = 0.0F;				//! 自機のY座標
	FLOAT m_jump_budget = 9.0F;			//! ジャンプの速度
	FLOAT m_spaceman_width = 128.0F;	//! 自機の幅
	FLOAT m_spaceman_height = 256.0F;	//! 自機の高さ

	/**
	* @fn virtual VOID SpaceManMove()
	* @brief 自機の移動用仮想関数
	*/
	virtual VOID SpaceManMove() = 0;

private:

protected:
	INT m_jump = NO_JAMP;				//! ジャンプ状態記憶用変数
	FLOAT m_max_jump_power = 384.0;		//! 自機の最大ジャンプ力
	FLOAT m_coordinate_storing = 0;		//! 現在の座標記憶用変数
	FLOAT m_max_jump_budget = 0;		//! 最大ジャンプ量
	BOOL m_is_call = FALSE;				//! 呼ばれたかどうか判断する用フラグ

};

class SPACEMAN1P :public SPACEMANBASE
{
public:
	VOID SpaceManJump();
	VOID SpaceManMove();
};

#endif // !CHARACTER_H_
