#pragma once
#include "CAbstractScene.h"

class CField;
class CGameMain : public CAbstractScene
{
private:
	CField* field;

public:
	//�R���X�g���N�^
	CGameMain();
	//�f�X�g���N�^
	~CGameMain()override;

	//�X�V
	CAbstractScene* Update()override;
	//�`��
	void Draw()const override;
};

