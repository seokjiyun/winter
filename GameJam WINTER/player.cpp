#include"player.h"
#include <math.h>

void Player::Player_Move()
{
	Vector2 moveDir = { 0, 0 };

	if (IsKeyDown(KEY_UP)) {
		moveDir.y -= 1;
	}

	if (IsKeyDown(KEY_DOWN)) {
		moveDir.y += 1;
	}

	if (IsKeyDown(KEY_RIGHT)) {
		moveDir.x += 1;
	}

	if (IsKeyDown(KEY_LEFT)) {
		moveDir.x -= 1;
	}

	if (moveDir.x != 0 || moveDir.y != 0) {
		float length = sqrt(moveDir.x * moveDir.x + moveDir.y * moveDir.y);
		facingDirection = { moveDir.x / length, moveDir.y / length };
	}

	if (IsKeyDown(KEY_W)) {
		Player_Pos_Y -= Player_Speed;
	}
	if (IsKeyDown(KEY_S)) {
		Player_Pos_Y += Player_Speed;
	}
	if (IsKeyDown(KEY_D)) {
		Player_Pos_X += Player_Speed;
	}
	if (IsKeyDown(KEY_A)) {
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
	DrawText(TextFormat("Hp: %d", Player_HP), Player_Pos_X, Player_Pos_Y - 10, 10, HP_Color);
}

Rectangle Player::GetAttackRect() const {
	float attackWidth = 50;
	float attackHeight = 50;
	float offsetX = 0;
	float offsetY = 0;


	if (fabs(facingDirection.x) > fabs(facingDirection.y)) {

		if (facingDirection.x > 0) {
			offsetX = Player_R;
			offsetY = (Player_R / 2) - (attackHeight / 2);
		}
		else {
			offsetX = -attackWidth;
			offsetY = (Player_R / 2) - (attackHeight / 2);
		}
	}
	else {

		if (facingDirection.y > 0) {
			offsetY = Player_R;
			offsetX = (Player_R / 2) - (attackWidth / 2);
		}
		else {
			offsetY = -attackHeight;
			offsetX = (Player_R / 2) - (attackWidth / 2);
		}
	}
	DrawRectangle(Player_Pos_X + offsetX, Player_Pos_Y + offsetY, attackWidth, attackHeight, RED);
	return { Player_Pos_X + offsetX, Player_Pos_Y + offsetY, attackWidth, attackHeight };
}


void Player::Attack(Gob& gob, Gob2& gob2, Oak& oak, Item& bush) {
	if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_LEFT)){
		Rectangle attackRect = GetAttackRect();
		
		if (CheckCollisionRecs(attackRect, gob.GetRec())) {
			gob.hp -= 5;
		}if (CheckCollisionRecs(attackRect, gob2.GetRec())) {
			gob2.hp -= 5;
		}
		if (CheckCollisionRecs(attackRect, oak.GetRec())) {
			oak.hp -= 5;
		}
		if (CheckCollisionRecs(attackRect, oak.GetRec())) {
			oak.hp -= 5;
		}
		if (CheckCollisionRecs(attackRect, bush.GetRec())) {
			bush.hp -= 5;
		}
	}
}

void Player::UpdateCollision(Rectangle GobRec, Rectangle Gob2Rec, Rectangle OakRec, Rectangle ItemRec, Gob& gob, Gob2& gob2, Oak& oak, Item& item)
{
	Rectangle playerRec{ Player_Pos_X, Player_Pos_Y, Player_R, Player_R};
	if (CheckCollisionRecs(playerRec, GobRec)) {
		Player_HP -= gob.Gob_Damage;
	}
	if (CheckCollisionRecs(playerRec, OakRec)) {
		Player_HP -= oak.Oak_Damage;
	}
}

int Player::GetHP() const{
	return Player_HP;
}