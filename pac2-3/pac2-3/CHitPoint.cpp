#include<stdio.h>
#include"DxLib.h"
#include"CHitPoint.h"

CHitPoint::CHitPoint()
{
	bool error = false;
	if (LoadDivGraph("images/sprites/dying.png", 12, 12, 1, 32, 32, HitPoint) == -1)error = true;
}

void CHitPoint::Draw()const
{
	DrawRotaGraphF(100, 0, 1, 0, HitPoint[10], TRUE);
}

//リスポーンするときに残機が1減る処理
void CHitPoint::Respawn()
{

}

//スコアを10000稼いだ時に残機を1増やす処理(残機が3機ある場合は増えない)
void CHitPoint::Recovery()
{
	
}