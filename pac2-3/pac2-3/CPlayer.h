#pragma once
#include"Object.h"

class CPlayer : public CObject 
{
private:
	int pacmanDying[11];

public:
	CPlayer();
	~CPlayer() {}
	void Update() {}
	void Draw()const;
	void HitAction();

	int LoadImage();
};