#pragma once
#include"Object.h"
#include"define.h"
#define ESA_IMAGE_ORIGINNL 100.0 //�G�T�摜�̌��̑傫��
#define ESA_IMAGE_NEWLY 20.0 //�G�T�摜�̑傫���ɂ���T�C�Y
#define D_ESA_MAX 244

class CEsa : public CObject
{
private:

	int *EsaImage;//�G�T�p�̕ϐ�
	//int Bigesa;//�傫���G�T�p�̕ϐ�

	//int esaImages[ESA_IMAGE_MAX];//�G�T�̔z��
	
	bool esaType;  //�G�T�摜�̔���
	bool esaFlg;  //�G�T�̕\���t���O
	int esaScore;  //�G�T�̃X�R�A
	int esaTime;  //�G�T�̓_�ŗp�̎��Ԃ�����ϐ�
	bool esaIsShow; //1��0���`��t���O
	
	
	////���W
	//float x;
	//float y;
	////�c��
	//float height;
	//float width;

public:
	CEsa();//�R���X�g���N�^
	~CEsa();//�f�X�g���N�^
	void Update() {};
	void Draw()const;
	void HitAction(){ esaFlg = false; }
	void Init(float x, float y,int *EsaImage, bool esaType,int esaScore);//�ϐ��̏�����
	void LoadesaImage();//�摜�̓Ǎ���
	bool GetFlg() { return esaFlg; }//�G�T�̕\���t���O
	void ImageBlinking(void);//�_�ŏ���
	void toggle(void) { esaIsShow = !(esaIsShow); }//�`��t���O
	int GetScore() { return esaScore; }//�G�T�̃X�R�A��Ⴄ

	//�f�o�b�O�p�@TODO:����
	void DeleteFeed() { esaFlg = false; }

};


