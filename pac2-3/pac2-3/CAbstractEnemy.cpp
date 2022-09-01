#include"DxLib.h"
#include"CAbstractEnemy.h"

#define _USE_MATH_DEFINES
#include<math.h>

//---------------------------
// �R���X�g���N�^
//---------------------------
CAbstractEnemy::CAbstractEnemy()
{
	direction = D_DIRECTION_DOWN;
	x = 20;  //�t�B�[���h�����0�Ƃ����Ƃ���x���W�Ƃ���
	y = 20;  //�t�B�[���h�����0�Ƃ����Ƃ���y���W�Ƃ���
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
	MoveToTarget();


	//�f�o�b�O�p�^�[�Q�b�g�̈ʒu�X�V
	if ((int)x / (int)D_TILE_SIZE == targetPosX &&
		(int)y / (int)D_TILE_SIZE == targetPosY)
	{
		do
		{
			targetPosX = GetRand(D_FIELD_WIDTH - 1);
			targetPosY = GetRand(D_FIELD_HEIGHT - 1);

		} while (floor[targetPosY][targetPosX] == 0);
	}
	//----------------

	static int animTimer = 0;
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
	//�f�o�b�O�p�t�B�[���h�̐��l
	//for (int i = 0; i < D_FIELD_HEIGHT; i++)
	//{
	//	for (int j = 0; j < D_FIELD_WIDTH; j++)
	//	{
	//		if (floor[i][j] > 0)
	//		{
	//			DrawRotaGraphF(/* x */D_FIELD_POS_X + j * D_TILE_SIZE, /* y */D_FIELD_POS_Y + i * D_TILE_SIZE,
	//				/* �g�嗦 */1.0 , 0, testNums[floor[i][j]], TRUE);
	//		}
	//	}
	//}

	
	DrawRotaGraphF(D_FIELD_POS_X + x, D_FIELD_POS_Y + y,
		1.0 , 0, enemyImages[anim], TRUE);
	
	DrawRotaGraphF(D_FIELD_POS_X + x, D_FIELD_POS_Y + y,
		1.0 , 0, enemyEyes[direction/ D_SEPARATE_ANGLE], TRUE);

	//�f�o�b�O�p�^�[�Q�b�g�ʒu�̕\��
	DrawBoxAA(D_FIELD_POS_X + targetPosX * D_TILE_SIZE - D_TILE_SIZE / 4
		, D_FIELD_POS_Y + targetPosY * D_TILE_SIZE - D_TILE_SIZE / 4
		, D_FIELD_POS_X + targetPosX * D_TILE_SIZE + D_TILE_SIZE / 4
		, D_FIELD_POS_Y + targetPosY * D_TILE_SIZE + D_TILE_SIZE / 4,
		0xFF0000, TRUE);

	DrawLine(D_FIELD_POS_X + x, D_FIELD_POS_Y + y,
		D_FIELD_POS_X + targetPosX * D_TILE_SIZE, 
		D_FIELD_POS_Y + targetPosY * D_TILE_SIZE, 0xFF0000);

	//�G�ʒu�̃t�B�[���h�����W�̕\��
	//DrawFormatString(0, 80+20*0, 0xFFFFFF, "Y���W�F%d", (int)y / (int)D_TILE_SIZE % D_FIELD_HEIGHT);
	//DrawFormatString(0, 80+20*1, 0xFFFFFF, "X���W�F%d", (int)x / (int)D_TILE_SIZE % D_FIELD_WIDTH);
}

//-------------------------
// �����������̏���
//-------------------------
void CAbstractEnemy::HitAction()
{

}

//-------------------------
// �ړ�
//-------------------------
void CAbstractEnemy::MoveToTarget()
{
	//�}�X���W
	int onFieldX = (int)x / (int)D_TILE_SIZE;
	int onFieldY = (int)y / (int)D_TILE_SIZE;

	//�}�X�̒��x�^�񒆂ɗ�����
	if ((int)x % (int)D_TILE_SIZE == 0 
		&& (int)y % (int)D_TILE_SIZE == 0)
	{
		//���̃}�X�������_��������
		if (floor[onFieldY][onFieldX] == D_CROSSPOINT)
		{
			//�����̌v�Z������
			ChangeDirection(onFieldX,onFieldY);
		}
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
		y--;
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
// �����]��
//-------------------------
void CAbstractEnemy::ChangeDirection(int x,int y)
{
	int distance = D_DISTANCE_MAX;
	int tmp = 0;
	int directionBack;
	directionBack = direction + 180;//���̏��̂��߁A180�x���Z����
	if (directionBack > D_DIRECTION_RIGHT)
	{
		directionBack -= 360;//�����ł���E�����܂ł𒴂��������߂�
	}
	
	/*
	�㉺���E�̃}�X���ǂłȂ����Ƃ��m�F���āA
	��̃}�X����ڕW�܂ł̋������v�Z���A
	�����΂�߂�������ʂ�B
	�܂��A�l�������ꍇ�́A�D��̂��̂��� �㍶���E �Ƃ���B
	*/

	//��
	if (directionBack != D_DIRECTION_UP) 
	{
		if (floor[y - 1][x] != D_BLOCK)
		{
			distance = pow(((double)x - targetPosX), 2.0) + 
				pow((double)y - 1 - targetPosY, 2.0);
			direction = D_DIRECTION_UP;
		}

	}

	//��
	if (directionBack != D_DIRECTION_LEFT)
	{
		if (floor[y][x - 1] != D_BLOCK)
		{
			tmp = pow((double)x - 1 - targetPosX, 2.0) +
				pow((double)y - targetPosY, 2.0);
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
			tmp = pow((double)x - targetPosX, 2.0) +
				pow((double)y + 1 - targetPosY, 2.0);

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
			tmp = pow((double)x + 1 - targetPosX, 2.0) +
				pow((double)y - targetPosY, 2.0);
			if (tmp < distance)
			{
				distance = tmp;
				direction = D_DIRECTION_RIGHT;
			}
		}
	}
}
