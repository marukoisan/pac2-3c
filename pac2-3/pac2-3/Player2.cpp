///***********************************************
// ** �@�p�b�N�}��
// ***********************************************/
//#include "DxLib.h"
//#include<stdio.h>
//#define _USE_MATH_DEFINES
//#include<math.h>
// #include"Player2.h"
//
// //#include"main.h"
//
//  /***********************************************
//   *�ϐ��錾
//  /***********************************************/
//   //MovePlayer moveplayer;
//   //BaseAP baseap;
//
//
//int g_OldKey;//�O��̓��̓L�[
//int g_NowKey;//����̓��̓L�[
//int g_KeyFlg;//���̓L�[���
//int g_GameState = 0;//�Q�[�����[�h
////int g_TitleImage;//�摜�p�ϐ�
////int g_Score = 0;//�X�R�A
////int g_WaitTime = 0;//�҂�����
////int g_EndImage;
////int g_Mileage;//���s����
////int g_EnemyCount1, g_EnemyCount2, g_EnemyCount3;//�G�J�E���g
////int g_Appleimage;//�L�����摜�ϐ�
//int g_PlayerUp, g_PlayerRight,g_PlayerLeft,g_PlayerDawn;          //�L�����摜�ϐ�
////int g_StageImage;
////int g_PosY;            //�X�N���[������Y���W
////int g_HelpImage;
////int g_Menu, g_AppleMenu;//���j���[�摜�ϐ�
//
//
///***********************************************
// *�֐��̃v���g�^�C�v�錾
// ***********************************************/
//
//void GameInit(void);//�Q�[������������
//void GameMain(void);//�Q�[�����C������
//int LoadImages();
//
////void DrawEnd();	//�Q�[���G���h����
////void DrawGameTitle();//�^�C�g���`�揈��
////void DrawHelp();
//
///***********************************************
// *�v���O�����̊J�n
// ***********************************************/
//
////int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
////	LPSTR lpCmdLine, int nCmdShow) {
////
////	SetMainWindowText("Pacman");//�^�C�g����ݒ�
////	ChangeWindowMode(TRUE);//�E�B���h�E���[�h�ŋN��
////	if (DxLib_Init() == -1)return -1;//DX���C�u�����̏���������
////	SetDrawScreen(DX_SCREEN_BACK);//�`����ʂ𗠂ɂ���
////	if (LoadImages() == -1)return -1;//�摜�ǂݍ��݊֐����Ăяo��
////
////	//�Q�[�����[�v
////	while (ProcessMessage() == 0 && g_GameState != 99 && !(g_KeyFlg & PAD_INPUT_START)) {
////		// ���̓L�[�擾
////		g_OldKey = g_NowKey;
////		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
////		g_KeyFlg = g_NowKey & ~g_OldKey;
////		ClearDrawScreen();//�摜�̏�����
////
////		switch (g_GameState) {
////			//case 0:
////			//	DrawGameTitle();	//�Q�[���^�C�g���`�揈��
////			//	break;
////		case 1:
////			GameInit();		//�Q�[����������
////			break;
////			//case 3:
////			//	DrawHelp();		//�Q�[���w���v�`�揈��
////			//	break;
////			//case 4:
////			//	DrawEnd();		//�Q�[���G���h�`�揈��
////			//	break;
////		case 5:
////			GameMain();     //�Q�[�����C������
////			break;
////
////
////		}
////		ScreenFlip();     //����ʂ̓��e��\��ʂɔ��f
////	}
////	DxLib_End();
////
////	return 0;
////}
//
///***********************************************
// *�Q�[���^�C�g���\��(���j���[���)
// ***********************************************/
// //void DrawGameTitle(void) {
// //	static int MenuNo = 0;
// //	//���j���[�J�[�\���ړ�����
// //	if (g_KeyFlg & PAD_INPUT_DOWN) {
// //		if (++MenuNo > 3)MenuNo = 0;
// //	}
// //	if (g_KeyFlg & PAD_INPUT_UP) {
// //		if (--MenuNo < 0)MenuNo = 3;
// //	}
// //	//A�{�^���Ń��j���[�I��
// //	if (g_KeyFlg & PAD_INPUT_A)g_GameState = MenuNo + 1;
// //	//�^�C�g���摜�\��
// //	DrawGraph(0, 0, g_TitleImage, FALSE);
// //	//���j���[
// //	DrawGraph(120, 200, g_Menu, TRUE);
// //	//���j���[�J�[�\��
// //	DrawRotaGraph(125, 220 + MenuNo * 35, 0.7f, M_PI / 50, g_Appleimage, TRUE);
// //}
//
//// /***********************************************
////  *�Q�[����������
////  ***********************************************/
////void GameInit(void) {
////
////
////	//�v���C���[�̏����ݒ�
////	/*baseap.PlayerInit();*/
////
////
////	//�Q�[�����C��������
////	g_GameState = 5;//1
////}
////
/////***********************************************
//// *�Q�[�����C��
////***********************************************/
////void GameMain(void) {
////
////
////	/*moveplayer.PlayerControl(g_PlayerRight, g_PlayerLeft);
////	moveapple.AppleControl();*/
////}
//
//
///***********************************************
//*�摜�ǂݍ���
//***********************************************/
//
//int LoadImages() {
//
//	//�^�C�g��
//	//if ((g_TitleImage = LoadGraph("images/Title.png")) == -1)return -1;
//	
//	//�G
//	//if ((g_Appleimage = LoadGraph("images/Apple.png")) == -1)return-1;
//
//	////�X�e�[�W�w�i
//	//if ((g_StageImage = LoadGraph("images/mori.png")) == -1) return -1;
//
//	////�G���f�B���O
//	//if ((g_EndImage = LoadGraph("images/mori.png")) == -1) return -1;
//
//	//�v���C���[
//	if ((g_PlayerUp = LoadGraph("images/sprites/pacman.png")) == -1)return -1;//��
//	//if ((g_PlayerRight = LoadGraph("images/sprites/pacman.png")) == -1)return -1;//�E
//	//if ((g_PlayerLeft = LoadGraph("images/sprites/pacman.png")) == -1)return -1;//��
//	//if ((g_PlayerDawn = LoadGraph("images/sprites/pacman.png")) == -1)return -1;//��
//	
//
//	//�w���v
//	//if ((g_HelpImage = LoadGraph("images/Gamehelp.png")) == -1)return -1;
//
//	//���j���[
//	//if ((g_Menu = LoadGraph("images/menu.png")) == -1) return -1;
//	//if ((g_AppleMenu = LoadGraph("images/Apple.png")) == -1) return-1;
//
//
//	return 0;
//}
//
////int AppleGame::getg_Appleimage() {
////	return g_Appleimage;
////}
////int AppleGame::getMileage() {
////	return g_Mileage;
////}
////int AppleGame::getNowKey() {
////	return g_NowKey;
////}
////int AppleGame::getSCREEN_WIDTH() {
////	return SCREEN_WIDTH;
////}
////int AppleGame::getSCREEN_HEIGHT() {
////	return SCREEN_HEIGHT;
////}
////int AppleGame::getg_PlayerLeft(int a) {
////	return g_PlayerLeft;
////}
////int AppleGame::getg_PlayerRight(int b) {
////	return g_PlayerRight;
////}
//
//#include "DxLib.h"
//
//#define MAP_NUM         3           // �}�b�v�̐�
//
//#define MAP_SIZE        32          // �}�b�v�`�b�v��̃h�b�g�T�C�Y
//
//#define MAP_WIDTH_MAX   40          // �}�b�v�̍ő啝
//#define MAP_HEIGHT_MAX  40          // �}�b�v�̍ő�c����
//
//#define MOVE_FRAME      15          // �ړ��ɂ�����t���[����
//
//// �}�b�v�̍\����
//struct MAPDATA
//{
//    // �}�b�v�̕�
//    int Width;
//
//    // �}�b�v�̍���
//    int Height;
//
//    // �}�b�v
//    int Data[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
//};
//
//// �}�b�v�̃f�[�^
//MAPDATA MapData[MAP_NUM] =
//{
//    // �}�b�v�O
//    {
//        10,
//        8,
//        {
//            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
//            { 0, 1, 0, 0, 0, 1, 1, 1, 1, 0 } ,
//            { 0, 1, 1, 1, 0, 1, 1, 0, 1, 0 } ,
//            { 0, 0, 0, 1, 0, 1, 1, 0, 1, 0 } ,
//            { 0, 0, 0, 1, 0, 0, 1, 0, 1, 0 } ,
//            { 0, 0, 1, 1, 0, 0, 1, 0, 1, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 1, 0, 1, 0 } ,
//            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
//        }
//    },
//
//    // �}�b�v�P
//    {
//        20,
//        16,
//        {
//            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
//            { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 ,  1, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
//            { 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 ,  1, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
//            { 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 ,  1, 1, 1, 1, 1, 1, 0, 0, 1, 0 } ,
//            { 0, 1, 1, 0, 1, 0, 0, 1, 1, 0 ,  0, 0, 0, 0, 0, 1, 0, 0, 1, 0 } ,
//            { 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 ,  0, 0, 1, 1, 1, 1, 1, 0, 1, 0 } ,
//            { 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 ,  0, 0, 1, 0, 0, 1, 1, 0, 1, 0 } ,
//            { 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 ,  0, 0, 1, 0, 0, 1, 1, 0, 1, 0 } ,
//
//            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 ,  0, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
//            { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 ,  0, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
//            { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 ,  0, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
//            { 0, 0, 0, 1, 1, 0, 0, 1, 0, 0 ,  0, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
//            { 0, 1, 1, 1, 1, 0, 0, 1, 1, 1 ,  1, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
//            { 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
//            { 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
//            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
//        }
//    },
//
//    // �}�b�v�Q
//    {
//        40,
//        32,
//        {
//            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 ,  0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  1, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 ,  0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  1, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 ,  0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  1, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 ,  0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  1, 0, 0, 0, 1, 1, 1, 1, 1, 1 ,  1, 1, 1, 1, 1, 1, 1, 1, 0, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 ,  0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  1, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  0, 0, 0, 1, 0, 0, 0, 1, 0, 0 } ,
//            { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 ,  0, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,  1, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  1, 1, 1, 1, 0, 0, 0, 1, 0, 0 } ,
//            { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  1, 0, 0, 0, 0, 1, 1, 1, 0, 0 } ,
//
//            { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  1, 0, 1, 0, 1, 1, 0, 0, 0, 0 } ,
//            { 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  1, 0, 1, 0, 1, 0, 0, 1, 1, 0 } ,
//            { 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  1, 0, 1, 0, 1, 0, 1, 1, 0, 0 } ,
//            { 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 1, 1, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  1, 0, 1, 0, 1, 1, 1, 0, 0, 0 } ,
//            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 1, 1, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  1, 1, 1, 0, 1, 0, 0, 1, 1, 0 } ,
//            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 1, 1, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  0, 0, 0, 0, 1, 0, 0, 1, 1, 0 } ,
//            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 1 ,  1, 1, 1, 1, 1, 0, 0, 1, 1, 0 } ,
//            { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 ,  1, 1, 1, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 1 ,  0, 0, 0, 1, 0, 1, 1, 1, 1, 0 } ,
//
//            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 1 ,  1, 1, 0, 1, 0, 1, 0, 0, 0, 0 } ,
//            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 1 ,  1, 1, 0, 1, 0, 1, 0, 1, 1, 0 } ,
//            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 1, 1, 1, 1, 1, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  0, 1, 0, 1, 1, 1, 0, 1, 1, 0 } ,
//            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 1, 0, 0, 0, 1, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 1, 1 ,  1, 1, 0, 0, 0, 0, 1, 1, 1, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,  1, 1, 1, 0, 0, 0, 1, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 1, 0 ,  0, 0, 0, 0, 0, 1, 1, 0, 1, 0 } ,
//            { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 1, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 1, 1 ,  1, 1, 1, 1, 1, 1, 0, 0, 1, 0 } ,
//            { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 1, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 1, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
//            { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 1, 1 ,  1, 1, 1, 1, 1, 1, 1, 0, 1, 0 } ,
//
//            { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 1, 0, 1, 0 } ,
//            { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 0, 0, 0, 0 ,  0, 0, 0, 0, 1, 1, 1, 0, 1, 1 ,  1, 1, 1, 1, 1, 1, 1, 0, 1, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  0, 1, 1, 1, 1, 1, 1, 1, 1, 0 ,  0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  0, 0, 0, 0, 0, 1, 1, 0, 1, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  0, 1, 0, 0, 0, 1, 0, 0, 1, 0 ,  0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
//            { 0, 1, 1, 0, 0, 1, 1, 0, 0, 0 ,  0, 1, 0, 0, 0, 1, 0, 0, 1, 0 ,  0, 1, 1, 1, 1, 0, 0, 0, 0, 0 ,  1, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  0, 1, 0, 0, 0, 1, 0, 0, 1, 0 ,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,  1, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
//            { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,  0, 1, 1, 1, 1, 1, 0, 0, 1, 1 ,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,  1, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
//            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
//        }
//    },
//};
//
//// ���݂̃}�b�v�ԍ�
//int MapNo;
//
//// �v���C���[�̈ʒu
//int PlayerX, PlayerY;
//
//// �ړ����Ă��邩�ǂ����̃t���O( 0:��~��  1:�ړ��� )
//int Move;
//
//// �e�����Ɉړ������
//int MoveX, MoveY;
//
//// �ړ����n�߂Ă��牽�t���[���o�߂�������ێ�����ϐ�
//int MoveCounter;
//
//// �}�b�v�ƃv���C���[�̕`��֐�
//void GraphDraw(int ScrollX, int ScrollY)
//{
//    int j, i;
//    int MapDrawPointX, MapDrawPointY;     // �`�悷��}�b�v���W�l
//    int DrawMapChipNumX, DrawMapChipNumY; // �`�悷��}�b�v�`�b�v�̐�
//
//    // �`�悷��}�b�v�`�b�v�̐����Z�b�g
//    DrawMapChipNumX = 640 / MAP_SIZE + 2;
//    DrawMapChipNumY = 480 / MAP_SIZE + 2;
//
//    // ��ʍ���ɕ`�悷��}�b�v���W���Z�b�g
//    MapDrawPointX = PlayerX - (DrawMapChipNumX / 2 - 1);
//    MapDrawPointY = PlayerY - (DrawMapChipNumY / 2 - 1);
//
//    // �}�b�v��`��
//    for (i = -1; i < DrawMapChipNumY; i++)
//    {
//        for (j = -1; j < DrawMapChipNumX; j++)
//        {
//            // ��ʂ���͂ݏo���ʒu�Ȃ�`�悵�Ȃ�
//            if (j + MapDrawPointX < 0 || i + MapDrawPointY < 0 ||
//                j + MapDrawPointX >= MapData[MapNo].Width || i + MapDrawPointY >= MapData[MapNo].Height) continue;
//
//            // �}�b�v�f�[�^���O��������l�p��`�悷��
//            if (MapData[MapNo].Data[i + MapDrawPointY][j + MapDrawPointX] == 0)
//            {
//                DrawBox(j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,
//                    j * MAP_SIZE + MAP_SIZE + ScrollX, i * MAP_SIZE + MAP_SIZE + ScrollY,
//                    GetColor(255, 0, 0), TRUE);
//            }
//        }
//    }
//
//    // �v���C���[�̕`��
//    DrawBox((PlayerX - MapDrawPointX) * MAP_SIZE, (PlayerY - MapDrawPointY) * MAP_SIZE,
//        (PlayerX - MapDrawPointX + 1) * MAP_SIZE, (PlayerY - MapDrawPointY + 1) * MAP_SIZE,
//        GetColor(255, 255, 255), TRUE);
//}
//
//// �v�����l�������֐�
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
//    LPSTR lpCmdLine, int nCmdShow)
//{
//    int Key;
//    int ScrollX, ScrollY;
//
//    SetGraphMode(640, 480, 16);
//    if (DxLib_Init() == -1)    // �c�w���C�u��������������
//    {
//        return -1;             // �G���[���N�����璼���ɏI��
//    }
//
//    // �`����ʂ𗠉�ʂɂ���
//    SetDrawScreen(DX_SCREEN_BACK);
//
//    // �v���C���[�̏����ʒu���Z�b�g
//    PlayerX = 1;
//    PlayerY = 1;
//
//    // �ŏ��͒�~��(0)�ɂ��Ă���
//    Move = 0;
//
//    // ���[�v
//    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
//    {
//        // ��ʂ�������
//        ClearDrawScreen();
//
//        // �X�y�[�X�L�[�������ꂽ��}�b�v�ԍ���؂�ς���
//        if (GetInputChar(TRUE) == ' ')
//        {
//            // �v���C���[�̈ʒu��������
//            PlayerX = 1;
//            PlayerY = 1;
//
//            // ��~���t���O���|��
//            Move = 0;
//
//            // �}�b�v�ԍ������Z
//            MapNo++;
//            if (MapNo == MAP_NUM)
//            {
//                MapNo = 0;
//            }
//        }
//
//        // �ړ����ł͂Ȃ��ꍇ�L�[���͂��󂯕t����
//        if (Move == 0)
//        {
//            // �L�[���͂𓾂�
//            Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//
//            // �L�[���͂ɉ����ăv���C���[�̍��W���ړ�
//            if (Key & PAD_INPUT_LEFT)
//            {
//                Move = 1;
//                MoveX = -1;
//                MoveY = 0;
//            }
//            if (Key & PAD_INPUT_RIGHT)
//            {
//                Move = 1;
//                MoveX = 1;
//                MoveY = 0;
//            }
//            if (Key & PAD_INPUT_UP)
//            {
//                Move = 1;
//                MoveX = 0;
//                MoveY = -1;
//            }
//            if (Key & PAD_INPUT_DOWN)
//            {
//                Move = 1;
//                MoveX = 0;
//                MoveY = 1;
//            }
//
//            // �i���s�\�ȃ}�b�v�������ꍇ�͈ړ��ł��Ȃ�
//            if (Move == 1)
//            {
//                if (MapData[MapNo].Data[PlayerY + MoveY][PlayerX + MoveX] == 0)
//                {
//                    Move = 0;
//                }
//                else
//                {
//                    MoveCounter = 0;
//                }
//            }
//
//            // ��~���͉�ʂ̃X�N���[���͍s��Ȃ�
//            ScrollX = 0;
//            ScrollY = 0;
//        }
//
//        // �ړ����̏ꍇ�͈ړ��������s��
//        if (Move == 1)
//        {
//            MoveCounter++;
//
//            // �ړ��������I���������~���ɂ���
//            if (MoveCounter == MOVE_FRAME)
//            {
//                Move = 0;
//
//                // �v���C���[�̈ʒu��ύX����
//                PlayerX += MoveX;
//                PlayerY += MoveY;
//
//                // ��~���͉�ʂ̃X�N���[���͍s��Ȃ�
//                ScrollX = 0;
//                ScrollY = 0;
//            }
//            else
//            {
//                // �o�ߎ��Ԃ���X�N���[���ʂ��Z�o����
//                ScrollX = -(MoveX * MAP_SIZE * MoveCounter / MOVE_FRAME);
//                ScrollY = -(MoveY * MAP_SIZE * MoveCounter / MOVE_FRAME);
//            }
//        }
//
//        // �}�b�v�ƃv���C���[��`��
//        GraphDraw(ScrollX, ScrollY);
//
//        // ����ʂ̓��e��\��ʂɉf��
//        ScreenFlip();
//    }
//
//    DxLib_End();               // �c�w���C�u�����g�p�̏I������
//
//    return 0;                  // �\�t�g�̏I��
//}
//
//

