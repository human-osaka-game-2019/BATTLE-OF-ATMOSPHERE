#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "../BATTLE-OF-ATMOSPHERE/DirectX.h"
#include "../BATTLE-OF-ATMOSPHERE/Main.h"
#include "../BATTLE-OF-ATMOSPHERE/MapChip.h"

/**
* @brief 自機のステータスのベース
*/
class SPACEMANBASE
{
public:
	FLOAT m_spaceman_speed = 5.0F;			//! 自機の移動速度
	FLOAT m_plus_spaceman_speed = 0.0F;

	CONST FLOAT m_max_gravity = 0.2F;		//! 重力の定数
	FLOAT m_gravity = 0.0F;					//! 自機にかかる重力

	FLOAT m_pos_x = 0.0F;					//! 自機のX座標
	FLOAT m_pos_y = 0.0F;					//! 自機のY座標
	FLOAT m_spaceman_width = 96.0F;			//! 自機の幅
	FLOAT m_spaceman_height = 192.0F;		//! 自機の高さ

	CONST FLOAT m_max_jump_power = 10.0F;	//! ジャンプ速度の定数
	FLOAT m_jump_power = 0.0F;				//! ジャンプの速度
	FLOAT m_plus_jump_power = 0.0F;


	enum JAMP
	{
		NO_JAMP,
		ONE_JAMP,
		TWO_JAMP
	};

	/**
	* @fn VOID SpaceManRelease()
	* @brief 自機のステータス解放用関数
	*/
	VOID SpaceManRelease();

	/**
	* @fn virtual VOID SpaceManDash()
	* @brief 自機のダッシュ用仮想関数
	*/
	virtual VOID SpaceManDash() = 0;

	/**
	* @fn virtual VOID SpaceManMove()
	* @brief 自機の移動用仮想関数
	*/
	virtual VOID SpaceManMove() = 0;

private:

protected:
	INT m_jump = NO_JAMP;				//! ジャンプ状態記憶用変数
	FLOAT m_coordinate_storing = 0;		//! 現在の座標記憶用変数
	BOOL m_is_dash = FALSE;				//! 現在ジャンプが可能かどうかを判断する用フラグ
	BOOL m_is_call = FALSE;				//! 呼ばれたかどうか判断する用フラグ
};

class SPACEMAN1P :public SPACEMANBASE
{
public:
	VOID SpaceManJump();
	VOID SpaceManDash();
	VOID SpaceManMove();
};

#endif // !CHARACTER_H_
