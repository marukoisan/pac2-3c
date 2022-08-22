#pragma once
#include"CAbstractScene.h"
class CAbstractScene;
class CSceneManager
{
private:
	CAbstractScene* scene;
public:
	//�R���X�g���N�^
	CSceneManager(CAbstractScene* pScene) :scene(pScene) {};
	//�f�X�g���N�^
	~CSceneManager()
	{
		//�m�ۂ��Ă���V�[���̉��
		delete scene;
	}

	//�X�V
	CAbstractScene* Update();
	//�`��
	void Draw()const { scene->Draw(); }
};
