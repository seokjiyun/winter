#pragma once
#include"raylib.h"

class Item {
public:
	void bush_Draw();
	void potion_Draw();
	void armory_Draw();

	Rectangle GetRec();
	Image bush_Img;
	Texture2D bush_Txt;

	bool bush_active = false;
	bool active = false;
	float item_Pos_X;
	float item_Pos_Y;
	float bush_Pos_X;
	float bush_Pos_Y;
	float potion_Heal = 30;
	float additional_Heal = 2;
	int hp = 15;
private:
	float bush_Width = 30;
	float bush_Height = 20;
	float item_Width = 20;
	float item_Height = 15;
	float potion_Radius = 5;
	float armory_Hence = 50;
	Color armory_Color = ORANGE;
	Color item_Color = RED;
	Color potion_Color = RED;
	Color bush_Color = GREEN;
};