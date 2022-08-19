#include"DxLib.h"
#include"CEnemy.h"

CEnemy::CEnemy()//コンストラクタ
{
	 enemy[2];    //エネミー本体画像

	 enemyRun = 0; //エネミー移動用画像
	 enemyEye[4]; //エネミー目の画像

	 enemySpeed = 0.0; //エネミースピード
	 enemyX = 0.0;   //座標
	 enemyY = 0.0;   //座標
}

int CEnemy::Image()//画像関数
{
	if
}