#pragma once

class CHitPoint
{
private:
	int hitPointImages[12];
	int Color = GetColor(0, 0, 0);

public:
	CHitPoint();
	~CHitPoint() {}
	void Update() {}
	void Draw()const;
	void Respawn();
	void Recovery();
	int playerLife = 3;
};