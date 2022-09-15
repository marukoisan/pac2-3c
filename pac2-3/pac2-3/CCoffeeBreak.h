#pragma once
#include "CPlayer.h"

class CCoffeeBreak
{
private:
	int images[D_PLAYER_IMAGE_MAX];
	int animPlayer[12];
	int animEnemy[20];
public:
	void CoffeeBreak();
	void LoadImages();
};