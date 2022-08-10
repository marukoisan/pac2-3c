#pragma once
class CAbstractScene;
class CSceneManager
{
private:
	CAbstractScene* scene;
public:
	//コンストラクタ
	CSceneManager() {}
	//デストラクタ
	~CSceneManager() {}

	//
	CAbstractScene* Update();

	//
	void Draw()const;
};

