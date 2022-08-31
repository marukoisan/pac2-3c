
#include "DxLib.h"
#include "Player2.h"

Player2 player2;


// �O���[�o���ϐ�>_<
int gPacman[12];			// �p�b�N�}���̃O���t�B�b�N�n���h��
//int gMapChip[10];			// �}�b�v�`�b�v�̃n���h��
int gMap[31][28];			// �}�b�v�f�[�^
//int gScore;				// ���_
//int gBg;					// �w�i�O���t�B�b�N�n���h��





// �摜�̓ǂݍ���
int Player2::LoadImages()
{
	// �摜�̓ǂݍ���
	if (LoadDivGraph("images/sprites/pacman.png", 12, 12, 1, 32, 32, gPacman) == -1) {
		//MessageBox(NULL, "pacman.bmp", "ReadError", MB_OK);
		return -1;
	}
	//if (LoadDivGraph("mapchip1.bmp", 5, 5, 1, 16, 16, gMapChip) == -1) {
	//	/*MessageBox(NULL, "mapchip1.bmp", "ReadError", MB_OK);*/
	//	return -1;
	//}

	return 0;
}

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
	static float x = 40, y = 34;	// �}�b�v���W
	static float dx = 0, dy = 0;	// ���������͗^���Ȃ�
	static float Angle = 0.0f;	// �����@������
	static int mv = 0;			// �v���C���[�ړ���
	int mvx = 0, mvy = 0;
	static float speed = 1.0f;

	key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (key & PAD_INPUT_START) return -1;		// PAD_INPUT_START  [ESC]Key

	if (mv == 0) {
		// ��������
		if (gMap[(int)y][(int)x] == 1) {
			// Sound�u�ς����I�I�v
			/*gScore += 10;*/
			gMap[(int)y][(int)x] = 0;
		}
		if (gMap[(int)y][(int)x] == 2) {
			// �n�C�p�[���I�I
			/*gScore += 50;*/
			gMap[(int)y][(int)x] = 0;
		}

		/*if (KEY_INPUT_B) {
			speed = 1.0 * 5 / 16;
		}

		if (KEY_INPUT_V) {
			speed = 1.0 * 15 / 16;
		}

		if (KEY_INPUT_C) {
			speed = 1.0 * 16 / 16;
		}

		if (KEY_INPUT_X) {
			speed = 1.0 * 17 / 16;
		}

		if (KEY_INPUT_Z) {
			speed = 1.0 * 18 / 16;
		}*/

		// �҂����}�X�ڂɂ���Ƃ������L�[���͔���
		mv = 20;
		if (key & PAD_INPUT_UP) {
			if (!CheckWall(x, y, 0, -1)) {
				dx = 0; dy = -1.0 * 15 / 16; Angle = PI / 2;//speed; 
			}
		}
		else if (key & PAD_INPUT_DOWN) {
			if (!CheckWall(x, y, 0, 1)) {
				dx = 0; dy = speed; Angle = -PI / 2;
			}
		}
		else if (key & PAD_INPUT_LEFT) {
			if (!CheckWall(x, y, -1, 0)) {
				dx = -speed; dy = 0; Angle = 0;
			}
		}
		else if (key & PAD_INPUT_RIGHT) {
			if (!CheckWall(x, y, 1, 0)) {
				dx = speed; dy = 0; Angle = PI;
			}
		}
		else {	// �L�[���͂��Ȃ������Ƃ��������蔻��
			if (CheckWall(x, y, dx, dy)) {
				dx = 0; dy = 0; mv = 0;
			}
			else {
				mv = 20;
			}
		}
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

	DrawRotaGraph((x - 1) * 16 + 32 + mvx, (y - 1) * 16 + 32 + mvy, 1, Angle, gPacman[s / 5 % 3 + 9], TRUE);



	return 0;
}