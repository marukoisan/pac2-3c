#pragma once
class CAbstractScene
{
private:
	//�f�[�^�̑ޔ��ꏊ
	int saveData = 0;
public:
	//�R���X�g���N�^
	CAbstractScene() {}
	//�f�X�g���N�g�^
	virtual ~CAbstractScene() = 0;

	//�X�V
	virtual CAbstractScene* Update() = 0;
	//�`��
	virtual void Draw()const = 0;


	//�f�[�^�̑ޔ�
	void SetSaveData(int saveData) { if (this->saveData != 0)this->saveData = saveData; }
	//�f�[�^�̎��o��
	int GetSaveData()const { return saveData; }

};

