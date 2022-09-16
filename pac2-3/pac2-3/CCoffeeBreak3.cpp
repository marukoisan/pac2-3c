#include "CCoffeeBreak3.h"
#include"define.h"

CCoffeeBreak3::CCoffeeBreak3()
{
	LoadImages();
	anim = false;
	anime = false;
	animpacman = 0;
	x = 0;
	y = 0;
}


CCoffeeBreak3::~CCoffeeBreak3()
{

}

void CCoffeeBreak3::Update()
{
	// アニメーション制御用変数の更新
	static int animTimer = 0;
	animTimer++;//つぎはぎくんといもむしくん用の処理
	animpacman++;//パックマン用の処理

	x++;
	y--;
	if (animTimer % 3 == 0)//8はフレーム数
	{
		anim = !anim;
	}
	if (animTimer % 5 == 0)
	{
		anime = !anime;
	}
}

void CCoffeeBreak3::Draw() const
{
	/*DrawGraph(200, 200, tugihagi[0], TRUE);
	DrawGraph(200, 250, tugihagi[1], TRUE);*/

	//つぎはぎくんの描画
	DrawRotaGraphF(TUGIHAGI_POSX + y, D_FIELD_POS_Y,
		1.0 / 14 * 32, 0, tugihagi[anim], TRUE);

	//いもむしくんの描画
	DrawRotaGraphF(D_FIELD_POS_X + x, D_FIELD_POS_Y + 30,
		1.0 / 22 * 32, 0, imomusi[anime], TRUE);

	/*DrawGraph(200, 300, imomusi[0], TRUE);
	DrawGraph(200, 350, imomusi[1], TRUE);*/

	//パックマン用の描画
	DrawRotaGraphF(PACMAN_POSX + y, D_FIELD_POS_Y + 60,
		1.0, 0, pacman[animpacman / 3 % 3 + 9], TRUE);

	/*DrawGraph(200, 370, pacman[9 + 0 % 3], TRUE);
	DrawGraph(200, 400, pacman[9 + 1 % 3], TRUE);
	DrawGraph(200, 430, pacman[9 + 2 % 3], TRUE);*/

	DrawBox(0, 0, 369, 720, 0x0000ff, TRUE);
	DrawBox(910, 0, 1280, 720, 0x00ff00, TRUE);

	DrawFormatString(200, 460, 0xFFFFFF, "%d", (int)anim);
}

void CCoffeeBreak3::LoadImages()
{
	LoadDivGraph("images/tugihagi1.png",TUGIHAGI_MAX,2,1,14,14,tugihagi);
	LoadDivGraph("images/imomusi1.png",IMOMUSI_MAX,1,2,20,10,imomusi);
	LoadDivGraph("images/sprites/pacman.png", PACMAN_MAX, 12, 1, 32, 32, pacman);
}