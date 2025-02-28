#pragma once
#include"raylib.h"

class Oak {
public:
	float Oak_Pos_X = 350;
	float Oak_Pos_Y = 500;
	float Oak_Speed = 0.2f;
	int hp = 200;
	int Oak_Damage = 350;
	void Oak_Draw();
	void Oak_Move(Vector2 target);
	bool active = false;
	
	Image oak_Img;
	Texture2D oak_Txt;
	void oak_Unload();
	Rectangle GetRec();
	Color Oak_Color = WHITE;
private:
	
};