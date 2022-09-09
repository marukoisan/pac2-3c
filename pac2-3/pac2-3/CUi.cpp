#include"CUi.h"

CUi::CUi()
{
	LoadDivGraph("images/numbers.png", SCORE_MAX, 10, 1, 9, 7, scoreImage);//�X�R�A�摜�ϐ�
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
		DrawRotaGraphF(100, 100, 1.0/ ONEUP_ORIGINNL* ONEUP_NEWSIZE, 0, oneupImage, TRUE);//1UP�̉摜�̕\��(�_�ŏ�����)
		
	}

	//DrawRotaGraphF(100, 130, 1.5, 0, scoreImage[3], TRUE);//�X�R�A��\�����邽�߂�Draw���ׂĂ��ɂ͂܂�����Ȃ�

	karikannsuu();
	
}


void CUi::karikannsuu() const//���O�͌�ŕύX����
{
	int digit;//�����Ƃ����Ӗ�  //weight

	for (digit = 0; digit < MAX_DIGIT; digit++)
	{
		int w = totalScore;  //totalScore�ɉ����Ȃ�����
		
		w /= 10;

		if (totalScore == 0)break;

	}

	for (int i = 0; i < digit; i++)
	{
		int weight;

		weight = i * 10 ^ digit;

		DrawRotaGraphF(100, 130, 1.0, 0, scoreImage[totalScore / weight], TRUE);//�X�R�A��\�����邽�߂�Draw���ׂĂ��ɂ͂܂�����Ȃ�

	}

}

void CUi::AddScore(int Addscore)//�����ɒl�����Ċ���������
{
	totalScore += Addscore;
}

void CUi::uiImageBlinking(void)
{
	oneupTime++;
	if (oneupTime % 10 == 0)//1�b�ԂɈ��
	{
		uitoggle();
	}

}