#pragma once

#include "Maths/Vec2.h"

struct Ray2D
{
    Vec2 position;
    Vec2 direction;
    float length;

    Ray2D(Vec2 _position, Vec2 _direction, float _length) :
        position(_position), direction(_direction), length(_length)
    {
    }
};
