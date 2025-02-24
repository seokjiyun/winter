#include"gob.h"

void Gob::Gob_Move() {
	Gob_Pos_X += Gob_Speed;
}

void Gob::Gob_Draw() {
	DrawRectangle(Gob_Pos_X, Gob_Pos_Y, Gob_Width, Gob_Height, Gob_Color);
}

bool Gob::Is_Collision_Gob() {
	
	return true;
}