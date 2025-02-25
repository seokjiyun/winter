#pragma once
#include"raylib.h"
#include "gob.h" 

class Player {
public:
	void Player_Move();
	void Player_Draw();

	Rectangle GetAttackRect() const;
	void Attack(Gob& gob);

	float Player_Pos_X = 0;
	float Player_Pos_Y = 0;
	float Player_Speed = 3;

	Vector2 facingDirection = { 1, 0 };

private:
	float Player_R = 50;
	Color Player_Color = BLACK;
};