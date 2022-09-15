#include<stdio.h>
#include"DxLib.h"
#include "CFruit.h"


CFruit::CFruit()//�R���X�g���N�^
{
	bool error = false;
	if (LoadDivGraph("images/sprites/fruit.png", FRUIT_MAX, 13, 1, 32, 32, FruitImage) == -1)error = true;

	FruitType = 0;  //�G�T�摜�̔���
	FruitFlg = true;  //�G�T�̕\���t���O
	FruitScore = 0;  //�G�T�̃X�R�A
	FruitTime = 0;   //�G�T�̓_�ł����邽�ߗp�̎��ԕϐ�
	FruitIsShow = true; //�G�T�̕`��t���O

	height = 3;
	width = 3;

}

void CFruit::Draw()const
{

	DrawGraph(620, 395, FruitImage[0], TRUE);
	DrawGraph(840, 680, FruitImage[0], TRUE);
	//DrawGraph(815, 680, FruitImage[1], TRUE);
	/*DrawGraph(640, 680, FruitImage[2], TRUE);
	DrawGraph(540, 680, FruitImage[3], TRUE);
	DrawGraph(440, 680, FruitImage[4], TRUE);
	DrawGraph(340, 680, FruitImage[5], TRUE);
	DrawGraph(240, 680, FruitImage[6], TRUE);
	DrawGraph(140, 680, FruitImage[7], TRUE);*/

}

void CFruit::Init(float x, float y, int* FruitImage, bool FruitType, int FruitScore)
{
	this->x = x;  //���W
	this->y = y;  //���W
	this->FruitType = FruitType;  //�G�T�摜�̔���
	this->FruitScore = FruitScore; //�G�T�̃X�R�A

}