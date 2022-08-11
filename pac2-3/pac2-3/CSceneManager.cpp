#include "CSceneManager.h"
#include"CGameMain.h"

//-------------------------------
// XV
//-------------------------------
CAbstractScene* CSceneManager::Update()
{
	CAbstractScene* pScene = scene->Update();
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