#include "CGuzuta.h"


//---------------------------------------
// コンストラクタ
//---------------------------------------
CGuzuta::CGuzuta()
{
	LoadImages();

	restAreaX = 1;
	restAreaY = 29;

	initialPosX = D_ENEMY_ROOM_X + 40;
	initialPosY = 14 * D_TILE_SIZE;
	initialDirection = D_DIRECTION_UP;

	x = initialPosX;
	y = initialPosY;
	direction = initialDirection;
}

//---------------------------------------
// ターゲット位置の更新
//---------------------------------------
void CGuzuta::SetTargetPos()
{
	float distanceX = player->GetX() - x;
	float distanceY = player->GetY() - y;
	float distance = (distanceX * distanceX) + (distanceY * distanceY);
	
	//半径8マス以内にいるなら
	if ((8 * D_TILE_SIZE) * (8 * D_TILE_SIZE) > distance)
	{
		static int Timer;
		Timer++;
		if (Timer % 5 == 0)
		{

			int floorX;
			int floorY;
			do
			{
				floorX = GetRand(D_FIELD_WIDTH - 1);
				floorY = GetRand(D_FIELD_HEIGHT - 1);

			} while (floor[floorY][floorX] == 0);

			targetPosX = floorX * D_TILE_SIZE;
			targetPosY = floorY * D_TILE_SIZE;
		}
	}
	else
	{
		//外ならアカベイと同じ
		targetPosX = player->GetX();
		targetPosY = player->GetY();
	}
}


//---------------------------------------
// 画像の読み込み
//---------------------------------------
void CGuzuta::LoadImages()
{

	int* images = new int[20];

	LoadDivGraph("images/testNum.png", 10, 10, 1, 20, 20, testNums);
	LoadDivGraph("images/sprites/eyes.png", 4, 4, 1, 32, 32, enemyEyes);
	LoadDivGraph("images/sprites/monster.png", 20, 20, 1, 32, 32, images);
	enemyImages[0] = images[6];
	enemyImages[1] = images[7];
	surprisingImages[0][0] = images[20 - 4];
	surprisingImages[0][1] = images[20 - 3];
	surprisingImages[1][0] = images[20 - 2];
	surprisingImages[1][1] = images[20 - 1];
	delete[] images;
}


//--------------------------------
// 食べられた時の動き
//--------------------------------
void CGuzuta::EatenMove()
{
	if (isEaten)
	{
		static bool step = false;
		if (-speed < (x - targetPosX) && (x - targetPosX) < speed
			&& -speed < (y - targetPosY) && (y - targetPosY) < speed)
		{
			x = targetPosX;
			y = targetPosY;
		}
		//巣の中に入ったら各種フラグを切り換える
		if ((double)x == targetPosX
			&& (double)y == targetPosY
			&& !step)
		{
			targetPosX = initialPosX;
			targetPosY = initialPosY;

			step = true;
		}
		if ((double)x == targetPosX
			&& (double)y == targetPosY
			&& step)
		{
			floor[D_DOOR_Y][D_DOOR_X] = D_BLOCK;
			floor[D_DOOR_Y][D_DOOR_X + 1] = D_BLOCK;
			inEnemyroom = true;
			isEaten = false;
			isSurprising = false;
			isLeaveTheNest = true;

			step = false;
		}
	}

}