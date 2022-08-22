#include"DxLib.h"
#include"CEnemy.h"

//�萔�錾
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;


CEnemy::CEnemy()//�R���X�g���N�^
{
	   //�G�l�~�[�{�̉摜
	 LoadDivGraph("images/sprites/monster.png",
		 20, 20, 1, ENEMY_IMAGE_SIZE, ENEMY_IMAGE_SIZE, enemy);//�摜�̕����ǂݍ���
	 //enemyRun = 0; //�G�l�~�[�ړ��p�摜
	  //�G�l�~�[�ڂ̉摜
	 LoadDivGraph("images/sprites/eyes.png",
		 4, 4, 1, ENEMY_IMAGE_SIZE, ENEMY_IMAGE_SIZE, enemyEye);//�摜�̕����ǂݍ���
	 enemySpeed = 0.0; //�G�l�~�[�X�s�[�h
	 x = 0.0;   //���W
	 y = 0.0;   //���W

	 //�c��
	 height = 0.0;
	 width = 0.0;
	 /*angleX = 0.0;
	 angleY = 0.0;*/
	 enemyFlg = 0;
}

//void CEnemy::EnemyDisplay()
//{
//	if (enemyFlg == TRUE)
//	{
//		
//	}
//	
//}

void CEnemy::Init()//������
{
	x = 300.0;//���W
	y = 300.0;//���W

	//�c��
	height = 20.0;
	width = 20.0;
	//angleX = 0.0;
	//angleY = 0.0;
	//enemySpeed = 2.0; //�G�l�~�[�X�s�[�h
}

void CEnemy::Draw()const//�`��֐�
{
	DrawRotaGraphF(x, y, 1.0/ ENEMY_IMAGE_SIZE * ENEMY_ENEMY_SIZE,0,
		enemy[0],TRUE);//F�����邱�ƂŃL���X�g����K�v���Ȃ��A�����Ȃ̂�1.0�ɂ��Ȃ��Ƃ����Ȃ�
	DrawRotaGraphF(x, y, 1.0/ ENEMY_IMAGE_SIZE * ENEMY_ENEMY_SIZE,0,
		enemyEye[3],TRUE);
	
}

//void CEnemy::MoveEnemy()
//{
//
//}
//
//void CEnemy::notOverhang()
//{
//
//}
//
//float CEnemy::GetPosX()
//{
//	angleX = GetRand(1280) / 1280.f * 1280;
//}
//
//float CEnemy::GetPosY()
//{
//	angleY = GetRand(720) / 720.f * 720;
//}

