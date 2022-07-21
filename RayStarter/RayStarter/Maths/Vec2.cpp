#include "Vec2.h"

Vec2::Vec2()
{
    x = 0.f;
    y = 0.f;
}

Vec2::Vec2(const float _x, const float _y)
{
    x = _x;
    y = _y;
}

Vec2::Vec2(const initializer_list<float> _values)
{
    int iter = 0;
    for(const auto val : _values)
        asArray[iter++] = val;
}

float Vec2::Magnitude() const
{
    return sqrtf(x * x + y * y);
}

void Vec2::Normalize()
{
    const float length = Magnitude();
    if (length == 0)
    {
        x = 0;
        y = 0;
    }
    else
    {
        x /= length;
        y /= length;
    }
}

Vec2::operator Vector2() const
{
    return {x, y};
}

Vec2 operator+(const Vec2& _lhs, const Vec2& _rhs)
{
    return {_lhs.x + _rhs.x, _lhs.y + _rhs.y};
}

Vec2 operator-(const Vec2& _lhs, const Vec2& _rhs)
{
    return {_lhs.x - _rhs.x, _lhs.y - _rhs.y};
}

Vec2 operator*(const Vec2& _lhs, const Vec2& _rhs)
{
    return {_lhs.x * _rhs.x, _lhs.y * _rhs.y};
}

Vec2 operator*(const Vec2& _lhs, const float& _rhs)
{
    return {_lhs.x * _rhs, _lhs.y * _rhs};
}

Vec2 Vec2::Normalized(const Vec2& _toNormalize)
{
    Vec2 normalized = _toNormalize;
    normalized.Normalize();

    return normalized;
}

float Vec2::Distance(const Vec2& _lhs, const Vec2& _rhs)
{
    return (_lhs - _rhs).Magnitude();
}

float Vec2::Dot(const Vec2& _lhs, const Vec2& _rhs)
{
    return _lhs.x * _rhs.x + _lhs.y * _rhs.y;
}

Vec2 Vec2::Rotate(const Vec2& _vec, const float& _amount)
{
    float xRotated = _vec.x * cosf(_amount) - _vec.y * sinf(_amount);
    float yRotated = _vec.x * sinf(_amount) + _vec.y * cosf(_amount);

    return {xRotated, yRotated};
}

Vec2 operator-(const Vec2& _lhs)
{
    return Vec2{-_lhs.x, -_lhs.y};
}

bool operator==(const Vec2& _lhs, const Vec2& _rhs)
{
    return _lhs.x == _rhs.x && _lhs.y == _rhs.y;
}

bool operator!=(const Vec2& _lhs, const Vec2& _rhs)
{
    return _lhs.x != _rhs.x || _lhs.y != _rhs.y;
}

bool operator>(const Vec2& _lhs, const Vec2& _rhs)
{
    return _lhs.x + _lhs.y > _rhs.x + _rhs.y;
}

bool operator<(const Vec2& _lhs, const Vec2& _rhs)
{
    return _lhs.x + _lhs.y > _rhs.x + _rhs.y;
}

bool operator>=(const Vec2& _lhs, const Vec2& _rhs)
{
    return _lhs.x + _lhs.y >= _rhs.x + _rhs.y;
}

bool operator<=(const Vec2& _lhs, const Vec2& _rhs)
{
    return _lhs.x + _lhs.y <= _rhs.x + _rhs.y;
}