#include"DxLib.h"
#include "CField.h"

//------------------------------
// コンストラクタ
//------------------------------
CField::CField() {
	if ((LoadImages()) == -1) 
	{
		;//error
	}
}

//-------------------------------
// デストラクタ
//-------------------------------
CField::~CField() {
	;
}

//-------------------------------
// 描画
//-------------------------------
void CField::Draw()const {
	DrawRotaGraphF(640, 360, 1.0 / 100.0 * D_TILE_SIZE, 0, testTiles[0], TRUE);
	DrawRotaGraphF(660, 360, 1.0 / 100.0 * D_TILE_SIZE, 0, testTiles[1], TRUE);
	DrawRotaGraphF(640, 380, 1.0 / 100.0 * D_TILE_SIZE, 0, testTiles[2], TRUE);
	DrawRotaGraphF(660, 380, 1.0 / 100.0 * D_TILE_SIZE, 0, testTiles[3], TRUE);
}

//-------------------------------
// 
//-------------------------------

//-------------------------------
// 
//-------------------------------

//-------------------------------
// 画像の読み込み
//-------------------------------
bool CField::LoadImages() {
	testTiles[0] = LoadGraph("images/tiles/corner_top_left.png");
	testTiles[1] = LoadGraph("images/tiles/corner_top_right.png");
	testTiles[2] = LoadGraph("images/tiles/corner_bottom_left.png");
	testTiles[3] = LoadGraph("images/tiles/corner_bottom_right.png");
	testTiles[3] = LoadGraph("images/tiles/outercorner_top_left.png");
	testTiles[3] = LoadGraph("images/tiles/outercorner_top_right.png");
	testTiles[3] = LoadGraph("images/tiles/outercorner_bottom_left.png");
	testTiles[3] = LoadGraph("images/tiles/outercorner_bottom_right.png");
	testTiles[3] = LoadGraph("images/tiles/outercorner_narrow_top_left.png");
	testTiles[3] = LoadGraph("images/tiles/outercorner_narrow_top_right.png");
	testTiles[3] = LoadGraph("images/tiles/outercorner_narrow_bottom_left.png");
	testTiles[3] = LoadGraph("images/tiles/outercorner_narrow_bottom_right.png");
	testTiles[] = LoadGraph("images/tiles/outernose_top_right.png");//left
	testTiles[] = LoadGraph("images/tiles/outernose_top_left.png");//right
	testTiles[] = LoadGraph("images/tiles/.png");
	testTiles[] = LoadGraph("images/tiles/.png");
	testTiles[] = LoadGraph("images/tiles/.png");
	testTiles[] = LoadGraph("images/tiles/.png");
	testTiles[] = LoadGraph("images/tiles/.png");
	testTiles[] = LoadGraph("images/tiles/.png");
	testTiles[] = LoadGraph("images/tiles/.png");
}