#pragma once
#include "Object.h"
#include"define.h"

#define D_PLAYER_IMAGE_MAX 3

#define D_PLAYER_UP 0
#define D_PLAYER_RIGHT 1
#define D_PLAYER_DOWN 2
#define D_PLAYER_LEFT 3
#define D_PLAYER_ANIM_FPS 5

class CController;
class CPlayer : public CObject
{
private:
	//コントローラ
	CController* controller;
	XINPUT_STATE* keyState;
	//画像ハンドル
	int images[D_PLAYER_IMAGE_MAX] = {};
	//アニメーション用フレーム
	int animTimer;
	
	//移動用変数
	int direction;
	float angle;

	int pacmanDyings[11];

	bool isAlive = FALSE;

	bool checkAnimFlg;

public:
	CPlayer(CController* pController);
	~CPlayer();

	//更新
	void Update()override;
	//描画
	void Draw()const override;
	//当たった時の処理
	void HitAction()override {}

	void Move();
	void MoveStraight();
	void Control();

	void HitActionanim();

	void Respawn();

	bool GetAnimFlg();

	bool GetisAlive();
};

