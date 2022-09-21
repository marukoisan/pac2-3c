#pragma once
#include"DxLib.h"
#define PACMAN_IMAGE_MAX 12
#define BIGPACMAN_IMAGE_MAX 3
#define ENEMY_IMAGE_MAX 2
#define ENEMY_IZIKE_MAX 2


class CCoffeeBreak
{
private:
	int pacman[PACMAN_IMAGE_MAX] = {};
	int akabei[ENEMY_IMAGE_MAX] = {};
	
	int bigpacman[BIGPACMAN_IMAGE_MAX] = {};
	int izike[ENEMY_IZIKE_MAX] = {};

	
	bool anim;
	bool anim2;
	int animepacman;

	float pacmanX;
	float bigPacmanX;
	float akabeiX;
	float izikeX;

	float pacmanSpeed;
	float bigPacmanSpeed;
	float akabeiSpeed;
	float izikeSpeed;

	int Timer;
public:
	CCoffeeBreak();
	~CCoffeeBreak() {}
	void Update();
	void Draw() const;
	void LoadImages();
};