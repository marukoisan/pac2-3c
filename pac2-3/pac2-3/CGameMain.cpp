#include"DxLib.h"
#include "CGameMain.h"

//-------------------
// �R���X�g���N�^
//-------------------
CGameMain::CGameMain()
{
	;
}

//-------------------
// �f�X�g���N�^
//-------------------
CGameMain::~CGameMain()
{
	;
}

//-------------------
// �X�V
//-------------------
CAbstractScene* CGameMain::Update()
{
	return this;
}

//-------------------
// �`��
//-------------------
void CGameMain::Draw()const
{
	DrawFormatString(0, 0, 0xffffff, "%d", saveData);
}