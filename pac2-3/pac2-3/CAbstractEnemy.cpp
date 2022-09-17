#include"DxLib.h"
#include"CAbstractEnemy.h"


#define _USE_MATH_DEFINES
#include<math.h>


//---------------------------
// コンストラクタ
//---------------------------
CAbstractEnemy::CAbstractEnemy()
{
	LoadImages();
	direction = D_DIRECTION_DOWN;
	x = 240;  //フィールド左上を0としたときのx座標とする
	y = 280;  //フィールド左上を0としたときのy座標とする
	height = D_TILE_SIZE;
	width = D_TILE_SIZE;


	int floorX;
	int floorY;
	do
	{
		floorX = GetRand(D_FIELD_WIDTH - 1);
		floorY = GetRand(D_FIELD_HEIGHT - 1);

	} while (floor[floorY][floorX] == 0);

	targetPosX = floorX * D_TILE_SIZE;
	targetPosY = floorY * D_TILE_SIZE;
	
	anim = false;

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

	//移動パターンの制御
	if (inEnemyroom)
	{
		LeaveTheNest();
	}
	else
	{
		MoveToTarget();
	}

	//イジケ状態制御用変数の更新
	if (isSurprising)
	{
		
		surprisingTimer--;
		if (!surprisingTimer)
		{
			isSurprising = false;
		}
	}

	//目標地点についたら目標を更新する
	if ((double)x == targetPosX &&
		(double)y == targetPosY)
	{
		ChangeTargetPos();
	}

	//波状攻撃用処理
	AttackInterval();
	if (!isAttack)
	{
		targetPosX = REST_AREA_X * D_TILE_SIZE;
		targetPosY = REST_AREA_Y * D_TILE_SIZE;
	}

	//アニメーション制御用変数の更新
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
	//デバッグ用フィールドの数値
	//for (int i = 0; i < D_FIELD_HEIGHT; i++)
	//{
	//	for (int j = 0; j < D_FIELD_WIDTH; j++)
	//	{
	//		if (floor[i][j] > 0)
	//		{
	//			DrawRotaGraphF(/* x */D_FIELD_POS_X + j * D_TILE_SIZE, /* y */D_FIELD_POS_Y + i * D_TILE_SIZE,
	//				/* 拡大率 */1.0 , 0, testNums[floor[i][j]], TRUE);
	//		}
	//	}
	//}

	if (isEaten)
	{
		DrawRotaGraphF(D_FIELD_POS_X + x, D_FIELD_POS_Y + y,
			1.0, 0, enemyEyes[direction], TRUE);
	}
	else
	{
		if (isSurprising)
		{
			//イジケ状態時の描画
			DrawRotaGraphF(D_FIELD_POS_X + x, D_FIELD_POS_Y + y,
				1.0, 0, surprisingImages[0][anim], TRUE);
		}
		else
		{
			//通常時の描画
			DrawRotaGraphF(D_FIELD_POS_X + x, D_FIELD_POS_Y + y,
				1.0, 0, enemyImages[anim], TRUE);

			DrawRotaGraphF(D_FIELD_POS_X + x, D_FIELD_POS_Y + y,
				1.0, 0, enemyEyes[direction], TRUE);
		}
	}
	//デバッグ用ターゲット位置の表示
	DrawBoxAA(D_FIELD_POS_X + targetPosX - D_TILE_SIZE / 4
		, D_FIELD_POS_Y + targetPosY - D_TILE_SIZE / 4
		, D_FIELD_POS_X + targetPosX + D_TILE_SIZE / 4
		, D_FIELD_POS_Y + targetPosY + D_TILE_SIZE / 4,
		0xFF0000, TRUE);

	DrawLineAA(D_FIELD_POS_X + x, D_FIELD_POS_Y + y,
		D_FIELD_POS_X + targetPosX, 
		D_FIELD_POS_Y + targetPosY, 0xFF0000);

	//敵位置のフィールド内座標の表示
	//DrawFormatString(0, 80+20*0, 0xFFFFFF, "Y座標：%d", (int)y / (int)D_TILE_SIZE % D_FIELD_HEIGHT);
	//DrawFormatString(0, 80+20*1, 0xFFFFFF, "X座標：%d", (int)x / (int)D_TILE_SIZE % D_FIELD_WIDTH);
	{
		int i = 0;
		DrawRotaGraph(200, 10 + i++ * 32, 1.0, 0, surprisingImages[0][0], TRUE);
		DrawRotaGraph(200, 10 + i++ * 32, 1.0, 0, surprisingImages[0][1], TRUE);
		DrawRotaGraph(200, 10 + i++ * 32, 1.0, 0, surprisingImages[1][0], TRUE);
		DrawRotaGraph(200, 10 + i++ * 32, 1.0, 0, surprisingImages[1][1], TRUE);
		DrawFormatString(200, 10 + i++ * 32, 0x00FF00, "%lf", y);
		DrawFormatString(200, 10 + i++ * 32, 0x00FF00, "%lf", x);
	}
}

