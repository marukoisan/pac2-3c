#pragma once
#include"Object.h"
#define ENEMY_IMAGE_MAX  20  //エネミー画像の数
#define ENEMY_IMAGEEYE_MAX  4  //エネミー画像の数
#define ENEMY_IMAGE_SIZE  32 //大元の画像の大きさ
#define ENEMY_ENEMY_SIZE  20.0 //今から使う画像の大きさ


class CEnemy : public CObject
{
private:
	
	int enemy[ENEMY_IMAGE_MAX];    //エネミー本体画像
	//int enemyRun; //エネミー移動用画像
	
	int enemyEye[ENEMY_IMAGEEYE_MAX]; //エネミーの目画像
	float enemySpeed; //エネミースピード

	//float angleX;   //乱数で出されたX座標
	//float angleY;   //乱数で出されたY座標

	float x;   //座標
	float y;   //座標

	//当たり判定　縦横
	float height;
	float width;

	bool enemyFlg;//エネミーフラグ


public:
	CEnemy();     //コンストラクタ
	void EnemyDisplay();  //エネミー表示
	void Init();  //変数初期化用
	void Update() {} //継承元のUpdate
	void Draw()const;   //画像用関数
	void HitAction() {} //継承元のHitAction
	void MoveEnemy();   //エネミー移動
	void notOverhang(); //はみ出さない処理を行う 
	float GetPosX();     //プロト用の座標を取得する関数 X用
	float GetPosY();     //プロト用の座標を取得する関数 Y用

};

