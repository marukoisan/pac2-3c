#pragma once
class GameMain : public AbstractScene
{
public:
	//コンストラクタ
	GameMain();
	//デストラクタ
	~GameMain();
	AbstractScene* Update()override;
	void Draw()const override;

};

