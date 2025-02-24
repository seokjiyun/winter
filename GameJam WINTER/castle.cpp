#include "castle.h"

Castle::Castle() : width(100), height(100),hp(1000),gameover(false){

    x = (800 - width) / 2;
    y = (600 - height) / 2;
}

void Castle::Draw() {
    DrawRectangle(x, y, width, height, BLACK);
    DrawText(TextFormat("Castle HP: %d", hp), x, y - 30, 20, WHITE);
}

void Castle::UpdateCollision(Rectangle gobRec) {

    Rectangle castleRec = { x, y, width, height };
    if (CheckCollisionRecs(castleRec, gobRec)) {
        if (hp > 0) {
            hp-=50;
            if (hp <= 0) {
                gameover = true;
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
