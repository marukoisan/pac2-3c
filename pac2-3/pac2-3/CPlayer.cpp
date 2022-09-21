#include"CPlayer.h"
#include"CController.h"


//--------------------
// �R���X�g���N�^
//--------------------
CPlayer::CPlayer(CController* pController)
{
	controller = pController;
	keyState = controller->GetKeyState();
	directionX = D_PLAYER_LEFT;
	directionY = 99;
	nextDirection = D_PLAYER_LEFT;
	angle = -M_PI / 2;//������
	speed = MAKE_SPEED * 16.0f;
	isReleased = false;

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

	downSound = 0;//�T�E���h�p�ϐ��̏�����
	LoadSounds();
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
	SpeedUpdate();

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
		
		if (animTimer < 9 * 11)
		{

			
			//�`��
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
// �����������̏���:�G
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
// �����]��
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
	angle = -M_PI / 2;//������
}

bool CPlayer::GetisAlive()
{
	return isAlive;
}

//--------------------
// �ړ�
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
// �R���g���[��
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
// �v���C���[���[�v
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
// �X�s�[�h�̍X�V
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
	downSound = LoadSoundMem("sounds2/regular2.wav");//�T�E���h�̓ǂݍ���
}