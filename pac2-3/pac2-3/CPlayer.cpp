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
        //•`‰æ
        DrawGraph(0, 0, pacmanDying[i], FALSE);

        //ˆê’èŽžŠÔ‘Ò‚Â
        WaitTimer(100);

        // “Ç‚Ýž‚ñ‚¾‰æ‘œ‚ðíœ
        DeleteGraph(pacmanDying[i]);
	}

}

int CPlayer::LoadImage()
{
	return 0;
}
