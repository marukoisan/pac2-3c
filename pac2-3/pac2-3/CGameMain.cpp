#include"DxLib.h"
#include "CGameMain.h"
#include"CAbstractEnemy.h"
#include"CField.h"
#include"CEsa.h"
#include"CEsaController.h"
#include"CPlayer.h"

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

	if (esaController->GetIsClear() == true)
	{
		DrawString(0, 500, "gameClear", 0xFFFFF0);
	}
}