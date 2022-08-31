#include"DxLib.h"
#include"CEsa.h"

CEsa::CEsa()//コンストラクタ
{
	
	 //esa = 0;
	 //Bigesa = 0;
	//esaFlg = 0; //エサのフラグ
	EsaImage = 0; 
	 esaType = 0;  //エサ画像の判別
	 esaFlg = true;  //エサの表示フラグ
	 esaScore = 0;  //エサのスコア
	

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
	DrawRotaGraphF(x, y, 1.0 / ESA_IMAGE_ORIGINNL * ESA_IMAGE_NEWLY, 0, EsaImage[esaType], TRUE);
}

void CEsa::Init(float x, float y,int *EsaImage, bool esaType)
{
	this->x = x;  //座標
	this->y = y;  //座標
	this->EsaImage = EsaImage;   //エサの画像
	this->esaType = esaType;  //エサ画像の判別

}

void CEsa::LoadesaImage()
{
	/*esa = LoadGraph("images/tiles/dot.png");
	Bigesa = LoadGraph("images/tiles/big_dot.png");*/

	//esaImages[0] = LoadGraph("images/tiles/dot.png");
	//esaImages[1] = LoadGraph("images/tiles/big_dot.png");
}