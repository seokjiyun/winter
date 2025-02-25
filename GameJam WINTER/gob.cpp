#include "gob.h"
#include <math.h>

void Gob::Gob_Move(Vector2 target) {
 
    float dx = target.x - Gob_Pos_X;
    float dy = target.y - Gob_Pos_Y;
    float distance = sqrt(dx * dx + dy * dy);
    if (distance != 0) {
        Gob_Pos_X += (dx / distance) * Gob_Speed;
        Gob_Pos_Y += (dy / distance) * Gob_Speed;
    }
}

void Gob::Gob_Draw() {
    if (hp > 0) {
        DrawRectangle(Gob_Pos_X, Gob_Pos_Y, Gob_Width, Gob_Height, Gob_Color);
    }
}

Rectangle Gob::GetRec() {
    return { Gob_Pos_X, Gob_Pos_Y, Gob_Width, Gob_Height };
}
