#pragma once
#include"DxLib.h"
#define SCORE_MAX 10
#define ONEUP_ORIGINNL  22.0
#define ONEUP_NEWSIZE   45.0 
#define MAX_DIGIT  6 //����


class CUi
{
private:
	int scoreImage[SCORE_MAX] = {};//�摜�p�ϐ�
	int oneupImage;//�摜�p�ϐ�

	int oneupTime;//1UP�̂��߂̎��ԗp�ϐ�
	bool uiIsShow; //1��0���`��t���O

	int totalScore;//�X�R�A�̍��v���i�[����ϐ�
	
public:
	CUi();//�R���X�g���N�^
	~CUi();//�f�X�g���N�^

	void Update();//�A�b�v�f�[�g
	void Draw()const;//�`��֐�

	void karikannsuu() const;//���O�͌�ŕύX���� Draw�֐��ɓ����֐�
	int GetScore()const { return totalScore; }
	void AddScore(int nowScore);
	void uiImageBlinking(void);//�_�ŏ���
	void uitoggle(void) { uiIsShow = !(uiIsShow); }//�`��t���O
	//void karikansuu3();
};