#pragma once
#include"define.h"
#include "CAbstractScene.h"

#define D_GAMEOVER_POS 21 //マス目
#define D_SCREEN_SIZE_WIDTH 1280
#define D_SCREEN_SIZE_HEIGHT 720

class CField;
class CEsaController;
class CEsa;
class CAbstractEnemy;
class CPlayer;
class CGameMain : public CAbstractScene
{
private:
	CField* field;
	CEsaController* esaController;
	CEsa* esa;
	CAbstractEnemy* enemy;
	CPlayer* player;
	bool isPlayMode;

	//画像用変数
	int gameOverImage; //ゲームオーバー画像
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
};

