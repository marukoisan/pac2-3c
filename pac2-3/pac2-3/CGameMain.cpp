#include"DxLib.h"
#include "CGameMain.h"
#include"CPlayer.h"


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
	
	player->Update();
	return this;
}

//-------------------
// 描画
//-------------------
void CGameMain::Draw()const
{
		player->Draw();
		DrawFormatString(0, 0, 0xffffff, "%d", saveData);
}