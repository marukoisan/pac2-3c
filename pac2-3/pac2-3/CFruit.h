#pragma once
#include"Object.h"
#define FRUIT_MAX 13

class CFruit : public CObject
{
private:

	int FruitImage[FRUIT_MAX] = {};
	int Cherry = 100;
	bool FruitType;  //�G�T�摜�̔���
	bool FruitFlg;  //�G�T�̕\���t���O
	int FruitScore;  //�G�T�̃X�R�A
	int FruitTime;  //�G�T�̓_�ŗp�̎��Ԃ�����ϐ�
	bool FruitIsShow; //1��0���`��t���O





public:

	CFruit();
	~CFruit() {}
	void Update() {}
	void Draw()const;
	void HitAction() { FruitFlg = false; }
	void Init(float x, float y, int* FruitImage, bool FruitType, int FruitScore);//�ϐ��̏�����
	bool GetFlg() { return FruitFlg; }//�G�T�̕\���t���O
	void toggle(void) { FruitIsShow = !(FruitIsShow); }//�`��t���O
	int GetScore() { return FruitScore; }//�G�T�̃X�R�A��Ⴄ

};

