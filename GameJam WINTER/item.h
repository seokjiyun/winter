#pragma once
#include"raylib.h"

class Item {
public:
	void bush_Draw();
	void potion_Draw();
	void mace_Draw();
	float mace_Pos_X;
	float mace_Pos_Y;
	Rectangle GetRec();
	Rectangle potionGetRec();
	Rectangle maceGetRec();
	Image bush_Img;
	Image mace_Img;
	Texture2D bush_Txt;
	Texture2D mace_Txt;

	bool bush_active = false;
	bool mace_active = false;
	float item_Pos_X;
	float item_Pos_Y;
	float bush_Pos_X;
	float bush_Pos_Y;
	float potion_Heal = 30;
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