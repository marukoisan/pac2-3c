#pragma once
#include"AbstractScene.h"

class AbstractScene;
class SceneManager;

class GameMain : public AbstractScene
{
private://�ϐ��錾
	
public:
	//��Ɍp�����̃R���X�g���N�^���Ă�ł���p����̃R���X�g���N�^���Ă�ł���
	GameMain(SceneManager* sManager) : AbstractScene(sManager)
	{

	}

	~GameMain() {}

	virtual AbstractScene* Update() override;

	virtual void Draw() const override;
};

