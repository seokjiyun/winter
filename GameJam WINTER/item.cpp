#include"item.h"

void Item::bush_Draw() {
	DrawRectangle(bush_Pos_X, bush_Pos_Y, bush_Width, bush_Height, bush_Color);
}

void Item::potion_Draw() {
	DrawRectangle(item_Pos_X, item_Pos_Y, item_Width, item_Height, item_Color);
}



Rectangle Item::GetRec() {
	return { item_Pos_X, item_Pos_Y, item_Width, item_Height};
}