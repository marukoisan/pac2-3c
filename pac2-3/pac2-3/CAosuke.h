#pragma once
#include "CAbstractEnemy.h"
class CAosuke : public CAbstractEnemy
{
public:
	CAosuke();
	~CAosuke() {}

	//�������̊֐��ɃA�I�X�P�̋����𐧌䂷�邽�߂̏���������
	//void SetTargetPos()override;
	void LoadImages()override;

	void EatenMove()override;
};

