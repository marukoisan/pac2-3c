#include"DxLib.h"
#include "CGameMain.h"
#include"CEnemy.h"

//-------------------
// �R���X�g���N�^
//-------------------
CGameMain::CGameMain()
{
	enemy = new CEnemy;//�Z�b�g
	enemy->Init();//����������
}

//-------------------
// �f�X�g���N�^
//-------------------
CGameMain::~CGameMain()
{
	delete enemy;//�Z�b�g
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
	enemy->Draw();//�`��֐�
	DrawFormatString(100, 100, 0xffffff, "%d", saveData);
}