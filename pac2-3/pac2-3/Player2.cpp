/***********************************************
 ** 　パックマン
 ***********************************************/
#include "DxLib.h"
#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>
 #include"Player2.h"

 //#include"main.h"

  /***********************************************
   *変数宣言
  /***********************************************/
   //MovePlayer moveplayer;
   //BaseAP baseap;


int g_OldKey;//前回の入力キー
int g_NowKey;//今回の入力キー
int g_KeyFlg;//入力キー情報
int g_GameState = 0;//ゲームモード
//int g_TitleImage;//画像用変数
//int g_Score = 0;//スコア
//int g_WaitTime = 0;//待ち時間
//int g_EndImage;
//int g_Mileage;//走行距離
//int g_EnemyCount1, g_EnemyCount2, g_EnemyCount3;//敵カウント
//int g_Appleimage;//キャラ画像変数
int g_PlayerUp, g_PlayerRight,g_PlayerLeft,g_PlayerDawn;          //キャラ画像変数
//int g_StageImage;
//int g_PosY;            //スクロール時のY座標
//int g_HelpImage;
//int g_Menu, g_AppleMenu;//メニュー画像変数


/***********************************************
 *関数のプロトタイプ宣言
 ***********************************************/

void GameInit(void);//ゲーム初期化処理
void GameMain(void);//ゲームメイン処理
int LoadImages();

//void DrawEnd();	//ゲームエンド処理
//void DrawGameTitle();//タイトル描画処理
//void DrawHelp();

/***********************************************
 *プログラムの開始
 ***********************************************/

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
//	LPSTR lpCmdLine, int nCmdShow) {
//
//	SetMainWindowText("Pacman");//タイトルを設定
//	ChangeWindowMode(TRUE);//ウィンドウモードで起動
//	if (DxLib_Init() == -1)return -1;//DXライブラリの初期化処理
//	SetDrawScreen(DX_SCREEN_BACK);//描画先画面を裏にする
//	if (LoadImages() == -1)return -1;//画像読み込み関数を呼び出し
//
//	//ゲームループ
//	while (ProcessMessage() == 0 && g_GameState != 99 && !(g_KeyFlg & PAD_INPUT_START)) {
//		// 入力キー取得
//		g_OldKey = g_NowKey;
//		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//		g_KeyFlg = g_NowKey & ~g_OldKey;
//		ClearDrawScreen();//画像の初期化
//
//		switch (g_GameState) {
//			//case 0:
//			//	DrawGameTitle();	//ゲームタイトル描画処理
//			//	break;
//		case 1:
//			GameInit();		//ゲーム初期処理
//			break;
//			//case 3:
//			//	DrawHelp();		//ゲームヘルプ描画処理
//			//	break;
//			//case 4:
//			//	DrawEnd();		//ゲームエンド描画処理
//			//	break;
//		case 5:
//			GameMain();     //ゲームメイン処理
//			break;
//
//
//		}
//		ScreenFlip();     //裏画面の内容を表画面に反映
//	}
//	DxLib_End();
//
//	return 0;
//}

/***********************************************
 *ゲームタイトル表示(メニュー画面)
 ***********************************************/
 //void DrawGameTitle(void) {
 //	static int MenuNo = 0;
 //	//メニューカーソル移動処理
 //	if (g_KeyFlg & PAD_INPUT_DOWN) {
 //		if (++MenuNo > 3)MenuNo = 0;
 //	}
 //	if (g_KeyFlg & PAD_INPUT_UP) {
 //		if (--MenuNo < 0)MenuNo = 3;
 //	}
 //	//Aボタンでメニュー選択
 //	if (g_KeyFlg & PAD_INPUT_A)g_GameState = MenuNo + 1;
 //	//タイトル画像表示
 //	DrawGraph(0, 0, g_TitleImage, FALSE);
 //	//メニュー
 //	DrawGraph(120, 200, g_Menu, TRUE);
 //	//メニューカーソル
 //	DrawRotaGraph(125, 220 + MenuNo * 35, 0.7f, M_PI / 50, g_Appleimage, TRUE);
 //}

 /***********************************************
  *ゲーム初期処理
  ***********************************************/
void GameInit(void) {


	//プレイヤーの初期設定
	/*baseap.PlayerInit();*/


	//ゲームメイン処理へ
	g_GameState = 5;//1
}

/***********************************************
 *ゲームメイン
***********************************************/
void GameMain(void) {
	/*moveplayer.PlayerControl(g_PlayerRight, g_PlayerLeft);
	moveapple.AppleControl();*/
}


/***********************************************
*画像読み込み
***********************************************/

int LoadImages() {

	//タイトル
	//if ((g_TitleImage = LoadGraph("images/Title.png")) == -1)return -1;
	
	//敵
	//if ((g_Appleimage = LoadGraph("images/Apple.png")) == -1)return-1;

	////ステージ背景
	//if ((g_StageImage = LoadGraph("images/mori.png")) == -1) return -1;

	////エンディング
	//if ((g_EndImage = LoadGraph("images/mori.png")) == -1) return -1;

	//プレイヤー
	if ((g_PlayerUp = LoadGraph("images/sprites/pacman.png")) == -1)return -1;//上
	//if ((g_PlayerRight = LoadGraph("images/sprites/pacman.png")) == -1)return -1;//右
	//if ((g_PlayerLeft = LoadGraph("images/sprites/pacman.png")) == -1)return -1;//左
	//if ((g_PlayerDawn = LoadGraph("images/sprites/pacman.png")) == -1)return -1;//下
	

	//ヘルプ
	//if ((g_HelpImage = LoadGraph("images/Gamehelp.png")) == -1)return -1;

	//メニュー
	//if ((g_Menu = LoadGraph("images/menu.png")) == -1) return -1;
	//if ((g_AppleMenu = LoadGraph("images/Apple.png")) == -1) return-1;


	return 0;
}

//int AppleGame::getg_Appleimage() {
//	return g_Appleimage;
//}
//int AppleGame::getMileage() {
//	return g_Mileage;
//}
//int AppleGame::getNowKey() {
//	return g_NowKey;
//}
//int AppleGame::getSCREEN_WIDTH() {
//	return SCREEN_WIDTH;
//}
//int AppleGame::getSCREEN_HEIGHT() {
//	return SCREEN_HEIGHT;
//}
//int AppleGame::getg_PlayerLeft(int a) {
//	return g_PlayerLeft;
//}
//int AppleGame::getg_PlayerRight(int b) {
//	return g_PlayerRight;
//}




