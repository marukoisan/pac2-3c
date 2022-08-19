#pragma once
#include"Object.h"

class CPlayer : public CObject 
{
protected:
	//•ªŠ„“Ç‚İ‚İ
	int pacmanDying[11];
public:
	int LoadImage();
};