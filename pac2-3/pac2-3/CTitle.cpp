#include<stdio.h>
#include"DxLib.h"
#include "CTitle.h"
#include"CGameMain.h"
#define TILESIZE 20

int z;
int i = 1;
//----------------------------
// �R���X�g���N�^
//----------------------------
CTitle::CTitle()
{
	charactar_strImage = LoadGraph("images/character_str.png");


	//�摜�ǂݍ���
	nickname = LoadGraph("images/nickname.png");
	akabei_font = LoadGraph("images/akabei.png");
	pinky_font = LoadGraph("images/PINKY.png");
	aosuke_font = LoadGraph("images/AOSUKE.png");
	guzuta_font = LoadGraph("images/guzuta.png");
	highscore = LoadGraph("images/highscore.png");
	slash = LoadGraph("images/slash.png");
	nickname = LoadGraph("images/nickname.png");
	oikake = LoadGraph("images/oikake.png");
	machibuse = LoadGraph("images/machibuse.png");
	kimagure = LoadGraph("images/kimagure.png");
	otoboke = LoadGraph("images/otoboke.png");
	akabei_title = LoadGraph("images/akabei_title.png");
	pinky_title = LoadGraph("images/pinky_title.png");
	aosuke_title = LoadGraph("images/aosuke_title.png");
	guzuta_title = LoadGraph("images/guzuta_title.png");
	esa = LoadGraph("images/tiles/big_dot.png");
	pressA = LoadGraph("images/pressA.png");


	//�p�b�N�}��
	LoadDivGraph("images/sprites/pacman.png", D_PLAYER_IMAGE_MAX, 3, 1, 32, 32, pacman);

	//�G�l�~�[
	LoadDivGraph("images/sprites/monster.png", 20, 20, 1, 32, 32, enemy);
	LoadDivGraph("images/sprites/eyes.png", 4, 4, 1, 32, 32, enemyEyes);
}

//---------------------
// �X�V
//---------------------
CAbstractScene* CTitle::Update()
{
	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) == PAD_INPUT_2)
	{
		timer=28*10;
	}
	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) == PAD_INPUT_3)
	{
		saveData = 3;
	}

	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) == PAD_INPUT_1)
	{
		return new CGameMain;
	}


	timer++;

	if (timer % 20==0)
	{
		isShow = !isShow;
	}
	//�p�b�N�}���X�s�[�h
	if (timer >270 && timer< 438)
	{
		angle = -M_PI / 2;	//������
		pacmanx -= 24.0 * D_TILE_SIZE / 168;
	}


	//�G�l�~�[
	if (timer % 8 == 0)//8�̓t���[����
	{
		anim = !anim;
	}

	if (timer / 15 >= 18 && timer / 15 < 28)
	{
		enemyx -= 3.05;
		eye = 1;
	}



	pacx = D_TITLE_POS_X + 28 * TILESIZE + pacmanx;

	teki1x = D_TITLE_POS_X + 30 * TILESIZE + enemyx;

	teki2x = D_TITLE_POS_X + 30 * TILESIZE + enemyx + 40;

	teki3x = D_TITLE_POS_X + 30 * TILESIZE + enemyx + 80;

	teki4x = D_TITLE_POS_X + 30 * TILESIZE + enemyx + 120;

	return this;
}

//---------------------
// �`��
//---------------------
void CTitle::Draw()const
{

	//DrawGraph(D_TITLE_POS_X +  9 * TILESIZE,   0, highscore, TRUE);

	DrawGraph(D_TITLE_POS_X +  7 * TILESIZE, 100, charactar_strImage, TRUE);
	DrawGraph(D_TITLE_POS_X + 18 * TILESIZE, 100, slash, TRUE);
	DrawGraph(D_TITLE_POS_X + 21 * TILESIZE, 100, nickname, TRUE);


	//�A�J�x�C
	if (timer / 15 >= 1)
	{
		DrawRotaGraphF(D_TITLE_POS_X + 5 * TILESIZE, 145, 1.8, 0, akabei_title, TRUE);
	}
	if (timer / 15 >= 3)
	{
		DrawGraph(D_TITLE_POS_X +  8 * TILESIZE, 140, oikake, TRUE);
	}
	if (timer / 15 >= 4)
	{
		DrawGraph(D_TITLE_POS_X + 18 * TILESIZE, 140, akabei_font, TRUE);

	}


	//�s���L�[
	if (timer / 15 >= 5)
	{
		DrawRotaGraphF(D_TITLE_POS_X + 5 * TILESIZE, 185, 1.8, 0, pinky_title, TRUE);
	}
	if (timer / 15 >= 7)
	{
		DrawGraph(D_TITLE_POS_X +  8 * TILESIZE, 180, machibuse, TRUE);
	}
	if (timer / 15 >= 8)
	{
		DrawGraph(D_TITLE_POS_X + 19 * TILESIZE, 180, pinky_font, TRUE);
	}


	//�A�I�X�P
	if (timer / 15 >= 9)
	{
		DrawRotaGraphF(D_TITLE_POS_X + 5 * TILESIZE, 225, 1.8, 0, aosuke_title, TRUE);
	}
	if (timer / 15 >= 11)
	{
		DrawGraph(D_TITLE_POS_X +  8 * TILESIZE, 220, kimagure, TRUE);
	}
	if (timer / 15 >= 12)
	{
		DrawGraph(D_TITLE_POS_X + 18 * TILESIZE, 220, aosuke_font, TRUE);
	}


	//�O�Y�^
	if (timer / 15 >= 13)
	{
		DrawRotaGraphF(D_TITLE_POS_X + 5 * TILESIZE, 265, 1.8, 0, guzuta_title, TRUE);
	}
	if (timer / 15 >= 15)
	{
		DrawGraph(D_TITLE_POS_X +  8 * TILESIZE, 260, otoboke, TRUE);
	}
	if (timer / 15 >= 16)
	{
		DrawGraph(D_TITLE_POS_X + 18 * TILESIZE, 260, guzuta_font, TRUE);
	}

	if (timer > 270 && isShow)
	{
		DrawGraph(D_TITLE_POS_X + 50, 21 * D_TILE_SIZE, pressA,TRUE);
	}

}

void CTitle::enemyhit() const
{
	if (pacx + 25 >= teki1x)i = 2;
	if (pacx + 25 >= teki2x)i = 3;
	if (pacx + 25 >= teki3x)i = 4;
	if (pacx + 25 >= teki4x)i = 5;
}