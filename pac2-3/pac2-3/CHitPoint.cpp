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

//���X�|�[������Ƃ��Ɏc�@��1���鏈��
void CHitPoint::Respawn()
{

}

//�X�R�A��10000�҂������Ɏc�@��1���₷����(�c�@��3�@����ꍇ�͑����Ȃ�)
void CHitPoint::Recovery()
{
	
}