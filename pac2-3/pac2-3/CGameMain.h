#pragma once
#include"CAbstractScene.h"
class CGameMain : public CAbstractScene
{
public:
	//�R���X�g���N�^
	CGameMain() {}
	//�f�X�g���N�^
	~CGameMain() {}

	//�X�V
	CAbstractScene* Update()override;
	//�`��
	void Draw()const override;
};

