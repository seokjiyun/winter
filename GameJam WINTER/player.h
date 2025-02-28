#pragma once
#include"raylib.h"
#include "gob.h" 
#include "Oak.h" 
#include "witch.h"
#include "item.h"

class Player {
public:
	void Player_Move();
	void Player_Draw();
	
	Rectangle GetAttackRect() const;
	Rectangle GetRec();

	void Attack(Gob& gob, Witch& witch,Oak& oak, Item& bush);
	void UpdateCollision(Rectangle GobRec, Rectangle WitchRec, Rectangle OakRec, Rectangle itemRec, Rectangle maceRec, Gob& gob, Witch& witch,Oak& oak, Item& potion, Item& mace);
	Item bush;
	float Player_Pos_X = 200;
	float Player_Pos_Y = 200;
	float Player_Pos_X_P = 0;
	float Player_Pos_Y_P = 0;
	float Player_Speed = 3;
	int Player_HP = 1000;

	//플레이어 공격(검)
	Image   atk1 = LoadImage("atk1.png");
	Image	atk2 = LoadImage("atk2.png");
	Image	atk3 = LoadImage("atk3.png");
	//플레이어 공격(창)
	Image   Latk1 = LoadImage("Latk1.png");
	Image	Latk2 = LoadImage("Latk2.png");
	Image	Latk3 = LoadImage("Latk3.png");
	//플레이어
	Image   P_front = LoadImage("player_front.png");
	Image   P_back = LoadImage("player_back.png");
	Image   P_right = LoadImage("player_right.png");
	Image   P_left = LoadImage("player_left.png");

	Texture2D atk1_t = LoadTextureFromImage(atk1);
	Texture2D atk2_t = LoadTextureFromImage(atk2);
	Texture2D atk3_t = LoadTextureFromImage(atk3);
	Texture2D Latk1_t = LoadTextureFromImage(Latk1);
	Texture2D Latk2_t = LoadTextureFromImage(Latk2);
	Texture2D Latk3_t = LoadTextureFromImage(Latk3);

	Texture2D P_front_t = LoadTextureFromImage(P_front);
	Texture2D P_back_t = LoadTextureFromImage(P_back);
	Texture2D P_right_t = LoadTextureFromImage(P_right);
	Texture2D P_left_t = LoadTextureFromImage(P_left);

	Texture2D last_State;

	void knight_Load();
	void knight_Unload();

	Vector2 facingDirection = { 1, 0 };
	Color HP_Color = WHITE;

	float lastAttackTime = 0.0f;
	float attackCooldown = 0.5f;

	float lastDamageTime = 0.0f;  
	float damageCooldown = 1.0f;

private:
	float Player_R = 50;
	Color Player_Color = BLACK;
};