#include"DxLib.h"
#include"CEsa.h"

CEsa::CEsa()//コンストラクタ
{
	LoadesaImage();
	 esa = 0;
	 Bigesa = 0;

	//座標
	 x = 0.0;
	 y = 0.0;
	//縦横
	 height = 0.0;
	 width = 0.0;


}

CEsa::~CEsa()//デストラクタ
{
	;
}

//void CEsa::Update()//更新
//{
//
//}

void CEsa::Draw() const//
{
	DrawRotaGraphF(x, y, 1.0 / ESA_IMAGE_ORIGINNL * ESA_IMAGE_NEWLY, 0,esa,TRUE); 
	DrawRotaGraphF(x, y+32, 1.0 / ESA_IMAGE_ORIGINNL * ESA_IMAGE_NEWLY, 0,Bigesa,TRUE); 
}

void CEsa::Init()
{
	//座標
	x = 550.0;
	y = 360.0;
	//縦横
	height = 20.0;
	width = 20.0;
}

void CEsa::LoadesaImage()
{
	esa = LoadGraph("images/tiles/dot.png");
	Bigesa = LoadGraph("images/tiles/big_dot.png");
}