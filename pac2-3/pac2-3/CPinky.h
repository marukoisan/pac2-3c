#pragma once
#include "CAbstractEnemy.h"
class CPinky : public CAbstractEnemy
{
public:
	CPinky();
	~CPinky() {}

	void HitAction_Player()override;
};

