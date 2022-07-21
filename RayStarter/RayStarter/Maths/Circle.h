#pragma once

#include "Vec2.h"

#include <raylib.h>
#include <functional>

#include "Hit.h"

using std::initializer_list;

typedef struct Circle
{
    union
    {
        struct
        {
            float x;
            float y;
            float radius;
        };

        float asArray[3];
    };

    Circle();
    Circle(float _x, float _y, float _rad);
    Circle(Vec2 _pos, float _rad);
    Circle(initializer_list<float> _values);

    Vec2 Position();

    Hit Intersects(Vec2 _point);
    Hit Intersects(Circle _circle);
    
} Circle;
