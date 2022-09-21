#include"DxLib.h"
#include"CEsa.h"

int CEsa::esaCount;

CEsa::CEsa()//コンストラクタ
{
	//esa = 0;
	//Bigesa = 0;
   //esaFlg = 0; //エサのフラグ
	EsaImage = 0;
	esaType = 0;  //エサ画像の判別
	esaFlg = true;  //エサの表示フラグ
	esaScore = 0;  //エサのスコア
	esaTime = 0;   //エサの点滅させるため用の時間変数
	esaIsShow = true; //エサの描画フラグ



	height = 3;
	width = 3;

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
	if (esaIsShow)
	{
		DrawRotaGraphF(D_FIELD_POS_X + x,D_FIELD_POS_Y + y, 1.0 / ESA_IMAGE_ORIGINNL * ESA_IMAGE_NEWLY, 0, EsaImage[esaType], TRUE);
	}
}

void CEsa::HitAction()
	{ 
		esaFlg = false;
		PlaySoundMem(esaSound[esaCount % 2 ], DX_PLAYTYPE_BACK);
		esaCount++;
	}

void CEsa::Init(float x, float y,int *EsaImage, bool esaType, int esaScore, int* esaSound)
{
	this->x = x;  //座標
	this->y = y;  //座標
	this->EsaImage = EsaImage;   //エサの画像
	this->esaType = esaType;  //エサ画像の判別
	this->esaScore = esaScore; //エサのスコア
	this->esaSound = esaSound;

}



void CEsa::ImageBlinking(void)
{
	esaTime++;
	if (esaType == 1)
	{
		if (esaTime % 15 == 0)//2秒間に一回って処理
		{
			toggle();
		}
		
	}
	
}



void CEsa::LoadSounds()
{
	/*esa = LoadGraph("images/tiles/dot.png");
	Bigesa = LoadGraph("images/tiles/big_dot.png");*/

	//esaImages[0] = LoadGraph("images/tiles/dot.png");
	//esaImages[1] = LoadGraph("images/tiles/big_dot.png");
}