#pragma once
#include"Object.h"

#define D_TILE_SIZE 20.0f

class CField : public CObject
{
private:
	int tiles[30];//�^�C���摜�̑���
	int testTiles[4];
public:
	//�R���X�g���N�^
	CField();
	//�f�X�g���N�^
	~CField();

	//�X�V
	void Update() {};
	//�`��
	void Draw()const;


	void HitAction() {};
};

