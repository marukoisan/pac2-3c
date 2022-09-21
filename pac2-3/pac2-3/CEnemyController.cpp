#include "CEnemyController.h"

CEnemyController::CEnemyController(CAkabei* pAkabei, CPinky* pPinky,
	CAosuke* pAosuke, CGuzuta* pGuzuta)
{
	akabei = pAkabei;
	pinky = pPinky;
	aosuke = pAosuke;
	guzuta = pGuzuta;

	enemys[0]= pAkabei;
	enemys[1]= pPinky;
	enemys[2]= pAosuke;
	enemys[3]= pGuzuta;
}

void CEnemyController::Update()
{
	eatenFeedCount++;

	switch (pattern)
	{
	case 0:
		PatternA();
		break;
		
	case 1:
		PatternB();
		break;
		
	case 2:
		PatternC();
		break;

	default:
		;

	}

}


void CEnemyController::PatternA()
{
	if (enemyCount < 2)
	{
		enemys[enemyCount]->LeaveTheNest();
		enemyCount++;
	}
	else if (enemyCount < 3 && eatenFeedCount > 30)
	{
		enemys[enemyCount]->LeaveTheNest();
		enemyCount++;
	}
	else if (enemyCount < 4 && eatenFeedCount > 60)
	{
		enemys[enemyCount]->LeaveTheNest();
		enemyCount++;
	}
	else
	{
		;
	}
}

void CEnemyController::PatternB()
{

	if (enemyCount < 3)
	{
		enemys[enemyCount]->LeaveTheNest();
		enemyCount++;
	}
	else if (enemyCount < 4 && eatenFeedCount > 30)
	{
		enemys[enemyCount]->LeaveTheNest();
		enemyCount++;
	}
	else
	{
		;
	}
}

void CEnemyController::PatternC()
{
	if (enemyCount < 4)
	{
		enemys[enemyCount]->LeaveTheNest();
		enemyCount++;
	}
}

void CEnemyController::GameClear()
{
	eatenFeedCount = 0;
	enemyCount = 1;
	isMiss = false;
}