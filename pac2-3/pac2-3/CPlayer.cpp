#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include"CPlayer.h"
#include"CController.h"


//--------------------
// �R���X�g���N�^
//--------------------
CPlayer::CPlayer(CController* pController)
{
	controller = pController;
	keyState = controller->GetKeyState();
	direction = D_PLAYER_LEFT;
	angle = -M_PI / 2;//������

	animTimer = 0;
	
	LoadDivGraph("images/sprites/pacman.png", D_PLAYER_IMAGE_MAX,
		3, 1, 32, 32, images);

	LoadDivGraph("images/sprites/dying.png", 11, 11, 1, 32, 32, pacmanDyings);

	//�s�{�b�g�ʒu
	x = 270;
	y = 460;

	isAlive = true;

	//�����蔻��
	height = 20;
	width = 20;
}

//--------------------
// �f�X�g���N�^
//--------------------
CPlayer::~CPlayer()
{
	;
}

//--------------------
// �X�V
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
		//����ł����ꍇ����ł���̕b���𐔂��ă��X�|�[������
		if (animTimer > 9 * 11)
		{
			isAlive = true;
			Respawn();
		}
	}
}


//--------------------
// �`��
//--------------------
void CPlayer::Draw()const
{
	if (isAlive)
	{
		//�ʏ펞
		DrawRotaGraphF(D_FIELD_POS_X + x, D_FIELD_POS_Y + y, 1.0, angle,
			images[animTimer / D_PLAYER_ANIM_FPS % D_PLAYER_IMAGE_MAX], TRUE);
	}
	else
	{
		//�`��
		DrawRotaGraphF(x + D_FIELD_POS_X, y + D_FIELD_POS_Y, 1, 0, pacmanDyings[animTimer / 9 % 11], TRUE);
	}
	
	{
		int i = 0;
		DrawFormatString(0, 562 + 20 * i++, 0x750927, "%d", (int)isAlive);
		DrawFormatString(0, 562 + 20 * i++, 0x750927, "%d", animTimer);

	}
}


//--------------------
// �����������̏���
//--------------------

//--------------------
// �ړ�
//--------------------
void CPlayer::Move()
{
	MoveStraight();
}

//----------------------------
// �ړ������ɉ����������ړ�
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
// �R���g���[��
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



void CPlayer::HitAction_Enemy()
{
	if (isAlive)
	{
		animTimer = 0;
	}
	isAlive = false;
}

void CPlayer::Respawn() 
{
	x = 270;
	y = 460;

	direction = D_PLAYER_LEFT;
	angle = -M_PI / 2;//������
}

bool CPlayer::GetAnimFlg()
{
	return isAlive;
}

bool CPlayer::GetisAlive()
{
	return isAlive;
}