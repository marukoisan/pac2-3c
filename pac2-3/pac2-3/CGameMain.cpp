#include"DxLib.h"
#include "CGameMain.h"
#include"CAbstractEnemy.h"
#include"CField.h"
#include"CEsa.h"
#include"CEsaController.h"

XINPUT_STATE keyState;//デバッグ用　TODO：消す

//-------------------
// コンストラクタ
//-------------------
CGameMain::CGameMain()
{
	isPlayMode = true;
	gameOverImage = LoadGraph("game_over.png");
	field = new CField;
	enemy = new CAbstractEnemy;
	esacontroller = new CEsaController();
}

//-------------------
// デストラクタ
//-------------------
CGameMain::~CGameMain()
{
	delete field;
	delete esacontroller;
	delete enemy;
}

//-------------------
// 更新
//-------------------
CAbstractScene* CGameMain::Update()
{
	enemy->Update();

	if (isPlayMode)
	{
		//デバッグ用
		
		GetJoypadXInputState(DX_INPUT_PAD1, &keyState);
		if (keyState.Buttons[XINPUT_BUTTON_START] == TRUE)//エサの残りの数を受け取り、0の時にゲームクリアとする
		{
			//ゲームクリアの処理
			// ステージの更新
			// エサの再配置
			//敵の初期化(難易度を渡す)
			//プレイヤーの位置の初期化、難易度の更新
			isPlayMode = false;


			if (keyState.Buttons[XINPUT_BUTTON_X] == TRUE)//プレイヤーが敵に当たった時、残機が0だったらゲームオーバーとする
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
	enemy->Draw();
	field->Draw();
	esacontroller->Draw();
	DrawFormatString(0, 0, 0xffffff, "%d", saveData);

	if (keyState.Buttons[XINPUT_BUTTON_X] == TRUE)//プレイヤーが敵に当たった時、残機が0だったらゲームオーバーとする
	{
		DrawRotaGraph(D_SCREEN_SIZE_WIDTH / 2, D_GAMEOVER_POS * D_TILE_SIZE - (D_TILE_SIZE / 2)//中心座標の為
							, 1.0 / 8 * D_TILE_SIZE, 0, gameOverImage, TRUE);
		WaitKey();
	}
	if (isPlayMode)
	{
		DrawString(0, 0, "PlayMode", 0xFFFFFF);
	}
	else
	{
		DrawString(0, 0, "StartMode", 0xFFFFFF);
	}
}