#include"DxLib.h"
#include "CSpeed.h"
//#include "CEsaController.h"
#include "CEsa.h"
#include "CPlayer.h"



void CSpeed::SetEsa()
{
	int esaIndex = 0;
    float speed = 1.0;


	for (int i = 0; i < ESA_FIELD_HEIGHT; i++)//�c
	{
		for (int j = 0; j < ESA_FIELD_WIDTH; j++)//��
		{
			if (esaType == 0)//�a
			{
				/*if (esaIndex < D_ESA_MAX - 1)speed = 1.0 * 15/16;*/
				if (esaIndex > D_ESA_MAX - 1)speed = 1.0 * 15 / 16;

			}
			else if (esaType == 1)//�p���[�a
			{

				if (esaIndex < D_ESA_MAX - 1)speed = 1.0 * 13/16;



			}
		}
	}
}

//if (index > -1)
//{
//	if (esa[index].GetFlg() == true)
//	{
//		CheckHitBox(player, &esa[index]);
//	}
//}
