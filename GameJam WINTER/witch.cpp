#include"Witch.h"
#include"raylib.h"

void Witch::Witch_Move()
{
	Witch_Pos_X += 1;

}

void Witch::Witch_Draw() {
	DrawRectangle(Witch_Pos_X, Witch_Pos_Y, Witch_R, Witch_R, Witch_Color);
}