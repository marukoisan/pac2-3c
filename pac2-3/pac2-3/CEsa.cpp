#include"DxLib.h"
#include"CEsa.h"

int CEsa::esaCount;

CEsa::CEsa()//�R���X�g���N�^
{
	//esa = 0;
	//Bigesa = 0;
   //esaFlg = 0; //�G�T�̃t���O
	EsaImage = 0;
	esaType = 0;  //�G�T�摜�̔���
	esaFlg = true;  //�G�T�̕\���t���O
	esaScore = 0;  //�G�T�̃X�R�A
	esaTime = 0;   //�G�T�̓_�ł����邽�ߗp�̎��ԕϐ�
	esaIsShow = true; //�G�T�̕`��t���O



	height = 3;
	width = 3;

}

CEsa::~CEsa()//�f�X�g���N�^
{
	;
}

//void CEsa::Update()//�X�V
//{
//
//}

void CEsa::Draw() const//
{
	if (esaIsShow)
	{
		DrawRotaGraphF(D_FIELD_POS_X + x,D_FIELD_POS_Y + y, 1.0 / ESA_IMAGE_ORIGINNL * ESA_IMAGE_NEWLY, 0, EsaImage[esaType], TRUE);
	}
}

void CEsa::HitAction()
	{ 
		esaFlg = false;
		PlaySoundMem(esaSound[esaCount % 2 ], DX_PLAYTYPE_BACK);
		esaCount++;
	}

void CEsa::Init(float x, float y,int *EsaImage, bool esaType, int esaScore, int* esaSound)
{
	this->x = x;  //���W
	this->y = y;  //���W
	this->EsaImage = EsaImage;   //�G�T�̉摜
	this->esaType = esaType;  //�G�T�摜�̔���
	this->esaScore = esaScore; //�G�T�̃X�R�A
	this->esaSound = esaSound;

}



void CEsa::ImageBlinking(void)
{
	esaTime++;
	if (esaType == 1)
	{
		if (esaTime % 15 == 0)//2�b�ԂɈ����ď���
		{
			toggle();
		}
		
	}
	
}



void CEsa::LoadSounds()
{
	/*esa = LoadGraph("images/tiles/dot.png");
	Bigesa = LoadGraph("images/tiles/big_dot.png");*/

	//esaImages[0] = LoadGraph("images/tiles/dot.png");
	//esaImages[1] = LoadGraph("images/tiles/big_dot.png");
}