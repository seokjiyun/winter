#include "castle.h"
#include "gob.h"
#include "oak.h"
#include "witch.h"
#include "math.h"

Castle::Castle() : width(100), height(100),hp(3000),gameover(false){

    x = (800 - width) / 2;
    y = (600 - height) / 2;
}

void Castle::Draw() {
    Vector2 castleCenter = { x,y };
    castle_Img = LoadImage("castle.png");
    castle_Txt = LoadTextureFromImage(castle_Img);
    DrawRectangleLinesEx(GetRec(), 1, RED);
    DrawTextureEx(castle_Txt, castleCenter, 1, 1, WHITE);
    DrawText(TextFormat("Castle HP: %d", hp), x, y - 30, 20, WHITE);
}


void Castle::UpdateCollision(Rectangle gobRec, Rectangle witchRec, Rectangle oakRec, Gob& gob, Witch& witch, Oak& oak) {

    Rectangle castleRec = { x, y, width, height };
    if (CheckCollisionRecs(castleRec, gobRec)) {
        if (hp > 0) {
            hp -= gob.Gob_Damage;
            gob.hp = 0;
            if (hp <= 0) {
                hp = 0;
                gameover = true;
            }
        }
    }

    if (CheckCollisionRecs(castleRec, oakRec)) {
        if (hp > 0) {
            hp -= oak.Oak_Damage;
            oak.hp = 0; 
            if (hp <= 0) {
                hp = 0;
                gameover = true;
            }
        }

        if (CheckCollisionRecs(castleRec, witchRec)) {
            if (hp > 0) {
                hp -= 150;
                if (hp <= 0) {
                    hp = 0;
                    gameover = true;
                }
            }
        }
    }
}

Rectangle Castle::GetRec() const {
    return { x, y, width, height };
}

int Castle::GetHP() const {
    return hp;
}
