#include"DxLib.h"
#include"CCoffeeBreak.h"
#include"define.h"
#include "CPlayer.h"

//--------------------
// 画像読み込み
//--------------------
void CCoffeeBreak::LoadImages()
{
	LoadDivGraph("images/sprites/pacman.png", D_PLAYER_IMAGE_MAX,
		3, 1, 32, 32, images);
}

//--------------------
// 描画
//--------------------
void CCoffeeBreak::CoffeeBreak()
{

}
- M_PI / 2