#pragma once
class CObject
{
protected:
	//�s�{�b�g�ʒu
	float x = 0;
	float y = 0;

	//�����蔻��
	float height = 0;
	float width = 0;

	//����p�ϐ�
	bool oldHitFlg = false;
	bool nowHitFlg = false;

public:
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	void UpdateFlg() { oldHitFlg = nowHitFlg; }

	//�����������̏���
	virtual void HitAction() = 0;
	virtual void OverLapAction() {}

	virtual void ReleaseAction() {}


	//get�֐�
	float GetX()const { return x; }
	float GetY()const { return y; }
	float GetHeight()const { return height; }
	float GetWidth()const { return width; }
	bool GetOldHitFlg()const { return oldHitFlg; }
	bool GetNowHitFlg()const { return nowHitFlg; }

	//set�֐�
	void SetNowFlg(bool flg) { nowHitFlg = flg; }
};

//��`�Ƌ�`�̓����蔻��
bool CheckHitBox(CObject* obj1, CObject* obj2);
bool CheckHitBox_Circle(CObject* box,CObject* circle);