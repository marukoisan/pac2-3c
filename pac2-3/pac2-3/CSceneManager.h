#pragma once
#include"CAbstractScene.h"
class CAbstractScene;
class CSceneManager
{
private:
	CAbstractScene* scene;
public:
	//コンストラクタ
	CSceneManager(CAbstractScene* pScene) :scene(pScene) {};
	//デストラクタ
	~CSceneManager() {}

	//更新
	CAbstractScene* Update();
	//描画
	void Draw()const { scene->Draw(); }
};

