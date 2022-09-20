#include"DxLib.h"
#include"CAbstractEnemy.h"


#define _USE_MATH_DEFINES
#include<math.h>


//---------------------------
// コンストラクタ
//---------------------------
CAbstractEnemy::CAbstractEnemy()
{
	LoadSounds();
	LoadImages();
	direction = initialDirection;
	x = initialPosX;  //フィールド左上を0としたときのx座標とする
	y = initialPosY;  //フィールド左上を0としたときのy座標とする
	height = D_TILE_SIZE-8;
	width = D_TILE_SIZE-8;


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
	if (GetisAttack())
	{
		SetTargetPos();
	}

	//移動パターンの制御
	if (inEnemyroom)
	{
		MoveInEnemyRoom();
		if(isLeaveTheNest)
		{
			LeaveTheNest();
		}
		
	}
	else
	{
		(isSurprising && !isEaten) ? SurprisingMove() : MoveToTarget();
		
	}

	//イジケ状態制御用変数の更新
	surprisingTimer--;

	if (surprisingTimer <= 0)
	{
		isSurprising = false;
	}

	if (isSurprising || isEaten)
	{
		if (surprisingTimer < 60 * 2)
		{
			if (surprisingTimer % (60 / 5) == 0)
			{
				isWhite = !isWhite;
			}
		}
	}
	else
	{
		//波状攻撃用処理
		AttackInterval();
	}

	if (isEaten)
	{
		EatenMove();
	}

	
	if (!isAttack && !isSurprising && !isEaten)
	{
		targetPosX = restAreaX * D_TILE_SIZE;
		targetPosY = restAreaY * D_TILE_SIZE;
	}

	//アニメーション制御用変数の更新
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
				1.0, 0, surprisingImages[isWhite][anim], TRUE);
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

	//デバッグ用処理ここから-------------------------------------------------------------------------------
	
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
		DrawFormatString(200, 10 + i++ * 32, 0x00FF00, "%lf", speed);

	}
	////デバッグ用フィールドの数値
	//for (int i = 0; i < D_FIELD_HEIGHT; i++)
	//{
	//	for (int j = 0; j < D_FIELD_WIDTH; j++)
	//	{
	//		if (floor[i][j] > 0)
	//		{
	//			DrawRotaGraphF(D_FIELD_POS_X + j * D_TILE_SIZE, //x
	//				D_FIELD_POS_Y + i * D_TILE_SIZE,//y
	//				1.0 // 拡大率 
	//				, 0, testNums[floor[i][j]], TRUE);
	//		}
	//	}
	//}

	
	//----------------------------------------------------------------デバッグ用処理ここまで

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
	
	isWhite = false;
	isSurprising = true;
	surprisingTimer = surprisingTime;
	if (!isEaten)
	{
		direction = (direction + 2) % 4;
		PlaySoundMem(izikeSound, DX_PLAYTYPE_LOOP, TRUE);//イジケ状態中鳴らす
	}
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

//----------------------------------
// 初期化
//----------------------------------
void CAbstractEnemy::Init()
{
	x = initialPosX;
	y = initialPosY;
	direction = initialDirection;
	inEnemyroom = true;
	isSurprising = false;
	isEaten = false;
	isWhite = false;
	attackCycle = 0;
	leaveStep = 0;
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

	float centerX = onFieldX * D_TILE_SIZE;  //今いるマスの中心座標
	float centerY = onFieldY * D_TILE_SIZE;  //今いるマスの中心座標

		//そのマスが交差点だった時
	if (floor[onFieldY][onFieldX] == D_CROSSPOINT)
	{

		//マスの真ん中付近に来た時
		if (-speed < (x - centerX) && (x - centerX) < speed
			&& -speed < (y - centerY) && (y - centerY) < speed)
		{
			y = centerY;
			x = centerX;
			//方向の計算をする
			ChangeDirection(onFieldX, onFieldY);
		}
	}

	if (-speed < (x - (D_ENEMY_ROOM_X)) && (x - (D_ENEMY_ROOM_X)) < speed)
	{
		x = D_ENEMY_ROOM_X;
		ChangeDirection(onFieldX, onFieldY);
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
		y-=speed;
		if (floor[onFieldY - 1][onFieldX] == D_BLOCK)
		{
			if (y < onFieldY * D_TILE_SIZE)
			{
				y = onFieldY * D_TILE_SIZE;
			}
		}
		break;
		
	case D_DIRECTION_LEFT:
		x -= speed;
		if (floor[onFieldY][onFieldX - 1] == D_BLOCK)
		{
			if (x < onFieldX * D_TILE_SIZE)
			{
				x = onFieldX * D_TILE_SIZE;
			}
		}
		break;

	case D_DIRECTION_DOWN:
		y += speed;
		if (floor[onFieldY + 1][onFieldX] == D_BLOCK)
		{
			if (y > onFieldY * D_TILE_SIZE)
			{
				y = onFieldY * D_TILE_SIZE;
			}
		}
		break;

	case D_DIRECTION_RIGHT:
		x += speed;
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
		if (floor[y - 1][x] != D_BLOCK && floor[y - 1][x] != D_VALVE)
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
	attackInterval[attackCycle]--;
	if (attackCycle < 7)
	{
		if (attackInterval[attackCycle] <= 0)
		{
			attackCycle++;
			isAttack = !isAttack;
			direction = (direction + 2) % 4;
		}
	}
	else
	{
		isAttack = true;
	}
}

//----------------------------------------------------
// 巣からの解放 
//----------------------------------------------------
void CAbstractEnemy::LeaveTheNest()
{
	isLeaveTheNest = true;

	if (leaveStep == 0)
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
			leaveStep++;
		}
		else
		{
			;
		}
	}

	if (leaveStep == 1)
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
			leaveStep++;
		}
		else
		{
			;
		}
	}

	if (leaveStep == 2)
	{
		if (y > D_ENEMY_LEAVE_Y)
		{
			direction = D_DIRECTION_UP;
			y -= 0.5f;
			if (y == D_ENEMY_LEAVE_Y)
			{
				inEnemyroom = false;
				isLeaveTheNest = false;
				leaveStep = 0;
			}
		}
	}
}

