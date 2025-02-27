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
	DrawTexture(oak_Txt, Oak_Pos_X, Oak_Pos_Y, WHITE);
	
}

void Oak::Image_Load() {
	oak_Img = LoadImage("resources/oak.png");
	oak_Txt = LoadTextureFromImage(oak_Img);
	
}

void Oak::Image_Unload() {
	UnloadImage(oak_Img);
	UnloadTexture(oak_Txt);
}
Rectangle Oak::GetRec() {
	return { Oak_Pos_X, Oak_Pos_Y, Oak_Width, Oak_Height };
}
