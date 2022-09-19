#include "CAkabei.h"

//-------------------
// コンストラクタ
//-------------------
CAkabei::CAkabei()
{
	inEnemyroom = false;
}

//----------------------------------
// 初期化
//----------------------------------
void CAkabei::Init()
{
	x = initialPosX;
	y = initialPosY;
	direction = initialDirection;
	inEnemyroom = false;
	isSurprising = false;
	isEaten = false;
	isWhite = false;
	attackCycle = 0;
}