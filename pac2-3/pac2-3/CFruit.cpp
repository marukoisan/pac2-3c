#include<stdio.h>
#include"DxLib.h"
#include "CFruit.h"
#include "define.h"


CFruit::CFruit()//コンストラクタ
{
	bool error = false;
	if (LoadDivGraph("images/sprites/fruit.png", FRUIT_MAX, 13, 1, 32, 32, FruitImage) == -1)error = true;
	int* images = new int[8];
	LoadDivGraph("images/fruit_score.png", 8, 1, 8, 20, 20, images);
	int i = 0;
	scoreImages[i++] = images[0];
	scoreImages[i++] = images[1];
	scoreImages[i++] = images[2];
	scoreImages[i++] = images[2];
	scoreImages[i++] = images[3];
	scoreImages[i++] = images[3];
	scoreImages[i++] = images[4];
	scoreImages[i++] = images[4];
	scoreImages[i++] = images[5];
	scoreImages[i++] = images[5];
	scoreImages[i++] = images[6];
	scoreImages[i++] = images[6];
	scoreImages[i++] = images[7];

	delete[] images;

	stageLevel = 0;  //エサ画像の判別
	fruitFlg = false;  //エサの表示フラグ
	fruitScore = 0;  //エサのスコア
	fruitTimer = 0;   //エサの点滅させるため用の時間変数
	fruitIsShow = true; //エサの描画フラグ

	height = 20;
	width = 20;
	x = 270;
	y = 340;
}

CFruit::~CFruit()//デストラクタ
{
	;
}

void CFruit::Update()
{
	scoreTimer--;
	fruitTimer--;
	if (fruitTimer < 0)
	{
		fruitFlg = false;
	}
}

void CFruit::Draw()const
{
	if (fruitFlg)
	{
		DrawRotaGraphF(D_FIELD_POS_X+x, D_FIELD_POS_Y+y, 1.0, 0, FruitImage[stageLevel], TRUE);
	}
	if (scoreTimer > 0)
	{
		DrawRotaGraphF(D_FIELD_POS_X + x, D_FIELD_POS_Y + y, 1.0/20*32, 0, scoreImages[stageLevel], TRUE);
	}
	DrawGraph(840, 680, FruitImage[0], TRUE);
	//DrawGraph(815, 680, FruitImage[1], TRUE);
	/*DrawGraph(640, 680, FruitImage[2], TRUE);
	DrawGraph(540, 680, FruitImage[3], TRUE);
	DrawGraph(440, 680, FruitImage[4], TRUE);
	DrawGraph(340, 680, FruitImage[5], TRUE);
	DrawGraph(240, 680, FruitImage[6], TRUE);
	DrawGraph(140, 680, FruitImage[7], TRUE);*/

}

void CFruit::Init()
{
	fruitTimer = 0;
	fruitFlg = false;
}

void CFruit::Advent()
{
	fruitScore = FRUIT_SCORES[stageLevel]; //エサのスコア
	fruitFlg = true;
	fruitTimer = 60 * 10;
}