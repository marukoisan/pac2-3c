#include"DxLib.h"
#include"define.h"
#include "CTile.h"

//-----------------------------
// コンストラクタ
//-----------------------------
CTile::CTile()
{
	image = 0;
	height = D_TILE_SIZE / 2;
	width = D_TILE_SIZE / 2;
}

//-----------------------------
// デストラクタ
//-----------------------------
CTile::~CTile()
{
	;
}

//-----------------------------
// 描画
//-----------------------------
void CTile::Draw()const
{
	DrawRotaGraphF(/* x */D_FIELD_POS_X + x, /* y */D_FIELD_POS_Y + y,
		/* 拡大率 */1.0 / D_TILE_IMAGE_SIZE * D_TILE_SIZE, 0, image, TRUE);

}

//-----------------------------
// 初期化
//-----------------------------
void CTile::Init(float x,float y,int image)
{
	this->x = x;
	this->y = y;
	this->image = image;
}
