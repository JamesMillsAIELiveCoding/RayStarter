#include "Hit.h"

Hit::Hit()
{
    pos = {};
    normal = {};
    delta = {};
    didHit = false;
}

Hit::Hit(const Vec2 _pos, const Vec2 _normal, const Vec2 _delta)
{
    pos = _pos;
    normal = _normal;
    delta = _delta;
    didHit = true;
}
