#pragma once
#include"raylib.h"

class Oak {
public:
	float Oak_Pos_X = 350;
	float Oak_Pos_Y = 500;
	float Oak_Speed = 0.1;
	void Oak_Draw();
	void Oak_Move(Vector2 target);

private:
	Color Oak_Color = DARKGREEN;
	float Oak_Width = 50;
	float Oak_Height = 50;
};