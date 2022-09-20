#pragma once
#include "CAbstractScene.h"

#define D_TITLE_POS_X (360)

class CTitle : public CAbstractScene
{
private:

	int charactar_strImage;

public:
	CTitle();
	~CTitle() {}
	//XV
	CAbstractScene* Update()override;
	//•`‰æ
	void Draw()const override;
};

