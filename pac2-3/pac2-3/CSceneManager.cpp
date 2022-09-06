#include "CSceneManager.h"
#include"CGameMain.h"

//-------------------------------
// XV
//-------------------------------
CAbstractScene* CSceneManager::Update()
{

	scene->ControllerUpdate();
	CAbstractScene* pScene = scene->Update();	

	if (scene->GetKeyFlgStateButton() == TRUE)
	{
		return nullptr;
	}

	if (pScene != scene)
	{
		int tmp;
		tmp = scene->GetSaveData();
		delete scene;
		scene = pScene;
		pScene->SetSaveData(tmp);
	}

	return pScene;
}