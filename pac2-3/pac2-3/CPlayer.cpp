#include"DxLib.h"
#include"CPlayer.h"
#include"CController.h"


//--------------------
// コンストラクタ
//--------------------
CPlayer::CPlayer(CController* pController)
{
	controller = pController;
	keyState = controller->GetKeyState();
	nextDirection = D_PLAYER_LEFT;
	direction = D_PLAYER_LEFT;
	angle = -M_PI / 2;//左向き
	speed = 2;

	animTimer = 0;
	
	LoadDivGraph("images/sprites/pacman.png", D_PLAYER_IMAGE_MAX,
		3, 1, 32, 32, images);

	LoadDivGraph("images/sprites/dying.png", 11, 11, 1, 32, 32, pacmanDyings);

	//ピボット位置
	x = 270;
	y = 460;

	isAlive = true;

	//当たり判定
	height = 20;
	width = 20;
}

//--------------------
// デストラクタ
//--------------------
CPlayer::~CPlayer()
{
	;
}

//--------------------
// 更新
//--------------------
void CPlayer::Update()
{
	animTimer++;
	if (isAlive)
	{
		Control();
		Move();
	}
	else
	{
		//死んでいた場合死んでからの秒数を数えてリスポーンする
		if (animTimer > 9 * 11)
		{
			isAlive = true;
			Respawn();
		}
	}
}


//--------------------
// 描画
//--------------------
void CPlayer::Draw()const
{
	if (isAlive)
	{
		//通常時
		DrawRotaGraphF(D_FIELD_POS_X + x, D_FIELD_POS_Y + y, 1.0, angle,
			images[animTimer / D_PLAYER_ANIM_FPS % D_PLAYER_IMAGE_MAX], TRUE);
	}
	else
	{
		//描画
		DrawRotaGraphF(x + D_FIELD_POS_X, y + D_FIELD_POS_Y, 1, 0, pacmanDyings[animTimer / 9 % 11], TRUE);
	}
	
	{
		int i = 0;
		DrawFormatString(0, 562 + 20 * i++, 0x750927, "%d", (int)isAlive);
		DrawFormatString(0, 562 + 20 * i++, 0x750927, "%d", animTimer);

	}
}


//--------------------
// 当たった時の処理:敵
//--------------------
void CPlayer::HitAction_Enemy()
{
	if (isAlive)
	{
		animTimer = 0;
	}
	isAlive = false;
}

//------------------------------
// 方向転換
//------------------------------
void CPlayer::ChangeDirection(int direction)
{
	static bool isOnCrossPointOld = false;
	static bool isOnCrossPointNow = false;

	isOnCrossPointOld = isOnCrossPointNow;
	if (direction == nextDirection)
	{
		angle = DIRECTIONS[direction];
		if (floor[(int)y % (int)D_TILE_SIZE][(int)x % (int)D_TILE_SIZE] == D_PLAYER_CROSSPOINT)
		{
			isOnCrossPointNow = true;
		}
		else
		{
			isOnCrossPointNow = false;
		}
	
		//if ((int)y % (int)D_TILE_SIZE <= 5
		//	//|| (int)y % (int)D_TILE_SIZE >= 19 
		//	&& (int)x % (int)D_TILE_SIZE <= 5
		//	//|| (int)x % (int)D_TILE_SIZE >= 19
		//	)
		if (isOnCrossPointOld == true
			&& isOnCrossPointNow == false)
		{
			this->direction = nextDirection;
			nextDirection = 99;
		}
	}
}

void CPlayer::Respawn() 
{
	x = 270;
	y = 460;

	nextDirection = D_PLAYER_LEFT;
	direction = D_PLAYER_LEFT;
	angle = -M_PI / 2;//左向き
}

bool CPlayer::GetisAlive()
{
	return isAlive;
}

//--------------------
// 移動
//--------------------
void CPlayer::Move()
{
	switch (direction)
	{
	case D_PLAYER_UP:
		y -= speed;
		break;

	case D_PLAYER_RIGHT:
		x += speed;
		break;

	case D_PLAYER_DOWN:
		y += speed;
		break;

	case D_PLAYER_LEFT:
		x -= speed;
		break;


	default:
		;
	}
	
	if (direction != nextDirection)
	{
		switch (nextDirection)
		{
		case D_PLAYER_UP:
			y -= speed;
			break;

		case D_PLAYER_RIGHT:
			x += speed;
			break;

		case D_PLAYER_DOWN:
			y += speed;
			break;

		case D_PLAYER_LEFT:
			x -= speed;
			break;


		default:
			;
		}
	}
}

//---------------------
// コントロール
//---------------------
void CPlayer::Control()
{

	if (keyState->Buttons[XINPUT_BUTTON_DPAD_UP] == TRUE)
	{
		if ((direction + 2) % 4 != D_PLAYER_UP)
		{
			nextDirection = D_PLAYER_UP;
		}
		else
		{
			direction = D_PLAYER_UP;
			angle = DIRECTIONS[direction];
			//nextDirection = 99;
		}

	}

	if (keyState->Buttons[XINPUT_BUTTON_DPAD_RIGHT] == TRUE)
	{
		if ((direction + 2) % 4 != D_PLAYER_RIGHT)
		{
			nextDirection = D_PLAYER_RIGHT;
		}
		else
		{
			direction = D_PLAYER_RIGHT;
			angle = DIRECTIONS[direction];
			//nextDirection = 99;
		}

	}

	if (keyState->Buttons[XINPUT_BUTTON_DPAD_DOWN] == TRUE)
	{
		if ((direction + 2) % 4 != D_PLAYER_DOWN)
		{
			nextDirection = D_PLAYER_DOWN;
		}
		else
		{
			direction = D_PLAYER_DOWN;
			angle = DIRECTIONS[direction];
			//nextDirection = 99;
		}
	}

	if (keyState->Buttons[XINPUT_BUTTON_DPAD_LEFT] == TRUE)
	{
		if ((direction + 2) % 4 != D_PLAYER_LEFT)
		{
			nextDirection = D_PLAYER_LEFT;
		}
		else
		{
			direction = D_PLAYER_LEFT;
			angle = DIRECTIONS[direction];
			//nextDirection = 99;
		}
	}
}
