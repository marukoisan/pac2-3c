#pragma once
#include"DxLib.h"
#define TUGIHAGI_MAX 2
#define IMOMUSI_MAX 2

class CCoffeeBreak3
{
private:
	int tugihagi[TUGIHAGI_MAX] = {};//�摜�p�ϐ�
	int imomusi[IMOMUSI_MAX] = {};//�摜�p�ϐ�

public:

	CCoffeeBreak3();
	~CCoffeeBreak3();

	void Update();
	
	void Draw() const;

	void LoadImages();//�摜�̓Ǎ���

};

