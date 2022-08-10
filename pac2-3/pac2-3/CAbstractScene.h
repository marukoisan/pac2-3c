#pragma once
class CAbstractScene
{
private:
	//データの退避場所
	int saveData = 0;
public:
	//コンストラクタ
	CAbstractScene() {}
	//デストラクトタ
	virtual ~CAbstractScene() = 0;

	//更新
	virtual CAbstractScene* Update() = 0;
	//描画
	virtual void Draw()const = 0;


	//データの退避
	void SetSaveData(int saveData) { if (this->saveData != 0)this->saveData = saveData; }
	//データの取り出し
	int GetSaveData()const { return saveData; }

};

