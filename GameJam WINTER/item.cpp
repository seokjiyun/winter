#include"item.h"

void Item::bush_Draw() {
	bush_Img = LoadImage("bush.png");
	mace_Img = LoadImage("mace.png");
	bush_Txt = LoadTextureFromImage(bush_Img);
	mace_Txt = LoadTextureFromImage(mace_Img);
	DrawTexture(bush_Txt, bush_Pos_X, bush_Pos_Y, WHITE);
	item_Pos_X = bush_Pos_X;
	item_Pos_Y = bush_Pos_Y;
}

void Item::potion_Draw() {
	DrawCircle(item_Pos_X, item_Pos_Y, potion_Radius, potion_Color);
}

void Item::mace_Draw() {
	DrawTexture(mace_Txt, item_Pos_X, item_Pos_Y, WHITE);
}


Rectangle Item::GetRec() {
	return { bush_Pos_X, bush_Pos_Y, bush_Width, bush_Height};
}