#ifndef ICE_H_
#define ICE_H_
#include <Windows.h>
#include "Character.h"
#include"GameScene.h"
#include"Stage.h"
typedef struct
{
	DIRECTION ice_direction;
	BOOL is_ice_move = FALSE;
	FLOAT x, y;//適当な値で初期化
	FLOAT width, height;
}ICE_SHOT;
class ICE
{
public:
/**
 * @fn
 * アイスが当たったか当たっていないかを判断する関数
 * @brief アイスの矩形とキャラが当たっているかを判断する
 * @param (char_) キャラクターの情報を渡す
 * @param (ice_shot) アイスの情報を渡す
 * @return BOOL
 * @detail アイスの矩形とのキャラの矩形が当たっていたら、trueを返しほかの時にfalseを返す
 */
	BOOL IceHitCharCheck(CHAR_ char_, ICE_SHOT ice_shot);
	/**
 * @fn
 * アイスが当たったか当たっていないかを判断する関数
 * @brief アイスの矩形とブロックが当たっているかを判断する
 * @param (block) ブロックの情報を渡す
 * @param (ice_shot) アイスの情報を渡す
 * @return BOOL
 * @detail アイスの矩形とのブロックの矩形が当たっていたら、trueを返しほかの時にfalseを返す
 */
	BOOL IceHitBlockCheck(BLOCK block, ICE_SHOT ice_shot);
	/**
 * @fn
 * アイスを初期化
 * @brief アイスの情報を初期化
 * @param (ice_shot) アイスの情報を渡す
 * @detail アイスのx,y,width,heightを初期化する
 */
	VOID Init_Ice(ICE_SHOT* ice_shot);
	/**
 * @fn
 * 
 * @brief アイスを使う時の関数
 * @param (char_) キャラクターの情報を渡す
 * @param (ice_shot) アイスの情報を渡す
 * @detail 
 */
	VOID UseIce(CHAR_* char_, ICE_SHOT* ice_shot);
/**
 * @fn
 * アイスを出す方向判断する関数
 * @brief 向いている方向からアイスを発射する方向を決める関数
 * @param (chra_) キャラクターの情報を渡す
 * @param (ice_shot) アイスの情報を渡す
 * @detail キャラのm_directionで方向を割り出し呼び出す関数を変える
 */
	VOID ShotIce_Change(CHAR_* char_, ICE_SHOT* ice_shot);
/**
* @fn
* 
* @brief 
* @param (char_) キャラクターの情報を渡す
* @param (ice_shot) アイスの情報を渡す
* @sa 参照すべき関数を書けばリンクが貼れる
* @detail 
*/
	VOID EvaporatingIce(CHAR_* char_, ICE_SHOT* ice_shot);
/**
 * @fn
 * 右にアイスを発射する
 * @brief アイスを右側に発射する
 * @param (char_) キャラの情報を渡す
 * @param (ice_shot) アイスの情報渡す
 * @sa VOID ShotIce_Change(CHAR_* char_, ICE_SHOT* ice_shot);
 * @detail 
 */
	VOID Right_ShotIce(CHAR_* char_, ICE_SHOT* ice_shot);
/**
 * @fn
 * 左にアイスを発射する
 * @brief アイスを左側に発射する
 * @param (char_) キャラの情報を渡す
 * @param (ice_shot) アイスの情報渡す
 * @sa VOID ShotIce_Change(CHAR_* char_, ICE_SHOT* ice_shot);
 * @detail 
 */
	VOID Left_ShotIce(CHAR_* char_, ICE_SHOT* ice_shot);
/**
 * @fn
 * 上にアイスを発射する
 * @brief アイスを上側に発射する
 * @param (char_) キャラの情報を渡す
 * @param (ice_shot) アイスの情報渡す
 * @sa VOID ShotIce_Change(CHAR_* char_, ICE_SHOT* ice_shot);
 * @detail
 */
	VOID Up_ShotIce(CHAR_* char_, ICE_SHOT* ice_shot);
/**
 * @fn
 * 下にアイスを発射する
 * @brief アイスを下側に発射する
 * @param (char_) キャラの情報を渡す
 * @param (ice_shot) アイスの情報渡す
 * @sa VOID ShotIce_Change(CHAR_* char_, ICE_SHOT* ice_shot);
 * @detail 
 */
	VOID Down_ShotIce(CHAR_* char_, ICE_SHOT* ice_shot);
/**
* @fn
* 
* @brief 
* @param (char_) キャラの情報を渡す
* @param (ice_shot) アイスの情報渡す
* @return 戻り値の説明
* @sa 参照すべき関数を書けばリンクが貼れる
* @detail 
*/
	VOID MoveIce(CHAR_* char_, ICE_SHOT* ice_shot);
	
/**
* @fn
* キャラクターとアイスが当たったの関数
* @brief キャラクターとアイスが当たった時の関数
* @param (char_) キャラクターの情報を渡す
* @param (ice_shot) アイスの情報を渡す
* @sa 参照すべき関数を書けばリンクが貼れる
* @detail 
*/
	VOID HitIceChar(CHAR_* char_, ICE_SHOT* ice_shot);

	ICE_SHOT ice_shot_one = { RIGHT,FALSE,100000,100000,96.0f,96.0f };

	ICE_SHOT ice_shot_two = { LEFT,FALSE,-100000,-100000,96.0f,96.0f };
};

#endif