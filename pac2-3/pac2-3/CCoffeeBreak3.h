#pragma once
#include"DxLib.h"
#define TUGIHAGI_MAX 2
#define IMOMUSI_MAX 2

class CCoffeeBreak3
{
private:
	int tugihagi[TUGIHAGI_MAX] = {};//画像用変数
	int imomusi[IMOMUSI_MAX] = {};//画像用変数

public:

	CCoffeeBreak3();
	~CCoffeeBreak3();

	void Update();
	
	void Draw() const;

	void LoadImages();//画像の読込み

};

