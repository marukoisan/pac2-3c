#include "CSceneManager.h"
#include"CGameMain.h"

//-----------------------
// コンストラクタ
//-----------------------
//CSceneManager::CSceneManager() {}

//-------------------------------
// 更新
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