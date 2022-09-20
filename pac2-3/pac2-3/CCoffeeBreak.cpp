#include"DxLib.h"
#include"CCoffeeBreak.h"

//--------------------
// コンストラクタ
//--------------------
CCoffeeBreak::CCoffeeBreak()
{
	LoadImages();

	anim = FALSE;
	anim2 = FALSE;

	pacmanX = 930.0;
	bigPacmanX = 230.0;
	akabeiX = 990.0;
	izikeX = 360.0;

	pacmanSpeed = 0;
	bigPacmanSpeed = 0;
	akabeiSpeed = 0;
	izikeSpeed = 0;

	Timer = 480;
}

//--------------------
// 更新
//--------------------
void CCoffeeBreak::Update() 
{
	static int animTimer = 0;
	animTimer++;//アカベイの処理
	animepacman++;//パックマン用の処理

	pacmanSpeed = 540.0 / 195;
	bigPacmanSpeed = 540.0 / 160;
	akabeiSpeed = 540.0 / 182;
	izikeSpeed = 540.0 / 182;

	--Timer;

	pacmanX = pacmanX - pacmanSpeed;
	

	akabeiX = akabeiX - akabeiSpeed;
	

	if (Timer < 230)
	{
		izikeX = izikeX + izikeSpeed;
	}

	if (Timer < 210)
	{
		bigPacmanX = bigPacmanX + bigPacmanSpeed;
	}


	if (animTimer % 4 == 0)//8はフレーム数　通常パックマン : 通常アカベイ
	{
		anim =! anim;
	}
	if (animTimer % 6 == 0)//でかいパックマン用
	{
		anim2 =! anim2;
	}
}

//--------------------
// 描画
//--------------------
void CCoffeeBreak::Draw() const
{

	if (Timer < 480)
	{
		 
		DrawRotaGraphF(pacmanX,360, 1.0 / 32 * 32 ,0,pacman[animepacman / 3 % 3 + 11],TRUE);

		DrawRotaGraphF(akabeiX, 360, 1.0 / 17 * 32, 0, akabei[anim], TRUE);
		
	}

	if (Timer < 230)
	{
		DrawRotaGraphF(izikeX, 360, 1.0 / 14 * 27, 0, izike[anim], TRUE);
	}

	if (Timer < 210)
	{
		DrawRotaGraphF(bigPacmanX, 360, 1.0 / 32 * 60, 0, bigpacman[animepacman / 3 % 3 + 2], TRUE);
	}


	DrawBox(0, 0, 369, 720, 0x00ff00, TRUE);
	DrawBox(930, 0, 1380, 720, 0x00ff00, TRUE);


}

void CCoffeeBreak::LoadImages()
{
	LoadDivGraph("images/akabei.png", ENEMY_IMAGE_MAX, 2, 1, 14, 14, akabei);
	
	LoadDivGraph("images/sprites/pacman.png", PACMAN_IMAGE_MAX,
		12, 1, 32, 32, pacman);
 
	LoadDivGraph("images/pacman_bigpicture.png", BIGPACMAN_IMAGE_MAX,
		3, 1, 32, 32, bigpacman);

	LoadDivGraph("images/izike.png", ENEMY_IZIKE_MAX, 2, 1, 14, 14, izike);

}