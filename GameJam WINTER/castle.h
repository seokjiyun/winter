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
    bool gamewin;
    int hp;

    Image castle_Img;
    Texture2D castle_Txt;

private:
    float x;
    float y;
    float width;
    float height;

};
