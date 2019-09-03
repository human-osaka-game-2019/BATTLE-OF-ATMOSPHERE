?�#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <Windows.h>

enum JUMP
{
	FALL,       //! 
	NO_JUMP,	//! ジャンプして�?���?
	ONE_JUMP,	//! 1回ジャンプし�?
	TWO_JUMP	//! 二段ジャンプし�?
};

enum DIRECTION
{
	RIGHT,
	LEFT,
	UP,
	DOWN,
};

enum PLAYER
{
	ONE_PLAYER,
	TWO_PLAYER,
};

enum ITEM
{
	ICE_ITEM,
	CREATE_ITEM,
	GRAVITY_ITEM,
	JET_ITEM,
	IMPACT_ITEM,
	MAX_ITEM,
};

typedef struct
{
	FLOAT x, y, tu, tv, width, height;
	FLOAT vec_x, vec_y;					            //! 今移動して�?��方向を割り�?�?
	JUMP m_action = FALL;				            //! 今�?状�?
	FLOAT m_gravity = 0.0f;				            //! 自機にかかる重�?
	BOOL m_is_dash = FALSE;				            //! 現在ジャンプが可能かど�?��を判断する用フラグ
	BOOL m_is_call = FALSE;				            //! 呼ばれたかど�?��判断する用フラグ
	DIRECTION m_direction;                          //! 向いて�?��方�?
	PLAYER player;                                  //! playerの?�pか２ｐ保存して�?��関数
	// 歩行関係変数
	FLOAT m_spaceman_speed = 5.0F;					//! 自機�?移動�?�度
	// �?�?��ュ関係変数
	FLOAT m_plus_spaceman_speed = 0.0F;				//! �?�?��ュ時�?現在の速度�?速量
	CONST FLOAT m_max_plus_spaceman_power = 5.0F;	//! �?�?��ュ時�?�?大�?速量
	CONST FLOAT m_plus_dash_power = 0.05F;			//! �?�?��ュの�?速度
	FLOAT m_plus_jump_power = 0.0F;					//! �?�?��ュ時�?�上�?したジャンプ量
	FLOAT save_x;
	FLOAT save_y;
	BOOL create;

}CHAR_;

struct ITEM_
{
	FLOAT x, y, tu, tv, width, height;
	INT item_type;
};

/**
* @brief 自機�?ス�??タスのベ�?ス
*/
class SPACEMAN
{
public:



	// 重力関係変数
	CONST FLOAT m_max_gravity = 0.2F;				//! 重力の定数

	//CHAR char_1p = {0.0f,0.0f,100.0f,200.0f,0.0f,0.0f};
	//CHAR cahr_2p;

	// 自機�?座標�?�サイズ関係変数
	///FLOAT m_pos_x = 0.0F;							//! 自機�?X座�?
	///FLOAT m_pos_y = 0.0F;							//! 自機�?Y座�?
	///FLOAT m_spaceman_width = 96.0F;					//! 自機�?�?
	///FLOAT m_spaceman_height = 192.0F;				//! 自機�?高さ

	// ジャンプ関係変数
	//CONST FLOAT m_max_jump_power = 10.0F;			//! ジャンプ�?�度の定数
	//FLOAT m_jump_power = 0.0F;						//! ジャンプ�?速度
	//FLOAT m_plus_jump_power = 0.0F;					//! �?�?��ュ時�?�上�?したジャンプ量



	///BOOL is_hit_block = true;

	///CHAR char_1;
	///CHAR char_2;



	///JUMP m_jump = NO_JUMP;				//! ジャンプ状態記�?用変数



	CHAR_ char_one = { 200,100,0.0f,0.0f,96.f,192.f,0,0,FALL,0.0f,FALSE,FALSE,RIGHT,ONE_PLAYER,5.0f,0.0f,5.0f,0.05f,0.0f };
	CHAR_ char_two = { 200,100,0.0f,0.0f,96.f,192.f,0,0,FALL,0.0f,FALSE,FALSE,LEFT ,TWO_PLAYER,5.0f,0.0f,5.0f,0.05f,0 };

	ITEM_ item[MAX_ITEM];

	VOID SpaceManDash(CHAR_* char_);
	VOID SpaceManMove(CHAR_* char_);

	/**
	* @fn VOID SpaceManRelease()
	* @brief 自機�?ス�??タス解放用関数
	*/
	VOID SpaceManInit(CHAR_* char_);

	/**
	* @fn VOID SpaceManJumpSwitchChange(INT* jump)
	* @param (INT jump) 現在のジャンプ状�?
	* @brief ジャンプ�?タンが押されたときジャンプ状態を�?��替える
	*/
	VOID SpaceManJumpSwitchChange(JUMP* jump);

	/**
	* @fn VOID SpaceManSwitchJump(INT jump)
	* @param (INT jump) 現在のジャンプ状�?
	* @brief 現在のジャンプ状態に応じて処�?��行う関数
	*/
	VOID SpaceManSwitchJump(CHAR_* char_);

	VOID Move(CHAR_* char_, FLOAT save_x, FLOAT save_y);
};

#endif // !CHARACTER_H_

