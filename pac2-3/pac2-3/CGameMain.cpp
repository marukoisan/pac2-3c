#include"DxLib.h"
#include "CGameMain.h"

#include"CField.h"

//-------------------
// �R���X�g���N�^
//-------------------
CGameMain::CGameMain()
{
	field = new CField();
}

//-------------------
// �f�X�g���N�^
//-------------------
CGameMain::~CGameMain()
{
	delete field;
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
	DrawFormatString(0, 0, 0xffffff, "%d", saveData);
}