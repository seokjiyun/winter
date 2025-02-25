#include "gob2.h"
#include <math.h>
#include "raylib.h" 

void Gob2::Gob2_Move(Vector2 target) {

    float dx = target.x - Gob2_Pos_X;
    float dy = target.y - Gob2_Pos_Y;
    float distance = sqrtf(dx * dx + dy * dy);

    if (distance > 100.0f) {
        if (distance != 0) {
            Gob2_Pos_X += (dx / distance) * Gob2_Speed;
            Gob2_Pos_Y += (dy / distance) * Gob2_Speed;
        }
    }
}

void Gob2::Gob2_UpdateAttack(Vector2 castleCenter) {
    float dt = GetFrameTime();


    float centerX = Gob2_Pos_X + (Gob2_Width / 2);
    float centerY = Gob2_Pos_Y + (Gob2_Height / 2);
    float dx = castleCenter.x - centerX;
    float dy = castleCenter.y - centerY;
    float distance = sqrtf(dx * dx + dy * dy);

    if (distance <= 100.0f && !projectileActive && attackCooldown <= 0.0f) {
        projectileActive = true;
 
        projPosX = centerX;
        projPosY = centerY;

        if (distance != 0) {
            projDirX = dx / distance;
            projDirY = dy / distance;
        }
        attackCooldown = attackInterval;
    }

    if (attackCooldown > 0.0f) {
        attackCooldown -= dt;
    }

    if (projectileActive) {
        projPosX += projDirX * projSpeed * dt;
        projPosY += projDirY * projSpeed * dt;
        if (projPosX < 0 || projPosX > 800 || projPosY < 0 || projPosY > 600) {
            projectileActive = false;
        }
    }
}

void Gob2::Gob2_Draw() {
    if (hp > 0) {
        DrawRectangle((int)Gob2_Pos_X, (int)Gob2_Pos_Y, (int)Gob2_Width, (int)Gob2_Height, Gob2_Color);
    }
    if (projectileActive) {
        DrawCircle((int)projPosX, (int)projPosY, projRadius, RED);
    }
}

Rectangle Gob2::GetRec() {
    return { Gob2_Pos_X, Gob2_Pos_Y, Gob2_Width, Gob2_Height };
}
