#pragma once
#include"raylib.h"

class Witch {
public:
	float Witch_Pos_X = 50;
	float Witch_Pos_Y = 200;

	void Witch_Draw();
	void Witch_Move(Vector2 target);
	void Witch_Attack(bool Collision); //collision with player or castle

	//Witch attack
	float Witch_AT_X = Witch_Pos_X;
	float Witch_AT_Y = Witch_Pos_Y;
	float Witch_AT_R = 1;
	float Witch_AT_S = 2;
	Color Witch_AT_C = RED;

private:
	Rectangle Get_Hit();
	float Witch_Width = 50;
	float Witch_Height = 50;
	float Witch_Speed = 0.1;

	Color Witch_color = PURPLE;
};