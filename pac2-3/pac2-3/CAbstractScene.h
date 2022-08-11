#pragma once
class CAbstractScene
{
protected:
	//�f�[�^�̑ޔ��ꏊ
	int saveData = 0;
public:
	//�R���X�g���N�^
	CAbstractScene() {}
	//�f�X�g���N�g�^
	virtual ~CAbstractScene() {}

	//�X�V
	virtual CAbstractScene* Update() = 0;
	//�`��
	virtual void Draw()const {}


	//�f�[�^�̑ޔ�
	void SetSaveData(int saveData) { if (saveData != 0)this->saveData = saveData; }
	//�f�[�^�̎��o��
	int GetSaveData()const { return saveData; }

};

