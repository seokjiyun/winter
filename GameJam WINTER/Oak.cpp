#include"oak.h"
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
	Vector2 oak_Center = { Oak_Pos_X - (oak_Txt.width / 4), Oak_Pos_Y - (oak_Txt.height / 4) };
	DrawRectangleLinesEx(GetRec(), 1, RED);
	DrawTextureEx(oak_Txt, oak_Center, 1, 1, WHITE);
	DrawText(TextFormat("HP: %d", hp), Oak_Pos_X, Oak_Pos_Y, 10, RED);
	oak_Img = LoadImage("oak.png");
	oak_Txt = LoadTextureFromImage(oak_Img);
}

void Oak::oak_Unload() {
	UnloadImage(oak_Img);
	UnloadTexture(oak_Txt);
}

Rectangle Oak::GetRec() {
	return { Oak_Pos_X, Oak_Pos_Y, Oak_Width, Oak_Height };
}