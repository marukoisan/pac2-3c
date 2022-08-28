#include"DxLib.h"
#include"CAbstractEnemy.h"

//---------------------------
// コンストラクタ
//---------------------------
CAbstractEnemy::CAbstractEnemy()
{
	LoadDivGraph("images/testNum.png", 10, 10, 1, 20, 20, testNums);
}

//---------------------------
// デストラクタ
//---------------------------
CAbstractEnemy::~CAbstractEnemy()
{

}

//----------------------------
// 描画
//----------------------------
void CAbstractEnemy::Draw()const
{
	for (int i = 0; i < D_FIELD_HEIGHT; i++)
	{
		for (int j = 0; j < D_FIELD_WIDTH; j++)
		{
			if (floor[i][j] > 0)
			{
				DrawRotaGraphF(/* x */D_FIELD_POS_X + j * D_TILE_SIZE, /* y */D_FIELD_POS_Y + i * D_TILE_SIZE,
					/* 拡大率 */1.0 , 0, testNums[floor[i][j]], TRUE);
			}

		}
	}
}