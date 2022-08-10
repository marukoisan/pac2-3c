#include "CSceneManager.h"
#include"CGameMain.h"

//-----------------------
// �R���X�g���N�^
//-----------------------
//CSceneManager::CSceneManager() {}

//-------------------------------
// �X�V
//-------------------------------
CAbstractScene* CSceneManager::Update()
{
	CAbstractScene* pScene = scene->Update();
	if (pScene != scene)
	{
		delete scene;
		scene = pScene;
	}

	return pScene;
}