#pragma once
#include"DxLib.h"
#include"AbstractScene.h"
#include"GameMain.h"

class AbstractScene;
class GameMain;

// シーンマネージャークラス
// 各シーンの切り替えを管理する。
class SceneManager{
private:
    AbstractScene* mScene;  // 現在のシーン


public:
    // コンストラクタ
    SceneManager()
    {
        mScene = nullptr;

        //ゲームメインのシーンを作成
        mScene = new GameMain(this);

    }

    // デストラクタ
    ~SceneManager() {
        delete mScene;
    }

    //描画以外の更新を実装する
    AbstractScene* Update();

    //描画に関することを実装する
    void Draw() const;

   
};