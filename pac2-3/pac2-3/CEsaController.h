#pragma once
#include"CEsa.h"


#define ESA_IMAGE_MAX 2 //エサ画像の配列の最大数
#define ESA_FIELD_WIDTH 28
#define ESA_FIELD_HEIGHT 31
#define ESA_FIELD_POS_X 370.0f //開始地点
#define ESA_FIELD_POS_Y 70.0f //開始地点


class CEsa;

class CEsaController
{
private:
	CEsa *esa; //エサの数小さいものが240大きいものが4つ

	int esaImages[ESA_IMAGE_MAX];  //エサの画像
	int esaSounds[2];
	
	bool isClear = false;
	


	int esaData[ESA_FIELD_HEIGHT][ESA_FIELD_WIDTH] =
	{
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1},
	{-1, 0,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1, 0,-1,-1, 0,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1, 0,-1},
	{-1, 1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1, 0,-1,-1, 0,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1, 1,-1},
	{-1, 0,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1, 0,-1,-1, 0,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1, 0,-1},
	{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1},
	{-1, 0,-1,-1,-1,-1, 0,-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1, 0,-1,-1,-1,-1, 0,-1},
	{-1, 0,-1,-1,-1,-1, 0,-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1, 0,-1,-1,-1,-1, 0,-1},
	{-1, 0, 0, 0, 0, 0, 0,-1,-1, 0, 0, 0, 0,-1,-1, 0, 0, 0, 0,-1,-1, 0, 0, 0, 0, 0, 0,-1},
	{-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1,-1},
	{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1},
	{-1, 0,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1, 0,-1,-1, 0,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1, 0,-1},
	{-1, 0,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1, 0,-1,-1, 0,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1, 0,-1},
	{-1, 1, 0, 0,-1,-1, 0, 0, 0, 0, 0, 0, 0,-1,-1, 0, 0, 0, 0, 0, 0, 0,-1,-1, 0, 0, 1,-1},
	{-1,-1,-1, 0,-1,-1, 0,-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1, 0,-1,-1, 0,-1,-1,-1},
	{-1,-1,-1, 0,-1,-1, 0,-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1, 0,-1,-1, 0,-1,-1,-1},
	{-1, 0, 0, 0, 0, 0, 0,-1,-1, 0, 0, 0, 0,-1,-1, 0, 0, 0, 0,-1,-1, 0, 0, 0, 0, 0, 0,-1},
	{-1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1},
	{-1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1},
	{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}

	};



public:
	CEsaController();  //コンストラクタ
	~CEsaController();  //デストラクタ
	void Update();
	void Draw()const;
	void HitAction() {};

	void Init(); //初期化処理
	void LoadesaImage();//画像の読込み
	void SetEsa();//エサを配置する関数
	bool GetIsClear() { return isClear; }
	CEsa* GetEsa() { return esa; }
	int GetEsaIndex(int x, int y) { return esaData[y][x]; }

	//デバッグ用
	void DeleteFeed()
	{
		for (int i = 0; i < D_ESA_MAX - 1; i++)
		{
			esa[i].DeleteFeed();
		}
	}
	

};