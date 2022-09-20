#include"DxLib.h"
#include"CAbstractEnemy.h"


#define _USE_MATH_DEFINES
#include<math.h>


//---------------------------
// �R���X�g���N�^
//---------------------------
CAbstractEnemy::CAbstractEnemy()
{
	LoadSounds();
	LoadImages();
	direction = initialDirection;
	x = initialPosX;  //�t�B�[���h�����0�Ƃ����Ƃ���x���W�Ƃ���
	y = initialPosY;  //�t�B�[���h�����0�Ƃ����Ƃ���y���W�Ƃ���
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
// �f�X�g���N�^
//---------------------------
CAbstractEnemy::~CAbstractEnemy()
{

}

//----------------------------
// �X�V
//----------------------------
void CAbstractEnemy::Update()
{
	if (GetisAttack())
	{
		SetTargetPos();
	}

	//�ړ��p�^�[���̐���
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

	//�C�W�P��Ԑ���p�ϐ��̍X�V
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
		//�g��U���p����
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

	//�A�j���[�V��������p�ϐ��̍X�V
	animTimer++;
	if (animTimer % 8 == 0)//8�̓t���[����
	{
		anim = !anim;
	}
}

//----------------------------
// �`��
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
			//�C�W�P��Ԏ��̕`��
			DrawRotaGraphF(D_FIELD_POS_X + x, D_FIELD_POS_Y + y,
				1.0, 0, surprisingImages[isWhite][anim], TRUE);
		}
		else
		{
			//�ʏ펞�̕`��
			DrawRotaGraphF(D_FIELD_POS_X + x, D_FIELD_POS_Y + y,
				1.0, 0, enemyImages[anim], TRUE);

			DrawRotaGraphF(D_FIELD_POS_X + x, D_FIELD_POS_Y + y,
				1.0, 0, enemyEyes[direction], TRUE);
		}
	}

	//�f�o�b�O�p������������-------------------------------------------------------------------------------
	
	//�f�o�b�O�p�^�[�Q�b�g�ʒu�̕\��
	DrawBoxAA(D_FIELD_POS_X + targetPosX - D_TILE_SIZE / 4
		, D_FIELD_POS_Y + targetPosY - D_TILE_SIZE / 4
		, D_FIELD_POS_X + targetPosX + D_TILE_SIZE / 4
		, D_FIELD_POS_Y + targetPosY + D_TILE_SIZE / 4,
		0xFF0000, TRUE);

	DrawLineAA(D_FIELD_POS_X + x, D_FIELD_POS_Y + y,
		D_FIELD_POS_X + targetPosX, 
		D_FIELD_POS_Y + targetPosY, 0xFF0000);

	//�G�ʒu�̃t�B�[���h�����W�̕\��
	//DrawFormatString(0, 80+20*0, 0xFFFFFF, "Y���W�F%d", (int)y / (int)D_TILE_SIZE % D_FIELD_HEIGHT);
	//DrawFormatString(0, 80+20*1, 0xFFFFFF, "X���W�F%d", (int)x / (int)D_TILE_SIZE % D_FIELD_WIDTH);
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
	////�f�o�b�O�p�t�B�[���h�̐��l
	//for (int i = 0; i < D_FIELD_HEIGHT; i++)
	//{
	//	for (int j = 0; j < D_FIELD_WIDTH; j++)
	//	{
	//		if (floor[i][j] > 0)
	//		{
	//			DrawRotaGraphF(D_FIELD_POS_X + j * D_TILE_SIZE, //x
	//				D_FIELD_POS_Y + i * D_TILE_SIZE,//y
	//				1.0 // �g�嗦 
	//				, 0, testNums[floor[i][j]], TRUE);
	//		}
	//	}
	//}

	
	//----------------------------------------------------------------�f�o�b�O�p���������܂�

}

//-------------------------
// �����������̏���
//-------------------------
void CAbstractEnemy::HitAction()
{

}

//---------------------------
// �C�W�P��Ԃւ̑J��
//---------------------------
void CAbstractEnemy::Surprised()
{
	
	isWhite = false;
	isSurprising = true;
	surprisingTimer = surprisingTime;
	if (!isEaten)
	{
		direction = (direction + 2) % 4;
		PlaySoundMem(izikeSound, DX_PLAYTYPE_LOOP, TRUE);//�C�W�P��Ԓ��炷
	}
}

//--------------------------------
// �����������i�v���C���[�j
//--------------------------------
void CAbstractEnemy::HitAction_Player()
{
	if (isSurprising)
	{
		isEaten = true;

		floor[D_DOOR_Y][D_DOOR_X] = D_FLOOR;
		floor[D_DOOR_Y][D_DOOR_X + 1] = D_FLOOR;

		//���̒�
		targetPosX = 13 * D_TILE_SIZE + 10;
		targetPosY = 14 * D_TILE_SIZE;
	}
}

