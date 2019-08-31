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

	// 歩行関係変数
	FLOAT m_spaceman_speed = 5.0F;					//! 自機の移動速度

	// 重力関係変数
	CONST FLOAT m_max_gravity = 0.2F;				//! 重力の定数
	FLOAT m_gravity = 0.0F;							//! 自機にかかる重力

	// 自機の座標、サイズ関係変数
	FLOAT m_spaceman_pos_x = 0.0F;							//! 自機のX座標
	FLOAT m_spaceman_pos_y = 0.0F;							//! 自機のY座標
	FLOAT m_spaceman_width = 96.0F;					//! 自機の幅
	FLOAT m_spaceman_height = 192.0F;				//! 自機の高さ

	// ジャンプ関係変数
	CONST FLOAT m_max_jump_power = 10.0F;			//! ジャンプ速度の定数
	FLOAT m_jump_power = 0.0F;						//! ジャンプの速度
	FLOAT m_plus_jump_power = 0.0F;					//! ダッシュ時、上昇したジャンプ量

	// ダッシュ関係変数
	FLOAT m_plus_spaceman_speed = 0.0F;				//! ダッシュ時の現在の速度加速量
	CONST FLOAT m_max_plus_spaceman_power = 5.0F;	//! ダッシュ時の最大加速量
	CONST FLOAT m_plus_dash_power = 0.05F;			//! ダッシュの加速度



	enum JUMP
	{
		NO_JUMP,	//! ジャンプしていない
		ONE_JUMP,	//! 1回ジャンプした
		TWO_JUMP	//! 2回ジャンプした
	};

	/**
	* @fn VOID SpaceManJumpSwitchChange(JUMP jump)
	* @param (JUMP jump) 現在のジャンプ状態
	* @brief ジャンプボタンが押されたとき次のジャンプ状態を返す
	*/
	JUMP SpaceManJumpSwitchChange(JUMP jump);

	VOID SpaceManJump();

	/**
	* @fn VOID SpaceManSwitchJump(INT jump)
	* @param (INT jump) 現在のジャンプ状態
	* @brief 現在のジャンプ状態に応じて処理を行う関数
	*/
	VOID SpaceManSwitchJump(JUMP jump);

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

protected:
	JUMP m_jump = NO_JUMP;				//! ジャンプ状態記憶用変数
	BOOL m_is_dash = FALSE;				//! 現在ジャンプが可能かどうかを判断する用フラグ
	BOOL m_is_call = FALSE;				//! 呼ばれたかどうか判断する用フラグ
};

class SPACEMANONE :public SPACEMANBASE
{
public:
	VOID SpaceManDash();
	VOID SpaceManMove();
};

class SPACEMANTWO :public SPACEMANBASE
{
public:
	FLOAT m_spaceman_pos_x = 500;
	VOID SpaceManDash();
	VOID SpaceManMove();
};

#endif // !CHARACTER_H_
