#pragma once
#include "CAbstractScene.h"

class CPlayer;
class CGameMain : public CAbstractScene
{
private:
	CPlayer* player;

	bool testisLoop = true;
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

