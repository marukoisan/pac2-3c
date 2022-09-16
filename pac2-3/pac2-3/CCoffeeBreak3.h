#pragma once
#include"DxLib.h"
#define TUGIHAGI_MAX 2
#define IMOMUSI_MAX 2
#define PACMAN_MAX 12
#define TUGIHAGI_POSX 1020
#define PACMAN_POSX 930
class CCoffeeBreak3
{
private:
	int tugihagi[TUGIHAGI_MAX] = {};//画像用変数
	int imomusi[IMOMUSI_MAX] = {};//画像用変数
	int pacman[PACMAN_MAX] = {};//画像用変数

	bool anim;//いもむしとつぎはぎの画像の判別0と1で 2枚しかないので
	bool anime;//いもむし用
	int animpacman;//アニメ処理加算
	int x;//加算処理
	int y;//減算処理

public:

	CCoffeeBreak3();
	~CCoffeeBreak3();

	void Update();
	
	void Draw() const;

	void LoadImages();//画像の読込み

};

