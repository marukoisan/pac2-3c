#pragma once
class CAbstractScene
{
protected:
	//データの退避場所
	int saveData = 0;
public:
	//コンストラクタ
	CAbstractScene() {}
	//デストラクトタ
	virtual ~CAbstractScene() {}

	//更新
	virtual CAbstractScene* Update() = 0;
	//描画
	virtual void Draw()const {}


	//データの退避
	void SetSaveData(int saveData) { if (saveData != 0)this->saveData = saveData; }
	//データの取り出し
	int GetSaveData()const { return saveData; }

};

