#include"DxLib.h"
#include "CSpeed.h"
//#include "CEsaController.h"
#include "CEsa.h"
#include "CPlayer.h"



void CSpeed::SetEsa()
{
	int esaIndex = 0;
	float speed = 1.0;



	for (int i = 0; i < ESA_FIELD_HEIGHT; i++)//c
	{
		for (int j = 0; j < ESA_FIELD_WIDTH; j++)//‰¡
		{
			if (esaType == 0)//‰a
			{
				if (esaIndex < D_ESA_MAX - 1)15/speed;

			}
			else if (esaType == 1)//ƒpƒ[‰a
			{
				if (esaIndex < D_ESA_MAX - 1)13/speed;

			}
		}
	}
}


