#include"DxLib.h"
#include "CGameMain.h"

#include"CField.h"
#include"CEsa.h"

//-------------------
// コンストラクタ
//-------------------
CGameMain::CGameMain()
{
	field = new CField();
	esa = new CEsa();
	esa->Init();
}

//-------------------
// デストラクタ
//-------------------
CGameMain::~CGameMain()
{
	delete field;
	delete esa;
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
	esa->Draw();
	DrawFormatString(0, 0, 0xffffff, "%d", saveData);
}