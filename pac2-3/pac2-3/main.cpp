#include"DxLib.h"
#include"CSceneManager.h"
#include"CTitle.h"
#include"CEnemy.h"

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
 
	//シーンマネージャーの確保
	CSceneManager* sceneManager;
	sceneManager = new CSceneManager(new CTitle);

	//ゲームループ
	while (ProcessMessage() == 0
			&& sceneManager->Update() != nullptr
			&& GetJoypadInputState(DX_INPUT_KEY_PAD1) != PAD_INPUT_9/*ESCキー*/)
	{
		//画面の初期化
		ClearDrawScreen();

		sceneManager->Draw();
 
		//裏画面の内容を表画面に反映
		ScreenFlip();
	}

	//シーンマネージャーの解放
	delete sceneManager;

	//DXライブラリ使用の終了処理
	DxLib_End();
	//ソフトの終了
	return 0;

}