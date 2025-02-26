#include"item.h"

void Item::bush_Draw() {
	DrawRectangle(bush_Pos_X, bush_Pos_Y, bush_Width, bush_Height, bush_Color);
	item_Pos_X = bush_Pos_X;
	item_Pos_Y = bush_Pos_Y;
}

void Item::potion_Draw() {
	DrawCircle(item_Pos_X, item_Pos_Y, potion_Radius, potion_Color);
}




Rectangle Item::GetRec() {
	return { bush_Pos_X, bush_Pos_Y, bush_Width, bush_Height};
}