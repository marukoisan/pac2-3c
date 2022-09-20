#pragma once
#include "CAbstractEnemy.h"
class CGuzuta : public CAbstractEnemy
{
public:

	CGuzuta();
	~CGuzuta() {}


	//↓↓この関数にアオスケの挙動を制御するための処理を書く
	void SetTargetPos()override;
	void LoadImages()override;

	void EatenMove()override;

};

