#include"DxLib.h"
#include "CGameMain.h"
#include"CAbstractEnemy.h"
#include"CField.h"
#include"CEsa.h"
#include"CEsaController.h"
#include"CPlayer.h"
#include"CUi.h"
#include"CHitPoint.h"
#include"CFruit.h"


XINPUT_STATE keyState;//デバッグ用　TODO：消す

//-------------------
// コンストラクタ
//-------------------
CGameMain::CGameMain()
{
	isPlayMode = true;
	gameOverImage = LoadGraph("images/game_over.png");
	field = new CField;
	tiles = field->GetTiles();
	enemy = new CAbstractEnemy;
	esaController = new CEsaController();
	esa = esaController->GetEsa();
	player = new CPlayer(controller);
	ui = new CUi;//uiの動的確保
	hitPoint = new CHitPoint();
	fruit = new CFruit();

}

//-------------------
// デストラクタ
//-------------------
CGameMain::~CGameMain()
{
	delete field;
	delete esaController;
	delete enemy;
	delete player;
	delete hitPoint;
	delete ui;
	delete fruit;
}

//-------------------
// 更新
//-------------------
CAbstractScene* CGameMain::Update()
{
	enemy->SetTargetPos(player->GetX(), player->GetY());
	esaController->Update();

	player->Update();
	ui->Update();

	if (player->GetisAlive() == true)
	{
		PlayerControl();
		enemy->Update();

	}
	

	if (keyState->Buttons[XINPUT_BUTTON_START] == TRUE)
	{
		esaController->DeleteFeed();
	}

	if (keyState->Buttons[XINPUT_BUTTON_A] == TRUE)
	{
		fruit->Advent(0);
		enemy->LeaveTheNest();
	}

	if (keyState->Buttons[XINPUT_BUTTON_B] == TRUE)
	{
		player->Respawn();
	}

	if (isPlayMode)
	{
		if (esaController->GetIsClear() == true)//エサの残りの数を受け取り、0の時にゲームクリアとする
		{
			//ゲームクリアの処理
			// ステージの更新
			// エサの再配置
			//敵の初期化(難易度を渡す)
			//プレイヤーの位置の初期化、難易度の更新
			isPlayMode = false;


			if (keyState->Buttons[XINPUT_BUTTON_X] == TRUE)//プレイヤーが敵に当たった時、残機が0だったらゲームオーバーとする
			{

			}
		}
		else
		{
			HitCheck();
		}

	}
	else
	{

		//スタートモードを流す

		//流れ終わったらプレイモードに返す
		isPlayMode = true;
	}

	return this;
}

//-------------------
// 描画
//-------------------
void CGameMain::Draw()const
{
	field->Draw();
	esaController->Draw();
	fruit->Draw();
	
	player->Draw();
	enemy->Draw();

	hitPoint->Draw();
	//coffeebreak3->Draw();//TODO : 移動させる


	DrawFormatString(0, 0, 0xffffff, "%d", saveData);
	ui->Draw();

	if (keyState->Buttons[XINPUT_BUTTON_X] == TRUE)//プレイヤーが敵に当たった時、残機が0だったらゲームオーバーとする
	{
		DrawRotaGraph(D_SCREEN_SIZE_WIDTH / 2, D_GAMEOVER_POS * (int)D_TILE_SIZE - (int)(D_TILE_SIZE / 2)//中心座標の為
			, 1.0 / 8 * D_TILE_SIZE, 0, gameOverImage, TRUE);
	}
	if (isPlayMode)
	{
		DrawString(0, 0, "PlayMode", 0xFFFFFF);
	}
	else
	{
		DrawString(0, 0, "StartMode", 0xFFFFFF);
	}


	//デバッグ数値表示用
	{
		int i = 0;
		if (esaController->GetIsClear() == true)
		{
			DrawString(0, 500 + i++ * 20, "gameClear", 0xFFFFF0);
		}
		
		DrawFormatString(0, 500 + i++ * 20, 0x3355FF, "%d",hitPoint->playerLife);


	}


}


//-----------------------------
// 当たり判定
//-----------------------------
void CGameMain::HitCheck()
{
	HitCheck_PlayerAndFeed();
	HitCheck_PlayerAndEnemy();
	HitCheck_PlayerAndFruit();
}

