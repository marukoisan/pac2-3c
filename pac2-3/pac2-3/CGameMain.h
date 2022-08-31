#pragma once
#include "CAbstractScene.h"

#define D_GAMEOVER_POS 21 //�}�X��
#define D_MASS_SIZE 20
#define D_SCREEN_SIZE_WIDTH 1280
#define D_SCREEN_SIZE_HEIGHT 720

class CField;
class CEsaController;

class CGameMain : public CAbstractScene
{
private:
	CField* field;

	//�v���C���[�h���ǂ����@true�F�v���C���[�h�@false�F�X�^�[�g���[�h
	bool isPlayMode;

	
	CEsaController* esacontroller;


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

