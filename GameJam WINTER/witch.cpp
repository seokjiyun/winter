#include"witch.h"
#include"math.h"

void Witch::Witch_Draw() {
    DrawRectangle(Witch_Pos_X, Witch_Pos_Y, Witch_Width, Witch_Height, Witch_color);
}

void Witch::Witch_Move(Vector2 target) {
    float dx = target.x - Witch_Pos_X;
    float dy = target.y - Witch_Pos_Y;
    float distance = sqrt(dx * dx + dy * dy);
    if (distance != 0) {
        Witch_Pos_X += (dx / distance) * Witch_Speed;
        Witch_Pos_Y += (dy / distance) * Witch_Speed;
    }
}

//Rectangle Witch::Get_Hit() {
//    
//}

void Witch::Witch_Attack(bool Collision) {
    DrawCircle(Witch_AT_X, Witch_AT_Y, Witch_AT_R, Witch_AT_C);
    if (Collision) {
        Witch_AT_R *= 2;
        Witch_AT_C = BLACK;
        Collision = false;
    }
}