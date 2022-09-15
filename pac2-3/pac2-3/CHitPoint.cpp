#include<stdio.h>
#include"DxLib.h"
#include"CHitPoint.h"

CHitPoint::CHitPoint()
{
	bool error = false;
	if (LoadDivGraph("images/sprites/pacman.png", 12, 12, 1, 32, 32, hitPointImages) == -1)error = true;
}

void CHitPoint::Draw()const
{
	DrawRotaGraphF(280, 700, 1, 0, hitPointImages[10], TRUE);
	DrawRotaGraphF(320, 700, 1, 0, hitPointImages[10], TRUE);
	DrawRotaGraphF(360, 700, 1, 0, hitPointImages[10], TRUE);

	//残機数に応じて表示している残機の上に重ねて見えなくする
	if (playerLife < 3)
	{
		DrawBox(340, 680, 380, 720, Color, TRUE);
		if (playerLife < 2)
		{
			DrawBox(300, 680, 340, 720, Color, TRUE);
			if (playerLife < 1)
			{
				DrawBox(260, 680, 300, 720, Color, TRUE);
			}
		}
	}

	
}

//リスポーンするときに残機が1減る処理(リスポーンするとき残機が0ならゲームオーバー)
void CHitPoint::Respawn()
{
	if (playerLife == 0)
	{
		//ゲームオーバー
	}
	playerLife--;
}

//スコアを10000稼いだ時に残機を1増やす処理(残機が3機ある場合は増えない)
void CHitPoint::Recovery()
{
	if (playerLife < 3)
	{
		playerLife++;
	}
}