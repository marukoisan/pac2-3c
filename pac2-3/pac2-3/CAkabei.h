#pragma once
#include "CAbstractEnemy.h"
class CAkabei :  public CAbstractEnemy
{
public:
	CAkabei();
	~CAkabei() {}

	void Init() override;
	void HitAction_Player()override;
};

