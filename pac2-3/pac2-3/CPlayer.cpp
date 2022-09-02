#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include"CPlayer.h"

//--------------------
// �R���X�g���N�^
//--------------------
CPlayer::CPlayer()
{
	direction = D_PLAYER_RIGHT;
	angle = M_PI / 2;

	animTimer = 0;
	
	LoadDivGraph("images/sprites/pacman.png", D_PLAYER_IMAGE_MAX,
		3, 1, 32, 32, images);

	//�s�{�b�g�ʒu
	x = 20;
	y = 20;

	//�����蔻��
	height = 0;
	width = 0;
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
	float directions[4] =
	{ 0,M_PI / 2,M_PI,-M_PI / 2 };
	static int timer = 0;
	timer++;/*
	if (timer == 60 * 3) {
		direction = D_PLAYER_DOWN;
		angle = directions[direction];
	}
	if (timer == 60 * 6) {
		direction = D_PLAYER_LEFT;
		angle = directions[direction];
	}
	if (timer == 60 * 9) {
		direction = D_PLAYER_UP;
		angle = directions[direction];
	}
	if (timer == 60 * 12) {
		direction = D_PLAYER_RIGHT;
		angle = directions[direction];
	}*/

	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) == PAD_INPUT_2)
	{
		direction = D_PLAYER_DOWN;
		angle = directions[direction];
	}


	Move();
}


//--------------------
// �`��
//--------------------
void CPlayer::Draw()const
{
	DrawRotaGraphF(D_FIELD_POS_X + x, D_FIELD_POS_Y + y, 1.0, angle,
		images[animTimer / D_PLAYER_ANIM_FPS % D_PLAYER_IMAGE_MAX], TRUE);
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