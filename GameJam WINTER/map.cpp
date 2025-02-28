#include "map.h"
#include"gob.h"
#include "castle.h"

Gob gob;
Castle castle;

Map::Map() : stage(1) { 
}

void Map::SetStage(int stageNumber) {
    stage = stageNumber;
}

int Map::GetStage() const {
    return stage;
}

void Map::SetCastle(Castle* castle) {
    castlePtr = castle;
}

void Map::Map_Draw() {
    if (IsKeyPressed(KEY_ONE)) {
        stage = 1;
        
    }
    else if(IsKeyPressed(KEY_TWO)) {
        stage = 2;
    }
    else if (IsKeyPressed(KEY_THREE)) {
        stage = 3;
    }
    else if (IsKeyPressed(KEY_FOUR)) {
        stage = 4;
    }
    if (castlePtr != nullptr && castlePtr->gameover == true) {
        stage = 3;
    }
    if (castlePtr != nullptr && castlePtr->gamewin == true) {
        stage = 4;
    }
    switch (stage) {
    case 1: {
        ClearBackground(SKYBLUE);
        break; }
    case 2: {
        ClearBackground(YELLOW);
        break; }
    case 3: {
        ClearBackground(BLUE);
        DrawText(TextFormat("Game Over"), 400, 300, 10, DARKGREEN);
        break; }
    
    case 4: {
        ClearBackground(WHITE);
        DrawText(TextFormat("Game Win"), 400, 300, 10, DARKGREEN);
        break; }
    default: {

        break;
    }
    }
}
