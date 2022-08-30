#include"DxLib.h"
#include"CAbstractEnemy.h"

#define _USE_MATH_DEFINES
#include<math.h>

//---------------------------
// コンストラクタ
//---------------------------
CAbstractEnemy::CAbstractEnemy()
{
	direction = D_DIRECTION_RIGHT;
	x = 20;  //フィールド左上を0としたときのx座標とする
	y = 20;  //フィールド左上を0としたときのy座標とする
	height = D_ENEMY_IMAGE_SIZE / 2;
	width = D_ENEMY_IMAGE_SIZE / 2;

	do
	{
		targetPosX = GetRand(D_FIELD_WIDTH - 1);
		targetPosY = GetRand(D_FIELD_HEIGHT - 1);

	} while (floor[targetPosY][targetPosX] == 0);
	

	anim = false;
	LoadDivGraph("images/testNum.png", 10, 10, 1, 20, 20, testNums);
	LoadDivGraph("images/sprites/monster.png", 2, 2, 1, 32, 32, enemyImages);
	LoadDivGraph("images/sprites/eyes.png", 4, 4, 1, 32, 32, enemyEyes);
}

//---------------------------
// デストラクタ
//---------------------------
CAbstractEnemy::~CAbstractEnemy()
{

}

//----------------------------
// 更新
//----------------------------
void CAbstractEnemy::Update()
{
	switch (D_DIRECTION_RIGHT)
	{
	case D_DIRECTION_UP:
		y--;
		break;
	case D_DIRECTION_LEFT:
		x--;
		break;
	case D_DIRECTION_DOWN:
		y++;
		break;
	case D_DIRECTION_RIGHT:
		x++;
		break;
	}

	static int timer = 0;
	timer++;
	if (timer % 60 == 0) 
	{
		direction += D_SEPARATE_ANGLE;
		if (direction >= 360)
		{
			direction -= 360;
		}
	}

	MoveToTarget();

	static int animTimer = 0;
	animTimer++;
	if (animTimer % 8 == 0)//8はフレーム数
	{
		anim = !anim;
	}
}

//----------------------------
// 描画
//----------------------------
void CAbstractEnemy::Draw()const
{
	for (int i = 0; i < D_FIELD_HEIGHT; i++)
	{
		for (int j = 0; j < D_FIELD_WIDTH; j++)
		{
			if (floor[i][j] > 0)
			{
				DrawRotaGraphF(/* x */D_FIELD_POS_X + j * D_TILE_SIZE, /* y */D_FIELD_POS_Y + i * D_TILE_SIZE,
					/* 拡大率 */1.0 , 0, testNums[floor[i][j]], TRUE);
			}
		}
	}

	
	DrawRotaGraphF(D_FIELD_POS_X + x, D_FIELD_POS_Y + y,
		1.0 , 0, enemyImages[anim], TRUE);
	
	DrawRotaGraphF(D_FIELD_POS_X + x, D_FIELD_POS_Y + y,
		1.0 , 0, enemyEyes[direction/ D_SEPARATE_ANGLE], TRUE);

	//デバッグ用ターゲット位置の表示
	DrawBoxAA(D_FIELD_POS_X + targetPosX * D_TILE_SIZE - D_TILE_SIZE / 4
		, D_FIELD_POS_Y + targetPosY * D_TILE_SIZE - D_TILE_SIZE / 4
		, D_FIELD_POS_X + targetPosX * D_TILE_SIZE + D_TILE_SIZE / 4
		, D_FIELD_POS_Y + targetPosY * D_TILE_SIZE + D_TILE_SIZE / 4,
		0xFF0000, TRUE);

	//敵位置のフィールド内座標の表示
	//DrawFormatString(0, 80, 0xFFFFFF, "Y座標：%d", (int)y / (int)D_TILE_SIZE % D_FIELD_HEIGHT);
	//DrawFormatString(0, 100, 0xFFFFFF, "X座標：%d", (int)x / (int)D_TILE_SIZE % D_FIELD_WIDTH);

	if ((int)x % (int)D_TILE_SIZE == 0
		&& (int)y % (int)D_TILE_SIZE == 0)
	{
		DrawString(0, 100, "マスの中心", 0xFFFFF);
	}
}

//-------------------------
// 当たった時の処理
//-------------------------
void CAbstractEnemy::HitAction()
{

}

//-------------------------
// 移動
//-------------------------
void CAbstractEnemy::MoveToTarget()
{
	//マス座標
	int onFieldX = (int)x / (int)D_TILE_SIZE;
	int onFieldY = (int)y / (int)D_TILE_SIZE;

	//マスの丁度真ん中に来た時
	if ((int)x % (int)D_TILE_SIZE == 0 
		&& (int)y % (int)D_TILE_SIZE == 0)
	{
		//そのマスが交差点だった時
		if (floor[onFieldX][onFieldY] == D_CROSSPOINT)
		{
			//方向の計算をする
			ChangeDirection(onFieldX,onFieldY);
		}
	}
}
 
//-------------------------
// 方向転換
//-------------------------
void CAbstractEnemy::ChangeDirection(int x,int y)
{
	int distance;
	int tmp;
	
	if (floor[y - 1][x] != D_BLOCK)
	{
		distance = pow(x - targetPosX, 2.0) + pow(y - 1 - targetPosY, 2.0);
		direction = D_DIRECTION_UP;
	}

	if (floor[y][x - 1] != D_BLOCK)
	{
		tmp = pow(x - 1 - targetPosX, 2.0) + pow(y - targetPosY, 2.0);
		if(tmp<direction)
		{
			distance = tmp;
			direction = D_DIRECTION_LEFT;
		}
	}

	if (floor[y - 1][x] != D_BLOCK)
	{
		distance = pow(x - targetPosX, 2.0) + pow(y - 1 - targetPosY, 2.0);
		direction = D_DIRECTION_UP;
	}

	if (floor[y - 1][x] != D_BLOCK)
	{
		distance = pow(x - targetPosX, 2.0) + pow(y - 1 - targetPosY, 2.0);
		direction = D_DIRECTION_UP;
	}
}
