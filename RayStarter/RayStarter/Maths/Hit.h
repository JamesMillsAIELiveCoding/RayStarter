#pragma once

#include "Vec2.h"

typedef struct Hit
{
    Vec2 pos;
    Vec2 normal;
    Vec2 delta;
    bool didHit;

    Hit();
    Hit(Vec2 _pos, Vec2 _normal, Vec2 _delta);
    
} Hit;
