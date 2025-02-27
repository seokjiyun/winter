#pragma once
#include"raylib.h"
#include "gob.h" 
#include "gob2.h" 
#include "Oak.h" 
#include "item.h"

class Player {
public:
	void Player_Move();
	void Player_Draw();

	Rectangle GetAttackRect() const;

	void Attack(Gob& gob, Gob2& gob2,Oak& oak, Item& bush);
	void UpdateCollision(Rectangle GobRec, Rectangle Gob2Rec, Rectangle OakRec, Rectangle itemRec, Gob& gob, Gob2& gob2,Oak& oak, Item& potion);
	int GetHP() const;

	float Player_Pos_X = 0;
	float Player_Pos_Y = 0;
	float Player_Speed = 3;
	int Player_HP = 300;

	Image   P_front = LoadImage("player_front.png");
	Texture2D P_front_t = LoadTextureFromImage(P_front);
	Image   P_back = LoadImage("player_back.png");
	Texture2D P_back_t = LoadTextureFromImage(P_back);
	Image   P_right = LoadImage("player_right.png");
	Texture2D P_right_t = LoadTextureFromImage(P_right);
	Image   P_left = LoadImage("player_left.png");
	Texture2D P_left_t = LoadTextureFromImage(P_left);
	Texture2D last_State;

	void knight_Load();
	void knight_Unload();

	Vector2 facingDirection = { 1, 0 };
	Color HP_Color = WHITE;
private:
	float Player_R = 50;
	Color Player_Color = BLACK;
};