#include<stdio.h>
#include"DxLib.h"
#include "CFruit.h"
#include "define.h"


CFruit::CFruit()//�R���X�g���N�^
{
	bool error = false;
	if (LoadDivGraph("images/sprites/fruit.png", FRUIT_MAX, 13, 1, 32, 32, FruitImage) == -1)error = true;

	stageLevel = 0;  //�G�T�摜�̔���
	fruitFlg = false;  //�G�T�̕\���t���O
	fruitScore = 0;  //�G�T�̃X�R�A
	fruitTimer = 0;   //�G�T�̓_�ł����邽�ߗp�̎��ԕϐ�
	fruitIsShow = true; //�G�T�̕`��t���O

	height = 20;
	width = 20;
	x = 270;
	y = 340;
}

CFruit::~CFruit()//�f�X�g���N�^
{
	;
}

void CFruit::Update()
{
	fruitTimer--;
	if (fruitTimer < 0)
	{
		fruitFlg = false;
	}
}

void CFruit::Draw()const
{
	if (fruitFlg)
	{
		DrawRotaGraphF(D_FIELD_POS_X+x, D_FIELD_POS_Y+y, 1.0, 0, FruitImage[stageLevel], TRUE);
	}
	DrawGraph(840, 680, FruitImage[0], TRUE);
	//DrawGraph(815, 680, FruitImage[1], TRUE);
	/*DrawGraph(640, 680, FruitImage[2], TRUE);
	DrawGraph(540, 680, FruitImage[3], TRUE);
	DrawGraph(440, 680, FruitImage[4], TRUE);
	DrawGraph(340, 680, FruitImage[5], TRUE);
	DrawGraph(240, 680, FruitImage[6], TRUE);
	DrawGraph(140, 680, FruitImage[7], TRUE);*/

}

void CFruit::Init()
{
	fruitTimer = 0;
	fruitFlg = false;
}

void CFruit::Advent()
{
	fruitScore = FRUIT_SCORES[stageLevel]; //�G�T�̃X�R�A
	fruitFlg = true;
	fruitTimer = 60 * 10;
}