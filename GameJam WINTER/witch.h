#pragma once
#include"raylib.h"

class Witch {
public:
	float Witch_Pos_X = 50;
	float Witch_Pos_Y = 200;
	
	void Witch_Draw();
	void Witch_Move();

private:
	float Witch_Width = 50;
	float Witch_Height = 50;
	
	Color Witch_color = PURPLE;
};