#pragma once

#include "Vec2.h"

#include <raylib.h>
#include <functional>

#include "Hit.h"

using std::initializer_list;

struct Rect
{
    union
    {
        struct
        {
            float x;
            float y;
            float width;
            float height;
        };

        float asArray[4];
    };

    Rect();
    Rect(float _x, float _y, float _width, float _height);
    Rect(Vec2 _pos, Vec2 _size);
    Rect(initializer_list<float> _values);

    Vec2 Position();
    Vec2 Size();
    Vec2 Min();
    Vec2 Max();

    bool IsPointInside(Vec2 _point);
    Hit Intersects(Vec2 _point);
    Hit Intersects(Rect _rect);
    
    operator Rectangle() const;
    
};
