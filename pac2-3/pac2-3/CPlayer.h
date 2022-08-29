#pragma once
#include"Object.h"

class CPlayer : public CObject 
{
private:
	int pacmanDyings[11];

public:
	CPlayer();
	~CPlayer() {}
	void Update() {}
	void Draw()const;
	void HitAction();

	int LoadImage();
};