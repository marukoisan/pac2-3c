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
	DrawRotaGraphF(100, 460, 1, 0, hitPointImages[10], TRUE);
	DrawRotaGraphF(140, 460, 1, 0, hitPointImages[10], TRUE);
	DrawRotaGraphF(180, 460, 1, 0, hitPointImages[10], TRUE);
}

//���X�|�[������Ƃ��Ɏc�@��1���鏈��(���X�|�[������Ƃ��c�@��0�Ȃ�Q�[���I�[�o�[)
void CHitPoint::Respawn()
{
	if (playerLife == 0)
	{
		//�Q�[���I�[�o�[
	}
	playerLife--;
}

//�X�R�A��10000�҂������Ɏc�@��1���₷����(�c�@��3�@����ꍇ�͑����Ȃ�)
void CHitPoint::Recovery()
{
	if (playerLife < 3)
	{
		playerLife++;
	}
}