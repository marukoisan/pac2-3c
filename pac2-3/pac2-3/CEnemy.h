#pragma once


class CEnemy
{
private:
	int enemy;    //�G�l�~�[�Î~�摜
	int enemyRun; //�G�l�~�[�ړ��p�摜
	float enemySpeed; //�G�l�~�[�X�s�[�h
	float enemyX;   //���W
	float enemyY;   //���W

	//bool enemyFlg;//�G�l�~�[�t���O


public:
	CEnemy();     //�R���X�g���N�^
	void EnemyDisplay(void);  //�G�l�~�[�\��
	void Init();  //�ϐ��������p
	int Image();  //�摜�p�֐�
	void MoveEnemy();   //�G�l�~�[�ړ�

};