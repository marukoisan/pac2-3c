#include"DxLib.h"
#include"define.h"
#include "CTile.h"

//-----------------------------
// �R���X�g���N�^
//-----------------------------
CTile::CTile()
{
	image = 0;
	height = D_TILE_SIZE / 2;
	width = D_TILE_SIZE / 2;
}

//-----------------------------
// �f�X�g���N�^
//-----------------------------
CTile::~CTile()
{
	;
}

//-----------------------------
// �`��
//-----------------------------
void CTile::Draw()const
{
	DrawRotaGraphF(/* x */D_FIELD_POS_X + x, /* y */D_FIELD_POS_Y + y,
		/* �g�嗦 */1.0 / D_TILE_IMAGE_SIZE * D_TILE_SIZE, 0, image, TRUE);

}

//-----------------------------
// ������
//-----------------------------
void CTile::Init(float x,float y,int image)
{
	this->x = x;
	this->y = y;
	this->image = image;
}
