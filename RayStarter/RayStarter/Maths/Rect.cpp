#include "Rect.h"

Rect::Rect()
{
    x = 0;
    y = 0;
    width = 0;
    height = 0;
}

Rect::Rect(const float _x, const float _y, const float _width, const float _height)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
}

Rect::Rect(const Vec2 _pos, const Vec2 _size)
{
    x = _pos.x;
    y = _pos.y;
    width = _size.x;
    height = _size.y;
}

Rect::Rect(const initializer_list<float> _values)
{
    int iter = 0;
    for(const auto val : _values)
        asArray[iter++] = val;
}

Vec2 Rect::Position()
{
    return {x, y};
}

Vec2 Rect::Size()
{
    return {width, height};
}

Vec2 Rect::Min()
{
    return Position() - Size();
}

Vec2 Rect::Max()
{
    return Position() + Size();
}

bool Rect::IsPointInside(const Vec2 _point)
{
    const Vec2 min = Min();
    const Vec2 max = Max();

    return _point.x > min.x && _point.x < max.x &&
        _point.y > min.y && _point.y < max.y;
}

Hit Rect::Intersects(const Vec2 _point)
{
    if(!IsPointInside(_point))
        return {};

    auto hit = Hit();

    const Vec2 vec = _point - Position();
    const Vec2 overlap = Size() - Vec2(fabsf(vec.x), fabsf(vec.y));

    if(overlap.x < overlap.y)
    {
        const float xDir = vec.x < 0 ? -1 : 1;
        hit.delta.x = overlap.x * xDir;
        hit.normal.x = xDir;
        hit.pos.x = Position().x + (Size().x * xDir);
        hit.pos.y = _point.y;
    }
    else
    {
        const float yDir = vec.y < 0 ? -1 : 1;
        hit.delta.y = overlap.y * yDir;
        hit.normal.y = yDir;
        hit.pos.y = Position().y + (Size().y * yDir);
        hit.pos.x = _point.x;
    }

    return hit;
}

Hit Rect::Intersects(Rect _rect)
{
    const Vec2 vec = _rect.Position() - Position();
    const Vec2 overlap = _rect.Size() + Size() - Vec2(fabsf(vec.x), fabsf(vec.y));

    if(overlap.x <= 0 || overlap.y <= 0)
        return {};

    auto hit = Hit();

    if(overlap.x < overlap.y)
    {
        const float sx = vec.x < 0 ? -1 : 1;
        hit.delta.x = overlap.x * sx;
        hit.normal.x = sx;
        hit.pos.x = Position().x + (Size().x * sx);
        hit.pos.y = _rect.Position().y;
    }
    else
    {
        const float sy = vec.y < 0 ? -1 : 1;
        hit.delta.y = overlap.y * sy;
        hit.normal.y = sy;
        hit.pos.y = Position().y + (Size().y * sy);
        hit.pos.x = _rect.Position().x;
    }

    return hit;
}

Rect::operator Rectangle() const
{
    return Rectangle{x, y, width, height};
}
