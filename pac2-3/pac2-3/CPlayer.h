#pragma once
#include"DxLib.h"
#include "Object.h"
#include"define.h"
#define _USE_MATH_DEFINES
#include<math.h>

#define D_PLAYER_IMAGE_MAX 3

#define D_PLAYER_UP 0
#define D_PLAYER_RIGHT 1
#define D_PLAYER_DOWN 2
#define D_PLAYER_LEFT 3
#define D_PLAYER_ANIM_FPS 5
#define D_PLAYER_CROSSPOINT 2

#define D_N_N 0      //�ʏ펞
#define D_N_N_ATE 1  //�ʏ펞�a��H�ׂ��Ƃ�
#define D_N_P_ATE 2  //�ʏ펞�p���[�a��H�ׂ���
#define D_P_N 3
#define D_P_N_ATE 4
#define D_P_P_ATE 5
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


	double DIRECTIONS[4] =
	{ 0,M_PI / 2,M_PI,M_PI + M_PI / 2 };
	
	//�ړ��p�ϐ�
	int nextDirection;
	int directionX;
	int directionY;
	double angle;
	float speed;
	const float MAKE_SPEED = 20.0f / 8.0f / 16.0f;
	bool isReleased;

	int powerTime=0;
	int eatTime = 0;
	int eatTimeSp = 0;

	int pacmanDyings[11];

	bool isAlive;
	int floor[D_FIELD_HEIGHT][D_FIELD_WIDTH] =
	{

		/*
		define D_BLOCK 0
		define D_FLOOR 1
		define D_CROSSPOINT 2  �����_
		*/

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,2,1,1,1,1,2,1,1,1,1,1,2,0,0,2,1,1,1,1,1,2,1,1,1,1,2,0},
		{0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
		{0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
		{0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
		{0,2,1,1,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,1,1,2,0},
		{0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0},
		{0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0},
		{0,2,1,1,1,1,2,0,0,2,1,1,2,0,0,2,1,1,2,0,0,2,1,1,1,1,2,0},
		{0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,2,1,1,2,1,1,2,1,1,2,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,1,0,1,1,1,1,1,1,0,1,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,2,1,1,2,0,1,1,1,1,1,1,0,2,1,1,2,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,1,0,1,1,1,1,1,1,0,1,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,2,1,1,1,1,1,1,1,1,2,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
		{0,2,1,1,1,1,2,1,1,2,1,1,2,0,0,2,1,1,2,1,1,2,1,1,1,1,2,0},
		{0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
		{0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
		{0,2,1,2,0,0,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,0,0,2,1,2,0},
		{0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0},
		{0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0},
		{0,2,1,2,1,1,2,0,0,2,1,1,2,0,0,2,1,1,2,0,0,2,1,1,2,1,2,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,2,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,2,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};


	int level=0;
	const float SPEED_LEVEL[4][6] =
	{
		{16.0f,15.0f,13.0f,18.0f,17.0f,15.0f},
		{18.0f,17.0f,15.0f,19.0f,18.0f,16.0f},
		{20.0f,19.0f,17.0f,20.0f,19.0f,17.0f},
		{18.0f,17.0f,15.0f,18.0f,17.0f,15.0f}
	};

public:
	CPlayer(CController* pController);
	~CPlayer();

	//�X�V
	void Update()override;
	//�`��
	void Draw()const override;
	//�����������̏���
	void HitAction()override {};


	void HitAction_Enemy();

	void ChangeDirection(int direction);

	void Respawn();

	bool GetisAlive();

	double GetAngle() { return angle; }

	void SetLevel(int lev) { level = lev; }
	void SetPowerTime(int time) { powerTime = time; }
	void eatFeed(bool isPower)
	{
		if (isPower)
		{
			eatTimeSp = 5;
		}
		else
		{
			eatTime = 5;
		}
	}

	void warp();

private:
	void Move();
	void Control();
	void SpeedUpdate();

};