#include "DxLib.h"
//#include <fstream>
#include "Player2.h"
//#define PI	3.1415926535897932384626433832795f

Player2 player2;


// �O���[�o���ϐ�>_<
int gPacman[12];			// �p�b�N�}���̃O���t�B�b�N�n���h��
int gMapChip[10];			// �}�b�v�`�b�v�̃n���h��
int gMap[31][28];			// �}�b�v�f�[�^
//int gScore;					// ���_
int gBg;					// �w�i�O���t�B�b�N�n���h��




// �摜�̓ǂݍ���
int LoadImages()
{
	// �摜�̓ǂݍ���
	if (LoadDivGraph("images/sprites/pacman.png", 12, 12, 1, 32, 32, gPacman) == -1) {
		//MessageBox(NULL, "pacman.bmp", "ReadError", MB_OK);
		return -1;
	}
	if (LoadDivGraph("mapchip1.bmp", 5, 5, 1, 16, 16, gMapChip) == -1) {
		/*MessageBox(NULL, "mapchip1.bmp", "ReadError", MB_OK);*/
		return -1;
	}

	return 0;
}

 //�}�b�v�̓ǂݍ���
int MapInit()
{
	int FileHandle = FileRead_open("StageData.txt");		// �t�@�C���̃I�[�v��
	int FileSize = FileRead_size("StageData.txt");			// �t�@�C���T�C�Y���擾����
	char* FileImage = new char[FileSize];					// ���̑傫�������̈�m��
	FileRead_read(FileImage, FileSize, FileHandle);			// ��C�ǂ�
	FileRead_close(FileHandle);								// �t�@�C������ďI��

	const char* d = FileImage;
	int sx = 0, sy = 0;
	int o;

	while (*d != '\0') { // NULL�����i�I�[�j�ł͂Ȃ���
		switch (*d) {
		case ' ':	o = 0; break;
		case 'o':	o = 1; break;
		case '@':	o = 2; break;
		case '#':	o = 3; break;
		case '=':	o = 4; break;
		case '\n':
			sy++;		// ��s���ցA���[��
			sx = 0;		// throw down
		default:	o = 5; break;
		}
		d++;
		if (o != 5) {
			gMap[sy][sx] = o;	// �}�b�v��񏑂�����
			sx++;
		}
	}
	return 0;
}

