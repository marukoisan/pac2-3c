#pragma once
#include"Object.h"

#define FRUIT_MAX 13

class CFruit : public CObject
{
private:

	int FruitImage[FRUIT_MAX] = {};
	int fruitType;  //�G�T�摜�̔���
	bool fruitFlg;  //�G�T�̕\���t���O
	int fruitScore = 0;  //�G�T�̃X�R�A
	int fruitTimer;  //�G�T�̓_�ŗp�̎��Ԃ�����ϐ�
	bool fruitIsShow; //1��0���`��t���O
	int FRUIT_SCORES[FRUIT_MAX]={100,300,500,500,700,700,1000,1000,2000,2000,3000,3000,5000};

public:

	CFruit();
	~CFruit(); 
	void Update();
	void Draw()const;
	void Init();
	void HitAction() { }
	int HitAction_Player() 
	{
		fruitFlg = false; 
		return fruitScore;
	}

	void Advent(int index);//�ϐ��̏�����
	bool GetFlg() { return fruitFlg; }//�G�T�̕\���t���O
	//void toggle(void) { FruitIsShow = !(FruitIsShow); }//�`��t���O
	int GetScore() { return fruitScore; }//�G�T�̃X�R�A��Ⴄ

	//�f�o�b�O�p�@TODO:����
	void DeleteFeed() { fruitFlg = false; }

};

