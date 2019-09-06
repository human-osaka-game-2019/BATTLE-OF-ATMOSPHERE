#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <Windows.h>

enum JUMP
{
	FALL,       //! 
	NO_JUMP,	//! �W�����v���Ă��Ȃ�
	ONE_JUMP,	//! 1��W�����v����
	TWO_JUMP	//! ��i�W�����v����
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
	FLOAT x, y;
	FLOAT blast_power_x, blast_power_y = 0.0f;
	FLOAT size;
}BLAST_STATUS;

typedef struct
{
	FLOAT x, y, tu, tv, width, height;
	FLOAT vec_x, vec_y;                              //! ���ړ����Ă������������o��
	JUMP m_action = FALL;                            //! ���̏��
	FLOAT m_gravity = 0.0f;                          //! ���@�ɂ�����d��
	BOOL m_is_dash = FALSE;                          //! ���݃W�����v���\���ǂ����𔻒f����p�t���O
	BOOL m_is_call = FALSE;                          //! �Ă΂ꂽ���ǂ������f����p�t���O
	BOOL m_is_guard = FALSE;						 //! ���݃K�[�h�����ǂ����𔻒f����p�t���O
	BOOL m_is_hit = FALSE;
	DIRECTION m_direction;                           //! �����Ă������
	PLAYER player;                                   //! player�̂Pp���Q���ۑ����Ă���֐�
	// ���s�֌W�ϐ�
	FLOAT m_spaceman_speed = 5.0F;                   //! ���@�̈ړ����x
	// �_�b�V���֌W�ϐ�
	FLOAT m_plus_spaceman_speed = 0.0F;              //! �_�b�V�����̌��݂̑��x������
	FLOAT m_plus_jump_power = 0.0F;                  //! �_�b�V�����A�㏸�����W�����v��
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
* @brief ���@�̃X�e�[�^�X�̃x�[�X
*/
class SPACEMAN
{
public:

	CONST FLOAT m_max_plus_spaceman_power = 5.0F;    //! �_�b�V�����̍ő������
	CONST FLOAT m_plus_dash_power = 0.05F;           //! �_�b�V���̉����x

	// ���s�֌W�ϐ�
	CONST FLOAT m_max_gravity = 0.2F;				//! 重力の定数

	//CHAR char_1p = {0.0f,0.0f,100.0f,200.0f,0.0f,0.0f};
	//CHAR cahr_2p;

	// ���@�̍��W�A�T�C�Y�֌W�ϐ�
	///FLOAT m_pos_x = 0.0F;							//! 自機�?X座�?
	///FLOAT m_pos_y = 0.0F;							//! 自機�?Y座�?
	///FLOAT m_spaceman_width = 96.0F;					//! 自機�?�?
	///FLOAT m_spaceman_height = 192.0F;				//! 自機�?高さ

	//CONST FLOAT m_max_jump_power = 10.0F;			//! ジャンプ�?�度の定数
	//FLOAT m_jump_power = 0.0F;						//! ジャンプ�?速度
	//FLOAT m_plus_jump_power = 0.0F;					//! �?�?��ュ時�?�上�?したジャンプ量



	///BOOL is_hit_block = true;

	///CHAR char_1;
	///CHAR char_2;



	///JUMP m_jump = NO_JUMP;			

	BLAST_STATUS blast_one = { 0,0,0,0,96.0f };
	BLAST_STATUS blast_two = { 0,0,0,0,96.0f };

	CHAR_ char_one = { 200,100,0.0f,0.0f,96.f,192.f,0,0,FALL,0.0f,FALSE,FALSE,FALSE,FALSE,RIGHT,ONE_PLAYER,5.0f,0.0f,0.0f};
	CHAR_ char_two = { 200,100,0.0f,0.0f,96.f,192.f,0,0,FALL,0.0f,FALSE,FALSE,FALSE,FALSE,LEFT ,TWO_PLAYER,5.0f,0.0f,0};

	ITEM_ item[MAX_ITEM];

	/**
	* @fn VOID SpaceManRelease()
	*/
	VOID SpaceManInit(CHAR_* char_);

	BOOL BlastHitCheck(CHAR_ char_, BLAST_STATUS blast_status);

	/**
	* @fn VOID SpaceManPush(CHAR_* char_me, CHAR_* char_you, BLAST_STATUS* blast_status)
	* @brief
	*/
	VOID SpaceManPush(CHAR_* char_me, CHAR_* char_you, BLAST_STATUS* blast_status);

	/**
	* @fn VOID SpaceManBlastHit(CHAR_* char_, BLAST_STATUS* blast_status)
	* @brief �����o���ꂽ�i������΂����j�Ƃ��̏���
	*/
	VOID SpaceManBlastHit(CHAR_* char_, BLAST_STATUS* blast_status);

	/**
	* @fn VOID SpaceManDash(CHAR_ char_, PLAYER player)
	*/
	VOID SpaceManDash(CHAR_* char_);
	/**
	* @fn VOID SpaceManMove(CHAR_* char_, PLAYER player)
	* @param PLAYER player 1P��2P���𔻒f���Ă���
	*/
	VOID SpaceManMove(CHAR_* char_, CHAR_* char_you, BLAST_STATUS* blast_status);

	/**
	* @fn VOID SpaceManJumpSwitchChange(INT* jump)
	* @param (INT jump) ���݂̃W�����v���
	* @brief �W�����v�{�^���������ꂽ�Ƃ��W�����v��Ԃ�؂�ւ���
	*/
	VOID SpaceManJumpSwitchChange(JUMP* jump);

	/**
	* @fn VOID SpaceManSwitchJump(INT jump)
	* @param (CHAR_* char_) ���݂̃W�����v���
	* @brief ���݂̃W�����v��Ԃɉ����ď������s���֐�
	*/
	VOID SpaceManSwitchJump(CHAR_* char_);

	VOID Move(CHAR_* char_, FLOAT save_x, FLOAT save_y);
};

#endif // !CHARACTER_H_

