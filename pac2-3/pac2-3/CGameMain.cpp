#include"DxLib.h"
#include "CGameMain.h"
#include"CEnemy.h"

//-------------------
// コンストラクタ
//-------------------
CGameMain::CGameMain()
{
	enemy = new CEnemy;//セット
	enemy->Init();//初期化処理
}

//-------------------
// デストラクタ
//-------------------
CGameMain::~CGameMain()
{
	delete enemy;//セット
}

//-------------------
// 更新
//-------------------
CAbstractScene* CGameMain::Update()
{
	return this;
}

//-------------------
// 描画
//-------------------
void CGameMain::Draw()const
{
	enemy->Draw();//描画関数
	DrawFormatString(100, 100, 0xffffff, "%d", saveData);
}