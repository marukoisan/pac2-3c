#pragma once
#include "CAbstractScene.h"

class CField;
class CGameMain : public CAbstractScene
{
private:
	CField* field;

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

