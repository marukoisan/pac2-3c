#pragma once
#define FRUIT_MAX 13

class CFruit
{
private:
	int FruitImage[FRUIT_MAX] = {};

public:

	CFruit();
	~CFruit() {}
	void Update() {}
	void Draw()const;

};

