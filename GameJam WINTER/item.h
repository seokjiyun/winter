#pragma once
#include"raylib.h"

class Item {
public:
	void bush_Draw();
	void potion_Draw();

	Rectangle GetRec();


	bool bush_active = false;
	bool active = false;
	float item_Pos_X;
	float item_Pos_Y;
	float bush_Pos_X;
	float bush_Pos_Y;

	int hp = 15;
private:
	float bush_Width = 30;
	float bush_Height = 20;
	float item_Width = 20;
	float item_Height = 15;
	Color item_Color = RED;
	Color bush_Color = GREEN;
};