#include "CCoffeeBreak3.h"
#include"define.h"

CCoffeeBreak3::CCoffeeBreak3()
{
	LoadImages();
	anim = false;
	anime = false;
	animpacman = 0;
	x = 0;
	y = -2;

	tugihagiX = 1090.0;
	pacmanX = 930.0;
	imomusiX = 370.0;
	Timer = 480;
	tugihagiSpeed = 0;
	pacmanSpeed = 0;
	imomusiSpeed = 0;


	coffeeBreak3BGM = LoadSoundMem("sounds2/7.wav");//�R�[�q�[�u���C�N�̃T�E���h7��
}


CCoffeeBreak3::~CCoffeeBreak3()
{

}

void CCoffeeBreak3::Update()
{
	if (CheckSoundMem(coffeeBreak3BGM) == 0)
	{
		ChangeVolumeSoundMem(300, coffeeBreak3BGM);//���ʒ���
		PlaySoundMem(coffeeBreak3BGM, DX_PLAYTYPE_LOOP, FALSE);//���[�v�^�C�v�ɂ��Ė炵������
	}

	
	// �A�j���[�V��������p�ϐ��̍X�V
	static int animTimer = 0;
	animTimer++;//���͂�����Ƃ����ނ�����p�̏���
	animpacman++;//�p�b�N�}���p�̏���

	x++;
	
	pacmanSpeed = 560.0 / 240;
	tugihagiSpeed = 560.0 / 240;

	imomusiSpeed = 560.0 / 240;

	--Timer;
	

	//���̂������Q�Ƃ��܂�
	pacmanX = pacmanX - pacmanSpeed;
	tugihagiX = tugihagiX - tugihagiSpeed;

	if (Timer < 110) {
		imomusiX = imomusiX + imomusiSpeed;
	}
	


	if (animTimer % 3 == 0)//8�̓t���[����
	{
		anim = !anim;
	}
	if (animTimer % 5 == 0)
	{
		anime = !anime;
	}
}

void CCoffeeBreak3::Draw() const
{
	if(Timer < 480)
	{
		//�p�b�N�}���p�̕`��
		DrawRotaGraphF(pacmanX, D_FIELD_POS_Y + 360,
			1.0/32*32, 0, pacman[animpacman / 3 % 3 + 9], TRUE);

		//���͂�����̕`�� ���̂������Q�l�ɂ���
		DrawRotaGraphF(tugihagiX, D_FIELD_POS_Y + 360,
			1.0 / 14 * 28, 0, tugihagi[anim], TRUE);

	}

	if (Timer < 110) {
		//�����ނ�����̕`��
		DrawRotaGraphF(imomusiX, D_FIELD_POS_Y + 360,
			1.0 / 22 * 38, 0, imomusi[anime], TRUE);
		}
		
	/*DrawGraph(200, 200, tugihagi[0], TRUE);
	DrawGraph(200, 250, tugihagi[1], TRUE);*/

	/*DrawGraph(200, 300, imomusi[0], TRUE);
	DrawGraph(200, 350, imomusi[1], TRUE);*/


	/*DrawGraph(200, 370, pacman[9 + 0 % 3], TRUE);
	DrawGraph(200, 400, pacman[9 + 1 % 3], TRUE);
	DrawGraph(200, 430, pacman[9 + 2 % 3], TRUE);*/

	DrawBox(0, 0, 369, 720, 0x000000, TRUE);
	DrawBox(910, 0, 1280, 720, 0x000000, TRUE);

	DrawFormatString(200, 460, 0xFFFFFF, "%d", (int)anim);//TODO��ŃR�����g���O��
	DrawFormatString(200, 490, 0xFFFFFF, "%d", (int)Timer);//TODO��ŃR�����g���O��
}

void CCoffeeBreak3::LoadImages()
{
	LoadDivGraph("images/tugihagi1.png",TUGIHAGI_MAX,2,1,14,14,tugihagi);
	LoadDivGraph("images/imomusi1.png",IMOMUSI_MAX,1,2,20,10,imomusi);
	LoadDivGraph("images/sprites/pacman.png", PACMAN_MAX, 12, 1, 32, 32, pacman);
}