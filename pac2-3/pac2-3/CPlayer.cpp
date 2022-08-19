#include<stdio.h>
#include"DxLib.h"
#include"CPlayer.h"

int i;
int pacmanDying[11];

int LoadImage()
{
	if (LoadDivGraph("images/sprites/dying.png", 11, 11, 1, 20, 20, pacmanDying) == -1)return 1;
}

void HitAction()
{
	for (i = 0; i < 11; i++) {
        //描画
        DrawGraph(0, 0, pacmanDying[i], FALSE);

        //一定時間待つ
        WaitTimer(100);

        // 読み込んだ画像を削除
        DeleteGraph(pacmanDying[i]);
	}

}

int CPlayer::LoadImage()
{
	return 0;
}
