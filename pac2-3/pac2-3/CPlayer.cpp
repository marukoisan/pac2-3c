#include"CPlayer.h"
#include"CController.h"


//--------------------
// コンストラクタ
//--------------------
CPlayer::CPlayer(CController* pController)
{
	controller = pController;
	keyState = controller->GetKeyState();
	directionX = D_PLAYER_LEFT;
	directionY = 99;
	nextDirection = D_PLAYER_LEFT;
	angle = -M_PI / 2;//左向き
	speed = MAKE_SPEED * 16.0f;
	isReleased = false;

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

	downSound = 0;//サウンド用変数の初期化
	LoadSounds();
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
	SpeedUpdate();

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
			
			animTimer = 0;
			isAlive = true;
			Respawn();
		}
	}


	static bool isOnCrossPointOld = false;
	static bool isOnCrossPointNow = false;

	isOnCrossPointOld = isOnCrossPointNow;
	if (floor[(int)(y + 10) / (int)D_TILE_SIZE][(int)(x + 10)/ (int)D_TILE_SIZE] == D_PLAYER_CROSSPOINT)
	{
		isOnCrossPointNow = true;
	}
	else
	{
		isOnCrossPointNow = false;
	}

	if (isOnCrossPointOld == true
		&& isOnCrossPointNow == false)
	{
		isReleased = true;
	}
	else
	{
		isReleased = false;
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
		
		if (animTimer < 9 * 11)
		{

			
			//描画
			DrawRotaGraphF(x + D_FIELD_POS_X, y + D_FIELD_POS_Y, 1, 0, pacmanDyings[animTimer / 9 % 11], TRUE);
			
		}
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
	if (direction == nextDirection)
	{
		angle = DIRECTIONS[nextDirection];

		if (isReleased)
		{
			if (directionX == nextDirection)
			{
				directionY = 99;
			}
			if (directionY == nextDirection)
			{
				directionX = 99;

			}
		}
	}
}

void CPlayer::Respawn() 
{
	x = 270;
	y = 460;

	directionX = D_PLAYER_LEFT;
	directionY = 99;
	nextDirection = D_PLAYER_LEFT;
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
	switch (directionY)
	{
	case D_PLAYER_UP:
		y -= speed;
		break;

	case D_PLAYER_DOWN:
		y += speed;
		break;

	default:
		;
	}

	switch (directionX)
	{
	case D_PLAYER_RIGHT:
		x += speed;
		break;

	case D_PLAYER_LEFT:
		x -= speed;
		break;

	default:
		;
	}
}

//---------------------
// コントロール
//---------------------
void CPlayer::Control()
{

	if (keyState->Buttons[XINPUT_BUTTON_DPAD_UP] == TRUE)
	{
		directionY = D_PLAYER_UP;
		nextDirection = D_PLAYER_UP;
	}

	if (keyState->Buttons[XINPUT_BUTTON_DPAD_RIGHT] == TRUE)
	{
		directionX = D_PLAYER_RIGHT;
		nextDirection = D_PLAYER_RIGHT;
	}

	if (keyState->Buttons[XINPUT_BUTTON_DPAD_DOWN] == TRUE)
	{
		directionY = D_PLAYER_DOWN;
		nextDirection = D_PLAYER_DOWN;
	}

	if (keyState->Buttons[XINPUT_BUTTON_DPAD_LEFT] == TRUE)
	{
		directionX = D_PLAYER_LEFT;
		nextDirection = D_PLAYER_LEFT;
	}
}

//---------------------
// プレイヤーワープ
//---------------------
void CPlayer::warp()
{
	if (D_FIELD_POS_X + x > D_FIELD_POS_X + D_FIELD_WIDTH * 20 - 20)
	{
		x = 0;
	}

	if (D_FIELD_POS_X + x < D_FIELD_POS_X)
	{
		x += D_FIELD_WIDTH * 20 - 20;
	}
}

//-----------------------
// スピードの更新
//-----------------------
void CPlayer::SpeedUpdate()
{
	if (powerTime >= 0)
	{
		if (eatTimeSp >= 0)
		{
			speed = MAKE_SPEED * SPEED_LEVEL[level][D_P_P_ATE];
		}
		else if (eatTime >= 0)
		{
			speed = MAKE_SPEED * SPEED_LEVEL[level][D_P_N_ATE];
		}
		else
		{
			speed = MAKE_SPEED * SPEED_LEVEL[level][D_P_N];
		}
	}
	else
	{
		if (eatTimeSp >= 0)
		{
			speed = MAKE_SPEED * SPEED_LEVEL[level][D_N_P_ATE];
		}
		else if (eatTime >= 0)
		{
			speed = MAKE_SPEED * SPEED_LEVEL[level][D_N_N_ATE];
		}
		else
		{
			speed = MAKE_SPEED * SPEED_LEVEL[level][D_N_N];
		}
	}

	powerTime--;
	eatTime--;
	eatTimeSp--;
}
}

void CPlayer::LoadSounds()
{
	downSound = LoadSoundMem("sounds2/regular2.wav");//サウンドの読み込み
}