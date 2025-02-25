#pragma once
#include "raylib.h"
#include "gob.h"
class Castle {
public:
    Castle();                              
    void Draw();                            
    void UpdateCollision(Rectangle gobRec, Gob& gob);
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
