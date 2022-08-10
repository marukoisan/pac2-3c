#include "CSceneManager.h"
#include"CAbstractScene.h"

//-------------------------------
// XV
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