#pragma once
#include "CAbstractScene.h"
#include"CPlayer.h"

#define D_TITLE_POS_X (360)

class CTitle : public CAbstractScene
{
private:

	int charactar_strImage;

	//画像用変数
	int akabei_font;
	int pinky_font;
	int aosuke_font;
	int guzuta_font;
	int highscore;
	int slash;
	int nickname;
	int oikake;
	int machibuse;
	int kimagure;
	int otoboke;
	int akabei_title;
	int pinky_title;
	int aosuke_title;
	int guzuta_title;
	int esa;

	//タイマー
	int timer;

	//向き
	float angle;

	//パックマンアニメーション
	int pacman[D_PLAYER_IMAGE_MAX] = {};

	//パックマンスピード
	float pacmanx;

	//エネミー
	int enemy[20] = {};		//アカ
	int enemyEyes[4] = {};
	float enemyx;
	bool anim;

	int pacx;
	int teki1x;
	int teki2x;
	int teki3x;
	int teki4x;

	int eye;


public:
	CTitle();
	~CTitle() {}
	//更新
	CAbstractScene* Update()override;
	//描画
	void Draw()const override;
	//当たり判定
	void enemyhit()const;
};

