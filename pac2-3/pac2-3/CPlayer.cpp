#include<stdio.h>
#include"DxLib.h"
#include"CPlayer.h"


CPlayer::CPlayer()
{
	bool error = false;
	if (LoadDivGraph("images/sprites/dying.png", 11, 11, 1, 32, 32, pacmanDying) == -1)error=true;
}

void CPlayer::Draw()const
{
	static int animTimer = 0;
	animTimer++;
	//•`‰æ
	DrawRotaGraphF(640, 360, 1, 0, pacmanDying[animTimer /9  %11], TRUE);
	DrawRotaGraphF(640, 360+32, 1, 0, pacmanDying[animTimer /8  %11], TRUE);
	DrawRotaGraphF(640, 360+64, 1, 0, pacmanDying[animTimer /7  %11], TRUE);

}

void CPlayer::HitAction()
{
	

}

int CPlayer::LoadImage()
{
	return 0;
}
