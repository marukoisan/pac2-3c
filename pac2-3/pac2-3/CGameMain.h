#pragma once
#include "CAbstractScene.h"

class CField;
class CEsa;
class CGameMain : public CAbstractScene
{
private:
	CField* field;
	CEsa* esa;

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

