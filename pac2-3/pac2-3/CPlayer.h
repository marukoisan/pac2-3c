#pragma once
#include "Object.h"
#include"define.h"

#define D_PLAYER_IMAGE_MAX 3

#define D_PLAYER_UP 0
#define D_PLAYER_RIGHT 1
#define D_PLAYER_DOWN 2
#define D_PLAYER_LEFT 3
#define D_PLAYER_ANIM_FPS 5

class CController;
class CPlayer : public CObject
{
private:
	//�R���g���[��
	CController* controller;
	XINPUT_STATE* keyState;
	//�摜�n���h��
	int images[D_PLAYER_IMAGE_MAX] = {};
	//�A�j���[�V�����p�t���[��
	int animTimer;
	
	//�ړ��p�ϐ�
	int direction;
	float angle;

	int pacmanDyings[11];

	bool isAlive = FALSE;

	bool checkAnimFlg;

public:
	CPlayer(CController* pController);
	~CPlayer();

	//�X�V
	void Update()override;
	//�`��
	void Draw()const override;
	//�����������̏���
	void HitAction()override {}

	void Move();
	void MoveStraight();
	void Control();

	void HitActionanim();

	void Respawn();

	bool GetAnimFlg();

	bool GetisAlive();
};

