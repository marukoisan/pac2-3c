#include "CAkabei.h"

//-------------------
// �R���X�g���N�^
//-------------------
CAkabei::CAkabei()
{
	inEnemyroom = false;
}

//----------------------------------
// ������
//----------------------------------
void CAkabei::Init()
{
	floor[D_DOOR_Y][D_DOOR_X] = D_BLOCK;
	floor[D_DOOR_Y][D_DOOR_X + 1] = D_BLOCK;
	x = initialPosX;
	y = initialPosY;
	direction = initialDirection;
	inEnemyroom = false;
	isSurprising = false;
	isEaten = false;
	isWhite = false;
	attackCycle = 0;
}

//---------------------------------------
// �����������i�v���C���[�j
//---------------------------------------
void CAkabei::HitAction_Player()
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