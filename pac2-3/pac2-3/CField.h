#pragma once
#include"Object.h"

#define D_TILE_SIZE 20.0f
#define D_TILE_IMAGE_MAX 27
#define D_FIELD_WIDTH 28
#define D_FIELD_HEIGHT 31

class CField : public CObject
{
private:
	int tileImages[D_TILE_IMAGE_MAX];//タイル画像の総数
	int testImageIndex;

	const int FEILD_DATA[D_FIELD_HEIGHT][D_FIELD_HEIGHT] =
	{
		{04,18,18,18,18,18,18,18,18,18,18,18,18,12,13,18,18,18,18,18,18,18,18,18,18,18,18,05},
		{},
		{},
		{},
		{},
		{}
		
	};

public:
	//コンストラクタ
	CField();
	//デストラクタ
	~CField();

	//更新
	void Update();
	//描画
	void Draw()const;
	
	//画像の読み込み
	void LoadImages();

	void HitAction() {};
};

