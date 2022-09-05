#include"DxLib.h"
#include"CEsaController.h"

CEsaController::CEsaController()//コンストラクタ
{
	LoadesaImage();
	
	esa = new CEsa[D_ESA_MAX];
	SetEsa();
	


	//esaFlg = 0; //エサのフラグ
	////座標
	//x = 0.0;
	//y = 0.0;
	
}

CEsaController::~CEsaController()//デストラクタ
{
	delete[] esa;//開放します
}

void CEsaController::Update()
{
	isClear = true;//clear判定を入れて、エサが一つでものこっていれば消す
	for (int i = 0; i < D_ESA_MAX; i++)
	{
		if (esa[i].GetFlg() == true)
		{
			isClear = false;
			esa[i].ImageBlinking();
		}
	}
}

void CEsaController::Draw() const
{
	for (int i = 0; i < D_ESA_MAX; i++)
	{
		if (esa[i].GetFlg() == true)
		{
			esa[i].Draw();
		}
	}
}

void CEsaController::Init()
{
	////初期化処理を書く

	//x = 550.0;
	//y = 360.0;
	////縦横
	//height = 20.0;
	//width = 20.0;
}

void CEsaController::LoadesaImage()
{
	esaImages[0] = LoadGraph("images/tiles/dot.png");
	esaImages[1] = LoadGraph("images/tiles/big_dot.png");
}

void CEsaController::SetEsa()
{
	int esaIndex = 0;

	for (int i = 0; i < ESA_FIELD_HEIGHT; i++)//縦
	{
		for (int j = 0; j < ESA_FIELD_WIDTH; j++)//横
		{
			if (ESA_DATA[i][j] == 0)
			{
				esa[esaIndex].Init(ESA_FIELD_POS_X + j * ESA_IMAGE_NEWLY, ESA_FIELD_POS_Y + i * ESA_IMAGE_NEWLY, esaImages, 0);
				if(esaIndex< D_ESA_MAX-1)esaIndex++;
			}
			else if (ESA_DATA[i][j] == 1)
			{
				esa[esaIndex].Init(ESA_FIELD_POS_X + j * ESA_IMAGE_NEWLY, ESA_FIELD_POS_Y + i * ESA_IMAGE_NEWLY, esaImages, 1);
				if (esaIndex < D_ESA_MAX-1)esaIndex++;
			}
		}
	}
}


