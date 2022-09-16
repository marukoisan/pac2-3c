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

//--------------------
// 描画
//--------------------
void CCoffeeBreak::Draw()
{
	static int X = 0;
	static float x = 0;
	angle = -M_PI / 2;
	animTimer++;
	X -= 3;
	x -= 3.07;

	if (animTimer % 8 == 0)//8はフレーム数
	{
		anim = !anim;
	}

	//パックマンの描画
	DrawRotaGraphF(1280 + X, 360, 1.0, angle,
		images[animTimer / D_PLAYER_ANIM_FPS % D_PLAYER_IMAGE_MAX], TRUE);

	//敵の描画
	DrawRotaGraphF(1340 + x, 360, 1.0, 0, enemyImages[anim], TRUE);

	DrawRotaGraphF(1340 + x, 360, 1.0, 0, enemyEyes[1], TRUE);
}