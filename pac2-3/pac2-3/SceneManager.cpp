#include "SceneManager.h"

// メンバ変数の値を書き換えるのがアップデート関数
AbstractScene* SceneManager::Update() {
    // 現在シーンのアップデートを実行
    AbstractScene* p = mScene->Update();

    // 次のシーンが現在シーンと違う場合切り替える
    if (p != mScene) {
        delete mScene;
        mScene = p;
    }

    return p;
}

// 描画処理のみを行う関数
void SceneManager::Draw() const {
    // 現在シーンの描画関数を実行
    mScene->Draw();
}