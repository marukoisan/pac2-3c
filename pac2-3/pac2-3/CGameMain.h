#pragma once
#include "CAbstractScene.h"
class CEnemy;//�N���X���`���邱�ƂŁA�N���X�ɓ����Ă�����̂��g�����Ƃ��o����
      //�Q�Ƃ���Ƃ��̓A���[���Z�q���g�p����
class CGameMain : public CAbstractScene
{
private:
	CEnemy* enemy;//�ϐ��Ƃ��������ꕨ���m�ۂ��Ă���

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

