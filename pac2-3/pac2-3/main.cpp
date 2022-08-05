#include"DxLib.h"
//�ϐ��̐錾
int g_LoopCount = 0;
//�v���O�����̊J�n
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
{
	//�E�B���h�E���[�h�ŋN������
	ChangeWindowMode(TRUE);
	SetGraphMode(1280, 720, 32);
 
	//DX���C�u�����̏���������:�G���[���N�����璼���ɏI��
	if (DxLib_Init() == -1)return-1;
 
	//�`����ʂ𗠂ɂ���
	SetDrawScreen(DX_SCREEN_BACK);
 
	//�Q�[�����[�v
	while (ProcessMessage() == 0)
	{
		//��ʂ̏�����
		ClearDrawScreen();
 
		//���[�v�J�E���^�̕\��
		DrawFormatString(0, 0, GetColor(255, 128, 0), "LoopCount=%d", g_LoopCount++);
 
		//����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();
	}
	//DX���C�u�����g�p�̏I������
	DxLib_End();
	//�\�t�g�̏I��
	return 0;

}