#include<math.h>
#include"CUi.h"

CUi::CUi()
{
	LoadDivGraph("images/numbers.png", SCORE_MAX, 10, 1, 7, 7, scoreImage);//�X�R�A�摜�ϐ�
	oneupImage = LoadGraph("images/oneup.png");
	oneupTime = 0;//1UP�p�̎���
	uiIsShow = true;  //1UP�̕`��t���O
	totalScore = 0;
	
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
		DrawRotaGraphF(370, 10, 1.0/ ONEUP_ORIGINNL* ONEUP_NEWSIZE, 0, oneupImage, TRUE);//1UP�̉摜�̕\��(�_�ŏ�����)
		
	}

	//DrawRotaGraphF(100, 130, 1.5, 0, scoreImage[3], TRUE);//�X�R�A��\�����邽�߂�Draw���ׂĂ��ɂ͂܂�����Ȃ�

	DigitCalculation();//���v�Z
	
}


void CUi::DigitCalculation() const//���v�Z
{
	int digit;//�����Ƃ����Ӗ�  //weight

	int w = totalScore;  //totalScore�ɉ����Ȃ�����

	int i = 0;
	while (w > 0)
	{
		DrawRotaGraphF(POSX - i * NUM, POSY, 1.0 / ONEUP_ORIGINNL * ONEUP_NEWSIZE, 0, scoreImage[w % 10], FALSE);//�X�R�A��\�����邽�߂�Draw���ׂĂ��ɂ͂܂�����Ȃ�
		w /= 10;
		i++;
	}

}

void CUi::AddScore(int nowScore)//�����ɒl�����Ċ���������
{
	totalScore += nowScore;
}

void CUi::uiImageBlinking(void)
{
	oneupTime++;
	if (oneupTime % 10 == 0)//1�b�ԂɈ��
	{
		uitoggle();
	}

}