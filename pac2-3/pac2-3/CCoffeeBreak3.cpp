#include "CCoffeeBreak3.h"


CCoffeeBreak3::CCoffeeBreak3()
{
	LoadImages();
}


CCoffeeBreak3::~CCoffeeBreak3()
{

}

void CCoffeeBreak3::Update()
{

}

void CCoffeeBreak3::Draw() const
{
	DrawGraph(200, 200, tugihagi[0], TRUE);
	DrawGraph(200, 250, tugihagi[1], TRUE);
	DrawGraph(200, 300, imomusi[0], TRUE);
	DrawGraph(200, 350, imomusi[1], TRUE);
}

void CCoffeeBreak3::LoadImages()
{
	LoadDivGraph("images/tugihagi.png",TUGIHAGI_MAX,2,1,17,14,tugihagi);
	LoadDivGraph("images/imomusi.png",IMOMUSI_MAX,1,2,22,15,imomusi);
}