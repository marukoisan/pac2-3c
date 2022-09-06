#include"DxLib.h"
#include "CController.h"

//------------------
// �R���X�g���N�^�@
//------------------
CController::CController()
{
	this->inputInterval = 15;
}


//---------------------------------------------------------------
// �R���X�g���N�^�@���� 1 �Őݒ肵���t���[�������ɓ��͂��擾����
//---------------------------------------------------------------
CController::CController(int inputInterval)
{
	this->inputInterval = inputInterval;
}

//----------------------
// �f�X�g���N�^
//----------------------
CController::~CController()
{

}

//------------------------
// �X�V
//------------------------
void CController::Update()
{
	XINPUT_STATE oldKey = inputKey;
	GetJoypadXInputState(DX_INPUT_PAD1, &inputKey);
	keyState = inputKey;
	for (int i = 0; i <= XINPUT_BUTTON_Y; i++)
	{
		keyState.Buttons[i] = inputKey.Buttons[i] & ~oldKey.Buttons[i];
	}
}