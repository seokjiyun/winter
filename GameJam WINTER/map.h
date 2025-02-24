#pragma once
#include "raylib.h"
#include "castle.h"

class Map {
public:
    Map();
    void Map_Draw();
    void SetStage(int stage);
    int GetStage() const;
    void SetCastle(Castle* castle);

private:
    int stage;
    Castle* castlePtr;
};