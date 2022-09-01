#pragma once

class CHitPoint
{
private:
	int HitPoint[12];
public:
	CHitPoint();
	~CHitPoint() {}
	void Update() {}
	void Draw()const;
	void Respawn();
	void Recovery();
};