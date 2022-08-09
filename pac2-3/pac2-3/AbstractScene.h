#pragma once
#include"DxLib.h"
#include"SceneManager.h"

//�f�t�H���g�̒��ۃV�[���N���X
//���[�U�[�͂�����p�����ăV�[������������Ɗy
class AbstractScene {
private:
    //�V�[���}�l�[�W���[�̃|�C���^


public:
    // �f�X�g���N�^
    virtual ~AbstractScene() {};

    //�`��ȊO�̍X�V����������
    virtual AbstractScene* Update(XINPUT_STATE* data) = 0;

    //�`��Ɋւ��邱�Ƃ���������
    virtual void Draw() const = 0;

    

};