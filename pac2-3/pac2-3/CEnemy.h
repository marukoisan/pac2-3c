#pragma once


class CEnemy
{
private:
	int enemy;    //エネミー静止画像
	int enemyRun; //エネミー移動用画像
	float enemySpeed; //エネミースピード
	float enemyX;   //座標
	float enemyY;   //座標

	//bool enemyFlg;//エネミーフラグ


public:
	CEnemy();     //コンストラクタ
	void EnemyDisplay(void);  //エネミー表示
	void Init();  //変数初期化用
	int Image();  //画像用関数
	void MoveEnemy();   //エネミー移動

};