#pragma once
#include"DxLib.h"
#define SCORE_MAX 10

class CUi
{
private:
	int scoreImage[SCORE_MAX];//�摜�p�ϐ�
	int oneupImage;//�摜�p�ϐ�

	int oneupTime;//1UP�̂��߂̎��ԗp�ϐ�
	bool uiIsShow; //1��0���`��t���O


public:
	CUi();//�R���X�g���N�^
	~CUi();//�f�X�g���N�^

	void Update();//�A�b�v�f�[�g
	void Draw()const;//�`��֐�

	void Score();
	void OneUp();
	void uiImageBlinking(void);//�_�ŏ���
	void uitoggle(void) { uiIsShow = !(uiIsShow); }//�`��t���O
	//void karikansuu3();
};