#include"DxLib.h"
#include "CGameMain.h"
#include"CPlayer.h"

int old;
int now;
int keyFlg;

//-------------------
// コンストラクタ
//-------------------
CGameMain::CGameMain()
{
	player = new CPlayer;
}

//-------------------
// デストラクタ
//-------------------
CGameMain::~CGameMain()
{
	delete player;
}

//-------------------
// 更新
//-------------------
CAbstractScene* CGameMain::Update()
{
	old = now;
	now = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	keyFlg = now & ~old;

	if (keyFlg == PAD_INPUT_1)testisLoop = !testisLoop;
	player->Update();
	return this;
}

//-------------------
// 描画
//-------------------
void CGameMain::Draw()const
{
	if (testisLoop)
	{
		player->Draw();
		DrawFormatString(0, 0, 0xffffff, "%d", saveData);
	}
}