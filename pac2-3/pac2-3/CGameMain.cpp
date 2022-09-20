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
#include"CAkabei.h"
#include"CPinky.h"


XINPUT_STATE keyState;//デバッグ用　TODO：消す

//-------------------
// コンストラクタ
//-------------------
CGameMain::CGameMain()
{
	isPlayMode = false;
	gameOverImage = LoadGraph("images/game_over.png");
	readyImage = LoadGraph("images/ready.png");
	player_oneImage = LoadGraph("images/player_one.png");
	field = new CField;
	tiles = field->GetTiles();
	esaController = new CEsaController();
	esa = esaController->GetEsa();
	player = new CPlayer(controller);
	ui = new CUi;//uiの動的確保
	hitPoint = new CHitPoint();
	fruit = new CFruit();

	akabei = new CAkabei;
	akabei->SetPlayerCrass(player);

	pinky = new CPinky;
	pinky->SetPlayerCrass(player);

	isGameStart = true;
	isGameOver = false;
	startModeTimer = 0;
	playerAnimTimer = 9 * 11 + 1;
	stopTimer = 0;
}

//-------------------
// デストラクタ
//-------------------
CGameMain::~CGameMain()
{
	delete field;
	delete esaController;
	delete player;
	delete hitPoint;
	delete ui;
	delete fruit;
	delete akabei;
	delete pinky;
}

//-------------------
// 更新
//-------------------
CAbstractScene* CGameMain::Update()
{
	stopTimer--;
	if (isGameStart)
	{
		if (startModeTimer < 60 * 2)
		{
			startModeTimer++;
		}
		else
		{
			hitPoint->Respawn();
			isGameStart = false;
			startModeTimer = 0;
		}
	}
	else
	{
		ui->Update();
		esaController->Update();

		if (stopTimer < 0)
		{





			if (keyState->Buttons[XINPUT_BUTTON_START] == TRUE)
			{
				esaController->DeleteFeed();
			}

			if (keyState->Buttons[XINPUT_BUTTON_A] == TRUE)
			{
				fruit->Advent(3);
				pinky->LeaveTheNest();
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


				}
				else
				{
					if (player->GetisAlive() == true)
					{
						PlayerControl();
						akabei->Update();
						pinky->Update();
					}
					player->Update();
					HitCheck();
				}

			}
			else
			{
				if (!(playerAnimTimer > 9 * 11))
				{
					player->Update();
					playerAnimTimer++;
					if (playerAnimTimer == 9 * 11)
					{
						stopTimer = 30;
					}
					if (playerAnimTimer > 9 * 11)
					{
						hitPoint->Respawn();
						akabei->Init();
						pinky->Init();
					}
				}
				else
				{
					//スタートモードを流す
					startModeTimer++;
					if (startModeTimer > 60 * 2)
					{
						//流れ終わったらプレイモードに返す
						isPlayMode = true;
						startModeTimer = 0;
					}
				}
			}
		}
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

	hitPoint->Draw();
	//coffeebreak3->Draw();//TODO : 移動させる


	DrawFormatString(0, 0, 0xffffff, "%d", saveData);
	ui->Draw();

	if (isGameOver)
	{
		DrawRotaGraph(D_SCREEN_SIZE_WIDTH / 2, D_GAMEOVER_POS * (int)D_TILE_SIZE - (int)(D_TILE_SIZE / 2)//中心座標の為
			, 1.0 / 8 * D_TILE_SIZE, 0, gameOverImage, TRUE);
	}

	if (isGameStart)
	{
		DrawRotaGraphF(D_SCREEN_SIZE_WIDTH / 2, 15 * (int)D_TILE_SIZE - (int)(D_TILE_SIZE / 2)//中心座標の為
			, 1.0 / 8 * D_TILE_SIZE, 0, player_oneImage, TRUE);
	}
	else
	{
		akabei->Draw();
		pinky->Draw();
	}

	if (isPlayMode && !isGameOver)
	{
		DrawString(0, 0, "PlayMode", 0xFFFFFF);
	}
	else
	{
		if (playerAnimTimer > 9 * 11)
		{
			if (startModeTimer <= 60 * 2)
			{
				DrawRotaGraphF(D_SCREEN_SIZE_WIDTH / 2, D_GAMEOVER_POS * (int)D_TILE_SIZE - (int)(D_TILE_SIZE / 2)//中心座標の為
					, 1.0 / 7 * D_TILE_SIZE, 0, readyImage, TRUE);
			}
		}
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
					akabei->Surprised();
					pinky->Surprised();
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
	if (player->GetisAlive())
	{
		//アカベイ
		if (CheckHitBox(player, akabei))
		{
			if (akabei->GetisSurprising())
			{
				akabei->HitAction_Player();
			}
			else
			{
				if (akabei->GetisHit())
				{
					player->HitAction_Enemy();
					isPlayMode = false;
					playerAnimTimer = 0;
					stopTimer = 60;
				}
			}
		}

		//ピンキー
		if (CheckHitBox(player, pinky))
		{
			if (pinky->GetisSurprising())
			{
				pinky->HitAction_Player();
			}
			else
			{
				if (pinky->GetisHit())
				{
					player->HitAction_Enemy();
					isPlayMode = false;
					playerAnimTimer = 0;
					stopTimer = 60;
				}
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