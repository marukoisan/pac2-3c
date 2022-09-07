#include"CUi.h"

CUi::CUi()
{
	LoadDivGraph("images/numbers.png", 10, 10, 1, 97, 7, scoreImage);//スコア画像変数
	oneupImage = LoadGraph("images/oneup.png");
	oneupTime = 0;//1UP用の時間
	uiIsShow = true;  //1UPの描画フラグ
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
		DrawGraph(100, 100, oneupImage, TRUE);
	}

	DrawFormatString(100, 130, 0x00000, "%06d", scoreImage);
	
}


void Score()
{

}

void OneUp()
{

}

void CUi::uiImageBlinking(void)
{
	oneupTime++;
	if (oneupTime % 10 == 0)//1秒間に一回
	{
		uitoggle();
	}

}