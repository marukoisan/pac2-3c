#pragma once
#include"DxLib.h"
#define PACMAN_IMAGE_MAX 12
#define ENEMY_IMAGE_MAX 2
#define ENEMYEYE_IMAGE_MAX 4


class CCoffeeBreak
{
private:
	float angle = 0;
	int images[PACMAN_IMAGE_MAX] = {};
	int animTimer = 0;
	int enemyImages[ENEMY_IMAGE_MAX] = {};
	int enemyEyes[ENEMYEYE_IMAGE_MAX] = {};
	bool anim;
	bool anim2;
	float pacmanSpeed;
	float bigPacmanSpeed;
	float akabeiSpeed;
	float izikeSpeed;
	int Timer;
public:
	CCoffeeBreak();
	~CCoffeeBreak() {}
	void Update() {}
	void Draw();
	void LoadImages();
};