#pragma once
#include"Object.h"
#define ESA_IMAGE_ORIGINNL 100.0 //エサ画像の元の大きさ
#define ESA_IMAGE_NEWLY 20.0 //エサ画像の大きさにするサイズ

class CEsa : public CObject
{
private:

	int *EsaImage;//エサ用の変数
	//int Bigesa;//大きいエサ用の変数

	//int esaImages[ESA_IMAGE_MAX];//エサの配列
	
	bool esaType;  //エサ画像の判別
	bool esaFlg;  //エサの表示フラグ
	int esaScore;  //エサのスコア
	
	////座標
	//float x;
	//float y;
	////縦横
	//float height;
	//float width;

public:
	CEsa();//コンストラクタ
	~CEsa();//デストラクタ
	void Update() {};
	void Draw()const;
	void HitAction() { esaFlg = false; }
	void Init(float x, float y,int *EsaImage, bool esaType);//変数の初期化
	void LoadesaImage();//画像の読込み
	bool GetFlg() { return esaFlg; }//エサの表示フラグ


};


