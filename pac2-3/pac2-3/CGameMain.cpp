#include"DxLib.h"
#include "CGameMain.h"

#include"CField.h"

//-------------------
// コンストラクタ
//-------------------
CGameMain::CGameMain()
{
	field = new CField();
}

//-------------------
// デストラクタ
//-------------------
CGameMain::~CGameMain()
{
	delete field;
}

//-------------------
// 更新
//-------------------
CAbstractScene* CGameMain::Update()
{
	field->Update();
	return this;
}

//-------------------
// 描画
//-------------------
void CGameMain::Draw()const
{
	field->Draw();
	DrawFormatString(0, 0, 0xffffff, "%d", saveData);
}