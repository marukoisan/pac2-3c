#pragma once
#include "CAbstractScene.h"
class CTitle : public CAbstractScene
{
private:

public:
	//�X�V
	CAbstractScene* Update()override;
	//�`��
	void Draw()const override;
};

