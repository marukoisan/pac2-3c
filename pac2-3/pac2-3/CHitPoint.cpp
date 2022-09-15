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

	//�c�@���ɉ����ĕ\�����Ă���c�@�̏�ɏd�˂Č����Ȃ�����
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