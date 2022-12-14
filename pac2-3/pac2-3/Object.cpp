#include "Object.h"
#include <math.h>

//-------------------------
// 絶対値を求める
//-------------------------
float absf(void* num) 
{
	if(*(float*)num<0)
	{
		*(float*)num = *(float*)num * -1;
	}
	return *(float*)num;
}

//--------------------------
// 矩形と矩形の当たり判定 
//--------------------------
bool CheckHitBox(CObject* obj1, CObject* obj2)
{
	//old, nowの更新
	obj1->UpdateFlg();
	obj2->UpdateFlg();

	//必要な情報の準備
	float distanceX = obj1->GetX() - obj2->GetX();
	float distanceY = obj1->GetY() - obj2->GetY();
	float rangeX = obj1->GetWidth() / 2 + obj2->GetWidth() / 2;
	float rangeY = obj1->GetHeight() / 2 + obj2->GetHeight() / 2;

	//-------------------------------
	// 	当たった瞬間
	//-------------------------------
	if (obj1->GetOldHitFlg() == false 
		&& obj2->GetOldHitFlg() == false
		&&absf(&distanceX) <= rangeX 
		&& absf(&distanceY) <= rangeY) 
	{
		obj1->SetNowFlg(true);
		obj2->SetNowFlg(true);

		obj1->HitAction();
		obj2->HitAction();

		return true;
	}
	//------------------------------
	//	重なっている間
	//------------------------------
	else if(obj1->GetOldHitFlg() == true 
		&& obj2->GetOldHitFlg() == true
		&& absf(&distanceX) <= rangeX
		&& absf(&distanceY) <= rangeY)
	{
		obj1->OverLapAction();
		obj2->OverLapAction();
	}
	else //それ以外は当たっていない(false)
	{
		obj1->SetNowFlg(false);
		obj2->SetNowFlg(false);
	}


	//-----------------
	//  離れたとき
	//-----------------
	if (obj1->GetOldHitFlg() == true
		&& obj2->GetOldHitFlg() == true
		&& obj1->GetNowHitFlg() == false
		&& obj2->GetNowHitFlg() == false)
	{
		obj1->ReleaseAction();
		obj2->ReleaseAction();
	}

	return false;
}

//--------------------------------
// 円と矩形の当たり判定
//--------------------------------
bool CheckHitBox_Circle(CObject* box, CObject* circle) {
	return true;
}


//--------------------------------------
// 矩形と矩形の重なりを防ぐ
// （引数１のクラスが動く）
//--------------------------------------
void PreventOverlapBox(CObject* obj1, CObject* obj2)
{
	//必要な情報の準備
	float distanceX = obj1->GetX() - obj2->GetX();
	float distanceY = obj1->GetY() - obj2->GetY();
	float rangeX = obj1->GetWidth() / 2 + obj2->GetWidth() / 2;
	float rangeY = obj1->GetHeight() / 2 + obj2->GetHeight() / 2;


	if (absf(&distanceX) < rangeX
		&& absf(&distanceY) < rangeY)
	{
		if (obj1->GetX() < obj2->GetX() - (obj2->GetWidth() / 2))
		{
			//obj1->SetX(obj2->GetX() - rangeX);
			obj1->AddX(-(rangeX - absf(&distanceX)));
			distanceX += rangeX - absf(&distanceX);
		}
		else if (obj1->GetX() > obj2->GetX() + (obj2->GetWidth() / 2))
		{
			obj1->AddX(rangeX - absf(&distanceX));
			distanceX += rangeX - absf(&distanceX);
		}
		else
		{
			;
		}
	}

	if (absf(&distanceX) < rangeX
		&& absf(&distanceY) < rangeY)
	{
		if (obj1->GetY() < obj2->GetY() - (obj2->GetHeight() / 2))
		{
			obj1->AddY(-(rangeY - absf(&distanceY)));
			distanceY += rangeY - absf(&distanceY);
		}
		else if (obj1->GetY() > obj2->GetY() + (obj2->GetHeight() / 2))
		{
			obj1->AddY(rangeY - absf(&distanceY));
			distanceY += rangeY - absf(&distanceY);
		}
		else
		{
			;
		}
	}

}

