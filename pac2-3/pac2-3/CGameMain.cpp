#include"DxLib.h"
#include "CGameMain.h"
#include"CAbstractEnemy.h"
#include"CField.h"
#include"CEsa.h"
#include"CEsaController.h"
#include"CPlayer.h"
#include"CUi.h"

XINPUT_STATE keyState;//デバッグ用　TODO：消す

//-------------------
// コンストラクタ
//-------------------
CGameMain::CGameMain()
{
	isPlayMode = true;
	gameOverImage = LoadGraph("images/game_over.png");
	field = new CField;
	enemy = new CAbstractEnemy;
	esaController = new CEsaController();
	esa = esaController->GetEsa();
	player = new CPlayer(controller);
	ui = new CUi;//uiの動的確保
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
}

//-------------------
// 更新
//-------------------
CAbstractScene* CGameMain::Update()
{
	esaController->Update();
	player->Update();
	enemy->Update();
	ui->Update();

	if (keyState->Buttons[XINPUT_BUTTON_START] == TRUE)
	{
		esaController->DeleteFeed();
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

	field->Update();
	

	return this;
}

//-------------------
// 描画
//-------------------
void CGameMain::Draw()const
{
	field->Draw();
	esaController->Draw();
	player->Draw();
	enemy->Draw();
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
		
		if (CheckHitBox(player, enemy))
		{
			DrawString(0, 500 + i++ * 20, "HIT", 0x3355FF);
		}
	}
}


//-----------------------------
// 当たり判定
//-----------------------------
void CGameMain::HitCheck()
{
	HitCheck_PlayerAndFeed();
	HitCheck_PlayerAndEnemy();
}

//-------------------------------
// 当たり判定　プレイヤー：エサ
//-------------------------------
void CGameMain::HitCheck_PlayerAndFeed()
{
	//1マスの範囲が、10～30になっていているため、20で区切るために+10する
	int x = (player->GetX() + D_TILE_SIZE / 2) / D_TILE_SIZE;
	int y = (player->GetY() + D_TILE_SIZE / 2) / D_TILE_SIZE;
	int index = esaController->GetEsaIndex(x, y);
	if (index > -1)
	{
		if (esa[index].GetFlg() == true)
		{
			CheckHitBox(player, &esa[index]);
		}
	}
	
}

//------------------------------------
// 当たり判定　プレイヤー：敵
//------------------------------------
void CGameMain:: HitCheck_PlayerAndEnemy()
{
	CheckHitBox(player, enemy);
}