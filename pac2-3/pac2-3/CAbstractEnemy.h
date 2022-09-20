#pragma once
#include"Object.h"
#include"define.h"
#include"CPlayer.h"

#define D_BLOCK 0
#define D_FLOOR 1
#define D_CROSSPOINT 2
#define D_VALVE 3
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
	CPlayer* player;
	//向き
	int direction;
	//目標座標
	float targetPosX;
	float targetPosY;

	//初期位置 継承先で上書き前提
	float initialPosX = D_ENEMY_ROOM_X;
	float initialPosY = 11 * D_TILE_SIZE;
	int initialDirection = D_DIRECTION_RIGHT;

	//スピード
	float speed = 20.0f / 8.0f * (8.0f / 16.0f);
	//巣の中にいるか
	bool inEnemyroom = true;
	bool isLeaveTheNest = false;
	int leaveStep = 0;
	bool inTheNest_isUp = true;

	//イジケ状態
	int surprisingTime = 60 * 6;
	int surprisingTimer = 0;
	bool isSurprising = false;
	bool isWhite = false;

	//食べられた
	bool isEaten = false;

	//描画用変数
	bool anim;
	int testNums[10] = {};
	int enemyImages[2] = {};
	int enemyEyes[4] = {};
	int surprisingImages[2][2] = {};
	int animTimer = 0;

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
	int attackCycle = 0;

	int restAreaX = 26;
	int restAreaY = 1;

	int floor[D_FIELD_HEIGHT][D_FIELD_WIDTH] =
	{

		/*
		define D_BLOCK 0
		define D_FLOOR 1
		define D_CROSSPOINT 2  交差点
		define D_VALVE 3
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
		{0,0,0,0,0,0,1,0,0,0,0,0,3,0,0,3,0,0,0,0,0,1,0,0,0,0,0,0},
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
		{0,1,0,0,0,0,1,0,0,0,0,0,3,0,0,3,0,0,0,0,0,1,0,0,0,0,1,0},
		{0,1,0,0,0,0,1,0,0,0,0,0,3,0,0,3,0,0,0,0,0,1,0,0,0,0,1,0},
		{0,2,1,2,0,0,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,0,0,2,1,2,0},
		{0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0},
		{0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0},
		{0,2,1,2,1,1,2,0,0,2,1,1,2,0,0,2,1,1,2,0,0,2,1,1,2,1,2,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,2,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,2,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	//通常時のSEと、イジケ状態時のSE
	int neutralSound;//一段階目
	int angerSound;//二段階目
	int furySound;//三段階目
	int wrathSound;//四段階目
	int izikeSound;//イジケ状態
public:
	CAbstractEnemy();
	~CAbstractEnemy();
	void SetPlayerCrass(CPlayer* pPlayer) { player = pPlayer; }

	virtual void Update()override;
	virtual void Draw()const override;
	virtual void HitAction()override;

	void Surprised();

	//当たった時（プレイヤー）
	virtual void HitAction_Player();
	virtual void Init();

	bool GetisSurprising() { return isSurprising; }

	virtual void SetTargetPos()
	{
		if (GetisAttack())
		{
			targetPosX = player->GetX();
			targetPosY = player->GetY();
		}
	}
	bool GetisHit() { return  (!isSurprising && !isEaten) ? true : false; }
	bool GetisAttack() { return (!isSurprising && !isEaten && isAttack) ? true : false; }
	//巣からの解放
	void LeaveTheNest();

protected:
	//画像読み込み
	virtual void LoadImages();
	//移動
	void MoveToTarget();
	void MoveStraight(int onFieldX,int onFieldY);
	void ChangeDirection(int x,int y);
	//波状攻撃
	void AttackInterval();

	void SurprisingMove();
	void ChooseRandomDirection(int x,int y);
	virtual void MoveInEnemyRoom();
	virtual void EatenMove();

	//SEの読込み
	void LoadSounds();
};

