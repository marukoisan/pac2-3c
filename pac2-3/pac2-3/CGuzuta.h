#pragma once
#include "CAbstractEnemy.h"
class CGuzuta : public CAbstractEnemy
{
public:

	CGuzuta();
	~CGuzuta() {}


	//�������̊֐��ɃA�I�X�P�̋����𐧌䂷�邽�߂̏���������
	void SetTargetPos()override;
	void LoadImages()override;

	void EatenMove()override;

};

