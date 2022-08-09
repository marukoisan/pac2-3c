#pragma once
#include"DxLib.h"
#include"AbstractScene.h"
#include"GameMain.h"

class AbstractScene;
class GameMain;

// �V�[���}�l�[�W���[�N���X
// �e�V�[���̐؂�ւ����Ǘ�����B
class SceneManager{
private:
    AbstractScene* mScene;  // ���݂̃V�[��


public:
    // �R���X�g���N�^
    SceneManager()
    {
        mScene = nullptr;

        //�Q�[�����C���̃V�[�����쐬
        mScene = new GameMain(this);

    }

    // �f�X�g���N�^
    ~SceneManager() {
        delete mScene;
    }

    //�`��ȊO�̍X�V����������
    AbstractScene* Update();

    //�`��Ɋւ��邱�Ƃ���������
    void Draw() const;

   
};