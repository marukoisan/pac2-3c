#pragma once
#include "CAbstractScene.h"
class CGameMain : public CAbstractScene
{
private:
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

