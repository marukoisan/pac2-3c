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
	x = initialPosX;
	y = initialPosY;
	direction = initialDirection;
	inEnemyroom = false;
	isSurprising = false;
	isEaten = false;
	isWhite = false;
	attackCycle = 0;
}