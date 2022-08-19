#include "Object.h"
#include<math.h>

////-------------------------
//// ��Βl�����߂�
////-------------------------
//float absf(void* num) 
//{
//	if(*(float*)num<0)
//	{
//		*(float*)num = *(float*)num * -1;
//	}
//	return *(float*)num;
//}
//
////--------------------------
//// ��`�Ƌ�`�̓����蔻�� 
////--------------------------
//bool CheckHitBox(CObject* obj1, CObject* obj2)
//{
//	//old, now�̍X�V
//	obj1->UpdateFlg();
//	obj2->UpdateFlg();
//
//	//�K�v�ȏ��̏���
//	float distanceX = obj1->GetX() - obj2->GetX();
//	float distanceY = obj1->GetY() - obj2->GetY();
//	float rangeX = obj1->GetWidth() / 2 + obj2->GetWidth() / 2;
//	float rangeY = obj1->GetHeight() / 2 + obj2->GetHeight() / 2;
//
//	//-------------------------------
//	// 	���������u��
//	//-------------------------------
//	if (obj1->GetOldHitFlg() == false 
//		&& obj2->GetOldHitFlg() == false
//		&&absf(&distanceX) <= rangeX 
//		&& absf(&distanceY) <= rangeY) 
//	{
//		obj1->SetNowFlg(true);
//		obj2->SetNowFlg(true);
//
//		obj1->HitAction();
//		obj2->HitAction();
//
//		return true;
//	}
//	//------------------------------
//	//	�d�Ȃ��Ă����
//	//------------------------------
//	else if(obj1->GetOldHitFlg() == true 
//		&& obj2->GetOldHitFlg() == true
//		&& absf(&distanceX) <= rangeX
//		&& absf(&distanceY) <= rangeY)
//	{
//		obj1->OverLapAction();
//		obj2->OverLapAction();
//	}
//	else //����ȊO�͓������Ă��Ȃ�(false)
//	{
//		obj1->SetNowFlg(false);
//		obj2->SetNowFlg(false);
//	}
//
//
//	//-----------------
//	//  ���ꂽ�Ƃ�
//	//-----------------
//	if (obj1->GetOldHitFlg() == true
//		&& obj2->GetOldHitFlg() == true
//		&& obj1->GetNowHitFlg() == false
//		&& obj2->GetNowHitFlg() == false)
//	{
//		obj1->ReleaseAction();
//		obj2->ReleaseAction();
//	}
//
//	return false;
//}
//
////--------------------------------
//// �~�Ƌ�`�̓����蔻��
////--------------------------------
//bool CheckHitBox_Circle(CObject* box, CObject* circle) {
//
//}

//--------------------------
// �~�Ɖ~�̓����蔻�� 
//--------------------------
bool CheckHitCircle(CObject* obj1, CObject* obj2)
{

	//�K�v�ȏ��̏���
	float distance = pow(double(obj1->GetX()) - double(obj2->GetX()), 2.0)
		+ pow(double(obj1->GetY()) - double(obj2->GetY()), 2.0);
	float range = pow(double(obj1->GetWidth() / 2) + double(obj2->GetWidth() / 2), 2.0);

	//-------------------------------
	// 	���������u��
	//-------------------------------
	if (distance <= range)
	{
		obj1->HitAction();
		obj2->HitAction();

		return true;
	}
	else
	{
		return false;
	}
}