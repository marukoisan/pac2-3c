#pragma once
class CAbstractScene;
class CSceneManager
{
private:
	CAbstractScene* scene;
public:
	//�R���X�g���N�^
	CSceneManager() {}
	//�f�X�g���N�^
	~CSceneManager() {}

	//
	CAbstractScene* Update();

	//
	void Draw()const;
};

