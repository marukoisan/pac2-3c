#include"DxLib.h"
#include "CFruit.h"

CFruit::CFruit()//コンストラクタ
{

	int FruitImage = 0;
	LoadDivGraph("images/sprites/fruit.png", 13, 13, 1, 32, 32, FruitImage);
}
