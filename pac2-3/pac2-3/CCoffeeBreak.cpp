#include"define.h"
#include"DxLib.h"
#include"CCoffeeBreak.h"
#include "CPlayer.h"
#define _USE_MATH_DEFINES
#include<math.h>

//--------------------
// 画像読み込み
//--------------------
CCoffeeBreak::CCoffeeBreak()
{

	LoadDivGraph("images/sprites/monster.png", 2, 2, 1, 32, 32, enemyImages);
	LoadDivGraph("images/sprites/eyes.png", 4, 4, 1, 32, 32, enemyEyes);
	//LoadDivGraph("images/sprites/monster.png", 20, 20, 1, 32, 32, images);

	LoadDivGraph("images/sprites/pacman.png", D_PLAYER_IMAGE_MAX,
		3, 1, 32, 32, images);

	anim = FALSE;
}

////--------------------
//// 更新
////--------------------
//void CCoffeeBreak::Update()
//{
//
//}

//--------------------
// 描画
//--------------------
void CCoffeeBreak::Draw()
{
	static int X = 930;
	static float x = 990;
	static int X2 = 280;
	static float x2 = 360;
	angle = -M_PI / 2;
	animTimer++;

	if (animTimer % 4 == 0)//8はフレーム数
	{
		anim = !anim;
	}
	
	if (X > 350)
	{
		X -= 2;
		DrawRotaGraphF(X, 360, 1.0, angle,
			images[animTimer / D_PLAYER_ANIM_FPS % D_PLAYER_IMAGE_MAX], TRUE);
	}

	if (x > 350)
	{
		x -= 2.1;
		DrawRotaGraphF(x, 360, 1.0, 0, enemyImages[anim], TRUE);
		DrawRotaGraphF(x, 360, 1.0, 0, enemyEyes[1], TRUE);
	}
	DrawBox(0, 0, 369, 720, 0x0000ff, TRUE);
	DrawBox(910, 0, 1280, 720, 0x0000ff, TRUE);
}