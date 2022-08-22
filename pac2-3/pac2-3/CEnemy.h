#pragma once
#include"Object.h"
#define ENEMY_IMAGE_MAX  20  //�G�l�~�[�摜�̐�
#define ENEMY_IMAGEEYE_MAX  4  //�G�l�~�[�摜�̐�
#define ENEMY_IMAGE_SIZE  32 //�匳�̉摜�̑傫��
#define ENEMY_ENEMY_SIZE  20.0 //������g���摜�̑傫��


class CEnemy : public CObject
{
private:
	
	int enemy[ENEMY_IMAGE_MAX];    //�G�l�~�[�{�̉摜
	//int enemyRun; //�G�l�~�[�ړ��p�摜
	
	int enemyEye[ENEMY_IMAGEEYE_MAX]; //�G�l�~�[�̖ډ摜
	float enemySpeed; //�G�l�~�[�X�s�[�h

	//float angleX;   //�����ŏo���ꂽX���W
	//float angleY;   //�����ŏo���ꂽY���W

	float x;   //���W
	float y;   //���W

	//�����蔻��@�c��
	float height;
	float width;

	bool enemyFlg;//�G�l�~�[�t���O


public:
	CEnemy();     //�R���X�g���N�^
	void EnemyDisplay();  //�G�l�~�[�\��
	void Init();  //�ϐ��������p
	void Update() {} //�p������Update
	void Draw()const;   //�摜�p�֐�
	void HitAction() {} //�p������HitAction
	void MoveEnemy();   //�G�l�~�[�ړ�
	void notOverhang(); //�͂ݏo���Ȃ��������s�� 
	float GetPosX();     //�v���g�p�̍��W���擾����֐� X�p
	float GetPosY();     //�v���g�p�̍��W���擾����֐� Y�p

};

