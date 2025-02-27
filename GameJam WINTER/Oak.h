#pragma once
#include"raylib.h"

class Oak {
public:
	float Oak_Pos_X = 350;
	float Oak_Pos_Y = 500;
	float Oak_Speed = 0.2;
	int hp = 200;
	int Oak_Damage = 350;
	void Oak_Draw();
	void Oak_Move(Vector2 target);
	bool active = false;
	
	Image oak_Img;
	Texture2D oak_Txt;
	void oak_Load();
	void oak_Unload();
	Rectangle GetRec();

private:
	Color Oak_Color = DARKGREEN;
	float Oak_Width = 70;
	float Oak_Height = 150;
};