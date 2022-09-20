#include<stdio.h>
#include"DxLib.h"
#include "CTitle.h"
#include"CGameMain.h"

//----------------------------
// コンストラクタ
//----------------------------
CTitle::CTitle()
{
	charactar_strImage = LoadGraph("images/character_str.png");
}

//---------------------
// 更新
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
// 描画
//---------------------
void CTitle::Draw()const
{
	DrawGraph(D_TITLE_POS_X + 140, 100, charactar_strImage, TRUE);
	DrawFormatString(0, 0, 0xffffff, "%d", saveData);
}