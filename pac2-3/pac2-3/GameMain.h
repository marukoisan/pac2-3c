#pragma once
#include"AbstractScene.h"

class GameMain : public AbstractScene
{
private://•Ï”éŒ¾

public:
	GameMain()
	{

	}

	~GameMain() {}

	AbstractScene* Update(XINPUT_STATE* data) override;

	void Draw() const override;
};

