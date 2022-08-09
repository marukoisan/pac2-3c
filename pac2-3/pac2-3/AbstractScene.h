#pragma once

//デフォルトの抽象シーンクラス
//ユーザーはこれを継承してシーンを実装すると楽
class AbstractScene
{
protected:
	int saveData;
public:
	//コンストラクタ
	AbstractScene();
	//デストラクタ
	virtual ~AbstractScene() = 0;

	//更新
	virtual AbstractScene* Update() = 0;
	//描画
	virtual void Draw()const = 0;

};