#pragma once
#include"define.h"
#include "CAbstractScene.h"

#define D_GAMEOVER_POS 21 //�}�X��
#define D_SCREEN_SIZE_WIDTH 1280
#define D_SCREEN_SIZE_HEIGHT 720

class CField;
class CAbstractEnemy;
class CGameMain : public CAbstractScene
{
private:
	CField* field;
	CAbstractEnemy* enemy;
	//�v���C���[�h���ǂ����@true�F�v���C���[�h�@false�F�X�^�[�g���[�h
	bool isPlayMode;

	//�摜�p�ϐ�
	int gameOverImage; //�Q�[���I�[�o�[�摜
public:
	//�R���X�g���N�^
	CGameMain();
	//�f�X�g���N�^
	~CGameMain()override;

	//�X�V
	CAbstractScene* Update()override;
	//�`��
	void Draw()const override;
};
