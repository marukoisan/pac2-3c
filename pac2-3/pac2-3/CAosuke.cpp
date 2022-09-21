#include "CAosuke.h"


//---------------------------------------
// �R���X�g���N�^
//---------------------------------------
CAosuke::CAosuke()
{
	LoadImages();

	restAreaX = 26;
	restAreaY = 29;

	initialPosX = D_ENEMY_ROOM_X - 40;
	initialPosY = 14 * D_TILE_SIZE;
	initialDirection = D_DIRECTION_UP;

	x = initialPosX;
	y = initialPosY;
	direction = initialDirection;
}

//---------------------------------------
// �^�[�Q�b�g�ʒu�̍X�V
//---------------------------------------
void CAosuke::SetTargetPos()
{
	//���}�X����Ă�H
	int gridX =
		(akabei->GetX() - player->GetX()) / D_TILE_SIZE;
	int gridY =
		(akabei->GetY() - player->GetY()) / D_TILE_SIZE;

	//���ꂼ��̋������v���C���[�𒆐S�ɔ��]�����ĉ��Z����
	targetPosX =
		player->GetX() + (gridX * -1) * D_TILE_SIZE;
	targetPosY =
		player->GetY() + (gridY * -1) * D_TILE_SIZE;
	
}


//---------------------------------------
// �摜�̓ǂݍ���
//---------------------------------------
void CAosuke::LoadImages()
{
		
	int* images = new int[20];

	LoadDivGraph("images/testNum.png", 10, 10, 1, 20, 20, testNums);
	LoadDivGraph("images/sprites/eyes.png", 4, 4, 1, 32, 32, enemyEyes);
	LoadDivGraph("images/sprites/monster.png", 20, 20, 1, 32, 32, images);
	enemyImages[0] = images[4];
	enemyImages[1] = images[5];
	surprisingImages[0][0] = images[20 - 4];
	surprisingImages[0][1] = images[20 - 3];
	surprisingImages[1][0] = images[20 - 2];
	surprisingImages[1][1] = images[20 - 1];
	delete[] images;
}


//--------------------------------
// �H�ׂ�ꂽ���̓���
//--------------------------------
void CAosuke::EatenMove()
{
	if (isEaten)
	{
		static bool step = false;
		if (-speed < (x - targetPosX) && (x - targetPosX) < speed
			&& -speed < (y - targetPosY) && (y - targetPosY) < speed)
		{
			x = targetPosX;
			y = targetPosY;
		}
		//���̒��ɓ�������e��t���O��؂芷����
		if ((double)x == targetPosX
			&& (double)y == targetPosY
			&& !step)
		{
			targetPosX = initialPosX;
			targetPosY= initialPosY;

			step = true;
		}
		if ((double)x == targetPosX
			&& (double)y == targetPosY
			&& step)
		{
			floor[D_DOOR_Y][D_DOOR_X] = D_BLOCK;
			floor[D_DOOR_Y][D_DOOR_X + 1] = D_BLOCK;
			inEnemyroom = true;
			isEaten = false;
			isSurprising = false;
			isLeaveTheNest = true;

			step = false;
		}
	}

}