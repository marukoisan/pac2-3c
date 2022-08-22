#pragma once
#include "CAbstractScene.h"

class CField;
class CGameMain : public CAbstractScene
{
private:
	CField* field;
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

