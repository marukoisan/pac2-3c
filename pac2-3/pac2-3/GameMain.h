#pragma once
class GameMain : public AbstractScene
{
public:
	//�R���X�g���N�^
	GameMain();
	//�f�X�g���N�^
	~GameMain();
	AbstractScene* Update()override;
	void Draw()const override;

};

