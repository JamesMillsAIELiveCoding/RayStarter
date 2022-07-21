#include "Circle.h"

Circle::Circle()
{
    x = 0;
    y = 0;
    radius = 0;
}

Circle::Circle(const float _x, const float _y, const float _rad)
{
    x = _x;
    y = _y;
    radius = _rad;
}

Circle::Circle(const Vec2 _pos, const float _rad)
{
    x = _pos.x;
    y = _pos.y;
    radius = _rad;
}

Circle::Circle(const initializer_list<float> _values)
{
    int iter = 0;
    for(const auto val : _values)
        asArray[iter++] = val;
}

Vec2 Circle::Position()
{
    return {x, y};
}

Hit Circle::Intersects(const Vec2 _point)
{
    const float dist = Vec2::Distance(Position(), _point);
    if(dist > radius)
        return {};

    Vec2 offset = Vec2::Normalized(_point - Position());
    offset *= radius;
    const Vec2 closestPoint = Position() + offset;
    const Vec2 delta = closestPoint - _point;
    return {closestPoint, delta, Vec2::Normalized(delta)};
}

Hit Circle::Intersects(Circle _circle)
{
    const float dist = Vec2::Distance(Position(), _circle.Position());
    if(dist > radius)
        return {};

    Vec2 offset = Vec2::Normalized(_circle.Position() - Position());
    offset *= radius;
    const Vec2 closestPoint = Position() + offset;
    const float overlapLength = radius + _circle.radius - dist;
    Vec2 delta = offset;
    delta *= overlapLength;
    return {closestPoint, delta, Vec2::Normalized(delta)};
}
