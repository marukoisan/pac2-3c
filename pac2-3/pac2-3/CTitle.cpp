#include<stdio.h>
#include"DxLib.h"
#include "CTitle.h"
#include"CGameMain.h"
#define TILESIZE 20

//----------------------------
// コンストラクタ
//----------------------------
CTitle::CTitle()
{
	charactar_strImage = LoadGraph("images/character_str.png");
}

//---------------------
// 更新
//---------------------
CAbstractScene* CTitle::Update()
{
	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) == PAD_INPUT_2)
	{
		saveData = 2;
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

	//パックマンスピード
	if (timer / 15 >= 18 && D_TITLE_POS_X + 5 * TILESIZE <= D_TITLE_POS_X + 28 * TILESIZE + playerx)
	{
	playerx-=3;
	}

	angle = -M_PI / 2;	//左向き


	//画像読み込み
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

	//パックマン
	LoadDivGraph("images/sprites/pacman.png", D_PLAYER_IMAGE_MAX, 3, 1, 32, 32, pacman);

	return this;
}

//---------------------
// 描画
//---------------------
void CTitle::Draw()const
{
	DrawGraph(D_TITLE_POS_X +  9 * TILESIZE,   0, highscore, TRUE);

	DrawGraph(D_TITLE_POS_X +  7 * TILESIZE, 100, charactar_strImage, TRUE);
	DrawGraph(D_TITLE_POS_X + 18 * TILESIZE, 100, slash, TRUE);
	DrawGraph(D_TITLE_POS_X + 21 * TILESIZE, 100, nickname, TRUE);


	//アカベイ
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


	//ピンキー
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


	//アオスケ
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


	//グズタ
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


	//エサ
	if (timer / 15 >= 17 && timer / 15 <= 18)
	{
		DrawRotaGraphF(D_TITLE_POS_X + 5 * TILESIZE, 320, 0.2, 0, esa, TRUE);
	}
	if (timer / 15 >= 17)
	{
		if (timer / 15 % 2)
		{
			DrawRotaGraphF(D_TITLE_POS_X + 5 * TILESIZE, 320, 0.2, 0, esa, TRUE);
		}
	}


	//パックマン
	if (timer / 15 >= 18)

	{
		if (timer / D_TITLE_POS_X + 5 * TILESIZE <= D_TITLE_POS_X + 28 * TILESIZE + playerx)
		{
			DrawRotaGraphF(D_TITLE_POS_X + 28 * TILESIZE + playerx, 320, 1.0, angle, pacman[timer / D_PLAYER_ANIM_FPS % D_PLAYER_IMAGE_MAX], TRUE);
		}
	}

	

	DrawFormatString(0, 0, 0xffffff, "%d", saveData);

	
}