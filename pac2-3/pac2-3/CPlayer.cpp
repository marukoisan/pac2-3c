#include<stdio.h>
#include"DxLib.h"
#include"CPlayer.h"

CPlayer::CPlayer()
{
	bool error = false;
	if (LoadDivGraph("images/sprites/dying.png", 11, 11, 1, 32, 32, pacmanDyings) == -1)error = true;
}

void CPlayer::Draw()const
{
	static int animTimer = 0;
	animTimer++;
	//•`‰æ
	DrawRotaGraphF(640, 360, 1, 0, pacmanDyings[animTimer / 9 % 11], TRUE);
}

void CPlayer::HitAction()
{
	
}

int CPlayer::LoadImage()
{
	return 0;
}
