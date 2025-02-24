#include<stdio.h>
#include"raylib.h"
#include"player.h"

int main() {

	InitWindow(800, 600, "Castle");

	Color vcolor = WHITE;
	Player player;

	while (!WindowShouldClose()) {
		SetTargetFPS(60);
		BeginDrawing();
		ClearBackground(vcolor);

		player.Player_Draw();
		player.Player_Move();

		EndDrawing();
	}
	CloseWindow();
	return 0;
}