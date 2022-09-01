#pragma once
#include"Object.h"
#define PI	3.1415926535897932384626433832795f
#define PACMAN_NEW_SIZE  20.0


class Player2 : public CObject
{
private:
	int gPacman[12];
	bool wallSize;

public:
	Player2();
	~Player2();
	void Update() {}
	void Draw()const;
	void HitAction() { wallSize = false; }//0‚ª“ü‚Á‚Ä‚¢‚é
	int LoadImages();
	int Init();
	bool GetFlg() { return wallSize; }

};


