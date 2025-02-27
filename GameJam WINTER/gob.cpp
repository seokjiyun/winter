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
    Vector2 gob_Center = { Gob_Pos_X - (gob_Txt.width / 4), Gob_Pos_Y - (gob_Txt.height / 4) };
    if (hp > 0) {
        gob_Img = LoadImage("gob.png");
        gob_Txt = LoadTextureFromImage(gob_Img);
        DrawRectangleLinesEx(GetRec(), 1, RED);
        DrawTextureEx(gob_Txt,gob_Center, 1, 1, WHITE);
        DrawText(TextFormat("HP: %d", hp), Gob_Pos_X, Gob_Pos_Y - 10, 10, DARKGREEN);
    }
}

void Gob::gob_Unload() {
    UnloadImage(gob_Img);
    UnloadTexture(gob_Txt);
}

Rectangle Gob::GetRec() {
    return { Gob_Pos_X, Gob_Pos_Y, Gob_Width, Gob_Height };
}
