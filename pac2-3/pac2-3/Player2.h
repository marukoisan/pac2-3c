#pragma once
#include"Object.h"
#define PI	3.1415926535897932384626433832795f
#define D_FIELD_WIDTH 28  
#define D_FIELD_HEIGHT 31 


class Player2 : public CObject
{
private:
	int gPacman[12];
	int gMap[D_FIELD_HEIGHT][D_FIELD_WIDTH];			// マップデータ

public:
	Player2();
	~Player2();
	void Update() {}
	void Draw()const;
	int PlayerMove();
	int CheckWall(int cx, int cy, int mx, int my);
	int LoadImages();
	int Init();

};


