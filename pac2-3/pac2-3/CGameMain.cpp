#include"DxLib.h"
#include "CGameMain.h"
#include"CPlayer.h"


//-------------------
// �R���X�g���N�^
//-------------------
CGameMain::CGameMain()
{
	player = new CPlayer;
}

//-------------------
// �f�X�g���N�^
//-------------------
CGameMain::~CGameMain()
{
	delete player;
}

//-------------------
// �X�V
//-------------------
CAbstractScene* CGameMain::Update()
{
	
	player->Update();
	return this;
}

//-------------------
// �`��
//-------------------
void CGameMain::Draw()const
{
		player->Draw();
		DrawFormatString(0, 0, 0xffffff, "%d", saveData);
}