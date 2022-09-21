#pragma once
#include "CAbstractScene.h"
#include"CPlayer.h"

#define D_TITLE_POS_X (360)

class CTitle : public CAbstractScene
{
private:

	int charactar_strImage;

	//�摜�p�ϐ�
	int akabei_font;
	int pinky_font;
	int aosuke_font;
	int guzuta_font;
	int highscore;
	int slash;
	int nickname;
	int oikake;
	int machibuse;
	int kimagure;
	int otoboke;
	int akabei_title;
	int pinky_title;
	int aosuke_title;
	int guzuta_title;
	int esa;

	//�^�C�}�[
	int timer;

	//����
	float angle;

	//�p�b�N�}���A�j���[�V����
	int pacman[D_PLAYER_IMAGE_MAX] = {};

	//�p�b�N�}���X�s�[�h
	float pacmanx;

	//�G�l�~�[
	int enemy[20] = {};		//�A�J
	int enemyEyes[4] = {};
	float enemyx;
	bool anim;

	int pacx;
	int teki1x;
	int teki2x;
	int teki3x;
	int teki4x;

	int eye;


public:
	CTitle();
	~CTitle() {}
	//�X�V
	CAbstractScene* Update()override;
	//�`��
	void Draw()const override;
	//�����蔻��
	void enemyhit()const;
};

