#pragma once
#include "raylib.h"

class Witch {
public:
    void Witch_Move(Vector2 target);
    void Witch_UpdateAttack(Vector2 playerCenter);
    void Witch_Draw();
    Rectangle GetRec();

    Image icewitch_Img;
    Image firewitch_Img;
    Texture2D icewitch_Txt;
    Texture2D firewitch_Txt;

    void witch_UnLoad();
    float Witch_Pos_X = 0;
    float Witch_Pos_Y = 100;
    int hp = 50;
    int firewitch_Damage = 10;
    int icewitch_Damage = 3;
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
    float Gob2_Speed = 0.4f;
    Color Gob2_Color = BLACK;
};
