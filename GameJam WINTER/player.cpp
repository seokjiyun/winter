#include"player.h"

void Player::Player_Move()
{
	if (IsKeyDown(KEY_UP)) {
		Player_Pos_Y -= Player_Speed;
	}
	if (IsKeyDown(KEY_DOWN)) {
		Player_Pos_Y += Player_Speed;
	}
	if (IsKeyDown(KEY_RIGHT)) {
		Player_Pos_X += Player_Speed;
	}
	if (IsKeyDown(KEY_LEFT)) {
		Player_Pos_X -= Player_Speed;
	}
	if (IsKeyDown(KEY_LEFT_SHIFT)) {
		Player_Speed = 7;
	}
	if (IsKeyUp(KEY_LEFT_SHIFT)) {
		Player_Speed = 3;
	}
	
}

void Player::Player_Draw() {
	DrawRectangle(Player_Pos_X, Player_Pos_Y, Player_R, Player_R, Player_Color);
}


Rectangle Player::GetAttackRect() const {
	DrawRectangle( Player_Pos_X - 50, Player_Pos_Y, 50, 50,GREEN );
	return{ Player_Pos_X - 50, Player_Pos_Y, 50, 50 };
}

void Player::Attack(Gob& gob) {
	if (IsKeyPressed(KEY_SPACE)) {
		Rectangle attackRect = GetAttackRect();
		if (CheckCollisionRecs(attackRect, gob.GetRec())) {
			gob.hp -= 5;
		}
	}
}