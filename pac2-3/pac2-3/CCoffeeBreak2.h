#pragma once
#include"CPlayer.h"

class CCoffeeBreak2
{
private:
	int AnimTimer = 0;
	int images[D_PLAYER_IMAGE_MAX] = {};
	float angle;
	int enemyImages[2] = {};
	int enemyEyes[4] = {};
	bool anim;
	int bou;		//棒画像用変数
	int enemy;		//敵画像用変数
	int enemy2;		//敵画像用変数
	int enemy3;		//敵画像用変数
	float enemyx;		//敵座標
	float playerx;	//プレイヤー座標

	int coffeesound;	//サウンド用変数

public:
	CCoffeeBreak2();
	~CCoffeeBreak2() {}
	void CoffeeBreakM2();
	int playsound();

};
