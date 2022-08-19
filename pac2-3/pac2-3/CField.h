#pragma once
#include"Object.h"

#define D_TILE_SIZE 20.0f

class CField : public CObject
{
private:
	int tileImages[30];//タイル画像の総数
	int testTiles[4];
public:
	//コンストラクタ
	CField();
	//デストラクタ
	~CField();

	//更新
	void Update() {};
	//描画
	void Draw()const;
	
	//画像の読み込み
	bool LoadImages();

	void HitAction() {};
};

