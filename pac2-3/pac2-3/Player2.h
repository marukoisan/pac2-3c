#pragma once
#include"Object.h"
#define PI	3.1415926535897932384626433832795f



class Player2 : public CObject
{
private:
	int gPacman[12];
	

public:
	Player2();
	~Player2();
	void Update() {}
	void Draw()const;
	
	int LoadImages();
	int Init();

};


