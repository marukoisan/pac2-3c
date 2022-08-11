#pragma once
#include "CAbstractScene.h"
class CGameMain : public CAbstractScene
{
private:

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

