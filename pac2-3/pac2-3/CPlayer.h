#pragma once
#include "Object.h"
#include"define.h"

#define D_PLAYER_IMAGE_MAX 3

#define D_PLAYER_UP 0
#define D_PLAYER_RIGHT 1
#define D_PLAYER_DOWN 2
#define D_PLAYER_LEFT 3
#define D_PLAYER_ANIM_FPS 5

class CPlayer : public CObject
{
private:
	int images[D_PLAYER_IMAGE_MAX];

	int animTimer;
	
	int direction;
	float angle;

public:
	CPlayer();
	~CPlayer();

	//更新
	void Update()override;
	//描画
	void Draw()const override;
	//当たった時の処理
	void HitAction()override {}

	void Move();
	void MoveStraight();
};

