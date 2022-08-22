#include"DxLib.h"
#include"CEnemy.h"

//定数宣言
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;


CEnemy::CEnemy()//コンストラクタ
{
	   //エネミー本体画像
	 LoadDivGraph("images/sprites/monster.png",
		 20, 20, 1, ENEMY_IMAGE_SIZE, ENEMY_IMAGE_SIZE, enemy);//画像の分割読み込み
	 //enemyRun = 0; //エネミー移動用画像
	  //エネミー目の画像
	 LoadDivGraph("images/sprites/eyes.png",
		 4, 4, 1, ENEMY_IMAGE_SIZE, ENEMY_IMAGE_SIZE, enemyEye);//画像の分割読み込み
	 enemySpeed = 0.0; //エネミースピード
	 x = 0.0;   //座標
	 y = 0.0;   //座標

	 //縦横
	 height = 0.0;
	 width = 0.0;
	 /*angleX = 0.0;
	 angleY = 0.0;*/
	 enemyFlg = 0;
}

//void CEnemy::EnemyDisplay()
//{
//	if (enemyFlg == TRUE)
//	{
//		
//	}
//	
//}

void CEnemy::Init()//初期化
{
	x = 300.0;//座標
	y = 300.0;//座標

	//縦横
	height = 20.0;
	width = 20.0;
	//angleX = 0.0;
	//angleY = 0.0;
	//enemySpeed = 2.0; //エネミースピード
}

void CEnemy::Draw()const//描画関数
{
	DrawRotaGraphF(x, y, 1.0/ ENEMY_IMAGE_SIZE * ENEMY_ENEMY_SIZE,0,
		enemy[0],TRUE);//Fをつけることでキャストする必要がない、少数なので1.0にしないといけない
	DrawRotaGraphF(x, y, 1.0/ ENEMY_IMAGE_SIZE * ENEMY_ENEMY_SIZE,0,
		enemyEye[3],TRUE);
	
}

//void CEnemy::MoveEnemy()
//{
//
//}
//
//void CEnemy::notOverhang()
//{
//
//}
//
//float CEnemy::GetPosX()
//{
//	angleX = GetRand(1280) / 1280.f * 1280;
//}
//
//float CEnemy::GetPosY()
//{
//	angleY = GetRand(720) / 720.f * 720;
//}

