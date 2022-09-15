#include<stdio.h>
#include"DxLib.h"
#include "CFruit.h"


CFruit::CFruit()//コンストラクタ
{
	bool error = false;
	if (LoadDivGraph("images/sprites/fruit.png", FRUIT_MAX, 13, 1, 32, 32, FruitImage) == -1)error = true;

	FruitType = 0;  //エサ画像の判別
	FruitFlg = true;  //エサの表示フラグ
	FruitScore = 0;  //エサのスコア
	FruitTime = 0;   //エサの点滅させるため用の時間変数
	FruitIsShow = true; //エサの描画フラグ

	height = 3;
	width = 3;

}

void CFruit::Draw()const
{

	DrawGraph(620, 395, FruitImage[0], TRUE);
	DrawGraph(840, 680, FruitImage[0], TRUE);
	//DrawGraph(815, 680, FruitImage[1], TRUE);
	/*DrawGraph(640, 680, FruitImage[2], TRUE);
	DrawGraph(540, 680, FruitImage[3], TRUE);
	DrawGraph(440, 680, FruitImage[4], TRUE);
	DrawGraph(340, 680, FruitImage[5], TRUE);
	DrawGraph(240, 680, FruitImage[6], TRUE);
	DrawGraph(140, 680, FruitImage[7], TRUE);*/

}

void CFruit::Init(float x, float y, int* FruitImage, bool FruitType, int FruitScore)
{
	this->x = x;  //座標
	this->y = y;  //座標
	this->FruitType = FruitType;  //エサ画像の判別
	this->FruitScore = FruitScore; //エサのスコア

}