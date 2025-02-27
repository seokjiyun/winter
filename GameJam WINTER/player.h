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
	void UpdateCollision(Rectangle GobRec, Rectangle Gob2Rec, Rectangle OakRec, Rectangle potionRec, Rectangle armoryRec, Gob& gob, Gob2& gob2,Oak& oak, Item& potion, Item& armory);
	void Image_Load();
	void Image_Unload();
	int GetHP() const;


	Image   Pfront = LoadImage("resources/Pfront.png");
	Image 	Pback = LoadImage("resources/Pback.png");
	Image 	Pright = LoadImage("resources/Pright.png");
	Image 	Pleft = LoadImage("resources/Pleft.png");
	Texture2D P_front;
	Texture2D P_back;
	Texture2D P_right;
	Texture2D P_left;
	Texture2D Last_state;

	float Player_Pos_X = 0;
	float Player_Pos_Y = 0;
	float Player_Speed = 3;
	int Player_HP = 300;

	Vector2 facingDirection = { 1, 0 };
	Color HP_Color = WHITE;
private:
	
	float Player_R = 50;
	Color Player_Color = BLACK;
};