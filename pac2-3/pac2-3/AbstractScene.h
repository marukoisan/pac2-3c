#pragma once
#include"DxLib.h"
#include"SceneManager.h"

class SceneManager;

//�f�t�H���g�̒��ۃV�[���N���X
//���[�U�[�͂�����p�����ăV�[������������Ɗy
class AbstractScene {
protected:
    //�V�[���}�l�[�W���[�̃|�C���^
    SceneManager* sceneManager;//�ϐ��̐錾���鎞�ŏ�������

public:
    //�R���X�g���N�^
    //�����o�ϐ��̃V�[���}�l�[�W���[�Ɉ����̃V�[���}�l�[�W���[��n���Ă���
    AbstractScene(SceneManager* sManager)
    {
       sceneManager = sManager;
    }

    // �f�X�g���N�^
    virtual ~AbstractScene() {};

    //�`��ȊO�̍X�V����������
    virtual AbstractScene* Update() = 0;

    //�`��Ɋւ��邱�Ƃ���������
    virtual void Draw() const = 0;

    

};