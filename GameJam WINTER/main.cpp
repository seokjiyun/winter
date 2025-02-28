#include<stdio.h>
#include <math.h>
#include "raylib.h"
#include "player.h"
#include "gob.h"
#include "map.h"
#include "castle.h"
#include "witch.h"
#include "oak.h"
#include "item.h"

const int NUM_GOBLINS = 10;
const int NUM_WITCHES = 3;
const int NUM_OAKS = 2;
const int NUM_ITEMS = 5;


int main() {

	InitWindow(800, 600, "Castle");

	Color vcolor = WHITE;
	Player player;
	player.last_State = player.P_front_t;
	Gob gob[NUM_GOBLINS];
	Witch witch[NUM_WITCHES];
	Oak oak[NUM_OAKS];
	//부쉬 수 = 아이템 수
	Item bush[NUM_ITEMS];
	Item item[NUM_ITEMS];

	Map map;
	Castle castle;
	Image background_Img;
	Texture2D background_Txt;
	background_Img = LoadImage("background.png");
	background_Txt = LoadTextureFromImage(background_Img);

	float elapsedTime = 0.0f;         
	int goblinsSpawned = 0;  

	int witchesSpawned = 0;
	int oaksSpawned = 0;
	int bushesSpawned = 0;
	int itemsSpawned = 0;
	
	const float spawnGobInterval = 30.0f / NUM_GOBLINS;
	const float spawnWitchInterval = 30.0f / NUM_WITCHES;
	const float spawnOakInterval = 30.0f / NUM_OAKS;
	const float spawnItemInterval = 30.0f / NUM_ITEMS;

	player.knight_Load();
	
	map.SetCastle(&castle);

	while (!WindowShouldClose()) {
		float deltaTime = GetFrameTime();
		elapsedTime += deltaTime;
		BeginDrawing();

		
			if (goblinsSpawned < NUM_GOBLINS && elapsedTime >= goblinsSpawned * spawnGobInterval) {
				gob[goblinsSpawned].Gob_Pos_X = 1;
				gob[goblinsSpawned].Gob_Pos_Y = GetRandomValue(50, 550);
				gob[goblinsSpawned].active = true;
				goblinsSpawned++;
			}
			if (witchesSpawned < NUM_WITCHES && elapsedTime >= witchesSpawned * spawnGobInterval) {
				witch[witchesSpawned].Witch_Pos_X = 1;
				witch[witchesSpawned].Witch_Pos_Y = GetRandomValue(50, 550);
				witch[witchesSpawned].active = true;
				witchesSpawned++;
			}
			if (oaksSpawned < NUM_OAKS && elapsedTime >= oaksSpawned * spawnOakInterval) {
				oak[oaksSpawned].Oak_Pos_X = GetRandomValue(50, 750);
				oak[oaksSpawned].Oak_Pos_Y = 550;
				oak[oaksSpawned].active = true;
				oaksSpawned++;
			}
			if (bushesSpawned < NUM_ITEMS && elapsedTime >= bushesSpawned * spawnItemInterval) {
				bush[bushesSpawned].bush_Pos_X = GetRandomValue(50, 750);
				item[itemsSpawned].item_Pos_X = bush[bushesSpawned].bush_Pos_X;
				bush[bushesSpawned].bush_Pos_Y = GetRandomValue(50,550);
				item[itemsSpawned].item_Pos_Y = bush[bushesSpawned].bush_Pos_Y;
				bush[bushesSpawned].bush_active = true;
				bushesSpawned++;
				itemsSpawned++;
			}

		SetTargetFPS(60);
		BeginDrawing();
		ClearBackground(vcolor);
		DrawTexture(background_Txt, 0, 0, WHITE);
		castle.Draw();
		map.Map_Draw();
		player.Player_Draw();
		player.Player_Move();


		for (int i = 0; i < NUM_GOBLINS; i++) {
			player.Attack(gob[i], witch[i], oak[i], bush[i]);
		}
			for (int i = 0;  i < NUM_OAKS; i++) {
			player.Attack(gob[i], witch[i], oak[i], bush[i]);
		}

		
		for (int i = 0; i < NUM_GOBLINS; i++) {
			if (gob[i].active && gob[i].hp > 0) {
				
				castle.UpdateCollision(gob[i].GetRec(), { 0,0,0,0 }, { 0,0,0,0 }, gob[i],  witch[0],  oak[0]);
			}
		}

		for (int i = 0; i < NUM_OAKS; i++) {
			if (oak[i].active && oak[i].hp > 0) {
				castle.UpdateCollision({ 0,0,0,0 }, { 0,0,0,0 }, oak[i].GetRec(),  gob[0],  witch[0], oak[i]);
			}
		}

		
		Rectangle castleRec = castle.GetRec();
		Rectangle playerRec = player.GetRec();
		Rectangle bushRec = item->GetRec();
		Rectangle itemRec = item->potionGetRec();

		Vector2 castleCenter = { castleRec.x + castleRec.width / 2, castleRec.y + castleRec.height / 2 };
		Vector2 player_Center;
		for (int i = 0; i < NUM_GOBLINS; i++) {
			if (gob[i].active && gob[i].hp > 0) {
				gob[i].Gob_Move(castleCenter);
				gob[i].Gob_Draw();
			}
		}
		for (int i = 0; i < NUM_OAKS; i++) {
			if (oak[i].active && oak[i].hp > 0) {
				oak[i].Oak_Move(castleCenter);
				oak[i].Oak_Draw();
			}
		}
		
		for (int i = 0; i < NUM_GOBLINS; i++) {
			for (int j = 0; j < NUM_ITEMS; j++) {
				player.UpdateCollision(
					gob[i].GetRec(),
					witch[i].GetRec(),
					oak[i].GetRec(),
					item[i].potionGetRec(),
					item[i].maceGetRec(),
					gob[i],
					witch[i],
					oak[i],
					item[j-1],
					item[NUM_ITEMS]
				);
			}
			
		}
		for (int i = 0; i < NUM_OAKS; i++) {
			for (int j = 0; j < NUM_ITEMS; j++) {
				player.UpdateCollision(
					gob[i].GetRec(),
					witch[i].GetRec(),
					oak[i].GetRec(),
					item[i].potionGetRec(),
					item[i].maceGetRec(),
					gob[i],
					witch[i],
					oak[i],
					item[j - 1],
					item[NUM_ITEMS]
				);
			}
		}
		
		Vector2 player_CenterP = { player.Player_Pos_X - (player.P_back_t.width / 2), player.Player_Pos_Y - (player.P_back_t.height / 2) };
		for (int i = 0; i < NUM_WITCHES; i++) {
			if (witch[i].active && witch[i].hp > 0) {
				witch[i].Witch_Move(player_CenterP); 
				witch[i].Witch_UpdateAttack(player_CenterP);
				witch[i].Witch_Draw();

				if (witch[i].projectileActive) {

					if (CheckCollisionCircleRec({ witch[i].projPosX, witch[i].projPosY }, witch[i].projRadius, playerRec)) {

						player.Player_HP -= witch->firewitch_Damage;

						witch[i].projectileActive = false;
					}
				}
			}
		}

		for (int i = 0; i < NUM_ITEMS; i++) {
			if (bush[i].bush_active && bush[i].hp > 0) {
				bush[i].bush_Draw();
			}
			if(bush[i].hp == 0) {
				for (int j = 0; j < NUM_ITEMS-1; j++) {
					item[j].potion_Draw();
				}
				item[NUM_ITEMS - 1].mace_Draw();
				
			}
		}

		for (int i = 0; i < NUM_ITEMS; i++) {
			player.Attack(gob[i], witch[i], oak[i], bush[i]);
		}
		if (map.GetStage() == 1) {
			ClearBackground(BLACK);
			EndDrawing();
			continue;
		}
		if (map.GetStage() == 2) {
			ClearBackground(BLACK);
			EndDrawing();
			continue;
		}
		
		ClearBackground(vcolor);
		DrawTexture(background_Txt, 0, 0, WHITE);
		map.Map_Draw();
		player.Player_Draw();
		player.Player_Move();

		EndDrawing();
		
	}
	

	

	player.knight_Unload();
	oak->oak_Unload();
	gob->gob_Unload();
	CloseWindow();
	return 0;
}