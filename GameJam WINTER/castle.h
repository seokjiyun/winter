#pragma once
#include "raylib.h"
#include "gob.h"
#include "oak.h"

class Castle {
public:
    Castle();                              
    void Draw();                            
    void UpdateCollision(Rectangle gobRec,Rectangle oakRec, Gob& gob, Oak& oak);
    Rectangle GetRec() const;             
    int GetHP() const;                    
    bool gameover ;

private:
    float x;
    float y;
    float width;
    float height;
    int hp;
};
