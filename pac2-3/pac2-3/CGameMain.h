#pragma once
#include"CAbstractScene.h"
class CGameMain : public CAbstractScene
{
public:
	//コンストラクタ
	CGameMain() {}
	//デストラクタ
	~CGameMain() {}

	//更新
	CAbstractScene* Update()override;
	//描画
	void Draw()const override;
};

