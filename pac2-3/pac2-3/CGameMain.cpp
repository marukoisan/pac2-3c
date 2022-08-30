#include"DxLib.h"
#include "CGameMain.h"
#include"CPlayer.h"
#include"CHitPoint.h"


//-------------------
// コンストラクタ
//-------------------
CGameMain::CGameMain()
{
	player = new CPlayer;
	hitPoint = new CHitPoint;
}

//-------------------
// デストラクタ
//-------------------
CGameMain::~CGameMain()
{
	delete player;
	delete hitPoint;
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
	hitPoint->Draw();
		player->Draw();
		DrawFormatString(0, 0, 0xffffff, "%d", saveData);
}