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
	~CSceneManager()
	{
		//確保しているシーンの解放
		delete scene;
	}

	//更新
	CAbstractScene* Update();
	//描画
	void Draw()const { scene->Draw(); }
};

