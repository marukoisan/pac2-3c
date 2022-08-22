#pragma once
#include "CAbstractScene.h"
class CEnemy;//クラスを定義することで、クラスに入っているものを使うことが出来る
      //参照するときはアロー演算子を使用する
class CGameMain : public CAbstractScene
{
private:
	CEnemy* enemy;//変数というか入れ物を確保している

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

