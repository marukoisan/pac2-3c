#pragma once
#include"Object.h"
#include"define.h"

#define D_BLOCK 0
#define D_FLOOR 1
#define D_CROSSPOINT 2
#define D_DISTANCE_MAX D_FIELD_WIDTH * D_FIELD_WIDTH + D_FIELD_HEIGHT * D_FIELD_HEIGHT
#define D_ENEMY_IMAGE_SIZE 32
#define D_SEPARATE_ANGLE 90 //方向を90度ずつで分ける
#define D_ENEMY_ROOM_X 13.0f * D_TILE_SIZE + 10.0f
#define D_ENEMY_ROOM_Y 14.0f * D_TILE_SIZE
#define D_ENEMY_LEAVE_Y 11.0f * D_TILE_SIZE 
#define D_DOOR_X 13
#define D_DOOR_Y 12



class CAbstractEnemy : public CObject
{
protected:
	//向き
	int direction;
	//目標座標
	float targetPosX;
	float targetPosY;

	//スピード
	float speed = 2;
	//巣の中にいるか
	bool inEnemyroom = true;

	//イジケ状態
	int surprisingTime = 60 * 6;
	int surprisingTimer = 0;
	bool isSurprising = false;

	//食べられた
	bool isEaten = false;

	//描画用変数
	bool anim;
	int testNums[10] = {};
	int enemyImages[2] = {};
	int enemyEyes[4] = {};
	int surprisingImages[2][2] = {};

	//波状攻撃用タイマー
	int attackInterval[7] =
	{
		 7 * 60,
		20 * 60,
		 7 * 60,
		20 * 60,
		 5 * 60,
		20 * 60,
		 5 * 60
	};
	//攻撃中か、休息中か
	bool isAttack = false;

	const int REST_AREA_X = 26;
	const int REST_AREA_Y = 1;

	int floor[D_FIELD_HEIGHT][D_FIELD_WIDTH] =
	{

		/*
		define D_BLOCK 0
		define D_FLOOR 1
		define D_CROSSPOINT 2  交差点
		*/

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,2,1,1,1,1,2,1,1,1,1,1,2,0,0,2,1,1,1,1,1,2,1,1,1,1,2,0},
		{0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
		{0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
		{0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
		{0,2,1,1,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,1,1,2,0},
		{0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0},
		{0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0},
		{0,2,1,1,1,1,2,0,0,2,1,1,2,0,0,2,1,1,2,0,0,2,1,1,1,1,2,0},
		{0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,2,1,1,2,1,1,2,1,1,2,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,1,0,1,1,1,1,1,1,0,1,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,2,1,1,2,0,1,1,1,1,1,1,0,2,1,1,2,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,1,0,1,1,1,1,1,1,0,1,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,2,1,1,1,1,1,1,1,1,2,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
		{0,2,1,1,1,1,2,1,1,2,1,1,2,0,0,2,1,1,2,1,1,2,1,1,1,1,2,0},
		{0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
		{0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
		{0,2,1,2,0,0,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,0,0,2,1,2,0},
		{0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0},
		{0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0},
		{0,2,1,2,1,1,2,0,0,2,1,1,2,0,0,2,1,1,2,0,0,2,1,1,2,1,2,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,2,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,2,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
public:
	CAbstractEnemy();
	~CAbstractEnemy();

	virtual void Update()override;
	virtual void Draw()const override;
	virtual void HitAction()override;

	void Surprised();

	//当たった時（プレイヤー）
	void HitAction_Player();

	bool GetisSurprising() { return isSurprising; }

	//ターゲット位置の変更
	virtual void ChangeTargetPos();

	void SetTargetPos(float x, float y)
	{
		targetPosX = x;
		targetPosY = y;
	}
protected:
	//画像読み込み
	void LoadImages();
	//移動
	void MoveToTarget();
	void MoveStraight(int onFieldX,int onFieldY);
	void ChangeDirection(int x,int y);
	//波状攻撃
	void AttackInterval();
	//巣からの解放
	void LeaveTheNest();

};

