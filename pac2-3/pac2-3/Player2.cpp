#include "DxLib.h"
#include "Player2.h"

Player2::Player2()
{


	if (LoadDivGraph("images/sprites/pacman.png", 12, 12, 1, 32, 32, gPacman) == -1);
}

Player2::~Player2()
{
	;
}

void Player2::Draw() const
{

}

//// 画像の読み込み
//int Player2::LoadImages()
//{
//	// 画像の読み込み
//	if (LoadDivGraph("images/sprites/pacman.png", 12, 12, 1, 32, 32, gPacman) == -1) {
//		//MessageBox(NULL, "pacman.bmp", "ReadError", MB_OK);
//		return -1;
//	}
//	//if (LoadDivGraph("mapchip1.bmp", 5, 5, 1, 16, 16, gMapChip) == -1) {
//	//	/*MessageBox(NULL, "mapchip1.bmp", "ReadError", MB_OK);*/
//	//	return -1;
//	//}
//
//	return 0;
//}

//マップの読み込み
//int MapInit()
//{
//	int FileHandle = FileRead_open("StageData.txt");		// ファイルのオープン
//	int FileSize = FileRead_size("StageData.txt");			// ファイルサイズを取得して
//	char* FileImage = new char[FileSize];					// その大きさだけ領域確保
//	FileRead_read(FileImage, FileSize, FileHandle);			// 一気読み
//	FileRead_close(FileHandle);								// ファイルを閉じて終了
//
//	const char* d = FileImage;
//	int sx = 0, sy = 0;
//	int o;
//
//	while (*d != '\0') { // NULL文字（終端）ではない間
//		switch (*d) {
//		case ' ':	o = 0; break;
//		case 'o':	o = 1; break;
//		case '@':	o = 2; break;
//		case '#':	o = 3; break;
//		case '=':	o = 4; break;
//		case '\n':
//			sy++;		// 一行下へ、左端へ
//			sx = 0;		// throw down
//		default:	o = 5; break;
//		}
//		d++;
//		if (o != 5) {
//			gMap[sy][sx] = o;	// マップ情報書き込み
//			sx++;
//		}
//	}
//	return 0;
//}

// 初期化
int Player2::Init()
{
//	ChangeWindowMode(TRUE);
//	if (DxLib_Init() == -1) return -1;
//
//	SetDrawScreen(DX_SCREEN_BACK);		// 裏画面に書き込みますよ宣言
//
//	if (LoadImages() == -1) {
//		DxLib_End();
//		return -1;
//	}
//	//MapInit();
//
//	// ゲームの設定
//	/*gScore = 0;*/
//	return 0;
}

//void ClearEvent()
//{
//	MessageBox(NULL, "おめでたう", "Congratulation", MB_OK);
//	return;
//}
// マップ配置（毎フレーム描画）



