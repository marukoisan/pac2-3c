#pragma once
#include "CAbstractScene.h"

class CPlayer;
class CHitPoint;
class CGameMain : public CAbstractScene
{
private:
	CPlayer* player;
	CHitPoint* hitPoint;

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

