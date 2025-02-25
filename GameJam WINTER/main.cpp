#include<stdio.h>
#include "raylib.h"
#include "player.h"
#include "gob.h"
#include "map.h"
#include "castle.h"
#include "witch.h"
#include "Oak.h"

int main() {

	InitWindow(800, 600, "Castle");

	Color vcolor = WHITE;
	Player player;
	Gob gob;
	Gob gob2;
	Witch witch;
	Oak oak;
	Map map;
	Castle castle;

	while (!WindowShouldClose()) {
		SetTargetFPS(60);
		BeginDrawing();
		ClearBackground(vcolor);

		map.Map_Draw();
		map.SetCastle(&castle);
		player.Player_Draw();
		player.Player_Move();

		player.Attack(gob);

		castle.Draw();
		castle.UpdateCollision(gob.GetRec());

		Rectangle castleRec = castle.GetRec();
		Vector2 castleCenter = { castleRec.x + castleRec.width / 2, castleRec.y + castleRec.height / 2 };
		gob.Gob_Move(castleCenter);
		oak.Oak_Move(castleCenter);
		Vector2 dummyTarget = { gob.Gob_Pos_X + 1, gob.Gob_Pos_Y };

		gob.Gob_Move(dummyTarget);
		gob.Gob_Draw();
		oak.Oak_Draw();

		EndDrawing();
	}
	CloseWindow();
	return 0;
}