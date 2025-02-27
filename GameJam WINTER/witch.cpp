#include "witch.h"
#include <math.h>
#include "raylib.h" 

void Witch::Witch_Move(Vector2 target) {

    float dx = target.x - Witch_Pos_X;
    float dy = target.y - Witch_Pos_Y;
    float distance = sqrtf(dx * dx + dy * dy);

    if (distance > 100.0f) {
        if (distance != 0) {
            Witch_Pos_X += (dx / distance) * Gob2_Speed;
            Witch_Pos_Y += (dy / distance) * Gob2_Speed;
        }
    }
}

void Witch::Witch_UpdateAttack(Vector2 playerCenter) {
    float dt = GetFrameTime();


    float centerX = Witch_Pos_X + (firewitch_Txt.width / 2);
    float centerY = Witch_Pos_Y + (firewitch_Txt.height / 2);
    float dx = playerCenter.x - centerX;
    float dy = playerCenter.y - centerY;
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

void Witch::Witch_Draw() {
    icewitch_Img = LoadImage("icewitch.png");
    firewitch_Img = LoadImage("firewitch.png");
    icewitch_Txt = LoadTextureFromImage(icewitch_Img);
    firewitch_Txt = LoadTextureFromImage(firewitch_Img);
    Vector2 witch_Center = { Witch_Pos_X - (firewitch_Txt.width / 2), Witch_Pos_Y - (firewitch_Txt.height / 2) };
    if (hp > 0) {
        DrawRectangleLinesEx(GetRec(), 1, RED);
        DrawTextureEx(firewitch_Txt, witch_Center, 1, 1, WHITE);
        DrawText(TextFormat("HP: %d", hp), float(Witch_Pos_X), float(Witch_Pos_Y - 10), 10, ORANGE);
    }
    if (projectileActive) {
        DrawCircle((int)projPosX, (int)projPosY, projRadius, RED);
    }
}

void Witch::witch_UnLoad() {
    UnloadImage(firewitch_Img);
    UnloadImage(icewitch_Img);
    UnloadTexture(firewitch_Txt);
    UnloadTexture(icewitch_Txt);
}

Rectangle Witch::GetRec() {
    return { Witch_Pos_X - (icewitch_Txt.width/2), Witch_Pos_Y - (icewitch_Txt.height/2), float(firewitch_Txt.width), float(firewitch_Txt.height)};
}
