#include<stdio.h>
#include"raylib.h"
#include"player.h"
#include"gob.h"
#include "map.h"
#include "castle.h"

const int NUM_GOBLINS = 10;

int main() {

	InitWindow(800, 600, "Castle");

	Color vcolor = WHITE;
	Player player;
	Gob gob[NUM_GOBLINS];
	Map map;
	Castle castle;

	float elapsedTime = 0.0f;         
	int goblinsSpawned = 0;           
	const float spawnInterval = 30.0f / NUM_GOBLINS;



	while (!WindowShouldClose()) {
		
		float deltaTime = GetFrameTime();
		elapsedTime += deltaTime;

		
			if (goblinsSpawned < NUM_GOBLINS && elapsedTime >= goblinsSpawned * spawnInterval) {
				
				gob[goblinsSpawned].Gob_Pos_X = 0;
				gob[goblinsSpawned].Gob_Pos_Y = GetRandomValue(50, 550);
				gob[goblinsSpawned].active = true;
				goblinsSpawned++;
			}
		
		SetTargetFPS(60);
		BeginDrawing();
		ClearBackground(vcolor);




		map.Map_Draw();
		player.Player_Draw();
		player.Player_Move();

		for (int i = 0; i < NUM_GOBLINS; i++) {
			player.Attack(gob[i]);
		}

		castle.Draw();
		for (int i = 0; i < NUM_GOBLINS; i++) {
			if (gob[i].active && gob[i].hp > 0) {
				castle.UpdateCollision(gob[i].GetRec());
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
			player.Attack(gob[i]);
		}
		EndDrawing();
	}
	CloseWindow();
	return 0;
}