#include"CUi.h"

CUi::CUi()
{
	LoadDivGraph("images/numbers.png", SCORE_MAX, 10, 1, 9, 7, scoreImage);//�X�R�A�摜�ϐ�
	oneupImage = LoadGraph("images/oneup.png");
	oneupTime = 0;//1UP�p�̎���
	uiIsShow = true;  //1UP�̕`��t���O
}

CUi::~CUi()
{
	;
}

void CUi::Update()
{
	uiImageBlinking();
}

void CUi::Draw() const
{
	if (uiIsShow)
	{
		DrawRotaGraphF(100, 100, 1.0/ ONEUP_ORIGINNL* ONEUP_NEWSIZE, 0, oneupImage, TRUE);//1UP�̉摜�̕\��(�_�ŏ�����)
		
	}

	DrawRotaGraphF(100, 130, 1.5, 0, scoreImage[3], TRUE);//�X�R�A��\�����邽�߂�Draw���ׂĂ��ɂ͂܂�����Ȃ�
	
}


void Score()
{

}

void OneUp()
{

}

void CUi::uiImageBlinking(void)
{
	oneupTime++;
	if (oneupTime % 10 == 0)//1�b�ԂɈ��
	{
		uitoggle();
	}

}