#pragma once
#include"AbstractScene.h"

class AbstractScene;
class SceneManager;

class GameMain : public AbstractScene
{
private://変数宣言
	
public:
	//先に継承元のコンストラクタを呼んでから継承先のコンストラクタを呼んでいる
	GameMain(SceneManager* sManager) : AbstractScene(sManager)
	{

	}

	~GameMain() {}

	virtual AbstractScene* Update() override;

	virtual void Draw() const override;
};

