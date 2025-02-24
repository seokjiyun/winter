#pragma once
#include"raylib.h"
class Witch {
public:
	void Witch_Move();
	void Witch_Draw();


	float Witch_Pos_X = 400;
	float Witch_Pos_Y = 200;
	float Witch_Speed = 3;
	float Witch_R = 20;
	Color Witch_Color = RED;
private:
	
};