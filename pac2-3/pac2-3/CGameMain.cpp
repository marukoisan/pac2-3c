#include"DxLib.h"
#include "CGameMain.h"

#include"CField.h"
#include"CEsa.h"

//-------------------
// �R���X�g���N�^
//-------------------
CGameMain::CGameMain()
{
	field = new CField();
	esa = new CEsa();
	esa->Init();
}

//-------------------
// �f�X�g���N�^
//-------------------
CGameMain::~CGameMain()
{
	delete field;
	delete esa;
}

//-------------------
// �X�V
//-------------------
CAbstractScene* CGameMain::Update()
{
	field->Update();
	
	return this;
}

//-------------------
// �`��
//-------------------
void CGameMain::Draw()const
{
	field->Draw();
	esa->Draw();
	DrawFormatString(0, 0, 0xffffff, "%d", saveData);
}