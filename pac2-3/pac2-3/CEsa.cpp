#include"DxLib.h"
#include"CEsa.h"

CEsa::CEsa()//�R���X�g���N�^
{
	LoadesaImage();
	 esa = 0;
	 Bigesa = 0;

	//���W
	 x = 0.0;
	 y = 0.0;
	//�c��
	 height = 0.0;
	 width = 0.0;


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
	DrawRotaGraphF(x, y, 1.0 / ESA_IMAGE_ORIGINNL * ESA_IMAGE_NEWLY, 0,esa,TRUE); 
	DrawRotaGraphF(x, y+32, 1.0 / ESA_IMAGE_ORIGINNL * ESA_IMAGE_NEWLY, 0,Bigesa,TRUE); 
}

void CEsa::Init()
{
	//���W
	x = 550.0;
	y = 360.0;
	//�c��
	height = 20.0;
	width = 20.0;
}

void CEsa::LoadesaImage()
{
	esa = LoadGraph("images/tiles/dot.png");
	Bigesa = LoadGraph("images/tiles/big_dot.png");
}