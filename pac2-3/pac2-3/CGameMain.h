#pragma once
#include "CAbstractScene.h"

#define D_GAMEOVER_POS 21 //マス目
#define D_MASS_SIZE 20
#define D_SCREEN_SIZE_WIDTH 1280
#define D_SCREEN_SIZE_HEIGHT 720

class CField;
class CGameMain : public CAbstractScene
{
private:
	CField* field;
	//プレイモードかどうか　true：プレイモード　false：スタートモード
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
};

