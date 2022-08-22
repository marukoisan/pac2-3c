#pragma once
#include "CAbstractScene.h"

class CPlayer;
class CGameMain : public CAbstractScene
{
private:
	CPlayer* player;

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

