#pragma once
#include"Object.h"
#define FRUIT_MAX 13

class CFruit : public CObject
{
private:

	int FruitImage[FRUIT_MAX] = {};
	int Cherry = 100;
	bool FruitType;  //エサ画像の判別
	bool FruitFlg;  //エサの表示フラグ
	int FruitScore;  //エサのスコア
	int FruitTime;  //エサの点滅用の時間を入れる変数
	bool FruitIsShow; //1か0か描画フラグ





public:

	CFruit();
	~CFruit() {}
	void Update() {}
	void Draw()const;
	void HitAction() { FruitFlg = false; }
	void Init(float x, float y, int* FruitImage, bool FruitType, int FruitScore);//変数の初期化
	bool GetFlg() { return FruitFlg; }//エサの表示フラグ
	void toggle(void) { FruitIsShow = !(FruitIsShow); }//描画フラグ
	int GetScore() { return FruitScore; }//エサのスコアを貰う

};

