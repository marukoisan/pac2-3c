#include"DxLib.h"
#include"CAbstractEnemy.h"

//---------------------------
// �R���X�g���N�^
//---------------------------
CAbstractEnemy::CAbstractEnemy()
{
	direction = D_DIRECTION_RIGHT;
	x = 20;
	y = 20;
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
	x++;
	static int animTimer = 0;
	animTimer++;
	if (animTimer % 8 == 0)//30�̓t���[����
	{
		anim = !anim;
	}
}

//----------------------------
// �`��
//----------------------------
void CAbstractEnemy::Draw()const
{
	for (int i = 0; i < D_FIELD_HEIGHT; i++)
	{
		for (int j = 0; j < D_FIELD_WIDTH; j++)
		{
			if (floor[i][j] > 0)
			{
				DrawRotaGraphF(/* x */D_FIELD_POS_X + j * D_TILE_SIZE, /* y */D_FIELD_POS_Y + i * D_TILE_SIZE,
					/* �g�嗦 */1.0 , 0, testNums[floor[i][j]], TRUE);
			}
		}
	}

	
	DrawRotaGraphF(D_FIELD_POS_X + x, D_FIELD_POS_Y + y,
		1.0 , 0, enemyImages[anim], TRUE);
	
	DrawRotaGraphF(D_FIELD_POS_X + x, D_FIELD_POS_Y + y,
		1.0 , 0, enemyEyes[direction], TRUE);

	//�f�o�b�O�p�^�[�Q�b�g�ʒu�̕\��
	DrawBox(D_FIELD_POS_X + targetPosX * D_TILE_SIZE - D_TILE_SIZE / 4
		, D_FIELD_POS_Y + targetPosY * D_TILE_SIZE - D_TILE_SIZE / 4
		, D_FIELD_POS_X + targetPosX * D_TILE_SIZE + D_TILE_SIZE / 4
		, D_FIELD_POS_Y + targetPosY * D_TILE_SIZE + D_TILE_SIZE / 4,
		0xFF0000, TRUE);
}