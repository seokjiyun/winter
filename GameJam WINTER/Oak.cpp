#include"Oak.h"
#include"math.h"

void Oak::Oak_Move(Vector2 target) {
	float dx = target.x - Oak_Pos_X;
	float dy = target.y - Oak_Pos_Y;
	float distance = sqrt(dx * dx + dy * dy);
	if (distance != 0) {
		Oak_Pos_X += (dx / distance) * Oak_Speed;
		Oak_Pos_Y += (dy / distance) * Oak_Speed;
	}
}

void Oak::Oak_Draw() {
	DrawRectangle(Oak_Pos_X, Oak_Pos_Y, Oak_Width, Oak_Height, Oak_Color);
}