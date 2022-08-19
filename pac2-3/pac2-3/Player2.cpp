///***********************************************
// ** 　パックマン
// ***********************************************/
//#include "DxLib.h"
//#include<stdio.h>
//#define _USE_MATH_DEFINES
//#include<math.h>
// #include"Player2.h"
//
// //#include"main.h"
//
//  /***********************************************
//   *変数宣言
//  /***********************************************/
//   //MovePlayer moveplayer;
//   //BaseAP baseap;
//
//
//int g_OldKey;//前回の入力キー
//int g_NowKey;//今回の入力キー
//int g_KeyFlg;//入力キー情報
//int g_GameState = 0;//ゲームモード
////int g_TitleImage;//画像用変数
////int g_Score = 0;//スコア
////int g_WaitTime = 0;//待ち時間
////int g_EndImage;
////int g_Mileage;//走行距離
////int g_EnemyCount1, g_EnemyCount2, g_EnemyCount3;//敵カウント
////int g_Appleimage;//キャラ画像変数
//int g_PlayerUp, g_PlayerRight,g_PlayerLeft,g_PlayerDawn;          //キャラ画像変数
////int g_StageImage;
////int g_PosY;            //スクロール時のY座標
////int g_HelpImage;
////int g_Menu, g_AppleMenu;//メニュー画像変数
//
//
///***********************************************
// *関数のプロトタイプ宣言
// ***********************************************/
//
//void GameInit(void);//ゲーム初期化処理
//void GameMain(void);//ゲームメイン処理
//int LoadImages();
//
////void DrawEnd();	//ゲームエンド処理
////void DrawGameTitle();//タイトル描画処理
////void DrawHelp();
//
///***********************************************
// *プログラムの開始
// ***********************************************/
//
////int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
////	LPSTR lpCmdLine, int nCmdShow) {
////
////	SetMainWindowText("Pacman");//タイトルを設定
////	ChangeWindowMode(TRUE);//ウィンドウモードで起動
////	if (DxLib_Init() == -1)return -1;//DXライブラリの初期化処理
////	SetDrawScreen(DX_SCREEN_BACK);//描画先画面を裏にする
////	if (LoadImages() == -1)return -1;//画像読み込み関数を呼び出し
////
////	//ゲームループ
////	while (ProcessMessage() == 0 && g_GameState != 99 && !(g_KeyFlg & PAD_INPUT_START)) {
////		// 入力キー取得
////		g_OldKey = g_NowKey;
////		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
////		g_KeyFlg = g_NowKey & ~g_OldKey;
////		ClearDrawScreen();//画像の初期化
////
////		switch (g_GameState) {
////			//case 0:
////			//	DrawGameTitle();	//ゲームタイトル描画処理
////			//	break;
////		case 1:
////			GameInit();		//ゲーム初期処理
////			break;
////			//case 3:
////			//	DrawHelp();		//ゲームヘルプ描画処理
////			//	break;
////			//case 4:
////			//	DrawEnd();		//ゲームエンド描画処理
////			//	break;
////		case 5:
////			GameMain();     //ゲームメイン処理
////			break;
////
////
////		}
////		ScreenFlip();     //裏画面の内容を表画面に反映
////	}
////	DxLib_End();
////
////	return 0;
////}
//
///***********************************************
// *ゲームタイトル表示(メニュー画面)
// ***********************************************/
// //void DrawGameTitle(void) {
// //	static int MenuNo = 0;
// //	//メニューカーソル移動処理
// //	if (g_KeyFlg & PAD_INPUT_DOWN) {
// //		if (++MenuNo > 3)MenuNo = 0;
// //	}
// //	if (g_KeyFlg & PAD_INPUT_UP) {
// //		if (--MenuNo < 0)MenuNo = 3;
// //	}
// //	//Aボタンでメニュー選択
// //	if (g_KeyFlg & PAD_INPUT_A)g_GameState = MenuNo + 1;
// //	//タイトル画像表示
// //	DrawGraph(0, 0, g_TitleImage, FALSE);
// //	//メニュー
// //	DrawGraph(120, 200, g_Menu, TRUE);
// //	//メニューカーソル
// //	DrawRotaGraph(125, 220 + MenuNo * 35, 0.7f, M_PI / 50, g_Appleimage, TRUE);
// //}
//
//// /***********************************************
////  *ゲーム初期処理
////  ***********************************************/
////void GameInit(void) {
////
////
////	//プレイヤーの初期設定
////	/*baseap.PlayerInit();*/
////
////
////	//ゲームメイン処理へ
////	g_GameState = 5;//1
////}
////
/////***********************************************
//// *ゲームメイン
////***********************************************/
////void GameMain(void) {
////
////
////	/*moveplayer.PlayerControl(g_PlayerRight, g_PlayerLeft);
////	moveapple.AppleControl();*/
////}
//
//
///***********************************************
//*画像読み込み
//***********************************************/
//
//int LoadImages() {
//
//	//タイトル
//	//if ((g_TitleImage = LoadGraph("images/Title.png")) == -1)return -1;
//	
//	//敵
//	//if ((g_Appleimage = LoadGraph("images/Apple.png")) == -1)return-1;
//
//	////ステージ背景
//	//if ((g_StageImage = LoadGraph("images/mori.png")) == -1) return -1;
//
//	////エンディング
//	//if ((g_EndImage = LoadGraph("images/mori.png")) == -1) return -1;
//
//	//プレイヤー
//	if ((g_PlayerUp = LoadGraph("images/sprites/pacman.png")) == -1)return -1;//上
//	//if ((g_PlayerRight = LoadGraph("images/sprites/pacman.png")) == -1)return -1;//右
//	//if ((g_PlayerLeft = LoadGraph("images/sprites/pacman.png")) == -1)return -1;//左
//	//if ((g_PlayerDawn = LoadGraph("images/sprites/pacman.png")) == -1)return -1;//下
//	
//
//	//ヘルプ
//	//if ((g_HelpImage = LoadGraph("images/Gamehelp.png")) == -1)return -1;
//
//	//メニュー
//	//if ((g_Menu = LoadGraph("images/menu.png")) == -1) return -1;
//	//if ((g_AppleMenu = LoadGraph("images/Apple.png")) == -1) return-1;
//
//
//	return 0;
//}
//
////int AppleGame::getg_Appleimage() {
////	return g_Appleimage;
////}
////int AppleGame::getMileage() {
////	return g_Mileage;
////}
////int AppleGame::getNowKey() {
////	return g_NowKey;
////}
////int AppleGame::getSCREEN_WIDTH() {
////	return SCREEN_WIDTH;
////}
////int AppleGame::getSCREEN_HEIGHT() {
////	return SCREEN_HEIGHT;
////}
////int AppleGame::getg_PlayerLeft(int a) {
////	return g_PlayerLeft;
////}
////int AppleGame::getg_PlayerRight(int b) {
////	return g_PlayerRight;
////}
//
//#include "DxLib.h"
//
//#define MAP_NUM         3           // マップの数
//
//#define MAP_SIZE        32          // マップチップ一つのドットサイズ
//
//#define MAP_WIDTH_MAX   40          // マップの最大幅
//#define MAP_HEIGHT_MAX  40          // マップの最大縦長さ
//
//#define MOVE_FRAME      15          // 移動にかけるフレーム数
//
//// マップの構造体
//struct MAPDATA
//{
//    // マップの幅
//    int Width;
//
//    // マップの高さ
//    int Height;
//
//    // マップ
//    int Data[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
//};
//
//// マップのデータ
//MAPDATA MapData[MAP_NUM] =
//{
//    // マップ０
//    {
//        10,
//        8,
//        {
//            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
//            { 0, 1, 0, 0, 0, 1, 1, 1, 1, 0 } ,
//            { 0, 1, 1, 1, 0, 1, 1, 0, 1, 0 } ,
//            { 0, 0, 0, 1, 0, 1, 1, 0, 1, 0 } ,
//            { 0, 0, 0, 1, 0, 0, 1, 0, 1, 0 } ,
//            { 0, 0, 1, 1, 0, 0, 1, 0, 1, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 1, 0, 1, 0 } ,
//            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
//        }
//    },
//
//    // マップ１
//    {
//        20,
//        16,
//        {
//            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
//            { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 ,  1, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
//            { 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 ,  1, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
//            { 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 ,  1, 1, 1, 1, 1, 1, 0, 0, 1, 0 } ,
//            { 0, 1, 1, 0, 1, 0, 0, 1, 1, 0 ,  0, 0, 0, 0, 0, 1, 0, 0, 1, 0 } ,
//            { 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 ,  0, 0, 1, 1, 1, 1, 1, 0, 1, 0 } ,
//            { 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 ,  0, 0, 1, 0, 0, 1, 1, 0, 1, 0 } ,
//            { 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 ,  0, 0, 1, 0, 0, 1, 1, 0, 1, 0 } ,
//
//            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 ,  0, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
//            { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 ,  0, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
//            { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 ,  0, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
//            { 0, 0, 0, 1, 1, 0, 0, 1, 0, 0 ,  0, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
//            { 0, 1, 1, 1, 1, 0, 0, 1, 1, 1 ,  1, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
//            { 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
//            { 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
//            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
//        }
//    },
//
//    // マップ２
//    {
//        40,
//        32,
//        {
//            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 ,  0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  1, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 ,  0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  1, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 ,  0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  1, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 ,  0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  1, 0, 0, 0, 1, 1, 1, 1, 1, 1 ,  1, 1, 1, 1, 1, 1, 1, 1, 0, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 ,  0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  1, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  0, 0, 0, 1, 0, 0, 0, 1, 0, 0 } ,
//            { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 ,  0, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,  1, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  1, 1, 1, 1, 0, 0, 0, 1, 0, 0 } ,
//            { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  1, 0, 0, 0, 0, 1, 1, 1, 0, 0 } ,
//
//            { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  1, 0, 1, 0, 1, 1, 0, 0, 0, 0 } ,
//            { 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  1, 0, 1, 0, 1, 0, 0, 1, 1, 0 } ,
//            { 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  1, 0, 1, 0, 1, 0, 1, 1, 0, 0 } ,
//            { 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 1, 1, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  1, 0, 1, 0, 1, 1, 1, 0, 0, 0 } ,
//            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 1, 1, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  1, 1, 1, 0, 1, 0, 0, 1, 1, 0 } ,
//            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 1, 1, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  0, 0, 0, 0, 1, 0, 0, 1, 1, 0 } ,
//            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 1 ,  1, 1, 1, 1, 1, 0, 0, 1, 1, 0 } ,
//            { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 ,  1, 1, 1, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 1 ,  0, 0, 0, 1, 0, 1, 1, 1, 1, 0 } ,
//
//            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 1 ,  1, 1, 0, 1, 0, 1, 0, 0, 0, 0 } ,
//            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 1 ,  1, 1, 0, 1, 0, 1, 0, 1, 1, 0 } ,
//            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 1, 1, 1, 1, 1, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  0, 1, 0, 1, 1, 1, 0, 1, 1, 0 } ,
//            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 1, 0, 0, 0, 1, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 1, 1 ,  1, 1, 0, 0, 0, 0, 1, 1, 1, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,  1, 1, 1, 0, 0, 0, 1, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 1, 0 ,  0, 0, 0, 0, 0, 1, 1, 0, 1, 0 } ,
//            { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 1, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 1, 1 ,  1, 1, 1, 1, 1, 1, 0, 0, 1, 0 } ,
//            { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 1, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 1, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
//            { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 1, 1 ,  1, 1, 1, 1, 1, 1, 1, 0, 1, 0 } ,
//
//            { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 1, 0, 1, 0 } ,
//            { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 1, 1 ,  1, 1, 1, 1, 1, 1, 1, 0, 1, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  0, 1, 1, 1, 1, 1, 1, 1, 1, 0 ,  0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 1, 0, 1, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  0, 1, 0, 0, 0, 1, 0, 0, 1, 0 ,  0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
//            { 0, 1, 1, 0, 0, 1, 1, 0, 0, 0 ,  0, 1, 0, 0, 0, 1, 0, 0, 1, 0 ,  0, 1, 1, 1, 1, 0, 0, 0, 0, 0 ,  1, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  0, 1, 0, 0, 0, 1, 0, 0, 1, 0 ,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,  1, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  0, 1, 1, 1, 1, 1, 0, 0, 1, 1 ,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,  1, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
//            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
//        }
//    },
//};
//
//// 現在のマップ番号
//int MapNo;
//
//// プレイヤーの位置
//int PlayerX, PlayerY;
//
//// 移動しているかどうかのフラグ( 0:停止中  1:移動中 )
//int Move;
//
//// 各方向に移動する量
//int MoveX, MoveY;
//
//// 移動し始めてから何フレーム経過したかを保持する変数
//int MoveCounter;
//
//// マップとプレイヤーの描画関数
//void GraphDraw(int ScrollX, int ScrollY)
//{
//    int j, i;
//    int MapDrawPointX, MapDrawPointY;     // 描画するマップ座標値
//    int DrawMapChipNumX, DrawMapChipNumY; // 描画するマップチップの数
//
//    // 描画するマップチップの数をセット
//    DrawMapChipNumX = 640 / MAP_SIZE + 2;
//    DrawMapChipNumY = 480 / MAP_SIZE + 2;
//
//    // 画面左上に描画するマップ座標をセット
//    MapDrawPointX = PlayerX - (DrawMapChipNumX / 2 - 1);
//    MapDrawPointY = PlayerY - (DrawMapChipNumY / 2 - 1);
//
//    // マップを描く
//    for (i = -1; i < DrawMapChipNumY; i++)
//    {
//        for (j = -1; j < DrawMapChipNumX; j++)
//        {
//            // 画面からはみ出た位置なら描画しない
//            if (j + MapDrawPointX < 0 || i + MapDrawPointY < 0 ||
//                j + MapDrawPointX >= MapData[MapNo].Width || i + MapDrawPointY >= MapData[MapNo].Height) continue;
//
//            // マップデータが０だったら四角を描画する
//            if (MapData[MapNo].Data[i + MapDrawPointY][j + MapDrawPointX] == 0)
//            {
//                DrawBox(j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,
//                    j * MAP_SIZE + MAP_SIZE + ScrollX, i * MAP_SIZE + MAP_SIZE + ScrollY,
//                    GetColor(255, 0, 0), TRUE);
//            }
//        }
//    }
//
//    // プレイヤーの描画
//    DrawBox((PlayerX - MapDrawPointX) * MAP_SIZE, (PlayerY - MapDrawPointY) * MAP_SIZE,
//        (PlayerX - MapDrawPointX + 1) * MAP_SIZE, (PlayerY - MapDrawPointY + 1) * MAP_SIZE,
//        GetColor(255, 255, 255), TRUE);
//}
//
//// ＷｉｎＭａｉｎ関数
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
//    LPSTR lpCmdLine, int nCmdShow)
//{
//    int Key;
//    int ScrollX, ScrollY;
//
//    SetGraphMode(640, 480, 16);
//    if (DxLib_Init() == -1)    // ＤＸライブラリ初期化処理
//    {
//        return -1;             // エラーが起きたら直ちに終了
//    }
//
//    // 描画先画面を裏画面にする
//    SetDrawScreen(DX_SCREEN_BACK);
//
//    // プレイヤーの初期位置をセット
//    PlayerX = 1;
//    PlayerY = 1;
//
//    // 最初は停止中(0)にしておく
//    Move = 0;
//
//    // ループ
//    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
//    {
//        // 画面を初期化
//        ClearDrawScreen();
//
//        // スペースキーが押されたらマップ番号を切り変える
//        if (GetInputChar(TRUE) == ' ')
//        {
//            // プレイヤーの位置を初期化
//            PlayerX = 1;
//            PlayerY = 1;
//
//            // 停止中フラグも倒す
//            Move = 0;
//
//            // マップ番号を加算
//            MapNo++;
//            if (MapNo == MAP_NUM)
//            {
//                MapNo = 0;
//            }
//        }
//
//        // 移動中ではない場合キー入力を受け付ける
//        if (Move == 0)
//        {
//            // キー入力を得る
//            Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//
//            // キー入力に応じてプレイヤーの座標を移動
//            if (Key & PAD_INPUT_LEFT)
//            {
//                Move = 1;
//                MoveX = -1;
//                MoveY = 0;
//            }
//            if (Key & PAD_INPUT_RIGHT)
//            {
//                Move = 1;
//                MoveX = 1;
//                MoveY = 0;
//            }
//            if (Key & PAD_INPUT_UP)
//            {
//                Move = 1;
//                MoveX = 0;
//                MoveY = -1;
//            }
//            if (Key & PAD_INPUT_DOWN)
//            {
//                Move = 1;
//                MoveX = 0;
//                MoveY = 1;
//            }
//
//            // 進入不可能なマップだった場合は移動できない
//            if (Move == 1)
//            {
//                if (MapData[MapNo].Data[PlayerY + MoveY][PlayerX + MoveX] == 0)
//                {
//                    Move = 0;
//                }
//                else
//                {
//                    MoveCounter = 0;
//                }
//            }
//
//            // 停止中は画面のスクロールは行わない
//            ScrollX = 0;
//            ScrollY = 0;
//        }
//
//        // 移動中の場合は移動処理を行う
//        if (Move == 1)
//        {
//            MoveCounter++;
//
//            // 移動処理が終了したら停止中にする
//            if (MoveCounter == MOVE_FRAME)
//            {
//                Move = 0;
//
//                // プレイヤーの位置を変更する
//                PlayerX += MoveX;
//                PlayerY += MoveY;
//
//                // 停止中は画面のスクロールは行わない
//                ScrollX = 0;
//                ScrollY = 0;
//            }
//            else
//            {
//                // 経過時間からスクロール量を算出する
//                ScrollX = -(MoveX * MAP_SIZE * MoveCounter / MOVE_FRAME);
//                ScrollY = -(MoveY * MAP_SIZE * MoveCounter / MOVE_FRAME);
//            }
//        }
//
//        // マップとプレイヤーを描画
//        GraphDraw(ScrollX, ScrollY);
//
//        // 裏画面の内容を表画面に映す
//        ScreenFlip();
//    }
//
//    DxLib_End();               // ＤＸライブラリ使用の終了処理
//
//    return 0;                  // ソフトの終了
//}
//
//

