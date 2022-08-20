#pragma once
#include"Object.h"

#define D_TILE_SIZE 20.0f
#define D_TILE_IMAGE_MAX 27
#define D_FIELD_WIDTH 28
#define D_FIELD_HEIGHT 31

class CField : public CObject
{
private:
	int tileImages[D_TILE_IMAGE_MAX];//�^�C���摜�̑���
	int testImageIndex;

	const int FEILD_DATA[D_FIELD_HEIGHT][D_FIELD_HEIGHT] =
	{
		{04,18,18,18,18,18,18,18,18,18,18,18,18,12,13,18,18,18,18,18,18,18,18,18,18,18,18,05},
		{},
		{},
		{},
		{},
		{}
		
	};

public:
	//�R���X�g���N�^
	CField();
	//�f�X�g���N�^
	~CField();

	//�X�V
	void Update();
	//�`��
	void Draw()const;
	
	//�摜�̓ǂݍ���
	void LoadImages();

	void HitAction() {};
};

