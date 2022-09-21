#pragma once
#include"CAkabei.h"
#include"CPinky.h"
#include"CAosuke.h"
#include"CGuzuta.h"
class CEnemyController
{
private:
	int pattern = 0;
	CAkabei* akabei	=0;
	CPinky* pinky=0;
	CAosuke* aosuke=0;
	CGuzuta* guzuta=0;
	CAbstractEnemy* enemys[4] = { akabei,pinky,aosuke,guzuta };

	int eatenFeedCount = 0;
	int enemyCount = 1;

	bool isMiss = false;

public:
	CEnemyController() {}
	CEnemyController(CAkabei* pAkabei, CPinky* pPinky, CAosuke* pAosuke, CGuzuta* pGuzuta);
	~CEnemyController() {}

	void Update();

	void PatternA();
	void PatternB();
	void PatternC();

	void GameClear();

	void SetPattern(int pattern) { this->pattern = pattern; }
};

