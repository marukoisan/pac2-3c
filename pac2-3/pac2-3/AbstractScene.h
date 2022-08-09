#pragma once

//�f�t�H���g�̒��ۃV�[���N���X
//���[�U�[�͂�����p�����ăV�[������������Ɗy
class AbstractScene
{
protected:
	int saveData;
public:
	//�R���X�g���N�^
	AbstractScene();
	//�f�X�g���N�^
	virtual ~AbstractScene() = 0;

	//�X�V
	virtual AbstractScene* Update() = 0;
	//�`��
	virtual void Draw()const = 0;

};