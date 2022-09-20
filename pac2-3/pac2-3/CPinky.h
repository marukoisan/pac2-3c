#pragma once
#include "CAbstractEnemy.h"
class CPinky : public CAbstractEnemy
{
public:
	CPinky();
	~CPinky() {}

	//««‚±‚ÌŠÖ”‚Éƒsƒ“ƒL[‚Ì‹““®‚ğ§Œä‚·‚é‚½‚ß‚Ìˆ—‚ğ‘‚­
	//void SetTargetPos()override;
	void LoadImages()override;
};

