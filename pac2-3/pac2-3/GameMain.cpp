#include "AbstractScene.h"
#include "GameMain.h"

//------------------------
// �R���X�g���N�^
//------------------------
GameMain::GameMain() 
{

}

//------------------------
// �f�X�g���N�^
//------------------------
GameMain::~GameMain() 
{

}

//-------------------------------
// �V�[���̍X�V
//-------------------------------
AbstractScene* GameMain::Update() 
{
	return this;
}

//------------------------------
// �`��
//------------------------------
void GameMain::Draw()const
{

}
