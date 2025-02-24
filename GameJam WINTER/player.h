#pragma once
#include"raylib.h"
class Player {
public:
	void Player_Move();
	void Player_Draw();

	float Player_Pos_X = 0;
	float Player_Pos_Y = 0;
	float Player_Speed = 3;
	
private:
	float Player_R = 50;
	Color Player_Color = BLACK;
};