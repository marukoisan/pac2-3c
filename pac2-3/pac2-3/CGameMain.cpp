#include"DxLib.h"
#include "CGameMain.h"
#include"CPlayer.h"
#include"CHitPoint.h"


//-------------------
// �R���X�g���N�^
//-------------------
CGameMain::CGameMain()
{
	player = new CPlayer;
	hitPoint = new CHitPoint;
}

//-------------------
// �f�X�g���N�^
//-------------------
CGameMain::~CGameMain()
{
	delete player;
	delete hitPoint;
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
	hitPoint->Draw();
		player->Draw();
		DrawFormatString(0, 0, 0xffffff, "%d", saveData);
}