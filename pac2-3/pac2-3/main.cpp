#include"DxLib.h"
#include"Player2.h"
//変数の宣言
//int g_LoopCount = 0;
//プログラムの開始
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
{
	//ウィンドウモードで起動する
	ChangeWindowMode(TRUE);
	SetGraphMode(1280, 720, 32);
 
	//DXライブラリの初期化処理:エラーが起きたら直ちに終了
	if (DxLib_Init() == -1)return-1;
 
	//描画先画面を裏にする
	SetDrawScreen(DX_SCREEN_BACK);
 
	//ゲームループ
	while (ProcessMessage() == 0)
	{
		//画面の初期化
		ClearDrawScreen();
		
		player2.Init();
		player2.LoadImages();
		player2.PlayerMove();

		////ループカウンタの表示
		//DrawFormatString(0, 0, GetColor(255, 128, 0), "LoopCount=%d", g_LoopCount++);
 
		//裏画面の内容を表画面に反映
		ScreenFlip();
	}
	//DXライブラリ使用の終了処理
	DxLib_End();
	//ソフトの終了
	return 0;

}

