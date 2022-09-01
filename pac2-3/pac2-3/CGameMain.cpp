#include"DxLib.h"
#include "CGameMain.h"
#include"CPlayer.h"


#include"CField.h"

XINPUT_STATE keyState;//�f�o�b�O�p�@TODO�F����

//-------------------
// �R���X�g���N�^
//-------------------
CGameMain::CGameMain()
{

	isPlayMode = true;
	gameOverImage = LoadGraph("game_over.png");
	field = new CField();
	player = new CPlayer;

}

//-------------------
// �f�X�g���N�^
//-------------------
CGameMain::~CGameMain()
{

	delete field;

	delete player;

}

//-------------------
// �X�V
//-------------------
CAbstractScene* CGameMain::Update()
{

	if (isPlayMode)
	{
		//�f�o�b�O�p
		
		GetJoypadXInputState(DX_INPUT_PAD1, &keyState);
		if (keyState.Buttons[XINPUT_BUTTON_START] == TRUE)//�G�T�̎c��̐����󂯎��A0�̎��ɃQ�[���N���A�Ƃ���
		{
			//�Q�[���N���A�̏���
			// �X�e�[�W�̍X�V
			// �G�T�̍Ĕz�u
			//�G�̏�����(��Փx��n��)
			//�v���C���[�̈ʒu�̏������A��Փx�̍X�V
			isPlayMode = false;


			if (keyState.Buttons[XINPUT_BUTTON_X] == TRUE)//�v���C���[���G�ɓ����������A�c�@��0��������Q�[���I�[�o�[�Ƃ���
			{
				
			}
		}

	}
	else
	{

		//�X�^�[�g���[�h�𗬂�

		//����I�������v���C���[�h�ɕԂ�
		isPlayMode = true;
	}

	
	player->Update();
>
	return this;
}

//-------------------
// �`��
//-------------------
void CGameMain::Draw()const
{

	field->Draw();
	DrawFormatString(0, 0, 0xffffff, "%d", saveData);

	if (keyState.Buttons[XINPUT_BUTTON_X] == TRUE)//�v���C���[���G�ɓ����������A�c�@��0��������Q�[���I�[�o�[�Ƃ���
	{
		DrawRotaGraph(D_SCREEN_SIZE_WIDTH / 2, D_GAMEOVER_POS * D_MASS_SIZE - (D_MASS_SIZE / 2)//���S���W�̈�
							, 1.0 / 8 * D_MASS_SIZE, 0, gameOverImage, TRUE);
		WaitKey();
	}
	if (isPlayMode)
	{
		DrawString(0, 0, "PlayMode", 0xFFFFFF);
	}
	else
	{
		DrawString(0, 0, "StartMode", 0xFFFFFF);
	}

		player->Draw();
		DrawFormatString(0, 0, 0xffffff, "%d", saveData);

}