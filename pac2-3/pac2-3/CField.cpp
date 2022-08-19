#include"DxLib.h"
#include "CField.h"

//------------------------------
// �R���X�g���N�^
//------------------------------
CField::CField() {
	testTiles[0] = LoadGraph("images/tiles/corner_top_left.png");
	testTiles[1] = LoadGraph("images/tiles/corner_top_right.png");
	testTiles[2] = LoadGraph("images/tiles/corner_bottom_left.png");
	testTiles[3] = LoadGraph("images/tiles/corner_bottom_right.png");
}

//-------------------------------
// �f�X�g���N�^
//-------------------------------
CField::~CField() {
	;
}

//-------------------------------
// �`��
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
// 
//-------------------------------