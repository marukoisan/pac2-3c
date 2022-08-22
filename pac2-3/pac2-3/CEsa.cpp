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

void CEsa::Init()
{
	//座標
	x = 0.0;
	y = 0.0;
	//縦横
	height = 0.0;
	width = 0.0;
}

int CEsa::LoadesaImage()
{

}