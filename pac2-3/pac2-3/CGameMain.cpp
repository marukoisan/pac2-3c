#include"DxLib.h"
#include "CGameMain.h"

//-------------------
// コンストラクタ
//-------------------
CGameMain::CGameMain()
{
	;
}

//-------------------
// デストラクタ
//-------------------
CGameMain::~CGameMain()
{
	;
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
	DrawFormatString(0, 0, 0xffffff, "%d", saveData);
}