//----------------------------------
// ������
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
// �摜�ǂݍ���
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
// �ړ�
//-------------------------
void CAbstractEnemy::MoveToTarget()
{
	//�}�X���W
	int onFieldX = (int)x / (int)D_TILE_SIZE;
	int onFieldY = (int)y / (int)D_TILE_SIZE;

	float centerX = onFieldX * D_TILE_SIZE;  //������}�X�̒��S���W
	float centerY = onFieldY * D_TILE_SIZE;  //������}�X�̒��S���W

		//���̃}�X�������_��������
	if (floor[onFieldY][onFieldX] == D_CROSSPOINT)
	{

		//�}�X�̐^�񒆕t�߂ɗ�����
		if (-speed < (x - centerX) && (x - centerX) < speed
			&& -speed < (y - centerY) && (y - centerY) < speed)
		{
			y = centerY;
			x = centerX;
			//�����̌v�Z������
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
// ���i�ړ�
//------------------------
void CAbstractEnemy::MoveStraight(int onFieldX,int onFieldY)
{
	/*
	�ecase���ł̏���
	�E�����ɉ������l�̍X�V
	�E�ړ���Ɂi1�}�X��j�ǂ���������A
		����������}�X�̒��S�̍��W���Ǒ��ɂ��Ȃ��悤�ɂ���
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
// �����]��
//-------------------------
void CAbstractEnemy::ChangeDirection(int x,int y)
{
	int distance = D_DISTANCE_MAX;
	int tmp = 0;

	//���ɔ��]���Ȃ������̂��߂̏���
	int directionBack;
	directionBack = (direction + 2) % 4;//2�񐳂̕����ɓ������i���]�j
	
	/*
	�㉺���E�̃}�X���ǂłȂ����Ƃ��m�F���āA
	��̃}�X����ڕW�܂ł̋������v�Z���A
	�����΂�߂�������ʂ�B
	�܂��A�l�������ꍇ�́A�D��̂��̂��� �㍶���E �Ƃ���B
	*/

	//��
	if (directionBack != D_DIRECTION_UP)
	{
		if (floor[y - 1][x] != D_BLOCK && floor[y - 1][x] != D_VALVE)
		{
			distance =(int)( pow((double)x - targetPosX / D_TILE_SIZE, 2.0) +
							 pow((double)y - 1 - targetPosY / D_TILE_SIZE, 2.0));
			direction = D_DIRECTION_UP;
		}

	}

	//��
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

	//��
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

	//�E
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
// �g��U��
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
// ������̉�� 
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
// �C�W�P��Ԃ̓���
//-------------------------------------------
void CAbstractEnemy::SurprisingMove()
{
	//�}�X���W
	int onFieldX = (int)x / (int)D_TILE_SIZE;
	int onFieldY = (int)y / (int)D_TILE_SIZE;

	float centerX = onFieldX * D_TILE_SIZE;  //������}�X�̒��S���W
	float centerY = onFieldY * D_TILE_SIZE;  //������}�X�̒��S���W

		//���̃}�X�������_��������
	if (floor[onFieldY][onFieldX] == D_CROSSPOINT)
	{

		//�}�X�̐^�񒆕t�߂ɗ�����
		if (-speed < (x - centerX) && (x - centerX) < speed
			&& -speed < (y - centerY) && (y - centerY) < speed)
		{
			y = centerY;
			x = centerX;
			//�����̌v�Z������
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
// �����_���ɓ���I��
//----------------------------------
void CAbstractEnemy::ChooseRandomDirection(int x, int y)
{

	//���ɔ��]���Ȃ������̂��߂̏���
	int directionBack;
	directionBack = (direction + 2) % 4;//2�񐳂̕����ɓ������i���]�j

	do
	{
		direction = GetRand(3);
		if (direction == directionBack)direction = 99;

		switch (direction)
		{
		case D_DIRECTION_UP:
			//��
			if (floor[y - 1][x] == D_BLOCK)
			{
				direction = 99;
			}
			break;

		case D_DIRECTION_LEFT:
			//��
			if (floor[y][x - 1] == D_BLOCK)
			{
				direction = 99;
			}
			break;

		case D_DIRECTION_DOWN:
			//��
			if (floor[y + 1][x] == D_BLOCK)
			{
				direction = 99;
			}
			break;

		case D_DIRECTION_RIGHT:
			//�E
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
// ���̒��ɂ��鎞�̓���
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
// �H�ׂ�ꂽ���̓���
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
		//���̒��ɓ�������e��t���O��؂芷����
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
//SE�ǂݍ���
//------------------------------------

void CAbstractEnemy::LoadSounds()
{
	//�ʏ펞��SE�ƁA�C�W�P��Ԏ���SE
	neutralSound = LoadSoundMem("sounds2/1.wav");//��i�K��
	angerSound = LoadSoundMem("sounds2/2.wav");//��i�K��
	furySound = LoadSoundMem("sounds2/3.wav");//�O�i�K��
	wrathSound = LoadSoundMem("sounds2/4.wav");//�l�i�K��
	izikeSound = LoadSoundMem("sounds2/6.wav");//�C�W�P���
}