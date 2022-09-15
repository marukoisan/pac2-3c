#include<stdio.h>
#include"DxLib.h"
#include "CFruit.h"

CFruit::CFruit()//コンストラクタ
{
	bool error = false;
	if (LoadDivGraph("images/sprites/fruit.png", FRUIT_MAX, 13, 1, 32, 32, FruitImage) == -1)error = true;
	
}

void CFruit::Draw()const
{
	DrawGraph(0, 100, FruitImage[0], TRUE);
}