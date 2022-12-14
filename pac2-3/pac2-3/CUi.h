#pragma once
#include"DxLib.h"
#define SCORE_MAX 10
#define ONEUP_ORIGINNL  22.0
#define ONEUP_NEWSIZE   45.0 
#define MAX_DIGIT  6 //桁数
#define POSX 460 //位置
#define POSY 40 //位置
#define NUM  15  //位置をずらすためのもの


class CUi
{
private:
	int scoreImage[SCORE_MAX] = {};//画像用変数
	int oneupImage;//画像用変数

	int oneupTime;//1UPのための時間用変数
	bool uiIsShow; //1か0か描画フラグ

	int totalScore;//スコアの合計を格納する変数
	
public:
	CUi();//コンストラクタ
	~CUi();//デストラクタ

	void Update();//アップデート
	void Draw()const;//描画関数

	void DigitCalculation() const;//桁計算 Draw関数に入れる関数
	int GetScore()const { return totalScore; }
	void AddScore(int nowScore);
	void uiImageBlinking(void);//点滅処理
	void uitoggle(void) { uiIsShow = !(uiIsShow); }//描画フラグ
	//void karikansuu3();
};