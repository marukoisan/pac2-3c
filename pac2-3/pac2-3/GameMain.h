#pragma once
#include"AbstractScene.h"

class GameMain : public AbstractScene
{
private://�ϐ��錾

public:
	GameMain()
	{

	}

	~GameMain() {}

	AbstractScene* Update(XINPUT_STATE* data) override;

	void Draw() const override;
};

