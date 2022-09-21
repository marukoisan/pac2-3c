#pragma once
#include"Object.h"

#define FRUIT_MAX 13

class CFruit : public CObject
{
private:

	int FruitImage[FRUIT_MAX] = {};
	int scoreImages[FRUIT_MAX] = {};
	int stageLevel;  //エサ画像の判別
	bool fruitFlg;  //エサの表示フラグ
	int fruitScore = 0;  //エサのスコア
	int fruitTimer;  //エサの点滅用の時間を入れる変数
	bool fruitIsShow; //1か0か描画フラグ
	int FRUIT_SCORES[FRUIT_MAX]={100,300,500,500,700,700,1000,1000,2000,2000,3000,3000,5000};


	int scoreTimer = 0;
public:

	CFruit();
	~CFruit(); 
	void Update();
	void Draw()const;
	void Init();
	void HitAction() { }
	int HitAction_Player() 
	{
		fruitFlg = false; 
		scoreTimer = 60 * 2;
		return fruitScore;
	}

	void SetStageLevel(int stageLevel)
	{
		this->stageLevel = stageLevel;
		if (stageLevel > 12)
		{
			this->stageLevel = 12;
		}
	}
	void Advent();//変数の初期化
	bool GetFlg() { return fruitFlg; }//エサの表示フラグ
	//void toggle(void) { FruitIsShow = !(FruitIsShow); }//描画フラグ
	int GetScore() { return fruitScore; }//エサのスコアを貰う

	//デバッグ用　TODO:消す
	void DeleteFeed() { fruitFlg = false; }

};

