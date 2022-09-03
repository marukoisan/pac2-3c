#include"DxLib.h"
#include "CController.h"

//------------------
// コンストラクタ　
//------------------
CController::CController()
{
	this->inputInterval = 15;
}


//---------------------------------------------------------------
// コンストラクタ　引数 1 で設定したフレーム数毎に入力を取得する
//---------------------------------------------------------------
CController::CController(int inputInterval)
{
	this->inputInterval = inputInterval;
}

//----------------------
// デストラクタ
//----------------------
CController::~CController()
{

}

//------------------------
// 更新
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