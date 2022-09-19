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
class CFruit;
class CAkabei;

class CGameMain : public CAbstractScene
{
private:
	CTile** tiles;
	CField* field;
	CEsaController* esaController;
	CEsa* esa;
	CAkabei* akabei;
	CPlayer* player;
	CUi* ui;//uiの奴
	CHitPoint* hitPoint;
	CFruit* fruit;


	bool isGameStart;//初回用フラグ
	bool isGameOver;
	bool isPlayMode;
	int startModeTimer;
	int playerAnimTimer;
	int stopTimer;

	//画像用変数
	int gameOverImage; //ゲームオーバー画像
	int readyImage;
	int player_oneImage;
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
};

