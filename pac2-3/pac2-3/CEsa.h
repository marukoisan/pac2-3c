#pragma once
#include"Object.h"
#define ESA_IMAGE_ORIGINNL 100.0 //�G�T�摜�̌��̑傫��
#define ESA_IMAGE_NEWLY 20.0 //�G�T�摜�̑傫���ɂ���T�C�Y

class CEsa : public CObject
{
private:

	int *EsaImage;//�G�T�p�̕ϐ�
	//int Bigesa;//�傫���G�T�p�̕ϐ�

	//int esaImages[ESA_IMAGE_MAX];//�G�T�̔z��
	
	bool esaType;  //�G�T�摜�̔���
	bool esaFlg;  //�G�T�̕\���t���O
	int esaScore;  //�G�T�̃X�R�A
	
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
	void HitAction() { esaFlg = false; }
	void Init(float x, float y,int *EsaImage, bool esaType);//�ϐ��̏�����
	void LoadesaImage();//�摜�̓Ǎ���
	bool GetFlg() { return esaFlg; }//�G�T�̕\���t���O


};

