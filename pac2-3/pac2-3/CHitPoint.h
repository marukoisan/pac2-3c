#pragma once
#pragma once

class CHitPoint
{
private:
	int hitPointImages[12];
	int playerLife = 3;
public:
	CHitPoint();
	~CHitPoint() {}
	void Update() {}
	void Draw()const;
	void Respawn();
	void Recovery();
};