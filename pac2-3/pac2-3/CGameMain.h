#pragma once
#include"define.h"
#include "CAbstractScene.h"

#define D_GAMEOVER_POS 21 //マス目
#define D_SCREEN_SIZE_WIDTH 1280
#define D_SCREEN_SIZE_HEIGHT 720

class CTile;
class CField;
class CEsaController;
class CEsa;
class CAbstractEnemy;
class CPlayer;
class CUi;
class CHitPoint;
class CCoffeeBreak;
class CFruit;
class CAkabei;
class CPinky;
class CAosuke;
class CGuzuta;
class CEnemyController;


class CGameMain : public CAbstractScene
{
private:
	CTile** tiles;
	CField* field;
	CEsaController* esaController;
	CEsa* esa;
	CPlayer* player;
	CUi* ui;//uiの奴
	CHitPoint* hitPoint;
	CCoffeeBreak* coffee;
	CFruit* fruit;
	CAkabei* akabei;
	CPinky* pinky;
	CAosuke* aosuke;
	CGuzuta* guzuta;
	CEnemyController* enemyController;

	bool isGameStart;//初回用フラグ
	bool isGameOver;
	bool isPlayMode;
	int startModeTimer;
	int playerAnimTimer;
	int stopTimer;
	int eatenFeedCount;

	int stageLevel = 0;

	//画像用変数
	int gameOverImage; //ゲームオーバー画像
	int readyImage;
	int player_oneImage;

	DIFICULTY level[D_LEVEL_MAX + 1] =
	{
		{0,60 * 6,0,0,4},{1,60 * 5,1,1,4},{1,60 * 4,2,2,3},
		{1,60 * 3,2,2,3},{2,60 * 2,2,2,3},{2,60 * 5,3,2,3},
		{2,60 * 2,3,2,3},{2,60 * 2,3,2,3},{2,60 * 1,4,2,3},
		{2,60 * 5,4,2,3},{2,60 * 2,4,2,3},{2,60 * 1,5,2,3},
		{2,60 * 1,5,2,3},{2,60 * 3,5,2,3},{2,60 * 1,6,2,3},
		{2,60 * 1,6,2,3},{2,60 * 0,6,2,3},{2,60 * 1,6,2,3},
		{2,60 * 0,6,2,3},{2,60 * 0,6,2,3},{2,60 * 0,6,2,3},
		{3,60 * 0,6,2,3}
	};


	//音声用変数
	int playStatSE;
	int neutralSound;//一段階目
public:
	//コンストラクタ
	CGameMain();
	//デストラクタ
	~CGameMain()override;

	//更新
	CAbstractScene* Update()override;
	//描画
	void Draw()const override;

	//当たり判定全般
	void HitCheck();
	void HitCheck_PlayerAndFeed();
	void HitCheck_PlayerAndEnemy();
	void HitCheck_PlayerAndFruit();

	void PlayerControl();
	void LoadSound();
};
