#pragma once
#include"Object.h"

class CPlayer : public CObject 
{
protected:
	//�����ǂݍ���
	int pacmanDying[11];
public:
	int LoadImage();
};