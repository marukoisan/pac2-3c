#pragma once
#include"CPlayer.h"

class CCoffeeBreak2
{
private:
	int AnimTimer = 0;
	int images[D_PLAYER_IMAGE_MAX] = {};
	float angle;
	int enemyImages[2] = {};
	int enemyEyes[4] = {};
	bool anim;
	int bou;		//�_�摜�p�ϐ�
	int enemy;		//�G�摜�p�ϐ�
	int enemy2;		//�G�摜�p�ϐ�
	int enemy3;		//�G�摜�p�ϐ�
	float enemyx;		//�G���W
	float playerx;	//�v���C���[���W

	int coffeesound;	//�T�E���h�p�ϐ�

public:
	CCoffeeBreak2();
	~CCoffeeBreak2() {}
	void CoffeeBreakM2();
	int playsound();

};
