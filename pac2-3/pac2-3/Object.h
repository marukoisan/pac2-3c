#pragma once
class CObject
{
protected:
	//ピボット位置
	float x = 0;
	float y = 0;

	//当たり判定
	float height = 0;
	float width = 0;

	//判定用変数
	bool oldHitFlg = false;
	bool nowHitFlg = false;

public:
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	void UpdateFlg() { oldHitFlg = nowHitFlg; }

	//当たった時の処理
	virtual void HitAction() = 0;
	virtual void OverLapAction() {}
	virtual void ReleaseAction() {};

	//get関数
	float GetX()const { return x; }
	float GetY()const { return y; }
	void AddX(float addX) { x += addX; }
	void SetX(float x) { this->x = x; }//ワープトンネル用
	void AddY(float addY) { y += addY; }
	float GetHeight()const { return height; }
	float GetWidth()const { return width; }
	bool GetOldHitFlg()const { return oldHitFlg; }
	bool GetNowHitFlg()const { return nowHitFlg; }

	//set関数
	void SetNowFlg(bool flg) { nowHitFlg = flg; }
};

//矩形と矩形の当たり判定
bool CheckHitBox(CObject* obj1, CObject* obj2);
bool CheckHitBox_Circle(CObject* box,CObject* circle);
void PreventOverlapBox(CObject* obj1, CObject* obj2);
void PreventOverlapCircle_Box(CObject* circle, CObject* box);
void PreventOverlapCircle(CObject* obj1, CObject* obj2);