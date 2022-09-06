#pragma once
#include"DxLib.h"
#include"CController.h"
class CController;
class CAbstractScene
{
protected:
	//データの退避場所
	int saveData = 0;

	CController* controller;
	XINPUT_STATE* keyState = {};

public:
	//コンストラクタ
	CAbstractScene();
	//デストラクトタ
	virtual ~CAbstractScene() { delete controller; }

	//更新
	virtual CAbstractScene* Update() = 0;
	void ControllerUpdate() { controller->Update(); }
	//描画
	virtual void Draw()const {}


	//データの退避
	void SetSaveData(int saveData) { if (saveData != 0)this->saveData = saveData; }
	//データの取り出し
	int GetSaveData()const { return saveData; }

	//強制終了ボタン用キーフラグ取り出し
	short int GetKeyFlgStateButton() { return keyState->Buttons[XINPUT_BUTTON_BACK]; }

};

