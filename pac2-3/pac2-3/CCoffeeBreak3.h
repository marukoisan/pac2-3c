#pragma once
#include"DxLib.h"
#define TUGIHAGI_MAX 2
#define IMOMUSI_MAX 2
#define PACMAN_MAX 12
#define TUGIHAGI_POSX 1020
#define PACMAN_POSX 930
class CCoffeeBreak3
{
private:
	int tugihagi[TUGIHAGI_MAX] = {};//�摜�p�ϐ�
	int imomusi[IMOMUSI_MAX] = {};//�摜�p�ϐ�
	int pacman[PACMAN_MAX] = {};//�摜�p�ϐ�

	bool anim;//�����ނ��Ƃ��͂��̉摜�̔���0��1�� 2�������Ȃ��̂�
	bool anime;//�����ނ��p
	int animpacman;//�A�j���������Z
	int x;//���Z����
	int y;//���Z����

public:

	CCoffeeBreak3();
	~CCoffeeBreak3();

	void Update();
	
	void Draw() const;

	void LoadImages();//�摜�̓Ǎ���

};

