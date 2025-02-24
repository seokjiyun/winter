#pragma once
#include"player.h"
#include"raylib.h"

class Gob {
public:
	void Gob_Move();
	void Gob_Draw();
	bool Is_Collision_Gob();
	

	float Gob_Pos_X = 0;
	float Gob_Pos_Y = 100;
	
	
	

	
private:
	
	float Gob_Width = 30;
	float Gob_Height = 30;
	float Gob_Speed = 5;
	Color Gob_Color = GREEN;
};