//-------------------------------
// 当たり判定　プレイヤー：エサ
//-------------------------------
void CGameMain::HitCheck_PlayerAndFeed()
{
	//1マスの範囲が、10～30になっていているため、20で区切るために+10する
	int x = (int)((player->GetX() + D_TILE_SIZE / 2) / D_TILE_SIZE);
	int y = (int)((player->GetY() + D_TILE_SIZE / 2) / D_TILE_SIZE);
	int index = esaController->GetEsaIndex(x, y);


	if (index > -1)
	{
		if (esa[index].GetFlg() == true)
		{
			if (CheckHitBox(player, &esa[index]))//プレイヤーとエサが当たった時
			{
				ui->AddScore(esa[index].GetScore());//uiの合計のスコアにesaのスコアを入れる処理
				
				if (esa[index].EsaGetType() == TRUE)//この部分の条件式をパワーエサを食べたときに変えたい
				{
					enemy->Surprised();
				}
			}


		}

		if (fruit[index].GetFlg() == true) {

			if (CheckHitBox(player, &fruit[index]))//プレイヤーとフルーツが当たった時
			{
				ui->AddScore(fruit[FRUIT_MAX].GetScore());//uiの合計のスコアにfruitのスコアを入れる処理
			}

		}

	}

}

//------------------------------------
// 当たり判定　プレイヤー：敵
//------------------------------------
void CGameMain::HitCheck_PlayerAndEnemy()
{
	if (CheckHitBox(player, enemy))
	{
		if (enemy->GetisSurprising())
		{
			enemy->HitAction_Player();
		}
		else
		{
			if (enemy->GetisHit())
			{
				player->HitAction_Enemy();
				hitPoint->Respawn();
			}
		}
	}

}

//----------------------------------
// プレイヤーの入力制御
//----------------------------------
void CGameMain::PlayerControl()
{

	//1マスの範囲が、10～30になっていているため、20で区切るために+10する
	int x = (int)((player->GetX() + D_TILE_SIZE / 2) / D_TILE_SIZE);
	int y = (int)((player->GetY() + D_TILE_SIZE / 2) / D_TILE_SIZE);
	if (field->GetTileData(y - 1, x) != D_FIELD_FLOOR)
	{
		PreventOverlapCircle_Box(player, &tiles[y - 1][x]);
	}
	else
	{
		player->ChangeDirection(D_PLAYER_UP);
	}

	if (field->GetTileData(y + 1, x) != D_FIELD_FLOOR)
	{
		PreventOverlapCircle_Box(player, &tiles[y + 1][x]);
	}
	else
	{
		player->ChangeDirection(D_PLAYER_DOWN);
	}

	if (field->GetTileData(y, x - 1) != D_FIELD_FLOOR)
	{
		PreventOverlapCircle_Box(player, &tiles[y][x - 1]);
	}
	else
	{
		player->ChangeDirection(D_PLAYER_LEFT);
	}

	if (field->GetTileData(y, x + 1) != D_FIELD_FLOOR)
	{
		PreventOverlapCircle_Box(player, &tiles[y][x + 1]);
	}
	else
	{
		player->ChangeDirection(D_PLAYER_RIGHT);
	}


	if (field->GetTileData(y - 1, x - 1) != D_FIELD_FLOOR)
	{
		PreventOverlapCircle_Box(player, &tiles[y - 1][x - 1]);
	}
	if (field->GetTileData(y - 1, x + 1) != D_FIELD_FLOOR)
	{
		PreventOverlapCircle_Box(player, &tiles[y - 1][x + 1]);
	}
	if (field->GetTileData(y + 1, x + 1) != D_FIELD_FLOOR)
	{
		PreventOverlapCircle_Box(player, &tiles[y + 1][x + 1]);
	}
	if (field->GetTileData(y + 1, x - 1) != D_FIELD_FLOOR)
	{
		PreventOverlapCircle_Box(player, &tiles[y + 1][x - 1]);
	}
}


//----------------------------------
// 当たり判定　プレイヤー:フルーツ
//----------------------------------
void CGameMain::HitCheck_PlayerAndFruit()
{
	if (fruit->GetFlg())
	{
		if (CheckHitBox(player, fruit))
		{
			ui->AddScore(fruit->HitAction_Player());
		}
	}
}