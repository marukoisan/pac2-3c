#pragma once
#include "CPlayer.h"


class CCoffeeBreak
{
private:
	float angle = 0;
	int images[D_PLAYER_IMAGE_MAX] = {};
	int animTimer = 0;
	int enemyImages[2] = {};
	int enemyEyes[4] = {};
	bool anim;
public:
	CCoffeeBreak();
	~CCoffeeBreak() {}
	void Update() {}
	void Draw();
};