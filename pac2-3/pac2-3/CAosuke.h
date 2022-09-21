#pragma once
#include "CAbstractEnemy.h"
#include "CAkabei.h"
class CAosuke : public CAbstractEnemy
{
private:
	CAkabei* akabei;
public:
	CAosuke();
	~CAosuke() {}

	void SetAkabei(CAkabei* pAkabei) { akabei = pAkabei; }
	
	//↓↓この関数にアオスケの挙動を制御するための処理を書く
	void SetTargetPos()override;
	void LoadImages()override;

	void EatenMove()override;
};

