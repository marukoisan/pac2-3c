#pragma once
#include"DxLib.h"
#define TUGIHAGI_MAX 2
#define IMOMUSI_MAX 2

class CCoffeeBreak3
{
private:
	int tugihagi[TUGIHAGI_MAX] = {};//‰æ‘œ—p•Ï”
	int imomusi[IMOMUSI_MAX] = {};//‰æ‘œ—p•Ï”

public:

	CCoffeeBreak3();
	~CCoffeeBreak3();

	void Update();
	
	void Draw() const;

	void LoadImages();//‰æ‘œ‚Ì“Ç‚İ

};