//--------------------------------------
// 円と矩形の重なりを防ぐ
// （円のクラスが動く）
//--------------------------------------
void PreventOverlapCircle_Box(CObject* circle, CObject* box)
{
	//必要な情報の準備
	float radius = circle->GetHeight() / 2;
	float distanceX = circle->GetX() - box->GetX();
	float distanceY = circle->GetY() - box->GetY();
	float rangeX = radius + box->GetWidth() / 2;
	float rangeY = radius + box->GetHeight() / 2;

	//必要な情報の準備
	float diagonal = (box->GetHeight() / 2) * (box->GetHeight() / 2)
		+ (box->GetWidth() / 2) * (box->GetWidth() / 2);
	float distance = (box->GetX() - circle->GetX()) * (box->GetX() - circle->GetX())
		+ (box->GetY() - circle->GetY()) * (box->GetY() - circle->GetY());


	if (sqrt(distance) <= (sqrt(diagonal) + radius))
	{
		if (absf(&distanceX) <= rangeX
			&& absf(&distanceY) <= rangeY)
		{
			//矩形同士がめり込んでいた場合、変数を用意する
			float leftPosX = box->GetX() - (box->GetWidth() / 2);
			float rightPosX = box->GetX() + (box->GetWidth() / 2);
			float upperPosY = box->GetY() - (box->GetHeight() / 2);
			float lowerPosY = box->GetY() + (box->GetHeight() / 2);


			//左上
			if (circle->GetY() < upperPosY
				&& circle->GetX() < leftPosX)
			{

				float vx = leftPosX - circle->GetX();
				float vy = upperPosY - circle->GetY();
				float len = vx * vx + vy * vy;
				len = sqrt(len);

				if (radius > len)
				{

					circle->AddX(vx / len * (len - radius));
					circle->AddY(vy / len * (len - radius));
				}

			}//左下
			else if (circle->GetY() > lowerPosY
				&& circle->GetX() < leftPosX)
			{
				float vx = leftPosX - circle->GetX();
				float vy = lowerPosY - circle->GetY();
				float len = vx * vx + vy * vy;
				len = sqrt(len);

				if (radius > len)
				{

					circle->AddX(vx / len * (len - radius));
					circle->AddY(vy / len * (len - radius));
				}

			}//右上
			else if (circle->GetY() < upperPosY
				&& circle->GetX() > rightPosX)
			{
				float vx = rightPosX - circle->GetX();
				float vy = upperPosY - circle->GetY();
				float len = vx * vx + vy * vy;
				len = sqrt(len);

				if (radius > len)
				{
					circle->AddX(vx / len * (len - radius));
					circle->AddY(vy / len * (len - radius));
				}

			}//右下
			else if (circle->GetY() > lowerPosY
				&& circle->GetX() > rightPosX)
			{
				float vx = rightPosX - circle->GetX();
				float vy = lowerPosY - circle->GetY();
				float len = vx * vx + vy * vy;
				len = sqrt(len);

				if (radius > len)
				{
					circle->AddX(vx / len * (len - radius));
					circle->AddY(vy / len * (len - radius));
				}

			}//boxより左側か、右側か
			else if (circle->GetX() < leftPosX)
			{
				circle->AddX(-(rangeX - absf(&distanceX)));
			}
			else if (circle->GetX() > rightPosX)
			{
				circle->AddX(rangeX - absf(&distanceX));

			}//上側か、下側か
			else if (circle->GetY() < upperPosY)
			{
				circle->AddY(-(rangeY - absf(&distanceY)));
			}
			else if (circle->GetY() > lowerPosY)
			{
				circle->AddY(rangeY - absf(&distanceY));
			}
			else
			{
				;
			}

		}
	}
}

//-----------------------------
// めり込み防ぎます
// 引数1が動きます
//-----------------------------
void PreventOverlapCircle(CObject* obj1, CObject* obj2)
{
	//必要な情報の準備
	float vx = obj2->GetX() - obj1->GetX();
	float vy = obj2->GetY() - obj1->GetY();
	float len = vx * vx + vy * vy;
	float range = pow(double(obj1->GetWidth() / 2) + double(obj2->GetWidth() / 2), 2.0);
	if (range >= len)
	{
		range = sqrt(range);
		len = sqrt(len);

		if (len != 0)
		{
			obj1->AddX(vx / len * (len - range));
			obj1->AddY(vy / len * (len - range));
		}

	}
}