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
	Last_state = P_front;
	Vector2 Player_Center = { Player_Pos_X - (P_back.width / 4), Player_Pos_Y - (P_back.height / 4) };
	if (IsKeyDown(KEY_W)) {
		DrawTextureEx(P_back, Player_Center, 1, 1, WHITE);
		Last_state = P_back;
	}
	if (IsKeyDown(KEY_S)) {
		DrawTextureEx(P_front, Player_Center, 1, 1, WHITE);
		Last_state = P_front;
	}
	if (IsKeyDown(KEY_D)) {
		DrawTextureEx(P_right, Player_Center, 1, 1, WHITE);
		Last_state = P_right;
	}
	if (IsKeyDown(KEY_A)) {
		DrawTextureEx(P_left, Player_Center, 1, 1, WHITE);
		Last_state = P_left;
	}
	DrawTextureEx(Last_state, Player_Center, 1, 1, WHITE);
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

void Player::UpdateCollision(Rectangle GobRec, Rectangle Gob2Rec, Rectangle OakRec, Rectangle PotionRec, Rectangle ArmoryRec, Gob& gob, Gob2& gob2, Oak& oak, Item& potion, Item&armory)
{
	Rectangle playerRec{ Player_Pos_X, Player_Pos_Y, Player_R, Player_R};
	if (CheckCollisionRecs(playerRec, GobRec)) {
		gob.hp = 0;
		Player_HP -= gob.Gob_Damage;
	}
	if (CheckCollisionRecs(playerRec, OakRec)) {
		oak.hp = 0;
		Player_HP -= oak.Oak_Damage;
	}
	if (CheckCollisionRecs(playerRec, PotionRec)) {
		//if (Player_HP > 300) {
		//	Player_HP = 300;
		//}
		Player_HP += potion.potion_Heal;

	}
}

int Player::GetHP() const{
	return Player_HP;
}

void Player::Image_Load() {
	
	P_front = LoadTextureFromImage(Pfront);
	P_back = LoadTextureFromImage(Pback);
	P_right = LoadTextureFromImage(Pright);
	P_left = LoadTextureFromImage(Pleft);
	UnloadImage(Pfront);
	UnloadImage(Pback);
	UnloadImage(Pright);
	UnloadImage(Pleft);
}

void Player::Image_Unload() {
	
	UnloadTexture(P_front);
	UnloadTexture(P_back);
	UnloadTexture(P_right);
	UnloadTexture(P_left);
}