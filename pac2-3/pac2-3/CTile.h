#pragma once
#include "Object.h"
#define D_TILE_IMAGE_SIZE 100.0

class CTile : public CObject
{
private:
	int image;

public:
	CTile();
	~CTile();
	//�X�V
	void Update() {}
	//�`��
	void Draw()const;
	void HitAction() {}

	//�t�B�[���h����������炤
	void Init(float x,float y,int image);

};

