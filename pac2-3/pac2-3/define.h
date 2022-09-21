#pragma once

#define D_FIELD_WIDTH 28
#define D_FIELD_HEIGHT 31

#define D_FIELD_POS_X 370.0f
#define D_FIELD_POS_Y 70.0f
#define D_TILE_SIZE 20.0f

#define D_DIRECTION_UP 0
#define D_DIRECTION_LEFT 1
#define D_DIRECTION_DOWN 2
#define D_DIRECTION_RIGHT 3
#define D_LEVEL_MAX 21

struct DIFICULTY
{
	int speedLevel;
	int powerTime;
	int spurt;
	int timing;//モンスター出現タイミング
	int noEatTime;
};