#include<stdio.h>
#include "raylib.h"
#include "player.h"
#include "gob.h"
#include "map.h"
#include "castle.h"
#include "witch.h"
#include "oak.h"

const int NUM_GOBLINS = 10;
const int NUM_WITCHES = 3;
const int NUM_OAKS = 2;

int main() {

	InitWindow(800, 600, "Castle");

	Color vcolor = WHITE;
	Player player;

	Gob gob[NUM_GOBLINS];
	Witch witch[NUM_WITCHES];
	Oak oak[NUM_OAKS];

	Map map;
	Castle castle;

	float elapsedTime = 0.0f;         
	int goblinsSpawned = 0;  
	int witchesSpawned = 0;
	int oaksSpawned = 0;

	const float spawnGobInterval = 30.0f / NUM_GOBLINS;
	const float spawnWitchInterval = 30.0f / NUM_WITCHES;
	const float spawnOakInterval = 30.0f / NUM_OAKS;


	while (!WindowShouldClose()) {
		
		float deltaTime = GetFrameTime();
		elapsedTime += deltaTime;

		
			if (goblinsSpawned < NUM_GOBLINS && elapsedTime >= goblinsSpawned * spawnGobInterval) {
				
				gob[goblinsSpawned].Gob_Pos_X = 0;
				gob[goblinsSpawned].Gob_Pos_Y = GetRandomValue(50, 550);
				gob[goblinsSpawned].active = true;
				goblinsSpawned++;
			}

			if (oaksSpawned < NUM_OAKS && elapsedTime >= oaksSpawned * spawnOakInterval) {

				oak[oaksSpawned].Oak_Pos_X = GetRandomValue(50, 750);
				oak[oaksSpawned].Oak_Pos_Y = 550;
				oak[oaksSpawned].active = true;
				oaksSpawned++;
			}
		
		SetTargetFPS(60);
		BeginDrawing();
		ClearBackground(vcolor);




		map.Map_Draw();
		map.SetCastle(&castle);
		player.Player_Draw();
		player.Player_Move();


		castle.Draw();
		for (int i = 0; i < NUM_GOBLINS; i++) {
			if (gob[i].active && gob[i].hp > 0) {
				castle.UpdateCollision(gob[i].GetRec(), oak[i].GetRec(), gob[i], oak[i]);
			}
		}

		for (int i = 0; i < NUM_OAKS; i++) {
			if (oak[i].active && oak[i].hp > 0) {
				castle.UpdateCollision(gob[i].GetRec(), oak[i].GetRec(), gob[i], oak[i]);
			}
		}
		
		Rectangle castleRec = castle.GetRec();
		Vector2 castleCenter = { castleRec.x + castleRec.width / 2, castleRec.y + castleRec.height / 2 };
		for (int i = 0; i < NUM_GOBLINS; i++) {
			if (gob[i].active && gob[i].hp > 0) {
				gob[i].Gob_Move(castleCenter);
				gob[i].Gob_Draw();
			}
		}

		for (int i = 0; i < NUM_GOBLINS; i++) {
			player.Attack(gob[i], oak[i]);
		}

		for (int i = 0; i < NUM_OAKS; i++) {
			if (oak[i].active && oak[i].hp > 0) {
				oak[i].Oak_Move(castleCenter);
				oak[i].Oak_Draw();
			}
		}

		for (int i = 0; i < NUM_OAKS; i++) {
			player.Attack(gob[i], oak[i]);
		}
		EndDrawing();
	}
	CloseWindow();
	return 0;
}