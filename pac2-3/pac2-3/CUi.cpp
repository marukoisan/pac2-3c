#include"CUi.h"

CUi::CUi()
{
	LoadDivGraph("images/numbers.png", 10, 10, 1, 97, 7, scoreImage);//�X�R�A�摜�ϐ�
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
		DrawGraph(100, 100, oneupImage, TRUE);
	}

	DrawFormatString(100, 130, 0x00000, "%06d", scoreImage);
	
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