#include "DxLib.h"
#include <fstream>

#define PI	3.1415926535897932384626433832795f

// グローバル変数>_<
int gPacman[10];			// パックマンのグラフィックハンドル
int gMapChip[10];			// マップチップのハンドル
int gMap[30][32];			// マップデータ

// 画像の読み込み
int LoadData()
{
	// 画像の読み込み
	if (LoadDivGraph("pacman.bmp", 10, 10, 1, 48, 48, gPacman) == -1) {
		MessageBox(NULL, "pacman.bmp", "ReadError", MB_OK);
		return -1;
	}
	if (LoadDivGraph("mapchip1.bmp", 5, 5, 1, 16, 16, gMapChip) == -1) {
		MessageBox(NULL, "mapchip1.bmp", "ReadError", MB_OK);
		return -1;
	}

	return 0;
}

// マップの読み込み
int MapInit()
{
	int FileHandle = FileRead_open("StageData.txt");		// ファイルのオープン
	int FileSize = FileRead_size("StageData.txt");			// ファイルサイズを取得して
	char* FileImage = new char[FileSize];					// その大きさだけ領域確保
	FileRead_read(FileImage, FileSize, FileHandle);			// 一気読み
	FileRead_close(FileHandle);								// ファイルを閉じて終了

	const char* d = FileImage;
	int sx = 0, sy = 0;
	int o;

	while (*d != '\0') { // NULL文字（終端）ではない間
		switch (*d) {
		case ' ':	o = 0; break;
		case 'o':	o = 1; break;
		case '@':	o = 2; break;
		case '#':	o = 3; break;
		case '=':	o = 4; break;
		case '\n':
			sy++;		// 一行下へ、左端へ
			sx = 0;		// throw down
		default:	o = 5; break;
		}
		d++;
		if (o != 5) {
			gMap[sy][sx] = o;	// マップ情報書き込み
			sx++;
		}
	}
	return 0;
}

