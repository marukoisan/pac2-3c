#include "CPinky.h"
#define _USE_MATH_DEFINES
#include<math.h>

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

	inTheNest_isUp = false;
	x = initialPosX;
	y = initialPosY;
	direction = initialDirection;
}

//---------------------------------------
// ターゲット位置の更新
//---------------------------------------
void CPinky::SetTargetPos()
{
	int pDirection = player->GetAngle() / M_PI * 2;
	switch (pDirection)
	{
	case D_PLAYER_UP:
		targetPosX = player->GetX();
		targetPosY = player->GetY() - D_TILE_SIZE * 3;
		break;

	case D_PLAYER_RIGHT:
		targetPosX = player->GetX() + D_TILE_SIZE * 3;
		targetPosY = player->GetY();
		break;

	case D_PLAYER_DOWN:
		targetPosX = player->GetX();
		targetPosY = player->GetY() + D_TILE_SIZE * 3;
		break;

	case D_PLAYER_LEFT:
		targetPosX = player->GetX() - D_TILE_SIZE * 3;
		targetPosY = player->GetY();
		break;

	default:
		;
	}
}


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

