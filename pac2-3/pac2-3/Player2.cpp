#include "DxLib.h"
#include "Player2.h"

Player2::Player2()
{


	if (LoadDivGraph("images/sprites/pacman.png", 12, 12, 1, 32, 32, gPacman) == -1);
}

Player2::~Player2()
{
	;
}

void Player2::Draw() const
{

}

//// �摜�̓ǂݍ���
//int Player2::LoadImages()
//{
//	// �摜�̓ǂݍ���
//	if (LoadDivGraph("images/sprites/pacman.png", 12, 12, 1, 32, 32, gPacman) == -1) {
//		//MessageBox(NULL, "pacman.bmp", "ReadError", MB_OK);
//		return -1;
//	}
//	//if (LoadDivGraph("mapchip1.bmp", 5, 5, 1, 16, 16, gMapChip) == -1) {
//	//	/*MessageBox(NULL, "mapchip1.bmp", "ReadError", MB_OK);*/
//	//	return -1;
//	//}
//
//	return 0;
//}

//�}�b�v�̓ǂݍ���
//int MapInit()
//{
//	int FileHandle = FileRead_open("StageData.txt");		// �t�@�C���̃I�[�v��
//	int FileSize = FileRead_size("StageData.txt");			// �t�@�C���T�C�Y���擾����
//	char* FileImage = new char[FileSize];					// ���̑傫�������̈�m��
//	FileRead_read(FileImage, FileSize, FileHandle);			// ��C�ǂ�
//	FileRead_close(FileHandle);								// �t�@�C������ďI��
//
//	const char* d = FileImage;
//	int sx = 0, sy = 0;
//	int o;
//
//	while (*d != '\0') { // NULL�����i�I�[�j�ł͂Ȃ���
//		switch (*d) {
//		case ' ':	o = 0; break;
//		case 'o':	o = 1; break;
//		case '@':	o = 2; break;
//		case '#':	o = 3; break;
//		case '=':	o = 4; break;
//		case '\n':
//			sy++;		// ��s���ցA���[��
//			sx = 0;		// throw down
//		default:	o = 5; break;
//		}
//		d++;
//		if (o != 5) {
//			gMap[sy][sx] = o;	// �}�b�v��񏑂�����
//			sx++;
//		}
//	}
//	return 0;
//}

// ������
int Player2::Init()
{
//	ChangeWindowMode(TRUE);
//	if (DxLib_Init() == -1) return -1;
//
//	SetDrawScreen(DX_SCREEN_BACK);		// ����ʂɏ������݂܂���錾
//
//	if (LoadImages() == -1) {
//		DxLib_End();
//		return -1;
//	}
//	//MapInit();
//
//	// �Q�[���̐ݒ�
//	/*gScore = 0;*/
//	return 0;
}

//void ClearEvent()
//{
//	MessageBox(NULL, "���߂ł���", "Congratulation", MB_OK);
//	return;
//}
// �}�b�v�z�u�i���t���[���`��j



