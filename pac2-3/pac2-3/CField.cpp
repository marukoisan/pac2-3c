#include"DxLib.h"
#include "CField.h"


//------------------------------
// �R���X�g���N�^
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
// �f�X�g���N�^
//-------------------------------
CField::~CField() 
{
	;
}


//-------------------------------
// �`��
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
// �摜�̓ǂݍ���
//-------------------------------
void CField::LoadImages()
{
	//�J�[�u��{
	tileImages[0] = LoadGraph("images/tiles/corner_top_left.png");
	tileImages[1] = LoadGraph("images/tiles/corner_top_right.png");
	tileImages[2] = LoadGraph("images/tiles/corner_bottom_left.png");
	tileImages[3] = LoadGraph("images/tiles/corner_bottom_right.png");

	//�傫���J�[�u��{
	tileImages[4] = LoadGraph("images/tiles/outercorner_top_left.png");
	tileImages[5] = LoadGraph("images/tiles/outercorner_top_right.png");
	tileImages[6] = LoadGraph("images/tiles/outercorner_bottom_left.png");
	tileImages[7] = LoadGraph("images/tiles/outercorner_bottom_right.png");

	//�J�[�u��{
	tileImages[8] = LoadGraph("images/tiles/outercorner_narrow_top_left.png");
	tileImages[9] = LoadGraph("images/tiles/outercorner_narrow_top_right.png");
	tileImages[10] = LoadGraph("images/tiles/outercorner_narrow_bottom_left.png");
	tileImages[11] = LoadGraph("images/tiles/outercorner_narrow_bottom_right.png");

	//�㑤�̓ˋN
	tileImages[12] = LoadGraph("images/tiles/outernose_top_left.png");
	tileImages[13] = LoadGraph("images/tiles/outernose_top_right.png");
	//�����̓ˋN
	tileImages[14] = LoadGraph("images/tiles/outernose_left_top.png");
	tileImages[15] = LoadGraph("images/tiles/outernose_left_bottom.png");
	//�E���̓ˋN
	tileImages[16] = LoadGraph("images/tiles/outernose_right_top.png");
	tileImages[17] = LoadGraph("images/tiles/outernose_right_bottom.png");

	//������{�i��ǁA���ǁj
	tileImages[18] = LoadGraph("images/tiles/outerwall_top.png");
	tileImages[19] = LoadGraph("images/tiles/outerwall_bottom.png");
	//�c����{�i���ǁA�E�ǁj
	tileImages[20] = LoadGraph("images/tiles/outerwall_left.png");
	tileImages[21] = LoadGraph("images/tiles/outerwall_right.png");

	//�c����
	tileImages[22] = LoadGraph("images/tiles/wall_warp.png");
	//������
	tileImages[23] = LoadGraph("images/tiles/wall_side.png");

	//�Q�[�g
	tileImages[24] = LoadGraph("images/tiles/gate_left.png");
	tileImages[25] = LoadGraph("images/tiles/gate_right.png");

	//��
	tileImages[26] = LoadGraph("images/tiles/floor.png");

	//�h�A
	tileImages[27] = LoadGraph("images/tiles/door.png");
}