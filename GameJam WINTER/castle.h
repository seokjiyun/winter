#pragma once
#include "raylib.h"
#include "gob.h"
#include "oak.h"
#include "witch.h"

class Castle {
public:
    Castle();                              
    void Draw();                            
    void UpdateCollision(Rectangle gobRec, Rectangle witchRec,Rectangle oakRec, Gob& gob, Witch& witch, Oak& oak);

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
