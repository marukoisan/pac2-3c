#pragma once
#include"Object.h"
#define ESA_IMAGE_HEIGHT 20.0
#define ESA_IMAGE_WIDTH 20.0


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
	void Update() {};
	void Draw()const;
	void HitAction() {};
	void Init();//�ϐ��̏�����
	int LoadesaImage();//�摜�̓Ǎ���
};

