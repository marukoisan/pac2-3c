#pragma once
#include "CAbstractEnemy.h"
#include "CAkabei.h"
class CAosuke : public CAbstractEnemy
{
private:
	CAkabei* akabei;
public:
	CAosuke();
	~CAosuke() {}

	void SetAkabei(CAkabei* pAkabei) { akabei = pAkabei; }
	
	//�������̊֐��ɃA�I�X�P�̋����𐧌䂷�邽�߂̏���������
	void SetTargetPos()override;
	void LoadImages()override;

	void EatenMove()override;
};