// 初期化
int Init()
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;

	SetDrawScreen(DX_SCREEN_BACK);		// 裏画面に書き込みますよ宣言

	if (LoadData() == -1) {
		DxLib_End();
		return -1;
	}
	MapInit();
	return 0;
}
int MapSet()
{
	int sx, sy, st;
	int dot = 0;

	for (sy = 0; sy < 30; sy++) {
		for (sx = 0; sx < 32; sx++) {
			st = gMap[sy][sx];
			DrawGraph(sx * 16, sy * 16, gMapChip[st], TRUE);
			if (st == 1 || st == 2) dot++;
		}
	}
	if (dot == 0) {		// 食べるものが残ってなければ
//		ClearEvent();	// クリアですよ、えらいねえ頑張ったねえ
		return -1;
	}
	return 0;
}

// メインループ
void MainLoop()
{
	int key;
	int s = 0;
	int x = 200, y = 200;
	int dx = -4, dy = 0;
	float Angle = 0.0f;	// 初期　左向き
	while (ProcessMessage() == 0) {
		ClsDrawScreen();
		if (MapSet() == -1)return;
		key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if (key & PAD_INPUT_START) break;		// PAD_INPUT_START  [ESC]Key

		if (x <= 0 + 48 || x >= 640 - 48 || y <= 0 + 48 || y >= 480 - 48) {	// 画面の端っこのほう確認
															// 端っこ近くではキー入力受け付けない
			if (x <= 0 + 24 || x >= 640 - 24 || y <= 0 + 24 || y >= 480 - 24) {	// 画面の端確認
				dx *= -1;
				dy *= -1;									// 端だったら方向転換
				Angle += PI;								// 進行方向にPI(180度)加算する
				if (Angle > 2 * PI) Angle -= 2 * PI;				// 360度以上なら360度引く。
			}												// 下方向は270度でも-90度でも両方対応してるので、そのルーズさに甘える。
		}
		else {
			if (key & PAD_INPUT_UP) { dx = 0; dy = -4; Angle = PI / 2; }
			if (key & PAD_INPUT_DOWN) { dx = 0; dy = 4; Angle = -PI / 2; }
			if (key & PAD_INPUT_LEFT) { dx = -4; dy = 0; Angle = 0; }
			if (key & PAD_INPUT_RIGHT) { dx = 4; dy = 0; Angle = PI; }
		}
		x += dx;
		y += dy;
		s = (++s) % 7;

		DrawRotaGraph(x, y, 1, Angle, gPacman[s], TRUE);
		ScreenFlip();
	}
	return;
}

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	if (Init()) return -1;	// 初期化

	MainLoop();				// メインルーチン

	DxLib_End();			// あとしまつ
	return 0;
}