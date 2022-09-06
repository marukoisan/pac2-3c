#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include"CPlayer.h"
#include"CController.h"


//--------------------
// コンストラクタ
//--------------------
CPlayer::CPlayer(CController* pController)
{
	controller = pController;
	keyState = controller->GetKeyState();
	direction = D_PLAYER_RIGHT;
	angle = M_PI / 2;//右向き

	animTimer = 0;
	
	LoadDivGraph("images/sprites/pacman.png", D_PLAYER_IMAGE_MAX,
		3, 1, 32, 32, images);

	//ピボット位置
	x = 20;
	y = 20;

	//当たり判定
	height = 10;
	width = 10;
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

	Control();
	Move();
}


//--------------------
// 描画
//--------------------
void CPlayer::Draw()const
{
	DrawRotaGraphF(D_FIELD_POS_X + x, D_FIELD_POS_Y + y, 1.0, angle,
		images[animTimer / D_PLAYER_ANIM_FPS % D_PLAYER_IMAGE_MAX], TRUE);
}


//--------------------
// 当たった時の処理
//--------------------

//--------------------
// 移動
//--------------------
void CPlayer::Move()
{
	MoveStraight();
}

//----------------------------
// 移動方向に応じた直線移動
//----------------------------
void CPlayer::MoveStraight()
{
	switch (direction)
	{
	case D_PLAYER_UP:
		y--;
		break;

	case D_PLAYER_RIGHT:
		x++;
		break;

	case D_PLAYER_DOWN:
		y++;
		break;

	case D_PLAYER_LEFT:
		x--;
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
	float directions[4] =
	{ 0,M_PI / 2,M_PI,-M_PI / 2 };

	if (keyState->Buttons[XINPUT_BUTTON_DPAD_UP] == TRUE)
	{
		direction = D_PLAYER_UP;
		angle = directions[direction];
	}

	if (keyState->Buttons[XINPUT_BUTTON_DPAD_RIGHT] == TRUE)
	{
		direction = D_PLAYER_RIGHT;
		angle = directions[direction];
	}

	if (keyState->Buttons[XINPUT_BUTTON_DPAD_DOWN] == TRUE)
	{
		direction = D_PLAYER_DOWN;
		angle = directions[direction];
	}

	if (keyState->Buttons[XINPUT_BUTTON_DPAD_LEFT] == TRUE)
	{
		direction = D_PLAYER_LEFT;
		angle = directions[direction];
	}
}
