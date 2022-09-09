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
		DrawRotaGraphF(100, 100, 1.0/ ONEUP_ORIGINNL* ONEUP_NEWSIZE, 0, oneupImage, TRUE);//1UPの画像の表示(点滅処理も)
		
	}

	//DrawRotaGraphF(100, 130, 1.5, 0, scoreImage[3], TRUE);//スコアを表示するためのDrawすべてやるにはまだ足りない

	karikannsuu();
	
}


void CUi::karikannsuu() const//名前は後で変更する
{
	int digit;//桁数という意味  //weight

	for (digit = 0; digit < MAX_DIGIT; digit++)
	{
		int w = totalScore;  //totalScoreに何もないため
		
		w /= 10;

		if (totalScore == 0)break;

	}

	for (int i = 0; i < digit; i++)
	{
		int weight;

		weight = i * 10 ^ digit;

		DrawRotaGraphF(100, 130, 1.0, 0, scoreImage[totalScore / weight], TRUE);//スコアを表示するためのDrawすべてやるにはまだ足りない

	}

}

void CUi::AddScore(int Addscore)//引数に値を入れて完成させる
{
	totalScore += Addscore;
}

void CUi::uiImageBlinking(void)
{
	oneupTime++;
	if (oneupTime % 10 == 0)//1秒間に一回
	{
		uitoggle();
	}

}