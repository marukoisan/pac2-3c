#pragma once
#include"DxLib.h"
#include"SceneManager.h"

class SceneManager;

//デフォルトの抽象シーンクラス
//ユーザーはこれを継承してシーンを実装すると楽
class AbstractScene {
protected:
    //シーンマネージャーのポインタ
    SceneManager* sceneManager;//変数の宣言する時最初小文字

public:
    //コンストラクタ
    //メンバ変数のシーンマネージャーに引数のシーンマネージャーを渡している
    AbstractScene(SceneManager* sManager)
    {
       sceneManager = sManager;
    }

    // デストラクタ
    virtual ~AbstractScene() {};

    //描画以外の更新を実装する
    virtual AbstractScene* Update() = 0;

    //描画に関することを実装する
    virtual void Draw() const = 0;

    

};