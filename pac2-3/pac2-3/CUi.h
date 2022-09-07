#pragma once
#include"DxLib.h"
#define SCORE_MAX 10

class CUi
{
private:
	int scoreImage[SCORE_MAX];//画像用変数
	int oneupImage;//画像用変数

	int oneupTime;//1UPのための時間用変数
	bool uiIsShow; //1か0か描画フラグ


public:
	CUi();//コンストラクタ
	~CUi();//デストラクタ

	void Update();//アップデート
	void Draw()const;//描画関数

	void Score();
	void OneUp();
	void uiImageBlinking(void);//点滅処理
	void uitoggle(void) { uiIsShow = !(uiIsShow); }//描画フラグ
	//void karikansuu3();
};