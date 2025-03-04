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
    Gob_Color = WHITE;
    Vector2 gob_Center = { Gob_Pos_X - (gob_Txt.width / 2), Gob_Pos_Y - (gob_Txt.height / 2) };
    if (hp > 0) {
        gob_Img = LoadImage("gob.png");
        gob_Txt = LoadTextureFromImage(gob_Img);
        DrawRectangleLinesEx(GetRec(), 1, RED);
        DrawTextureEx(gob_Txt,gob_Center, 1, 1, Gob_Color);
        DrawText(TextFormat("HP: %d", hp), Gob_Pos_X-15, Gob_Pos_Y - 35, 10, DARKGREEN);
    }
}

void Gob::gob_Unload() {
    UnloadImage(gob_Img);
    UnloadTexture(gob_Txt);
}

Rectangle Gob::GetRec() {
    return { Gob_Pos_X -20, Gob_Pos_Y - 25, float(gob_Txt.width- 40), float(gob_Txt.height- 10)};
}
