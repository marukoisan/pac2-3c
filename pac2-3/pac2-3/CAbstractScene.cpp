
#include"CAbstractScene.h"

CAbstractScene::CAbstractScene()
{
	controller = new CController;
	keyState = controller->GetKeyState();
}