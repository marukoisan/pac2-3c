#include"DxLib.h"
#include "CGameMain.h"
#include"CAbstractEnemy.h"
#include"CField.h"
#include"CEsa.h"
#include"CEsaController.h"
#include"CPlayer.h"
#include"CUi.h"
#include"CHitPoint.h"


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
	hitPoint = new CHitPoint();

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

}

//-------------------
// 更新
//-------------------
CAbstractScene* CGameMain::Update()
{
	esaController->Update();

	if (player->CheckAnimflg() == TRUE) 
	{
	player->Update();
	enemy->Update();

	player->CPlayeranim();

	}
	ui->Update();

	

	if (keyState->Buttons[XINPUT_BUTTON_START] == TRUE)
	{
		esaController->DeleteFeed();
	}

	if (keyState->Buttons[XINPUT_BUTTON_A] == TRUE)//この部分の条件式をパワーエサを食べたときに変えたい
	{
		enemy->Surprised();
	}

	if (keyState->Buttons[XINPUT_BUTTON_B] == TRUE)
	{
		enemy->HitAction_Player();
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

	if (player->CheckAnimflg() == TRUE)
	{
		player->Draw();
		enemy->Draw();
	}

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
			//敵に当たったときアニメーション再生
			
				player->AnimFlg();
				player->HitActionanim();
				DrawString(0, 500 + i++ * 20, "HIT", 0x3355FF);
			
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
				esa->AddEsaGetType(esa[index].EsaGetType());//エサタイプの値を入れる処理
			}
		}
	}
	
}

//------------------------------------
// 当たり判定　プレイヤー：敵
//------------------------------------
void CGameMain:: HitCheck_PlayerAndEnemy()
{
	if (CheckHitBox(player, enemy))
	{
		//敵に当たったらリスポーン位置に移動
		hitPoint->Respawn();
		/*player->Respawn();*/
	}
}