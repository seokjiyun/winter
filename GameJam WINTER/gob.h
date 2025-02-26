#pragma once
#include "raylib.h"

class Gob {
public:

    void Gob_Move(Vector2 target);
    void Gob_Draw();
 
    Rectangle GetRec();

    float Gob_Pos_X = 0;
    float Gob_Pos_Y = 100;
    int Gob_Damage = 50;
    int hp = 50; 
    bool active = false;

private:
    float Gob_Width = 30;
    float Gob_Height = 30;
    float Gob_Speed = 0.4f;
    Color Gob_Color = GREEN;
};
