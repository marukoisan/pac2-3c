/***********************************************
 ** �@�p�b�N�}��
 ***********************************************/
#include "DxLib.h"
#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>
 #include"Player2.h"

 //#include"main.h"

  /***********************************************
   *�ϐ��錾
  /***********************************************/
   //MovePlayer moveplayer;
   //BaseAP baseap;


int g_OldKey;//�O��̓��̓L�[
int g_NowKey;//����̓��̓L�[
int g_KeyFlg;//���̓L�[���
int g_GameState = 0;//�Q�[�����[�h
//int g_TitleImage;//�摜�p�ϐ�
//int g_Score = 0;//�X�R�A
//int g_WaitTime = 0;//�҂�����
//int g_EndImage;
//int g_Mileage;//���s����
//int g_EnemyCount1, g_EnemyCount2, g_EnemyCount3;//�G�J�E���g
//int g_Appleimage;//�L�����摜�ϐ�
int g_PlayerUp, g_PlayerRight,g_PlayerLeft,g_PlayerDawn;          //�L�����摜�ϐ�
//int g_StageImage;
//int g_PosY;            //�X�N���[������Y���W
//int g_HelpImage;
//int g_Menu, g_AppleMenu;//���j���[�摜�ϐ�


/***********************************************
 *�֐��̃v���g�^�C�v�錾
 ***********************************************/

void GameInit(void);//�Q�[������������
void GameMain(void);//�Q�[�����C������
int LoadImages();

//void DrawEnd();	//�Q�[���G���h����
//void DrawGameTitle();//�^�C�g���`�揈��
//void DrawHelp();

/***********************************************
 *�v���O�����̊J�n
 ***********************************************/

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
//	LPSTR lpCmdLine, int nCmdShow) {
//
//	SetMainWindowText("Pacman");//�^�C�g����ݒ�
//	ChangeWindowMode(TRUE);//�E�B���h�E���[�h�ŋN��
//	if (DxLib_Init() == -1)return -1;//DX���C�u�����̏���������
//	SetDrawScreen(DX_SCREEN_BACK);//�`����ʂ𗠂ɂ���
//	if (LoadImages() == -1)return -1;//�摜�ǂݍ��݊֐����Ăяo��
//
//	//�Q�[�����[�v
//	while (ProcessMessage() == 0 && g_GameState != 99 && !(g_KeyFlg & PAD_INPUT_START)) {
//		// ���̓L�[�擾
//		g_OldKey = g_NowKey;
//		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//		g_KeyFlg = g_NowKey & ~g_OldKey;
//		ClearDrawScreen();//�摜�̏�����
//
//		switch (g_GameState) {
//			//case 0:
//			//	DrawGameTitle();	//�Q�[���^�C�g���`�揈��
//			//	break;
//		case 1:
//			GameInit();		//�Q�[����������
//			break;
//			//case 3:
//			//	DrawHelp();		//�Q�[���w���v�`�揈��
//			//	break;
//			//case 4:
//			//	DrawEnd();		//�Q�[���G���h�`�揈��
//			//	break;
//		case 5:
//			GameMain();     //�Q�[�����C������
//			break;
//
//
//		}
//		ScreenFlip();     //����ʂ̓��e��\��ʂɔ��f
//	}
//	DxLib_End();
//
//	return 0;
//}

/***********************************************
 *�Q�[���^�C�g���\��(���j���[���)
 ***********************************************/
 //void DrawGameTitle(void) {
 //	static int MenuNo = 0;
 //	//���j���[�J�[�\���ړ�����
 //	if (g_KeyFlg & PAD_INPUT_DOWN) {
 //		if (++MenuNo > 3)MenuNo = 0;
 //	}
 //	if (g_KeyFlg & PAD_INPUT_UP) {
 //		if (--MenuNo < 0)MenuNo = 3;
 //	}
 //	//A�{�^���Ń��j���[�I��
 //	if (g_KeyFlg & PAD_INPUT_A)g_GameState = MenuNo + 1;
 //	//�^�C�g���摜�\��
 //	DrawGraph(0, 0, g_TitleImage, FALSE);
 //	//���j���[
 //	DrawGraph(120, 200, g_Menu, TRUE);
 //	//���j���[�J�[�\��
 //	DrawRotaGraph(125, 220 + MenuNo * 35, 0.7f, M_PI / 50, g_Appleimage, TRUE);
 //}

 /***********************************************
  *�Q�[����������
  ***********************************************/
void GameInit(void) {


	//�v���C���[�̏����ݒ�
	/*baseap.PlayerInit();*/


	//�Q�[�����C��������
	g_GameState = 5;//1
}

/***********************************************
 *�Q�[�����C��
***********************************************/
void GameMain(void) {
	/*moveplayer.PlayerControl(g_PlayerRight, g_PlayerLeft);
	moveapple.AppleControl();*/
}


/***********************************************
*�摜�ǂݍ���
***********************************************/

int LoadImages() {

	//�^�C�g��
	//if ((g_TitleImage = LoadGraph("images/Title.png")) == -1)return -1;
	
	//�G
	//if ((g_Appleimage = LoadGraph("images/Apple.png")) == -1)return-1;

	////�X�e�[�W�w�i
	//if ((g_StageImage = LoadGraph("images/mori.png")) == -1) return -1;

	////�G���f�B���O
	//if ((g_EndImage = LoadGraph("images/mori.png")) == -1) return -1;

	//�v���C���[
	if ((g_PlayerUp = LoadGraph("images/sprites/pacman.png")) == -1)return -1;//��
	//if ((g_PlayerRight = LoadGraph("images/sprites/pacman.png")) == -1)return -1;//�E
	//if ((g_PlayerLeft = LoadGraph("images/sprites/pacman.png")) == -1)return -1;//��
	//if ((g_PlayerDawn = LoadGraph("images/sprites/pacman.png")) == -1)return -1;//��
	

	//�w���v
	//if ((g_HelpImage = LoadGraph("images/Gamehelp.png")) == -1)return -1;

	//���j���[
	//if ((g_Menu = LoadGraph("images/menu.png")) == -1) return -1;
	//if ((g_AppleMenu = LoadGraph("images/Apple.png")) == -1) return-1;


	return 0;
}

//int AppleGame::getg_Appleimage() {
//	return g_Appleimage;
//}
//int AppleGame::getMileage() {
//	return g_Mileage;
//}
//int AppleGame::getNowKey() {
//	return g_NowKey;
//}
//int AppleGame::getSCREEN_WIDTH() {
//	return SCREEN_WIDTH;
//}
//int AppleGame::getSCREEN_HEIGHT() {
//	return SCREEN_HEIGHT;
//}
//int AppleGame::getg_PlayerLeft(int a) {
//	return g_PlayerLeft;
//}
//int AppleGame::getg_PlayerRight(int b) {
//	return g_PlayerRight;
//}




