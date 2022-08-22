#include"DxLib.h"
#include"CEsa.h"

CEsa::CEsa()//コンストラクタ
{
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

void CEsa::Update()//更新
{

}

void CEsa::Draw() const//
{
	DrawRotaGraphF(460,360,)
}

void CEsa::Init()
{
	//座標
	x = 0.0;
	y = 0.0;
	//縦横
	height = 20.0;
	width = 20.0;
}

int CEsa::LoadesaImage()
{
	esa = LoadGraph("images/tiles/dot.png");
	Bigesa = LoadGraph("images/tiles/big_dot.png");
}