// ������
int Init()
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;

	SetDrawScreen(DX_SCREEN_BACK);		// ����ʂɏ������݂܂���錾

	if (LoadImages() == -1) {
		DxLib_End();
		return -1;
	}
	//MapInit();

	// �Q�[���̐ݒ�
	/*gScore = 0;*/
	return 0;
}
//void ClearEvent()
//{
//	MessageBox(NULL, "���߂ł���", "Congratulation", MB_OK);
//	return;
//}
// �}�b�v�z�u�i���t���[���`��j

int MapSet()
{
	int sx, sy, st;
	int dot = 0;

	DrawGraph(0, 0, gBg, TRUE);
	for (sy = 0; sy < 30; sy++) {
		for (sx = 0; sx < 32; sx++) {
			st = gMap[sy][sx];
			DrawGraph(sx * 16, sy * 16, gMapChip[st], TRUE);
			if (st == 1 || st == 2) dot++;
		}
	}
	//if (dot == 0) {		// �H�ׂ���̂��c���ĂȂ����
	//	ClearEvent();	// �N���A�ł���A���炢�˂��撣�����˂�
	//	return -1;
	//}
	return 0;
}

 //�i�s�����ɕǂ��Ȃ����`�F�b�N����
int Player2::CheckWall(int cx, int cy, int mx, int my)
{
	int wall = 0;
	static int dbgx = 0, dbgy = 0;
	if (mx != 0) {
		if (gMap[cy - 1][cx + mx * 2] >= 3) wall++;
		if (gMap[cy][cx + mx * 2] >= 3) wall++;
		if (gMap[cy + 1][cx + mx * 2] >= 3) wall++;
		dbgx = mx; dbgy = my;
	}
	else if (my != 0) {
		if (gMap[cy + my * 2][cx - 1] >= 3) wall++;
		if (gMap[cy + my * 2][cx] >= 3) wall++;
		if (gMap[cy + my * 2][cx + 1] >= 3) wall++;
		dbgx = mx; dbgy = my;
	}

	return wall;
}
// �v���C���[���ړ�����֐�
int Player2::PlayerMove()
{
	static int key;
	static int s = 0;			// �v���C���[�\���p
	static int x = 20, y = 14;	// �}�b�v���W
	static int dx = 0, dy = 0;	// ���������͗^���Ȃ�
	static float Angle = 0.0f;	// �����@������
	static int mv = 0;			// �v���C���[�ړ���
	int mvx = 0, mvy = 0;

	key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (key & PAD_INPUT_START) return -1;		// PAD_INPUT_START  [ESC]Key

	if (mv == 0) {
		// ��������
		if (gMap[y][x] == 1) {
			// Sound�u�ς����I�I�v
			/*gScore += 10;*/
			gMap[y][x] = 0;
		}
		if (gMap[y][x] == 2) {
			// �n�C�p�[���I�I
			/*gScore += 50;*/
			gMap[y][x] = 0;
		}

		// �҂����}�X�ڂɂ���Ƃ������L�[���͔���
		mv = 20;
		if (key & PAD_INPUT_UP) {
			if (!CheckWall(x, y, 0, -1)) {
				dx = 0; dy = -1; Angle = PI / 2;
			}
		}
		else if (key & PAD_INPUT_DOWN) {
			if (!CheckWall(x, y, 0, 1)) {
				dx = 0; dy = 1; Angle = -PI / 2;
			}
		}
		else if (key & PAD_INPUT_LEFT) {
			if (!CheckWall(x, y, -1, 0)) {
				dx = -1; dy = 0; Angle = 0;
			}
		}
		else if (key & PAD_INPUT_RIGHT) {
			if (!CheckWall(x, y, 1, 0)) {
				dx = 1; dy = 0; Angle = PI;
			}
		}
		//else {	// �L�[���͂��Ȃ������Ƃ��������蔻��
		//	if (CheckWall(x, y, dx, dy)) {
		//		dx = 0; dy = 0; mv = 0;
		//	}
		//	else {
		//		mv = 20;
		//	}
		//}
	}
	else {
		// �v���C���[�ړ����i�}�X�ڂ̒��Ԃɂ���Ƃ��j
		mv -= 4;
		if (mv <= 0) {
			x += dx;
			y += dy;
			mv = 0;//dx=0;dy=0;
			if (CheckWall(x, y, dx, dy)) {
				dx = 0; dy = 0;
				mv = 0;			// �O�̂��ߑΉ��B
			}
		}
		else {
			mvx = (16 - mv) * dx;
			mvy = (16 - mv) * dy;
		}
	}
	if ((dx + dy) != 0) s++; // �����Ă���Ƃ������A�j���[�V����

	DrawRotaGraph((x - 1) * 16 + 32 + mvx, (y - 1) * 16 + 32 + mvy, 1, Angle, gPacman[s/5%3+9], TRUE);
	
	return 0;
}



// ���C�����[�v
void MainLoop()
{
	while (ProcessMessage() == 0) {
		ClsDrawScreen();

		//if (MapSet())return;
		if (player2.PlayerMove()) return;

		/*DrawFormatString(512, 0, RGB(255, 255, 255), "SCORE:");
		DrawFormatString(512, 16, RGB(255, 255, 255), "%6d", gScore)*/;

		ScreenFlip();
	}
	return;
}

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	if (Init()) return -1;	// ������

	MainLoop();				// ���C�����[�`��

	DxLib_End();			// ���Ƃ��܂�
	return 0;
}