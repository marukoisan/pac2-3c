#pragma once
#include "Object.h"
#define D_TILE_IMAGE_SIZE 100.0

class CTile : public CObject
{
private:
	int image;

public:
	CTile();
	~CTile();
	//更新
	void Update() {}
	//描画
	void Draw()const;
	void HitAction() {}

	//フィールドから情報をもらう
	void Init(float x,float y,int image);

};

