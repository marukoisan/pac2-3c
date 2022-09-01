#include"DxLib.h"

#include"CSceneManager.h"
#include"CTitle.h"


#include"Player2.h"
//�ϐ��̐錾
//int g_LoopCount = 0;

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
 
	//�V�[���}�l�[�W���[�̊m��
	CSceneManager* sceneManager;
	sceneManager = new CSceneManager(new CTitle);

	//�Q�[�����[�v
	while (ProcessMessage() == 0
			&& sceneManager->Update() != nullptr
			&& GetJoypadInputState(DX_INPUT_KEY_PAD1) != PAD_INPUT_9/*ESC�L�[*/)
	{
		//��ʂ̏�����
		ClearDrawScreen();


		sceneManager->Draw();

		
		player2.Init();
		player2.LoadImages();
		player2.PlayerMove();

		////���[�v�J�E���^�̕\��
		//DrawFormatString(0, 0, GetColor(255, 128, 0), "LoopCount=%d", g_LoopCount++);

 
		//����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();
	}

	//�V�[���}�l�[�W���[�̉��
	delete sceneManager;

	//DX���C�u�����g�p�̏I������
	DxLib_End();
	//�\�t�g�̏I��
	return 0;

}

