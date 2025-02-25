#pragma once
#include "raylib.h"
#include "gob.h"
#include "oak.h"
#include "gob2.h"

class Castle {
public:
    Castle();                              
    void Draw();                            
    void UpdateCollision(Rectangle gobRec, Rectangle gob2Rec,Rectangle oakRec, Gob& gob, Gob2& gob2, Oak& oak);

    Rectangle GetRec() const;             
    int GetHP() const;                    
    bool gameover ;
    int hp;
private:
    float x;
    float y;
    float width;
    float height;

};
