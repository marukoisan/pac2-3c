#pragma once
#include"Object.h"

class CPlayer : public CObject 
{
protected:
	//分割読み込み
	int pacmanDying[11];
public:
	int LoadImage();
};