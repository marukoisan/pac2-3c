#pragma once

class CHitPoint
{
private:
	int hitPointImages[12];
	
public:
	CHitPoint();
	~CHitPoint() {}
	void Update() {}
	void Draw()const;
	void Respawn();
	void Recovery();
	int playerLife = 3;
};