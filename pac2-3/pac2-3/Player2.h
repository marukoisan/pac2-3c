#pragma once
#define PI	3.1415926535897932384626433832795f


class Player2 {
	private:


	public:
		int PlayerMove();
		int CheckWall(int cx, int cy, int mx, int my);
};

extern Player2 player2;