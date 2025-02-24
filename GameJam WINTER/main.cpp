#include<stdio.h>
#include"raylib.h"
#include"player.h"
#include"gob.h"


int main() {

	InitWindow(800, 600, "Castle");

	Color vcolor = WHITE;
	Player player;
	Gob gob;

	while (!WindowShouldClose()) {
		SetTargetFPS(60);
		BeginDrawing();
		ClearBackground(vcolor);
		
		player.Player_Draw();
		player.Player_Move();
		gob.Gob_Draw();
		gob.Gob_Move();

		EndDrawing();
	}
	CloseWindow();
	return 0;
}