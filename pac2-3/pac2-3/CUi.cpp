#include<math.h>
#include"CUi.h"

CUi::CUi()
{
	LoadDivGraph("images/numbers.png", SCORE_MAX, 10, 1, 9, 7, scoreImage);//スコア画像変数
	oneupImage = LoadGraph("images/oneup.png");
	oneupTime = 0;//1UP用の時間
	uiIsShow = true;  //1UPの描画フラグ
	totalScore = 0;
	
}

CUi::~CUi()
{
	;
}

void CUi::Update()
{
	uiImageBlinking();
}

void CUi::Draw() const
{
	if (uiIsShow)
	{
		DrawRotaGraphF(370, 10, 1.0/ ONEUP_ORIGINNL* ONEUP_NEWSIZE, 0, oneupImage, TRUE);//1UPの画像の表示(点滅処理も)
		
	}

	//DrawRotaGraphF(100, 130, 1.5, 0, scoreImage[3], TRUE);//スコアを表示するためのDrawすべてやるにはまだ足りない

	karikannsuu();
	
}


void CUi::karikannsuu() const//名前は後で変更する
{
	int digit;//桁数という意味  //weight

	int w = totalScore;  //totalScoreに何もないため

	int i = 0;
	while (w > 0)
	{
		DrawRotaGraphF(POSX - i * NUM, POSY, 1.0 / ONEUP_ORIGINNL * ONEUP_NEWSIZE, 0, scoreImage[w % 10], TRUE);//スコアを表示するためのDrawすべてやるにはまだ足りない
		w /= 10;
		i++;
	}

}

void CUi::AddScore(int nowScore)//引数に値を入れて完成させる
{
	totalScore += nowScore;
}

void CUi::uiImageBlinking(void)
{
	oneupTime++;
	if (oneupTime % 10 == 0)//1秒間に一回
	{
		uitoggle();
	}

}