//-------------------------
// 当たった時の処理
//-------------------------
void CAbstractEnemy::HitAction()
{

}

//---------------------------
// イジケ状態への遷移
//---------------------------
void CAbstractEnemy::Surprised()
{
	isSurprising = true;
	surprisingTimer = surprisingTime;
	direction = (direction + 2) % 4;
}

//--------------------------------
// 当たった時（プレイヤー）
//--------------------------------
void CAbstractEnemy::HitAction_Player()
{
	if (isSurprising)
	{
		isEaten = true;

		floor[D_DOOR_Y][D_DOOR_X] = D_FLOOR;
		floor[D_DOOR_Y][D_DOOR_X + 1] = D_FLOOR;

		//巣の中
		targetPosX = 13 * D_TILE_SIZE + 10;
		targetPosY = 14 * D_TILE_SIZE;
	}
}

//----------------------------------------
// ターゲット位置の変更
//----------------------------------------
void CAbstractEnemy::ChangeTargetPos()
{
	if (isEaten)
	{
		floor[D_DOOR_Y][D_DOOR_X] = D_BLOCK;
		floor[D_DOOR_Y][D_DOOR_X + 1] = D_BLOCK;
		inEnemyroom = true;
		isEaten = false;
		isSurprising = false;
	}

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

//-------------------------
// 画像読み込み
//-------------------------
void CAbstractEnemy::LoadImages()
{
	int* images = new int[20];

	LoadDivGraph("images/testNum.png", 10, 10, 1, 20, 20, testNums);
	LoadDivGraph("images/sprites/monster.png", 2, 2, 1, 32, 32, enemyImages);
	LoadDivGraph("images/sprites/eyes.png", 4, 4, 1, 32, 32, enemyEyes);
	LoadDivGraph("images/sprites/monster.png", 20, 20, 1, 32, 32, images);
	surprisingImages[0][0] = images[20 - 4];
	surprisingImages[0][1] = images[20 - 3];
	surprisingImages[1][0] = images[20 - 2];
	surprisingImages[1][1] = images[20 - 1];
	delete[] images;

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
	if ((int)y % (int)D_TILE_SIZE == 0
		&& (int)x % (int)D_TILE_SIZE == 0 
		||(int)x==D_ENEMY_ROOM_X)
	{
		//そのマスが交差点だった時
		if (floor[onFieldY][onFieldX] == D_CROSSPOINT
			|| (int)x == D_ENEMY_ROOM_X)
		{
			//方向の計算をする
			ChangeDirection(onFieldX,onFieldY);
		}
	}

	MoveStraight(onFieldX, onFieldY);

}

//------------------------
// 直進移動
//------------------------
void CAbstractEnemy::MoveStraight(int onFieldX,int onFieldY)
{
	/*
	各case文での処理
	・方向に応じた値の更新
	・移動先に（1マス先）壁が見えたら、
		自分がいるマスの中心の座標より壁側によらないようにする
	*/
	
	switch (direction)
	{
	case D_DIRECTION_UP:
		y-=1.0*16/16;
		if (floor[onFieldY - 1][onFieldX] == D_BLOCK)
		{
			if (y < onFieldY * D_TILE_SIZE)
			{
				y = onFieldY * D_TILE_SIZE;
			}
		}
		break;
		
	case D_DIRECTION_LEFT:
		x--;
		if (floor[onFieldY][onFieldX - 1] == D_BLOCK)
		{
			if (x < onFieldX * D_TILE_SIZE)
			{
				x = onFieldX * D_TILE_SIZE;
			}
		}
		break;

	case D_DIRECTION_DOWN:
		y++;
		if (floor[onFieldY + 1][onFieldX] == D_BLOCK)
		{
			if (y > onFieldY * D_TILE_SIZE)
			{
				y = onFieldY * D_TILE_SIZE;
			}
		}
		break;

	case D_DIRECTION_RIGHT:
		x++;
		if (floor[onFieldY][onFieldX + 1] == D_BLOCK)
		{
			if (x > onFieldX * D_TILE_SIZE)
			{
				x = onFieldX * D_TILE_SIZE;
			}
		}
		break;


	default:
		;
	}

}
 
//-------------------------
// 方向転換
//-------------------------
void CAbstractEnemy::ChangeDirection(int x,int y)
{
	int distance = D_DISTANCE_MAX;
	int tmp = 0;

	//後ろに反転しない処理のための準備
	int directionBack;
	directionBack = (direction + 2) % 4;//2回正の方向に動かす（反転）
	
	/*
	上下左右のマスが壁でないことを確認して、
	先のマスから目標までの距離を計算し、
	いちばん近い方向を通る。
	また、値が同じ場合は、優先のものから 上左下右 とする。
	*/

	//上
	if (directionBack != D_DIRECTION_UP) 
	{
		if (floor[y - 1][x] != D_BLOCK)
		{
			distance =(int)( pow((double)x - targetPosX / D_TILE_SIZE, 2.0) +
							 pow((double)y - 1 - targetPosY / D_TILE_SIZE, 2.0));
			direction = D_DIRECTION_UP;
		}

	}

	//左
	if (directionBack != D_DIRECTION_LEFT)
	{
		if (floor[y][x - 1] != D_BLOCK)
		{
			tmp = (int)(pow((double)x - 1 - targetPosX / D_TILE_SIZE, 2.0) +
						pow((double)y - targetPosY / D_TILE_SIZE, 2.0));
			if (tmp < distance)
			{
				distance = tmp;
				direction = D_DIRECTION_LEFT;
			}
		}
	}

	//下
	if (directionBack != D_DIRECTION_DOWN)
	{
		if (floor[y + 1][x] != D_BLOCK)
		{
			tmp = (int)(pow((double)x - targetPosX / D_TILE_SIZE, 2.0) +
				        pow((double)y + 1 - targetPosY / D_TILE_SIZE, 2.0));

			if (tmp < distance)
			{
				distance = tmp;
				direction = D_DIRECTION_DOWN;
			}
		}
	}

	//右
	if (directionBack != D_DIRECTION_RIGHT)
	{
		if (floor[y][x + 1] != D_BLOCK)
		{
			tmp =(int)(pow((double)x + 1 - targetPosX / D_TILE_SIZE, 2.0) +
				       pow((double)y - targetPosY / D_TILE_SIZE, 2.0));
			if (tmp < distance)
			{
				distance = tmp;
				direction = D_DIRECTION_RIGHT;
			}
		}
	}
}

//-------------------------
// 波状攻撃
//-------------------------
void CAbstractEnemy::AttackInterval()
{
	static int cycle;
	attackInterval[cycle]--;
	if (cycle < 7)
	{
		if (attackInterval[cycle] <= 0)
		{
			cycle++;
			isAttack = !isAttack;
			direction = (direction + 2) % 4;
			ChangeTargetPos();
		}
	}
}

//----------------------------------------------------
// 巣からの解放  ：目標地点に達したら、trueを返す
//----------------------------------------------------
void CAbstractEnemy::LeaveTheNest()
{
	static int step = 0;


	if (step == 0)
	{
		if (y > D_ENEMY_ROOM_Y)
		{
			direction = D_DIRECTION_UP;
			y -= 0.5f;
		}
		else if (y < D_ENEMY_ROOM_Y)
		{
			direction = D_DIRECTION_DOWN;
			y += 0.5f;
		}
		else if (y == D_ENEMY_ROOM_Y)
		{
			step++;
		}
		else
		{
			;
		}
	}

	if (step == 1)
	{
		if (x > D_ENEMY_ROOM_X)
		{
			direction = D_DIRECTION_LEFT;
			x -= 0.5f;
		}
		else if (x < D_ENEMY_ROOM_X)
		{
			direction = D_DIRECTION_RIGHT;
			x += 0.5f;
		}
		else if (x == D_ENEMY_ROOM_X)
		{
			step++;
		}
		else
		{
			;
		}
	}

	if (step == 2)
	{
		if (y > D_ENEMY_LEAVE_Y)
		{
			direction = D_DIRECTION_UP;
			y -= 0.5f;
			if (y == D_ENEMY_LEAVE_Y)
			{
				inEnemyroom = false;
				step = 0;
			}
		}
	}
}