//-------------------------------------------
// イジケ状態の動き
//-------------------------------------------
void CAbstractEnemy::SurprisingMove()
{
	//マス座標
	int onFieldX = (int)x / (int)D_TILE_SIZE;
	int onFieldY = (int)y / (int)D_TILE_SIZE;

	float centerX = onFieldX * D_TILE_SIZE;  //今いるマスの中心座標
	float centerY = onFieldY * D_TILE_SIZE;  //今いるマスの中心座標

		//そのマスが交差点だった時
	if (floor[onFieldY][onFieldX] == D_CROSSPOINT)
	{

		//マスの真ん中付近に来た時
		if (-speed < (x - centerX) && (x - centerX) < speed
			&& -speed < (y - centerY) && (y - centerY) < speed)
		{
			y = centerY;
			x = centerX;
			//方向の計算をする
			ChooseRandomDirection(onFieldX, onFieldY);
		}
	}

	if (-speed < (x - (D_ENEMY_ROOM_X)) && (x - (D_ENEMY_ROOM_X)) < speed)
	{
		x = D_ENEMY_ROOM_X;
		ChangeDirection(onFieldX, onFieldY);
	}

	MoveStraight(onFieldX, onFieldY);

}

//----------------------------------
// ランダムに道を選ぶ
//----------------------------------
void CAbstractEnemy::ChooseRandomDirection(int x, int y)
{

	//後ろに反転しない処理のための準備
	int directionBack;
	directionBack = (direction + 2) % 4;//2回正の方向に動かす（反転）

	do
	{
		direction = GetRand(3);
		if (direction == directionBack)direction = 99;

		switch (direction)
		{
		case D_DIRECTION_UP:
			//上
			if (floor[y - 1][x] == D_BLOCK)
			{
				direction = 99;
			}
			break;

		case D_DIRECTION_LEFT:
			//左
			if (floor[y][x - 1] == D_BLOCK)
			{
				direction = 99;
			}
			break;

		case D_DIRECTION_DOWN:
			//下
			if (floor[y + 1][x] == D_BLOCK)
			{
				direction = 99;
			}
			break;

		case D_DIRECTION_RIGHT:
			//右
			if (floor[y][x + 1] == D_BLOCK)
			{
				direction = 99;
			}
			break;
			
		default:
			break;
		}

	} while (direction < 0 || 3 < direction);

}

//-----------------------------
// 巣の中にいる時の動き
//-----------------------------
void CAbstractEnemy::MoveInEnemyRoom()
{
	
	if (!isLeaveTheNest)
	{
		if (inTheNest_isUp)
		{
			targetPosY = D_ENEMY_ROOM_Y - 10;
		}
		else
		{
			targetPosY = D_ENEMY_ROOM_Y + 10;
		}
		targetPosY < y ? direction = D_DIRECTION_UP : direction = D_DIRECTION_DOWN;

		if (direction == D_DIRECTION_UP)
		{
			y -= 0.5f;
		}
		else if (direction == D_DIRECTION_DOWN)
		{
			y += 0.5f;
		}
		if (targetPosY == y)
		{
			inTheNest_isUp = !inTheNest_isUp;
		}
	}
}

//--------------------------------
// 食べられた時の動き
//--------------------------------
void CAbstractEnemy::EatenMove()
{
	if (isEaten)
	{
		if (-speed < (x - targetPosX) && (x - targetPosX) < speed
			&& -speed < (y - targetPosY) && (y - targetPosY) < speed)
		{
			x = targetPosX;
			y = targetPosY;
		}
		//巣の中に入ったら各種フラグを切り換える
		if ((double)x == targetPosX
			&& (double)y == targetPosY)
		{
			floor[D_DOOR_Y][D_DOOR_X] = D_BLOCK;
			floor[D_DOOR_Y][D_DOOR_X + 1] = D_BLOCK;
			inEnemyroom = true;
			isEaten = false;
			isSurprising = false;
			isLeaveTheNest = true;
		}
	}

}

//------------------------------------
//SE読み込み
//------------------------------------

void CAbstractEnemy::LoadSounds()
{
	//通常時のSEと、イジケ状態時のSE
	neutralSound = LoadSoundMem("sounds2/1.wav");//一段階目
	angerSound = LoadSoundMem("sounds2/2.wav");//二段階目
	furySound = LoadSoundMem("sounds2/3.wav");//三段階目
	wrathSound = LoadSoundMem("sounds2/4.wav");//四段階目
	izikeSound = LoadSoundMem("sounds2/6.wav");//イジケ状態
}