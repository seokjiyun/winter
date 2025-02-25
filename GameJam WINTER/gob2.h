#pragma once
#include "raylib.h"

class Gob2 {
public:
    void Gob2_Move(Vector2 target);
    void Gob2_UpdateAttack(Vector2 castleCenter);
    void Gob2_Draw();
    Rectangle GetRec();

    float Gob2_Pos_X = 0;
    float Gob2_Pos_Y = 100;
    int hp = 50;
    bool active = false;

    bool projectileActive = false;
    float projPosX = 0;
    float projPosY = 0;
    float projSpeed = 100.0f;
    float projRadius = 5.0f;
    float attackCooldown = 0.0f;  
    float attackInterval = 0.1f; 
    float projDirX = 0.0f;
    float projDirY = 0.0f;

private:
    float Gob2_Width = 30;
    float Gob2_Height = 30;
    float Gob2_Speed = 0.4f;
    Color Gob2_Color = BLACK;
};
