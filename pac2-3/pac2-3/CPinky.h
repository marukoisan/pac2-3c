#pragma once
#include "CAbstractEnemy.h"
class CPinky : public CAbstractEnemy
{
public:
	CPinky();
	~CPinky() {}

	//↓↓この関数にピンキーの挙動を制御するための処理を書く
	//void SetTargetPos()override;
	void LoadImages()override;
};

