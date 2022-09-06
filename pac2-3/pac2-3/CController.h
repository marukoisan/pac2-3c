#pragma once
class CController
{
private:
	XINPUT_STATE keyState = {};
	XINPUT_STATE inputKey = {};
	int inputInterval;

public:
	CController();
	CController(int inputInterval);
	~CController();

	//çXêV
	void Update();

	XINPUT_STATE* GetKeyState() { return &keyState; }
};

