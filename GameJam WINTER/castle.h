#pragma once
#include "raylib.h"

class Castle {
public:
    Castle();                              
    void Draw();                            
    void UpdateCollision(Rectangle gobRec); 
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
