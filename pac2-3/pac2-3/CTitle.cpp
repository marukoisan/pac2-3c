#include<stdio.h>
#include"DxLib.h"
#include "CTitle.h"
#include"CGameMain.h"

//---------------------
// çXêV
//---------------------
CAbstractScene* CTitle::Update()
{
	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) == PAD_INPUT_2)
	{
		saveData = 2;
	}
	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) == PAD_INPUT_3)
	{
		saveData = 3;
	}

	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) == PAD_INPUT_1)
	{
		return new CGameMain;
	}
	return this;
}

//---------------------
// ï`âÊ
//---------------------
void CTitle::Draw()const
{
	DrawFormatString(0, 0, 0xffffff, "%d", saveData);
}