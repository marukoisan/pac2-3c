#include"DxLib.h"
#include"CEsaController.h"

CEsaController::CEsaController()//�R���X�g���N�^
{
	LoadesaImage();
	
	esa = new CEsa[244];
	SetEsa();


	//esaFlg = 0; //�G�T�̃t���O
	////���W
	//x = 0.0;
	//y = 0.0;
	
}

CEsaController::~CEsaController()//�f�X�g���N�^
{
	delete esa;//�J�����܂�
}

void CEsaController::Draw() const
{
	for (int i = 0; i < 244; i++)//�c
	{
		if (esa[i].GetFlg() == true)
		{
			esa[i].Draw();
		}
		
	}
}

void CEsaController::Init()
{
	////����������������

	//x = 550.0;
	//y = 360.0;
	////�c��
	//height = 20.0;
	//width = 20.0;
}

void CEsaController::LoadesaImage()
{
	esaImages[0] = LoadGraph("images/tiles/dot.png");
	esaImages[1] = LoadGraph("images/tiles/big_dot.png");
}

void CEsaController::SetEsa()
{
	int esaIndex = 0;

	for (int i = 0; i < ESA_FIELD_HEIGHT; i++)//�c
	{
		for (int j = 0; j < ESA_FIELD_WIDTH; j++)//��
		{
			if (ESA_DATA[i][j] == 0)
			{
				esa[esaIndex].Init(ESA_FIELD_POS_X + j * ESA_IMAGE_NEWLY, ESA_FIELD_POS_Y + i * ESA_IMAGE_NEWLY, esaImages, 0);
				esaIndex++;
			}
			else if (ESA_DATA[i][j] == 1)
			{
				esa[esaIndex].Init(ESA_FIELD_POS_X + j * ESA_IMAGE_NEWLY, ESA_FIELD_POS_Y + i * ESA_IMAGE_NEWLY, esaImages, 1);
				esaIndex++;
			}
		}
	}
}