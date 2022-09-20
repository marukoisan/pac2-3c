#include "CPinky.h"

//---------------------------------------
// コンストラクタ
//---------------------------------------
CPinky::CPinky()
{
	LoadImages();

	restAreaX = 1;
	restAreaY = 1;

	initialPosX = D_ENEMY_ROOM_X;
	initialPosY = 14 * D_TILE_SIZE;
	initialDirection = D_DIRECTION_DOWN;

	x = initialPosX;
	y = initialPosY;
	direction = initialDirection;
}

//---------------------------------------
// ターゲット位置の更新
////---------------------------------------
//void CPinky::SetTargetPos()
//{
//	
//}


//---------------------------------------
// 画像の読み込み
//---------------------------------------
void CPinky::LoadImages()
{

	int* images = new int[20];

	LoadDivGraph("images/testNum.png", 10, 10, 1, 20, 20, testNums);
	LoadDivGraph("images/sprites/eyes.png", 4, 4, 1, 32, 32, enemyEyes);
	LoadDivGraph("images/sprites/monster.png", 20, 20, 1, 32, 32, images);
	enemyImages[0] = images[2];
	enemyImages[1] = images[3];
	surprisingImages[0][0] = images[20 - 4];
	surprisingImages[0][1] = images[20 - 3];
	surprisingImages[1][0] = images[20 - 2];
	surprisingImages[1][1] = images[20 - 1];
	delete[] images;
}

