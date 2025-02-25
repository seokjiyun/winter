#include<stdio.h>
#include <math.h>
#include "raylib.h"
#include "player.h"
#include "gob.h"
#include "gob2.h"
#include "map.h"
#include "castle.h"
#include "witch.h"
#include "Oak.h"


const int NUM_GOBLINS = 10;
const int NUM_WITCHES = 3;
const int NUM_OAKS = 2;

int main() {

	InitWindow(800, 600, "Castle");

	Color vcolor = WHITE;
	Player player;

	Gob gob[NUM_GOBLINS];
	Gob2 gob2[NUM_GOBLINS];
	Witch witch[NUM_WITCHES];
	Oak oak[NUM_OAKS];

	Map map;
	Castle castle;

	float elapsedTime = 0.0f;         
	int goblinsSpawned = 0;  
	int goblins2Spawned = 0;
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
			if (goblins2Spawned < NUM_GOBLINS && elapsedTime >= goblins2Spawned * spawnGobInterval) {

				gob2[goblins2Spawned].Gob2_Pos_X = 0;
				gob2[goblins2Spawned].Gob2_Pos_Y = GetRandomValue(50, 550);
				gob2[goblins2Spawned].active = true;
				goblins2Spawned++;
			}
			//if()
		
		SetTargetFPS(60);
		BeginDrawing();
		ClearBackground(vcolor);




		map.Map_Draw();
		map.SetCastle(&castle);
		player.Player_Draw();
		player.Player_Move();

		for (int i = 0; i < NUM_GOBLINS; i++) {
			player.Attack(gob[i], gob2[i], oak[i]);
		}

		castle.Draw();
		for (int i = 0; i < NUM_GOBLINS; i++) {
			if (gob[i].active && gob[i].hp > 0) {
				castle.UpdateCollision(gob[i].GetRec(), gob2[i].GetRec(), gob[i], gob2[i]);
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
			if (gob2[i].active && gob2[i].hp > 0) {
				gob2[i].Gob2_Move(castleCenter);
				gob2[i].Gob2_UpdateAttack(castleCenter);
				gob2[i].Gob2_Draw();

				if (gob2[i].projectileActive) {

					if (CheckCollisionCircleRec({ gob2[i].projPosX, gob2[i].projPosY }, gob2[i].projRadius, castleRec)) {

						castle.hp -= 50;

						gob2[i].projectileActive = false;
					}
				}
			}
		}

		

		EndDrawing();
	}
	CloseWindow();
	return 0;
}