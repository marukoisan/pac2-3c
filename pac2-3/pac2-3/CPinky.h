#pragma once
#include "CAbstractEnemy.h"
class CPinky : public CAbstractEnemy
{
public:
	CPinky();
	~CPinky() {}

	//�������̊֐��Ƀs���L�[�̋����𐧌䂷�邽�߂̏���������
	//void SetTargetPos()override;
	void LoadImages()override;
};

