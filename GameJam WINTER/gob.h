#pragma once
#include "raylib.h"

class Gob {
public:

    void Gob_Move(Vector2 target);
    void Gob_Draw();
 
    Rectangle GetRec();

    float Gob_Pos_X = 0;
    float Gob_Pos_Y = 100;
    int hp = 10; 
private:
    float Gob_Width = 30;
    float Gob_Height = 30;
    float Gob_Speed = 0.1f;
    Color Gob_Color = GREEN;
};
