#pragma once
#include"Object.h"
#define ESA_IMAGE_ORIGINNL 100.0
#define ESA_IMAGE_NEWLY 20.0


class CEsa : public CObject
{
private:
	int esa;//�������G�T�p�̕ϐ�
	int Bigesa;//�傫���G�T�p�̕ϐ�
	//���W
	float x;
	float y;
	//�c��
	float height;
	float width;
public:
	CEsa();//�R���X�g���N�^
	~CEsa();//�f�X�g���N�^
	void Update() {};
	void Draw()const;
	void HitAction() {};
	void Init();//�ϐ��̏�����
	void LoadesaImage();//�摜�̓Ǎ���
};

