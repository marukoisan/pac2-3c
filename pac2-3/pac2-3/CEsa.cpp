#include"DxLib.h"
#include"CEsa.h"

CEsa::CEsa()//�R���X�g���N�^
{
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

void CEsa::Update()//�X�V
{

}

void CEsa::Draw() const//
{
	DrawRotaGraphF(460,360,)
}

void CEsa::Init()
{
	//���W
	x = 0.0;
	y = 0.0;
	//�c��
	height = 20.0;
	width = 20.0;
}

int CEsa::LoadesaImage()
{
	esa = LoadGraph("images/tiles/dot.png");
	Bigesa = LoadGraph("images/tiles/big_dot.png");
}