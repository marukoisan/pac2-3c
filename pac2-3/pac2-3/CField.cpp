#include"DxLib.h"
#include "CField.h"


//------------------------------
// コンストラクタ
//------------------------------
CField::CField() {
	LoadImages();

	for (int i = 0; i < D_FIELD_HEIGHT; i++)
	{
		for (int j = 0; j < D_FIELD_WIDTH; j++)
		{
			tile[i][j].
				Init(j * D_TILE_SIZE, i * D_TILE_SIZE,
					tileImages[FIELD_DATA[i][j]]);
		}
	}
}

//-------------------------------
// デストラクタ
//-------------------------------
CField::~CField() 
{
	;
}


//-------------------------------
// 描画
//-------------------------------
void CField::Draw()const 
{
	for (int i = 0; i < D_FIELD_HEIGHT; i++)
	{
		for (int j = 0; j < D_FIELD_WIDTH; j++)
		{
			tile[i][j].Draw();
		}
	}
}

//-------------------------------
// 画像の読み込み
//-------------------------------
void CField::LoadImages()
{
	//カーブ一本
	tileImages[0] = LoadGraph("images/tiles/corner_top_left.png");
	tileImages[1] = LoadGraph("images/tiles/corner_top_right.png");
	tileImages[2] = LoadGraph("images/tiles/corner_bottom_left.png");
	tileImages[3] = LoadGraph("images/tiles/corner_bottom_right.png");

	//大きいカーブ二本
	tileImages[4] = LoadGraph("images/tiles/outercorner_top_left.png");
	tileImages[5] = LoadGraph("images/tiles/outercorner_top_right.png");
	tileImages[6] = LoadGraph("images/tiles/outercorner_bottom_left.png");
	tileImages[7] = LoadGraph("images/tiles/outercorner_bottom_right.png");

	//カーブ二本
	tileImages[8] = LoadGraph("images/tiles/outercorner_narrow_top_left.png");
	tileImages[9] = LoadGraph("images/tiles/outercorner_narrow_top_right.png");
	tileImages[10] = LoadGraph("images/tiles/outercorner_narrow_bottom_left.png");
	tileImages[11] = LoadGraph("images/tiles/outercorner_narrow_bottom_right.png");

	//上側の突起
	tileImages[12] = LoadGraph("images/tiles/outernose_top_left.png");
	tileImages[13] = LoadGraph("images/tiles/outernose_top_right.png");
	//左側の突起
	tileImages[14] = LoadGraph("images/tiles/outernose_left_top.png");
	tileImages[15] = LoadGraph("images/tiles/outernose_left_bottom.png");
	//右側の突起
	tileImages[16] = LoadGraph("images/tiles/outernose_right_top.png");
	tileImages[17] = LoadGraph("images/tiles/outernose_right_bottom.png");

	//横線二本（上壁、下壁）
	tileImages[18] = LoadGraph("images/tiles/outerwall_top.png");
	tileImages[19] = LoadGraph("images/tiles/outerwall_bottom.png");
	//縦線二本（左壁、右壁）
	tileImages[20] = LoadGraph("images/tiles/outerwall_left.png");
	tileImages[21] = LoadGraph("images/tiles/outerwall_right.png");

	//縦線壁
	tileImages[22] = LoadGraph("images/tiles/wall_warp.png");
	//横線壁
	tileImages[23] = LoadGraph("images/tiles/wall_side.png");

	//ゲート
	tileImages[24] = LoadGraph("images/tiles/gate_left.png");
	tileImages[25] = LoadGraph("images/tiles/gate_right.png");

	//床
	tileImages[26] = LoadGraph("images/tiles/floor.png");

	//ドア
	tileImages[27] = LoadGraph("images/tiles/door.png");
}