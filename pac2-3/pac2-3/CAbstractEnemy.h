#pragma once
#include"Object.h"
#include"define.h"

#define D_BLOCK 0
#define D_FLOOR 1
#define D_CROSSPOINT 2
#define D_DISTANCE_MAX D_FIELD_WIDTH * D_FIELD_WIDTH + D_FIELD_HEIGHT * D_FIELD_HEIGHT
#define D_ENEMY_IMAGE_SIZE 32
#define D_SEPARATE_ANGLE 90 //方向を90度ずつで分ける

class CAbstractEnemy : public CObject
{
protected:
	//向き
	int direction;
	//目標座標
	int targetPosX;//MAX:27,min:0
	int targetPosY;	//MAX:30,min:0

	//スピード
	int speed = 0;
	//攻撃中か、休息中か
	bool isAttack = false;
	//巣の中にいるか
	bool inEnemyroom = true;

	//描画用変数
	bool anim;
	int testNums[10] = {};
	int enemyImages[2] = {};
	int enemyEyes[4] = {};

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
		{0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,2,1,1,2,0,0,0,0,0,0,0,0,2,1,1,2,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
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


private:
	//移動
	void MoveToTarget();
	void MoveStraight(int onFieldX,int onFieldY);
	void ChangeDirection(int x,int y);
};

