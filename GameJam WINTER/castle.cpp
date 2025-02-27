#include "castle.h"
#include "gob.h"
#include "oak.h"
#include "gob2.h"

Castle::Castle() : width(100), height(100),hp(30000),gameover(false){

    x = (800 - width) / 2;
    y = (600 - height) / 2;
}

void Castle::Draw() {
    DrawRectangle(x, y, width, height, BLACK);
    DrawText(TextFormat("Castle HP: %d", hp), x, y - 30, 20, WHITE);
}


void Castle::UpdateCollision(Rectangle gobRec, Rectangle gob2Rec, Rectangle oakRec, Gob& gob, Gob2& gob2, Oak& oak) {

    Rectangle castleRec = { x, y, width, height };
    if (CheckCollisionRecs(castleRec, gobRec)) {
        if (hp > 0) {
            hp -= gob.Gob_Damage;
            gob.hp = 0;
            if (hp <= 0) {
                gameover = true;
            }
        }
    }

    if (CheckCollisionRecs(castleRec, oakRec)) {
        if (hp > 0) {
            hp -= oak.Oak_Damage;
            oak.hp = 0; if (hp <= 0) {
                gameover = true;
            }
        }

        if (CheckCollisionRecs(castleRec, gob2Rec)) {
            if (hp > 0) {
                hp -= 50;
                if (hp <= 0) {
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
