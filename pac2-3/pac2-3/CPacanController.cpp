//// プレイヤーが移動する関数
//int Player2::PlayerMove()
//{
//	static int key;
//	static int s = 0;			// プレイヤー表示用
//	static float x = 40, y = 34;	// マップ座標
//	static float dx = 0, dy = 0;	// 初期方向は与えない
//	static float Angle = 0.0f;	// 初期　左向き
//	static int mv = 0;			// プレイヤー移動中
//	int mvx = 0, mvy = 0;
//	static float speed = 1.0f;
//
//	key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//	if (key & PAD_INPUT_START) return -1;		// PAD_INPUT_START  [ESC]Key
//
//	if (mv == 0) {
//		// 足元判定
//		if (gMap[(int)y][(int)x] == 1) {
//			// Sound「ぱくっ！！」
//			/*gScore += 10;*/
//			gMap[(int)y][(int)x] = 0;
//		}
//		if (gMap[(int)y][(int)x] == 2) {
//			// ハイパー化！！
//			/*gScore += 50;*/
//			gMap[(int)y][(int)x] = 0;
//		}
//
//		/*if (KEY_INPUT_B) {
//			speed = 1.0 * 5 / 16;
//		}
//
//		if (KEY_INPUT_V) {
//			speed = 1.0 * 15 / 16;
//		}
//
//		if (KEY_INPUT_C) {
//			speed = 1.0 * 16 / 16;
//		}
//
//		if (KEY_INPUT_X) {
//			speed = 1.0 * 17 / 16;
//		}
//
//		if (KEY_INPUT_Z) {
//			speed = 1.0 * 18 / 16;
//		}*/
//
//		// ぴしゃりマス目にいるときだけキー入力判定
//		mv = 20;
//		if (key & PAD_INPUT_UP) {
//			if (!CheckWall(x, y, 0, -1)) {
//				dx = 0; dy = -1.0 * 15 / 16; Angle = PI / 2;//speed; 
//			}
//		}
//		else if (key & PAD_INPUT_DOWN) {
//			if (!CheckWall(x, y, 0, 1)) {
//				dx = 0; dy = speed; Angle = -PI / 2;
//			}
//		}
//		else if (key & PAD_INPUT_LEFT) {
//			if (!CheckWall(x, y, -1, 0)) {
//				dx = -speed; dy = 0; Angle = 0;
//			}
//		}
//		else if (key & PAD_INPUT_RIGHT) {
//			if (!CheckWall(x, y, 1, 0)) {
//				dx = speed; dy = 0; Angle = PI;
//			}
//		}
//		else {	// キー入力がなかったときも当たり判定
//			if (CheckWall(x, y, dx, dy)) {
//				dx = 0; dy = 0; mv = 0;
//			}
//			else {
//				mv = 20;
//			}
//		}
//	}
//	else {
//		// プレイヤー移動中（マス目の中間にいるとき）
//		mv -= 4;
//		if (mv <= 0) {
//			x += dx;
//			y += dy;
//			mv = 0;//dx=0;dy=0;
//			if (CheckWall(x, y, dx, dy)) {
//				dx = 0; dy = 0;
//				mv = 0;			// 念のため対応。
//			}
//		}
//		else {
//			mvx = (16 - mv) * dx;
//			mvy = (16 - mv) * dy;
//		}
//	}
//	if ((dx + dy) != 0) s++; // 動いているときだけアニメーション
//
//	DrawRotaGraph((x - 1) * 16 + 32 + mvx, (y - 1) * 16 + 32 + mvy, 1, Angle, gPacman[s / 5 % 3 + 9], TRUE);
//
//
//
//	return 0;
//}

// //進行方向に壁がないかチェックする
//int Player2::CheckWall(int cx, int cy, int mx, int my)
//{
//	int wall = 0;
//	static int dbgx = 0, dbgy = 0;
//	if (mx != 0) {
//		if (gMap[cy - 1][cx + mx * 2] >= 3) wall++;
//		if (gMap[cy][cx + mx * 2] >= 3) wall++;
//		if (gMap[cy + 1][cx + mx * 2] >= 3) wall++;
//		dbgx = mx; dbgy = my;
//	}
//	else if (my != 0) {
//		if (gMap[cy + my * 2][cx - 1] >= 3) wall++;
//		if (gMap[cy + my * 2][cx] >= 3) wall++;
//		if (gMap[cy + my * 2][cx + 1] >= 3) wall++;
//		dbgx = mx; dbgy = my;
//	}
//
//	return wall;
//}
