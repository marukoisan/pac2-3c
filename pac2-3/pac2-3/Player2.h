#pragma once
#include"Object.h"
#define PI	3.1415926535897932384626433832795f
#define PACMAN_IMAGE 12
#define PACMAN_ORIGINAL_SIZE 32.0
#define PACMAN_NEW_SIZE  20.0


class Player2 : public CObject
{
private:
	int gPacman[PACMAN_IMAGE];
	bool wallHit;

public:
	Player2();
	~Player2();
	void Update() {}
	void Draw()const;
	void HitAction() { wallHit = false; }//0が入っている
	int LoadImages();
	int Init(float x,float y);
	bool GetFlg() { return wallHit; }
	/*
	パックマンの縦横の奴をこっちで書くかコントローラー側で書くか
	*/

};


