#pragma once
#include"Object.h"
#define ESA_IMAGE_ORIGINNL 100.0
#define ESA_IMAGE_NEWLY 20.0


class CEsa : public CObject
{
private:
	int esa;//小さいエサ用の変数
	int Bigesa;//大きいエサ用の変数
	//座標
	float x;
	float y;
	//縦横
	float height;
	float width;
public:
	CEsa();//コンストラクタ
	~CEsa();//デストラクタ
	void Update() {};
	void Draw()const;
	void HitAction() {};
	void Init();//変数の初期化
	void LoadesaImage();//画像の読込み
};

