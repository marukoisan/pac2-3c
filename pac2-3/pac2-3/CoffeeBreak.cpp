#include<stdio.h>
#include"DxLib.h"
#include"CoffeeBreak.h"
#include"define.h"
#include"CPlayer.h"
#define _USE_MATH_DEFINES
#include<math.h>

//---------------------
// �R���X�g���N�^
//---------------------
Coffee::Coffee()
{
	bool err = FALSE;

	if (LoadDivGraph("images/sprites/pacman.png", D_PLAYER_IMAGE_MAX,
			3, 1, 32, 32, images) == -1)err = true;
	
	enemy  = LoadGraph("images/sprites/pac-enemy.png");
	enemy2 = LoadGraph("images/sprites/pac-enemy2.png");
	enemy3 = LoadGraph("images/sprites/pac-enemy3.png");

	bou = LoadGraph("images/sprites/pac-bou.png");


	LoadDivGraph("images/sprites/monster.png", 2, 2, 1, 32, 32, enemyImages);
	LoadDivGraph("images/sprites/eyes.png", 4, 4, 1, 32, 32, enemyEyes);

	anim = false;
	
}
//---------------------
// �R�[�q�[�u���C�N
//---------------------
void Coffee::CoffeeBreakM2()
{
	static float playerx = 1000;
	static float enemyx = 1050;

	++AnimTimer;

	/*if (enemyx >= 700)
	{
		
	}*/

	enemyx -= 2.1;

	playerx-= 2;

	angle = -M_PI / 2;	//������

	if (AnimTimer % 8 == 0)//8�̓t���[����
	{
		anim = !anim;
	}

	if (playerx < 360)	//�v���C���[�̍��W��360�ȉ��ɂȂ��������
	{
		images[2] = 0;
		images[1] = 0;
		images[0] = 0;
	}

	


	DrawFormatString(0, 120, 0xffffff, "%d", enemyx);

	DrawRotaGraphF(playerx, 360, 1.0, angle, images[AnimTimer / D_PLAYER_ANIM_FPS % D_PLAYER_IMAGE_MAX], TRUE);
	DrawRotaGraphF(enemyx, 360, 1.0, 0, enemyImages[anim], TRUE);	//�G�̑�
	
	DrawRotaGraphF(700, 360, 0.5, 0, bou, TRUE);	//�_

	if (enemyx < 700)
	{
		enemyImages[0] = 0;
		enemyImages[1] = 0;
		/*enemyEyes[1] = 0;*/

		/*enemyx = 700;*/

		if (enemyx > 500)
		{
			DrawRotaGraphF(700, 360, 0.35, 0, enemy, TRUE);
			DrawRotaGraphF(700, 360, 1.0, 0, enemyEyes[1], TRUE);	//�G�̖�
		}
		else if (enemyx < 500 && enemyx > 300)
		{
			DrawRotaGraphF(695, 360, 0.35, 0, enemy2, TRUE);
			DrawRotaGraphF(695, 360, 1.0, 0, enemyEyes[1], TRUE);	//�G�̖�
		}
		else if (enemyx < 300 && enemyx > 200)
		{
			DrawRotaGraphF(685, 360, 0.35, 0, enemy3, TRUE);
			DrawRotaGraphF(685, 360, 1.0, 0, enemyEyes[1], TRUE);	//�G�̖�
		}
		else if (enemyx < 200 && enemyx > 0)
		{
			DrawRotaGraphF(685, 360, 0.35, 0, enemy3, TRUE);
			DrawRotaGraphF(685, 360, 1.0, 0, enemyEyes[3], TRUE);	//�G�̖�
		}
		else if (enemyx < 0 && enemyx > -200)
		{
			DrawRotaGraphF(685, 360, 0.35, 0, enemy3, TRUE);
			DrawRotaGraphF(685, 360, 1.0, 0, enemyEyes[0], TRUE);	//�G�̖�
		}
		
	}

	if(enemyx>700)
	{
		DrawRotaGraphF(enemyx, 360, 1.0, 0, enemyEyes[1], TRUE);	//�G�̖�
	}


	//DrawGraph(100, 360, enemy, TRUE);
}