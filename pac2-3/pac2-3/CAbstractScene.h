#pragma once
#include"DxLib.h"
#include"CController.h"
class CController;
class CAbstractScene
{
protected:
	//�f�[�^�̑ޔ��ꏊ
	int saveData = 0;

	CController* controller;
	XINPUT_STATE* keyState = {};

public:
	//�R���X�g���N�^
	CAbstractScene();
	//�f�X�g���N�g�^
	virtual ~CAbstractScene() { delete controller; }

	//�X�V
	virtual CAbstractScene* Update() = 0;
	void ControllerUpdate() { controller->Update(); }
	//�`��
	virtual void Draw()const {}


	//�f�[�^�̑ޔ�
	void SetSaveData(int saveData) { if (saveData != 0)this->saveData = saveData; }
	//�f�[�^�̎��o��
	int GetSaveData()const { return saveData; }

	//�����I���{�^���p�L�[�t���O���o��
	short int GetKeyFlgStateButton() { return keyState->Buttons[XINPUT_BUTTON_BACK]; }

};

