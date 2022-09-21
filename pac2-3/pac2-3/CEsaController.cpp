#include"DxLib.h"
#include"CEsaController.h"

CEsaController::CEsaController()//�R���X�g���N�^
{
	LoadesaImage();
	
	
	esa = new CEsa[D_ESA_MAX];
	SetEsa();
	


	//esaFlg = 0; //�G�T�̃t���O
	////���W
	//x = 0.0;
	//y = 0.0;
	
}

CEsaController::~CEsaController()//�f�X�g���N�^
{
	delete[] esa;//�J�����܂�
}

void CEsaController::Update()
{

	isClear = true;//clear��������āA�G�T����ł��̂����Ă���Ώ���
	for (int i = 0; i < D_ESA_MAX; i++)
	{
		if (esa[i].GetFlg() == true)
		{
			isClear = false;
			esa[i].ImageBlinking();
		}
	}
}

void CEsaController::Draw() const
{
	for (int i = 0; i < D_ESA_MAX; i++)
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
	esaSounds[0] = LoadSoundMem("sounds2/AnyConv.com__regular3.wav");//�G�T�擾��
	esaSounds[1] = LoadSoundMem("sounds2/AnyConv.com__regular4.wav");//�G�T�擾��
}

void CEsaController::SetEsa()
{
	int esaIndex = 0;

	for (int i = 0; i < ESA_FIELD_HEIGHT; i++)//�c
	{
		for (int j = 0; j < ESA_FIELD_WIDTH; j++)//��
		{
			if (esaData[i][j] == 0)
			{
				esa[esaIndex].Init(j * ESA_IMAGE_NEWLY, i * ESA_IMAGE_NEWLY, esaImages, 0, 10, esaSounds);//�Ō�̐������X�R�A�̗\��
				esaData[i][j] = esaIndex;
				if(esaIndex< D_ESA_MAX-1)esaIndex++;
			}
			else if (esaData[i][j] == 1)
			{
				esa[esaIndex].Init(j * ESA_IMAGE_NEWLY, i * ESA_IMAGE_NEWLY, esaImages, 1, 50, esaSounds);//�Ō�̐������X�R�A�̗\��
				esaData[i][j] = esaIndex;
				if (esaIndex < D_ESA_MAX-1)esaIndex++;
			}
		}
	}
}


