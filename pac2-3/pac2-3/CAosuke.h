#pragma once
#include "CAbstractEnemy.h"
class CAosuke : public CAbstractEnemy
{
public:
	CAosuke();
	~CAosuke() {}

	//↓↓この関数にアオスケの挙動を制御するための処理を書く
	//void SetTargetPos()override;
	void LoadImages()override;

	void EatenMove()override;
};

